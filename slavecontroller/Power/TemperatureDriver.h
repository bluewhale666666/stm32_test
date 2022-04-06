#ifndef __TEMPERATUREDRIVER_H
#define __TEMPERATUREDRIVER_H



#include "stm32f4xx_hal.h"
#include "data_def.h"


uint8_t look_up_table(uint16_t *a,uint8_t ArrayLong,uint16_t data);
float num_to_temperature(uint8_t num);
void save_ntc_data(uint16_t data);			//Ö±²å
void save_ntc2_data(uint16_t data);		//smd



#endif
