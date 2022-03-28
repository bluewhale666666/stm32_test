
#define    __EXTI__ 1
#include "exti.h"
#undef __EXTI__

#include "sys.h" 
#include "delay.h" 
#include "do_led.h" 
#include "di_key.h"
#include "ecatappl.h"
/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    Interrupt service routine for the PDI interrupt from the EtherCAT Slave Controller
*////////////////////////////////////////////////////////////////////////////////////////

////�ⲿ�ж�1�������
//void EXTI1_IRQHandler(void)
//{
//	 
//	 PDI_Isr();
////	 GPIO_SetBits(GPIOF,GPIO_Pin_9);//��LEDO��֤��ȷʵ�����ж�
//	 EXTI_ClearITPendingBit(EXTI_Line1); //���LINE1�ϵ��жϱ�־λ 
//}	


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    Interrupt service routine for the interrupts from SYNC0���жϺ�0
*////////////////////////////////////////////////////////////////////////////////////////

void EXTI2_IRQHandler(void)
{
//	 GPIO_ResetBits(GPIOF,GPIO_Pin_7);//��LED1��֤��ȷʵ�����ж�
	 Sync0_Isr();
//	 GPIO_SetBits(GPIOF,GPIO_Pin_7);//��LED1��֤��ȷʵ�����ж�
	 //GPIO_ResetBits(GPIOF,GPIO_Pin_9);//��LEDO��֤��ȷʵ�����ж�
	 EXTI_ClearITPendingBit(EXTI_Line2);//���LINE2�ϵ��жϱ�־λ 
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    Interrupt service routine for the interrupts from SYNC1
*////////////////////////////////////////////////////////////////////////////////////////
void EXTI3_IRQHandler(void)
{
	 Sync1_Isr();
	 EXTI_ClearITPendingBit(EXTI_Line3);  //���LINE3�ϵ��жϱ�־λ  
}


//�ⲿ�ж�4�������
//void EXTI4_IRQHandler(void)
//{
//	
//	 EXTI_ClearITPendingBit(EXTI_Line4);//���LINE4�ϵ��жϱ�־λ  
//}
//	

//�ⲿ�жϳ�ʼ������
void EXTI1_Init(void)//�ж���0�����ȼ�������ߣ���ESC���ⲿ�ж�
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;	
	//KEY_Init(); //������Ӧ��IO�ڳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//ʹ��SYSCFGʱ��
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);//PA1 ���ӵ��ж���1
  /* ����EXTI_Line0 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line1;//LINE1
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½��ش��� 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ��LINE1
  EXTI_Init(&EXTI_InitStructure);//����	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;//�ⲿ�ж�1
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//��ռ���ȼ�3
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����	   
}
void EXTI2_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;	
//	KEY_Init(); //������Ӧ��IO�ڳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//ʹ��SYSCFGʱ��
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);//PE2 ���ӵ��ж���2
	/* ����EXTI_Line2*/
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½��ش���
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//�ж���ʹ��
  EXTI_Init(&EXTI_InitStructure);//����
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;//�ⲿ�ж�2
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//��ռ���ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;//�����ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����
	
}
void EXTI3_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	//KEY_Init(); //������Ӧ��IO�ڳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//ʹ��SYSCFGʱ��
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);//PE3 ���ӵ��ж���3
	/* ����EXTI_Line3 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½��ش���
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//�ж���ʹ��
  EXTI_Init(&EXTI_InitStructure);//����
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//�ⲿ�ж�3
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;//��ռ���ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����   
}



//PS2�ж���������//en:1������;0���ر�
void EN_DISEN_EXTI(u8 en,u8 linenum)
{    EXTI->PR=1<<linenum;           //���LINEnum�ϵ��жϱ�־λ    
	if(en)EXTI->IMR|=1<<linenum;    //������linenum�ϵ��ж�    
	else EXTI->IMR&=~(1<<linenum);  //����linenum�ϵ��ж�   
	
}







