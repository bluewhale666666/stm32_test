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
									
	/* PB1: Analog input 2 current/voltage mode switch, The default is voltage mode;
	   PB9: 24V_OUT1, Teaching device, main control, fan, safety controller MCU, 48V remote multi	*/
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1|GPIO_Pin_9;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOB,&GPIO_InitStructure);				 						
	AI_IU_SW2=1;	

	/* PC4: work led */
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_4;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOC,&GPIO_InitStructure);				 						

	/* PF2: 24V IO; PF12: 24V power indicator; PF13: error shutdown */
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_2|GPIO_Pin_12|GPIO_Pin_13;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOF,&GPIO_InitStructure);		
	DC24V2A_DR = 0;
	DC24V_FK_DR = 0;
	DC48V_ES_SHUTDOWN_DR = 1;
	
	/* PE1: OCPROTECT; PE6: Analog input 1 current/voltage mode switch, The default is voltage mode  */
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1|GPIO_Pin_6;			
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_OUT;		   			
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 						
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	DC24V1A_DR=0;
	AI_IU_SW1 = 1;
		
//	/* PE0: power on key in; PE15: power off remote key in */
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_15;	
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;		   										
//	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;		 									
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_Init(GPIOE,&GPIO_InitStructure);	
  /* PF12: power on key in */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;		   										
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;		 									
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);	
	/* PE15: power off remote key in */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	
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
}


