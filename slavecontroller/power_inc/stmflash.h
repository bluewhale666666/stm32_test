#ifndef __STMFLASH_H__
#define __STMFLASH_H__

#include "sys.h"  
//////////////////////////////////////////////////////////////////////////////////	 
//С������Ʒ���洢��1-32KB��     ÿҳ1KB��ϵͳ�洢��2KB 
//��������Ʒ���洢��64-128KB��   ÿҳ1KB��ϵͳ�洢��2KB
//��������Ʒ���洢��256KB���ϣ�  ÿҳ2KB��ϵͳ�洢��2KB

//stm32f103rct6  	  	256K
//			����					��С					����					��ע
//bootloader					40k			  		0-19          ��������
//APP								 100k			  	 20-69         APP����
//Dowload					   100k			  	 70-119        ���ػ���
//flag						    2k			  		127          ������־

//////////////////////////////////////////////////////////////////////////////////

//�û������Լ�����Ҫ����
#define STM32_FLASH_SIZE  256 	 		//��ѡSTM32��FLASH������С(��λΪK)
#define STM32_SECTOR_SIZE	2048	

#define FLASH_APP_ADDR          STM32_FLASH_BASE+20*STM32_SECTOR_SIZE			//20
#define FLASH_DOWNLOAD_ADDR     STM32_FLASH_BASE+70*STM32_SECTOR_SIZE			//70
//#define FLASH_UPDATA_FLAG_ADDR  STM32_FLASH_BASE+127*STM32_SECTOR_SIZE
//#define FLASH_APP_FLAG_ADDR		  FLASH_UPDATA_FLAG_ADDR + 2
#define FLASH_APP_FLAG_ADDR  		STM32_FLASH_BASE+127*STM32_SECTOR_SIZE		//127
#define FLASH_UPDATA_FLAG_ADDR	FLASH_APP_FLAG_ADDR + 2

//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH��ʼ��ַ
#define STM32_FLASH_BASE 	0x08000000 	//STM32 FLASH����ʼ��ַ
//FLASH������ֵ

#define STM32_SECTOR_NUM 	128					//ҳ����0-127

uint8_t 	STMFLASH_ReadByte(uint32_t Addr);
uint16_t 	STMFLASH_ReadHalfWord(uint32_t Addr);		//��������  
uint32_t 	STMFLASH_ReadWord(uint32_t faddr);

void STMFLASH_ReadPage(uint16_t Page_Num,uint8_t *pBuff);
void STMFLASH_WritePage(uint16_t Page_Num,uint8_t *pBuff);

void STMFLASH_WriteNData(uint32_t Addr,uint8_t *pBuff,uint32_t Len);
void STMFLASH_WriteNByte_NoErase(uint32_t Addr,uint8_t *pBuff,uint32_t Len);
void STMFlash_EraseSector(uint8_t Start_Page,uint8_t End_Page);

void Test_Flash_WR(uint8_t Page_Num);

void STMFLASH_ReadNByte(uint32_t Addr,uint8_t *pBuff,uint32_t Len);

#endif


