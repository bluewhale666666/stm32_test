/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIM_H
#define __TIM_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


void tim5_init(void);												//TIM6��ʱ��ʼ����1ms���ڸ��ּ�ʱ

void IWDG_Init(uint8_t prer,uint16_t rlr);						//���Ź���ʼ������
void IWDG_Feed(void);

void tim8_PWM_init(uint8_t Dutycycle);

#endif /*  				  */

/************************END OF FILE****/
