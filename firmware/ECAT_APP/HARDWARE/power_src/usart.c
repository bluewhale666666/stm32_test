#include "usart.h"

#include "main.h"							//主函数头文件
#include "sys.h"							//主函数头文件

#include "stmflash.h"
#include "string.h"


void DMA_init(void)
{
   DMA_InitTypeDef    DMA_Initstructure;
	
   //开启DMA时钟
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
	
   //DMA配置
	 DMA_DeInit(DMA2_Stream2);
	 DMA_Initstructure.DMA_Channel = DMA_Channel_4;
   DMA_Initstructure.DMA_PeripheralBaseAddr =  (uint32_t)(&USART1->DR);;
   DMA_Initstructure.DMA_Memory0BaseAddr     = (uint32_t)Rxd1_Buff;
   DMA_Initstructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
   DMA_Initstructure.DMA_BufferSize = RXD1_MAX_NUM;			//128
   DMA_Initstructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
   DMA_Initstructure.DMA_MemoryInc =DMA_MemoryInc_Enable;
   DMA_Initstructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
   DMA_Initstructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
   DMA_Initstructure.DMA_Mode = DMA_Mode_Normal;
   DMA_Initstructure.DMA_Priority = DMA_Priority_VeryHigh;
	
  //指定如果FIFO模式或直接模式将用于指定的流 ： 不使能FIFO模式  
	 DMA_Initstructure.DMA_FIFOMode = DMA_FIFOMode_Disable;    //指定了FIFO阈值水平
	 DMA_Initstructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;  //指定的Burst转移配置内存传输 
	 DMA_Initstructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;    //指定的Burst转移配置外围转移  
	 DMA_Initstructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single; 
	
   DMA_Init(DMA2_Stream2,&DMA_Initstructure);  
	 DMA_Cmd(DMA2_Stream2,ENABLE);	 
}

//USART1
void usart1_init(uint32_t bound)
{
	GPIO_InitTypeDef 	GPIO_InitStructure;
	USART_InitTypeDef	USART_InitStructure;								//定义配置寄存器结构
	NVIC_InitTypeDef 	NVIC_InitStructure;  								//嵌套中断向量控制器寄存器结构
		
 	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	//使能USART1,GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);	//初始化USRAT1时钟 

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9复用为USART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10复用为USART1
	
	//USART1_TX   GPIOA.9  USART1_RX   GPIOA.10初始化
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//USART1
//	USART_DeInit(USART1);	
	USART_InitStructure.USART_BaudRate=bound;						  					//波特率
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;				//8位数据
	USART_InitStructure.USART_StopBits=USART_StopBits_1;						//在帧结尾传输1个停止位
	USART_InitStructure.USART_Parity=USART_Parity_No;				  			//奇偶失能
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;	//硬件流控制失能																												
	USART_InitStructure.USART_Mode=(USART_Mode_Rx|USART_Mode_Tx);		//发送使能+接收使能
	USART_Init(USART1,&USART_InitStructure);												//USRAT1传送设定
	
	//配置debug
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	 				//对UART中断设置
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//先占优先级为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			//从优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	   				//中断使能
	NVIC_Init(&NVIC_InitStructure);														//配置UART2中断
	
	//以下代码改用DMA接收+空闲中断方式
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);  
  USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);
  USART_Cmd(USART1,ENABLE);
  DMA_init();//-------------------------------初始化DM
}





//接收中断
void USART1_IRQHandler(void)
{
	uint8_t clear = clear;  // 用来消除编译器的“没有用到”的提醒
	
	if(USART_GetITStatus(USART1,USART_IT_IDLE) == SET)
	{
		clear = USART1->SR;
		clear = USART1->DR; 	//清USART_IT_IDLE标志

		DMA_Cmd(DMA2_Stream2,DISABLE);    //关闭DMA
		DMA_ClearFlag(DMA2_Stream2, DMA_FLAG_TCIF2 | DMA_FLAG_FEIF2 | 
				DMA_FLAG_DMEIF2 | DMA_FLAG_TEIF2 | DMA_FLAG_HTIF2);//清零标志位
		Rxd1_Da_Num = RXD1_MAX_NUM -  DMA_GetCurrDataCounter(DMA2_Stream2);   //得到真正接收数据个数  
  
		DMA_SetCurrDataCounter(DMA2_Stream2,RXD1_MAX_NUM);   //重新设置接收数据个数
		DMA_Cmd(DMA2_Stream2,ENABLE);  //开启DMA

		Rx1Status = 1;   //标记接收到一帧		
	}
}

