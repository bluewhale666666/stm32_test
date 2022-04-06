
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

////外部中断1服务程序
//void EXTI1_IRQHandler(void)
//{
//	 
//	 PDI_Isr();
////	 GPIO_SetBits(GPIOF,GPIO_Pin_9);//打开LEDO，证明确实进入中断
//	 EXTI_ClearITPendingBit(EXTI_Line1); //清除LINE1上的中断标志位 
//}	


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    Interrupt service routine for the interrupts from SYNC0，中断号0
*////////////////////////////////////////////////////////////////////////////////////////

void EXTI2_IRQHandler(void)
{
//	 GPIO_ResetBits(GPIOF,GPIO_Pin_7);//打开LED1，证明确实进入中断
	 Sync0_Isr();
//	 GPIO_SetBits(GPIOF,GPIO_Pin_7);//打开LED1，证明确实进入中断
	 //GPIO_ResetBits(GPIOF,GPIO_Pin_9);//打开LEDO，证明确实进入中断
	 EXTI_ClearITPendingBit(EXTI_Line2);//清除LINE2上的中断标志位 
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    Interrupt service routine for the interrupts from SYNC1
*////////////////////////////////////////////////////////////////////////////////////////
void EXTI3_IRQHandler(void)
{
	 Sync1_Isr();
	 EXTI_ClearITPendingBit(EXTI_Line3);  //清除LINE3上的中断标志位  
}


//外部中断4服务程序
//void EXTI4_IRQHandler(void)
//{
//	
//	 EXTI_ClearITPendingBit(EXTI_Line4);//清除LINE4上的中断标志位  
//}
//	

//外部中断初始化程序
void EXTI1_Init(void)//中断线0的优先级给到最高，是ESC的外部中断
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;	
	//KEY_Init(); //按键对应的IO口初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//使能SYSCFG时钟
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);//PA1 连接到中断线1
  /* 配置EXTI_Line0 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line1;//LINE1
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//使能LINE1
  EXTI_Init(&EXTI_InitStructure);//配置	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;//外部中断1
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//抢占优先级3
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;//子优先级2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);//配置	   
}
void EXTI2_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;	
//	KEY_Init(); //按键对应的IO口初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//使能SYSCFG时钟
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);//PE2 连接到中断线2
	/* 配置EXTI_Line2*/
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//中断线使能
  EXTI_Init(&EXTI_InitStructure);//配置
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;//外部中断2
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//抢占优先级2
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;//子优先级1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);//配置
	
}
void EXTI3_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	//KEY_Init(); //按键对应的IO口初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//使能SYSCFG时钟
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);//PE3 连接到中断线3
	/* 配置EXTI_Line3 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//中断线使能
  EXTI_Init(&EXTI_InitStructure);//配置
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//外部中断3
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;//抢占优先级2
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;//子优先级2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);//配置   
}



//PS2中断屏蔽设置//en:1，开启;0，关闭
void EN_DISEN_EXTI(u8 en,u8 linenum)
{    EXTI->PR=1<<linenum;           //清除LINEnum上的中断标志位    
	if(en)EXTI->IMR|=1<<linenum;    //不屏蔽linenum上的中断    
	else EXTI->IMR&=~(1<<linenum);  //屏蔽linenum上的中断   
	
}







