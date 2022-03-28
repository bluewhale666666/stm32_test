#include "rs485.h"	 
#include "CAN_DATA.h"

#include "testmode.h"


u8 rs485_tm_tx[RS485_TMTX_LEN]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0xEF};
//u8 rs485_tm_rxack[RS485_TMRXACK_LEN] = {0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05};

u8 can_tm_tx[CAN_TMTX_LEN]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
u8 can_tm_rxack[CAN_TMRXACK_LEN] = {0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A};
unsigned int TM_CAN_TXID = 0x01;

u8 tm_rs485_rxflag = 0;
u8 tm_can_rxflag = 0;

void rs485_tm_senddata(void)
{
	USART_ITConfig(USART2,USART_IT_IDLE, DISABLE); 
	RS485_Send_Data(rs485_tm_tx,RS485_TMTX_LEN);	
	USART_ITConfig(USART2,USART_IT_IDLE, ENABLE);
}

void rs485_tm_sendack(void)
{
	USART_ITConfig(USART2,USART_IT_IDLE, DISABLE); 
	RS485_Send_Data(RS485_RX, RS485_rx_LEN);			//send the RX buffer as ack
	USART_ITConfig(USART2,USART_IT_IDLE, ENABLE);
}

void can_tm_senddata(void)
{
	CanWriteData(TM_CAN_TXID, CAN_TMTX_LEN, can_tm_tx);	
}

void can_tm_sendack(void)
{
	CanWriteData(can_rx_ID, can_rx_len, CAN_DATA);	//send the RX frame as ack
}


