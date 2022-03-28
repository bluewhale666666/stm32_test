#ifndef __IAP_H__
#define __IAP_H__
#include "sys.h"    
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//IAP ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/7/21
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////    
typedef  void (*iapfun)(void);				//����һ���������͵Ĳ���.   
#define FLASH_APP1_ADDR		0x08010000  	//��һ��Ӧ�ó�����ʼ��ַ(�����FLASH)
//����0X08000000~0X0800FFFF�Ŀռ�ΪBootloaderʹ��(��64KB)	
#define FLASH_APP2_ADDR		0x08040000  	//����Ӧ�ó�����ʼ��ַ(�����FLASH)sector_6
#define FLASH_UPDATE_ADDR		0x08071000  	//0x08071000 save update_flag,0x08071004 save total block_num
void Flash_to_Flash_Write(u32 src_addr,u32 dest_addr,u32 block_len);										   
void iap_load_app(u32 appxaddr);			//��ת��APP����ִ��
void iap_write_appbin(u32 appxaddr,u8 *appbuf,u32 applen);	//��ָ����ַ��ʼ,д��bin
#endif







































