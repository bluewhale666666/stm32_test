#ifndef __RECIEVE_SEND_COMMAND_DONE_H
#define __RECIEVE_SEND_COMMAND_DONE_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* function define  -------------------------------------*/

void USART1_Send_RecData(void);

void USART1_Data_Recieve(void);
void USART1_Data_Recieve_Standby(void);

void data_frame_code_handle(uint8_t code, uint8_t *pdata, uint8_t len);
void usart1_save_cmd_ok(uint8_t *data);
void usart1_save_ok_none_data(uint8_t code);
void usart1_save_bps_ok(uint8_t data);

void query_frame_code_handle(uint8_t code);
void usart1_send_upload_data(void);		//01
void usart1_send_threshold(void);			//07
void usart1_send_bps_worktime(void);	//12
void usart1_ver_worktime(void);

void usart1_send_code3_cmd(void);
void usart1_reply_code4_cmd(void);

void usart1_reply_code5_cmd(void);

void USART1_Send(uint8_t *RxBuffer, uint8_t len);

//void USART1_Send_nchar(uint8_t *RxBuffer);
//void USART_TxCircle_String(USART_TypeDef* USARTx, uint8_t *data, uint16_t len);

#endif /* __RECIEVE_SEND_COMMAND_DONE_H*/

/************************END OF FILE****/
