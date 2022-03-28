#include "ads1115b.h"

#include "main.h"							//主函数头文件
#include "delay.h"

//sda2   ADS1115_ADDR_1


void ADS1115b_Config(u16 config)
{
	IIC2_Start();
	
	IIC2_Send_Byte(ADS1115_ADDR_1); 	//发送寄存器配置信息
	IIC2_Wait_Ack();
	
	IIC2_Send_Byte(ADS1115_CONFIG_REG); 
	IIC2_Wait_Ack();

	IIC2_Send_Byte(config>>8);
	IIC2_Wait_Ack();

	IIC2_Send_Byte(config);
	IIC2_Wait_Ack();

	IIC2_Stop();	
	delay_us(100);	//延时
	
	IIC2_Start();//发送起始信号
	
	//指向ADS1115指针寄存器用于准备读取数据	
	IIC2_Send_Byte(ADS1115_ADDR_1); 	//发送寄存器配置信息
	IIC2_Wait_Ack();
	
	IIC2_Send_Byte(ADS1115_CONVERSION_REG);
	IIC2_Wait_Ack();

	IIC2_Stop();//发送停止信号
}

//
s16 ADS1115b_Read(void)
{
	s16 ad_tmp=0;

	IIC2_Start();

	IIC2_Send_Byte(ADS1115_ADDR_1+1);	//读指令
	IIC2_Wait_Ack(); 
	
	ad_tmp |= (uint16_t)IIC2_Read_Byte(1)<<8;
	ad_tmp |= (uint16_t)IIC2_Read_Byte(0);
	IIC2_Stop();//发送停止信号

	return ad_tmp;
}

//根据通道读取ADC芯片的数据，一次只读取一个，读完切换下一个通道，先读取再切换
//第一次读取0通道时，先进行配置（+延时），后续读取它不需要
uint16_t ADS1115b_Switch_Channl(uint8_t ch)
{
	static uint8_t flagb = 0;		//第一次延时读取
	s16 AD_value=0;
	
	switch(ch)
	{
		case 0:	
		{
			if(0==flagb)			//开机第一次采样+延时
			{
				flagb = 1;
				ADS1115b_Config(CH0);
				delay_ms(100);	//延时
			}			
			AD_value = ADS1115b_Read();		//先读取再配置下一通道
			delay_us(100);	//延时
			ADS1115b_Config(CH1);
			break;
		}
		case 1:
		{			
			AD_value = ADS1115b_Read();
			delay_us(100);	//延时
			ADS1115b_Config(CH2);
			break;
		}
		case 2:
		{			
			AD_value = ADS1115b_Read();
			delay_us(100);	//延时
			ADS1115b_Config(CH3);
			break;
		}
		case 3:
		{
			AD_value = ADS1115b_Read();
			delay_us(100);	//延时
			ADS1115b_Config(CH0);
			break;
		}
		default:
			break;		
	}

	return AD_value;
}

//初始化IIC
void ads1115b_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   //推挽输出
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	IIC_SCL2=1;
	IIC_SDA2=1;
}

//模拟I2C开始函数，SCL低电平，SDA从高到低的跳变
void IIC2_Start(void)
{
	SDA2_OUT();     //sda线输出
	IIC_SDA2=1;	  	  
	IIC_SCL2=1;
	delay_us(4);
 	IIC_SDA2=0;//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	IIC_SCL2=0;//钳住I2C总线，准备发送或接收数据 
}	 

//模拟I2C停止函数，SCL高电平，SDA从低到高的跳变
void IIC2_Stop(void)
{
	SDA2_OUT();//sda线输出
	IIC_SCL2=0;
	IIC_SDA2=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	IIC_SCL2=1; 
	IIC_SDA2=1;//发送I2C总线结束信号
	delay_us(4);							   	
}

//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
uint8_t IIC2_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	
	SDA2_IN();      //SDA设置为输入  
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
	IIC_SCL2=0;//时钟输出0 	   
	return 0;  
} 

//产生ACK应答
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

//不产生ACK应答		    
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

//IIC发送一个字节
void IIC2_Send_Byte(uint8_t txd)
{                        
  uint8_t t;  
	
	SDA2_OUT(); 	    
  IIC_SCL2=0;//拉低时钟开始数据传输
	for(t=0;t<8;t++)
	{              
		IIC_SDA2=(txd&0x80)>>7;
		txd<<=1; 	  
		delay_us(2);   //对TEA5767这三个延时都是必须的
		IIC_SCL2=1;
		delay_us(2); 
		IIC_SCL2=0;	
		delay_us(2);
	}	 
}

//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
uint8_t IIC2_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	
	SDA2_IN();//SDA设置为输入
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
		IIC2_NAck();//发送nACK
	else
		IIC2_Ack(); //发送ACK   
	return receive;
}

//返回1表示失败
uint8_t IIC2_Write_NByte(uint8_t *writebuffer, uint8_t n)
{
	uint8_t i;

	for(i=0;i<n;i++)
	{
		IIC2_Send_Byte(*writebuffer);

		if(IIC2_Wait_Ack())		//0，接收应答成功
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
