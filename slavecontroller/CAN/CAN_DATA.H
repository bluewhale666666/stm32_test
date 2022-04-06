
/***********************************************************************
文件名称：CAN_DATA.H
功    能：CAN数据定义
编写时间：2012.12.14
编 写 人：
注    意：
***********************************************************************/
#include "stm32f4xx.h"
#ifndef  _CAN_DATA_H_
#define  _CAN_DATA_H_

#define METER_CAN_ID       0X18400000       //电表数据CAN  id   报文第一字节开机命令 第二字节关机命令

void CanWriteData(unsigned int ID, unsigned int dlen, unsigned char *pbuf);

void CAN_data(void);


extern volatile unsigned int  CAN_ID;		//unsigned int为32位的 unsigned short int为16位的
extern u16 can_rx_cnt;
extern u16 can_rx_len;
extern u32 can_rx_ID;
extern u16 can_tx_cnt;
extern u16 can_tx_len;
extern u32 can_tx_ID;
extern u16 last_can_tx_cnt;
extern u8 Flag_canRx;
extern unsigned char CAN_DATA[8];
extern unsigned char can_send_data[8];
extern void CAN_Configuration(unsigned int can_br);
//extern void CAN_Send_Data(void);
extern void CanWriteData(unsigned int ID, unsigned int dlen, u8 *pbuf);
extern struct _CAN_BUFFER__
{
	unsigned short ID;
	unsigned char DLC;
	unsigned char ubData[1460];
}canbuf;
#endif
