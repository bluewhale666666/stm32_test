/*
 * PDIDriver.h
 *
 *  Created on: 2021Äê10ÔÂ8ÈÕ
 *      Author: siasun
 */

#ifndef COMMON_INCLUDE_PDIDRIVER_H_
#define COMMON_INCLUDE_PDIDRIVER_H_

#include "stm32f4xx_hal.h"
#include "ecat_def.h"
#include "9252_HW.h"
extern uint8_t PDI_Isr_enable;

void PDI_Enable_Global_interrupt(void);
void PDI_IRQ_Interrupt(void);
void PDI_Init_SYNC_Interrupts(void);
void PDI_Timer_Interrupt(void);
#endif /* COMMON_INCLUDE_PDIDRIVER_H_ */
