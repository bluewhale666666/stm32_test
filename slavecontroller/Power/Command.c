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
POWER_COMMAND_RECEIVED PowerCommandReceived;

static uint32_t PeriodicTransmissionTime = 0u;
static BOOL PeriodicTransmissionTimeout = FALSE;
static uint16_t PwrCmdTxSize = 0u;
static BOOL Power_Command_Receive_Idle_Detected = FALSE;
static BOOL Power_Command_Receive_Buffer_Full =  FALSE;
static BOOL Power_Command_Receive_Length_Error_Detected = FALSE;		
static BOOL Power_Command_ReceiveToIdle_Restart_Error = FALSE;				
static void SM2SU_Req_Call_Periodic_Transmission(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Reply_Control_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Power_Off_Require(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Reply_Power_Off_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Reply_Reboot_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Compulsory_Power_Off_Command(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void SM2SU_Req_Call_Encapsulation_Func(uint8_t ReqCd, uint8_t *pData, uint16_t *pSize, uint16_t InfoLength);
static void Power_Command_Receive(uint8_t * pData, uint16_t Size);
static uint8_t SU2SM_Req_Call_Reply_Periodic_Transmission(POWER_COMMAND_RECEIVED *pData);
static uint8_t SU2SM_Req_Call_Control_Command(POWER_COMMAND_RECEIVED *pData);
static uint8_t SU2SM_Req_Call_Reply_Power_Off_Require(POWER_COMMAND_RECEIVED *pData);
static uint8_t SU2SM_Req_Call_Power_Off_Command(POWER_COMMAND_RECEIVED *pData);
static uint8_t SU2SM_Req_Call_Reboot_Command(POWER_COMMAND_RECEIVED *pData);
static uint8_t SU2SM_Req_Call_Reply_Compulsory_Power_Off_Command(POWER_COMMAND_RECEIVED *pData);

const static SU2SM_REQ_DPCH strPwrCmdRxReqMap[SU2SM_REQ_MAX]=
{
	{
		SU2SM_REQ_CD_PERIODIC_TRANSMISSION_COMMAND, 
		SU2SM_Req_Call_Reply_Periodic_Transmission, 
	},
	
	{
		SU2SM_REQ_CD_CONTROL_COMMAND, 
		SU2SM_Req_Call_Control_Command, 
	},
	
	{
		SU2SM_REQ_CD_REPLY_POWER_OFF_REQUIRE, 
		SU2SM_Req_Call_Reply_Power_Off_Require,
	},
	
	{
		SU2SM_REQ_CD_POWER_OFF_COMMAND, 
		SU2SM_Req_Call_Power_Off_Command, 
	},
	
	{
		SU2SM_REQ_CD_REBOOT_COMMAND,
		SU2SM_Req_Call_Reboot_Command,
	},
	
	{
		SU2SM_REQ_CD_REPLY_COMPULSORY_POWER_OFF_COMMAND, 
		SU2SM_Req_Call_Reply_Compulsory_Power_Off_Command, 
	},
};

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
  Uart_HandlePtr->RxEventCallback= SU2SM_RxIdleEventCallback;
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
	uint32_t i;
	
	for(i=0u; i<(uint32_t)SU2SM_REQ_MAX;i++){
		if(PowerCommandReceived.RequireCode == strPwrCmdRxReqMap[i].SU2SM_REQ_CD){
			if(strPwrCmdRxReqMap[i].pFunc(&PowerCommandReceived) != 0u)
			{
				memset((uint8_t *)&PowerCommandReceived,0u, sizeof(PowerCommandReceived));
			}
			break;
		}
	}
	
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

static void Power_Command_Receive(uint8_t * pData, uint16_t Size)
{
		BOOL CommandReceived = FALSE;
		uint16_t crc16;
		uint16_t InfoLength;

		if(Power_Command_Receive_Buffer_Full == TRUE)
		{
			CommandReceived = TRUE;
		}
		if(Power_Command_Receive_Idle_Detected == TRUE)
		{
			CommandReceived = TRUE;
			Power_Command_Receive_Idle_Detected = FALSE;
		}
		
		if (CommandReceived == TRUE)
		{
			if((pData[0u] != 0xFFu) || \
				(pData[1u] != 0xAAu) || \
				(pData[2u] != 0xAAu) || \
				(pData[3u] != 0xFFu))
			{
				return;
			}
			InfoLength = pData[5u];
			if(InfoLength > POWER_COMMAND_MAX_SIZE)
			{
				return;
			}
			//CCITT-CRC16
			crc16 = CRC16_CCITT(pData, (POWER_COMMAND_HEADER_SIZE + \
																POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
																InfoLength));
			if((pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength] != (uint8_t)(crc16 & 0xff)) 	|| \
					(pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + 1u] != (uint8_t)((crc16 >> 8)& 0xff)))		
			{
				return;
			}						
			switch(pData[4u])
			{
				case 0u:
					return;	
					break;
				case 1u:
					if(InfoLength != 0u)
					{
						return;
					}
					break;
				case 2u:
					if(InfoLength != 2u)
					{
						return;
					}
					break;
				case 3u:
				case 4u:
				case 5u:
				case 6u:
					if(InfoLength != 1u)
					{
						return;
					}
					break;					
				default:
					return;
					break;
			}
			//EOI
			if((pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + POWER_COMMAND_CRC_SIZE] != 0xEEu) || \
				(pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + POWER_COMMAND_CRC_SIZE + 1u] != 0x55u) || \
				(pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + POWER_COMMAND_CRC_SIZE + 2u] != 0x55u) || \
				(pData[POWER_COMMAND_HEADER_SIZE + \
					POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
					InfoLength + POWER_COMMAND_CRC_SIZE + 3u] != 0xEEu))
			{
				return;
			}
			PowerCommandReceived.RequireCode = pData[4u];
			memcpy(PowerCommandReceived.PowerCommand.ContentDefAccess.HEADER, pData, POWER_COMMAND_HEADER_SIZE + \
																																	POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE);
			PowerCommandReceived.PowerCommand.ContentDefAccess.CRC16 = crc16;
			memcpy(PowerCommandReceived.PowerCommand.ContentDefAccess.INFO, &pData[POWER_COMMAND_HEADER_SIZE + \
																																	POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE], InfoLength);
			memcpy(PowerCommandReceived.PowerCommand.ContentDefAccess.END, &pData[POWER_COMMAND_HEADER_SIZE + \
																																	POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + \
																																	InfoLength + POWER_COMMAND_CRC_SIZE],4u);
		}
}

static uint8_t SU2SM_Req_Call_Reply_Periodic_Transmission(POWER_COMMAND_RECEIVED *pData)
{
	//TODO
	return 1u;
}

static uint8_t SU2SM_Req_Call_Control_Command(POWER_COMMAND_RECEIVED *pData)
{
		//TODO
	return 1u;
}


static uint8_t SU2SM_Req_Call_Reply_Power_Off_Require(POWER_COMMAND_RECEIVED *pData)
{
		//TODO
		return 1u;
}


static uint8_t SU2SM_Req_Call_Power_Off_Command(POWER_COMMAND_RECEIVED *pData)
{
  	//TODO
	if((power_manage.work_mode == POWER_STATUS_48VNOSTART) || (power_manage.work_mode == POWER_STATUS_48VSTART))
	{
	  power_manage.work_mode = POWER_STATUS_SOFTWAREPOWEROFF;
	}
	 
		return 1u;
}


static uint8_t SU2SM_Req_Call_Reboot_Command(POWER_COMMAND_RECEIVED *pData)
{
		//TODO
		HAL_StatusTypeDef TransmitResult;
	
	  TransmitResult = Power_Command_Transmit((uint8_t)SM2SU_REQ_CD_REPLY_REBOOT_COMMAND);
		if(TransmitResult == HAL_OK)
		{
			HAL_Delay(5000);
			force_shutdown(POWER_STATUS_IDLE);
			HAL_Delay(1000);
			power_manage.work_mode = POWER_STATUS_POWERON;
		}
	
		return 1u;
}


static uint8_t SU2SM_Req_Call_Reply_Compulsory_Power_Off_Command(POWER_COMMAND_RECEIVED *pData)
{
		//TODO
		return 1u;
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
		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = power_manage.p_state_l.VAL;
		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 1u] = power_manage.p_state_h.VAL;
		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 2u] = power_manage.p_breakdown_l.VAL;
		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 3u] = power_manage.p_breakdown_h.VAL;
		
		SM2SU_Req_Call_Encapsulation_Func(ReqCd, pData, pSize, InfoLength);
	}
}

/* RC暂不需要该指令 */
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
//		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = ;
//		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE + 1u] = ;
		
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
		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = 0x01;
		
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
		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = 0x01;
		
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
		pData[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_CMD_SIZE + POWER_COMMAND_LENGTH_SIZE] = 0x01;
		
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

void SU2SM_RxIdleEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
		uint16_t i;
		uint16_t length;
    if (huart->RxXferCount == 0U)
    {
				//called in UART_Receive_IT()
				//Buffer Full
			Power_Command_Receive_Buffer_Full = TRUE;
		}
		else
		{
				//Called in HAL_UART_IRQHandler()
				//IDLE event detected
			Power_Command_Receive_Idle_Detected = TRUE;
		}
		if(Size > POWER_COMMAND_MAX_SIZE)
		{
			Power_Command_Receive_Length_Error_Detected = TRUE;
			length = POWER_COMMAND_MAX_SIZE;				
		}
		else
		{
			length = Size;
		}
		Power_Command_Receive(PowerCommandRxBuffer,length);
		memset(PowerCommandRxBuffer,0u, POWER_COMMAND_TXRX_BUFFER_SIZE);
		//reset Buffer Countern and Pointer 
		if (HAL_UARTEx_ReceiveToIdle_IT(huart, PowerCommandRxBuffer, POWER_COMMAND_TXRX_BUFFER_SIZE) != HAL_OK)
		{
				Power_Command_ReceiveToIdle_Restart_Error = TRUE;				
		}	
}
