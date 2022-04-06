#ifndef __DEBUG_DATA_SEND_H
#define __DEBUG_DATA_SEND_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "head_conf.h"

/* function define  -------------------------------------*/
void Postern_Config_Inquiry(void);							//后台配置处理函数
void USART1_Send(char *RxBuffer, uint8_t len);
void USART1_Send_nchar(char *RxBuffer);

#endif /* __DEBUG_DATA_SEND_H*/

/************************END OF FILE****/
