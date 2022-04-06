/**
   ******************************
   *file    do_led.h 
   *author  liu
   *version V1.0.0
   *date    2021/11/2
   *brief   led init  
						DO init 
	          function/user DO init 
   ******************************  
   */


/* Define to prevent recursive inclusion ---------------------------------*/
#ifndef __DO_LED_H
#define __DO_LED_H


/* Includes -------------------------------------------------------------*/
#include "sys.h"
#include "Robot-Device.h"



#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
    #define PROTO
#else
    #define PROTO extern
#endif

		
		
/* Function define ---------------------------------------------------*/
void LED_Init(void);
void DO_Init(void);
PROTO void DO_process_data(TOBJ7000 *OUT_GENERIC);
		
#endif
