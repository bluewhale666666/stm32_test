#include "sys.h"		    
#include "stm32f4xx.h"                  // Device header
#include "rs232.h"	 
#include "delay.h"
#include "do_led.h"
#include "Robot-Device.h"
	 
#define CRC_INIT232 0xffff   //CCITT初始CRC为全1
#define GOOD_CRC232 0xf0b8   //校验时计算出的固定结果值
#define DMA_RX232_LEN 32
#define DMA_TX232_LEN 32
//#if EN_USART1_RX   		//如果使能了接收  
u16 RS232_CON;
u16 RS232_tx_CON;
u16 LAST_RS232_tx_CON;
u16 RS232_tx_LEN;
u16 RS232_rx_LEN;//接收数据长度

u8 RS232_RX[64];  	//接收数据,最大64个字节.
u8 RS232_TX[64];	//发送数据,最大64个字节.
u8 RS232_RX_CNT=0;  //接收到的数据长度
u8 uart_232[64];//针对uart的临时缓存数组
u8 Flag_Tx232_Busy;
u8 Flag_232Rx=0;
BOOL U232WorkWell=0;
void RS232_Send(u8 size);
void RS232_Send_Data(u8 *buf,u8 len);
void U232_data(void);
/*********************************************************************
*							DMA发送中断处理函数
**********************************************************************/

//void DMA2_Stream7_IRQHandler(void)
//{
//	if(DMA_GetITStatus(DMA2_Stream7,DMA_IT_TCIF6) != RESET) 
//	{
//			//清除标志位
//			USART_ClearITPendingBit(USART1, USART_IT_TC);	//清除USART1发送完成中断标志DMA_ClearFlag(DMA2_Stream7,DMA_FLAG_TCIF6);
//		    DMA_ClearFlag(DMA2_Stream7, DMA_FLAG_TCIF6 | DMA_FLAG_FEIF6 | 
//					  DMA_FLAG_DMEIF6 | DMA_FLAG_TEIF6 | DMA_FLAG_HTIF6);//清零标志位
//			//	GPIO_SetBits(GPIOF,GPIO_Pin_8);
//			//关闭DMA
//			DMA_Cmd(DMA2_Stream7,DISABLE);
//			USART_ITConfig(USART1,USART_IT_TC,ENABLE);//似乎还必须加上这个中断，然后等待发送完成进入串口中断检查
//	
//	}
//}
   
/*********************************************************************
*							串口中断处理函数,DMA方式接收
**********************************************************************/

void USART1_IRQHandler(void) 
{
    volatile u8 rx_len,rs9,rs10;
	u8 i;
	
	//接收完成中断
	if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)
    {
    	USART1->SR;
    	USART1->DR; //清USART_IT_IDLE标志
		//关闭DMA

    	DMA_Cmd(DMA2_Stream2,DISABLE);
		//清除标志位
//		DMA_ClearFlag(DMA2_Stream2,DMA_FLAG_TCIF5);
		DMA_ClearFlag(DMA2_Stream2, DMA_FLAG_TCIF2 | DMA_FLAG_FEIF2 | 
					  DMA_FLAG_DMEIF2 | DMA_FLAG_TEIF2 | DMA_FLAG_HTIF2);//清零标志位
		if(U232WorkWell==0){GPIO_ResetBits(GPIOF,GPIO_Pin_8);}else GPIO_SetBits(GPIOF,GPIO_Pin_8);		
		//获得接收帧帧长
		rx_len = DMA_RX232_LEN - DMA_GetCurrDataCounter(DMA2_Stream2);	
		RS232_rx_LEN = rx_len;
		RS232_CON++;
	    for (i=0;i<rx_len;i++)
		{
		  RS232_RX[i] = uart_232[i];
			
		}		
		Flag_232Rx =1;
		//设置传输数据长度
		DMA_SetCurrDataCounter(DMA2_Stream2,DMA_RX232_LEN);
    	//打开DMA
		DMA_Cmd(DMA2_Stream2,ENABLE);
	}
//	U232_data();


}







//////////////////////////////////////////////////////


/*********************************************************************
*							初始化串口
**********************************************************************/
//#endif										 
//初始化IO 串口1
//bound:波特率	  
void RS232_Init(u32 bound)
{  	 
	
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	//定义DMA结构体
	DMA_InitTypeDef DMA_InitStructure;
//////////////////////////////////////////////////////////	
/**
  \brief	串口发DMA配置 
	
*////////////////////////////////////////////////////////	
 
	//启动DMA时钟
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//使能USART1时钟
  
	
//////////////////////////////////////////////////////////	
/**
	\brief 串口收DMA配置 
	
*////////////////////////////////////////////////////////	

	//启动DMA时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
	//DMA通道配置
	DMA_DeInit(DMA2_Stream2);//XXC:注意看，在这里是DMA2的第5个流配置，也是第4通道。通过查映射表的方法，发现这个就是串口2的rx
	DMA_InitStructure.DMA_Channel = DMA_Channel_4;
	//外设地址
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR);
	//内存地址
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)uart_232;
	//dma传输方向
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
	//设置DMA在传输时缓冲区的长度
	DMA_InitStructure.DMA_BufferSize = DMA_RX232_LEN;
	//设置DMA的外设递增模式，一个外设
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	//设置DMA的内存递增模式
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	//外设数据字长
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	//内存数据字长
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	//设置DMA的传输模式
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	//设置DMA的优先级别
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	
	//指定如果FIFO模式或直接模式将用于指定的流 ： 不使能FIFO模式  
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;    
	//指定了FIFO阈值水平
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;        
	//指定的Burst转移配置内存传输 
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;       
	//指定的Burst转移配置外围转移 */  
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single; 
	
	//配置DMA2的通道         
	DMA_Init(DMA2_Stream2, &DMA_InitStructure);  
	//使能通道
	DMA_Cmd(DMA2_Stream2,ENABLE);
////////////////////////////////////////////////////////////////////////	
/** 
	\brief 串口2配置
	
*///////////////////////////////////////////////////////////////////////
  //串口2引脚复用映射
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA2复用为USART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA3复用为USART1
	
	//USART1    
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA2与GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure); //初始化PA2，PA3
	
   //USART1 初始化设置
	USART_InitStructure.USART_BaudRate = bound;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
  USART_Init(USART1, &USART_InitStructure); 						//初始化串口2
	
	//采用DMA方式接收
	USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);

	//中断配置

	 
		
  USART_Cmd(USART1, ENABLE);  									//使能串口 2
	USART_ClearFlag(USART1, USART_FLAG_TC);
	
// #if EN_USART1_RX	

	//USART1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x04;//抢占优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0x00;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
  USART_ITConfig(USART1,USART_IT_IDLE,ENABLE); 
//#endif	
	
//	GPIO_ResetBits(GPIOA,GPIO_Pin_4);		//默认为接收模式,接收使能是低电平有效	
  RS232_Baudrate0x8002 = bound ;
}


/*********************************************************************
*							接口函数:发送数据
*参数:data:发送数据存放地址
*	  size:发送数据字节数
**********************************************************************/

void RS232_Send(u8 size)
{
	//等待空闲
	while (Flag_Tx232_Busy);
	Flag_Tx232_Busy = 1;

	//设置传输数据长度
//	GPIO_SetBits(GPIOA,GPIO_Pin_4);				//设置为发送模式
	DMA_SetCurrDataCounter(DMA2_Stream7,size);
	//打开DMA,开始发送
 	DMA_Cmd(DMA2_Stream7,ENABLE);
}





//RS232发送len个字节.
//buf:发送区首地址
//len:发送的字节数(为了和本代码的接收匹配,这里建议不要超过32个字节)
void RS232_Send_Data(u8 *buf,u8 len)
{
	u8 t;
	volatile u8 dummy=0;

  	for(t=0;t<len;t++)		//循环发送数据
	{
		 USART_SendData(USART1,buf[t]); //发送数据
	   while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET){}; //等待发送结束		
   
	}	 
//	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET){}; //等待发送结束		
	 RS232_RX_CNT=0;	  
//	GPIO_ResetBits(GPIOA,GPIO_Pin_4);				//设置为接收模式	
}

/****下表是常用ccitt 16,生成式1021反转成8408后的查询表格****/
//u16 crc_table[256] =
//{
//0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5,
//		0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce,
//		0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
//		0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de, 0x2462,
//		0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a, 0xb54b,
//		0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672, 0x1611,
//		0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738,
//		0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840,
//		0x1861, 0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969,
//		0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33,
//		0x2a12, 0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
//		0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41, 0xedae,
//		0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97, 0x6eb6,
//		0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70, 0xff9f, 0xefbe, 0xdfdd,
//		0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca, 0xa1eb,
//		0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004,
//		0x4025, 0x7046, 0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c,
//		0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277,
//		0x7256, 0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
//		0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 0xa7db,
//		0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3, 0x36f2,
//		0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e,
//		0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827,
//		0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9,
//		0x9bd8, 0xabbb, 0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0,
//		0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8,
//		0x8dc9, 0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
//		0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, 0x6e17,
//		0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0};
/*****CRC计算函数,可将第一个参数reg_init简化掉********/
//unsigned short do_crc(unsigned char *message, unsigned int len)
//{
//    unsigned short int crc ;
////	unsigned char da;
//	crc=0;
// //   message++;    
//    while (len--){
//		
//		    message++;
////			crc=(crc<<8)^crc_table[((crc>>8)^*(char*)message)&0x00FF];
//		//	da = (u8) crc >> 8; 	/* 以8位二进制数的形式暂存CRC的高8位 */
//		//	crc <<= 8; 							/* 左移8位，相当于CRC的低8位乘以  */
//	//		message++;
//		//	crc ^= crc_table[da ^ *message]; 	/* 高8位和当前字节相加后再查表求CRC ，再加上以前的CRC */

//	} 
//    return (crc);
//} 

void U232_data(void)	
{
	
	if(LAST_RS232_tx_CON !=RS232_tx_CON)
	{
		
		if(RS232_tx_LEN >32) RS232_tx_LEN =32;		   				
		RS232_Send_Data(RS232_TX,RS232_tx_LEN);			//这是发送的数据函数，这里需要先设定好发送的数据格式，然后通过DMA一次性发送12个字节数据
		LAST_RS232_tx_CON = RS232_tx_CON ;
    }
    
}




