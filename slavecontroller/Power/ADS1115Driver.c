/**
  ******************************************************************************
  * @file    ADS1115Driver.c
  * @author  Xi Liang
  * @brief   ADS1115 I2C module driver.
  *         
  @verbatim
  ******************************************************************************
  */
#include "ADS1115Driver.h"

I2C_HandleTypeDef * I2C_Ptr_48V_NTC;
I2C_HandleTypeDef * I2C_Ptr_24V;
I2C_HandleTypeDef * I2C_Ptr_AI;

static uint32_t ADCStartConversionTimer1 = 0u;
static uint32_t ADCStartConversionTimer2 = 0u;
static uint32_t ADCStartConversionTimer3 = 0u;

const uint32_t ADS1115ConversionTimeTable[8u] =
{
		250u,			//SPS_8	(1/8 = 125ms)
		128u,			//SPS_16	(1/16 = 62.5ms)
		64u,			//SPS_32	(1/32 = 31.25ms)
		32u,			//SPS_64	(1/64 = 15.625ms)
		16u,			//SPS_128	(1/128 = 7.8125ms)
		8u,				//SPS_250	(1/250 = 4ms)
		6u,				//SPS_475	(1/475 = 2.105ms)
		4u,				//SPS_860	(1/860 = 1.16ms)
};

static uint8_t ADS1115_ChipA_Driver_Cnt = 0u;
#define ADS1115_ChipA_Driver_Number 2u
static ADS1115_DRIVER * ADS1115_ChipA_DriverPtr[ADS1115_ChipA_Driver_Number] =
{
		&ADS1115_Voltage24V,
		&ADS1115_Current24V,
};

static uint8_t ADS1115_ChipB_Driver_Cnt = 0u;
#define ADS1115_ChipB_Driver_Number 4u
static  ADS1115_DRIVER * ADS1115_ChipB_DriverPtr[ADS1115_ChipB_Driver_Number] = 
{
		&ADS1115_AnalogVoltageInput0,
		&ADS1115_AnalogVoltageInput1,	
		&ADS1115_AnalogCurrentInput1,
		&ADS1115_AnalogCurrentInput0,	
};

static uint8_t ADS1115_ChipC_Driver_Cnt = 0u;
#define ADS1115_ChipC_Driver_Number 3u
static ADS1115_DRIVER * ADS1115_ChipC_DriverPtr[ADS1115_ChipC_Driver_Number] = 
{
		&ADS1115_Voltage48V,
		&ADS1115_Current48V,
		&ADS1115_NTC,	
};

ADS1115_DRIVER ADS1115_AnalogVoltageInput0 =
{
		.ADDR = ADS1115_ADDR_1,
		.SampleValue = 0,
		 //AIN0-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN0_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE, 
		.StartConversionTimerPtr = &ADCStartConversionTimer2,
		.ConversionTime = 250u,
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};

ADS1115_DRIVER ADS1115_AnalogVoltageInput1 =
{
		.ADDR = ADS1115_ADDR_1,
		.SampleValue = 0,
		 //AIN1-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN1_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE,
		.StartConversionTimerPtr = &ADCStartConversionTimer2,	
		.ConversionTime = 250u,
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};

ADS1115_DRIVER ADS1115_AnalogCurrentInput0 =
{
		.ADDR = ADS1115_ADDR_1,
		.SampleValue = 0,
		 //AIN3-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN3_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE,	
		.StartConversionTimerPtr = &ADCStartConversionTimer2,
		.ConversionTime = 250u,	
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};

ADS1115_DRIVER ADS1115_AnalogCurrentInput1 =
{
		.ADDR = ADS1115_ADDR_1,
		.SampleValue = 0,
		 //AIN2-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN2_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE,
		.StartConversionTimerPtr = &ADCStartConversionTimer2,	
		.ConversionTime = 250u,	
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};

ADS1115_DRIVER ADS1115_Voltage48V =
{
		.ADDR = ADS1115_ADDR_0,
		.SampleValue = 0,
		//AIN0-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN0_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE,
		.StartConversionTimerPtr = &ADCStartConversionTimer3,
		.ConversionTime = 250u,	
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};

ADS1115_DRIVER ADS1115_Current48V =
{
		.ADDR = ADS1115_ADDR_0,
		.SampleValue = 0,
		//AIN2-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN2_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE,
		.StartConversionTimerPtr = &ADCStartConversionTimer3,
		.ConversionTime = 250u,	
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};

ADS1115_DRIVER ADS1115_NTC =
{
		.ADDR = ADS1115_ADDR_0,
		.SampleValue = 0,
		//AIN1-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN1_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE,
		.StartConversionTimerPtr = &ADCStartConversionTimer3,
		.ConversionTime = 250u,	
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};



ADS1115_DRIVER ADS1115_Voltage24V =
{
		.ADDR = ADS1115_ADDR_0,
		.SampleValue = 0,
		//AIN0-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN0_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE,
		.StartConversionTimerPtr = &ADCStartConversionTimer1,
		.ConversionTime = 250u,	
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};

ADS1115_DRIVER ADS1115_Current24V =
{
		.ADDR = ADS1115_ADDR_0,
		.SampleValue = 0,
		//AIN1-GND
		.ConfigRegData.ALL = ADS1115_CONFIG_REG_OS_START_SINGLE_CONVERSION | \
											ADS1115_CONFIG_REG_MUX_AIN1_GND | \
											ADS1115_CONFIG_REG_FSR_4p096 | \
											ADS1115_CONFIG_REG_MODE_CONTINUOUS | \
											ADS1115_CONFIG_REG_DR_SPS_860 | \
											ADS1115_CONFIG_REG_COMP_MODE_TRANDITIONAL | \
											ADS1115_CONFIG_REG_COMP_POL_ACT_LOW | \
											ADS1115_CONFIG_REG_COMP_QUE_DISABLE,
		.StartConversionTimerPtr = &ADCStartConversionTimer1,
		.ConversionTime = 250u,	
		.ConfigErrorCnt = 0u,
		.ConversionErrorCnt = 0u,
		.SampleValueMax = -0x7FFF,
		.SampleValueMin = 0x7FFF,
};

static void ADS1115_Read_Sample(ADS1115_DRIVER * strpADC);
static void ADS1115_Config(ADS1115_DRIVER * strpADC);

static void ADS1115_Read_Sample(ADS1115_DRIVER * strpADC)
{
	uint8_t Data;
	
	if(strpADC->ConfigResult == HAL_OK)
	{
		Data = ADS1115_CONVERSION_REG;
		strpADC->ConversionTransmitResult = HAL_I2C_Master_Transmit(strpADC->I2C_Handle, strpADC->ADDR, &Data, 1u, ADS1115_I2C_TIMEOUT_IN_MS);
		strpADC->ConversionReceiveResult = HAL_I2C_Master_Receive(strpADC->I2C_Handle, strpADC->ADDR, strpADC->SampleBuffer, 2u, ADS1115_I2C_TIMEOUT_IN_MS);
		if ((strpADC->ConversionTransmitResult != HAL_OK) || (strpADC->ConversionReceiveResult != HAL_OK))
		{
			strpADC->ConversionErrorCnt++;
			if(strpADC->ConversionErrorCnt >= 0xffffffffu)
			{
				strpADC->ConversionErrorCnt = 0xffffffffu;
			}
		}
		else
		{
			strpADC->SampleValue = (((int16_t)strpADC->SampleBuffer[0u])<< 8u) | (strpADC->SampleBuffer[1u]);
			if(strpADC->SampleValue > strpADC->SampleValueMax)
			{
				strpADC->SampleValueMax = strpADC->SampleValue;
			}
			else if(strpADC->SampleValue < strpADC->SampleValueMin)
			{
				strpADC->SampleValueMin = strpADC->SampleValue;
			}
			else
			{
				//no statement
			}
		}
	}
	else
	{
		strpADC->ConversionTransmitResult = HAL_ERROR;
		strpADC->ConversionReceiveResult = HAL_ERROR;		
		strpADC->ConversionErrorCnt++;
		if(strpADC->ConversionErrorCnt >= 0xffffffffu)
		{
			strpADC->ConversionErrorCnt = 0xffffffffu;
		}
	}
}

static void ADS1115_Config(ADS1115_DRIVER * strpADC)
{
	uint8_t Data[3u];
	Data[0u] = ADS1115_CONFIG_REG;
	Data[1u] = (uint8_t)((strpADC->ConfigRegData.ALL) >> 8u);
	Data[2u] = (uint8_t)((strpADC->ConfigRegData.ALL) & 0x00FFu);
	strpADC->ConfigResult = HAL_I2C_Master_Transmit(strpADC->I2C_Handle, strpADC->ADDR, Data, 3u, ADS1115_I2C_TIMEOUT_IN_MS);
	if(strpADC->ConfigResult == HAL_OK)
	{
		*(strpADC->StartConversionTimerPtr) = HAL_GetTick();
	}
	else
	{
		strpADC->ConfigErrorCnt++;
		if(strpADC->ConfigErrorCnt >= 0xffffffffu)
		{
			strpADC->ConfigErrorCnt = 0xffffffffu;
		}
	}
}

void ADS1115_Driver_Initilization(void)
{
	ADS1115_AnalogCurrentInput0.I2C_Handle = I2C_Ptr_AI;
	ADS1115_AnalogCurrentInput0.ConversionTime = ADS1115ConversionTimeTable[ADS1115_AnalogCurrentInput0.ConfigRegData.BIT.DR];
	ADS1115_AnalogCurrentInput1.I2C_Handle = I2C_Ptr_AI;
	ADS1115_AnalogCurrentInput1.ConversionTime = ADS1115ConversionTimeTable[ADS1115_AnalogCurrentInput1.ConfigRegData.BIT.DR];
	ADS1115_AnalogVoltageInput0.I2C_Handle = I2C_Ptr_AI;
	ADS1115_AnalogVoltageInput0.ConversionTime = ADS1115ConversionTimeTable[ADS1115_AnalogVoltageInput0.ConfigRegData.BIT.DR];
	ADS1115_AnalogVoltageInput1.I2C_Handle = I2C_Ptr_AI;
	ADS1115_AnalogVoltageInput1.ConversionTime = ADS1115ConversionTimeTable[ADS1115_AnalogVoltageInput1.ConfigRegData.BIT.DR];
	ADS1115_NTC.I2C_Handle = I2C_Ptr_48V_NTC;
	ADS1115_NTC.ConversionTime = ADS1115ConversionTimeTable[ADS1115_NTC.ConfigRegData.BIT.DR];
	ADS1115_Voltage48V.I2C_Handle = I2C_Ptr_48V_NTC;
	ADS1115_Voltage48V.ConversionTime = ADS1115ConversionTimeTable[ADS1115_Voltage48V.ConfigRegData.BIT.DR];
	ADS1115_Current48V.I2C_Handle = I2C_Ptr_48V_NTC;
	ADS1115_Current48V.ConversionTime = ADS1115ConversionTimeTable[ADS1115_Current48V.ConfigRegData.BIT.DR];
	ADS1115_Voltage24V.I2C_Handle = I2C_Ptr_24V;
	ADS1115_Voltage24V.ConversionTime = ADS1115ConversionTimeTable[ADS1115_Voltage24V.ConfigRegData.BIT.DR];
	ADS1115_Current24V.I2C_Handle = I2C_Ptr_24V;
	ADS1115_Current24V.ConversionTime = ADS1115ConversionTimeTable[ADS1115_Current24V.ConfigRegData.BIT.DR];
	ADS1115_Config(ADS1115_ChipA_DriverPtr[ADS1115_ChipA_Driver_Cnt]);
	ADS1115_Config(ADS1115_ChipB_DriverPtr[ADS1115_ChipB_Driver_Cnt]);
	ADS1115_Config(ADS1115_ChipC_DriverPtr[ADS1115_ChipC_Driver_Cnt]);
}

void ADS1115_Driver_MainLoop(void)
{
	ADS1115_DRIVER * strpADC;
	uint32_t nowTime;
	uint32_t elapseTime;
	
	nowTime = HAL_GetTick();
	
	strpADC = ADS1115_ChipA_DriverPtr[ADS1115_ChipA_Driver_Cnt];
	elapseTime = nowTime - (*(strpADC->StartConversionTimerPtr));
	if (elapseTime >= strpADC->ConversionTime)
	{
			ADS1115_Read_Sample(strpADC);
		  ADS1115_ChipA_Driver_Cnt++;
		
		  if(ADS1115_ChipA_Driver_Cnt == 1u)
			{
				power_manage.dc24v_u = 409.6*8.5*strpADC->SampleValue/ADC_Accuracy;
			}
			else if(ADS1115_ChipA_Driver_Cnt == 2u)
			{
				power_manage.dc24v_i = 409.6*strpADC->SampleValue/(0.5*ADC_Accuracy);
			}
			
			if(ADS1115_ChipA_Driver_Cnt >= (uint8_t)ADS1115_ChipA_Driver_Number)
			{
					ADS1115_ChipA_Driver_Cnt = 0u;
			}
			ADS1115_Config(ADS1115_ChipA_DriverPtr[ADS1115_ChipA_Driver_Cnt]);
	}
	
	nowTime = HAL_GetTick();
	strpADC = ADS1115_ChipB_DriverPtr[ADS1115_ChipB_Driver_Cnt];
	elapseTime = nowTime - (*(strpADC->StartConversionTimerPtr));
	if (elapseTime >= strpADC->ConversionTime)
	{
			ADS1115_Read_Sample(strpADC);
		  ADS1115_ChipB_Driver_Cnt++;
		
			if(ADS1115_ChipB_Driver_Cnt == 1u)
			{
				power_manage.ai1_u = 409.6*2.8*strpADC->SampleValue/ADC_Accuracy;	
			}
			else if(ADS1115_ChipB_Driver_Cnt == 2u)
			{
				power_manage.ai2_u = 409.6*2.8*strpADC->SampleValue/ADC_Accuracy;	
			}
			else if(ADS1115_ChipB_Driver_Cnt == 3u)
			{
				power_manage.ai2_i = 409.6*strpADC->SampleValue/(0.16*ADC_Accuracy);
			}
			else if(ADS1115_ChipB_Driver_Cnt == 4u)
			{
				power_manage.ai1_i = 409.6*strpADC->SampleValue/(0.16*ADC_Accuracy);
			}
		
			if(ADS1115_ChipB_Driver_Cnt >= (uint8_t)ADS1115_ChipB_Driver_Number)
			{
					ADS1115_ChipB_Driver_Cnt = 0u;
			}
			ADS1115_Config(ADS1115_ChipB_DriverPtr[ADS1115_ChipB_Driver_Cnt]);
	}
	
	nowTime = HAL_GetTick();
	strpADC = ADS1115_ChipC_DriverPtr[ADS1115_ChipC_Driver_Cnt];
	elapseTime = nowTime - (*(strpADC->StartConversionTimerPtr));
	if (elapseTime >= strpADC->ConversionTime)
	{
			ADS1115_Read_Sample(strpADC);
			ADS1115_ChipC_Driver_Cnt++;
		
			if(ADS1115_ChipC_Driver_Cnt == 1u)
			{
				power_manage.dc48v_u = 409.6*31.5*strpADC->SampleValue/(1.5*ADC_Accuracy);
			}
			else if(ADS1115_ChipC_Driver_Cnt == 2u)
			{
				save_ntc2_data(strpADC->SampleValue);
			}
			else if(ADS1115_ChipC_Driver_Cnt == 3u)
			{
				power_manage.dc48v_i = 409.6*strpADC->SampleValue/(0.05*ADC_Accuracy);
			}
			
			if(ADS1115_ChipC_Driver_Cnt >= (uint8_t)ADS1115_ChipC_Driver_Number)
			{
					ADS1115_ChipC_Driver_Cnt = 0u;
			}
			ADS1115_Config(ADS1115_ChipC_DriverPtr[ADS1115_ChipC_Driver_Cnt]);
	}
}