/**
   ******************************
   *file    gpio.h 
   *author  liu
   *version V1.0.0
   *date    2021/11/15
   *brief   power related gpio init
   ******************************  
   */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H
#define __GPIO_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "sys.h"							

/* output interface definition */
#define DC24V1A_DR    PBout(9) 	//示教器、主控、FAN、安全控制器的24V，与48V remote复用
#define DC24V2A_DR    PFout(2) 	//IO的24V
#define AI_IU_SW1     PEout(6)  //模拟量输入1电流电压切换
#define AI_IU_SW2     PBout(1)  //模拟量输入2电流电压切换
#define OCPROTECT_DR	PEout(1) 	//过流防护 
#define DC24V_FK_DR		PFout(12) //示教器指示灯
#define DC48V_ES_SHUTDOWN_DR  PFout(13) 	//48V异常控制

/* input interface definition */
#define SAFE_48V_SWITCH PFin(11)  //48V switch state input
#define POWKEY_STA   		PEin(0)   //按键上下电输入
#define REMOTEON_STA   	PBin(8)   //远程上电输入		
#define REMOTEOFF_STA		PEin(15)  //远程下电输入   
#define POWER_STA_OK		PGin(1)   //OK信号

/* Function define  -------------------------------------*/
void gpio_init(void);																

#endif 
