/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "ecatslv.h"

#define    _ECATAPPL_ 1
#include "ecatappl.h"
#undef _ECATAPPL_
/* ECATCHANGE_START(V5.11) ECAT10*/
/*remove definition of _ECATAPPL_ (#ifdef is used in ecatappl.h)*/
/* ECATCHANGE_END(V5.11) ECAT10*/

#include "coeappl.h"
#include "timer.h"

/* ECATCHANGE_START(V5.11) ECAT11*/
#define _APPL_INTERFACE_ 1
#include "applInterface.h"
#undef _APPL_INTERFACE_
/* ECATCHANGE_END(V5.11) ECAT11*/

#include "Robot-Device.h"
#include "hw_readwrite.h" 
#include "stmflash.h"
#include "rs485.h"
#include "CAN_DATA.h"
#include "usart.h"	
#include "main.h"
/*--------------------------------------------------------------------------------------
------
------    local Types and Defines
------
--------------------------------------------------------------------------------------*/

#define MAX_CMD_RETIRES     10
#define    FLASH_SAVE_ADDR_baud                0X080E0000
#ifndef ECAT_TIMER_INC_P_MS
/**
 * \todo Define the timer ticks per ms
 */
#warning "Define the timer ticks per ms"
#endif /* #ifndef ECAT_TIMER_INC_P_MS */

#define OTP_ADDRESS         0X1FFF7800
u32 Hardwarebuf[1] = {0};
u32 offset = 0;

u8 Ecat_Work_Well_add_sync =0;
u32 rs485_can_rs232_baudrate[3];
u32 Last_rs485_can_rs232_baudrate[3];

u16 g_nEncoderPerRotate;
/*-----------------------------------------------------------------------------------------
------
------    local variables and constants
------
-----------------------------------------------------------------------------------------*/
/*variables only required to calculate values for SM Synchronisation objects (0x1C3x)*/
UINT16 u16BusCycleCntMs;        //used to calculate the bus cycle time in Ms
UINT32 StartTimerCnt;    //variable to store the timer register value when get cycle time was triggered
BOOL bCycleTimeMeasurementStarted; // indicates if the bus cycle measurement is started

UINT16             aPdOutputData[(MAX_PD_OUTPUT_SIZE>>1)];
UINT16           aPdInputData[(MAX_PD_INPUT_SIZE>>1)];

/*variables are declared in ecatslv.c*/
extern VARVOLATILE UINT16    u16dummy;
BOOL bInitFinished = FALSE; /** < \brief indicates if the initialization is finished*/
/*-----------------------------------------------------------------------------------------
------
------    local functions
------
-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
------
------    Functions
------
-----------------------------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////////////////////////////////
/**
\brief      This function will copies the inputs from the local memory to the ESC memory
            to the hardware
*////////////////////////////////////////////////////////////////////////////////////////
void PDO_InputMapping(void)
{
    APPL_InputMapping((UINT16*)aPdInputData);
    HW_EscWrite(((UINT8 *)aPdInputData), nEscAddrInputData, nPdInputSize *4 );
}
/////////////////////////////////////////////////////////////////////////////////////////
/**
\brief    This function will copies the outputs from the ESC memory to the local memory
          to the hardware. This function is only called in case of an SM2 
          (output process data) event.
*////////////////////////////////////////////////////////////////////////////////////////
void PDO_OutputMapping(void)
{

    HW_EscReadIsr(((UINT8 *)aPdOutputData), nEscAddrOutputData, nPdOutputSize*4 );

    APPL_OutputMapping((UINT16*) aPdOutputData);
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    This function shall be called every 1ms.
 \brief If the switch ECAT_TIMER_INT is 0, the watchdog control is implemented without using
 \brief interrupts. In this case a local timer register is checked every ECAT_Main cycle
 \brief and the function is triggered if 1 ms is elapsed
 *////////////////////////////////////////////////////////////////////////////////////////

void ECAT_CheckTimer(void)
{
    if(sSyncManOutPar.u32CycleTime == 0)
    {
        u16BusCycleCntMs++;
    }

    /*decrement the state transition timeout counter*/
    if(bEcatWaitForAlControlRes &&  (EsmTimeoutCounter > 0))
    {
        EsmTimeoutCounter--;
    }



    DC_CheckWatchdog();
}

/*ECATCHANGE_START(V5.11) ECAT6*/
/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    This function is called from the PDI_Isr and is used to calculate the bus cycle time 
  *////////////////////////////////////////////////////////////////////////////////////////
void HandleBusCycleCalculation(void)
{
    /*calculate the cycle time if device is in SM Sync mode and Cycle time was not calculated yet*/
    if ( !bDcSyncActive && bEscIntEnabled)
    {
        BOOL bTiggerCalcCycleTime = FALSE;

        if(sSyncManOutPar.u16GetCycleTime == 1)
            bTiggerCalcCycleTime = TRUE;
        if(bTiggerCalcCycleTime)
        {
            /*get bus cycle time triggered */
            sSyncManOutPar.u32CycleTime = 0;
            sSyncManOutPar.u16GetCycleTime = 0;

            sSyncManInPar.u32CycleTime  = 0;
            sSyncManInPar.u16GetCycleTime = 0;
            
            u16BusCycleCntMs = 0;
            bCycleTimeMeasurementStarted = TRUE;
            StartTimerCnt = TimeCNT_Isr;
        }
        else
        {
            if(bCycleTimeMeasurementStarted == TRUE)
            {
                UINT32 CurTimerCnt = TimeCNT_Isr;
/*ECATCHANGE_START(V5.11) ECAT3*/
                UINT32 CalcCycleTime = 0;


#if ECAT_TIMER_INC_P_MS
                CalcCycleTime = (UINT32)u16BusCycleCntMs * 1000000 + (((INT32)(CurTimerCnt-StartTimerCnt))*1000000/ECAT_TIMER_INC_P_MS);    //get elapsed cycle time in ns
#endif

/*ECATCHANGE_START(V5.11) ECAT4*/
                sSyncManOutPar.u32CycleTime = CalcCycleTime;
/*ECATCHANGE_END(V5.11) ECAT4*/
                sSyncManInPar.u32CycleTime  = CalcCycleTime;
                u16BusCycleCntMs = 0;
                StartTimerCnt = 0;
                bCycleTimeMeasurementStarted = FALSE;

/*ECATCHANGE_END(V5.11) ECAT3*/
            /* CiA402 Motion controller cycle time is only set if DC Synchronisation is active*/
            }
        }
    }
}
/*ECATCHANGE_END(V5.11) ECAT6*/

//void PDI_Isr(void)
//{
//	
//    if(bEscIntEnabled)
//    {
//        /* get the AL event register */
//        UINT16  ALEvent = HW_GetALEventRegister_Isr();
//        ALEvent = SWAPWORD(ALEvent);

//        if ( ALEvent & PROCESS_OUTPUT_EVENT )
//        {
//            if(bDcRunning && bDcSyncActive)
//            {
//                /* Reset SM/Sync0 counter. Will be incremented on every Sync0 event*/
//                u16SmSync0Counter = 0;
//            }
//            if(sSyncManOutPar.u16SmEventMissedCounter > 0)
//                sSyncManOutPar.u16SmEventMissedCounter--;


///*ECATCHANGE_START(V5.11) ECAT6*/
//            //calculate the bus cycle time if required
//            HandleBusCycleCalculation();
///*ECATCHANGE_END(V5.11) ECAT6*/

//        /* Outputs were updated, set flag for watchdog monitoring */
//			bEcatFirstOutputsReceived = TRUE;


//			/*
//				handle output process data event
//			*/
//			if ( bEcatOutputUpdateRunning )
//			{
//				/* slave is in OP, update the outputs */
//				PDO_OutputMapping();
//				
//			}
//			else
//			{
//				/* Just acknowledge the process data event in the INIT,PreOP and SafeOP state */
//				HW_EscReadWordIsr(u16dummy,nEscAddrOutputData);
//				HW_EscReadWordIsr(u16dummy,(nEscAddrOutputData+nPdOutputSize-2));
//			}
//        }

///*ECATCHANGE_START(V5.11) ECAT4*/
//        if (( ALEvent & PROCESS_INPUT_EVENT ) && (nPdOutputSize == 0))
//        {
//            //calculate the bus cycle time if required
//            HandleBusCycleCalculation();
//        }
///*ECATCHANGE_END(V5.11) ECAT4*/

//        /*
//            Call ECAT_Application() in SM Sync mode
//        */
//        if (sSyncManOutPar.u16SyncType == SYNCTYPE_SM_SYNCHRON)
//        {
//            /* The Application is synchronized to process data Sync Manager event*/
//            ECAT_Application();
//        }

//    if ( bEcatInputUpdateRunning 
///*ECATCHANGE_START(V5.11) ESM7*/
//       && ((sSyncManInPar.u16SyncType == SYNCTYPE_SM_SYNCHRON) || (sSyncManInPar.u16SyncType == SYNCTYPE_SM2_SYNCHRON))
///*ECATCHANGE_END(V5.11) ESM7*/
//        )
//    {
//        /* EtherCAT slave is at least in SAFE-OPERATIONAL, update inputs */
//        PDO_InputMapping();
//    }

//    /*
//      Check if cycle exceed
//    */
//    /*if next SM event was triggered during runtime increment cycle exceed counter*/
//    ALEvent = HW_GetALEventRegister_Isr();
//    ALEvent = SWAPWORD(ALEvent);

//    if ( ALEvent & PROCESS_OUTPUT_EVENT )
//    {
//        sSyncManOutPar.u16CycleExceededCounter++;
//        sSyncManInPar.u16CycleExceededCounter = sSyncManOutPar.u16CycleExceededCounter;

//      /* Acknowledge the process data event*/
//            HW_EscReadWordIsr(u16dummy,nEscAddrOutputData);
//            HW_EscReadWordIsr(u16dummy,(nEscAddrOutputData+nPdOutputSize-2));
//    }
//    } //if(bEscIntEnabled)
//		 ECAT_Main();
//}
//void Sync0_Isr(void)
//{
//	
//     Sync0WdCounter = 0;
//	
//    if(bDcSyncActive)
//    {

//        if ( bEcatInputUpdateRunning )
//        {
//            LatchInputSync0Counter++;
//        }

///*ECATCHANGE_START(V5.11) ECAT4*/
//        if(u16SmSync0Value > 0)
//        {
//           /* Check if Sm-Sync sequence is invalid */
//           if (u16SmSync0Counter > u16SmSync0Value)
//           {
//              /*ECATCHANGE_START(V5.11) COE3*/
//              if ((nPdOutputSize > 0) && (sSyncManOutPar.u16SmEventMissedCounter <= sErrorSettings.u16SyncErrorCounterLimit))
//              {
//                 /*ECATCHANGE_END(V5.11) COE3*/
//                 sSyncManOutPar.u16SmEventMissedCounter = sSyncManOutPar.u16SmEventMissedCounter + 3;
//              }

///*ECATCHANGE_START(V5.11) COE3*/
//           if ((nPdInputSize > 0) && (nPdOutputSize == 0) && (sSyncManInPar.u16SmEventMissedCounter <= sErrorSettings.u16SyncErrorCounterLimit))
//           {
///*ECATCHANGE_END(V5.11) COE3*/
//               sSyncManInPar.u16SmEventMissedCounter = sSyncManInPar.u16SmEventMissedCounter + 3;
//           }

//           } // if (u16SmSync0Counter > u16SmSync0Value)

//           
//           if ((nPdOutputSize == 0) && (nPdInputSize > 0))
//           {
//              /* Input only with DC, check if the last input data was read*/
//              UINT16  ALEvent = HW_GetALEventRegister_Isr();
//              ALEvent = SWAPWORD(ALEvent);

//              if ((ALEvent & PROCESS_INPUT_EVENT) == 0)
//              {
//                 /* no input data was read by the master, increment the sm missed counter*/
//                 u16SmSync0Counter++;
//              }
//              else
//              {
//                 /* Reset SM/Sync0 counter*/
//                 u16SmSync0Counter = 0;

//                 sSyncManInPar.u16SmEventMissedCounter = 0;

//              }
//           }
//           else
//           {
//              u16SmSync0Counter++;
//           }
//        }//SM -Sync monitoring enabled
///*ECATCHANGE_END(V5.11) ECAT4*/


//        if(!bEscIntEnabled && bEcatOutputUpdateRunning)
//        {
//            /* Output mapping was not done by the PDI ISR */
//            PDO_OutputMapping();
//        }

//        /* Application is synchronized to SYNC0 event*/
//        ECAT_Application();

//        if ( bEcatInputUpdateRunning 
//           && (LatchInputSync0Value > 0) && (LatchInputSync0Value == LatchInputSync0Counter) ) /* Inputs shall be latched on a specific Sync0 event */
//        {
//            /* EtherCAT slave is at least in SAFE-OPERATIONAL, update inputs */
//            PDO_InputMapping();

//            if(LatchInputSync0Value == 1)
//            {
//                /* if inputs are latched on every Sync0 event (otherwise the counter is reset on the next Sync1 event) */
//                LatchInputSync0Counter = 0;
//            }
//        }

//    }
//   ECAT_Main();
//}
void Sync0_Isr(void)
{
  UINT16  ALEvent;
  Ecat_Work_Well_add_sync++; 
	Sync0WdCounter = 0;
	Sync1WdCounter = 0;

    if(bDcSyncActive)
    {

        if ( bEcatInputUpdateRunning )
        {
            LatchInputSync0Counter++;
        }

/*ECATCHANGE_START(V5.11) ECAT4*/
        if(u16SmSync0Value > 0)
        {
           /* Check if Sm-Sync sequence is invalid */
           if (u16SmSync0Counter > u16SmSync0Value)
           {
              /*ECATCHANGE_START(V5.11) COE3*/
              if ((nPdOutputSize > 0) && (sSyncManOutPar.u16SmEventMissedCounter <= sErrorSettings.u16SyncErrorCounterLimit))
              {
                 /*ECATCHANGE_END(V5.11) COE3*/
                sSyncManOutPar.u16SmEventMissedCounter = sSyncManOutPar.u16SmEventMissedCounter + 3;
              }

/*ECATCHANGE_START(V5.11) COE3*/
           if ((nPdInputSize > 0) && (nPdOutputSize == 0) && (sSyncManInPar.u16SmEventMissedCounter <= sErrorSettings.u16SyncErrorCounterLimit))
           {
/*ECATCHANGE_END(V5.11) COE3*/
               sSyncManInPar.u16SmEventMissedCounter = sSyncManInPar.u16SmEventMissedCounter + 3;
           }

           } // if (u16SmSync0Counter > u16SmSync0Value)

           
           if ((nPdOutputSize == 0) && (nPdInputSize > 0))
           {
              /* Input only with DC, check if the last input data was read*/
              UINT16  ALEvent = HW_GetALEventRegister_Isr();
              ALEvent = SWAPWORD(ALEvent);

              if ((ALEvent & PROCESS_INPUT_EVENT) == 0)
              {
                 /* no input data was read by the master, increment the sm missed counter*/
                 u16SmSync0Counter++;
              }
              else
              {
                 /* Reset SM/Sync0 counter*/
                 u16SmSync0Counter = 0;

                 sSyncManInPar.u16SmEventMissedCounter = 0;

              }
           }
           else
           {
              u16SmSync0Counter++;
           }
        }//SM -Sync monitoring enabled
/*ECATCHANGE_END(V5.11) ECAT4*/
  ALEvent   = HW_GetALEventRegister_Isr();
	ALEvent = SWAPWORD(ALEvent);

       if ( ALEvent & PROCESS_OUTPUT_EVENT )
        {
            if(bDcRunning && bDcSyncActive)
            {
                /* Reset SM/Sync0 counter. Will be incremented on every Sync0 event*/
                u16SmSync0Counter = 0;
            }
            if(sSyncManOutPar.u16SmEventMissedCounter > 0)
                sSyncManOutPar.u16SmEventMissedCounter =  sSyncManOutPar.u16SmEventMissedCounter -3;


/*ECATCHANGE_START(V5.11) ECAT6*/
            //calculate the bus cycle time if required
//            HandleBusCycleCalculation();
/*ECATCHANGE_END(V5.11) ECAT6*/

        /* Outputs were updated, set flag for watchdog monitoring */
			bEcatFirstOutputsReceived = TRUE;


			/*
				handle output process data event
			*/
			if(bDcSyncActive && bEcatOutputUpdateRunning)
			{
				/* slave is in OP, update the outputs */
				PDO_OutputMapping();
	
			}
			else
			{
				/* Just acknowledge the process data event in the INIT,PreOP and SafeOP state */
				HW_EscReadWordIsr(u16dummy,nEscAddrOutputData);
				HW_EscReadWordIsr(u16dummy,(nEscAddrOutputData+nPdOutputSize-2));
			}
        }

        /* Application is synchronized to SYNC0 event*/
        ECAT_Application();

        if ( bEcatInputUpdateRunning 
           && (LatchInputSync0Value > 0) && (LatchInputSync0Value == LatchInputSync0Counter) ) /* Inputs shall be latched on a specific Sync0 event */
        {
            /* EtherCAT slave is at least in SAFE-OPERATIONAL, update inputs */
            PDO_InputMapping();

            if(LatchInputSync0Value == 1)
            {
                /* if inputs are latched on every Sync0 event (otherwise the counter is reset on the next Sync1 event) */
                LatchInputSync0Counter = 0;
            }
        }
	
        if ( bEcatInputUpdateRunning 
            && (sSyncManInPar.u16SyncType == SYNCTYPE_DCSYNC1)
            && (LatchInputSync0Value == 0)) /* Inputs are latched on Sync1 (LatchInputSync0Value == 0), if LatchInputSync0Value > 0 inputs are latched with Sync0 */
        {
            /* EtherCAT slave is at least in SAFE-OPERATIONAL, update inputs */
            PDO_InputMapping();
        }

        /* Reset Sync0 latch counter (to start next Sync0 latch cycle) */
        LatchInputSync0Counter = 0;	 
    }
	  ECAT_Main();
}

void Sync1_Isr(void)
{
    Sync1WdCounter = 0;

        if ( bEcatInputUpdateRunning 
            && (sSyncManInPar.u16SyncType == SYNCTYPE_DCSYNC1)
            && (LatchInputSync0Value == 0)) /* Inputs are latched on Sync1 (LatchInputSync0Value == 0), if LatchInputSync0Value > 0 inputs are latched with Sync0 */
        {
            /* EtherCAT slave is at least in SAFE-OPERATIONAL, update inputs */
            PDO_InputMapping();
        }

        /* Reset Sync0 latch counter (to start next Sync0 latch cycle) */
        LatchInputSync0Counter = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
/**

 \brief    This function shall called within a 1ms cycle.
        Set Run and Error Led depending on the Led state

*////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pObjectDictionary   Pointer to application specific object dictionary.
                                NULL if no specific object are available.
\return     0 if initialization was successful

 \brief    This function initialize the EtherCAT Sample Code

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 MainInit(void)
{
    UINT16 Error = 0;
/*Hardware init function need to be called from the application layer*/

/*ECATCHANGE_START(V5.11) EEPROM1*/
#ifdef SET_EEPROM_PTR
    SET_EEPROM_PTR
#endif
/*ECATCHANGE_END(V5.11) EEPROM1*/

    /* initialize the EtherCAT Slave Interface */
    ECAT_Init();
    /* initialize the objects */
    COE_ObjInit();


    /*Timer initialization*/
    u16BusCycleCntMs = 0;
    StartTimerCnt = 0;
    bCycleTimeMeasurementStarted = FALSE;

    /*Reset PDI Access*/
    {
/*ECATCHANGE_START(V5.11) ECAT1*/
    UINT16 eepromConfigControl = 0; //register (0x0500 : 0x0503) values

    HW_EscReadWord(eepromConfigControl,ESC_EEPROM_CONFIG_OFFSET);
    eepromConfigControl = SWAPWORD(eepromConfigControl);

    if((eepromConfigControl & ESC_EEPROM_ASSIGN_TO_PDI_MASK) > 0)
    {
        /*Clear access register(0x0501.1)*/
        eepromConfigControl &= ~ESC_EEPROM_LOCKED_BY_PDI_MASK;

        eepromConfigControl = SWAPWORD(eepromConfigControl);
        HW_EscWriteWord(eepromConfigControl,ESC_EEPROM_CONFIG_OFFSET);
    }
/*ECATCHANGE_END(V5.11) ECAT1*/
    }
    /*indicate that the slave stack initialization finished*/
    bInitFinished = TRUE;

/*Application Init need to be called from the application layer*/
     return Error;
}


/////////////////////////////////////////////////////////////////////////////////////////
/**

 \brief    This function shall be called cyclically from main

*////////////////////////////////////////////////////////////////////////////////////////

void MainLoop(void)
{
    /*return if initialization not finished */
    if(bInitFinished == FALSE)
        return;



        /* FreeRun-Mode:  bEscIntEnabled = FALSE, bDcSyncActive = FALSE
           Synchron-Mode: bEscIntEnabled = TRUE, bDcSyncActive = FALSE
           DC-Mode:       bEscIntEnabled = TRUE, bDcSyncActive = TRUE */
        if (
            (bEscIntEnabled || !bEcatFirstOutputsReceived)     /* SM-Synchronous, but not SM-event received */
          && !bDcSyncActive                                               /* DC-Synchronous */
            )
        {
            /* if the application is running in ECAT Synchron Mode the function ECAT_Application is called
               from the ESC interrupt routine (in mcihw.c or spihw.c),
               in ECAT Synchron Mode it should be additionally checked, if the SM-event is received
               at least once (bEcatFirstOutputsReceived = 1), otherwise no interrupt is generated
               and the function ECAT_Application has to be called here (with interrupts disabled,
               because the SM-event could be generated while executing ECAT_Application) */
            if ( bEscIntEnabled )//20190807增加freerun模式
            {
                /* application is running in ECAT FreeRun Mode,
                   first we have to check, if outputs were received */
                UINT16 ALEvent = HW_GetALEventRegister();
                ALEvent = SWAPWORD(ALEvent);

                if ( ALEvent & PROCESS_OUTPUT_EVENT )
                {
                    /* set the flag for the state machine behaviour */
                    bEcatFirstOutputsReceived = TRUE;
                    if ( bEcatOutputUpdateRunning )
                    {
                        /* update the outputs */
                        PDO_OutputMapping();
                    }
                }
                else if ( nPdOutputSize == 0 )
                {
                    /* if no outputs are transmitted, the watchdog must be reset, when the inputs were read */
                    if ( ALEvent & PROCESS_INPUT_EVENT )
                    {
                        /* Outputs were updated, set flag for watchdog monitoring */
                        bEcatFirstOutputsReceived = TRUE;
                    }
                }
            }

//           INTX_DISABLE();
						DISABLE_ESC_INT();
            ECAT_Application();

            if ( bEcatInputUpdateRunning )
            {
                /* EtherCAT slave is at least in SAFE-OPERATIONAL, update inputs */
                PDO_InputMapping();
						
            }
						ENABLE_ESC_INT();
//          INTX_ENABLE();
        }

//        TIM_Cmd(TIM4,ENABLE); //使能定时器4
        /* call EtherCAT functions */
        ECAT_Main();

        /* call lower prior application part */
      COE_Main();
      CheckIfEcatError();
			if(Over_Temperature0x8010 != 0x0)
			{
				power_manage.temperature_h = Over_Temperature0x8010;
			}
			
			if(Consecutive_Failure_CNT0x8012 != 0x0)
			{
				power_manage.alarm_cfc = Consecutive_Failure_CNT0x8012;
			}
			
			if(Under_Voltage_48V0x800B != 0x0)
			{
				power_manage.dc48v_ul = Under_Voltage_48V0x800B;
			}
			
			if(Over_Voltage_48V0x800A != 0x0)
			{
				power_manage.dc48v_uh = Over_Voltage_48V0x800A;
			}
			
			if(Over_Current_48V0x800C != 0x0)
			{
				power_manage.dc48v_ih = Over_Current_48V0x800C;
			}
			
			if(Over_Voltage_24V0x800D != 0x0)
			{
				power_manage.dc24v1_uh = Over_Voltage_24V0x800D;
			}
			
			if(Under_Voltage_24V0x800E != 0x0)
			{
				power_manage.dc24v1_ul = Under_Voltage_24V0x800E;
			}
			
			if(Over_Current_24V0x800F != 0x0)
			{
				power_manage.dc24v1_ih = Over_Current_24V0x800F;
			}
			
			rs485_can_rs232_baudrate[0] = RS485_Baudrate0x8000;	
		  rs485_can_rs232_baudrate[1] = CAN_Baudrate0x8001;	
			g_nEncoderPerRotate = MotEncPerRotate0x8003; 	
			if((rs485_can_rs232_baudrate[0]!=Last_rs485_can_rs232_baudrate[0])||(rs485_can_rs232_baudrate[1]!=Last_rs485_can_rs232_baudrate[1] ))
			{		
				STMFLASH_Write(FLASH_SAVE_ADDR_baud,(u32*)rs485_can_rs232_baudrate,2);
				Last_rs485_can_rs232_baudrate[0] = rs485_can_rs232_baudrate[0];
				Last_rs485_can_rs232_baudrate[1] = rs485_can_rs232_baudrate[1];
				RS485_Init(RS485_Baudrate0x8000);
				CAN_Configuration(CAN_Baudrate0x8001);				
			} 
			
			Software_Version0x8004 = 0x80F;

			STMFLASH_Read(OTP_ADDRESS+offset,Hardwarebuf,1);

			if(((Hardwarebuf[0] & 0xFFFF) != 0xFFFF) && ((Hardwarebuf[0] & 0xFFFF0000) != 0xFFFF0000))
			{
				offset = offset + 2;
			}
			else if(((Hardwarebuf[0] & 0xFFFF) != 0xFFFF) && ((Hardwarebuf[0] & 0xFFFF0000) == 0xFFFF0000))
			{
				Hardware_Version0x8005 = Hardwarebuf[0] & 0xFFFF;
			}	
			else 
			{	
				Hardware_Version0x8005 = 0;	//error	
			}		
}

/*The main function was moved to the application files.*/
/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    ECAT_Application (prev. SSC versions "COE_Application")
 this function calculates and the physical process signals and triggers the input mapping
*////////////////////////////////////////////////////////////////////////////////////////
void ECAT_Application(void)
{
    {
        APPL_Application();
    }
/* PDO Input mapping is called from the specific trigger ISR */
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param        wordaddress      WORD based address in the EEPROM to be read
 \param        wordsize         size in WORD of EEPROM data to be read
 \param        pData            buffer for EEPROM to be read or with EEPROM data to be written
 \param        access           read (ESC_RD) or write (ESC_WR) access

 \return     0 - success, > 0: error code

 \brief        This function is called to read or write the EEPROM data, for BigEndian
 \brief        Controller (switch BIG_ENDIAN_FORMAT set) the data has to be swapped outside
 \brief        of this function)
*////////////////////////////////////////////////////////////////////////////////////////

UINT16 ESC_EepromAccess(UINT32 wordaddress, UINT16 wordsize, UINT16 MBXMEM *pData, UINT8 access)
{
    UINT16 i;
    UINT8 u8TimeOut;
    UINT16 u16RetErr = 0;
    UINT16 u16WordOffset = 0;
    UINT8 RetryCnt = MAX_CMD_RETIRES; //Maximum number of retries (evaluated in case of an Acknowledge Error)

    UINT16 nConfig;
/*ECATCHANGE_START(V5.11) EEPROM4*/
    VARVOLATILE UINT16 nControl;
/*ECATCHANGE_END(V5.11) EEPROM4*/

    HW_EscReadWord(nConfig,ESC_EEPROM_CONFIG_OFFSET);
    HW_EscReadWord(nControl, ESC_EEPROM_CONTROL_OFFSET);



    if ( nConfig & ESC_EEPROM_ASSIGN_TO_PDI_MASK )
    {
        /* register 0x500.0 is set (should be written by the master before sending
        the state transition request to PREOP),we have access to the EEPROM */
        UINT16 step = 1; /* we write always only 1 word with one write access */

        if ( access == ESC_RD )
        {
            /* read access requested, we have to check if we read 2 (register 0x502.6=0)
            or 4 words (register 0x502.6=1) with one access */
            if ( nControl & ESC_EEPROM_SUPPORTED_READBYTES_MASK )
                step = 4; /* we get 4 words with one read access */
            else
                step = 2; /* we get 2 words with one read access */
        }

        /* first we have to lock the EEPROM access that we will not be interrupted by the master
        by setting register 0x501.0 */
        nConfig = ESC_EEPROM_LOCKED_BY_PDI_MASK;
        HW_EscWriteWord(nConfig,ESC_EEPROM_CONFIG_OFFSET);
/*ECATCHANGE_START(V5.11) ECAT2*/
        for (i = 0; i < wordsize;)
/*ECATCHANGE_END(V5.11) ECAT2*/
        {
            /* we have to set the start address in register 0x504-0x507 */
            HW_EscWrite((UINT8 *) &wordaddress, ESC_EEPROM_ADDRESS_OFFSET, 4);

            if ( access == ESC_RD )
            {
                /* read access, we start the reading by setting 0x502.8
                (will be reset automatically when reading is finished) */
                nControl = ESC_EEPROM_CMD_READ_MASK;
                HW_EscWriteWord(nControl,ESC_EEPROM_CONTROL_OFFSET);
            }
            else
            {
                /* write access, we write the data in register 0x508-0x509 */
                HW_EscWriteWord(pData[i],ESC_EEPROM_DATA_OFFSET);

                /* we start the writing by setting 0x502.9
                (will be reset automatically when writing is finished) */

                nControl = SWAPWORD(ESC_EEPROM_CMD_WRITE_MASK);

                HW_EscWriteWord(nControl, ESC_EEPROM_CONTROL_OFFSET);
            }

            do
            {

                /*Wait 100 cycles before reading EEPROM status*/
                u8TimeOut = 100;
                while (u8TimeOut > 0)
                {
                    u8TimeOut--;
                }
                HW_EscReadWord(nControl, ESC_EEPROM_CONTROL_OFFSET);

            }
            while ( nControl & (ESC_EEPROM_BUSY_MASK));

            /* we have to check if the access was without errors */
            HW_EscReadWord(nControl, ESC_EEPROM_CONTROL_OFFSET);

            if ( nControl & ESC_EEPROM_ERROR_MASK )
            {
                if(!(nControl & ESC_EEPROM_ERROR_CMD_ACK) && (RetryCnt != 0))
                {
                    /* Only abort if non Acknowledge Error occurs
                       In case of an Acknowledge Error the operation should be repeated*/
                    u16RetErr =  ALSTATUSCODE_EE_ERROR;
                    break;
                }
            }
            else
            {
                if ( access == ESC_RD )
                {
                    UINT16 u16BytesToCopy = (step << 1);

                    /* read access, get the data from register 0x508-0x50B(0x50F)*/
                    if((u16WordOffset + step) > wordsize)
                    {
                        /*less than "step" words are left => copy only last required Bytes*/
                        u16BytesToCopy = (wordsize - u16WordOffset) << 1;
                    }

                    HW_EscRead((UINT8 *) &pData[i], ESC_EEPROM_DATA_OFFSET, u16BytesToCopy);
                }
            }

            if(!(nControl & ESC_EEPROM_ERROR_MASK))
            {
                /* In case of Acknowledge Error repeat same operation, otherwise increment the address and proceed*/
                wordaddress += step;
                u16WordOffset +=step;
                RetryCnt = MAX_CMD_RETIRES;

/*ECATCHANGE_START(V5.11) ECAT2*/
                i += step;
            }
            else
            {
                RetryCnt --;
                if(RetryCnt > 0)
                {
                    /* Wait for 10ms until repeat EEPROM access */
                    INT32 i32TimeoutTicks = (INT32)(ECAT_TIMER_INC_P_MS * 10);
                    UINT16 u16CurTimer = 0;
                    UINT16 u16LastTimer = TimeCNT_Isr;

                    /* Start wait loop */
                    while(i32TimeoutTicks > 0)
                    {
                         u16CurTimer = TimeCNT_Isr;

                        if(u16LastTimer < u16CurTimer)
                        {
                            i32TimeoutTicks = i32TimeoutTicks - (u16LastTimer - u16CurTimer);
                        }
                        else
                        {
                            /* 16bit overrun*/
                            i32TimeoutTicks = i32TimeoutTicks - (0xFFFF - u16LastTimer) - u16CurTimer;
                        }

                        u16LastTimer = u16CurTimer;
                    }
                }
                else
                {
                    /* Abort EEPROM access if max retires are reached*/
                    u16RetErr =  ALSTATUSCODE_EE_ERROR;
                    break;
                }
            }
/*ECATCHANGE_END(V5.11) ECAT2*/
        } //for-loop over all data
    } // if EEPROM access is assigned to PDI
    else
    {
        u16RetErr = ALSTATUSCODE_EE_NOACCESS;
    }

    /* clear EEPROM control register 0x500 */
    nConfig = 0;

    HW_EscWriteWord(nConfig, ESC_EEPROM_CONFIG_OFFSET);
    return u16RetErr;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return     success : ALSTATUSCODE_WAITFORCOLDSTART
            failed  : EEPROM ERRROR Code

 \brief        This function recalculates the EEPROM CRC and writes the updated value to EEPROM.
            After writing the ESC Config Area a device restart is required!
 *////////////////////////////////////////////////////////////////////////////////////////
UINT16 ESC_EepromWriteCRC(void)
{
    UINT16 u16Return = ALSTATUSCODE_UNSPECIFIEDERROR;
    UINT16 EscCfgData[8];
    UINT16 u16Crc = 0x00FF;
    UINT16 i,j;

    u16Return = ESC_EepromAccess(0,7,(UINT16 *)EscCfgData,ESC_RD);
    if(u16Return == 0)
    {
        UINT8 *pData = (UINT8 *)EscCfgData;

        for(i = 0; i < 14; i++ )
        {
            u16Crc ^= pData[i];

            for(j=0; j<8; j++ )
            {
                if( u16Crc & 0x80 )
                    u16Crc = (u16Crc<<1) ^ 0x07;
                else
                    u16Crc <<= 1;
            }
        }

        /*only low Byte shall be written*/
        u16Crc &= 0x00FF;

        /*write new calculated Crc to Esc Config area*/
        u16Return = ESC_EepromAccess(7,1,&u16Crc,ESC_WR);
        if(u16Return == 0)
        {
            u16Return =  ALSTATUSCODE_WAITFORCOLDSTART;
        }
    }

    return u16Return;
}



/** @} */

