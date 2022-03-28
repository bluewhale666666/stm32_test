#ifndef __DS18B20_H
#define __DS18B20_H 

#include "stm32f4xx.h"

#include "main.h"							//������ͷ�ļ�
#include "sys.h"							//������ͷ�ļ�
#include "delay.h"

//IO��������
#define DS18B20_IO_IN()  {GPIOA->CRH&=0XFFFF0FFF;GPIOA->CRH|=8<<12;}
#define DS18B20_IO_OUT() {GPIOA->CRH&=0XFFFF0FFF;GPIOA->CRH|=3<<12;}
////IO��������											   
#define	DS18B20_DQ_OUT PAout(11) //���ݶ˿�	PA11
#define	DS18B20_DQ_IN  PAin(11)  //���ݶ˿�	PA11

 	
u8 DS18B20_Init(void);			//��ʼ��DS18B20

void DS18B20_Start(void);		//��ʼ�¶�ת��
void DS18B20_Write_Byte(u8 dat);//д��һ���ֽ�
u8 DS18B20_Read_Byte(void);		//����һ���ֽ�
u8 DS18B20_Read_Bit(void);		//����һ��λ
u8 DS18B20_Check(void);			//����Ƿ����DS18B20
void DS18B20_Rst(void);			//��λDS18B20   

short DS18B20_Get_Temp(void);	//��ȡ�¶�
void mode_save_ds18b20_data(u8 mode);	//���ݹ���������¶Ȳɼ�

void save_ds18b20_data(void);



u8 look_up_table(u16 *a,u8 ArrayLong,u16 data);
float num_to_temperature(u8 num);
void save_ntc_data(u16 data);			//ֱ��
void save_ntc2_data(u16 data);		//smd

#endif















