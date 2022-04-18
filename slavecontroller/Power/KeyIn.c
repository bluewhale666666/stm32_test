/**
  ******************************************************************************
  * @file    KeyIn.c
  * @author  Xi Liang/Liu Gui Qing
  * @brief   Power Command module driver.
  *         
  @verbatim
  ******************************************************************************
  */
	
#include "KeyIn.h"




POWER_MANAGE_PACKED power_manage;




uint32_t POWERON_KEYIN_TIMER = 0u;
uint8_t POWERON_KEYIN_STATE = 0u;
void PowerOnKeyInState(void)
{
	uint32_t now = 0u;
	static uint32_t elapse = 0u;
	
	switch(POWERON_KEYIN_STATE)
	{
		case 0u: 
			if(HAL_GPIO_ReadPin(POWERON_KEYIN_GPIO_Port,POWERON_KEYIN_Pin) == GPIO_PIN_RESET)
			{
				POWERON_KEYIN_STATE = 1u;
				POWERON_KEYIN_TIMER = HAL_GetTick();
			}
			break;
		case 1u:
			if(HAL_GPIO_ReadPin(POWERON_KEYIN_GPIO_Port,POWERON_KEYIN_Pin) == GPIO_PIN_RESET)
			{
				now = HAL_GetTick();
		  	elapse = now - POWERON_KEYIN_TIMER;
				POWERON_KEYIN_STATE = 2u;
			}
			else
			{
			  POWERON_KEYIN_STATE = 0u;
			}
			break;
		case 2u:
			if(elapse >= 1000u)
			{
			  POWERON_KEYIN_STATE = 3u;
			}
			else
			{
			  POWERON_KEYIN_STATE = 1u;
			}
			break;
		case 3u:
		  if(HAL_GPIO_ReadPin(POWERON_KEYIN_GPIO_Port,POWERON_KEYIN_Pin) == GPIO_PIN_SET)
			{
				power_manage.work_mode = POWER_STATUS_POWERON;
				POWERON_KEYIN_STATE = 0u;
			}
			else
			{
			  POWERON_KEYIN_STATE = 2u;
			}
			break;	
		default:
			break;
	}
}

uint32_t POWERONREMOTE_KEYIN_TIMER = 0u;
uint8_t POWERONREMOTE_KEYIN_STATE = 0u;
void PowerOnRemoteKeyInState(void)
{
	uint32_t now = 0u;
	static uint32_t elapse = 0u;
	
	switch(POWERONREMOTE_KEYIN_STATE)
	{
		case 0u: 
			if(HAL_GPIO_ReadPin(POWERON_REMOTEIN_GPIO_Port,POWERON_REMOTEIN_Pin) == GPIO_PIN_RESET)
			{
				POWERONREMOTE_KEYIN_STATE = 1u;
				POWERONREMOTE_KEYIN_TIMER = HAL_GetTick();
			}
			break;
		case 1u:
			if(HAL_GPIO_ReadPin(POWERON_REMOTEIN_GPIO_Port,POWERON_REMOTEIN_Pin) == GPIO_PIN_RESET)
			{
				now = HAL_GetTick();
		  	elapse = now - POWERONREMOTE_KEYIN_TIMER;
				POWERONREMOTE_KEYIN_STATE = 2u;
			}
			else
			{
			  POWERONREMOTE_KEYIN_STATE = 0u;
			}
			break;
		case 2u:
			if(elapse >= 1000u)
			{
			  POWERONREMOTE_KEYIN_STATE = 3u;
			}
			else
			{
			  POWERONREMOTE_KEYIN_STATE = 1u;
			}
			break;
		case 3u:
		  if(HAL_GPIO_ReadPin(POWERON_REMOTEIN_GPIO_Port,POWERON_REMOTEIN_Pin) == GPIO_PIN_SET)
			{
				power_manage.work_mode = POWER_STATUS_POWERON;
				POWERONREMOTE_KEYIN_STATE = 0u;
			}
			else
			{
			  POWERONREMOTE_KEYIN_STATE = 2u;
			}
			break;	
		default:
			break;
	}
}

uint32_t POWEROFF_KEYIN_TIMER = 0u;
uint8_t POWEROFF_KEYIN_STATE = 0u;
void PowerOffKeyInState(void)
{
	uint32_t now = 0u;
	static uint32_t elapse = 0u;	
	
	switch(POWEROFF_KEYIN_STATE)
	{
		case 0u: 
			if(HAL_GPIO_ReadPin(POWERON_KEYIN_GPIO_Port,POWERON_KEYIN_Pin) == GPIO_PIN_RESET)
			{
				POWEROFF_KEYIN_STATE = 1u;
				POWEROFF_KEYIN_TIMER = HAL_GetTick();
			}
			break;
		case 1u:
			if(HAL_GPIO_ReadPin(POWERON_KEYIN_GPIO_Port,POWERON_KEYIN_Pin) == GPIO_PIN_RESET)
			{
				now = HAL_GetTick();
		  	elapse = now - POWEROFF_KEYIN_TIMER;
				POWEROFF_KEYIN_STATE = 2u;
			}
			else
			{
			  POWEROFF_KEYIN_STATE = 0u;
			}
			break;
		case 2u:
			if(elapse >= 3000u)
			{
			  POWEROFF_KEYIN_STATE = 3u;
			}
			else
			{
			  POWEROFF_KEYIN_STATE = 1u;
			}
			break;
		case 3u:
		  if(HAL_GPIO_ReadPin(POWERON_KEYIN_GPIO_Port,POWERON_KEYIN_Pin) == GPIO_PIN_SET)
			{
				power_manage.work_mode = POWER_STATUS_SHUTDWON;
				POWEROFF_KEYIN_STATE = 0u;
			}
			else
			{
			  POWEROFF_KEYIN_STATE = 2u;
			}
			break;	
		default:
			break;
	}
}

uint32_t POWEROFFREMOTE_KEYIN_TIMER = 0u;
uint8_t POWEROFFREMOTE_KEYIN_STATE = 0u;
void PowerOffREMOTEKeyInState(void)
{
	uint32_t now = 0u;
	static uint32_t elapse = 0u;	
	
	switch(POWEROFFREMOTE_KEYIN_STATE)
	{
		case 0u: 
			if(HAL_GPIO_ReadPin(POWEROFF_REMOTEIN_GPIO_Port,POWEROFF_REMOTEIN_Pin) == GPIO_PIN_RESET)
			{
				POWEROFFREMOTE_KEYIN_STATE = 1u;
				POWEROFFREMOTE_KEYIN_TIMER = HAL_GetTick();
			}
			break;
		case 1u:
			if(HAL_GPIO_ReadPin(POWEROFF_REMOTEIN_GPIO_Port,POWEROFF_REMOTEIN_Pin) == GPIO_PIN_RESET)
			{
				now = HAL_GetTick();
		  	elapse = now - POWEROFFREMOTE_KEYIN_TIMER;
				POWEROFFREMOTE_KEYIN_STATE = 2u;
			}
			else
			{
			  POWEROFFREMOTE_KEYIN_STATE = 0u;
			}
			break;
		case 2u:
			if(elapse >= 3000u)
			{
			  POWEROFFREMOTE_KEYIN_STATE = 3u;
			}
			else
			{
			  POWEROFFREMOTE_KEYIN_STATE = 1u;
			}
			break;
		case 3u:
		  if(HAL_GPIO_ReadPin(POWEROFF_REMOTEIN_GPIO_Port,POWEROFF_REMOTEIN_Pin) == GPIO_PIN_SET)
			{
				power_manage.work_mode = POWER_STATUS_SHUTDWON;
				POWEROFFREMOTE_KEYIN_STATE = 0u;
			}
			else
			{
			  POWEROFFREMOTE_KEYIN_STATE = 2u;
			}
			break;	
		default:
			break;
	}
}

uint8_t ACPowerOK_TEST_FLAG = 0;
void ACPowerOKInState(void)
{
	uint32_t ACPowerOKnowTime;
	uint32_t ACPowerOKelapseTime;
	static uint8_t ACPowerOKState = 0u;
	static uint32_t ACPowerOKTime = 0u;
	
	switch(ACPowerOKState)
	{
		case 0u:
		//	if(ACPowerOK_TEST_FLAG == 1)
			if(HAL_GPIO_ReadPin(ACPower_OK_GPIO_Port,ACPower_OK_Pin) == GPIO_PIN_SET)
			{
				ACPowerOKTime = HAL_GetTick();
				ACPowerOKState = 1u;
			}
			break;
		case 1u:
		//	if(ACPowerOK_TEST_FLAG == 1)
			if(HAL_GPIO_ReadPin(ACPower_OK_GPIO_Port,ACPower_OK_Pin) == GPIO_PIN_SET)
			{
				ACPowerOKnowTime = HAL_GetTick();
	  	  ACPowerOKelapseTime = ACPowerOKnowTime - ACPowerOKTime;
		    if(ACPowerOKelapseTime >= 100)
			  {
			    power_manage.work_mode = POWER_STATUS_SHUTDWON;
					ACPowerOKState = 0u;
			  }
			}
	  	break;
		default:
			break;
	}
}
	
	

void KeyScan(uint8_t mode)
{
  /*OK–≈∫≈Œ¥º”*/
	switch(mode)
	{
		case POWER_STATUS_IDLE:
			 PowerOnKeyInState();
       PowerOnRemoteKeyInState();
		   break;
		case POWER_STATUS_48VNOSTART: 
		case POWER_STATUS_48VSTART:
			 PowerOffKeyInState();
		   PowerOffREMOTEKeyInState();
		   ACPowerOKInState();
			break;
		default:
			break;
	}
}
	
	

