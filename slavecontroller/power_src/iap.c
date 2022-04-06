#include "sys.h"
#include "delay.h"
#include "iap.h"
#include "stmflash.h"

//////////////////////////////////////////////////////////////////////////////////
//stm32f103rct6  	  	256K
//			分区					大小					扇区					备注
//bootloader					40k			  		0-19          引导程序			0000---
//APP								 100k			  	 20-69         APP程序				A000---
//Dowload					   100k			  	 70-119        下载缓存				23000----
//flag						    2k			  		127          其他标志				3F800----				  
//////////////////////////////////////////////////////////////////////////////////	


////从备份的程序存储区域copy至APP区域
//void IAP_Copy_App(void)
//{
//	uint8_t i;
//	uint8_t buf[2] = {0x00,0x00};
//	uint8_t STM32_FLASH_BUFF[STM32_SECTOR_SIZE];	//最多是2K字节
//	
//	//擦除App扇区
//	Flash_EraseSector(20,69);
//	
//	for(i = 0;i < 50;i++)
//	{
//		FLASH_ReadPage(70 + i,STM32_FLASH_BUFF);
//		FLASH_WritePage(20 + i,STM32_FLASH_BUFF);
//	}
//	
//	FLASH_WriteNData(FLASH_UPDATA_FLAG_ADDR,buf,2);	//标志区域写0
//}


//
void IAP_WriteBin(uint32_t Addr,uint8_t *pBuff,uint32_t Len)
{
	uint8_t buf[2] = {0x55,0xAA};
	
	//擦除DOWNLOAD扇区
	STMFlash_EraseSector(70,119);				//(70,119);		50,99
	
	//更新标记
	STMFLASH_WriteNData(FLASH_UPDATA_FLAG_ADDR,buf,2);
	
	//写入程序
	STMFLASH_WriteNByte_NoErase(Addr,pBuff,Len);	
	
	//复位单片机
//	NVIC_SystemReset();
}


//跳转到应用程序段
//appxaddr:用户代码起始地址.
void iap_load_app(u32 appxaddr)
{
	iapfun jump2app; 	
	
	RCC_DeInit();//关闭外设
	NVIC_DeInit();
	
	if(((*(vu32*)appxaddr)&0x2FFE0000)==0x20000000)	//检查栈顶地址是否合法.
	{ 
		__disable_irq();		//关闭中断总开关
		
		jump2app=(iapfun)*(vu32*)(appxaddr+4);				//用户代码区第二个字为程序开始地址(复位地址)		
		MSR_MSP(*(vu32*)appxaddr);										//初始化APP堆栈指针(用户代码区的第一个字用于存放栈顶地址)
		jump2app();																		//跳转到APP.
	}
}		 

void app_load_iap(void)
{
	u32 IapSpInitVal;
	u32 IapJumpAddr;
	
	iapfun jump2iap; 

	RCC_DeInit();
	NVIC_DeInit();

	__disable_irq(); //关中断（）

	// APP如跳转前关中断，跳转到IAP后，IAP初始化后要打开中断

	IapSpInitVal = *(u32 *)STM32_FLASH_BASE;

	IapJumpAddr = *(u32 *)(STM32_FLASH_BASE + 4);

	__set_CONTROL(0);

	//进入用户级线程模式 进入软中断后才可以回到特权级线程模式

	//APP如使用系统如ucos必须要有此过程否则跳到IAP后，无法再次跳到APP
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
