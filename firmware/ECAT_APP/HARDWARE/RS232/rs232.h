#ifndef __RS232_H
#define __RS232_H			 
#include "sys.h"	 								  
#include "Robot-Device.h"
#include "stm32f4xx.h" 
//#if defined(_ROBOT_DEVICE_) && (_ROBOT_DEVICE_ == 1)
//    #define PROTO
//#else
//    #define PROTO extern
//#endif

	
	

extern u8 RS232_RX[64]; 		//���ջ���,���64���ֽ�
extern u16 RS232_CON;
extern u16 RS232_tx_CON;
extern	u16 LAST_RS232_tx_CON;
extern u16 RS232_tx_LEN;
extern u16 RS232_rx_LEN;//�������ݳ���	
extern u8 RS232_TX[64];		
	
extern u8 RS232_RX_CNT;   			//���յ������ݳ���

	
//extern u8 uart_485[64];               //���uart����ʱ��������	


extern void U232_data(void);														 
extern void RS232_Init(u32 bound);
extern void RS232_Send_Data(u8 *buf,u8 len);
extern void RS232_Receive_Data(u8 *buf,u8 *len);
//PROTO unsigned short do_crc( unsigned char *message, unsigned int len);	
//PROTO void U485_data(void);


extern void RS232_Send(u8 size);
#endif	   
















