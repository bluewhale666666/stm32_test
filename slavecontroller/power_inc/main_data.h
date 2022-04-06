#ifndef __MAIN_DATA_H
#define __MAIN_DATA_H

#include "stm32f4xx.h"
#include "main.h"

//eeprom param start
struct POWER_MANAGE_BOARD power_manage;

//USART1 
uint8_t 	Rxd1_Buff[RXD1_MAX_NUM];
uint16_t	Rxd1_Da_Num=0;
uint8_t 	Rx1Status=0,Rx1appStatus=0;
uint8_t 	Txd1_Buff[TXD1_MAX_NUM];

//时间变量
//uint16_t 	Time_100ms,Time_100ms2;

//时间标志
uint8_t time_2s_flag=0;

uint8_t upload_flag=0;
uint8_t ad_fast_flag=0,ad_slow_flag=0;
uint8_t led_blink_flag=0;
uint8_t adcok_flag=0;



uint8_t time_ds18b_flag=0;

uint8_t Alarm_Appear_Flag=0;
//				报警出现标志		

uint32_t const BPS_Table[7]={19200,2400,4800,9600,19200,38400,115200};

//AT24Cxx存储参数地址定义
//at24c32 = 0x8000
//at24c64 = 0x10000
//at24c256= 0x40000
//at24c512= 0x80000

uint16_t const EEROM_Config_Add_Table[96]={
0x0000,//编码,		设备ID 2字节	
0x0002,//编码,		波特率1字节	
0x0004,//编码,		上传间隔2字节
0x0006,//编码,		温度设定值 2字节
0x0008,//编码,		48v电压设定值l 2字节
0x000a,//编码,		48v电压设定值h 2字节
0x000c,//编码,		48v电流设定值h 2字节
0x0010,//编码,		24V1电压设定值l,2字节
0x0012,//编码,		24V1电压设定值h,2字节
0x0014,//编码,		24V1电流设定值h 2字节
0x0018,//编码,		24V2电压设定值l,2字节
0x001a,//编码,		24V2电压设定值h,2字节
0x001c,//编码,		24V2电流设定值1h,2字节
0x001e,//编码,		24V2电流设定值2h 2字节	
0x0028,//编码,		累计工作时间4字节
0x0030,//编码,		版本号，6字节
//保留
0x00ff,//编码,		正常(0)还是测试(1)	1字节
};

uint8_t send_code3_flag=0;					//发送请求关机指令
uint8_t receive_code3_flag=0;				//收到请求关机的确认
uint8_t receive_code4_flag=0;				//收到关机指令

uint8_t	code3_delay_st=0; 					//正在延时标志(0-未延时，1-正在延时)
uint8_t	poweroff_st=0; 								//继电器是否吸合状态(0-释放，1-已经吸合)
//uint16_t	delay_sec=0; 							//在延时时的计时器(每秒加一)
uint16_t	delay_count=0; 							//在延时时的中断计数器(每5毫秒加1)

uint16_t	oc_st_count=0;

uint8_t	last_workmode;
uint8_t	code3_times=0;

#endif /* __MAIN_DATA_H*/

/************************END OF FILE****/
