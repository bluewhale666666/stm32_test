/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H
#define __USART_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

void usart1_init(uint32_t bound);						//USART1初始化，后台通讯接口

void DMA_init(void);

#endif /*  				  */

/************************END OF FILE****/
