#include "usart.h"

#include "main.h"							//������ͷ�ļ�
#include "sys.h"							//������ͷ�ļ�

#include "stmflash.h"
#include "string.h"


void DMA_init(void)
{
   DMA_InitTypeDef    DMA_Initstructure;
	
   //����DMAʱ��
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
	
   //DMA����
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
	
  //ָ�����FIFOģʽ��ֱ��ģʽ������ָ������ �� ��ʹ��FIFOģʽ  
	 DMA_Initstructure.DMA_FIFOMode = DMA_FIFOMode_Disable;    //ָ����FIFO��ֵˮƽ
	 DMA_Initstructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;  //ָ����Burstת�������ڴ洫�� 
	 DMA_Initstructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;    //ָ����Burstת��������Χת��  
	 DMA_Initstructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single; 
	
   DMA_Init(DMA2_Stream2,&DMA_Initstructure);  
	 DMA_Cmd(DMA2_Stream2,ENABLE);	 
}

//USART1
void usart1_init(uint32_t bound)
{
	GPIO_InitTypeDef 	GPIO_InitStructure;
	USART_InitTypeDef	USART_InitStructure;								//�������üĴ����ṹ
	NVIC_InitTypeDef 	NVIC_InitStructure;  								//Ƕ���ж������������Ĵ����ṹ
		
 	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	//ʹ��USART1,GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);	//��ʼ��USRAT1ʱ�� 

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9����ΪUSART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10����ΪUSART1
	
	//USART1_TX   GPIOA.9  USART1_RX   GPIOA.10��ʼ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//USART1
//	USART_DeInit(USART1);	
	USART_InitStructure.USART_BaudRate=bound;						  					//������
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;				//8λ����
	USART_InitStructure.USART_StopBits=USART_StopBits_1;						//��֡��β����1��ֹͣλ
	USART_InitStructure.USART_Parity=USART_Parity_No;				  			//��żʧ��
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;	//Ӳ��������ʧ��																												
	USART_InitStructure.USART_Mode=(USART_Mode_Rx|USART_Mode_Tx);		//����ʹ��+����ʹ��
	USART_Init(USART1,&USART_InitStructure);												//USRAT1�����趨
	
	//����debug
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	 				//��UART�ж�����
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			//�����ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	   				//�ж�ʹ��
	NVIC_Init(&NVIC_InitStructure);														//����UART2�ж�
	
	//���´������DMA����+�����жϷ�ʽ
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);  
  USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);
  USART_Cmd(USART1,ENABLE);
  DMA_init();//-------------------------------��ʼ��DM
}





//�����ж�
void USART1_IRQHandler(void)
{
	uint8_t clear = clear;  // ���������������ġ�û���õ���������
	
	if(USART_GetITStatus(USART1,USART_IT_IDLE) == SET)
	{
		clear = USART1->SR;
		clear = USART1->DR; 	//��USART_IT_IDLE��־

		DMA_Cmd(DMA2_Stream2,DISABLE);    //�ر�DMA
		DMA_ClearFlag(DMA2_Stream2, DMA_FLAG_TCIF2 | DMA_FLAG_FEIF2 | 
				DMA_FLAG_DMEIF2 | DMA_FLAG_TEIF2 | DMA_FLAG_HTIF2);//�����־λ
		Rxd1_Da_Num = RXD1_MAX_NUM -  DMA_GetCurrDataCounter(DMA2_Stream2);   //�õ������������ݸ���  
  
		DMA_SetCurrDataCounter(DMA2_Stream2,RXD1_MAX_NUM);   //�������ý������ݸ���
		DMA_Cmd(DMA2_Stream2,ENABLE);  //����DMA

		Rx1Status = 1;   //��ǽ��յ�һ֡		
	}
}

