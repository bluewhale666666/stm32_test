/**
   ******************************
   *file    ad_da_spi.h  
   *author  liu
	 *version V1.0.0
   *date    2021/11/2
   *brief   spi drive
   ******************************
   */

/* Define to prevent recursive inclusion ---------------------------------*/
#ifndef __AD_DA_SPI_H
#define __AD_DA_SPI_H


/* Includes -------------------------------------------------------------*/
#include "sys.h"
#include "stm32f4xx.h"
#include "stm32f4xx_spi.h"
#include "ecat_def.h"
#include "Robot-Device.h"
#include "delay.h"


extern void SPI2_Init(void);			 //初始化SPI2口
extern void SPI2_SetSpeed(u8 SpeedSet); //设置SPI2速度   
extern UINT16 SPI2_ReadWriteWord(UINT16 TxData);//SPI2总线读写一个字节

extern void SPI3_Init(void);			 //初始化SPI3口
extern void SPI3_SetSpeed(u8 SpeedSet); //设置SPI3速度   
extern UINT8 SPI3_ReadWriteByte(UINT8 TxData);//SPI3总线读写一个字节

		 
#endif

