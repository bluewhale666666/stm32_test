#include "timer.h"
#include "do_led.h"
#include "ecatappl.h"
#include "ecatslv.h"
#include "hw_readwrite.h" 
#include "rs485.h"	 
#include "incappl.h"
#include "CAN_DATA.h"
#include "testmode.h"

#include "main.h"	
#include "ioin.h"							
#include "menu.h"

//通用定时器3中断初始化
//arr：自动重装值。
//psc：时钟预分频数
//定时器溢出时间计算方法:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=定时器工作频率,单位:Mhz
//这里使用的是定时器3!

u32 TimeCNT_Isr;
u16 LED_slow_count;
u16 LED_single_count;
u16 LED_fast_count;

void TIM2_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  ///使能TIM3时钟
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//初始化TIM3
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_Cmd(TIM2,ENABLE); //使能定时器2
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/** 
   *@brief   Encoder Configuration
   *@param   None
   *@note    A: PA6(TIM3_CH1) 
             B: PA7(TIM3_CH2)  
			       Z: PB0(TIM3_CH3)
   *@return  None
   *@author  liu  
   *@date    2021/11/8    
   *@version V1.0.0 
   */
void TIM_ENCODER_Configuration(void)
{
  GPIO_InitTypeDef         GPIO_InitStructure;
  TIM_ICInitTypeDef        TIM_ICInitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef         NVIC_InitStructure;
	
  /* 时钟配置 */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  	
  /* A、B相引脚配置 */
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6 | GPIO_Pin_7;           
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;                     
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  /* Z相引脚配置 */	
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;           
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;                     
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* 复用配置 */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM3);            
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM3);            
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_TIM3);            

  /* 时基配置 */
  TIM_TimeBaseStructure.TIM_Prescaler = 0;                           //预分频值
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;        //向上计数模式
  TIM_TimeBaseStructure.TIM_Period = 65535;//3760*4-1;               //定时周期
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;            //时钟分频因子
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  /* 编码器配置 */
  TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12,TIM_ICPolarity_Falling,TIM_ICPolarity_Falling);
   
  /* 输入捕获参数配置 */
  TIM_ICInitStructure.TIM_Channel = TIM_Channel_3;
  TIM_ICInitStructure.TIM_ICFilter = 0x00;  
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInit(TIM3, &TIM_ICInitStructure);
  
  TIM3->CNT = 0;
	TIM_ITConfig(TIM3,TIM_IT_CC3,ENABLE);//允许更新中断 ,允许CC1IE捕获中断		
  TIM_Cmd(TIM3,ENABLE ); 	//使能定时器3

	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器?
}

/**
   *@brief   Encoder Read
   *@param   Dir：Encoder Diraction 
             Cnt: Encoder CNT
   *@return  None
   *@author  pangpang  
   *@date    2021/11/8    
   *@version V1.0.0
   */
void ENCODER_Read(uint32_t *Dir, uint32_t *Cnt)
{	
	*Dir = ((TIM3->CR1) & TIM_CR1_DIR) >> 4;
  *Cnt = TIM_GetCounter(TIM3);
}

void TIM4_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  ///使能TIM4时钟
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);//初始化TIM4
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	TIM_Cmd(TIM4,ENABLE); //使能定时器4
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/** 
   *@brief   EtherCAT LED State
   *@param   None       
   *@note    EtherCAT LED indicates FSM status
   *@return  None
   *@author  liu
   *@date    2021/11/17      
   *@version V0.0.1
   */
void EtherCAT_LED_Control(void)
{
	/* The LED high level is off */
	switch(u8EcatRunLed)
	{
		case LED_OFF: 
			/* FSM: Init */
		  GPIO_SetBits(GPIOC,GPIO_Pin_5);
		  break;
		case LED_BLINKING:
			/* FSM: Pre OP, LED 500ms blink */
			LED_slow_count++;			 
			if(LED_slow_count <= 500) 
				GPIO_ResetBits(GPIOC,GPIO_Pin_5);					
			else if(LED_slow_count < 1000) 
				GPIO_SetBits(GPIOC,GPIO_Pin_5);
			else if(LED_slow_count >= 1000) 
				LED_slow_count =0;						
			break;
		case LED_SINGLEFLASH: 
			/* FSM: Safe OP, LED 1s single flash */			 
		  LED_single_count++;			 
		  if(LED_single_count <= 1)
			  GPIO_ResetBits(GPIOC,GPIO_Pin_5);
		  else if(LED_single_count < 1000) 
			  GPIO_SetBits(GPIOC,GPIO_Pin_5);
		  else if(LED_single_count >= 1000) 
			  LED_single_count =0;
		  break;
		case LED_ON: 
			/* FSM: OP */
			GPIO_ResetBits(GPIOC,GPIO_Pin_5);
			break;
		case LED_FLICKERING:
			/* FSM: boot, LED 100ms blink */	
			LED_fast_count++;
			if(LED_fast_count <= 100) 
				GPIO_ResetBits(GPIOC,GPIO_Pin_5);
			else if(LED_fast_count < 200)
				GPIO_SetBits(GPIOC,GPIO_Pin_5);	
			else if(LED_fast_count >= 200)
				LED_fast_count =0;
			break;							   
	 }
}


extern uint16_t test_i_value;
double heat_sum_value = 0;
double test_heat_sum_value = 0;
extern uint8_t sampling_flag;
void Res_Heat_Calculation(void)
{
	/* The precharge resistor is connected to the circuit before calculation */
	if(sampling_flag == 1)
	{	
		/* Filter current */
		if(test_i_value >= 1000)
		{
			 test_i_value = 0;
		}
		
		/* res heat sum value calculation */
		heat_sum_value = heat_sum_value + ((int)(test_i_value*0.01)*(int)(test_i_value*0.01)) -0.5;   		
		test_heat_sum_value = heat_sum_value;
		
		/* res heat sum value handle,Res_overheat alarm if value over limit */
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
}

/** 
   *@brief   TIM2 IRQ
   *@param   None       
   *@note    This interrupt is triggered every 1ms
   *@return  None
   *@author  liu
   *@date    2021/11/17      
   *@version V0.0.1
   */
void TIM2_IRQHandler(void)
{
	static u8 time_1ms_cnt = 0,time_2ms_cnt1 = 0,time_2ms_cnt2 = 0;
	static u8 time_10ms_cnt = 0,time_20ms_cnt = 0, time_500ms_cnt = 0;
	
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //溢出中断
	{
		time_1ms_cnt++;
		
		ECAT_CheckTimer(); /* Timeout detection */
		
		EtherCAT_LED_Control(); /* ethercat led state	*/	

		if(time_1ms_cnt >= 2)  //2ms
		{
			time_2ms_cnt1++;
			time_2ms_cnt2++;
			/* 2ms 485 and can send */
			if(Test_Mode0x8015 == 0)		//product mode
			{
				U485_data();  
				CAN_data(); 
			}
			time_1ms_cnt = 0;
		}
				
		/* update upload_flag */
		if(time_2ms_cnt1 > power_manage.upload_time/2)
		{
			upload_flag = 1;
			time_2ms_cnt1 = 0;
		}
	
		if(time_2ms_cnt2 >= 5) //10ms
		{
			time_2ms_cnt2 = 0;
			time_10ms_cnt++;
			/* ad sample fast flag */
			ad_fast_flag = 1;		
			/* res heat sum calculation */
			Res_Heat_Calculation();
			/* power key scan */
			keyscan(power_manage.work_mode);
			
	    if(time_10ms_cnt >= 2) //20ms
			{
			  time_10ms_cnt = 0;
				time_20ms_cnt++;				
				ad_slow_flag=1;		

        if(time_20ms_cnt >= 25)		//500ms		
				{
					led_blink_flag = 1;
					time_20ms_cnt = 0;
					time_500ms_cnt++;
				}
				
				if(time_500ms_cnt>= 2*TX_TINTERV)
				{
					if(Test_Mode0x8015 == 1)		//test mode
					{
						rs485_tm_senddata();
						can_tm_senddata();
					}
					time_500ms_cnt = 0;
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
		}

	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //清除中断标志位
}


/** 
   *@brief   TIM3 IRQ
   *@param   None       
   *@note    The interrupt is triggered when the z-phase rises
   *@return  None
   *@author  liu
   *@date    2021/11/17      
   *@version V0.0.1
   */
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_CC3)==SET) //溢出中断
	{
		INC_GetIncZLatch(); //获取编码器零点锁存值
		TIM_ClearITPendingBit(TIM3,TIM_IT_CC3);  //清除中断标志位
	}
}


/** 
   *@brief   TIM4 IRQ
   *@param   None       
   *@note    This interrupt is triggered every 1ms
   *@return  None
   *@author  liu
   *@date    2021/11/17      
   *@version V0.0.1
   */
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET) //溢出中断
	{
    TimeCNT_Isr++;
		if(TimeCNT_Isr>=1)
		{
			DISABLE_ESC_INT();
      ECAT_CheckTimer();
      TIM_ClearITPendingBit(TIM4,TIM_IT_Update); 
		  ENABLE_ESC_INT();	
		  TimeCNT_Isr=0;
		}
	}
}


