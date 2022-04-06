/**
   ******************************
   *file    di_key.c 
   *author  liu
   *version V1.0.0
   *date    2021/11/2
   *brief   DI init 
	          function/user DI init 
   ******************************  
   */
	 

#include "di_key.h"



/** 
   *@brief   DI Init
   *@note    8 channel DI
					   8 channel Function/User DI
   *@param   none
   *@return  none
   *@author  liu  
   *@date    2021/11/2    
   *@version V1.0.0
   */
void DI_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOG, ENABLE);
 
	/************************** DI ST_IN_1 ~ ST_IN_8 Init **************************/
	/* ST_IN_1: PG11;  ST_IN_2: PG12;  ST_IN_3: PG13; ST_IN_4: PG14;  ST_IN_5: PG10; ST_IN_6: PG9; */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOG, &GPIO_InitStructure);
	
	/* ST_IN_7: PD7;  ST_IN_8: PD6; */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	/******************Function/User DI ST_IN_17 ~ ST_IN_24 Init *******************/
	/* ST_IN_17: PG6;  ST_IN_18: PG7;  ST_IN_19: PG8; ST_IN_21: PG5;  ST_IN_22: PG3; ST_IN_23: PG2; */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOG, &GPIO_InitStructure);
	
	/* ST_IN_20: PC8; */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	/* ST_IN_24: PD15; */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}


/** 
   *@brief   Input filter
   *@note    the function is called multiple during init
   *@param   Input: input 
             FilterCounter: variable
             CounterMax:max counter 
						 CounterThreshold: threshold
						 InputLatch: latch value 
   *@return  ret
   *@author  liu  
   *@date    2021/11/1    
   *@version V1.0.0
   */
BOOL input_filter(const uint16_t Input, uint16_t * FilterCounter, const uint16_t CounterMax, const uint16_t CounterThreshold, BOOL * InputLatch)
{
    BOOL ret = FALSE;         /*Default D.O.*/
    BOOL input = (BOOL)Input;

    if(input == TRUE)
    {
        if ((*FilterCounter) >= (uint8_t)CounterMax)
        {
            (*FilterCounter) = (uint8_t)CounterMax;
        }
        else
        {
            (*FilterCounter)++;
        }
    }
    else
    {
        if ((*FilterCounter) <= (uint8_t)1u)
        {
            (*FilterCounter) = 0u;
        }
        else
        {
            (*FilterCounter) -- ;
        }
    }

    if ((*FilterCounter) <= CounterThreshold)
    {
        ret = FALSE;
    }
    else if((*FilterCounter) >= (uint16_t)(CounterMax - CounterThreshold))
    {
        ret = TRUE;
    }
    else
    {
        ret = (*InputLatch);
    }

    (*InputLatch) = ret;

    return ret;
}

/** 
   *@brief   DI Process Data
   *@note    8 channel DI process data processing
					   8 channel Function/User DI process data processing
   *@param   DI object dictionary
   *@return  none
   *@author  liu  
   *@date    2021/11/1    
   *@version V1.0.0
   */
uint16_t test_di[8]={0};
void DI_process_data(TOBJ6000 *IN_GENERIC)
{
	uint16_t a0=3,a1=3,a2=3,a3=3,a4=3,a5=3,a6=3,a7=3,a16=3,a17=3,a18=3,a19=3,a20=3,a21=3,a22=3,a23=3;
	BOOL b0=0,b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b16=0,b17=0,b18=0,b19=0,b20=0,b21=0,b22=0,b23=0;

	/* 8 channel DI, 取反才是合理的逻辑，这时接收到高电平就是1，低电平就是0 */
  IN_GENERIC->Digital_Inputs_channel1=~input_filter(ST_IN4_I0_0,(uint16_t *)&a0,6,2,(BOOL *)&b0);
	IN_GENERIC->Digital_Inputs_channel2=~input_filter(ST_IN3_I0_1,(uint16_t *)&a1,6,2,(BOOL *)&b1);
	IN_GENERIC->Digital_Inputs_channel3=~input_filter(ST_IN2_I0_2,(uint16_t *)&a2,6,2,(BOOL *)&b2);
	IN_GENERIC->Digital_Inputs_channel4=~input_filter(ST_IN1_I0_3,(uint16_t *)&a3,6,2,(BOOL *)&b3);
	IN_GENERIC->Digital_Inputs_channel5=~input_filter(ST_IN5_I1_0,(uint16_t *)&a4,6,2,(BOOL *)&b4);
	IN_GENERIC->Digital_Inputs_channel6=~input_filter(ST_IN6_I1_1,(uint16_t *)&a5,6,2,(BOOL *)&b5);
	IN_GENERIC->Digital_Inputs_channel7=~input_filter(ST_IN7_I1_2,(uint16_t *)&a6,6,2,(BOOL *)&b6);
	IN_GENERIC->Digital_Inputs_channel8=~input_filter(ST_IN8_I1_3,(uint16_t *)&a7,6,2,(BOOL *)&b7);
  
	/* 8 channel Function/User DI, 取反才是合理的逻辑，这时接收到高电平就是1，低电平就是0 */
	IN_GENERIC->Function_Digital_Inputs_Channel_1=~input_filter(ST_IN17_I2_0,(uint16_t *)&a16,6,2,(BOOL *)&b16);
	IN_GENERIC->Function_Digital_Inputs_Channel_2=~input_filter(ST_IN18_I2_1,(uint16_t *)&a17,6,2,(BOOL *)&b17);
	IN_GENERIC->Function_Digital_Inputs_Channel_3=~input_filter(ST_IN19_I2_2,(uint16_t *)&a18,6,2,(BOOL *)&b18);
	IN_GENERIC->Function_Digital_Inputs_Channel_4=~input_filter(ST_IN20_I2_3,(uint16_t *)&a19,6,2,(BOOL *)&b19);
	IN_GENERIC->Function_Digital_Inputs_Channel_8=~input_filter(ST_IN24_I3_0,(uint16_t *)&a23,6,2,(BOOL *)&b23);
	IN_GENERIC->Function_Digital_Inputs_Channel_7=~input_filter(ST_IN23_I3_1,(uint16_t *)&a22,6,2,(BOOL *)&b22);
	IN_GENERIC->Function_Digital_Inputs_Channel_6=~input_filter(ST_IN22_I3_2,(uint16_t *)&a21,6,2,(BOOL *)&b21);
	IN_GENERIC->Function_Digital_Inputs_Channel_5=~input_filter(ST_IN21_I3_3,(uint16_t *)&a20,6,2,(BOOL *)&b20);	
	
	test_di[0] = ST_IN17_I2_0;
	test_di[1] = ST_IN18_I2_1;
	test_di[2] = ST_IN19_I2_2;
	test_di[3] = ST_IN20_I2_3;
	test_di[4] = ST_IN21_I3_3;
	test_di[5] = ST_IN22_I3_2;
	test_di[6] = ST_IN23_I3_1;
	test_di[7] = ST_IN24_I3_0;
	
	/* INC CNT */
	IN_GENERIC->INC_AB_CNT = INC_GetIncABValue();
}

