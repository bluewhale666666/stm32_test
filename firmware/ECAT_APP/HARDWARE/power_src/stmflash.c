#include "stmflash.h"
#include "delay.h"
#include <string.h>
 
//////////////////////////////////////////////////////////////////////////////////	 

//写N字节函数，先把页数据读到缓存中，然后擦除相应的页，再写入
void STMFLASH_WriteNData(uint32_t Addr,uint8_t *pBuff,uint32_t Len)
{
	u8 STM32_FLASH_BUFF[STM32_SECTOR_SIZE];	//最多是2K字节
	
	uint32_t Offset;
	uint8_t  Page_Num;
	uint16_t Page_Offset;
	uint16_t Free_Space;
	uint16_t i;
	
	//注意不要超过flash范围
	if(Addr < STM32_FLASH_BASE)		// || (Addr >=(STM32_FLASH_BASE+1024*STM32_SECTOR_NUM)))	
		return;
	
	Offset = Addr - STM32_FLASH_BASE;								//偏移地址
	Page_Num = Offset / STM32_SECTOR_SIZE;					//得到地址所在页
	Page_Offset = Offset % STM32_SECTOR_SIZE;				//在页内的偏移地址
	Free_Space = STM32_SECTOR_SIZE -  Page_Offset;	//页区剩余空间
	
	//要写入的数据是否大于剩余空间
	if(Len <= Free_Space)
		Free_Space = Len;
	
	FLASH_Unlock();//解锁
	
	while(1)
	{
		STMFLASH_ReadPage(Page_Num,STM32_FLASH_BUFF);//先把数据读到缓存中
		FLASH_ErasePage(Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE);	//页擦除，页起始地址
		//修改缓存数据
		for(i = 0;i < Free_Space;i++)
		{
			STM32_FLASH_BUFF[i+Page_Offset] = pBuff[i];
		}
		STMFLASH_WritePage(Page_Num,STM32_FLASH_BUFF);//把缓存数据写入
		//判断是否超出当前页，超出进入下一页
		if(Len == Free_Space)
			break;
		else
		{
			Page_Num++;//下一页
			Page_Offset = 0;
			pBuff += Free_Space;
			
			Len -= Free_Space;
			if(Len > STM32_SECTOR_SIZE)
				Free_Space = STM32_SECTOR_SIZE;
			else
				Free_Space = Len;
		}
	}
	FLASH_Lock();
}

//写多字节，要求是从扇区首地址写入，可跨扇区写，APP升级时用；不擦出扇区（app升级前已擦除扇区），
void STMFLASH_WriteNByte_NoErase(uint32_t Addr,uint8_t *pBuff,uint32_t Len)
{
	uint16_t i;
	uint16_t temp = 0;
	
	if((Addr >= STM32_FLASH_BASE)&&(Len <= 50*STM32_SECTOR_SIZE))	//代码空间要小于约定的大小100k
	{
		FLASH_Unlock();//解锁
		
		for(i=0;i<Len;i += 2)
		{
			temp = pBuff[i];
			temp |= (uint16_t)pBuff[i+1] << 8;
			
			FLASH_ProgramHalfWord(Addr,temp);
			Addr += 2;
		}
		FLASH_Lock();
	}
}

//擦除指定页的函数
void STMFlash_EraseSector(uint8_t Start_Page,uint8_t End_Page)
{
	uint8_t i;
	uint8_t num = 0;
	
	if(Start_Page > End_Page)
		return;
	
	FLASH_Unlock();//解锁
	
	num = End_Page - Start_Page;//擦除页数
	
	for(i = 0;i <= num;i++)
	{
		FLASH_ErasePage((Start_Page + i) * STM32_SECTOR_SIZE + STM32_FLASH_BASE);//页擦除
	}
	
	FLASH_Lock();
}

//读取1整页数据
void STMFLASH_ReadPage(uint16_t Page_Num,uint8_t *pBuff)
{
	uint16_t i;
	uint32_t Buff;
	uint32_t Addr;
	
	//是否超出范围
	if(Page_Num > (STM32_SECTOR_NUM-1))		//0-127
		return;
	//先计算页首地址
	Addr = Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE;
	
	for(i = 0;i < STM32_SECTOR_SIZE;i += 4)
	{
		Buff = STMFLASH_ReadWord(Addr);
		
		pBuff[i]   = Buff;
		pBuff[i+1] = Buff >> 8;
		pBuff[i+2] = Buff >> 16;
		pBuff[i+3] = Buff >> 24;
		
		Addr += 4;
	}
}

//写入1整页数据
void STMFLASH_WritePage(uint16_t Page_Num,uint8_t *pBuff)
{
	uint16_t i;
	uint16_t Buff;
	uint32_t Addr;
	
	//是否超出范围
	if(Page_Num > (STM32_SECTOR_NUM-1))		//0-127
		return;
	//解锁
	FLASH_Unlock();
	//先计算页首地址
	Addr = Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE;
	
	for(i = 0;i < STM32_SECTOR_SIZE ;i += 2)
	{
		Buff = ((uint16_t)pBuff[i+1] << 8) | pBuff[i];
		FLASH_ProgramHalfWord(Addr,Buff);
		Addr += 2;
	}
	//上锁
	FLASH_Lock();
}


//读1个字节
uint8_t STMFLASH_ReadByte(uint32_t Addr)
{
	return *(__IO uint8_t *)Addr;		//vu8
}
//读2个字节
//读取指定地址的半字(16位数据)
//faddr:读地址(此地址必须为2的倍数!!)
//返回值:对应数据
uint16_t STMFLASH_ReadHalfWord(uint32_t Addr)
{
	return *(__IO uint16_t *)Addr;		//vu16
}
//读4个字节
uint32_t STMFLASH_ReadWord(uint32_t faddr)
{
	return *(__IO uint32_t*)faddr; 
}


//读N个字节
void STMFLASH_ReadNByte(uint32_t Addr,uint8_t *pBuff,uint32_t Len)
{
	uint32_t i;
	
	for(i=0;i<Len;i++)
	{
		pBuff[i] = STMFLASH_ReadByte(Addr);
		Addr += 1;
	}
}

/*
void Test_Flash_WR(uint8_t Page_Num)
{
	uint16_t 	i = 0;
	uint8_t 	j = 0;
	uint8_t 	buff[STM32_SECTOR_SIZE];	//最多是2K字节
	
	//是否超出范围
	if(Page_Num > STM32_SECTOR_NUM)
		return;
	
	for(i = 0;i < STM32_SECTOR_SIZE;i++)
	{
		buff[i] = j++;
	}
	//页擦除
//	Flash_EraseSector(Page_Num,Page_Num);
	//写入
//	FLASH_WritePage(Page_Num,buff);
	//写入
//	FLASH_WriteNByte(Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE,buff,STM32_SECTOR_SIZE);
	//写入
	STMFLASH_WriteNData(Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE + 4,buff,10);
	
	//清零
	memset(buff,0,STM32_SECTOR_SIZE);
	//读出
	FLASH_ReadPage(Page_Num,buff);
	
	for(i = 0;i < STM32_SECTOR_SIZE;i++)
	{
		printf("%02X ",buff[i]);
	}
	printf("\r\n");
}

*/
