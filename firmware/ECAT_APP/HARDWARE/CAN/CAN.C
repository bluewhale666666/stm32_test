
#include "stm32f4xx.h"
#include "CAN_DATA.h"
#include "stm32f4xx_can.h"
#include "Robot-Device.h"
#include "testmode.h"

//#include "main.h"
/*******************************************************************************
* Function Name  : CAN_Configuration
* Description    : Configures the CAN
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
#define CAN1_FILTER_START                        0
#define CAN2_FILTER_START						14//¹ýÂËÆ÷
#define	FILTER_MESSAGE_NUM					1	  	//Òª¹ýÂËµÄ±¨ÎÄ×Ü¸öÊý£¬²»ÄÜ³¬¹ý14¸ö
#define	FILTER_MESSAGE_NUM_SHAWOD			1	  	//Ò»°ãÓëFILTER_MESSAGE_NUMÏàµÈ£¬µ«Èç¹ûÎª0Ôò²»¹ýÂËÈÎºÎ±¨ÎÄ
u16 can_rx_cnt;                                     //can½ÓÊÕÊý¾Ý¼ÆÊý
u16 can_rx_len;                                     //can½ÓÊÕÊý¾Ý³¤¶È
u32 can_rx_ID;                                      //can ½ÓÊÕÊý¾ÝÖ¡ IDºÅ
u16 can_tx_cnt;                                     //can·¢ËÍÊý¾Ý¼ÆÊý
u16 can_tx_len;                                     //can·¢ËÍÊý¾Ý³¤¶È
u32 can_tx_ID;                                      //can ·¢ËÍÊý¾ÝÖ¡ IDºÅ
u16 last_can_tx_cnt;
u16 last_can_tx_len;                                     //can·¢ËÍÊý¾Ý³¤¶È
u32 last_can_tx_ID;

u8 Flag_canRx = 0;

const unsigned int can1_filter_list_id[FILTER_MESSAGE_NUM] = 
														{
															0x18400000,		//Ä
														};
const unsigned int can2_filter_list_id[FILTER_MESSAGE_NUM] = 
														{
															0x18412345,		//Ä
														};
volatile unsigned int  CAN_ID;		//unsigned intÎª32Î»µÄ unsigned short intÎª16Î»µÄ
u8 CAN_DATA[8];
u8 can_send_data[8];
u8 last_can_send_data[8];														
unsigned char can_baudrate = 0;
//unsigned int CO_Pro_Can_baudrate;
//struct _CAN_BUFFER__ canbuf;
//volatile unsigned char CanRec_flag = 0;

void CAN_Configuration(unsigned int can_br);
void NVIC_Configuration(void); 
void GPIO_Configuration(void);
void  Filter_List(const unsigned int *CAN1_filte_list_id,unsigned char CAN1_num,const unsigned int *CAN2_filte_list_id,unsigned char CAN2_num);

void CAN_Configuration(unsigned int can_br)
{
	
	CAN_InitTypeDef        CAN_InitStructure;
	GPIO_InitTypeDef      GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//Ê¹ÄÜPORTAÊ±ÖÓ	                   											 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);//Ê¹ÄÜCAN1Ê±ÖÓ	
	//³õÊ¼»¯GPIO
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11| GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//¸´ÓÃ¹¦ÄÜ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//ÍÆÍìÊä³ö
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//ÉÏÀ­
  GPIO_Init(GPIOA, &GPIO_InitStructure);//³õÊ¼»¯PD0,PD1
	
	//Òý½Å¸´ÓÃÓ³ÉäÅäÖÃ
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource11,GPIO_AF_CAN1); //GPIOA11¸´ÓÃÎªCAN1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource12,GPIO_AF_CAN1); //GPIOA12¸´ÓÃÎªCAN1

//	CAN_DeInit(CAN1);
	/* CAN cell init */
	CAN_InitStructure.CAN_TTCM = DISABLE; /* Ê±¼ä´¥·¢½ûÖ¹, Ê±¼ä´¥·¢£ºCANÓ²¼þµÄÄÚ²¿¶¨Ê±Æ÷±»¼¤»î£¬²¢ÇÒ±»ÓÃÓÚ²úÉúÊ±¼ä´Á */
	CAN_InitStructure.CAN_ABOM = ENABLE; /* ×Ô¶¯ÀëÏß½ûÖ¹£¬×Ô¶¯ÀëÏß£ºÒ»µ©Ó²¼þ¼à¿Øµ½128´Î11¸öÒþÐÔÎ»£¬¾Í×Ô¶¯ÍË³öÀëÏß×´Ì¬¡£ÔÚÕâÀïÒªÈí¼þÉè¶¨ºó²ÅÄÜÍË³ö */
	CAN_InitStructure.CAN_AWUM = DISABLE; /* ×Ô¶¯»½ÐÑ½ûÖ¹£¬ÓÐ±¨ÎÄÀ´µÄÊ±ºò×Ô¶¯ÍË³öÐÝÃß	*/
	CAN_InitStructure.CAN_NART = DISABLE; /* ±¨ÎÄÖØ´«, Èç¹û´íÎóÒ»Ö±´«µ½³É¹¦Ö¹£¬·ñÔòÖ»´«Ò»´Î */
	CAN_InitStructure.CAN_RFLM = DISABLE; /* ½ÓÊÕFIFOËø¶¨, 1--Ëø¶¨ºó½ÓÊÕµ½ÐÂµÄ±¨ÎÄÕª²»Òª£¬0--½ÓÊÕµ½ÐÂµÄ±¨ÎÄÔò¸²¸ÇÇ°Ò»±¨ÎÄ	*/
	CAN_InitStructure.CAN_TXFP = DISABLE;  /* ·¢ËÍÓÅÏÈ¼¶  0---ÓÉ±êÊ¶·û¾ö¶¨  1---ÓÉ·¢ËÍÇëÇóË³Ðò¾ö¶¨	*/
	CAN_InitStructure.CAN_Mode = CAN_Mode_Normal; /* Ä£Ê½	*/

	CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;
	CAN_InitStructure.CAN_BS1=CAN_BS1_7tq;
	CAN_InitStructure.CAN_BS2=CAN_BS2_6tq;
//	CAN_InitStructure.CAN_Prescaler=48;        //ÎÒµÄÊ±ÖÓÊÇPLL 72M,ÄÇÃ´CANÓ¦¸ÃÊÇ36MÁË°É?ÕâÑù¾ÍÊÇ36/((1+8+7)*18)=125K Ä¬ÈÏÎª125Kbps	
  switch(can_br)
{	 case 10:
	         CAN_InitStructure.CAN_Prescaler=300;
			 break;
	 case 20: 
			 CAN_InitStructure.CAN_Prescaler=150;
			 break;
	 case 50: 
			 CAN_InitStructure.CAN_Prescaler=60;
			 break;
	 case 100: 
			 CAN_InitStructure.CAN_Prescaler=30;
			 break;
	 case 125: 
			 CAN_InitStructure.CAN_Prescaler=24;
			 break;
	 case 250: 
			 CAN_InitStructure.CAN_Prescaler=12;
			 break;
	 case 500: 
			 CAN_InitStructure.CAN_Prescaler=6;
			 break;
	 case 800: 
//	         CAN_InitStructure.CAN_BS1=CAN_BS1_5tq;
//	         CAN_InitStructure.CAN_BS2=CAN_BS2_3tq; 
//			 CAN_InitStructure.CAN_Prescaler=5;
			 break;
	 case 1000: 
			 CAN_InitStructure.CAN_Prescaler=3;
			 break;
default:
		  CAN_InitStructure.CAN_Prescaler=24;
		  can_br = 125;
          
//          CAN_InitStructure.CAN_Prescaler=3;
		  break;  
 }
    
  //SDO_Input0x8001.CAN_Baudrate =can_br;
  CAN_Baudrate0x8001 = can_br;
	CAN_Init(CAN1,&CAN_InitStructure);
	Filter_List(can1_filter_list_id,0,can2_filter_list_id,0);//Îª0Ê±²»¹ýÂËÈÎºÎID
	CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);//Çå½ÓÊÕÖÐ¶Ï±êÖ¾
	CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);   /* ¹ÒºÅÖÐ¶Ï, ½øÈëÖÐ¶Ïºó¶ÁfifoµÄ±¨ÎÄº¯ÊýÊÍ·Å±¨ÎÄÇåÖÐ¶Ï±êÖ¾ */
 
  NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
* Function Name  : CanWriteData
* Description    : Can Write Date to CAN-BUS
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void  Filter_List(const unsigned int *CAN1_filte_list_id,unsigned char CAN1_num,const unsigned int *CAN2_filte_list_id,unsigned char CAN2_num)
{
	unsigned int temp_id = 0;
	unsigned char temp = 0;
	unsigned char i = 0;
	CAN_FilterInitTypeDef  CAN_FilterInitStructure;
	/*******************ÒÔÏÂÊÇnumÎª0²»¹ýÂËÈÎºÎID***************************************/

	if(CAN1_num > 0 && CAN2_num > 0)//can1ºÍcan2¶¼Òª¹ýÂË
	{
		temp = CAN1_num <= CAN2_num ? CAN1_num : CAN2_num;//È¡³ö½ÏÐ¡µÄÊý 
		for(i = 0;i < temp;i ++)
		{
			temp_id = CAN1_filte_list_id[i];
			CAN_FilterInitStructure.CAN_FilterNumber = i;     ///* ¹ýÂËÆ÷×é */
			CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;//CAN_FilterMode_IdList;//CAN_FilterMode_IdMask;  /* ÆÁ±ÖÄ£Ê½ */
			CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit; ///* 32Î» */
			CAN_FilterInitStructure.CAN_FilterIdHigh = (temp_id<<3)>>16;//(id<<3)>>16;  
			CAN_FilterInitStructure.CAN_FilterIdLow = (temp_id<<3)|CAN_ID_EXT|CAN_RTR_DATA;//À©Õ¹Ö¡
			CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0xffff;
			CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0xffff;
			CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;  ///* ÄÜ¹»Í¨¹ý¸Ã¹ýÂËÆ÷µÄ±¨ÎÄ´æµ½fifo0ÖÐ */
			CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
			CAN_FilterInit(&CAN_FilterInitStructure);

			temp_id = CAN2_filte_list_id[i];
			CAN_FilterInitStructure.CAN_FilterNumber = i + 14;     ///* ¹ýÂËÆ÷×é */
			CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;//CAN_FilterMode_IdList;//CAN_FilterMode_IdMask;  /* ÆÁ±ÖÄ£Ê½ */
			CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit; ///* 32Î» */
			CAN_FilterInitStructure.CAN_FilterIdHigh = (temp_id<<3)>>16;//(id<<3)>>16;  
			CAN_FilterInitStructure.CAN_FilterIdLow = (temp_id<<3)|CAN_ID_EXT|CAN_RTR_DATA;//À©Õ¹Ö¡
			CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0xffff;
			CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0xffff;
			CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;  ///* ÄÜ¹»Í¨¹ý¸Ã¹ýÂËÆ÷µÄ±¨ÎÄ´æµ½fifo0ÖÐ */
			CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
			CAN_FilterInit(&CAN_FilterInitStructure);		
		}	
	}
	else if(CAN1_num == 0 && CAN2_num == 0)
	{
		CAN_FilterInitStructure.CAN_FilterNumber = 0;     /* ¹ýÂËÆ÷×é */
		CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;//CAN_FilterMode_IdList;//CAN_FilterMode_IdMask;  /* ÆÁ±ÖÄ£Ê½ */
		CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit; /* 32Î» */
		CAN_FilterInitStructure.CAN_FilterIdHigh = 0;
		CAN_FilterInitStructure.CAN_FilterIdLow = 0;
		CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
		CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
		CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;  /* ÄÜ¹»Í¨¹ý¸Ã¹ýÂËÆ÷µÄ±¨ÎÄ´æµ½fifo0ÖÐ */
		CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
		CAN_FilterInit(&CAN_FilterInitStructure);
		CAN_FilterInitStructure.CAN_FilterNumber = 14;	//CAN2¹ýÂËÆ÷´Ó14¿ªÊ¼
		CAN_FilterInit(&CAN_FilterInitStructure);
	}

}


void CanWriteData(unsigned int ID, unsigned int dlen, u8 *pbuf)
{
		
	unsigned char i;
	CanTxMsg TxMessage;

	TxMessage.StdId = ID;
	TxMessage.IDE = CAN_ID_STD;
	TxMessage.RTR = CAN_RTR_DATA; /* ÉèÖÃÎªÊý¾ÝÖ¡ */
	TxMessage.DLC = dlen;            /* Êý¾Ý³¤¶È, can±¨ÎÄ¹æ¶¨×î´óµÄÊý¾Ý³¤¶ÈÎª8×Ö½Ú */
	for(i = 0;i < dlen; i ++)
	{
		TxMessage.Data[i] = pbuf[i];
	}
   
//	CAN_Transmit(CAN2,&TxMessage);  /* ·µ»ØÕâ¸öÐÅÏ¢ÇëÇó·¢ËÍµÄÓÊÏäºÅ0,1,2»òÃ»ÓÐÓÊÏäÉêÇë·¢ËÍno_box */	
	CAN_Transmit(CAN1,&TxMessage);  /* ·µ»ØÕâ¸öÐÅÏ¢ÇëÇó·¢ËÍµÄÓÊÏäºÅ0,1,2»òÃ»ÓÐÓÊÏäÉêÇë·¢ËÍno_box */	
}


//CAN1ÖÐ¶Ï³ÌÐò
void CAN1_RX0_IRQHandler(void)
{
	CanRxMsg RxMessage; 
	unsigned char i;
	
 	CAN_Receive(CAN1,CAN_FIFO0, &RxMessage);  /* ´Ëº¯Êý°üº¬ÊÍ·ÅÌá³ö±¨ÎÄÁËµÄ,ÔÚ·Ç±ØÒªÊ±,²»ÐèÒª×Ô¼ºÊÍ·Å */
	can_rx_ID = RxMessage.StdId;
	can_rx_len = RxMessage.DLC;
	//CAN_ID = RxMessage.ExtId;
	for(i = 0;i < 8; i ++)
	{
		CAN_DATA[i] = RxMessage.Data[i];
	}
    can_rx_cnt ++;
//	CanWriteData(0x02,8,CAN_DATA);
	CAN_ClearITPendingBit(CAN1,CAN_IT_FMP0);  /* Çå³ý¹ÒÆðÖÐ¶Ï */
	if(Test_Mode0x8015 == 0)	//product mode
	{
		Flag_canRx = 1;
	}
	if(Test_Mode0x8015 == 1)
	{
		tm_can_rxflag = 1;
	}
	
//	CanWriteData(Local_NodeID,8,CAN_DATA);
//	CAN_Send_Data();
//	SEI();//´ò¿ª×ÜÖÐ¶Ï
}

extern u8 can_tx_start; 
void CAN_data(void)
{
	int i;

	if(can_tx_start == 1)
	{
		CanWriteData(can_tx_ID,can_tx_len,can_send_data);		
		last_can_tx_ID = can_tx_ID;
		last_can_tx_len = can_tx_len;
		for(i=0;i<can_tx_len;i++)
		{
			last_can_send_data[i] = can_send_data[i];
		}
	}
	else
	{
		CanWriteData(last_can_tx_ID,last_can_tx_len,last_can_send_data);
	}
	
	GPIO_ResetBits(GPIOF,GPIO_Pin_7);		
}
