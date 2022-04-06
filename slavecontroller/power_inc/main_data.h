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

//ʱ�����
//uint16_t 	Time_100ms,Time_100ms2;

//ʱ���־
uint8_t time_2s_flag=0;

uint8_t upload_flag=0;
uint8_t ad_fast_flag=0,ad_slow_flag=0;
uint8_t led_blink_flag=0;
uint8_t adcok_flag=0;



uint8_t time_ds18b_flag=0;

uint8_t Alarm_Appear_Flag=0;
//				�������ֱ�־		

uint32_t const BPS_Table[7]={19200,2400,4800,9600,19200,38400,115200};

//AT24Cxx�洢������ַ����
//at24c32 = 0x8000
//at24c64 = 0x10000
//at24c256= 0x40000
//at24c512= 0x80000

uint16_t const EEROM_Config_Add_Table[96]={
0x0000,//����,		�豸ID 2�ֽ�	
0x0002,//����,		������1�ֽ�	
0x0004,//����,		�ϴ����2�ֽ�
0x0006,//����,		�¶��趨ֵ 2�ֽ�
0x0008,//����,		48v��ѹ�趨ֵl 2�ֽ�
0x000a,//����,		48v��ѹ�趨ֵh 2�ֽ�
0x000c,//����,		48v�����趨ֵh 2�ֽ�
0x0010,//����,		24V1��ѹ�趨ֵl,2�ֽ�
0x0012,//����,		24V1��ѹ�趨ֵh,2�ֽ�
0x0014,//����,		24V1�����趨ֵh 2�ֽ�
0x0018,//����,		24V2��ѹ�趨ֵl,2�ֽ�
0x001a,//����,		24V2��ѹ�趨ֵh,2�ֽ�
0x001c,//����,		24V2�����趨ֵ1h,2�ֽ�
0x001e,//����,		24V2�����趨ֵ2h 2�ֽ�	
0x0028,//����,		�ۼƹ���ʱ��4�ֽ�
0x0030,//����,		�汾�ţ�6�ֽ�
//����
0x00ff,//����,		����(0)���ǲ���(1)	1�ֽ�
};

uint8_t send_code3_flag=0;					//��������ػ�ָ��
uint8_t receive_code3_flag=0;				//�յ�����ػ���ȷ��
uint8_t receive_code4_flag=0;				//�յ��ػ�ָ��

uint8_t	code3_delay_st=0; 					//������ʱ��־(0-δ��ʱ��1-������ʱ)
uint8_t	poweroff_st=0; 								//�̵����Ƿ�����״̬(0-�ͷţ�1-�Ѿ�����)
//uint16_t	delay_sec=0; 							//����ʱʱ�ļ�ʱ��(ÿ���һ)
uint16_t	delay_count=0; 							//����ʱʱ���жϼ�����(ÿ5�����1)

uint16_t	oc_st_count=0;

uint8_t	last_workmode;
uint8_t	code3_times=0;

#endif /* __MAIN_DATA_H*/

/************************END OF FILE****/
