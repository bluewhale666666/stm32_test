#ifndef __LOCAL_MAIN_DISPLAY_H
#define __LOCAL_MAIN_DISPLAY_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "head_conf.h"


/* function define  -------------------------------------*/

//自动上传、报警数据上传判断函数
void Auto_Send_XXXX_Data_To_X80X(USART_TypeDef* USARTx);
void Auto_Send_XXXX_Data(USART_TypeDef* USARTx);

void Auto_Send_Data_To_Touchscreen_Timming(USART_TypeDef* USARTx);
void Auto_Send_Data_To_X80X_30s(USART_TypeDef* USARTx);


#endif /* __LOCAL_NAIN_DISPLAY_H*/

/************************END OF FILE****/
