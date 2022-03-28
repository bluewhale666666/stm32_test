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
//u8 uart_485[32];//针对uart的临时缓存数组

u8 i;

void start_task(void *pdata); 

extern void Adc_Temperate_Init(void); //声明Adc_Temperate_Init函数
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
            until a value unequal NOERROR_INWORK is returned//这个函数就是控制返回开启邮箱数据的，当然也可以上传不定状态。
NOERROR_INWORK就是这种不定状态。

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
             the state transition.也就是说，当需要往init回退的时候，必须回退。

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
           the transition by calling ECAT_StateChange.这是向safeop过渡的时候进行的，如果暂时没办法确认状态改变，也可以调用ECAT_StateChange来解决。
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
           the transition by calling ECAT_StateChange.这个只是通知没有状态错误，但是应用程序还是可以
拒绝状态改变通过返回错误码，当然也可以返回暂时无法知道状态改变，但是需要调用ECAT_StateChange
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
            and PDO mapping说白了，nPDoutputsize是怎么得到的呢，就是通过下面这个函数
计算得到的，这个函数的入口是两个指针变量，负责把npdoutputsize的地址放进来，然后两个指针
最后由inputsize和outputsize赋值，input和outputsize又是在COE模式下
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
   
    /*Scan object 0x1C12 RXPDO assign先是看有几个pdo*/
    for(PDOAssignEntryCnt = 0; PDOAssignEntryCnt < sRxPDOassign.u16SubIndex0; PDOAssignEntryCnt++)//看了一下这个结构体的定义，u16SubIndex0=1，所以也只有0的时候才会进到
	//这个for函数里面，这个assign是过程数据的读的分支个数，当然也可以很多，这里只有一个
    {
        pPDO = OBJ_GetObjectHandle(sRxPDOassign.aEntries[PDOAssignEntryCnt]);//默认的这个值是1600，也就是get的实参大小是1600，对象字典根据这个索引去找出来一个pdo的指针
		//相当于是通过了这个索引指向了输出过程数据的缓存区
        if(pPDO != NULL)
        {
            PDOSubindex0 = *((UINT16 *)pPDO->pVarPtr);//结构体指针指向对象buffer，这个就是数据区了基本上用户数据就是在这里，然后才可以计算下一级的数据的长度
            for(PDOEntryCnt = 0; PDOEntryCnt < PDOSubindex0; PDOEntryCnt++)//这是对每个pdo0的缓存区的字节数进行计算就是去找每个pdo的
            {
                pPDOEntry = (UINT32 *)((UINT8 *)pPDO->pVarPtr + (OBJ_GetEntryOffset((PDOEntryCnt+1),pPDO)>>3));    //goto PDO entry，右移3位等于把1000，第4位放到了最后
				//相当于是由位变成了字节，至于pvarptr是什么，这就是数据区，是1级数据区，一级数据区的第一个字节是该数据区的数量，也就是PDOSubindex0
				//然后通过子索引，找到子索引的大小，然后依次的找到这个子索引的子索引的第1字节，也就是存放子索引的子索引的数据长度的地址，然后给到outputsize，就是数据长度
				//11.23：这个pdo可是全面的，包括前，后，索引号入口描述等等的，它包括了所有子对象
				//11.23：从pdo的子索引的值开始，累加pdo的子索引的子索引的第一个字节的长度
				//12.8：这个函数不麻烦，先是通过sRxPDOassign找到1600这个读也就是输出过程数据的头部也就是pdo，然后找到pdo的数据区首地址，也就是subindex0
				//subindex0表明了对象有多少输出过程数据，实际上我不是可以通过给这个输出过程数据赋值而得到实际上的过程数据操作吗？这样看来，也就是不需要
				//2000和3000了，实际上，7000010这个就是一个数据，只不过对这个数据还有相应的定义而已，就是说为什么是70001000，而不是随意12345678呢，这个
				//32位的数据自然也有其道理在里面
				//在这个式子里面，先由PDO指向PVARPTR，这个是初始的地址，然后再加上offset是每个值对应字节偏移，那么加起来，就是子索引的地址，然后再取(UINT8 *)
				//就是这个子索引地址的值，也就是70000010这个值，然后把这个索引值当作地址，再取这个
                // we increment the expected output size depending on the mapped Entry
                OutputSize += (UINT16) ((*pPDOEntry) & 0xFF);//只要后8位，因为前面的0x70是不需要的，也不是数，你现在得到的是一个数据
            }
        }
        else
        {
            /*assigned PDO was not found in object dictionary. return invalid mapping，从这里可见，一定是要有对象索引的，一定要定义COE的结构的*/
            OutputSize = 0;
            result = ALSTATUSCODE_INVALIDOUTPUTMAPPING;
            break;
        }
    }

    OutputSize = (OutputSize + 7) >> 3;//+7相当于加上了初始的索引0的一个字节，然后把这个数量，往右移3位，得到的就是输出数据的量，差不多就是过程数据PDO的大小了

    if(result == 0)
    {
        /*Scan Object 0x1C13 TXPDO assign*/
        for(PDOAssignEntryCnt = 0; PDOAssignEntryCnt < sTxPDOassign.u16SubIndex0; PDOAssignEntryCnt++)
        {
            pPDO = OBJ_GetObjectHandle(sTxPDOassign.aEntries[PDOAssignEntryCnt]);
            if(pPDO != NULL)
            {
                PDOSubindex0 = *((UINT16 *)pPDO->pVarPtr);//指向数据区的地址，也就是pdo的数据地址在这之前已经映射到pdo了
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
void APPL_InputMapping(UINT16* pData)//这个函数把TOBJ6000这个结构体里面的数给到这个指针，然后这个指针又接着把数据通过HW写中断发出去，这个函数有趣的地方在
	/*两个，一个是取地址的时候，从IN_GENERIC0x6000的第2个字节开始，仔细看一下这个结构体的定义知道该结构体强制转换的数组的第一个字节是u16SubIndex0，这当然不是要上传的数据咯
第二个比较有趣的地方就是，上传数据的数量少了2个字，第一个字少了也就少了，可以少两个的话岂不是连bit8和bit7也不传了？*/
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


void process_app(TOBJ7000 *OUT_GENERIC, TOBJ6000 *IN_GENERIC)//这里要做一下地址的映射，也就是说，这两个指针要怎么对应到STM32的内存
{
    volatile u16 dummy;

}
 
void APPL_Application(void)
{

	U485_process_data(&OUT_GENERIC0x7000, &IN_GENERIC0x6000);//485的数据交换在此进行
	CAN_process_data(&OUT_GENERIC0x7000, &IN_GENERIC0x6000);//485的数据交换在此进行
	DI_process_data(&IN_GENERIC0x6000 );						//DI数据的交换在此进行
	DO_process_data(&OUT_GENERIC0x7000);                       // DO数据的交换在此进行
	ADC_process_data(&IN_GENERIC0x6000);						//ADC数据交换在此进行

}

#if EXPLICIT_DEVICE_ID
/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    The Explicit Device ID of the EtherCAT slave

 \brief     Calculate the Explicit Device ID这个应该小心，什么是得到复杂设备ID呢

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
/////-----下面是给各任务分配的堆栈及任务配置
/////-----
//////////////////////////////////////////////////////////////////////
	

//ECAT任务
//任务优先级
#define ETHERCAT_TASK_PRIO		7
//任务堆栈大小
#define ETHERCAT_STK_SIZE		1024
//任务堆栈
OS_STK	ETHERCAT_TASK_STK[ETHERCAT_STK_SIZE];
//任务函数
void ethercat_task(void *pdata);  

//START任务
//任务优先级
#define START_TASK_PRIO		12
//任务堆栈大小
#define START_STK_SIZE		128
//任务堆栈
OS_STK START_TASK_STK[START_STK_SIZE];
//任务函数	

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

	OSInit(); 					//UCOS初始化		//http初始化
	OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO);
	OSStart(); //开启UCOS
}



//start任务
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr;
	pdata = pdata ;
	
	OSStatInit();  			//初始化统计任务
	OS_ENTER_CRITICAL();  	//进入临界区（无法被中断打断）
	OSTaskCreate(ethercat_task,(void*)0,(OS_STK*)&ETHERCAT_TASK_STK[ETHERCAT_STK_SIZE-1],ETHERCAT_TASK_PRIO); 	//创建ECAT任务
	OSTaskSuspend(OS_PRIO_SELF); //挂起start_task任务
	OS_EXIT_CRITICAL();  //退出临界区（可以被中断打断）
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
//			//工作指示灯							
//			GPIOC->ODR ^= GPIO_Pin_4;		
//		}
		

//			DI_process_data(&IN_GENERIC0x6000 );						//DI数据的交换在此进行
			
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
uint8_t sampling_flag = 1;  //默认电阻接入电路，需要检测热量
void work_mode_operation(void)
{
	static u8 oc_st_count1=0, oc_st_count2=0;

	switch(power_manage.work_mode)		//
	{
		case 0:		//待机模式
		{
			sampling_flag = 1;
			if(ad_fast_flag)		//10ms
			{
				ad_fast_flag=0;
				adc_get_data();
			}
			break;
		}				
		case 1:		//上电模式
		{
			sampling_flag = 1;
			if(ad_fast_flag)		//10ms
			{
				ad_fast_flag=0;
				adc_get_data();
			}
			first_open_dr_save_state();			//开remote 	24V1  输出反馈信号 24V2
			power_manage.work_mode = 2;			//主工作模式
			power_manage.p_state.b.SYSTEM_RUN = 1;
			break;
		}
		case 2:		//mode=2，动力电no启动
		{
			if(ad_fast_flag)		//10ms
			{
				ad_fast_flag=0;				
				adc_get_data();
						
//				if(0 == SAFE_48V_SWITCH)	//开始计时
				if(0 == safe_48v_switch_flag)	//开始计时
				{
					oc_st_count1++;
					if(oc_st_count1>150)				//时间到，启动输出  100*10ms=1.5s
					{
						oc_st_count1=0;
						
						OCPROTECT_DR = 1;					//过流防护输出
						power_manage.p_state.b.DC48V_OC=1;	

						sampling_flag = 0;									
						power_manage.work_mode = 3;	//动力电启动
					}		
				}				
			}	
			
			//if(adcok_flag==1)		//why waiting for adc ok???		ysgang 2021.12.30
			{
				USART1_Data_Recieve();			//正常接收数据	
				
				if(upload_flag==1)	//500ms
				{
					upload_flag=0;				
					usart1_send_upload_data();	//正常工作时需要把此函数加上								
				}	
				
				//Alarm_Manage();		/* remove it. ysgang 2021.12.30 */
			}
			
			break;
		}
		case 3:		//mode=3，动力电启动
		{
			if(ad_slow_flag)		//20ms
			{
				ad_slow_flag=0;
				
				adc_get_data();
				
				//判电压,电流   24-65v
//				if(SAFE_48V_SWITCH == 1)
				if(safe_48v_switch_flag == 1)
				{
					oc_st_count2++;
					
					if(oc_st_count2>5)				//5次
					{
						oc_st_count2=0;
						
						OCPROTECT_DR = 0;										//过流防护输出
						power_manage.p_state.b.DC48V_OC=0;		
						
						sampling_flag = 1;				
						power_manage.work_mode = 2;					//动力电no启动
					}
				}
				else
				{
					oc_st_count2=0;
				}				
			}


			USART1_Data_Recieve();		//正常接收数据	

			if(upload_flag)		//500ms
			{
				upload_flag=0;
				usart1_send_upload_data();
			}

			//Alarm_Manage();		/* remove it. ysgang 2021.12.30 */
			
			break;
		}
		case 4:		//mode=4	远程按键关机模式，发送请求指令，无响应发三次后忽略,进入之前的工作模式
		{
			USART1_Data_Recieve();		//正常接收数据

			//发送请求关机指令时间到，且未收到确认
			if((1==send_code3_flag)&&(0==receive_code3_flag))
			{
				//send_code3_flag=0;		//why clear it here??? lead to send only once! ysgang 2022.1.29				
				send_code3_flag=0;
				
				usart1_send_code3_cmd();
				code3_times++;
				
				if(code3_times>=CODE3_TIMES)			//重发次数计数
				{
					send_code3_flag=0;		//should clear it here and receive handler!
					power_manage.work_mode = last_workmode;	//回到之前工作模式，继续工作，当前远程关机操作失败
					code3_times = 0;
					code3_delay_st = 0;							//3次都已发送完，不再重发请求指令
				}
				else
				{
					code3_delay_st = 1;							//正在延时标志
				}
			}
			
			break;
		}
		case 5:		//mode=5 	收到关机指令，等待主控反馈为L时，关机
		{
			receive_code3_flag = 0;				//清除标志，避免后续再用

			if(ad_slow_flag)		//20ms
			{
				ad_slow_flag=0;
				
				adc_get_data();			
			}
			
			USART1_Data_Recieve();				//正常接收数据	

//			if((1==receive_code4_flag)&&(0==power_manage.p_state.b.MCON_FKIN))
			if(1==receive_code4_flag)
			{
				delay_ms(10000);
				
				receive_code4_flag = 0;			//清除标志，避免后续再用
				force_shutdown(0);			
			}
				
			break;
		}
		case 6:		//mode=6 	断所有电源后回到待机模式
		{
			//delay_ms(10000);
			force_shutdown(0);
			break;
		}
		case 7:  //异常模式
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


