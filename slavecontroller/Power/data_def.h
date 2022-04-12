/**
  ******************************************************************************
  * @file    data_def.h
  * @author  Xi Liang/Liu Gui Qing
  * @brief   Data define.
  *         
  @verbatim
  ******************************************************************************
  */
	
#ifndef __DATA_DEF_H
#define __DATA_DEF_H

#include <stdint.h>



typedef union 
{
  struct
	{
		uint8_t SYSTEM_RUN        :1;		//ϵͳ����
		uint8_t DC48_OC           :1;		//48V��������
		uint8_t DC24V1_FK_OUT     :1;   //24V�������
		uint8_t MCON_FK_IN        :1;   //���ط����ź�����
		uint8_t BIT4B             :4;
	}STATE_DEFINE_H;
	uint8_t VAL;
}STATE_INFORMATION_H;

typedef union 
{
  struct
	{
		uint8_t DC48V_REM 	      :1;   //48v remote
		uint8_t DC24V1A  		      :1; 	//24v1a���������
		uint8_t DC24V1B  		      :1; 	//24v1b�������վMCU
		uint8_t DC24V1C  		      :1; 	//24v1c�������ȫMCU
		uint8_t DC24V2A  		      :1; 	//24v2a�������վIO
		uint8_t DC24V2B  		      :1; 	//24v2b�������ȫIO
		uint8_t FAN_RUN  	        :1; 	//��������
		uint8_t DC48V_ES_SHUTDOWN :1;   //48V�쳣MOS
	}STATE_DEFINE_L;
	uint8_t VAL;
}STATE_INFORMATION_L;

typedef union			
{
	struct 
	{
		uint8_t DC24V2_OV		      :1; 	//24v2��ѹ
		uint8_t DC24V2A_OC	      :1; 	//24v2A����
		uint8_t DC24V2B_OC	      :1; 	//24v2B����
		uint8_t MCON_FKIN		      :1; 	//���ط�������
		uint8_t RES_OVERHAET	 		:1; 	//Ԥ���������
		uint8_t BIT3B				      :3; 	
	}FAULT_DEFINE_H;
	uint8_t VAL;
}FAULT_INFORMATION_H;

typedef union			
{
	struct 
	{
		uint8_t TEMP_H	 		      :1; 	//�¶ȹ���
		uint8_t DC48V_UV		      :1; 	//48vǷѹ
		uint8_t DC48V_OV	       	:1; 	//48v��ѹ
		uint8_t DC48V_OC		      :1; 	//48v����
		uint8_t DC24V1_UV	      	:1; 	//24v1Ƿѹ
		uint8_t DC24V1_OV		      :1; 	//24v1��ѹ
		uint8_t DC24V1_OC		      :1; 	//24v1����
		uint8_t DC24V2_UV		      :1; 	//24v2Ƿѹ
	}FAULT_DEFINE_L;
	uint8_t VAL;
}FAULT_INFORMATION_L;

typedef struct 
{
	uint16_t upload_time;  
	uint8_t  work_mode;
	
	uint8_t temperature;
	uint16_t dc48v_u;
	uint16_t dc48v_i;
	uint16_t dc24v_u;
	uint16_t dc24v_i;
	
	uint16_t ai1_u;
	uint16_t ai1_i;
	uint16_t ai2_u;
	uint16_t ai2_i;
	
	uint8_t AI_SW1;
	uint8_t AI_SW2;
	
	STATE_INFORMATION_H p_state_h;
	STATE_INFORMATION_L p_state_l;
	FAULT_INFORMATION_H p_breakdown_h;
	FAULT_INFORMATION_L p_breakdown_l;
}POWER_MANAGE_PACKED;
extern POWER_MANAGE_PACKED power_manage;

typedef enum
{
	POWER_STATUS_IDLE = 0x00u,
	POWER_STATUS_POWERON,
	POWER_STATUS_48VNOSTART,
	POWER_STATUS_48VSTART,
	POWER_STATUS_SHUTDWON,
	POWER_STATUS_SOFTWAREPOWEROFF,
	POWER_STATUS_FAULT,
}POWER_STATUS_TYPE;

#endif

