/**
  ******************************************************************************
  * @file    ADS1115Driver.h
  * @author  Xi Liang
  * @brief   ADS1115 I2C module driver.
  *         
  @verbatim
  ******************************************************************************
  */
#ifndef __ADS1115DRIVER_H
#define __ADS1115DRIVER_H


#include "stm32f4xx_hal.h"
#include "data_def.h"
#include "TemperatureDriver.h"


#define ADS1115_Voltage_48V

#define ADS1115_I2C_TIMEOUT_IN_MS 500u

//Warning! 7 bits ADDR should must be shifted to the left
//ADDR PIN ->GND
/*1001000y*/
#define ADS1115_ADDR_0  (72u << 1)

//ADDR PIN ->VDD
/*1001001y*/
#define ADS1115_ADDR_1  (73u << 1)

//ADDR PIN ->SDA
/*1001010Y*/
#define ADS1115_ADDR_2  (74u << 1)

//ADDR PIN ->SCL
/*1001011Y*/
#define ADS1115_ADDR_3  (75u << 1)

#define ADS1115_CONVERSION_REG      0x00	//Convertion register
#define ADS1115_CONFIG_REG          0x01	//Config register
#define ADS1115_Lo_THRESH_REG       0x02	//Lo_thresh register
#define ADS1115_Ho_THRESH_REG       0x03	//Hi_thresh register

#define ADS1115_CONFIG_REG_OS_NO_EFFECT 0u
#define ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION ((uint16_t)1u << 15u)

#define ADS1115_CONFIG_REG_MUX_AIN0_AIN1 0u
#define ADS1115_CONFIG_REG_MUX_AIN0_AIN3 ((uint16_t)1u << 12u)
#define ADS1115_CONFIG_REG_MUX_AIN1_AIN3 ((uint16_t)2u << 12u)
#define ADS1115_CONFIG_REG_MUX_AIN2_AIN3 ((uint16_t)3u << 12u)
#define ADS1115_CONFIG_REG_MUX_AIN0_GND ((uint16_t)4u << 12u)
#define ADS1115_CONFIG_REG_MUX_AIN1_GND ((uint16_t)5u << 12u)
#define ADS1115_CONFIG_REG_MUX_AIN2_GND ((uint16_t)6u << 12u)
#define ADS1115_CONFIG_REG_MUX_AIN3_GND ((uint16_t)7u << 12u)

#define ADS1115_CONFIG_REG_FSR_6p114	(0u)
#define ADS1115_CONFIG_REG_FSR_4p096	((uint16_t)1u << 9u)
#define ADS1115_CONFIG_REG_FSR_2p048	((uint16_t)2u << 9u)
#define ADS1115_CONFIG_REG_FSR_1p024	((uint16_t)3u << 9u)
#define ADS1115_CONFIG_REG_FSR_0p512	((uint16_t)4u << 9u)
#define ADS1115_CONFIG_REG_FSR_0p256_1	((uint16_t)5u << 9u)
#define ADS1115_CONFIG_REG_FSR_0p256_2	((uint16_t)6u << 9u)
#define ADS1115_CONFIG_REG_FSR_0p256_3	((uint16_t)7u << 9u)

#define ADS1115_CONFIG_REG_MODE_CONTINUOUS	(0u)
#define ADS1115_CONFIG_REG_MODE_SINGLE_SHOT	((uint16_t)(1u) << 8u)

#define ADS1115_CONFIG_REG_DR_SPS_8	(0u)
#define ADS1115_CONFIG_REG_DR_SPS_16	((uint16_t)1u << 5u)
#define ADS1115_CONFIG_REG_DR_SPS_32	((uint16_t)2u << 5u)
#define ADS1115_CONFIG_REG_DR_SPS_64	((uint16_t)3u << 5u)
#define ADS1115_CONFIG_REG_DR_SPS_128	((uint16_t)4u << 5u)
#define ADS1115_CONFIG_REG_DR_SPS_250	((uint16_t)5u << 5u)
#define ADS1115_CONFIG_REG_DR_SPS_475	((uint16_t)6u << 5u)
#define ADS1115_CONFIG_REG_DR_SPS_860	((uint16_t)7u << 5u)

#define ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL 0u
#define ADS1115_CONFIG_REG_COMP_MODE_WINDOW ((uint16_t)(1) << 4u)

#define ADS1115_CONFIG_REG_COMP_POL_ACT_LOW (0u)
#define ADS1115_CONFIG_REG_COMP_POL_ACT_HIGH ((uint16_t)(1) << 3u)

#define ADS1115_CONFIG_REG_COMP_QUE_ONE 0u
#define ADS1115_CONFIG_REG_COMP_QUE_TWO (1u)
#define ADS1115_CONFIG_REG_COMP_QUE_FOUR (2u)
#define ADS1115_CONFIG_REG_COMP_QUE_DISABLE (3u)


#define ADC_Accuracy 		32768   //定义ADC精度，ADS1115单端输入时15位

extern I2C_HandleTypeDef * I2C_Ptr_48V_NTC;
extern I2C_HandleTypeDef * I2C_Ptr_24V;
extern I2C_HandleTypeDef * I2C_Ptr_AI;

typedef union
{
	struct 
	{
		uint16_t COMP_QUE 		:2;
		uint16_t COMP_LAT 		:1;
		uint16_t COMP_POL 		:1;
		uint16_t COMP_MODE  	:1;
		uint16_t DR         	:3;
		uint16_t MODE     		:1;
		uint16_t PGA        	:3;
		uint16_t MUX        	:3;
		uint16_t OS         	:1;
	}BIT;
	uint16_t ALL;
}ADS1115_CFG;

typedef struct tag_ADS1115_DRIVER
{
	I2C_HandleTypeDef * I2C_Handle;
	uint8_t ADDR;
	ADS1115_CFG ConfigRegData;
	int16_t SampleValue;
	uint32_t *StartConversionTimerPtr;
	uint32_t ConversionTime;
	uint32_t ConfigErrorCnt;
	uint32_t ConversionErrorCnt;
	int16_t SampleValueMax;
	int16_t SampleValueMin;
	uint8_t SampleBuffer[2u];
	HAL_StatusTypeDef ConfigResult;
	HAL_StatusTypeDef ConversionTransmitResult;
	HAL_StatusTypeDef ConversionReceiveResult;	
}ADS1115_DRIVER;

extern ADS1115_DRIVER ADS1115_NTC;
extern ADS1115_DRIVER ADS1115_Voltage48V;
extern ADS1115_DRIVER ADS1115_Current48V;
extern ADS1115_DRIVER ADS1115_Voltage24V;
extern ADS1115_DRIVER ADS1115_Current24V;
extern ADS1115_DRIVER ADS1115_AnalogVoltageInput0;
extern ADS1115_DRIVER ADS1115_AnalogVoltageInput1;
extern ADS1115_DRIVER ADS1115_AnalogCurrentInput0;
extern ADS1115_DRIVER ADS1115_AnalogCurrentInput1;
void ADS1115_Driver_Initilization(void);
void ADS1115_Driver_MainLoop(void);

#endif
