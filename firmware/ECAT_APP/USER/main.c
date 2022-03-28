/**
\addtogroup EtherCAT Main Function 
@{
*/


#include "sys.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "main.h"						
#include "main_data.h"	
#include "usart.h"
#include "gpio.h"
#include "at24c16.h" 
#include "ds18b20.h"
#include "ads1115a.h"
#include "ads1115b.h"
#include "ads1115c.h"
#include "Recieve_Send_Command_Done.h"
#include "menu.h"
#include "Boot_Initial.h"
#include "stmflash.h"
#include "iap.h"
#include "incappl.h"
#include "delay.h"

#include "do_led.h"
#include "di_key.h"
#include "timer.h"
#include "includes.h"
#include "ecat_def.h"
#include "applInterface.h"
#include "ad_da_spi.h"
#include "hw_readwrite.h"
#include "rs485.h"
#include "CAN_DATA.h"
#define _ROBOT_DEVICE_ 1
#include "Robot-Device.h"
#undef _ROBOT_DEVICE_

#include "testmode.h"

//static uint32_t dir;
//static uint32_t cnt;
//u8 uart_485[32];//���uart����ʱ��������

u8 i;

void start_task(void *pdata); 

extern void Adc_Temperate_Init(void); //����Adc_Temperate_Init����
/*--------------------------------------------------------------------------------------
------
------    local types and defines
------
--------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
------
------    local variables and constants

------
-----------------------------------------------------------------------------------------*/

u8 code; //means the init is ok


/*-----------------------------------------------------------------------------------------
------
------    application specific functions
------
-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
------
------    generic functions
------
-----------------------------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    The function is called when an error state was acknowledged by the master

*////////////////////////////////////////////////////////////////////////////////////////

void    APPL_AckErrorInd(UINT16 stateTrans)
{

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    AL Status Code (see ecatslv.h ALSTATUSCODE_....)

 \brief    The function is called in the state transition from INIT to PREOP when
             all general settings were checked to start the mailbox handler. This function
             informs the application about the state transition, the application can refuse
             the state transition when returning an AL Status error code.
            The return code NOERROR_INWORK can be used, if the application cannot confirm
            the state transition immediately, in that case this function will be called cyclically
            until a value unequal NOERROR_INWORK is returned//����������ǿ��Ʒ��ؿ����������ݵģ���ȻҲ�����ϴ�����״̬��
NOERROR_INWORK�������ֲ���״̬��

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StartMailboxHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return     0, NOERROR_INWORK

 \brief    The function is called in the state transition from PREEOP to INIT
             to stop the mailbox handler. This functions informs the application
             about the state transition, the application cannot refuse
             the state transition.Ҳ����˵������Ҫ��init���˵�ʱ�򣬱�����ˡ�

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StopMailboxHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param    pIntMask    pointer to the AL Event Mask which will be written to the AL event Mask
                        register (0x204) when this function is succeeded. The event mask can be adapted
                        in this function
 \return    AL Status Code (see ecatslv.h ALSTATUSCODE_....)

 \brief    The function is called in the state transition from PREOP to SAFEOP when
           all general settings were checked to start the input handler. This function
           informs the application about the state transition, the application can refuse
           the state transition when returning an AL Status error code.
           The return code NOERROR_INWORK can be used, if the application cannot confirm
           the state transition immediately, in that case the application need to be complete 
           the transition by calling ECAT_StateChange.������safeop���ɵ�ʱ����еģ������ʱû�취ȷ��״̬�ı䣬Ҳ���Ե���ECAT_StateChange�������
*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StartInputHandler(UINT16 *pIntMask)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return     0, NOERROR_INWORK

 \brief    The function is called in the state transition from SAFEOP to PREEOP
             to stop the input handler. This functions informs the application
             about the state transition, the application cannot refuse
             the state transition.

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StopInputHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    AL Status Code (see ecatslv.h ALSTATUSCODE_....)

 \brief    The function is called in the state transition from SAFEOP to OP when
             all general settings were checked to start the output handler. This function
             informs the application about the state transition, the application can refuse
             the state transition when returning an AL Status error code.
           The return code NOERROR_INWORK can be used, if the application cannot confirm
           the state transition immediately, in that case the application need to be complete 
           the transition by calling ECAT_StateChange.���ֻ��֪ͨû��״̬���󣬵���Ӧ�ó����ǿ���
�ܾ�״̬�ı�ͨ�����ش����룬��ȻҲ���Է�����ʱ�޷�֪��״̬�ı䣬������Ҫ����ECAT_StateChange
*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StartOutputHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return     0, NOERROR_INWORK

 \brief    The function is called in the state transition from OP to SAFEOP
             to stop the output handler. This functions informs the application
             about the state transition, the application cannot refuse
             the state transition.

*////////////////////////////////////////////////////////////////////////////////////////

UINT16 APPL_StopOutputHandler(void)
{
    return ALSTATUSCODE_NOERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
\return     0(ALSTATUSCODE_NOERROR), NOERROR_INWORK
\param      pInputSize  pointer to save the input process data length
\param      pOutputSize  pointer to save the output process data length

\brief    This function calculates the process data sizes from the actual SM-PDO-Assign
            and PDO mapping˵���ˣ�nPDoutputsize����ô�õ����أ�����ͨ�������������
����õ��ģ�������������������ָ������������npdoutputsize�ĵ�ַ�Ž�����Ȼ������ָ��
�����inputsize��outputsize��ֵ��input��outputsize������COEģʽ��
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 APPL_GenerateMapping(UINT16 *pInputSize,UINT16 *pOutputSize)
{
    UINT16 result = ALSTATUSCODE_NOERROR;
    UINT16 InputSize = 0;
    UINT16 OutputSize = 0;

#if COE_SUPPORTED
    UINT16 PDOAssignEntryCnt = 0;
    OBJCONST TOBJECT OBJMEM * pPDO = NULL;
    UINT16 PDOSubindex0 = 0;
    UINT32 *pPDOEntry = NULL;
    UINT16 PDOEntryCnt = 0;
   
    /*Scan object 0x1C12 RXPDO assign���ǿ��м���pdo*/
    for(PDOAssignEntryCnt = 0; PDOAssignEntryCnt < sRxPDOassign.u16SubIndex0; PDOAssignEntryCnt++)//����һ������ṹ��Ķ��壬u16SubIndex0=1������Ҳֻ��0��ʱ��Ż����
	//���for�������棬���assign�ǹ������ݵĶ��ķ�֧��������ȻҲ���Ժܶ࣬����ֻ��һ��
    {
        pPDO = OBJ_GetObjectHandle(sRxPDOassign.aEntries[PDOAssignEntryCnt]);//Ĭ�ϵ����ֵ��1600��Ҳ����get��ʵ�δ�С��1600�������ֵ�����������ȥ�ҳ���һ��pdo��ָ��
		//�൱����ͨ�����������ָ��������������ݵĻ�����
        if(pPDO != NULL)
        {
            PDOSubindex0 = *((UINT16 *)pPDO->pVarPtr);//�ṹ��ָ��ָ�����buffer����������������˻������û����ݾ��������Ȼ��ſ��Լ�����һ�������ݵĳ���
            for(PDOEntryCnt = 0; PDOEntryCnt < PDOSubindex0; PDOEntryCnt++)//���Ƕ�ÿ��pdo0�Ļ��������ֽ������м������ȥ��ÿ��pdo��
            {
                pPDOEntry = (UINT32 *)((UINT8 *)pPDO->pVarPtr + (OBJ_GetEntryOffset((PDOEntryCnt+1),pPDO)>>3));    //goto PDO entry������3λ���ڰ�1000����4λ�ŵ������
				//�൱������λ������ֽڣ�����pvarptr��ʲô�����������������1����������һ���������ĵ�һ���ֽ��Ǹ���������������Ҳ����PDOSubindex0
				//Ȼ��ͨ�����������ҵ��������Ĵ�С��Ȼ�����ε��ҵ�������������������ĵ�1�ֽڣ�Ҳ���Ǵ���������������������ݳ��ȵĵ�ַ��Ȼ�����outputsize���������ݳ���
				//11.23�����pdo����ȫ��ģ�����ǰ������������������ȵȵģ��������������Ӷ���
				//11.23����pdo����������ֵ��ʼ���ۼ�pdo�����������������ĵ�һ���ֽڵĳ���
				//12.8������������鷳������ͨ��sRxPDOassign�ҵ�1600�����Ҳ��������������ݵ�ͷ��Ҳ����pdo��Ȼ���ҵ�pdo���������׵�ַ��Ҳ����subindex0
				//subindex0�����˶����ж�������������ݣ�ʵ�����Ҳ��ǿ���ͨ�����������������ݸ�ֵ���õ�ʵ���ϵĹ������ݲ���������������Ҳ���ǲ���Ҫ
				//2000��3000�ˣ�ʵ���ϣ�7000010�������һ�����ݣ�ֻ������������ݻ�����Ӧ�Ķ�����ѣ�����˵Ϊʲô��70001000������������12345678�أ����
				//32λ��������ȻҲ�������������
				//�����ʽ�����棬����PDOָ��PVARPTR������ǳ�ʼ�ĵ�ַ��Ȼ���ټ���offset��ÿ��ֵ��Ӧ�ֽ�ƫ�ƣ���ô�������������������ĵ�ַ��Ȼ����ȡ(UINT8 *)
				//���������������ַ��ֵ��Ҳ����70000010���ֵ��Ȼ����������ֵ������ַ����ȡ���
                // we increment the expected output size depending on the mapped Entry
                OutputSize += (UINT16) ((*pPDOEntry) & 0xFF);//ֻҪ��8λ����Ϊǰ���0x70�ǲ���Ҫ�ģ�Ҳ�������������ڵõ�����һ������
            }
        }
        else
        {
            /*assigned PDO was not found in object dictionary. return invalid mapping��������ɼ���һ����Ҫ�ж��������ģ�һ��Ҫ����COE�Ľṹ��*/
            OutputSize = 0;
            result = ALSTATUSCODE_INVALIDOUTPUTMAPPING;
            break;
        }
    }

    OutputSize = (OutputSize + 7) >> 3;//+7�൱�ڼ����˳�ʼ������0��һ���ֽڣ�Ȼ������������������3λ���õ��ľ���������ݵ����������ǹ�������PDO�Ĵ�С��

    if(result == 0)
    {
        /*Scan Object 0x1C13 TXPDO assign*/
        for(PDOAssignEntryCnt = 0; PDOAssignEntryCnt < sTxPDOassign.u16SubIndex0; PDOAssignEntryCnt++)
        {
            pPDO = OBJ_GetObjectHandle(sTxPDOassign.aEntries[PDOAssignEntryCnt]);
            if(pPDO != NULL)
            {
                PDOSubindex0 = *((UINT16 *)pPDO->pVarPtr);//ָ���������ĵ�ַ��Ҳ����pdo�����ݵ�ַ����֮ǰ�Ѿ�ӳ�䵽pdo��
                for(PDOEntryCnt = 0; PDOEntryCnt < PDOSubindex0; PDOEntryCnt++)
                {
                    pPDOEntry = (UINT32 *)((UINT8 *)pPDO->pVarPtr + (OBJ_GetEntryOffset((PDOEntryCnt+1),pPDO)>>3));    //goto PDO entry
                    // we increment the expected output size depending on the mapped Entry
                    InputSize += (UINT16) ((*pPDOEntry) & 0xFF);
                }
            }
            else
            {
                /*assigned PDO was not found in object dictionary. return invalid mapping*/
                InputSize = 0;
                result = ALSTATUSCODE_INVALIDINPUTMAPPING;
                break;
            }
        }
    }
    InputSize = (InputSize + 7) >> 3;

//#else
//#if _WIN32
//   #pragma message ("Warning: Define 'InputSize' and 'OutputSize'.")
//#else
//    #warning "Define 'InputSize' and 'OutputSize'."//
//#endif
#endif

    *pInputSize = InputSize;
    *pOutputSize = OutputSize;
    return result;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
\param      pData  pointer to input process data

\brief      This function will copies the inputs from the local memory to the ESC memory
            to the hardware
*////////////////////////////////////////////////////////////////////////////////////////
void APPL_InputMapping(UINT16* pData)//���������TOBJ6000����ṹ����������������ָ�룬Ȼ�����ָ���ֽ��Ű�����ͨ��HWд�жϷ���ȥ�����������Ȥ�ĵط���
	/*������һ����ȡ��ַ��ʱ�򣬴�IN_GENERIC0x6000�ĵ�2���ֽڿ�ʼ����ϸ��һ������ṹ��Ķ���֪���ýṹ��ǿ��ת��������ĵ�һ���ֽ���u16SubIndex0���⵱Ȼ����Ҫ�ϴ������ݿ�
�ڶ����Ƚ���Ȥ�ĵط����ǣ��ϴ����ݵ���������2���֣���һ��������Ҳ�����ˣ������������Ļ�������bit8��bit7Ҳ�����ˣ�*/
{
	
   memcpy(pData,&(((UINT8*)&IN_GENERIC0x6000)[2]),SIZEOF(IN_GENERIC0x6000)-2);
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
\param      pData  pointer to output process data

\brief    This function will copies the outputs from the ESC memory to the local memory
            to the hardware
*////////////////////////////////////////////////////////////////////////////////////////
void APPL_OutputMapping(u16* pData)
{

  memcpy(&(((u8*)&OUT_GENERIC0x7000)[2]),pData,SIZEOF(OUT_GENERIC0x7000)-2);

}


/////////////////////////////////////////////////////////////////////////////////////////
/**
\brief    This function will called from the synchronisation ISR 
            or from the mainloop if no synchronisation is supported
*////////////////////////////////////////////////////////////////////////////////////////


void process_app(TOBJ7000 *OUT_GENERIC, TOBJ6000 *IN_GENERIC)//����Ҫ��һ�µ�ַ��ӳ�䣬Ҳ����˵��������ָ��Ҫ��ô��Ӧ��STM32���ڴ�
{
    volatile u16 dummy;

}
 
void APPL_Application(void)
{

	U485_process_data(&OUT_GENERIC0x7000, &IN_GENERIC0x6000);//485�����ݽ����ڴ˽���
	CAN_process_data(&OUT_GENERIC0x7000, &IN_GENERIC0x6000);//485�����ݽ����ڴ˽���
	DI_process_data(&IN_GENERIC0x6000 );						//DI���ݵĽ����ڴ˽���
	DO_process_data(&OUT_GENERIC0x7000);                       // DO���ݵĽ����ڴ˽���
	ADC_process_data(&IN_GENERIC0x6000);						//ADC���ݽ����ڴ˽���

}

#if EXPLICIT_DEVICE_ID
/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    The Explicit Device ID of the EtherCAT slave

 \brief     Calculate the Explicit Device ID���Ӧ��С�ģ�ʲô�ǵõ������豸ID��

*////////////////////////////////////////////////////////////////////////////////////////
UINT16 APPL_GetDeviceID()
{
//#if _WIN32
//   #pragma message ("Warning: Implement explicit Device ID latching")
//#else
//    #warning "Implement explicit Device ID latching"
//#endif
    /* Explicit Device 5 is expected by Explicit Device ID conformance tests*/
    return 0x5;
}
#endif





//const u8 TEXT_Buffer[]={"Explorer STM32F4 SPI TEST"};
//#define SIZE sizeof(TEXT_Buffer)	

//////////////////////////////////////////////////////////////////////
/////-----
/////-----�����Ǹ����������Ķ�ջ����������
/////-----
//////////////////////////////////////////////////////////////////////
	

//ECAT����
//�������ȼ�
#define ETHERCAT_TASK_PRIO		7
//�����ջ��С
#define ETHERCAT_STK_SIZE		1024
//�����ջ
OS_STK	ETHERCAT_TASK_STK[ETHERCAT_STK_SIZE];
//������
void ethercat_task(void *pdata);  

//START����
//�������ȼ�
#define START_TASK_PRIO		12
//�����ջ��С
#define START_STK_SIZE		128
//�����ջ
OS_STK START_TASK_STK[START_STK_SIZE];
//������	

void start_task(void *pdata);
void work_mode_operation(void);

int main(void)
{
	SCB->VTOR = FLASH_BASE | 0x10000;
	code=HW_Init();
// 	if(!code)
//	{
//		MainInit();
//	}

	OSInit(); 					//UCOS��ʼ��		//http��ʼ��
	OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO);
	OSStart(); //����UCOS
}



//start����
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr;
	pdata = pdata ;
	
	OSStatInit();  			//��ʼ��ͳ������
	OS_ENTER_CRITICAL();  	//�����ٽ������޷����жϴ�ϣ�
	OSTaskCreate(ethercat_task,(void*)0,(OS_STK*)&ETHERCAT_TASK_STK[ETHERCAT_STK_SIZE-1],ETHERCAT_TASK_PRIO); 	//����ECAT����
	OSTaskSuspend(OS_PRIO_SELF); //����start_task����
	OS_EXIT_CRITICAL();  //�˳��ٽ��������Ա��жϴ�ϣ�
}

uint16_t test_off_flag =  1;
void ethercat_task(void *pdata)
{
	bRunApplication = TRUE;
	do
	{
//		MainLoop(); 
		
//		if(led_blink_flag)		
//		{
//			led_blink_flag=0;
//			//����ָʾ��							
//			GPIOC->ODR ^= GPIO_Pin_4;		
//		}
		

//			DI_process_data(&IN_GENERIC0x6000 );						//DI���ݵĽ����ڴ˽���
			
		work_mode_operation();
					

		//test mode
//		if(Test_Mode0x8015 == 1)
//		{
//			if(tm_rs485_rxflag	== 1)
//			{
//				rs485_tm_sendack();
//				tm_rs485_rxflag	= 0;
//			}
//			
//			if(tm_can_rxflag == 1)
//			{
//				can_tm_sendack();
//				tm_can_rxflag = 0;
//			}
//		}

	} while (bRunApplication == TRUE);
}

uint8_t safe_48v_switch_flag = 1;
uint8_t sampling_flag = 1;  //Ĭ�ϵ�������·����Ҫ�������
void work_mode_operation(void)
{
	static u8 oc_st_count1=0, oc_st_count2=0;

	switch(power_manage.work_mode)		//
	{
		case 0:		//����ģʽ
		{
			sampling_flag = 1;
			if(ad_fast_flag)		//10ms
			{
				ad_fast_flag=0;
				adc_get_data();
			}
			break;
		}				
		case 1:		//�ϵ�ģʽ
		{
			sampling_flag = 1;
			if(ad_fast_flag)		//10ms
			{
				ad_fast_flag=0;
				adc_get_data();
			}
			first_open_dr_save_state();			//��remote 	24V1  ��������ź� 24V2
			power_manage.work_mode = 2;			//������ģʽ
			power_manage.p_state.b.SYSTEM_RUN = 1;
			break;
		}
		case 2:		//mode=2��������no����
		{
			if(ad_fast_flag)		//10ms
			{
				ad_fast_flag=0;				
				adc_get_data();
						
//				if(0 == SAFE_48V_SWITCH)	//��ʼ��ʱ
				if(0 == safe_48v_switch_flag)	//��ʼ��ʱ
				{
					oc_st_count1++;
					if(oc_st_count1>150)				//ʱ�䵽���������  100*10ms=1.5s
					{
						oc_st_count1=0;
						
						OCPROTECT_DR = 1;					//�����������
						power_manage.p_state.b.DC48V_OC=1;	

						sampling_flag = 0;									
						power_manage.work_mode = 3;	//����������
					}		
				}				
			}	
			
			//if(adcok_flag==1)		//why waiting for adc ok???		ysgang 2021.12.30
			{
				USART1_Data_Recieve();			//������������	
				
				if(upload_flag==1)	//500ms
				{
					upload_flag=0;				
					usart1_send_upload_data();	//��������ʱ��Ҫ�Ѵ˺�������								
				}	
				
				//Alarm_Manage();		/* remove it. ysgang 2021.12.30 */
			}
			
			break;
		}
		case 3:		//mode=3������������
		{
			if(ad_slow_flag)		//20ms
			{
				ad_slow_flag=0;
				
				adc_get_data();
				
				//�е�ѹ,����   24-65v
//				if(SAFE_48V_SWITCH == 1)
				if(safe_48v_switch_flag == 1)
				{
					oc_st_count2++;
					
					if(oc_st_count2>5)				//5��
					{
						oc_st_count2=0;
						
						OCPROTECT_DR = 0;										//�����������
						power_manage.p_state.b.DC48V_OC=0;		
						
						sampling_flag = 1;				
						power_manage.work_mode = 2;					//������no����
					}
				}
				else
				{
					oc_st_count2=0;
				}				
			}


			USART1_Data_Recieve();		//������������	

			if(upload_flag)		//500ms
			{
				upload_flag=0;
				usart1_send_upload_data();
			}

			//Alarm_Manage();		/* remove it. ysgang 2021.12.30 */
			
			break;
		}
		case 4:		//mode=4	Զ�̰����ػ�ģʽ����������ָ�����Ӧ�����κ����,����֮ǰ�Ĺ���ģʽ
		{
			USART1_Data_Recieve();		//������������

			//��������ػ�ָ��ʱ�䵽����δ�յ�ȷ��
			if((1==send_code3_flag)&&(0==receive_code3_flag))
			{
				//send_code3_flag=0;		//why clear it here??? lead to send only once! ysgang 2022.1.29				
				send_code3_flag=0;
				
				usart1_send_code3_cmd();
				code3_times++;
				
				if(code3_times>=CODE3_TIMES)			//�ط���������
				{
					send_code3_flag=0;		//should clear it here and receive handler!
					power_manage.work_mode = last_workmode;	//�ص�֮ǰ����ģʽ��������������ǰԶ�̹ػ�����ʧ��
					code3_times = 0;
					code3_delay_st = 0;							//3�ζ��ѷ����꣬�����ط�����ָ��
				}
				else
				{
					code3_delay_st = 1;							//������ʱ��־
				}
			}
			
			break;
		}
		case 5:		//mode=5 	�յ��ػ�ָ��ȴ����ط���ΪLʱ���ػ�
		{
			receive_code3_flag = 0;				//�����־�������������

			if(ad_slow_flag)		//20ms
			{
				ad_slow_flag=0;
				
				adc_get_data();			
			}
			
			USART1_Data_Recieve();				//������������	

//			if((1==receive_code4_flag)&&(0==power_manage.p_state.b.MCON_FKIN))
			if(1==receive_code4_flag)
			{
				delay_ms(10000);
				
				receive_code4_flag = 0;			//�����־�������������
				force_shutdown(0);			
			}
				
			break;
		}
		case 6:		//mode=6 	�����е�Դ��ص�����ģʽ
		{
			//delay_ms(10000);
			force_shutdown(0);
			break;
		}
		case 7:  //�쳣ģʽ
		{
			if(upload_flag)		//500ms
			{
				upload_flag=0;
				usart1_send_upload_data();
				DC48V_ES_SHUTDOWN_DR = 0; 
				power_manage.p_constate.b.DC48V_ES_shutdown = 1;				
			}					
			sampling_flag = 0;
			break;
		}
		default:
			break;
	}

	if(adcok_flag == 1)		//finish reading all the adc channels
	{
		adcok_flag = 0;
		if(Alarm_Manage() != 0)
		{
			power_manage.work_mode = 7;
		}
	}
}


