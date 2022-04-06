#include "sys.h"		    
#include "stm32f4xx.h"                  // Device header
#include "rs485.h"	 
#include "delay.h"
#include "do_led.h"
#include "Robot-Device.h"
#include "testmode.h"
	 
#define CRC_INIT 0xffff   //CCITT��ʼCRCΪȫ1
#define GOOD_CRC 0xf0b8   //У��ʱ������Ĺ̶����ֵ
#define DMA_RX_LEN 32
#define DMA_TX_LEN 32
//#if EN_USART2_RX   		//���ʹ���˽���  

u16 RS485_CON; 
u16 RS485_tx_CON; 
u16 RS485_tx_CON_LAST; 
u16 RS485_tx_LEN; 
u16 RS485_tx_LEN_LAST; 
u16 RS485_rx_LEN;//??????????? 
 
u8 RS485_RX[64];  	//????????,???32?????. 
u8 RS485_TX[64];	//????????,???32????? 
u8 RS485_TX_LAST[64];	//????????,???32????? 
 
u8 RS485_RX_CNT=0;  //���յ������ݳ���
u8 uart_485[64];//���uart����ʱ��������
u8 Flag_Tx_Busy;
u8 Flag_485Rx=0;
BOOL U485WorkWell=0;

/*********************************************************************
*							DMA�����жϴ�����
**********************************************************************/

//void DMA1_Stream6_IRQHandler(void)
//{
//	if(DMA_GetITStatus(DMA1_Stream6,DMA_IT_TCIF6) != RESET) 
//	{
//			//�����־λ
//			USART_ClearITPendingBit(USART2, USART_IT_TC);	//���USART1��������жϱ�־DMA_ClearFlag(DMA1_Stream6,DMA_FLAG_TCIF6);
//		    DMA_ClearFlag(DMA1_Stream6, DMA_FLAG_TCIF6 | DMA_FLAG_FEIF6 | 
//					  DMA_FLAG_DMEIF6 | DMA_FLAG_TEIF6 | DMA_FLAG_HTIF6);//�����־λ
//			//	GPIO_SetBits(GPIOF,GPIO_Pin_8);
//			//�ر�DMA
//			DMA_Cmd(DMA1_Stream6,DISABLE);
//			USART_ITConfig(USART2,USART_IT_TC,ENABLE);//�ƺ��������������жϣ�Ȼ��ȴ�������ɽ��봮���жϼ��
//	
//	}
//}
   
/*********************************************************************
*							�����жϴ�����,DMA��ʽ����
**********************************************************************/

void USART2_IRQHandler(void) 
{
    volatile u8 rx_len,rs9,rs10,res;
	   u8 i;

	//��������ж�
	if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET)
    {
      USART_ITConfig(USART2,USART_IT_IDLE, DISABLE);
			res = USART_ReceiveData(USART2);	//��USART_IT_IDLE��־	
			DMA_Cmd(DMA1_Stream5,DISABLE);			
		//�ر�DMA
		//�����־λ   
		DMA_ClearFlag(DMA1_Stream5, DMA_FLAG_TCIF5 | DMA_FLAG_FEIF5 | 
					  DMA_FLAG_DMEIF5 | DMA_FLAG_TEIF5 | DMA_FLAG_HTIF5);//�����־λ	
		//��ý���֡֡��
		rx_len = DMA_RX_LEN - DMA_GetCurrDataCounter(DMA1_Stream5);	
		RS485_rx_LEN = rx_len;
		RS485_CON++;
	  for (i=0;i<rx_len;i++)
		{
		  RS485_RX[i] = uart_485[i];
//			
		}	
    USART_ClearITPendingBit(USART2, USART_IT_IDLE);         //����жϱ�־
		//���ô������ݳ���

		DMA_SetCurrDataCounter(DMA1_Stream5,DMA_RX_LEN);
    	//��DMA
		DMA_Cmd(DMA1_Stream5,ENABLE);
		
		if(Test_Mode0x8015 == 0)	//product mode
		{
			Flag_485Rx	=1;
		}
			
		USART_ITConfig(USART2,USART_IT_IDLE, ENABLE);
		
		if(Test_Mode0x8015 == 1)	//test mode
		{
			tm_rs485_rxflag	= 1;
		}
	}

}







//////////////////////////////////////////////////////


/*********************************************************************
*							��ʼ������
**********************************************************************/
//#endif										 
//��ʼ��IO ����2
//bound:������	  
void RS485_Init(u32 bound)
{  	 
	
    GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	//����DMA�ṹ��
	DMA_InitTypeDef DMA_InitStructure;

//////////////////////////////////////////////////////////	
/**
	\brief ������DMA���� 
	
*////////////////////////////////////////////////////////	

	//����DMAʱ��
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
	//DMAͨ������
	DMA_DeInit(DMA1_Stream5);//XXC:ע�⿴����������DMA1�ĵ�5�������ã�Ҳ�ǵ�4ͨ����ͨ����ӳ���ķ���������������Ǵ���2��rx
	DMA_InitStructure.DMA_Channel = DMA_Channel_4;
	//�����ַ
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);
	//�ڴ��ַ
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)uart_485;
	//dma���䷽��
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
	//����DMA�ڴ���ʱ�������ĳ���
	DMA_InitStructure.DMA_BufferSize = DMA_RX_LEN;
	//����DMA���������ģʽ��һ������
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	//����DMA���ڴ����ģʽ
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	//���������ֳ�
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	//�ڴ������ֳ�
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	//����DMA�Ĵ���ģʽ
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	//����DMA�����ȼ���
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	
	//ָ�����FIFOģʽ��ֱ��ģʽ������ָ������ �� ��ʹ��FIFOģʽ  
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;    
	//ָ����FIFO��ֵˮƽ
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;        
	//ָ����Burstת�������ڴ洫�� 
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;       
	//ָ����Burstת��������Χת�� */  
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single; 
	
	//����DMA1��ͨ��         
	DMA_Init(DMA1_Stream5, &DMA_InitStructure);  
	//ʹ��ͨ��
	DMA_Cmd(DMA1_Stream5,ENABLE);
////////////////////////////////////////////////////////////////////////	
/** 
	\brief ����2����
	
*///////////////////////////////////////////////////////////////////////
  //����2���Ÿ���ӳ��
	
	USART_Cmd(USART2, DISABLE);  //ȥʹ�ܴ��� 2 2020-01-09
	

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //ʹ��GPIOAʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//ʹ��USART2ʱ��
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); //GPIOA2����ΪUSART2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); //GPIOA3����ΪUSART2
	
	//USART2    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; //GPIOA2��GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOA,&GPIO_InitStructure); //��ʼ��PA2��PA3
	
	//PA5���������485ģʽ����  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; //GPIOA5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //�������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOA,&GPIO_InitStructure); //��ʼ��PA5
	

   //USART2 ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART2, &USART_InitStructure); 						//��ʼ������2
	

	//����DMA��ʽ����
	USART_DMACmd(USART2,USART_DMAReq_Rx,ENABLE);		
  USART_Cmd(USART2, ENABLE);  									//ʹ�ܴ��� 2
	USART_ClearFlag(USART2, USART_FLAG_TC);
	
// #if EN_USART2_RX	

	//Usart2 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x03;//��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0x00;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���

//#endif	
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);		// Ĭ��Ϊ����ģʽ,����ʹ���ǵ͵�ƽ��Ч	
	//SDO_Input0x8001.RS485_Baudrate = bound ;
	RS485_Baudrate0x8000 = bound ;
	
	USART_ITConfig(USART2,USART_IT_IDLE,ENABLE);  
}



//RS485����len���ֽ�.
//buf:�������׵�ַ
//len:���͵��ֽ���(Ϊ�˺ͱ�����Ľ���ƥ��,���ｨ�鲻Ҫ����32���ֽ�)
 void RS485_Send_Data(u8 *buf,u8 len)
{
	u8 t;
	volatile u8 dummy=0;
	GPIO_SetBits(GPIOA,GPIO_Pin_4);			//����Ϊ����ģʽ
	delay_us(200);
  	for(t=0;t<len;t++)		//ѭ����������
	{
		
    USART_SendData(USART2,buf[t]); //��������
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)==RESET){}; //�ȴ����ͽ���	
	}	 
//	while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET){}; //�ȴ����ͽ���		
	RS485_RX_CNT=0;	  
	delay_us(200);
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);				//����Ϊ����ģʽ	
}

/****�±��ǳ���ccitt 16,����ʽ1021��ת��8408��Ĳ�ѯ���****/
u16 crc_table[256] =
{
0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5,
		0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce,
		0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
		0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de, 0x2462,
		0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a, 0xb54b,
		0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672, 0x1611,
		0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738,
		0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840,
		0x1861, 0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969,
		0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33,
		0x2a12, 0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
		0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41, 0xedae,
		0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97, 0x6eb6,
		0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70, 0xff9f, 0xefbe, 0xdfdd,
		0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca, 0xa1eb,
		0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004,
		0x4025, 0x7046, 0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c,
		0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277,
		0x7256, 0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
		0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 0xa7db,
		0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3, 0x36f2,
		0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e,
		0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827,
		0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9,
		0x9bd8, 0xabbb, 0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0,
		0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8,
		0x8dc9, 0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
		0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, 0x6e17,
		0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0};
/*****CRC���㺯��,�ɽ���һ������reg_init�򻯵�********/
unsigned short do_crc(unsigned char *message, unsigned int len)
{
    unsigned short int crc ;
//	unsigned char da;
	crc=0;
 //   message++;    
    while (len--){
		
		    message++;
			crc=(crc<<8)^crc_table[((crc>>8)^*(char*)message)&0x00FF];
		//	da = (u8) crc >> 8; 	/* ��8λ������������ʽ�ݴ�CRC�ĸ�8λ */
		//	crc <<= 8; 							/* ����8λ���൱��CRC�ĵ�8λ����  */
	//		message++;
		//	crc ^= crc_table[da ^ *message]; 	/* ��8λ�͵�ǰ�ֽ���Ӻ��ٲ����CRC ���ټ�����ǰ��CRC */

	} 
    return (crc);
} 

/** 
   *@brief   485 send data 
   *@param   None
   *@note    2ms call once 
   *@return  None
   *@author  liu 
   *@date    2021/11/15       
   *@version V1.0.0
   */
void U485_data(void)	
{
	int i;
	
	/*  */
	USART_ITConfig(USART2,USART_IT_IDLE, DISABLE); 
	
	/* 485 tx max length is 32*/
	if(RS485_tx_LEN >32)  
		RS485_tx_LEN =32; 

	if(rs485_tx_start == 0) 
	{ 
		/* Fetching data from PDO is complete */
		RS485_Send_Data(RS485_TX,RS485_tx_LEN);	 
		RS485_tx_CON_LAST = RS485_tx_CON; 
		RS485_tx_LEN_LAST = RS485_tx_LEN;	
    /* update last data */		
		for(i=0;i<RS485_tx_LEN;i++)
		{
			RS485_TX_LAST[i] = RS485_TX[i];
		} 
	} 
	else 
	{ 
		/* Fetching data from PDO is complete, send last data */
		RS485_Send_Data(RS485_TX_LAST,RS485_tx_LEN_LAST);	 
	} 
  USART_ITConfig(USART2,USART_IT_IDLE, ENABLE);  
}




