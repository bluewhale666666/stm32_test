#include "tim.h"

#include "main.h"							//������ͷ�ļ�
#include "ioin.h"							//������ͷ�ļ�

#include "menu.h"


//TIM5��ʱ��ʼ����5ms���ڸ��ּ�ʱ
void tim5_init(void)
{ 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStructure; 
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE); 				//��ʼ����ʱ��ʱ��|RCC_APB1Periph_TIM3
		
	//5ms TIM2_IRQn
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;	 						//��ͨ�ö�ʱ��TIM6�ж�����
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;			//��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;  					//�����ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;	   						//�ж�ʹ��
	NVIC_Init(&NVIC_InitStructure);															//����ͨ�ö�ʱ��TIM6�ж�
	
	TIM_DeInit(TIM5);
	TIM_TimeBaseInitStruct.TIM_Prescaler=168-1;   //Ԥ��Ƶϵ��0,168/168000000=0.000001
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up; 				//���ϼ���ģʽ
	TIM_TimeBaseInitStruct.TIM_Period=4999;														//�Զ�װ��ֵ(4999+1)*0.000001=0.005s
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;   
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseInitStruct); 									//1ms��ʱ�趨
		
	TIM_SelectMasterSlaveMode(TIM5,TIM_MasterSlaveMode_Disable); 			//�ر�����ģʽ��ʹ���ڲ�ʱ�� 
	TIM_UpdateDisableConfig(TIM5,DISABLE);  													//����ʱ������
	TIM_Cmd(TIM5,ENABLE);																							//������ʱ��
	TIM_ClearITPendingBit(TIM5,TIM_IT_Update);												//�嶨ʱ�ж� 
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE); 													//����1ms�����ж�
} 


//���Ź���ʼ��
//���Ƶ��Ϊ64,����ֵΪ625,���ʱ��Ϊ1s	   
//prer*rlr/40000 = x.xxs
//void IWDG_Init(uint8_t prer,uint16_t rlr) 
//{	
// 	RCC_LSICmd(ENABLE);										//��LSIʱ��
//	
//	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);  //ʹ�ܶԼĴ���IWDG_PR��IWDG_RLR��д����
//	
//	IWDG_SetPrescaler(prer);  //����IWDGԤ��Ƶֵ:����IWDGԤ��ƵֵΪ64
//	
//	IWDG_SetReload(rlr);  //����IWDG��װ��ֵ
//	
//	IWDG_ReloadCounter();  //����IWDG��װ�ؼĴ�����ֵ��װ��IWDG������
//	
//	IWDG_Enable();  //ʹ��IWDG
//}

////ι�������Ź�
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

//T6��ʱ��5ms��ʱ�жϷ�����,���ּ�ʱ
void TIM5_IRQHandler(void)
{	
//	uint8_t i;
	static vu16 time_5ms_ant=0,time_5ms_ant1=0;
	static vu8	time_10ms_ant=0,time_20ms_ant=0,time_100ms_ant=0,time_1s_ant=0;
	static u8   sampling_cnt = 0;
	
	if(TIM_GetITStatus(TIM5,TIM_IT_Update)==SET)	//�ж��Ƿ�ΪTIM6��ʱ�ж�
	{
		if(!time_2s_flag)		//=0ʱ�Ž�����ֻ����һ��
		{
			time_5ms_ant++;

			if(time_5ms_ant>=400)		//��LED��BUZZER	
			{
				time_2s_flag=1;
				time_5ms_ant = 0;
			}
		}
		else								//������
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
						
			if(1==code3_delay_st)		//������ʱ��־(0-δ��ʱ��1-������ʱ)
			{
				delay_count++; 
				if(delay_count>=200)			//1s
				{
					delay_count=0;
					send_code3_flag=1;			//����ػ�ָ�����
				}
			}	
			
		}
		TIM_ClearITPendingBit(TIM5,TIM_IT_Update);	//�嶨ʱ�ж� 
  }
}
*/

/************************END OF FILE****/
