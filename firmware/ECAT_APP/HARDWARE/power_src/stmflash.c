#include "stmflash.h"
#include "delay.h"
#include <string.h>
 
//////////////////////////////////////////////////////////////////////////////////	 

//дN�ֽں������Ȱ�ҳ���ݶ��������У�Ȼ�������Ӧ��ҳ����д��
void STMFLASH_WriteNData(uint32_t Addr,uint8_t *pBuff,uint32_t Len)
{
	u8 STM32_FLASH_BUFF[STM32_SECTOR_SIZE];	//�����2K�ֽ�
	
	uint32_t Offset;
	uint8_t  Page_Num;
	uint16_t Page_Offset;
	uint16_t Free_Space;
	uint16_t i;
	
	//ע�ⲻҪ����flash��Χ
	if(Addr < STM32_FLASH_BASE)		// || (Addr >=(STM32_FLASH_BASE+1024*STM32_SECTOR_NUM)))	
		return;
	
	Offset = Addr - STM32_FLASH_BASE;								//ƫ�Ƶ�ַ
	Page_Num = Offset / STM32_SECTOR_SIZE;					//�õ���ַ����ҳ
	Page_Offset = Offset % STM32_SECTOR_SIZE;				//��ҳ�ڵ�ƫ�Ƶ�ַ
	Free_Space = STM32_SECTOR_SIZE -  Page_Offset;	//ҳ��ʣ��ռ�
	
	//Ҫд��������Ƿ����ʣ��ռ�
	if(Len <= Free_Space)
		Free_Space = Len;
	
	FLASH_Unlock();//����
	
	while(1)
	{
		STMFLASH_ReadPage(Page_Num,STM32_FLASH_BUFF);//�Ȱ����ݶ���������
		FLASH_ErasePage(Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE);	//ҳ������ҳ��ʼ��ַ
		//�޸Ļ�������
		for(i = 0;i < Free_Space;i++)
		{
			STM32_FLASH_BUFF[i+Page_Offset] = pBuff[i];
		}
		STMFLASH_WritePage(Page_Num,STM32_FLASH_BUFF);//�ѻ�������д��
		//�ж��Ƿ񳬳���ǰҳ������������һҳ
		if(Len == Free_Space)
			break;
		else
		{
			Page_Num++;//��һҳ
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

//д���ֽڣ�Ҫ���Ǵ������׵�ַд�룬�ɿ�����д��APP����ʱ�ã�������������app����ǰ�Ѳ�����������
void STMFLASH_WriteNByte_NoErase(uint32_t Addr,uint8_t *pBuff,uint32_t Len)
{
	uint16_t i;
	uint16_t temp = 0;
	
	if((Addr >= STM32_FLASH_BASE)&&(Len <= 50*STM32_SECTOR_SIZE))	//����ռ�ҪС��Լ���Ĵ�С100k
	{
		FLASH_Unlock();//����
		
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

//����ָ��ҳ�ĺ���
void STMFlash_EraseSector(uint8_t Start_Page,uint8_t End_Page)
{
	uint8_t i;
	uint8_t num = 0;
	
	if(Start_Page > End_Page)
		return;
	
	FLASH_Unlock();//����
	
	num = End_Page - Start_Page;//����ҳ��
	
	for(i = 0;i <= num;i++)
	{
		FLASH_ErasePage((Start_Page + i) * STM32_SECTOR_SIZE + STM32_FLASH_BASE);//ҳ����
	}
	
	FLASH_Lock();
}

//��ȡ1��ҳ����
void STMFLASH_ReadPage(uint16_t Page_Num,uint8_t *pBuff)
{
	uint16_t i;
	uint32_t Buff;
	uint32_t Addr;
	
	//�Ƿ񳬳���Χ
	if(Page_Num > (STM32_SECTOR_NUM-1))		//0-127
		return;
	//�ȼ���ҳ�׵�ַ
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

//д��1��ҳ����
void STMFLASH_WritePage(uint16_t Page_Num,uint8_t *pBuff)
{
	uint16_t i;
	uint16_t Buff;
	uint32_t Addr;
	
	//�Ƿ񳬳���Χ
	if(Page_Num > (STM32_SECTOR_NUM-1))		//0-127
		return;
	//����
	FLASH_Unlock();
	//�ȼ���ҳ�׵�ַ
	Addr = Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE;
	
	for(i = 0;i < STM32_SECTOR_SIZE ;i += 2)
	{
		Buff = ((uint16_t)pBuff[i+1] << 8) | pBuff[i];
		FLASH_ProgramHalfWord(Addr,Buff);
		Addr += 2;
	}
	//����
	FLASH_Lock();
}


//��1���ֽ�
uint8_t STMFLASH_ReadByte(uint32_t Addr)
{
	return *(__IO uint8_t *)Addr;		//vu8
}
//��2���ֽ�
//��ȡָ����ַ�İ���(16λ����)
//faddr:����ַ(�˵�ַ����Ϊ2�ı���!!)
//����ֵ:��Ӧ����
uint16_t STMFLASH_ReadHalfWord(uint32_t Addr)
{
	return *(__IO uint16_t *)Addr;		//vu16
}
//��4���ֽ�
uint32_t STMFLASH_ReadWord(uint32_t faddr)
{
	return *(__IO uint32_t*)faddr; 
}


//��N���ֽ�
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
	uint8_t 	buff[STM32_SECTOR_SIZE];	//�����2K�ֽ�
	
	//�Ƿ񳬳���Χ
	if(Page_Num > STM32_SECTOR_NUM)
		return;
	
	for(i = 0;i < STM32_SECTOR_SIZE;i++)
	{
		buff[i] = j++;
	}
	//ҳ����
//	Flash_EraseSector(Page_Num,Page_Num);
	//д��
//	FLASH_WritePage(Page_Num,buff);
	//д��
//	FLASH_WriteNByte(Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE,buff,STM32_SECTOR_SIZE);
	//д��
	STMFLASH_WriteNData(Page_Num * STM32_SECTOR_SIZE + STM32_FLASH_BASE + 4,buff,10);
	
	//����
	memset(buff,0,STM32_SECTOR_SIZE);
	//����
	FLASH_ReadPage(Page_Num,buff);
	
	for(i = 0;i < STM32_SECTOR_SIZE;i++)
	{
		printf("%02X ",buff[i]);
	}
	printf("\r\n");
}

*/
