#ifndef __DS18B20_H
#define __DS18B20_H 

#include "stm32f4xx.h"

#include "main.h"							//主函数头文件
#include "sys.h"							//主函数头文件
#include "delay.h"

//IO方向设置
#define DS18B20_IO_IN()  {GPIOA->CRH&=0XFFFF0FFF;GPIOA->CRH|=8<<12;}
#define DS18B20_IO_OUT() {GPIOA->CRH&=0XFFFF0FFF;GPIOA->CRH|=3<<12;}
////IO操作函数											   
#define	DS18B20_DQ_OUT PAout(11) //数据端口	PA11
#define	DS18B20_DQ_IN  PAin(11)  //数据端口	PA11

 	
u8 DS18B20_Init(void);			//初始化DS18B20

void DS18B20_Start(void);		//开始温度转换
void DS18B20_Write_Byte(u8 dat);//写入一个字节
u8 DS18B20_Read_Byte(void);		//读出一个字节
u8 DS18B20_Read_Bit(void);		//读出一个位
u8 DS18B20_Check(void);			//检测是否存在DS18B20
void DS18B20_Rst(void);			//复位DS18B20   

short DS18B20_Get_Temp(void);	//获取温度
void mode_save_ds18b20_data(u8 mode);	//依据工作情况的温度采集

void save_ds18b20_data(void);



u8 look_up_table(u16 *a,u8 ArrayLong,u16 data);
float num_to_temperature(u8 num);
void save_ntc_data(u16 data);			//直插
void save_ntc2_data(u16 data);		//smd

#endif















