/**
  ******************************************************************************
  * @file    Command.c
  * @author  Xi Liang/Liu Gui Qing
  * @brief   Power Command module driver.
  *         
  @verbatim
  ******************************************************************************
  */
#include "Command.h"
#include "ADS1115Driver.h"
#include "applInterface.h"
#include "Crc16.h"

#define PERIODIC_TRANSMISSTION_LENGTH 16u
#define REPLY_CONTROL_COMMAND_LENGTH 2u
#define POWER_OFF_REQUIRE_LENGTH 1u
#define REPLY_POWER_OFF_COMMAND_LENGTH 1u
#define REPLY_REBOOT_COMMAND_LENGTH 1u
#define COMPULSORY_POWER_OFF_COMMAND_LENGTH 1u

uint8_t PowerCommandRxBuffer[POWER_COMMAND_TXRX_BUFFER_SIZE];
uint8_t PowerCommandTxBuffer[POWER_COMMAND_TXRX_BUFFER_SIZE];

UART_HandleTypeDef * Uart_HandlePtr;
DMA_HandleTypeDef * Udma_UartRx_HandlePtr;
DMA_HandleTypeDef * Udma_Uarttx_HandlePtr;

static uint32_t PeriodicTransmissionTime = 0u;
static BOOL PeriodicTransmissionTimeout = FALSE;
static uint16_t PwrCmdTxSize = 0u;

static void SM2SU_Req_Call_Periodic_Transmission(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Reply_Control_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Power_Off_Require(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Reply_Power_Off_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Reply_Reboot_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Compulsory_Power_Off_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Encapsulation_Func(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
const static SM2SU_REQ_DPCH strPwrCmdTxReqMap[SM2SU_REQ_MAX]=
{
	{
		SM2SU_REQ_CD_PERIODIC_TRANSMISSION, 
		SM2SU_Req_Call_Periodic_Transmission, 
		PERIODIC_TRANSMISSTION_LENGTH
	},
	
	{
		SM2SU_REQ_CD_REPLY_CONTROL_COMMAND, 
		SM2SU_Req_Call_Reply_Control_Command, 
		REPLY_CONTROL_COMMAND_LENGTH
	},
	
	{
		SM2SU_REQ_CD_POWER_OFF_REQUIRE, 
		SM2SU_Req_Call_Power_Off_Require,
		POWER_OFF_REQUIRE_LENGTH
	},
	
	{
		SM2SU_REQ_CD_REPLY_POWER_OFF_COMMAND, 
		SM2SU_Req_Call_Reply_Power_Off_Command, 
		REPLY_POWER_OFF_COMMAND_LENGTH
	},
	
	{
		SM2SU_REQ_CD_REPLY_REBOOT_COMMAND,
		SM2SU_Req_Call_Reply_Reboot_Command,
		REPLY_REBOOT_COMMAND_LENGTH
	},
	
	{
		SM2SU_REQ_CD_COMPULSORY_POWER_OFF_COMMAND, 
		SM2SU_Req_Call_Compulsory_Power_Off_Command, 
		COMPULSORY_POWER_OFF_COMMAND_LENGTH
	},
};

void Power_Command_Initilization(void)
{

}

HAL_StatusTypeDef Power_Command_Transmit(uint8_t ReqCode)
{
	HAL_StatusTypeDef ans = HAL_ERROR;
	uint32_t i;
	
	for(i=0u; i<(uint32_t)SM2SU_REQ_MAX;i++){
		if(ReqCode == strPwrCmdTxReqMap[i].SM2SU_REQ_CD){
			strPwrCmdTxReqMap[i].pFunc(ReqCode,PowerCommandTxBuffer, &PwrCmdTxSize, strPwrCmdTxReqMap[i].InfoLength);
			ans = HAL_UART_Transmit(Uart_HandlePtr, PowerCommandTxBuffer, PwrCmdTxSize, (uint32_t)POWER_COMMAND_TRANSMIT_TIMEOUT_IN_MS);
			break;
		}
	}
	return(ans);
}

void Power_Command_Main_Loop(void)
{
	uint32_t nowTime;
	uint32_t elapseTime;
	HAL_StatusTypeDef TransmitResult;
	
	nowTime = HAL_GetTick();
	elapseTime = nowTime - PeriodicTransmissionTime;
	if (elapseTime >= SM2SU_PERIODIC_TRANSMIT_IN_MS)
	{
		TransmitResult = Power_Command_Transmit((uint8_t)SM2SU_REQ_CD_PERIODIC_TRANSMISSION);
		if(TransmitResult == HAL_OK)
		{
			PeriodicTransmissionTime = HAL_GetTick();
		}
	}
	else if(elapseTime >= SM2SU_PERIODIC_TRANSMIT_TIMEOUT_IN_MS)
	{
		PeriodicTransmissionTimeout = TRUE;
	}
	else
	{
		//no statement
	}
}

static void SM2SU_Req_Call_Encapsulation_Func(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength)
{
		uint16_t crc16;
	
		*(pSize) = (POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_END_SIZE + \
																	POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
																	InfoLength + POWER_COMMAND_CRC_SIZE);
		//SOI
		pData[0u] = 0xFFu;
		pData[1u] = 0xAAu;
		pData[2u] = 0xAAu;
		pData[3u] = 0xFFu;
		//CMD
		pData[POWER_COMMAND_HEADER_SIZE] = ReqCd;
		//LENGTH
		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE] = InfoLength;

		//INFO
		//updated in corresponding function
	
		//CCITT-CRC16
		crc16 = CRC16_CCITT(pData, (POWER_COMMAND_HEADER_SIZE + \
																POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
																InfoLength));
		pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength] = (uint8_t)(crc16 & 0xff); 	
		pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + 1u] = (uint8_t)((crc16 >> 8)& 0xff);
	
		//EOI
		pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + POWER_COMMAND_CRC_SIZE] = 0xEEu;
		pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + POWER_COMMAND_CRC_SIZE + 1u] = 0x55u;
		pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + POWER_COMMAND_CRC_SIZE + 2u] = 0x55u;
		pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + POWER_COMMAND_CRC_SIZE + 3u] = 0xEEu;
}


static void SM2SU_Req_Call_Periodic_Transmission(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength)
{
	if(ReqCd != SM2SU_REQ_CD_PERIODIC_TRANSMISSION)
	{
		*(pData) = NULL;
		*(pSize) = 0u;
	}
	else
	{
		//TODO
		//INFO
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = ;
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 1u] = ;
		
		SM2SU_Req_Call_Encapsulation_Func(ReqCd, pData, pSize, InfoLength);
	}
}

static void SM2SU_Req_Call_Reply_Control_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength)
{
	if(ReqCd != SM2SU_REQ_CD_REPLY_CONTROL_COMMAND)
	{
		*(pData) = NULL;
		*(pSize) = 0u;
	}
	else
	{
		//TODO
		//INFO
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = ;
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 1u] = ;
		
		SM2SU_Req_Call_Encapsulation_Func(ReqCd, pData, pSize, InfoLength);
	}
}

static void SM2SU_Req_Call_Power_Off_Require(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength)
{
	if(ReqCd != SM2SU_REQ_CD_POWER_OFF_REQUIRE)
	{
		*(pData) = NULL;
		*(pSize) = 0u;
	}
	else
	{
		//TODO
		//INFO
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = ;
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 1u] = ;
		
		SM2SU_Req_Call_Encapsulation_Func(ReqCd, pData, pSize, InfoLength);
	}
}

static void SM2SU_Req_Call_Reply_Power_Off_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength)
{
	if(ReqCd != SM2SU_REQ_CD_REPLY_POWER_OFF_COMMAND)
	{
		*(pData) = NULL;
		*(pSize) = 0u;
	}
	else
	{
		//TODO
		//INFO
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = ;
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 1u] = ;
		
		SM2SU_Req_Call_Encapsulation_Func(ReqCd, pData, pSize, InfoLength);
	}
}

static void SM2SU_Req_Call_Reply_Reboot_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength)
{
	if(ReqCd != SM2SU_REQ_CD_REPLY_REBOOT_COMMAND)
	{
		*(pData) = NULL;
		*(pSize) = 0u;
	}
	else
	{
		//TODO
		//INFO
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = ;
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 1u] = ;
		
		SM2SU_Req_Call_Encapsulation_Func(ReqCd, pData, pSize, InfoLength);
	}
}

static void SM2SU_Req_Call_Compulsory_Power_Off_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength)
{
	if(ReqCd != SM2SU_REQ_CD_COMPULSORY_POWER_OFF_COMMAND)
	{
		*(pData) = NULL;
		*(pSize) = 0u;
	}
	else
	{
		//TODO
		//INFO
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = ;
		//pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 1u] = ;
		
		SM2SU_Req_Call_Encapsulation_Func(ReqCd, pData, pSize, InfoLength);
	}
}
