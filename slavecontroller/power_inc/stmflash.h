#ifndef __STMFLASH_H__
#define __STMFLASH_H__

#include "sys.h"  
//////////////////////////////////////////////////////////////////////////////////	 
//小容量产品主存储块1-32KB，     每页1KB。系统存储器2KB 
//中容量产品主存储块64-128KB，   每页1KB。系统存储器2KB
//大容量产品主存储块256KB以上，  每页2KB。系统存储器2KB

//stm32f103rct6  	  	256K
//			分区					大小					扇区					备注
//bootloader					40k			  		0-19          引导程序
//APP								 100k			  	 20-69         APP程序
//Dowload					   100k			  	 70-119        下载缓存
//flag						    2k			  		127          其他标志

//////////////////////////////////////////////////////////////////////////////////

//用户根据自己的需要设置
#define STM32_FLASH_SIZE  256 	 		//所选STM32的FLASH容量大小(单位为K)
#define STM32_SECTOR_SIZE	2048	

#define FLASH_APP_ADDR          STM32_FLASH_BASE+20*STM32_SECTOR_SIZE			//20
#define FLASH_DOWNLOAD_ADDR     STM32_FLASH_BASE+70*STM32_SECTOR_SIZE			//70
//#define FLASH_UPDATA_FLAG_ADDR  STM32_FLASH_BASE+127*STM32_SECTOR_SIZE
//#define FLASH_APP_FLAG_ADDR		  FLASH_UPDATA_FLAG_ADDR + 2
#define FLASH_APP_FLAG_ADDR  		STM32_FLASH_BASE+127*STM32_SECTOR_SIZE		//127
#define FLASH_UPDATA_FLAG_ADDR	FLASH_APP_FLAG_ADDR + 2

//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH起始地址
#define STM32_FLASH_BASE 	0x08000000 	//STM32 FLASH的起始地址
//FLASH解锁键值

#define STM32_SECTOR_NUM 	128					//页数，0-127

uint8_t 	STMFLASH_ReadByte(uint32_t Addr);
uint16_t 	STMFLASH_ReadHalfWord(uint32_t Addr);		//读出半字  
uint32_t 	STMFLASH_ReadWord(uint32_t faddr);

void STMFLASH_ReadPage(uint16_t Page_Num,uint8_t *pBuff);
void STMFLASH_WritePage(uint16_t Page_Num,uint8_t *pBuff);

void STMFLASH_WriteNData(uint32_t Addr,uint8_t *pBuff,uint32_t Len);
void STMFLASH_WriteNByte_NoErase(uint32_t Addr,uint8_t *pBuff,uint32_t Len);
void STMFlash_EraseSector(uint8_t Start_Page,uint8_t End_Page);

void Test_Flash_WR(uint8_t Page_Num);

void STMFLASH_ReadNByte(uint32_t Addr,uint8_t *pBuff,uint32_t Len);

#endif


