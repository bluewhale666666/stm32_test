#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
#include "ecat_def.h"



extern u32 TimeCNT_Isr;
extern u16 LED_slow_count;
extern u16 LED_single_count;
extern u16 LED_fast_count;



void EtherCAT_LED_Control(void);
void Res_Heat_Calculation(void);


void TIM2_Int_Init(u16 arr,u16 psc);
void TIM4_Int_Init(u16 arr,u16 psc);
void TIM_ENCODER_Configuration(void);
void ENCODER_Read(uint32_t *Dir, uint32_t *Cnt);
void TIM9_CH2_Cap_Init(void);

#endif
