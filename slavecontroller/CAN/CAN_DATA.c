/***********************************************************************
文件名称：CAN_DATA.C
功    能：完成CAN 数据的读取
编写时间：2012.12.14
编 写 人：
注    意：
***********************************************************************/
#include "CAN_DATA.h"
#include "stm32f4xx.h"
//#include "main.h"

extern unsigned char meter_flag;
extern volatile unsigned char CanRec_flag;



void CAN_Send_Data(void)
{
//	CanWriteData(0x18412345);	//以id号为0x18412345向can发数据
}

