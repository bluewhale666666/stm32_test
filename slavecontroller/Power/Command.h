/**
  ******************************************************************************
  * @file    Command.h
  * @author  Xi Liang/Liu Gui Qing
  * @brief   Power Command module driver.
  *         
  @verbatim
  ******************************************************************************
  */
	
#ifndef __COMMAND_H
#define __COMMAND_H


#include "stm32f4xx_hal.h"
#include "data_def.h"
#include "PowerMenu.h"

#define POWER_COMMAND_TXRX_BUFFER_SIZE 32u

#define POWER_COMMAND_HEADER_SIZE (4u)
#define POWER_COMMAND_END_SIZE (4u)
#define POWER_COMMAND_CMD_SIZE (1u)
#define POWER_COMMAND_LENGTH_SIZE (1u)
#define POWER_COMMAND_INFO_MAX_SIZE (16u)
#define POWER_COMMAND_CRC_SIZE (2u)
//#define POWER_COMMAND_DMA_SIZE (POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_END_SIZE + \
																	POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
																	POWER_COMMAND_INFO_MAX_SIZE + POWER_COMMAND_CRC_SIZE)
																	
#define POWER_COMMAND_MAX_SIZE (POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_END_SIZE + \
																	POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
																	POWER_COMMAND_INFO_MAX_SIZE + POWER_COMMAND_CRC_SIZE)

#define SOI 0xFFAAAAFFu
#define EOI 0xEE5555EEu

#define SM2SU_PERIODIC_TRANSMIT_IN_MS 500u
#define SM2SU_PERIODIC_TRANSMIT_TIMEOUT_IN_MS 1000u
#define POWER_COMMAND_TRANSMIT_TIMEOUT_IN_MS 500u

typedef struct tag_POWER_COMMAND_PROTOCOL
{
		uint8_t HEADER[POWER_COMMAND_HEADER_SIZE];
		uint8_t CMD;
		uint8_t LENGTH;
		uint8_t INFO[POWER_COMMAND_INFO_MAX_SIZE];	
		uint16_t CRC16;
		uint8_t END[POWER_COMMAND_END_SIZE];
}POWER_COMMAND_PROTOCOL;

typedef union 
{
		uint8_t ByteAccess[POWER_COMMAND_MAX_SIZE];
		uint16_t WordAccess[POWER_COMMAND_MAX_SIZE >> 1];
		uint32_t	LongAccess[POWER_COMMAND_MAX_SIZE >> 2];
		POWER_COMMAND_PROTOCOL  ContentDefAccess;
}POWER_COMMAND;

typedef struct tag_POWER_COMMAND_RECEIVED 
{
	uint8_t RequireCode;
	POWER_COMMAND PowerCommand;
	
	
}POWER_COMMAND_RECEIVED;

typedef void (*SM2SU_REQ_CALL)(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);

typedef struct	tag_SM2SU_REQ_DPCH{
	uint8_t	SM2SU_REQ_CD;
	SM2SU_REQ_CALL	pFunc;
	uint16_t InfoLength;
} SM2SU_REQ_DPCH;

typedef uint8_t (*SU2SM_REQ_CALL)(POWER_COMMAND_RECEIVED *pData);

typedef struct	tag_SU2SM_REQ_DPCH{
	uint8_t	SU2SM_REQ_CD;
	SU2SM_REQ_CALL	pFunc;
} SU2SM_REQ_DPCH;

//	SM->SU
//	require code used by Power_Command_Transmit()
#define SM2SU_REQ_CD_PERIODIC_TRANSMISSION 1u
#define SM2SU_REQ_CD_REPLY_CONTROL_COMMAND 2u
#define SM2SU_REQ_CD_POWER_OFF_REQUIRE 3u
#define SM2SU_REQ_CD_REPLY_POWER_OFF_COMMAND 4u
#define SM2SU_REQ_CD_REPLY_REBOOT_COMMAND 5u
#define SM2SU_REQ_CD_COMPULSORY_POWER_OFF_COMMAND 6u
#define SM2SU_REQ_MAX 6u

//	SU->SM
//	require code used by Power_Command_Receive()
#define SU2SM_REQ_CD_PERIODIC_TRANSMISSION_COMMAND 1u
#define SU2SM_REQ_CD_CONTROL_COMMAND 2u
#define SU2SM_REQ_CD_REPLY_POWER_OFF_REQUIRE 3u
#define SU2SM_REQ_CD_POWER_OFF_COMMAND 4u
#define SU2SM_REQ_CD_REBOOT_COMMAND 5u
#define SU2SM_REQ_CD_REPLY_COMPULSORY_POWER_OFF_COMMAND 6u
#define SU2SM_REQ_MAX 6u


extern POWER_COMMAND_RECEIVED PowerCommandReceived;
extern uint8_t PowerCommandRxBuffer[POWER_COMMAND_TXRX_BUFFER_SIZE];
extern uint8_t PowerCommandTxBuffer[POWER_COMMAND_TXRX_BUFFER_SIZE];

extern UART_HandleTypeDef * Uart_HandlePtr;
extern DMA_HandleTypeDef * Udma_UartRx_HandlePtr;
extern DMA_HandleTypeDef * Udma_Uarttx_HandlePtr;

HAL_StatusTypeDef Power_Command_Transmit(uint8_t ReqCode);
void Power_Command_Initilization(void);
void Power_Command_Main_Loop(void);
void SU2SM_RxIdleEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

#endif
