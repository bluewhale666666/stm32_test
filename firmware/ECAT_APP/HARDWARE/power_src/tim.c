#include "tim.h"

#include "main.h"							//主函数头文件
#include "ioin.h"							//主函数头文件

#include "menu.h"


//TIM5定时初始化，5ms用于各种计时
void tim5_init(void)
{ 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStructure; 
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE); 				//初始化定时器时钟|RCC_APB1Periph_TIM3
		
	//5ms TIM2_IRQn
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;	 						//对通用定时器TIM6中断设置
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;			//先占优先级为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;  					//从优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;	   						//中断使能
	NVIC_Init(&NVIC_InitStructure);															//配置通用定时器TIM6中断
	
	TIM_DeInit(TIM5);
	TIM_TimeBaseInitStruct.TIM_Prescaler=168-1;   //预分频系数0,168/168000000=0.000001
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up; 				//向上计数模式
	TIM_TimeBaseInitStruct.TIM_Period=4999;														//自动装载值(4999+1)*0.000001=0.005s
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;   
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseInitStruct); 									//1ms定时设定
		
	TIM_SelectMasterSlaveMode(TIM5,TIM_MasterSlaveMode_Disable); 			//关闭主从模式，使用内部时钟 
	TIM_UpdateDisableConfig(TIM5,DISABLE);  													//允许定时器更新
	TIM_Cmd(TIM5,ENABLE);																							//开启定时器
	TIM_ClearITPendingBit(TIM5,TIM_IT_Update);												//清定时中断 
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE); 													//开启1ms更新中断
} 


//看门狗初始化
//与分频数为64,重载值为625,溢出时间为1s	   
//prer*rlr/40000 = x.xxs
//void IWDG_Init(uint8_t prer,uint16_t rlr) 
//{	
// 	RCC_LSICmd(ENABLE);										//开LSI时钟
//	
//	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);  //使能对寄存器IWDG_PR和IWDG_RLR的写操作
//	
//	IWDG_SetPrescaler(prer);  //设置IWDG预分频值:设置IWDG预分频值为64
//	
//	IWDG_SetReload(rlr);  //设置IWDG重装载值
//	
//	IWDG_ReloadCounter();  //按照IWDG重装载寄存器的值重装载IWDG计数器
//	
//	IWDG_Enable();  //使能IWDG
//}

////喂独立看门狗
//void IWDG_Feed(void)
//{   
// 	IWDG_ReloadCounter();										   
//}
//	
/*
extern uint8_t sampling_flag;
extern uint16_t test_i_value;
double heat_sum_value = 0;
double test_heat_sum_value = 0;

//T6定时器5ms定时中断服务函数,各种计时
void TIM5_IRQHandler(void)
{	
//	uint8_t i;
	static vu16 time_5ms_ant=0,time_5ms_ant1=0;
	static vu8	time_10ms_ant=0,time_20ms_ant=0,time_100ms_ant=0,time_1s_ant=0;
	static u8   sampling_cnt = 0;
	
	if(TIM_GetITStatus(TIM5,TIM_IT_Update)==SET)	//判断是否为TIM6定时中断
	{
		if(!time_2s_flag)		//=0时才进来，只进来一次
		{
			time_5ms_ant++;

			if(time_5ms_ant>=400)		//关LED和BUZZER	
			{
				time_2s_flag=1;
				time_5ms_ant = 0;
			}
		}
		else								//正常后
		{
			time_5ms_ant++;
			time_5ms_ant1++;	
			
			if(time_5ms_ant1>power_manage.upload_time/5)
			{
				upload_flag=1;
				time_5ms_ant1=0;				
			}			
			
			if(time_5ms_ant>=2)		//10ms
			{
				if(sampling_flag == 1)
				{	
					  if(test_i_value >= 1000)
						{
						   test_i_value = 0;
						}
						
						heat_sum_value = heat_sum_value + ((int)(test_i_value*0.01)*(int)(test_i_value*0.01)) -0.5;   		
						test_heat_sum_value = heat_sum_value;
						
						if(heat_sum_value <= 0.0)	
						{
							heat_sum_value = 0.0;
						}
						else if(heat_sum_value >2000)
						{
							power_manage.p_breakdownh.b.Res_overheat = 1;
							power_manage.work_mode = 7;							
						}
						else
						{
							while(0);
						}				
				}
				else
				{
				  heat_sum_value = 0.0;
				}
				
				
				time_5ms_ant=0;
				time_10ms_ant++;
				
				ad_fast_flag=1;			//10ms
				
				keyscan(power_manage.work_mode);
				
				if(time_10ms_ant>=2)		//20ms
				{
					time_10ms_ant=0;					
					time_20ms_ant++;
					
					ad_slow_flag=1;			
					
					if(time_20ms_ant>=5)	//100ms
					{
						time_20ms_ant=0;					
						time_100ms_ant++;	
						
						if(time_100ms_ant>=10)		//1000ms
						{
							time_100ms_ant=0;					
							time_1s_ant++;
							
							time_ds18b_flag=1;
							led_slow_flag = 1;					

							if(time_1s_ant>=60)			//60s
							{
								time_1s_ant=0;
							}
						}							
					}					
				}
			}
						
			if(1==code3_delay_st)		//正在延时标志(0-未延时，1-正在延时)
			{
				delay_count++; 
				if(delay_count>=200)			//1s
				{
					delay_count=0;
					send_code3_flag=1;			//请求关机指令继续
				}
			}	
			
		}
		TIM_ClearITPendingBit(TIM5,TIM_IT_Update);	//清定时中断 
  }
}
*/

/************************END OF FILE****/
