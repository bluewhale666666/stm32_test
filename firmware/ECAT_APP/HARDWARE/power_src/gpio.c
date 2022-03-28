/**
   ******************************
   *file    gpio.c 
   *author  liu
   *version V1.0.0
   *date    2021/11/15
   *brief   power related gpio init
   ******************************  
   */
	 
	 
/* Includes -------------------------------------------------------------*/ 

#include "gpio.h"



/** 
   *@brief   Gpio Init  
   *@param   None 
   *@note    power gpio init
   *@return  None
   *@author  liu  
   *@date    2021/11/15       
   *@version V1.0.0 
   */
void gpio_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;														
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOF,ENABLE);

	/************************** AI Switch Init **************************/
	/* PE6: Analog input 1 current/voltage mode switch */
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_6;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	/* PB1: Analog input 2 current/voltage mode switch;	*/
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOB,&GPIO_InitStructure);		

  /************************** Output Init **************************/	
	/* PB9: 24V_OUT1, Teaching device, main control, fan, safety controller MCU, 48V remote multi	*/
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_9;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOB,&GPIO_InitStructure);		
				
	/* PF2: 24V IO; PF12: 24V_OUT1 power indicator; PF13: error shutdown */
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_2|GPIO_Pin_12|GPIO_Pin_13;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOF,&GPIO_InitStructure);		
	
	/* PE1: OCPROTECT; */
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOE,&GPIO_InitStructure);

  /************************** Input Init **************************/	
	/* PE0: power on key in; PE15: power off remote key in */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_15;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;		   										
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;		 									
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE,&GPIO_InitStructure);	
	
	/* PB8: power on remote key in */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* PF11: 48V switch state */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;		   	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);		

	/*OK sign*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;		   										
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;		 									
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOG,&GPIO_InitStructure);	
}


