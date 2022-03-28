#include "sys.h"
#include "delay.h"   
#include "stmflash.h" 
#include "iap.h"   

//ALIENTEK 探索者STM32F407开发板 实验50
//串口IAP实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

u32 flashbuf[512]; 	//2K字节缓存 
void Bootloader_JUMP(u32 Sect,u32 Msp,u32 Reset);

int main(void)
{ 	
	  u32 Buf_update[2]={0};
		u32 buf[4];
		u32 msp;
		u32 reset;
		
	  delay_init(168);  //初始化延时函数		
	  STMFLASH_Read(FLASH_UPDATE_ADDR ,Buf_update,2);	
	  if((Buf_update[0] == 0xA0A0A0A0)&&(Buf_update[1]!=0))//the flag of update code
		{
			Flash_to_Flash_Write(FLASH_APP2_ADDR, FLASH_APP1_ADDR, Buf_update[1]/4);
		  Buf_update[0] = 0;
			Buf_update[1] = 0;
			STMFLASH_Write(FLASH_UPDATE_ADDR,Buf_update,2);			
		}
	  STMFLASH_Read(FLASH_APP1_ADDR,buf,2);
		msp = buf[0];
		reset = buf[1];
		Bootloader_JUMP(FLASH_APP1_ADDR,msp,reset);
		while(1);   									 	  		   		 
 
}
void Bootloader_JUMP(u32 Sect,u32 Msp,u32 Reset)
{
  u32 base;
	u32 offset;
	base = (Sect > NVIC_VectTab_FLASH) ? NVIC_VectTab_FLASH : NVIC_VectTab_RAM;
  offset = Sect - base;
	NVIC_SetVectorTable(base,offset);
	__set_MSP(Msp);
	((void (*)())(Reset))();
}
void Flash_to_Flash_Write(u32 src_addr,u32 dest_addr,u32 block_len)
{
    u32 Buff[4]={0};
	  uint32_t offset = 0;
    uint32_t current_len = 0;
    current_len = block_len;

		while(current_len > 0)
		{
				if(current_len >= 4)						
				{ 
					/*read flash value from backup flash 0x0804 0000*/
						STMFLASH_Read(src_addr + offset ,Buff,4);			
          /*write flash value to 0x0801 0000 flash*/					
						STMFLASH_Write(dest_addr + offset,Buff,4);
						Buff[0]=0;
						Buff[1]=0;
						Buff[2]=0;
						Buff[3]=0;
						offset += 16;
						current_len = current_len-4;
				}
				else if(current_len < 4)
				{
				  /*read flash value from backup flash 0x0804 0000*/
						STMFLASH_Read(src_addr + offset ,Buff,current_len);			
          /*write flash value to 0x0801 0000 flash*/					
						STMFLASH_Write(dest_addr + offset,Buff,current_len);  
					  current_len = 0;
				}
			 
		}

}
