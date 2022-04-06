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
						HAL_GPIO_WritePin(OC_PROTECT_GPIO_Port, OC_PROTECT_Pin, GPIO_PIN_SET);
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

void work_mode_operation(void)
{
	switch(power_manage.work_mode)
	{
		case POWER_STATUS_IDLE:
			sampling_flag = 1u;
		  break;
		case POWER_STATUS_POWERON:
			sampling_flag = 1u;
		  first_open_dr_save_state();
		  power_manage.p_state_h.STATE_DEFINE_H.SYSTEM_RUN = 1u;
	    power_manage.work_mode = POWER_STATUS_48VNOSTART;
		  break;
		case POWER_STATUS_48VNOSTART:
			Power_Command_Main_Loop();
			break;
		case POWER_STATUS_48VSTART:
			Power_Command_Main_Loop();
			break;
		case POWER_STATUS_SHUTDWON:
			force_shutdown(POWER_STATUS_IDLE);
	    break;

		default:
			break;	
	}
}

