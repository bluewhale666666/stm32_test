/**
  ******************************************************************************
  * @file    PowerMenu.h
  * @author  Xi Liang/Liu Gui Qing
  * @brief   Power Menu Driver.
  *         
  @verbatim
  ******************************************************************************
  */
	
#include "PowerMenu.h"


extern POWER_MANAGE_PACKED power_manage;
extern UART_HandleTypeDef huart1;

uint8_t sampling_flag = 1;  //默认电阻接入电路，需要检测热量



void close_all_dr_save_state(void)
{
	power_manage.p_state_h.VAL = 0x00u;
  power_manage.p_state_l.VAL = 0x00u;
	
		
	HAL_GPIO_WritePin(GPIOB, V24V_OUT1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOF, V24V_OUT4_Pin|POWER24V_ON_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOF, ES_SHUTDOWN_Pin, GPIO_PIN_SET);
}

void force_shutdown(uint8_t nxt_mode) 
{
  close_all_dr_save_state();
	
	HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_RESET);
	power_manage.p_state_h.STATE_DEFINE_H.DC48_OC = 0;
	power_manage.p_state_h.STATE_DEFINE_H.SYSTEM_RUN = 0;
	
	power_manage.work_mode = nxt_mode;
}

void first_open_dr_save_state(void)
{
	power_manage.p_state_h.VAL = 0x05u;
  power_manage.p_state_l.VAL = 0x7fu; 
	
	HAL_GPIO_WritePin(GPIOB, V24V_OUT1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOF, V24V_OUT4_Pin|POWER24V_ON_Pin, GPIO_PIN_SET);
}

void Reload_State_All_Value(void)
{	
	close_all_dr_save_state();
	power_manage.p_breakdown_h.VAL = 0x00u;
	power_manage.p_breakdown_l.VAL = 0x00u;
	HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_RESET);
	power_manage.work_mode = 0u;
}

void Reload_Config_All_Value(void)
{
	power_manage.upload_time = 500;
}

static uint32_t SAFE_48V_SWITCH_ON_TIMER = 0u;
static uint8_t SAFE_48V_SWITCH_ON_STATE = 0u;
static void PowerOnCharge(void)
{
		uint32_t now = 0u;
		uint32_t elapse = 0u;
		if(HAL_GPIO_ReadPin(SAFE_48V_SWITCH_GPIO_Port,SAFE_48V_SWITCH_Pin) == GPIO_PIN_SET)
		{
			SAFE_48V_SWITCH_ON_STATE = 0u;
		}
		
		switch(SAFE_48V_SWITCH_ON_STATE)
		{
			case 1u:
					HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_RESET);
					now = HAL_GetTick();
					elapse = now - SAFE_48V_SWITCH_ON_TIMER;
					if(elapse >= 1500u)
					{
						SAFE_48V_SWITCH_ON_STATE = 2u;
					}
				break;
			case 2u:
					HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_SET);
			    power_manage.work_mode = POWER_STATUS_48VSTART;
				break;
			case 0u:
			default:
					HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_RESET);
					if(HAL_GPIO_ReadPin(SAFE_48V_SWITCH_GPIO_Port,SAFE_48V_SWITCH_Pin) == GPIO_PIN_RESET)
					{
							SAFE_48V_SWITCH_ON_STATE = 1u;
							SAFE_48V_SWITCH_ON_TIMER = HAL_GetTick();
					}
				break;
		}
}

static uint32_t SAFE_48V_SWITCH_OFF_TIMER = 0u;
static uint8_t SAFE_48V_SWITCH_OFF_STATE = 0u;
static void PowerAccessCharge(void)
{
		uint32_t now = 0u;
		uint32_t elapse = 0u;
		if(HAL_GPIO_ReadPin(SAFE_48V_SWITCH_GPIO_Port,SAFE_48V_SWITCH_Pin) == GPIO_PIN_RESET)
		{
			SAFE_48V_SWITCH_OFF_STATE = 0u;
		}
		
		switch(SAFE_48V_SWITCH_OFF_STATE)
		{
			case 1u:
					HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_SET);
					now = HAL_GetTick();
					elapse = now - SAFE_48V_SWITCH_OFF_TIMER;
					if(elapse >= 100u)
					{
						SAFE_48V_SWITCH_OFF_STATE = 2u;
					}
				break;
			case 2u:
					HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_RESET);
			    power_manage.work_mode = POWER_STATUS_48VNOSTART;
				break;
			case 0u:
			default:
					HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_SET);
					if(HAL_GPIO_ReadPin(SAFE_48V_SWITCH_GPIO_Port,SAFE_48V_SWITCH_Pin) == GPIO_PIN_SET)
					{
							SAFE_48V_SWITCH_OFF_STATE = 1u;
							SAFE_48V_SWITCH_OFF_TIMER = HAL_GetTick();
					}
				break;
		}
}

void shutdown_mode_operation(void)
{
	HAL_StatusTypeDef TransmitResult;
	uint32_t ShutdownnowTime;
	uint32_t ShutdownelapseTime;
	static uint8_t ShutdownState = 0u;
	static uint32_t ShutdownTime = 0u;
	
	switch(ShutdownState)
	{
		case 0u:	
		  TransmitResult = Power_Command_Transmit((uint8_t)SM2SU_REQ_CD_POWER_OFF_REQUIRE);
	    if(TransmitResult == HAL_OK)
			{
				ShutdownTime = HAL_GetTick();
				ShutdownState = 1u;
			}
			break;
		case 1u:
			ShutdownnowTime = HAL_GetTick();
	    ShutdownelapseTime = ShutdownnowTime - ShutdownTime; 
		  if(ShutdownelapseTime >= 5000)
		  {
			  force_shutdown(POWER_STATUS_IDLE);
				ShutdownState = 0u;
		  }		
			break;
		default:
			break;		
	}
}

void softwarepoweroff_mode_operation(void)
{
	HAL_StatusTypeDef TransmitResult;
	uint32_t softwarepoweroffnowTime;
	uint32_t softwarepoweroffelapseTime;
	static uint8_t softwarepoweroffState = 0u;
	static uint32_t softwarepoweroffTime = 0u;
	
	switch(softwarepoweroffState)
	{
		case 0u:	
		  TransmitResult = Power_Command_Transmit((uint8_t)SM2SU_REQ_CD_REPLY_POWER_OFF_COMMAND);
	    if(TransmitResult == HAL_OK)
			{
				softwarepoweroffTime = HAL_GetTick();
				softwarepoweroffState = 1u;
			}
			break;
		case 1u:
			softwarepoweroffnowTime = HAL_GetTick();
	    softwarepoweroffelapseTime = softwarepoweroffnowTime - softwarepoweroffTime; 
		  if(softwarepoweroffelapseTime >= 5000)
		  {
			  force_shutdown(POWER_STATUS_IDLE);
				softwarepoweroffState = 0u;
		  }		
			break;
		default:
			break;		
	}
}

void Reboot_mode_operation(void)
{
	HAL_StatusTypeDef TransmitResult;
	uint32_t nowTime;
	uint32_t elapseTime;
	static uint8_t RebootState = 0u;
	static uint32_t RebootTime = 0u;

	
	switch(RebootState)
	{
		case 0u:	
		  TransmitResult = Power_Command_Transmit((uint8_t)SM2SU_REQ_CD_REPLY_REBOOT_COMMAND);
	    if(TransmitResult == HAL_OK)
			{
				RebootTime = HAL_GetTick();
				RebootState = 1u;
			}
			break;
		case 1u:
			nowTime = HAL_GetTick();
	    elapseTime = nowTime - RebootTime; 
		  if(elapseTime >= 5000)
		  {
			  force_shutdown(POWER_STATUS_IDLE);
				RebootState = 2u;
		  }		
			break;
		case 2u:
			HAL_Delay(1000);
		  power_manage.work_mode = POWER_STATUS_POWERON;
			Reboot_Flag = FALSE;
	    RebootState = 0u;
			break;
		default:
			break;		
	}
}

void work_mode_operation(void)
{
	
	if(power_manage.AI_SW1 == 1) /* 电压 */
	{
		HAL_GPIO_WritePin(AI_IU_SW1_GPIO_Port, AI_IU_SW1_Pin, GPIO_PIN_RESET);
	}
	else if(power_manage.AI_SW1 == 0) /* 电流 */
	{
	  HAL_GPIO_WritePin(AI_IU_SW1_GPIO_Port, AI_IU_SW1_Pin, GPIO_PIN_SET);
	}
	
	if(power_manage.AI_SW2 == 1)
	{
		HAL_GPIO_WritePin(AI_IU_SW2_GPIO_Port, AI_IU_SW2_Pin, GPIO_PIN_RESET);
	}
	else if(power_manage.AI_SW2 == 0)
	{
	  HAL_GPIO_WritePin(AI_IU_SW2_GPIO_Port, AI_IU_SW2_Pin, GPIO_PIN_SET);
	}
	

	switch(power_manage.work_mode)
	{
		case POWER_STATUS_IDLE:
			sampling_flag = 1u;
			if(Reboot_Flag == TRUE)
			{
				Reboot_mode_operation();			
			}
		  break;
		case POWER_STATUS_POWERON:
			sampling_flag = 1u;
		  first_open_dr_save_state();
		  power_manage.p_state_h.STATE_DEFINE_H.SYSTEM_RUN = 1u;
	    power_manage.work_mode = POWER_STATUS_48VNOSTART;
		  break;
		case POWER_STATUS_48VNOSTART:
		  PowerOnCharge();
			if(Reboot_Flag == TRUE)
			{
				Reboot_mode_operation();			
			}
			break;
		case POWER_STATUS_48VSTART:
		  PowerAccessCharge();
			if(Reboot_Flag == TRUE)
			{
				Reboot_mode_operation();			
			}
			break;
		case POWER_STATUS_SHUTDWON:
      shutdown_mode_operation();
	    break;
		case POWER_STATUS_SOFTWAREPOWEROFF:
      softwarepoweroff_mode_operation();
			break;
		default:
			break;	
	}
}

