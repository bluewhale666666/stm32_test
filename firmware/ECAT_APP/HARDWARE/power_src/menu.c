#include "menu.h"

#include "main.h"							//主函数头文件
#include "sys.h"							//主函数头文件

#include "gpio.h"
#include "ads1115a.h"
#include "ads1115b.h"
#include "ads1115c.h"

#include "ds18b20.h"



extern u8 last_duty;

//控制各路输出（除了控制主控和示教器），打开/关闭
//0-----x-----x------x 			 x------x-----x-----x
//		风扇	24V2B		24V2A		24v1C	24v1B	24v1A	 48v

void save_control_state_to_dr(uint8_t pdata)
{
	power_manage.p_constate.val = pdata;	
	
	if(power_manage.p_constate.b.AI_SW1 == 0)//模拟量输入1电流电压切换
	{
	  AI_IU_SW1 = 1;
	}
	else
	{
	  AI_IU_SW1 = 0;
	}
	
	if(power_manage.p_constate.b.AI_SW2== 0)//模拟量输入2电流电压切换
	{
	  AI_IU_SW2 = 1;
	}
	else
	{
	  AI_IU_SW2 = 0;
	}
	
	DC24V2A_DR = power_manage.p_constate.b.DC24V2A;			//24V2A 安全IO,从站IO

//	DC48V_RE_DR = power_manage.p_constate.b.DC48V_REM;	//48V开关电源
//	DC24V1A_DR = power_manage.p_constate.b.DC24V1A;			//24V1A 主控制器，示教器  
//	DC24V1B_DR = power_manage.p_constate.b.DC24V1B;			//24V1B 从站MCU
//	DC24V1C_DR = power_manage.p_constate.b.DC24V1C;			//24V1C 安全MCU
//	DC24V2A_DR = power_manage.p_constate.b.DC24V2A;			//24V2A 安全IO,从站IO
//	DC24V2B_DR = power_manage.p_constate.b.DC24V2B;			//24V2B 外设
//	FAN_DR = power_manage.p_constate.b.FAN_RUN;					//风扇
//	
//	DC24V_FK_DR = power_manage.p_constate.b.DC24V1A;		//24V反馈输出
//	power_manage.p_state.b.DC24V1_FK=power_manage.p_constate.b.DC24V1A;		//24v反馈输出状态
}


/** 
   *@brief   close all output
   *@note    DC24V1A_DR: teaching device, main control, fan, safety controller MCU, 48V remote multi
					   DC24V2A_DR: 24V IO
						 DC24V_FK_DR: 24V power indicator
						 DC48V_ES_SHUTDOWN_DR:  error shutdown
   *@param   none
   *@return  none
   *@author  liu  
   *@date    2021/11/15    
   *@version V1.0.0
   */
void close_all_dr_save_state(void)
{
	power_manage.p_constate.val = 0x00;
	power_manage.p_state.val = 0x00;
	
	DC24V1A_DR = 0;		
	DC24V2A_DR = 0;			
	DC48V_ES_SHUTDOWN_DR = 1;  
	DC24V_FK_DR = 0;		
}

//上电按键后的动作，打开所有输出
void first_open_dr_save_state(void)
{
  power_manage.p_constate.val = 0x7f;
	power_manage.p_state.val = 0x04; 
	
	DC24V1A_DR = 1;		//示教器、主控、FAN、安全控制器的24V，与48V remote复用
	DC24V2A_DR = 1;		//24V2A 安全IO,从站IO
	DC24V_FK_DR = 1;	//示教器指示灯
}

//轮询读取ADC采样芯片的数据,v0.2版本和V0.1版本的ads1115c  AD接口有区别！！！！！！！！！！！！！！！！！
uint16_t test_i_value = 0;
void adc_get_data(void)
{
	static vu8 ch1=0;
	static u16 utmp=0;
	float ftmp;
	
	switch(ch1)	
	{
		/* 48v ads1115c */
		case 0:
		{
			ftmp = ADS1115c_Switch_Channl(0);				//48v电压 x100
			ftmp = 409.6*31.5*ftmp/(1.5*ADC_Accuracy);

			if((ftmp<6000)&&(ftmp>200))	
				power_manage.dc48v_u = ftmp;
			else
				power_manage.dc48v_u = 0;	

			ch1++;
			break;
		}
		case 1:
		{
			utmp = ADS1115c_Switch_Channl(1);	//ntc2		
			save_ntc2_data(utmp);			
			
			ch1++;
			break;
		}
		case 2:
		{
			ftmp = ADS1115c_Switch_Channl(2);	//48v 电流  x100
			ftmp = 409.6*ftmp/(0.05*ADC_Accuracy);	

			if((ftmp<10000)&&(ftmp>5))	
			{
				power_manage.dc48v_i = ftmp;
				test_i_value =  ftmp;
			}				
			else
			{
				power_manage.dc48v_i = 0;
				test_i_value = 0;
			}

			ch1++;		
			break;
		}
		/* 24v ads1115a */
		case 3:
		{
			ftmp = ADS1115a_Switch_Channl(0);			//24v电压
			ftmp = 409.6*8.5*ftmp/ADC_Accuracy;	
			
			if((ftmp<3200)&&(ftmp>100))	
				power_manage.dc24v1_u = ftmp;
			else
				power_manage.dc24v1_u = 0;	
			
			ch1++;
			break;
		}
		case 4:
		{
			ftmp = ADS1115a_Switch_Channl(1);			//24v电流
			ftmp = 409.6*ftmp/(0.5*ADC_Accuracy);	
			
		  if(ftmp>500)	
				power_manage.dc24v1_i=0;
			else					
				power_manage.dc24v1_i = ftmp;

			ch1++;
			break;	
		}
		case 5:					
		{
			ftmp = ADS1115a_Switch_Channl(3);			//ntc			
			save_ntc_data(ftmp);

			ch1++;
			break;	
		}
		
		/* ads1115b AI */
		case 6:
		{
			if(power_manage.p_constate.b.AI_SW1 == 1)
			{
				AI_IU_SW1 = 0;
				ftmp = ADS1115b_Switch_Analog1Voltage();	//AI_IU_SW1电压
				ftmp = 409.6*2.8*ftmp/ADC_Accuracy;			
				power_manage.dc24v2_u = ftmp;				
			}
			else
			{
				power_manage.dc24v2_u = 0;
			}
		
			ch1++;
			break;
		}
		case 7:
		{
			if(power_manage.p_constate.b.AI_SW2 == 1)
			{
				AI_IU_SW2 = 0;
				ftmp = ADS1115b_Switch_Analog2Voltage();	//AI_IU_SW2电压
				ftmp = 409.6*2.8*ftmp/ADC_Accuracy;		
				power_manage.dc24v2_ul = ftmp;				
			}
			else
			{
		  	power_manage.dc24v2_ul = 0;
			}
			
			ch1++;
			break;
		}
		case 8:
		{
			if(power_manage.p_constate.b.AI_SW2 == 0)
			{			
				AI_IU_SW2 = 1;
				ftmp = ADS1115b_Switch_Analog2Current();			//AI_IU_SW2电流
				ftmp = 409.6*ftmp/(0.16*ADC_Accuracy);					
				power_manage.dc24v2_i2 = ftmp;
			}
			else
			{
		  	power_manage.dc24v2_i2 = 0;
			}
				
      ch1++;
			break;
		}
		case 9:
		{
			if(power_manage.p_constate.b.AI_SW1 == 0)
			{			
		    AI_IU_SW1 = 1;				
				ftmp = ADS1115b_Switch_Analog1Current();			//AI_IU_SW1电流
				ftmp = 409.6*ftmp/(0.16*ADC_Accuracy);						
				power_manage.dc24v2_i1 = ftmp;
			}
			else
			{
		  	power_manage.dc24v2_i1 = 0;
			}
				
			ch1=0;		
			adcok_flag = 1;	
			break;
		}
		default:
			break;	
	}
}	
	
//报警管理
unsigned int Alarm_Manage(void)
{
	unsigned int nRet = 0;
	static u8 ov_temp_times = 0, ov_dc48v_times = 0, uv_dc48v_times = 0, oc_dc48v_times = 0;
	static u8 ov_dc24v_times = 0, uv_dc24v_times, oc_dc24v_times = 0;
		
	//温度高
	if(power_manage.temperature_ntc2 > power_manage.temperature_h)	//
	{
		ov_temp_times++;
		if(ov_temp_times > power_manage.alarm_cfc)
		{
			power_manage.p_breakdownl.b.TEMP_H = 1;
			nRet |= TAG_OV_TEMP;
		}
	}
	else
	{
		ov_temp_times = 0;
		power_manage.p_breakdownl.b.TEMP_H = 0;	
	}
	
	//48v欠压		过流防护打开了才开始判断欠压
	if((power_manage.dc48v_u<power_manage.dc48v_ul)&&(1==power_manage.p_state.b.DC48V_OC))	
	{
		uv_dc48v_times++;
		if(uv_dc48v_times > power_manage.alarm_cfc)
		{
			nRet |= TAG_UV_DC48V;
			power_manage.p_breakdownl.b.DC48V_UV = 1;
		}
	}
	else
	{
		uv_dc48v_times = 0;
		power_manage.p_breakdownl.b.DC48V_UV = 0;	
	}
	
	//48v过压
	if(power_manage.dc48v_u>power_manage.dc48v_uh)	
	{
		ov_dc48v_times++;
		if(ov_dc48v_times > power_manage.alarm_cfc)
		{
			power_manage.p_breakdownl.b.DC48V_OV = 1;
			nRet |= TAG_OV_DC48V;
		}
	}
	else
	{
		ov_dc48v_times = 0;
		power_manage.p_breakdownl.b.DC48V_OV = 0;	
	}
	
	//48v过流
	if(power_manage.dc48v_i>power_manage.dc48v_ih)	
	{
		oc_dc48v_times++;
		if(oc_dc48v_times > power_manage.alarm_cfc)
		{
			power_manage.p_breakdownl.b.DC48V_OC = 1;
			nRet |= TAG_OC_DC48V;
		}
	}
	else
	{
		oc_dc48v_times = 0;
		power_manage.p_breakdownl.b.DC48V_OC = 0;	
	}
	
	//24V1欠压				欠压判断需要优化
	if(power_manage.dc24v1_u<power_manage.dc24v1_ul)	
	{
		uv_dc24v_times++;
		if(uv_dc24v_times > power_manage.alarm_cfc)
		{
			power_manage.p_breakdownl.b.DC24V1_UV = 1;
			nRet |= TAG_UV_DC24V;
		}
	}
	else
	{
		uv_dc24v_times = 0;
		power_manage.p_breakdownl.b.DC24V1_UV = 0;	
	}
	
	//24V1过压
	if(power_manage.dc24v1_u>power_manage.dc24v1_uh)	
	{
		ov_dc24v_times++;
		if(ov_dc24v_times > power_manage.alarm_cfc)
		{
			power_manage.p_breakdownl.b.DC24V1_OV = 1;
			nRet |= TAG_OV_DC24V;
		}
	}
	else
	{
		ov_dc24v_times = 0;
		power_manage.p_breakdownl.b.DC24V1_OV = 0;	
	}
	
	//24V1过流
	if(power_manage.dc24v1_i>power_manage.dc24v1_ih)	
	{
		oc_dc24v_times++;
		if(oc_dc24v_times > power_manage.alarm_cfc)
		{
			power_manage.p_breakdownl.b.DC24V1_OC = 1;
			nRet |= TAG_OC_DC24V;
		}
	}
	else
	{
		oc_dc24v_times = 0;
		power_manage.p_breakdownl.b.DC24V1_OC = 0;	
	}
	return nRet;
}


void force_shutdown(uint8_t nxt_mode)
{
	close_all_dr_save_state();			////关闭所有
	delay_ms(10);
			
	OCPROTECT_DR = 0;								//过流防护输出
	power_manage.p_state.b.DC48V_OC=0;				
	power_manage.p_state.b.SYSTEM_RUN = 0;	
			
	power_manage.work_mode = nxt_mode;			
}

////打印2进制	
//void print_2(uint8_t val2)
//{
//	u8 i;
//	
//	char uu[9];
//	
//	for (i=0; i<8; i++)
//	{
//		if(val2 & 0x80)
//			uu[i]='1';
//		else
//			uu[i]='0';
//		val2 = val2<<1;
//	}
//	uu[8] = 0;
//	printf("%s \r\n", uu);
//}



/***************END OF FILE***********************************************/
