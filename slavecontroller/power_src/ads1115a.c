#include "ads1115a.h"

#include "delay.h"
#include "main.h"							//������ͷ�ļ�

//sda1   ADS1115_ADDR_0


void ADS1115a_Config(u16 config)
{
	IIC1_Start();
	
	IIC1_Send_Byte(ADS1115_ADDR_0); 	//���ͼĴ���������Ϣ
	IIC1_Wait_Ack();
	
	IIC1_Send_Byte(ADS1115_CONFIG_REG); 
	IIC1_Wait_Ack();

	IIC1_Send_Byte(config>>8);
	IIC1_Wait_Ack();

	IIC1_Send_Byte(config);
	IIC1_Wait_Ack();

	IIC1_Stop();	
	delay_us(100);	//��ʱ
	
	IIC1_Start();//������ʼ�ź�
	
	//ָ��ADS1115ָ��Ĵ�������׼����ȡ����	
	IIC1_Send_Byte(ADS1115_ADDR_0); 	//���ͼĴ���������Ϣ
	IIC1_Wait_Ack();
	
	IIC1_Send_Byte(ADS1115_CONVERSION_REG); 
	IIC1_Wait_Ack();

	IIC1_Stop();//����ֹͣ�ź�
}

//
s16 ADS1115a_Read(void)
{
	s16 ad_tmp=0;

	IIC1_Start();

	IIC1_Send_Byte(ADS1115_ADDR_0+1);	//��ָ��
	IIC1_Wait_Ack(); 
	
	ad_tmp |= (uint16_t)IIC1_Read_Byte(1)<<8;
	ad_tmp |= (uint16_t)IIC1_Read_Byte(0);
	IIC1_Stop();//����ֹͣ�ź�

	return ad_tmp;
}


//����ͨ����ȡADCоƬ�����ݣ�һ��ֻ��ȡһ���������л���һ��ͨ�����ȶ�ȡ���л�
//��һ�ζ�ȡ0ͨ��ʱ���Ƚ������ã�+��ʱ����������ȡ������Ҫ
uint16_t ADS1115a_Switch_Channl(uint8_t ch)
{
	static uint8_t flaga = 0;		//��һ����ʱ��ȡ
	s16 AD_value=0;
	
	switch(ch)
	{
		case 0:	
		{
			if(0==flaga)			//������һ�β���+��ʱ
			{
				flaga = 1;
				ADS1115a_Config(CH0);
				delay_ms(100);	//��ʱ
			}			
			AD_value = ADS1115a_Read();		//�ȶ�ȡ��������һͨ��
			delay_us(100);	//��ʱ
			ADS1115a_Config(CH1);
			break;
		}
		case 1:
		{			
			AD_value = ADS1115a_Read();
			delay_us(100);	//��ʱ
			ADS1115a_Config(CH3);
			break;
		}
		case 3:
		{			
			AD_value = ADS1115a_Read();
			delay_us(100);	//��ʱ
			ADS1115a_Config(CH0);
			break;
		}
		default:
			break;		
	}

	return AD_value;
}

//��ʼ��IIC
void ads1115a_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT ;   //�������
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	IIC_SCL1=1;
	IIC_SDA1=1;
}

//ģ��I2C��ʼ������SCL�͵�ƽ��SDA�Ӹߵ��͵�����
void IIC1_Start(void)
{
	SDA1_OUT();     //sda�����
	IIC_SDA1=1;	  	  
	IIC_SCL1=1;
	delay_us(4);
 	IIC_SDA1=0;//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	IIC_SCL1=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	 

//ģ��I2Cֹͣ������SCL�ߵ�ƽ��SDA�ӵ͵��ߵ�����
void IIC1_Stop(void)
{
	SDA1_OUT();//sda�����
	IIC_SCL1=0;
	IIC_SDA1=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	IIC_SCL1=1; 
	IIC_SDA1=1;//����I2C���߽����ź�
	delay_us(4);							   	
}

//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
uint8_t IIC1_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	
	SDA1_IN();      //SDA����Ϊ����  
	IIC_SDA1=1;delay_us(1);	   
	IIC_SCL1=1;delay_us(1);	 
	while(READ_SDA1)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC1_Stop();
			return 1;
		}
	}
	IIC_SCL1=0;//ʱ�����0 	   
	return 0;  
} 

//����ACKӦ��
void IIC1_Ack(void)
{
	IIC_SCL1=0;
	SDA1_OUT();
	IIC_SDA1=0;
	delay_us(2);
	IIC_SCL1=1;
	delay_us(2);
	IIC_SCL1=0;
}

//������ACKӦ��		    
void IIC1_NAck(void)
{
	IIC_SCL1=0;
	SDA1_OUT();
	IIC_SDA1=1;
	delay_us(2);
	IIC_SCL1=1;
	delay_us(2);
	IIC_SCL1=0;
}

//IIC����һ���ֽ�
void IIC1_Send_Byte(uint8_t txd)
{                        
  uint8_t t;  
	
	SDA1_OUT(); 	    
  IIC_SCL1=0;//����ʱ�ӿ�ʼ���ݴ���
	for(t=0;t<8;t++)
	{              
		IIC_SDA1=(txd&0x80)>>7;
		txd<<=1; 	  
		delay_us(2);   //��TEA5767��������ʱ���Ǳ����
		IIC_SCL1=1;
		delay_us(2); 
		IIC_SCL1=0;	
		delay_us(2);
	}	 
}

//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
uint8_t IIC1_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	
	SDA1_IN();//SDA����Ϊ����
  for(i=0;i<8;i++ )
	{
		IIC_SCL1=0; 
		delay_us(2);
		IIC_SCL1=1;
		receive<<=1;
		if(READ_SDA1)receive++;   
		delay_us(1); 
	}					 
	if (!ack)
		IIC1_NAck();//����nACK
	else
		IIC1_Ack(); //����ACK   
	return receive;
}

//����1��ʾʧ��
//uint8_t IIC1_Write_NByte(uint8_t *writebuffer, uint8_t n)
//{
//	uint8_t i;

//	for(i=0;i<n;i++)
//	{
//		IIC1_Send_Byte(*writebuffer);

//		if(IIC1_Wait_Ack())		//0������Ӧ��ɹ�
//		{
//			IIC1_Stop();
//			return 1;
//		}
//		else
//		{
//			writebuffer++;
//		}
//	}
//	IIC1_Stop();	
//	return 0;
//}

/***************END OF FILE***********************************************/
