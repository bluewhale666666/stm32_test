/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIM_H
#define __TIM_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


void tim5_init(void);												//TIM6定时初始化，1ms用于各种计时

void IWDG_Init(uint8_t prer,uint16_t rlr);						//看门狗初始化函数
void IWDG_Feed(void);

void tim8_PWM_init(uint8_t Dutycycle);

#endif /*  				  */

/************************END OF FILE****/
