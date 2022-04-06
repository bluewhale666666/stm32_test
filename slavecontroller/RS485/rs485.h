#ifndef __RS485_H
#define __RS485_H			 
#include "sys.h"	 								  
#include "Robot-Device.h"
//#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
//    #define PROTO
//#else
//    #define PROTO extern
//#endif


	
	

extern u8 RS485_RX[64]; 		//接收缓冲,最大64个字节
extern u16 RS485_CON;
extern u16 RS485_tx_CON;
extern u16 RS485_tx_CON_LAST; 
extern	u16 LAST_RS485_tx_CON; 
extern u16 RS485_tx_LEN; 
extern u16 RS485_tx_LEN_LAST; 
extern u16 RS485_rx_LEN;//???????????	 
extern u8 RS485_TX[64];		 
extern u8 RS485_TX_LAST[64];	//????????,???32?????	 
extern u8 RS485_RX_CNT;   			//?????????????? 
extern u8 rs485_tx_start;  

														 
void RS485_Init(u32 bound);
void RS485_Send_Data(u8 *buf,u8 len);
void RS485_Receive_Data(u8 *buf,u8 *len);
extern unsigned short do_crc( unsigned char *message, unsigned int len);	
extern void U485_data(void);


//extern void RS485_Send(u8 size);
#endif	   
















