/**
  ******************************************************************************
  * @file    PowerMenu.h
  * @author  Xi Liang/Liu Gui Qing
  * @brief   Power Menu Driver.
  *         
  @verbatim
  ******************************************************************************
  */
	
#ifndef __POWERMENU_H
#define __POWERMENU_H


#include "data_def.h"
#include "main.h"
#include "ADS1115Driver.h"
#include "Command.h"




void close_all_dr_save_state(void);
void first_open_dr_save_state(void);
void Reload_State_All_Value(void);
void Reload_Config_All_Value(void);
void work_mode_operation(void);
static void PowerOnCharge(void);
void force_shutdown(uint8_t nxt_mode);
void softwarepoweroff_mode_operation(void);
void shutdown_mode_operation(void);



#endif
