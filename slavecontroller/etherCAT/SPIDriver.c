/*******************************************************************************
 PIC32 SPI Interface Driver

  Company:
    Microchip Technology Inc.

  File Name:
    SPIDriver.c

  Summary:
    Contains the functional implementation of PIC32 SPI Interface Driver

  Description:
    This file contains the functional implementation of PIC32 SPI Interface Driver
	
  Change History:
    Version		Changes
	0.1			Initial version.
	1.3			Re-arranged the function. Moved the other functions to PIC32SPIDriver.C
*******************************************************************************/

/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
 
#include "SPIDriver.h"
#include "9252_HW.h"

SPI_HandleTypeDef *EcatHspiPtr;
UINT8 EcatSpiReadBuffer[SPI_BUFFER_SIZE];
UINT8 EcatSpiWriteBuffer[SPI_BUFFER_SIZE];

static void SPIWriteBytes(UINT16 Address, UINT8 *Val, UINT8 nLenght);
void CSHIGH(void);
void CSLOW(void);
/*******************************************************************************
  Function:
	UINT32 SPIReadDWord (UINT16 Address)
  Summary:
    This function reads the LAN9252 CSR registers.        
  
*****************************************************************************/
UINT32 SPIReadDWord (UINT16 Address)
{
    UINT32_VAL dwResult;
    UINT16_VAL wAddr;
		UINT8 i;
	
    wAddr.Val  = Address;
    //buffer Clear
    for (i=0;i<8u;i++)
    {
        EcatSpiReadBuffer[i] = 0u;
        EcatSpiWriteBuffer[i] = 0u;
    }
		//Write buffer update
    //Write Command
    EcatSpiWriteBuffer[0u] = (uint8_t)CMD_FAST_READ;
    EcatSpiWriteBuffer[1u] = wAddr.byte.HB;
    EcatSpiWriteBuffer[2u] = wAddr.byte.LB;
    EcatSpiWriteBuffer[3u] = (uint8_t)CMD_FAST_READ_DUMMY;

//		HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_RESET);
		CSLOW();
    HAL_SPI_TransmitReceive(EcatHspiPtr, EcatSpiWriteBuffer, EcatSpiReadBuffer, 8u, ECAT_SPI_TIMEOUT);
		CSHIGH();
//		__HAL_SPI_DISABLE(EcatHspiPtr);
//		HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_SET);

	  dwResult.Val = *((UINT32 *)(&EcatSpiReadBuffer[4u]));

    return dwResult.Val;
}

#define ADDRESS_AUTO_INCREMENT 0x40
/*******************************************************************************
  Function:
	void SPIWriteBytes(UINT16 Address, UINT8 *Val, UINT8 nLenght)
  Summary:
    This function writes the LAN9252 CSR registers.        
  
*****************************************************************************/
static void SPIWriteBytes(UINT16 Address, UINT8 *Val, UINT8 nLenght)
{
    UINT8 *dwData;
    UINT16_VAL wAddr;
		UINT8 i;
		UINT16 size;

		wAddr.Val  = Address;
    dwData = Val;
    size = nLenght + 3u;

    if (size > (uint32_t)SPI_BUFFER_SIZE)
    {
        //Size overflow
    }
    else
    {
        //buffer Clear
        for (i=0;i<size;i++)
        {
						EcatSpiReadBuffer[i] = 0u;
						EcatSpiWriteBuffer[i] = 0u;
        }
        //Write buffer update
        //Write Command
        EcatSpiWriteBuffer[0u] = (uint8_t)CMD_SERIAL_WRITE;
        EcatSpiWriteBuffer[1u] = (wAddr.byte.HB|(uint8_t)ADDRESS_AUTO_INCREMENT);
        EcatSpiWriteBuffer[2u] = wAddr.byte.LB;
        memcpy(&EcatSpiWriteBuffer[3u], dwData, nLenght);
				
//				HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_RESET);
				CSLOW();
				HAL_SPI_TransmitReceive(EcatHspiPtr, EcatSpiWriteBuffer, EcatSpiReadBuffer, size, ECAT_SPI_TIMEOUT);
				CSHIGH();
//				__HAL_SPI_DISABLE(EcatHspiPtr);
//				HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_SET);
    }
}

/*******************************************************************************
  Function:
	void SPIWriteDWord (UINT16 Address, UINT32 Val)
  Summary:
    This function writes the LAN9252 CSR registers.        
  
*****************************************************************************/
void SPIWriteDWord (UINT16 Address, UINT32 Val)
{
    UINT32_VAL dwData;
    UINT16_VAL wAddr;
	  UINT16 i;
		UINT16 size;
		
    wAddr.Val  = Address;
    dwData.Val = Val;
		size = 7u;

    //buffer Clear
    for (i=0;i<size;i++)
    {
				EcatSpiReadBuffer[i] = 0u;
				EcatSpiWriteBuffer[i] = 0u;
    }

    //Write buffer update
    //Write Command
    EcatSpiWriteBuffer[0u] = (uint8_t)CMD_SERIAL_WRITE;
    //Write Address
    EcatSpiWriteBuffer[1u] = wAddr.byte.HB;
    EcatSpiWriteBuffer[2u] = wAddr.byte.LB;
    //Write Bytes
    EcatSpiWriteBuffer[3u] = dwData.byte.LB;
    EcatSpiWriteBuffer[4u] = dwData.byte.HB;
    EcatSpiWriteBuffer[5u] = dwData.byte.UB;
    EcatSpiWriteBuffer[6u] = dwData.byte.MB;

//		HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_RESET);
		CSLOW();
    HAL_SPI_TransmitReceive(EcatHspiPtr, EcatSpiWriteBuffer, EcatSpiReadBuffer, size, ECAT_SPI_TIMEOUT);
		CSHIGH();
		//__HAL_SPI_DISABLE(EcatHspiPtr);
//		HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_SET);
}

/*******************************************************************************
  Function:
   void SPIReadRegUsingCSR(UINT8 *ReadBuffer, UINT16 Address, UINT8 Count)
  Summary:
    This function reads the EtherCAT core registers using LAN9252 CSR registers.        
  
*****************************************************************************/
void SPIReadRegUsingCSR(UINT8 *ReadBuffer, UINT16 Address, UINT8 Count)
{
    UINT32_VAL param32_1 = {0};
    UINT8 i = 0;
    UINT16_VAL wAddr;
    wAddr.Val = Address;

    param32_1.v[0] = wAddr.byte.LB;
    param32_1.v[1] = wAddr.byte.HB;
    param32_1.v[2] = Count;
    param32_1.v[3] = ESC_READ_BYTE;

    SPIWriteDWord (ESC_CSR_CMD_REG, param32_1.Val);

    do
    {
        param32_1.Val = SPIReadDWord (ESC_CSR_CMD_REG);
		
    }while(param32_1.v[3] & ESC_CSR_BUSY);

    param32_1.Val = SPIReadDWord (ESC_CSR_DATA_REG);

    
    for(i=0;i<Count;i++)
         ReadBuffer[i] = param32_1.v[i];
   
    return;
}

/*******************************************************************************
  Function:
   void SPIWriteRegUsingCSR( UINT8 *WriteBuffer, UINT16 Address, UINT8 Count)
  Summary:
    This function writes the EtherCAT core registers using LAN9252 CSR registers.        
  
*****************************************************************************/
void SPIWriteRegUsingCSR( UINT8 *WriteBuffer, UINT16 Address, UINT8 Count)
{
    UINT32_VAL param32_1 = {0};
    UINT8 i = 0;
    UINT16_VAL wAddr;

    for(i=0;i<Count;i++)
         param32_1.v[i] = WriteBuffer[i];

    SPIWriteDWord (ESC_CSR_DATA_REG, param32_1.Val);


    wAddr.Val = Address;

    param32_1.v[0] = wAddr.byte.LB;
    param32_1.v[1] = wAddr.byte.HB;
    param32_1.v[2] = Count;
    param32_1.v[3] = ESC_WRITE_BYTE;

    SPIWriteDWord (0x304, param32_1.Val);
    do
    {
        param32_1.Val = SPIReadDWord (0x304);

    }while(param32_1.v[3] & ESC_CSR_BUSY);

    return;
}

/*******************************************************************************
  Function:
   void SPIReadPDRamRegister(UINT8 *ReadBuffer, UINT16 Address, UINT16 Count)
  Summary:
    This function reads the PDRAM using LAN9252 FIFO.        
  
*****************************************************************************/
void SPIReadPDRamRegister(UINT8 *ReadBuffer, UINT16 Address, UINT16 Count)
{
    UINT64_VAL param32_1 = {0};
    UINT8 i = 0,nlength, nBytePosition;
    UINT8 nReadSpaceAvblCount;
    UINT16 RefAddr = Address;
    UINT16_VAL wAddr;
    UINT16 j;
		UINT16 size;
		
	/*Reset/Abort any previous commands.*/
    param32_1.Val = PRAM_RW_ABORT_MASK;                                                 

    SPIWriteDWord (PRAM_READ_CMD_REG, param32_1.Val);

    /*The host should not modify this field unless the PRAM Read Busy
    (PRAM_READ_BUSY) bit is a 0.*/
	do
    {
        param32_1.Val = SPIReadDWord (PRAM_READ_CMD_REG);

    }while((param32_1.v[3] & PRAM_RW_BUSY_8B));
    
    /*Write Address and Length Register (PRAM_READ_ADDR_LEN) with the
    starting UINT8 address and length) and Set PRAM Read Busy (PRAM_READ_BUSY) bit(-EtherCAT Process RAM Read Command Register)
    to start read operatrion*/
	param32_1.w[0] = Address;
    param32_1.w[1] = Count;
    param32_1.w[2] = 0x0;
    param32_1.w[3] = 0x8000;
    
	SPIWriteBytes (PRAM_READ_ADDR_LEN_REG, (UINT8*)&param32_1.Val,8);   

    /*Read PRAM Read Data Available (PRAM_READ_AVAIL) bit is set*/
    do
    {
        param32_1.Val = SPIReadDWord (PRAM_READ_CMD_REG);

    }while(!(param32_1.v[0] & IS_PRAM_SPACE_AVBL_MASK));

    nReadSpaceAvblCount = param32_1.v[1] & PRAM_SPACE_AVBL_COUNT_MASK;

    /*Fifo registers are aliased address. In indexed it will read indexed data reg 0x04, but it will point to reg 0
     In other modes read 0x04 FIFO register since all registers are aliased*/

    /*get the UINT8 lenth for first read*/
    //Auto increment is supported in SPIO
    param32_1.Val = SPIReadDWord (PRAM_READ_FIFO_REG);
    nReadSpaceAvblCount--;
    nBytePosition = (Address & 0x03);
    nlength = (4-nBytePosition) > Count ? Count:(4-nBytePosition);
    memcpy(ReadBuffer+i ,&param32_1.v[nBytePosition],nlength);
    Count-=nlength;
    i+=nlength;

    wAddr.Val  = PRAM_READ_FIFO_REG;
    size = Count + 4u;

    if (size > (uint32_t)SPI_BUFFER_SIZE)
    {
        //Size overflow
    }
    else
    {
        //buffer Clear
        for (j=0;j<size;j++)
        {
						EcatSpiReadBuffer[i] = 0u;
						EcatSpiWriteBuffer[i] = 0u;
        }
        //Write buffer update
        //Write Command
        EcatSpiWriteBuffer[0u] = (uint8_t)CMD_FAST_READ;
        EcatSpiWriteBuffer[1u] = wAddr.byte.HB;
        EcatSpiWriteBuffer[2u] = wAddr.byte.LB;
        EcatSpiWriteBuffer[3u] = (uint8_t)CMD_FAST_READ_DUMMY;

//				HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_RESET);
				CSLOW();
				HAL_SPI_TransmitReceive(EcatHspiPtr, EcatSpiWriteBuffer, EcatSpiReadBuffer, size, ECAT_SPI_TIMEOUT);
				CSHIGH();
				//__HAL_SPI_DISABLE(EcatHspiPtr);
//				HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_SET);
				
        memcpy((ReadBuffer+i) ,&(EcatSpiReadBuffer[4u]),Count);
    }
    return;
}
        
/*******************************************************************************
  Function:
   void SPIWritePDRamRegister(UINT8 *WriteBuffer, UINT16 Address, UINT16 Count)
  Summary:
    This function writes the PDRAM using LAN9252 FIFO.        
  
*****************************************************************************/
void SPIWritePDRamRegister(UINT8 *WriteBuffer, UINT16 Address, UINT16 Count)
{
    UINT64_VAL param32_1 = {0};
    UINT8 i = 0,nlength, nBytePosition,nWrtSpcAvlCount;
    UINT16_VAL wAddr;
    UINT16 j;
    UINT16 size;
    /*Reset or Abort any previous commands.*/
    param32_1.Val = PRAM_RW_ABORT_MASK;                                                

    SPIWriteDWord (PRAM_WRITE_CMD_REG, param32_1.Val);

    /*Make sure there is no previous write is pending
    (PRAM Write Busy) bit is a 0 */
    do
    {
        param32_1.Val = SPIReadDWord (PRAM_WRITE_CMD_REG);

    }while((param32_1.v[3] & PRAM_RW_BUSY_8B));

    /*Write Address and Length Register (ECAT_PRAM_WR_ADDR_LEN) with the
    starting UINT8 address and length) and write to the EtherCAT Process RAM Write Command Register (ECAT_PRAM_WR_CMD) with the  PRAM Write Busy
    (PRAM_WRITE_BUSY) bit set*/
	param32_1.w[0] = Address;
    param32_1.w[1] = Count;
    param32_1.w[2] = 0x0;
    param32_1.w[3] = 0x8000;
    
   SPIWriteBytes (PRAM_WRITE_ADDR_LEN_REG, (UINT8*)&param32_1.Val,8);

   /*Read PRAM write Data Available (PRAM_READ_AVAIL) bit is set*/
	do
    {
       param32_1.Val = SPIReadDWord (PRAM_WRITE_CMD_REG);

    }while(!(param32_1.v[0] & IS_PRAM_SPACE_AVBL_MASK));

    /*Check write data available count*/
    nWrtSpcAvlCount = param32_1.v[1] & PRAM_SPACE_AVBL_COUNT_MASK;

    /*Write data to Write FIFO) */ 
    /*get the byte lenth for first read*/
    nBytePosition = (Address & 0x03);

    nlength = (4-nBytePosition) > Count ? Count:(4-nBytePosition);

    param32_1.Val = 0;
    memcpy(&param32_1.v[nBytePosition],WriteBuffer+i, nlength);

    SPIWriteDWord (PRAM_WRITE_FIFO_REG,param32_1.Val);

    nWrtSpcAvlCount--;
    Count-=nlength;
    i+=nlength;
		
    wAddr.Val  = PRAM_WRITE_FIFO_REG;
    size = Count + 3u;

    if (size > (uint32_t)SPI_BUFFER_SIZE)
    {
        //Size overflow
    }
    else
    {
        //buffer Clear
        for (j=0;j<size;j++)
        {
						EcatSpiReadBuffer[i] = 0u;
						EcatSpiWriteBuffer[i] = 0u;
        }
        //Write buffer update
        //Write Command
        EcatSpiWriteBuffer[0u] = (uint8_t)CMD_SERIAL_WRITE;
        EcatSpiWriteBuffer[1u] = wAddr.byte.HB;
        EcatSpiWriteBuffer[2u] = wAddr.byte.LB;
        memcpy(&EcatSpiWriteBuffer[3u], (WriteBuffer+i), Count);

//				HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_RESET);
				CSLOW();
        HAL_SPI_TransmitReceive(EcatHspiPtr, EcatSpiWriteBuffer, EcatSpiReadBuffer, size, ECAT_SPI_TIMEOUT);
				CSHIGH();
				//__HAL_SPI_DISABLE(EcatHspiPtr);
//				HAL_GPIO_WritePin(GPIOG,4u,GPIO_PIN_SET);
    }
    return;
}

/*******************************************************************************
  Function:
   void PDIReadReg(UINT8 *ReadBuffer, UINT16 Address, UINT16 Count)
  Summary:
    This function reads the ESC registers using LAN9252 CSR or FIFO.         
  
*****************************************************************************/
void PDIReadReg(UINT8 *ReadBuffer, UINT16 Address, UINT16 Count)
{
    if (Address >= 0x1000)
    {
         SPIReadPDRamRegister(ReadBuffer, Address,Count);
    }
    else
    {
         SPIReadRegUsingCSR(ReadBuffer, Address,Count);
    }
}

/*******************************************************************************
  Function:
   void PDIWriteReg( UINT8 *WriteBuffer, UINT16 Address, UINT16 Count)
  Summary:
    This function writes the ESC registers using LAN9252 CSR or FIFO.        
  
*****************************************************************************/
void PDIWriteReg( UINT8 *WriteBuffer, UINT16 Address, UINT16 Count)
{
   
   if (Address >= 0x1000)
   {
		SPIWritePDRamRegister(WriteBuffer, Address,Count);
   }
   else
   {
		SPIWriteRegUsingCSR(WriteBuffer, Address,Count);
   }
    
}

/*******************************************************************************
  Function:
	UINT32 PDIReadLAN9252DirectReg( UINT16 Address)
  Summary:
    This function reads the LAN9252 CSR registers(Not ESC registers).        
  
*****************************************************************************/
UINT32 PDIReadLAN9252DirectReg( UINT16 Address)
{   
    UINT32 data;
    data = SPIReadDWord (Address);
    return data;
}

/*******************************************************************************
  Function:
	void PDIWriteLAN9252DirectReg( UINT32 Val, UINT16 Address)
  Summary:
    This function writes the LAN9252 CSR registers(Not ESC registers).        
  
*****************************************************************************/
void PDIWriteLAN9252DirectReg( UINT32 Val, UINT16 Address)
{
    SPIWriteDWord (Address, Val);
}

void CSHIGH(void)
{
	 //atomic
	 GPIOG->ODR |= ((uint32_t)1u << 4u);
	 EcatHspiPtr->Instance->CR1 |= 0x0010;
}

void CSLOW(void)
{
	 //atomic
	 GPIOG->ODR &= 0xffefu;
	 EcatHspiPtr->Instance->CR1 &= 0xffefu;
}