#ifndef __MENU_H
#define __MENU_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


#define TAG_OV_TEMP  (1 << 0)
#define TAG_OV_DC48V (1 << 1)
#define TAG_UV_DC48V (1 << 2)
#define TAG_OC_DC48V (1 << 3)
#define TAG_OV_DC24V (1 << 4)
#define TAG_UV_DC24V (1 << 5)
#define TAG_OC_DC24V (1 << 6)

/* function define  -------------------------------------*/
void save_control_state_to_dr(uint8_t pdata);
void first_open_dr_save_state(void);
void close_all_dr_save_state(void);

//void standby_mode(void);
//void power_on_mode(void);
//void main_work1_mode(void);
//void main_work2_mode(void);

//void adc_fast_get_data(void);
//void adc_slow_get_data(void);

void adc_get_data(void);
void mode_adc_get_data(u8 speed);

void normal_power_off_mode(void);
void power_off_mode(void);
void fault_mode(void);
unsigned int Alarm_Manage(void);
void force_shutdown(uint8_t nxt_mode);

void in_io_scan(void);

void print_2(uint8_t val2);		//以2进制打印出来

#endif /* __MENU_H*/

/************************END OF FILE****/
