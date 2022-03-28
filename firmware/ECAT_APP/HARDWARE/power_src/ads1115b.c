#include "ads1115b.h"

#include "main.h"							//������ͷ�ļ�
#include "delay.h"

//sda2   ADS1115_ADDR_1


void ADS1115b_Config(u16 config)
{
	IIC2_Start();
	
	IIC2_Send_Byte(ADS1115_ADDR_1); 	//���ͼĴ���������Ϣ
	IIC2_Wait_Ack();
	
	IIC2_Send_Byte(ADS1115_CONFIG_REG); 
	IIC2_Wait_Ack();

	IIC2_Send_Byte(config>>8);
	IIC2_Wait_Ack();

	IIC2_Send_Byte(config);
	IIC2_Wait_Ack();

	IIC2_Stop();	
	delay_us(100);	//��ʱ
	
	IIC2_Start();//������ʼ�ź�
	
	//ָ��ADS1115ָ��Ĵ�������׼����ȡ����	
	IIC2_Send_Byte(ADS1115_ADDR_1); 	//���ͼĴ���������Ϣ
	IIC2_Wait_Ack();
	
	IIC2_Send_Byte(ADS1115_CONVERSION_REG);
	IIC2_Wait_Ack();

	IIC2_Stop();//����ֹͣ�ź�
}

//
s16 ADS1115b_Read(void)
{
	s16 ad_tmp=0;

	IIC2_Start();

	IIC2_Send_Byte(ADS1115_ADDR_1+1);	//��ָ��
	IIC2_Wait_Ack(); 
	
	ad_tmp |= (uint16_t)IIC2_Read_Byte(1)<<8;
	ad_tmp |= (uint16_t)IIC2_Read_Byte(0);
	IIC2_Stop();//����ֹͣ�ź�

	return ad_tmp;
}

//����ͨ����ȡADCоƬ�����ݣ�һ��ֻ��ȡһ���������л���һ��ͨ�����ȶ�ȡ���л�
//��һ�ζ�ȡ0ͨ��ʱ���Ƚ������ã�+��ʱ����������ȡ������Ҫ
uint16_t ADS1115b_Switch_Channl(uint8_t ch)
{
	static uint8_t flagb = 0;		//��һ����ʱ��ȡ
	s16 AD_value=0;
	
	switch(ch)
	{
		case 0:	
		{
			if(0==flagb)			//������һ�β���+��ʱ
			{
				flagb = 1;
				ADS1115b_Config(CH0);
				delay_ms(100);	//��ʱ
			}			
			AD_value = ADS1115b_Read();		//�ȶ�ȡ��������һͨ��
			delay_us(100);	//��ʱ
			ADS1115b_Config(CH1);
			break;
		}
		case 1:
		{			
			AD_value = ADS1115b_Read();
			delay_us(100);	//��ʱ
			ADS1115b_Config(CH2);
			break;
		}
		case 2:
		{			
			AD_value = ADS1115b_Read();
			delay_us(100);	//��ʱ
			ADS1115b_Config(CH3);
			break;
		}
		case 3:
		{
			AD_value = ADS1115b_Read();
			delay_us(100);	//��ʱ
			ADS1115b_Config(CH0);
			break;
		}
		default:
			break;		
	}

	return AD_value;
}

//��ʼ��IIC
void ads1115b_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   //�������
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	IIC_SCL2=1;
	IIC_SDA2=1;
}

//ģ��I2C��ʼ������SCL�͵�ƽ��SDA�Ӹߵ��͵�����
void IIC2_Start(void)
{
	SDA2_OUT();     //sda�����
	IIC_SDA2=1;	  	  
	IIC_SCL2=1;
	delay_us(4);
 	IIC_SDA2=0;//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	IIC_SCL2=0;//ǯסI2C���ߣ�׼�����ͻ�������� 
}	 

//ģ��I2Cֹͣ������SCL�ߵ�ƽ��SDA�ӵ͵��ߵ�����
void IIC2_Stop(void)
{
	SDA2_OUT();//sda�����
	IIC_SCL2=0;
	IIC_SDA2=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	IIC_SCL2=1; 
	IIC_SDA2=1;//����I2C���߽����ź�
	delay_us(4);							   	
}

//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
uint8_t IIC2_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	
	SDA2_IN();      //SDA����Ϊ����  
	IIC_SDA2=1;delay_us(1);	   
	IIC_SCL2=1;delay_us(1);	 
	while(READ_SDA2)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC2_Stop();
			return 1;
		}
	}
	IIC_SCL2=0;//ʱ�����0 	   
	return 0;  
} 

//����ACKӦ��
void IIC2_Ack(void)
{
	IIC_SCL2=0;
	SDA2_OUT();
	IIC_SDA2=0;
	delay_us(2);
	IIC_SCL2=1;
	delay_us(2);
	IIC_SCL2=0;
}

//������ACKӦ��		    
void IIC2_NAck(void)
{
	IIC_SCL2=0;
	SDA2_OUT();
	IIC_SDA2=1;
	delay_us(2);
	IIC_SCL2=1;
	delay_us(2);
	IIC_SCL2=0;
}

//IIC����һ���ֽ�
void IIC2_Send_Byte(uint8_t txd)
{                        
  uint8_t t;  
	
	SDA2_OUT(); 	    
  IIC_SCL2=0;//����ʱ�ӿ�ʼ���ݴ���
	for(t=0;t<8;t++)
	{              
		IIC_SDA2=(txd&0x80)>>7;
		txd<<=1; 	  
		delay_us(2);   //��TEA5767��������ʱ���Ǳ����
		IIC_SCL2=1;
		delay_us(2); 
		IIC_SCL2=0;	
		delay_us(2);
	}	 
}

//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
uint8_t IIC2_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	
	SDA2_IN();//SDA����Ϊ����
  for(i=0;i<8;i++ )
	{
		IIC_SCL2=0; 
		delay_us(2);
		IIC_SCL2=1;
		receive<<=1;
		if(READ_SDA2)receive++;   
		delay_us(1); 
	}					 
	if (!ack)
		IIC2_NAck();//����nACK
	else
		IIC2_Ack(); //����ACK   
	return receive;
}

//����1��ʾʧ��
uint8_t IIC2_Write_NByte(uint8_t *writebuffer, uint8_t n)
{
	uint8_t i;

	for(i=0;i<n;i++)
	{
		IIC2_Send_Byte(*writebuffer);

		if(IIC2_Wait_Ack())		//0������Ӧ��ɹ�
		{
			IIC2_Stop();
			return 1;
		}
		else
		{
			writebuffer++;
		}
	}
	IIC2_Stop();	
	return 0;
}

/***************END OF FILE***********************************************/
