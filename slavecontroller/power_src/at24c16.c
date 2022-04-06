#include "at24c16.h" 

#include "sys.h"							//主函数头文件
#include "delay.h"

//AT24C16 内部空间从0x0000开始
//1KB=1024B；1MB=1024KB=1024×1024B。
//1B（byte，字节）= 8 bit

//AT24Cxx存储参数地址定义
//at24c02 = 0x800			=0x100 Byte
//at24c04 = 0x1000
//at24c08 = 0x2000
//at24c16 = 0x4000
//at24c32 = 0x8000		=0x1000 Byte
//at24c64 = 0x10000
//at24c256= 0x40000
//at24c512= 0x80000		=0x10000 Byte


//AT24Cxx初始化
void AT24C16_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(	RCC_AHB1Periph_GPIOC, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT ;   //推挽输出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	AT_IIC_SCL=1;
	AT_IIC_SDA=1;
}

//AT24C512写数据串函数，支持跨页写操作
void AT24CXX_NPage_Write(uint16_t Write_Address,uint8_t *Write_Data,uint16_t Write_Len)
{
	uint16_t j,p=0;
	uint16_t temp;
	uint16_t Write_Address_0,Write_Address_begin,Write_Address_end,Write_Len_temp;
	uint16_t Write_Times;

	temp = AT24_PAGE-(Write_Address%AT24_PAGE);
	Write_Address_0 = Write_Address + temp;
	Write_Times = Write_Len/AT24_PAGE;

	if(Write_Times>0)		//长度大于128
	{
		AT24CXX_Write(Write_Address,&Write_Data[0],temp);
		p = temp;
		Write_Address_begin = Write_Address_0;
		Write_Address_end = Write_Address_0+Write_Len-temp;
		for(j=0;j<Write_Times;j++)
		{
		  if((Write_Address_begin+AT24_PAGE) <= Write_Address_end)
			{
				AT24CXX_Write(Write_Address_begin,&Write_Data[p],AT24_PAGE);
				p = p+AT24_PAGE;
				Write_Address_begin += AT24_PAGE;
			}
		}
		Write_Len_temp = Write_Address_end-Write_Address_begin;
		AT24CXX_Write(Write_Address_begin,&Write_Data[p],Write_Len_temp);
	}
	else					//长度小于等于128
	{
		if(Write_Len<=temp)	//不跨页
		{
			AT24CXX_Write(Write_Address,&Write_Data[0],temp);
		}
		else   		//需要跨页
		{
			AT24CXX_Write(Write_Address,&Write_Data[0],temp);
			p = temp;
			AT24CXX_Write(Write_Address_0,&Write_Data[p],(Write_Len-temp));
		}
	}
}


//在AT24CXX指定地址读出一个数据
//ReadAddr:开始读数的地址  
//返回值  :读到的数据
uint8_t AT24CXX_ReadOneByte(uint16_t ReadAddr)
{				  
	uint8_t temp=0;	
	
  AT_I2C_Start();  
	
	if(EE_TYPE>AT24C16)
	{
		AT_I2C_SendByte(0XA0);	   //发送写命令
		AT_I2C_Check_ACK();
		AT_I2C_SendByte(ReadAddr>>8);//发送高地址
		AT_I2C_Check_ACK();		 
	}
	else 
	{
		AT_I2C_SendByte(0XA0+((ReadAddr/256)<<1));   //发送器件地址0XA0,写数据 	 
	}
	AT_I2C_Check_ACK(); 
	
	AT_I2C_SendByte(ReadAddr%256);   //发送低地址
	AT_I2C_Check_ACK();	  
  
	AT_I2C_Start();  	 	   
	AT_I2C_SendByte(0XA1);           //进入接收模式			   
	AT_I2C_Check_ACK();	
	
  temp=AT_I2C_ReadByte(0);		   
  AT_I2C_Stop();//产生一个停止条件	
	
	return temp;
}

//在AT24CXX指定地址写入一个数据
//WriteAddr  :写入数据的目的地址    
//DataToWrite:要写入的数据
void AT24CXX_WriteOneByte(uint16_t WriteAddr,uint8_t DataToWrite)
{				   	  	    																 
 	AT_I2C_Start();															//I2C总线开始
	
	if(EE_TYPE>AT24C16)
	{
		AT_I2C_SendByte(0XA0);	    //发送写命令
		AT_I2C_Check_ACK();
		AT_I2C_SendByte(WriteAddr>>8);//发送高地址
 	}
	else
	{
		AT_I2C_SendByte(0XA0+((WriteAddr/256)<<1));   //发送器件地址0XA0,写数据 
	}	 
	AT_I2C_Check_ACK();	 
  
  AT_I2C_SendByte(WriteAddr%256);   //发送低地址
	AT_I2C_Check_ACK(); 
	
	AT_I2C_SendByte(DataToWrite);     //发送字节							   
	AT_I2C_Check_ACK(); 
	
  AT_I2C_Stop();
	delay_ms(5);	 
}

//在AT24CXX里面的指定地址开始读出指定个数的数据
//ReadAddr :开始读出的地址 对24c02为0~255
//pBuffer  :数据数组首地址
//NumToRead:要读出数据的个数
void AT24CXX_Read(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead)
{
	while(NumToRead)
	{
		*pBuffer++=AT24CXX_ReadOneByte(ReadAddr++);	
		NumToRead--;
	}
}  
//在AT24CXX里面的指定地址开始写入指定个数的数据
//WriteAddr :开始写入的地址 对24c02为0~255
//pBuffer   :数据数组首地址
//NumToWrite:要写入数据的个数
void AT24CXX_Write(uint16_t WriteAddr,uint8_t *pBuffer,uint16_t NumToWrite)
{
	while(NumToWrite--)
	{
		AT24CXX_WriteOneByte(WriteAddr,*pBuffer);
		WriteAddr++;
		pBuffer++;
	}
}


//在AT24CXX里面的指定地址开始写入长度为Len的数据
//该函数用于写入16bit或者32bit的数据.
//WriteAddr  :开始写入的地址  
//DataToWrite:数据数组首地址
//Len        :要写入数据的长度2,4
void AT24CXX_WriteLenByte(uint16_t WriteAddr,uint32_t DataToWrite,uint8_t Len)
{  	
	uint8_t t;
	for(t=0;t<Len;t++)
	{
		AT24CXX_WriteOneByte(WriteAddr+t,(DataToWrite>>(8*t))&0xff);
	}												    
}

//在AT24CXX里面的指定地址开始读出长度为Len的数据
//该函数用于读出16bit或者32bit的数据.
//ReadAddr   :开始读出的地址 
//返回值     :数据
//Len        :要读出数据的长度2,4
uint32_t AT24CXX_ReadLenByte(uint16_t ReadAddr,uint8_t Len)
{  	
	uint8_t t;
	uint32_t temp=0;
	for(t=0;t<Len;t++)
	{
		temp<<=8;
		temp+=AT24CXX_ReadOneByte(ReadAddr+Len-t-1); 	 				   
	}
	return temp;												    
}

//模拟I2C开始函数，SCL低电平，SDA从高到低的跳变
void AT_I2C_Start(void)
{
//	AT_SDA_OUT();
	
	AT_IIC_SDA=1;	
	AT_IIC_SCL=1;
	delay_us(4);
	AT_IIC_SDA=0;	
	delay_us(4);
	AT_IIC_SCL=0;
}

//模拟I2C停止函数，SCL高电平，SDA从低到高的跳变
void AT_I2C_Stop(void)
{
//	AT_SDA_OUT();
	
	AT_IIC_SCL=0;
	AT_IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	AT_IIC_SCL=1; 
	AT_IIC_SDA=1;//发送I2C总线结束信号
	delay_us(4);							   	
}



//模拟I2C发送一字节函数，模拟I2C接收一字节函数，SCL低电平SDA准备数据，SCL高电平SDA读取数据
void AT_I2C_SendByte(uint8_t txd)
{
	uint8_t temp;
	
//AT_SDA_OUT();
	AT_IIC_SCL=0;	
 	for(temp=0;temp<8;temp++)
	{
		AT_IIC_SDA=(txd&0x80)>>7;
		txd<<=1;
		delay_us(2);
		AT_IIC_SCL=1;
		delay_us(2); 
		AT_IIC_SCL=0;	
		delay_us(2);
		
	}
}

//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
uint8_t AT_I2C_Check_ACK(void)
{
	uint8_t ucErrTime=0;
	
//	AT_SDA_IN();      //SDA设置为输入  
	AT_IIC_SDA=1;	delay_us(1);
	AT_IIC_SCL=1;	delay_us(1);
	while(AT_READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			AT_I2C_Stop();
			return 1;
		}
	}
	AT_IIC_SCL=0;//时钟输出0 	   
	return 0;  
}

uint8_t AT_I2C_ReadByte(uint8_t ack)
{
	unsigned char i,receive=0;
	
//	AT_SDA_IN();//SDA设置为输入
  for(i=0;i<8;i++ )
	{
		AT_IIC_SCL=0;
		delay_us(2);
		AT_IIC_SCL=1;
		receive<<=1;
    if(AT_READ_SDA) 
			receive++;  
		delay_us(1); 
  }					 
	if (!ack)
			AT_I2C_NAck();//发送nACK
	else
			AT_I2C_Ack(); //发送ACK   
	return receive;
}


//模拟I2C设置ACK函数,SCL第9个脉冲，SDA低电平输出
void AT_I2C_Ack(void)
{
	AT_IIC_SCL=0;
//	AT_SDA_OUT();
	AT_IIC_SDA=0;
	delay_us(2);
	AT_IIC_SCL=1;
	delay_us(2);
	AT_IIC_SCL=0;
}

//模拟I2C设置NACK函数,SCL第9个脉冲，SDA高电平输出
void AT_I2C_NAck(void)
{
	AT_IIC_SCL=0;
//	AT_SDA_OUT();
	AT_IIC_SDA=1;
	delay_us(2);
	AT_IIC_SCL=1;
	delay_us(2);
	AT_IIC_SCL=0;
}

/*

//
void AT24Cxx_Test(void)
{
	uint8_t i;
	uint8_t I2c_Buf_Write[256];
	uint8_t I2c_Buf_Read[256];

//	printf("写入数据\n\r");

	for(i=0;i<100;i++)
	{
		I2c_Buf_Write[i] = i+32;
//		printf("0x%02X ",I2c_Buf_Write[i]);
//		if(i%16 == 15)
//		{
//			printf("\n\r");
//		}
	}
	AT24CXX_NPage_Write(0x50,&I2c_Buf_Write[0],100);

//	printf("\n\r读出的数据\r\n");

	AT24CXX_Read(0x50,&I2c_Buf_Read[0],100);

	for(i=0;i<100;i++)
	{
		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
		{
//		printf("0x%02X ",I2c_Buf_Read[i]);
			printf("错误:I2C EEPROM写入与读出数据不一样\r\n");
			return;
		}
//		printf("0x%02X ",I2c_Buf_Read[i]);
//		if(i%16 == 15)
//		{
//			printf("\r\n");
//		}
	}
	printf("\r\n读写测试通过PASSED\r\n");
}

*/
