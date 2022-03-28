/**
   ******************************
   *file    di_key.h 
   *author  liu
   *version V1.0.0
   *date    2021/11/2
   *brief   DI init 
	          function/user DI init 
   ******************************  
   */


/* Define to prevent recursive inclusion ---------------------------------*/
#ifndef __DI_KEY_H
#define __DI_KEY_H	


/* Includes -------------------------------------------------------------*/
#include "sys.h" 
#include "Robot-Device.h"
#include "incappl.h"


#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
    #define PROTO
#else
    #define PROTO extern
#endif


#define ST_IN4_I0_0      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_14)	 	
#define ST_IN3_I0_1      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_13)	 	
#define ST_IN2_I0_2      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_12)   
#define ST_IN1_I0_3      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_11)	

#define ST_IN5_I1_0      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_10)	
#define ST_IN6_I1_1      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_9)	
#define ST_IN7_I1_2      GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_7)	
#define ST_IN8_I1_3      GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)	
	
#define ST_IN17_I2_0      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_5)	 	
#define ST_IN18_I2_1      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_3)	 	
#define ST_IN19_I2_2      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_2)    
#define ST_IN20_I2_3      GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_15)	 

#define ST_IN24_I3_0      GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_14)	
#define ST_IN23_I3_1      GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_11)	
#define ST_IN22_I3_2      GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_12)	
#define ST_IN21_I3_3      GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_13)	





/* Function define  ---------------------------------------------------*/
void DI_Init(void);     
BOOL input_filter(const uint16_t Input, uint16_t * FilterCounter, const uint16_t CounterMax, const uint16_t CounterThreshold, BOOL * InputLatch);
PROTO void DI_process_data(TOBJ6000 *IN_GENERIC);



#endif
