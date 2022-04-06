#ifndef _EXTI_H_
#define _EXIT_H_	 
#include "sys.h"  	



 extern void EXTI1_Init(void);	//外部中断初始化	
 extern void EXTI2_Init(void);	//外部中断初始化
 extern void EXTI3_Init(void);	//外部中断初始化
 //extern void EXTI4_Init(void);	//外部中断初始化

 extern void EN_DISEN_EXTI(u8 en,u8 linenum);//使能使能相应中断线
 
#endif















