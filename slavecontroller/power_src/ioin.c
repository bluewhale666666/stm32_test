/**
   ******************************
   *file    ioin.c 
   *author  liu
   *version V1.0.0
   *date    2021/11/18
   *brief   key detect
   ******************************  
   */
	 

#include "ioin.h"



/** 
   *@brief   key detect
   *@param   mode: work mode       
   *@note    This function is called every 10ms;
						 power on: 1s; power off: 3s;
						 remote on: 1s; remote off: 3s;
						 Standby status check Power on, Work status Check Power-off;
   *@return  None
   *@author  liu
   *@date    2021/11/18      
   *@version V0.0.1
   */
void keyscan(uint8_t mode)
{
	static vu16 key1_cnt=0; /* power on and power off multiplex */
	static vu16 key2_cnt=0,key3_cnt=0; /*key2_cnt: remote power on; key3_cnt: remote power off */
	
	switch(mode)				
	{
		case 0:	 /* Standby mode*/
			if(0 == POWKEY_STA)  /* Press the power on button */
			{
				key1_cnt++;			
				if(key1_cnt > 500)	
					key1_cnt = 500;
			}
			else
			{
				if(key1_cnt>KEY_SHORT_VALUE)  /* Press finish */
				{
					/* Enter start up mode */
					power_manage.work_mode = 1;
				}				
				key1_cnt = 0;			
			}
			
			if(0 == REMOTEON_STA)	 /* Press remote power on button */
			{
				key2_cnt++;				
				if(key2_cnt > 500)	
					key2_cnt = 500;
			}
			else
			{
				if(key2_cnt  >KEY_SHORT_VALUE)  /* Press finish */
				{
					/* Enter start up mode */
					power_manage.work_mode = 1;				
				}				
				key2_cnt = 0;
			}
			break;
		case 2:		/* Working status, robot power is not started */	
		case 3:		/* Working status, robot power is start */	
			if(0 == POWKEY_STA)	 /* Press the power off button */
			{
				key1_cnt++;			
				if(key1_cnt > 500)	
					key1_cnt = 500;
			}
			else
			{
				if(key1_cnt > KEY_LONG_VALUE)	 /* Press finish */
				{
					/* Enter force shutdown mode */
					power_manage.work_mode = 6;		
				}				
				key1_cnt=0;			
			}
			
			if(0 == REMOTEOFF_STA)	/* Press remote power off button */
			{
				key3_cnt++;
				if(key3_cnt > 500)	
					key3_cnt = 500;
			}
			else
			{
				if(key3_cnt > KEY_LONG_VALUE)  /* Press finish */
				{
					/* Save the current working mode */
					last_workmode = power_manage.work_mode;
					/* Enter ask shutdown mode */
					power_manage.work_mode =  4;	
					send_code3_flag = 1;	/* Trigger ask shutdown command */			
				}				
				key3_cnt=0;			
			}
			break;			
		case 5:	/* Wait for shutdown confirmation,force shutdown is supported */		
		  if(0 == POWKEY_STA)	 /* Press the power off button */
			{
				key1_cnt++;
				if(key1_cnt > 500)	
					key1_cnt = 500;
			}
			else
			{
				if(key1_cnt > KEY_LONG_VALUE)		/* Press finish */
				{
					/* Enter force shutdown mode */
					power_manage.work_mode = 6;		
				}				
				key1_cnt = 0;			
			}
			break;				
		default:
			break;
	}				
}




/***************END OF FILE***********************************************/
