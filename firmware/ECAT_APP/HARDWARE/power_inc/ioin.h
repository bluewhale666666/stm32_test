/**
   ******************************
   *file    ioin.h 
   *author  liu
   *version V1.0.0
   *date    2021/11/18
   *brief   key detect
   ******************************  
   */


/* Define to prevent recursive inclusion ---------------------------------*/
#ifndef __IOIN_H
#define __IOIN_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "main.h"						
#include "gpio.h"


#define KEY_SHORT_VALUE							100		//1s
#define KEY_LONG_VALUE							300   //3s
#define POWERSTA_LOW_THD						5


/* Function define  -------------------------------------*/
void keyscan(uint8_t mode);



#endif /* __IOIN_H*/


