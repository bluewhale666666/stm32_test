#include <string.h>
#include "ecat_def.h"
#include "stmflash.h"
#include "stm32f4xx.h" 
#include "delay.h"
//#include "F28x_Project.h" // Device Header file and Examples Include File
//#include "F2837xD_Ipc_drivers.h"
#include "stm32f4xx_flash.h"
#define CAN_WATCH  1
#define DSP_ONE    0
#define DSP_TWO    1

#define FILE_LEN   9

#define TLR_TRUE   1
#define TLR_FALSE  0

#define PACKET_SEQ_LAST 0x06

#define CODE_SIZE       (0x10 + 5)      // + 5 for Length and address offset
#define ADDR_SIZE        6
#define FLASH_SAVE_ADDR_offset  0X00030000 	//设置FLASH 保存地址偏移量(必须为偶数，且所在扇区,要大于本代码所占用到的扇区.6扇区
#define FLASH_UPDATE_ADDR       0X08071000  //设置备份程序更新标志位
//UINT8 pBuff_uint8[240];
#define Flash_UPDATE_FLAG       0xA0A0A0A0
UINT8 forCRC_data[30];
uint32_t Block_total_num;
uint32_t ArrFlash_Update[2];
//#pragma arm section code = "RAMCODE"
typedef volatile struct FLASH_ADDR 
{
    UINT32 flash_src_addr;
    UINT32 flash_dest_addr;
    UINT16 flash_offset;
    UINT32 block_size;
}Flash_addr;

Flash_addr Flash_Ptr[ADDR_SIZE]={0};

UINT16 is_update  = 0;
UINT16 write_ok   = 0;
UINT8 STM32_FlashCode[CODE_SIZE];
//#pragma arm section
//UINT16  DSP_FlashCode[CODE_SIZE];
//#pragma DATA_SECTION(DSP_FlashCode,"BufferDataSection3");


//#pragma DATA_SECTION(Flash_Ptr,"BufferDataSection1")

UINT8 addr_i = 0;
UINT16 addr_block;
//#pragma DATA_SECTION(addr_i,"BufferDataSection2")

//extern UINT16 Flash_Init();
//extern UINT16 Flash_Erase(UINT32 Flash_Section_addr);
//extern UINT16 Flash_Write(UINT32 Flash_Section_addr,UINT16 *pBuff);
 void Flash_to_Flash_Write(Flash_addr *pFlash_Ptr,UINT8 block_num);
void Flash_Write(uint32_t section_base_addr,uint16_t offset_t,uint32_t *pBuff,uint16_t len_t);
/*************************************************************************************************
 * @brief This functions decode the hex file
 * @param pBuff   Pointer to file data buff.
 *************************************************************************************************/
//static UINT16 DECODE(UINT16 *pBuff,UINT16 ulLen)
//{
//    UINT16 i = 0, Length = 0;
//	  UINT8 j = 0;
//    UINT8 uData_H = 0, uData_L = 0;
//	  
//  	for(j=0;j<ulLen;j++)
//	 {
//	   pBuff_uint8[2*j] = pBuff[j]&0x00ff;
//		 pBuff_uint8[2*j+1] = ( pBuff[j]&0xff00 )>>8;
//	 }
//	

//    if((pBuff_uint8[1]>='0')&&(pBuff_uint8[1]<='9'))
//        uData_H = pBuff_uint8[1] - '0';
//    else
//        uData_H = pBuff_uint8[1] - 'A' + 10;

//    if((pBuff_uint8[2]>='0')&&(pBuff_uint8[2]<='9'))
//        uData_L = pBuff_uint8[2] - '0';
//    else
//        uData_L = pBuff_uint8[2] - 'A' + 10;

//    Length = ((uData_H<<8)|uData_L)*2+9;

//    for(i = 3; i < Length; i++)
//    {
//        if(pBuff_uint8[8] != '1')
//        {
//            pBuff_uint8[i] = pBuff_uint8[i] - 2;

//            if(pBuff_uint8[i] == '?')
//                pBuff_uint8[i] = '8';
//            else if(pBuff_uint8[i] == '@')
//                pBuff_uint8[i] = '9';
//            else if(pBuff_uint8[i] == '.')
//                pBuff_uint8[i] = 'E';
//            else if(pBuff[i] == '/')
//                pBuff_uint8[i] = 'F';
//        }
//    }

//    return 0;
//}

/*************************************************************************************************
 * @brief This functions handles CRC check
 * @param pBuff   Pointer to file data buff.
 * @param len     length of buff.
 *************************************************************************************************/
static UINT16 F_CHKSUM(UINT8* pBuff, UINT16 Length)
{
    UINT16 i = 0, CHKSUM = 0;
	UINT8 value;
    for(i = 0; i < Length-1; i++)
    {
        CHKSUM += pBuff[i];
    }

    CHKSUM = CHKSUM%256;
	CHKSUM = 256 - CHKSUM;
	value = CHKSUM&0x00ff;
	if(pBuff[Length-1] == value)		
		 return 0;
    else
		return 1;
    
}

/*************************************************************************************************
 * @brief This functions handles ASCII from FoE file
 * @param pBuff   Pointer to file data buff.
 * @param len     length of buff.
 *************************************************************************************************/
static void ASCII_Handle(UINT16 *pBuff,UINT16 len)
{
    UINT16 i = 0, Length = 0 ;
	  UINT8 j = 0 ;
    UINT8 uData_H = 0, uData_L = 0;
	  UINT8 pBuff_uint8[240] = {0};
	  memset((char*)forCRC_data,0x0,20);
  	for(j=0;j<len;j++)
	 {
	   pBuff_uint8[2*j] = pBuff[j]&0x00ff;
		 pBuff_uint8[2*j+1] = ( pBuff[j]&0xff00 )>>8;
	 }	
    if((pBuff_uint8[1]>='0')&&(pBuff_uint8[1]<='9'))
        uData_H = pBuff_uint8[1] - '0';
    else
        uData_H = pBuff_uint8[1] - 'A' + 10;

    if((pBuff_uint8[2]>='0')&&(pBuff_uint8[2]<='9'))
        uData_L = pBuff_uint8[2] - '0';
    else
        uData_L = pBuff_uint8[2] - 'A' + 10;
		
    Length = ((uData_H<<4)|uData_L)*2+11;

    for(i = 1; i < Length; i+=2)
    {						
		    if((pBuff_uint8[i]>='0')&&(pBuff_uint8[i]<='9'))
          uData_H = pBuff_uint8[i] - '0';
        else
         uData_H = pBuff_uint8[i] - 'A' + 10;
		 
		   if((pBuff_uint8[i+1]>='0')&&(pBuff_uint8[i+1]<='9'))
         uData_L = pBuff_uint8[i+1] - '0';
        else
         uData_L = pBuff_uint8[i+1] - 'A' + 10;
		 
		   forCRC_data[(i-1)/2] = (uData_H<<4)|uData_L;		
	}
}

///*************************************************************************************************
// * @brief This functions handles FoE write file indications for virtual files
// * @param ptData             Pointer to foe packet.
// * @param ulLen              length  of foe packet.
// * @param end_flag           end flag.
// *************************************************************************************************/
UINT16 FoEWriteFileInd(UINT16* ptData,UINT16 ulLen,UINT16 end_flag)
{
    /* variable for result values */
    UINT16 tResult = 0;
    UINT16 i = 0,j =0;
    static UINT16 tfirsttime = TLR_TRUE,tlasttime = TLR_FALSE;

    char VirtStrName1[] = "ecat";

    if (tfirsttime)   //the name of the file
    {
        tfirsttime = TLR_FALSE;

        /*check correct length in first packet*/
        if(sizeof(VirtStrName1) - 1 != ulLen )
        {
            tResult = 1;
        }
        else if(0 == memcmp(ptData, &VirtStrName1, ulLen))
        {
            addr_i = 0;
            tResult = 0;
        }
       else
        {
           /* recycle the ind, generate res and reply it */
           tResult = 1;
           tfirsttime = TLR_TRUE;
        }
    }
   else
    {
       /*check if last packet*/
       if ((ulLen < 116)||(end_flag == PACKET_SEQ_LAST))
       {
           tfirsttime = TLR_TRUE;
           tlasttime  = TLR_TRUE;
       }
       /*you got the data on second and following indications, save it or do what you want with it*/
//       DECODE(ptData,ulLen);
      
       ASCII_Handle(ptData,ulLen);

       if(0 == F_CHKSUM(forCRC_data, forCRC_data[0]+5))
       {
					 if(forCRC_data[3] == 0x04)
					 {                 
						 Flash_Ptr[addr_i].flash_src_addr = ((forCRC_data[4] << 8 | forCRC_data[5])<<16 ) + FLASH_SAVE_ADDR_offset;		//the start_address of backup flash			   
						 Flash_Ptr[addr_i].flash_dest_addr = (forCRC_data[4] << 8 | forCRC_data[5])<<16 ; ////the start_address of default flash	
						 Flash_Ptr[addr_i].flash_offset    = (forCRC_data[1] << 8) | forCRC_data[2];				 
						 Flash_Ptr[addr_i].block_size      = 0;
						 addr_i++;
						 tResult = 0;							
						}
					 else if(forCRC_data[3] == 0x0)
					 {							
							memset((char*)STM32_FlashCode,0xFF,CODE_SIZE);

							for(i = 0; i < STM32_FlashCode[0]+4; i++)
							{
							 STM32_FlashCode[i] = forCRC_data[i];
							}
							Flash_Ptr[addr_i-1].block_size += STM32_FlashCode[0];
							Flash_Write(Flash_Ptr[addr_i-1].flash_src_addr ,(STM32_FlashCode[1]<<8|STM32_FlashCode[2]),(uint32_t*)(STM32_FlashCode+4),STM32_FlashCode[0]);					 
							tResult = 0;	           			   
						} 
					 else if(forCRC_data[3] == 0x1)
						{ 
							write_ok =1;
							for(j=0;j<addr_i;j++)
							Block_total_num +=Flash_Ptr[j].block_size;
						}
        }
        else
        {
          return 1;
        }
     }
    if(tlasttime)
    {
	    is_update  = tlasttime;
      write_ok   = 0;
      tlasttime  = TLR_FALSE;
    }

    return tResult;
}
#pragma arm section code = "RAMCODE"
void Flash_UpdateStart(UINT16 is_ok)
{	 
		if(0 == is_ok)
		{
			 ArrFlash_Update[0] = Flash_UPDATE_FLAG;
			 ArrFlash_Update[1] = Block_total_num;
			 STMFLASH_Write(FLASH_UPDATE_ADDR,ArrFlash_Update,2);  
//          Flash_to_Flash_Write(&Flash_Ptr[0],addr_i);
		}

}
void Flash_Write(uint32_t section_base_addr,uint16_t offset_t,uint32_t *pBuff,uint16_t len_t)
{
    uint16_t current_len = 0;
    uint32_t write_addr = 0,offset = 0;
    current_len = len_t;

    if(current_len > 0)
    {
        write_addr = section_base_addr+offset_t+offset;
        STMFLASH_Write(write_addr,pBuff,current_len/4);        
        delay_us(10);
    }
}

//void Flash_to_Flash_Write(Flash_addr *pFlash_Ptr,UINT8 block_num)
//{
//    uint16_t i = 0;
//    uint32_t Flash_start = 0;
//    uint32_t Buff[1];
//	  uint16_t offset = 0;
//    uint32_t current_len = 0;

//    for(i = 0; i < block_num; i++)
//    {
//        Flash_start = (pFlash_Ptr[i].flash_src_addr+pFlash_Ptr[i].flash_offset);
//        current_len = pFlash_Ptr[i].block_size;
//        offset = 0;
//        memset(Buff,0,1);

//        while(current_len > 0)
//        {
//            if(current_len >= 4)						
//            { 
//								STMFLASH_Read(Flash_start + offset ,Buff,1);																			
//							  Flash_Write(pFlash_Ptr[i].flash_dest_addr,pFlash_Ptr[i].flash_offset,Buff,4);
//								memset(Buff,0,1);
//								offset += 4;
//								current_len -= 4;
//            }
//           
//        }
//    }

//    while(1);
//}
#pragma arm section
