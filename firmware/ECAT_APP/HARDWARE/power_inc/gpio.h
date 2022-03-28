/**
   ******************************
   *file    gpio.h 
   *author  liu
   *version V1.0.0
   *date    2021/11/15
   *brief   power related gpio init
   ******************************  
   */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H
#define __GPIO_H


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "sys.h"							

/* output interface definition */
#define DC24V1A_DR    PBout(9) 	//ʾ���������ء�FAN����ȫ��������24V����48V remote����
#define DC24V2A_DR    PFout(2) 	//IO��24V
#define AI_IU_SW1     PEout(6)  //ģ��������1������ѹ�л�
#define AI_IU_SW2     PBout(1)  //ģ��������2������ѹ�л�
#define OCPROTECT_DR	PEout(1) 	//�������� 
#define DC24V_FK_DR		PFout(12) //ʾ����ָʾ��
#define DC48V_ES_SHUTDOWN_DR  PFout(13) 	//48V�쳣����

/* input interface definition */
#define SAFE_48V_SWITCH PFin(11)  //48V switch state input
#define POWKEY_STA   		PEin(0)   //�������µ�����
#define REMOTEON_STA   	PBin(8)   //Զ���ϵ�����		
#define REMOTEOFF_STA		PEin(15)  //Զ���µ�����   
#define POWER_STA_OK		PGin(1)   //OK�ź�

/* Function define  -------------------------------------*/
void gpio_init(void);																

#endif 
