#include "sys.h"
#include "delay.h"
#include "iap.h"
#include "stmflash.h"

//////////////////////////////////////////////////////////////////////////////////
//stm32f103rct6  	  	256K
//			����					��С					����					��ע
//bootloader					40k			  		0-19          ��������			0000---
//APP								 100k			  	 20-69         APP����				A000---
//Dowload					   100k			  	 70-119        ���ػ���				23000----
//flag						    2k			  		127          ������־				3F800----				  
//////////////////////////////////////////////////////////////////////////////////	


////�ӱ��ݵĳ���洢����copy��APP����
//void IAP_Copy_App(void)
//{
//	uint8_t i;
//	uint8_t buf[2] = {0x00,0x00};
//	uint8_t STM32_FLASH_BUFF[STM32_SECTOR_SIZE];	//�����2K�ֽ�
//	
//	//����App����
//	Flash_EraseSector(20,69);
//	
//	for(i = 0;i < 50;i++)
//	{
//		FLASH_ReadPage(70 + i,STM32_FLASH_BUFF);
//		FLASH_WritePage(20 + i,STM32_FLASH_BUFF);
//	}
//	
//	FLASH_WriteNData(FLASH_UPDATA_FLAG_ADDR,buf,2);	//��־����д0
//}


//
void IAP_WriteBin(uint32_t Addr,uint8_t *pBuff,uint32_t Len)
{
	uint8_t buf[2] = {0x55,0xAA};
	
	//����DOWNLOAD����
	STMFlash_EraseSector(70,119);				//(70,119);		50,99
	
	//���±��
	STMFLASH_WriteNData(FLASH_UPDATA_FLAG_ADDR,buf,2);
	
	//д�����
	STMFLASH_WriteNByte_NoErase(Addr,pBuff,Len);	
	
	//��λ��Ƭ��
//	NVIC_SystemReset();
}


//��ת��Ӧ�ó����
//appxaddr:�û�������ʼ��ַ.
void iap_load_app(u32 appxaddr)
{
	iapfun jump2app; 	
	
	RCC_DeInit();//�ر�����
	NVIC_DeInit();
	
	if(((*(vu32*)appxaddr)&0x2FFE0000)==0x20000000)	//���ջ����ַ�Ƿ�Ϸ�.
	{ 
		__disable_irq();		//�ر��ж��ܿ���
		
		jump2app=(iapfun)*(vu32*)(appxaddr+4);				//�û��������ڶ�����Ϊ����ʼ��ַ(��λ��ַ)		
		MSR_MSP(*(vu32*)appxaddr);										//��ʼ��APP��ջָ��(�û��������ĵ�һ�������ڴ��ջ����ַ)
		jump2app();																		//��ת��APP.
	}
}		 

void app_load_iap(void)
{
	u32 IapSpInitVal;
	u32 IapJumpAddr;
	
	iapfun jump2iap; 

	RCC_DeInit();
	NVIC_DeInit();

	__disable_irq(); //���жϣ���

	// APP����תǰ���жϣ���ת��IAP��IAP��ʼ����Ҫ���ж�

	IapSpInitVal = *(u32 *)STM32_FLASH_BASE;

	IapJumpAddr = *(u32 *)(STM32_FLASH_BASE + 4);

	__set_CONTROL(0);

	//�����û����߳�ģʽ �������жϺ�ſ��Իص���Ȩ���߳�ģʽ

	//APP��ʹ��ϵͳ��ucos����Ҫ�д˹��̷�������IAP���޷��ٴ�����APP
	__set_MSP(IapSpInitVal);

	jump2iap = (void (*)(void))IapJumpAddr;

	(*jump2iap)();
}

void NVIC_DeInit(void)
{
  u32 index = 0;
   
  NVIC->ICER[0] = 0xFFFFFFFF;
  NVIC->ICER[1] = 0x000007FF;
  NVIC->ICPR[0] = 0xFFFFFFFF;
  NVIC->ICPR[1] = 0x000007FF;
   
  for(index = 0; index < 0x0B; index++)
  {
     NVIC->IP[index] = 0x00000000;
  }  
}
