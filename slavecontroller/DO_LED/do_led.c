/**
   ******************************
   *file    do_led.c 
   *author  liu
   *version V1.0.0
   *date    2021/11/2
   *brief   led init  
						8 channel DO init 
	          8 channel function/user DO init 
   ******************************  
   */
	 
	 
/* Includes -------------------------------------------------------------*/ 
#include "do_led.h" 



/** 
   *@brief   LED Init
   *@note    EtherCAT: PF6
					   CAN LED:  PF7
						 485 LED:  PF8
						 232 LED:  PF9
						 AL  LED:  PF10
   *@param   none
   *@return  none
   *@author  liu  
   *@date    2021/11/1    
   *@version V1.0.0
   */
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 |GPIO_Pin_7 |GPIO_Pin_8 |GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化GPIO
	
  GPIO_SetBits(GPIOF,GPIO_Pin_6| GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_8|GPIO_Pin_9| GPIO_Pin_10);//灯灭
}


/** 
   *@brief   DO Init
   *@note    8 channel DO
					   8 channel Function/User DO
   *@param   none
   *@return  none
   *@author  liu  
   *@date    2021/11/1    
   *@version V1.0.0
   */
void DO_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOF|RCC_AHB1Periph_GPIOG, ENABLE);//使能GPIOD和GPIOG时钟

	/************************** DO ST_OUT_1 ~ ST_OUT_8 Init **************************/
	/* ST_OUT_1: PD14;  ST_OUT_2: PD13;  ST_OUT_3: PD12; ST_OUT_4: PD11; */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 |GPIO_Pin_12| GPIO_Pin_13 |GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIO
	GPIO_SetBits(GPIOD,GPIO_Pin_11_14);
	
	/* ST_OUT_5: PB14;  ST_OUT_6: PB13;  ST_OUT_7: PB12; ST_OUT_8: PB11; */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIO
	GPIO_SetBits(GPIOB,GPIO_Pin_11_14);
	
	/******************Function/User DO ST_OUT_17 ~ ST_OUT_24 Init *******************/
	/* ST_OUT_17: PD10;  ST_OUT_18: PD9;  ST_OUT_19: PD8; */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 |GPIO_Pin_9| GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化GPIO
	GPIO_SetBits(GPIOD, GPIO_Pin_10|GPIO_Pin_9|GPIO_Pin_8);
	
	/* ST_OUT_20: PB15; */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIO
	GPIO_SetBits(GPIOB,GPIO_Pin_15);
	
	/* ST_OUT_21: PE11;  ST_OUT_22: PE12;  ST_OUT_23: PE13;  ST_OUT_24: PE14; */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIO
	GPIO_SetBits(GPIOE,GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14);
}

/** 
   *@brief   DO Process Data
   *@note    8 channel DO process data processing
					   8 channel Function/User DO process data processing
   *@param   DO object dictionary
   *@return  none
   *@author  liu  
   *@date    2021/11/1    
   *@version V1.0.0
   */
void DO_process_data(TOBJ7000 *OUT_GENERIC)
{
	/********************  DO 8 channel ********************/
	if(OUT_GENERIC->Digital_Outputs_channel_1) 
		GPIO_ResetBits(GPIOD,GPIO_Pin_14);
	else 
		GPIO_SetBits(GPIOD,GPIO_Pin_14);
	
	if(OUT_GENERIC->Digital_Outputs_channel_2) 
		GPIO_ResetBits(GPIOD,GPIO_Pin_13);
	else 
		GPIO_SetBits(GPIOD,GPIO_Pin_13);
	
	if(OUT_GENERIC->Digital_Outputs_channel_3) 
		GPIO_ResetBits(GPIOD,GPIO_Pin_12);
	else 
		GPIO_SetBits(GPIOD,GPIO_Pin_12);
	
	if(OUT_GENERIC->Digital_Outputs_channel_4) 
		GPIO_ResetBits(GPIOD,GPIO_Pin_11);
	else 
		GPIO_SetBits(GPIOD,GPIO_Pin_11);
	
	if(OUT_GENERIC->Digital_Outputs_channel_5) 
		GPIO_ResetBits(GPIOB,GPIO_Pin_14);
	else 
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
	
	if(OUT_GENERIC->Digital_Outputs_channel_6) 
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	else 
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
	
	if(OUT_GENERIC->Digital_Outputs_channel_7) 
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	else 
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
	
	if(OUT_GENERIC->Digital_Outputs_channel_8) 
		GPIO_ResetBits(GPIOB,GPIO_Pin_11);
	else 
		GPIO_SetBits(GPIOB,GPIO_Pin_11);
	
   /********************  Function/User DO 8 channel ********************/
	if(OUT_GENERIC->Function_Digital_Outputs_Channel_1) 
		GPIO_ResetBits(GPIOD,GPIO_Pin_10);
	else 
		GPIO_SetBits(GPIOD,GPIO_Pin_10);
	
	if(OUT_GENERIC->Function_Digital_Outputs_Channel_2) 
		GPIO_ResetBits(GPIOD,GPIO_Pin_9);
	else 
		GPIO_SetBits(GPIOD,GPIO_Pin_9);
	
	if(OUT_GENERIC->Function_Digital_Outputs_Channel_3) 
		GPIO_ResetBits(GPIOD,GPIO_Pin_8);
	else 
		GPIO_SetBits(GPIOD,GPIO_Pin_8);
	
	if(OUT_GENERIC->Function_Digital_Outputs_Channel_4) 
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
	else 
		GPIO_SetBits(GPIOB,GPIO_Pin_15);
	
	if(OUT_GENERIC->Function_Digital_Outputs_Channel_5) 
		GPIO_ResetBits(GPIOE,GPIO_Pin_11);
	else 
		GPIO_SetBits(GPIOE,GPIO_Pin_11);
	
	if(OUT_GENERIC->Function_Digital_Outputs_Channel_6) 
		GPIO_ResetBits(GPIOE,GPIO_Pin_12);
	else 
		GPIO_SetBits(GPIOE,GPIO_Pin_12);
	
	if(OUT_GENERIC->Function_Digital_Outputs_Channel_7) 
		GPIO_ResetBits(GPIOE,GPIO_Pin_13);
	else 
		GPIO_SetBits(GPIOE,GPIO_Pin_13);
	
	if(OUT_GENERIC->Function_Digital_Outputs_Channel_8) 
		GPIO_ResetBits(GPIOE,GPIO_Pin_14);
	else 
		GPIO_SetBits(GPIOE,GPIO_Pin_14);
}

