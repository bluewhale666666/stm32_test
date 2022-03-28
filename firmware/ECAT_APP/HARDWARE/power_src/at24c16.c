#include "at24c16.h" 

#include "sys.h"							//������ͷ�ļ�
#include "delay.h"

//AT24C16 �ڲ��ռ��0x0000��ʼ
//1KB=1024B��1MB=1024KB=1024��1024B��
//1B��byte���ֽڣ�= 8 bit

//AT24Cxx�洢������ַ����
//at24c02 = 0x800			=0x100 Byte
//at24c04 = 0x1000
//at24c08 = 0x2000
//at24c16 = 0x4000
//at24c32 = 0x8000		=0x1000 Byte
//at24c64 = 0x10000
//at24c256= 0x40000
//at24c512= 0x80000		=0x10000 Byte


//AT24Cxx��ʼ��
void AT24C16_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(	RCC_AHB1Periph_GPIOC, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT ;   //�������
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	AT_IIC_SCL=1;
	AT_IIC_SDA=1;
}

//AT24C512д���ݴ�������֧�ֿ�ҳд����
void AT24CXX_NPage_Write(uint16_t Write_Address,uint8_t *Write_Data,uint16_t Write_Len)
{
	uint16_t j,p=0;
	uint16_t temp;
	uint16_t Write_Address_0,Write_Address_begin,Write_Address_end,Write_Len_temp;
	uint16_t Write_Times;

	temp = AT24_PAGE-(Write_Address%AT24_PAGE);
	Write_Address_0 = Write_Address + temp;
	Write_Times = Write_Len/AT24_PAGE;

	if(Write_Times>0)		//���ȴ���128
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
	else					//����С�ڵ���128
	{
		if(Write_Len<=temp)	//����ҳ
		{
			AT24CXX_Write(Write_Address,&Write_Data[0],temp);
		}
		else   		//��Ҫ��ҳ
		{
			AT24CXX_Write(Write_Address,&Write_Data[0],temp);
			p = temp;
			AT24CXX_Write(Write_Address_0,&Write_Data[p],(Write_Len-temp));
		}
	}
}


//��AT24CXXָ����ַ����һ������
//ReadAddr:��ʼ�����ĵ�ַ  
//����ֵ  :����������
uint8_t AT24CXX_ReadOneByte(uint16_t ReadAddr)
{				  
	uint8_t temp=0;	
	
  AT_I2C_Start();  
	
	if(EE_TYPE>AT24C16)
	{
		AT_I2C_SendByte(0XA0);	   //����д����
		AT_I2C_Check_ACK();
		AT_I2C_SendByte(ReadAddr>>8);//���͸ߵ�ַ
		AT_I2C_Check_ACK();		 
	}
	else 
	{
		AT_I2C_SendByte(0XA0+((ReadAddr/256)<<1));   //����������ַ0XA0,д���� 	 
	}
	AT_I2C_Check_ACK(); 
	
	AT_I2C_SendByte(ReadAddr%256);   //���͵͵�ַ
	AT_I2C_Check_ACK();	  
  
	AT_I2C_Start();  	 	   
	AT_I2C_SendByte(0XA1);           //�������ģʽ			   
	AT_I2C_Check_ACK();	
	
  temp=AT_I2C_ReadByte(0);		   
  AT_I2C_Stop();//����һ��ֹͣ����	
	
	return temp;
}

//��AT24CXXָ����ַд��һ������
//WriteAddr  :д�����ݵ�Ŀ�ĵ�ַ    
//DataToWrite:Ҫд�������
void AT24CXX_WriteOneByte(uint16_t WriteAddr,uint8_t DataToWrite)
{				   	  	    																 
 	AT_I2C_Start();															//I2C���߿�ʼ
	
	if(EE_TYPE>AT24C16)
	{
		AT_I2C_SendByte(0XA0);	    //����д����
		AT_I2C_Check_ACK();
		AT_I2C_SendByte(WriteAddr>>8);//���͸ߵ�ַ
 	}
	else
	{
		AT_I2C_SendByte(0XA0+((WriteAddr/256)<<1));   //����������ַ0XA0,д���� 
	}	 
	AT_I2C_Check_ACK();	 
  
  AT_I2C_SendByte(WriteAddr%256);   //���͵͵�ַ
	AT_I2C_Check_ACK(); 
	
	AT_I2C_SendByte(DataToWrite);     //�����ֽ�							   
	AT_I2C_Check_ACK(); 
	
  AT_I2C_Stop();
	delay_ms(5);	 
}

//��AT24CXX�����ָ����ַ��ʼ����ָ������������
//ReadAddr :��ʼ�����ĵ�ַ ��24c02Ϊ0~255
//pBuffer  :���������׵�ַ
//NumToRead:Ҫ�������ݵĸ���
void AT24CXX_Read(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead)
{
	while(NumToRead)
	{
		*pBuffer++=AT24CXX_ReadOneByte(ReadAddr++);	
		NumToRead--;
	}
}  
//��AT24CXX�����ָ����ַ��ʼд��ָ������������
//WriteAddr :��ʼд��ĵ�ַ ��24c02Ϊ0~255
//pBuffer   :���������׵�ַ
//NumToWrite:Ҫд�����ݵĸ���
void AT24CXX_Write(uint16_t WriteAddr,uint8_t *pBuffer,uint16_t NumToWrite)
{
	while(NumToWrite--)
	{
		AT24CXX_WriteOneByte(WriteAddr,*pBuffer);
		WriteAddr++;
		pBuffer++;
	}
}


//��AT24CXX�����ָ����ַ��ʼд�볤��ΪLen������
//�ú�������д��16bit����32bit������.
//WriteAddr  :��ʼд��ĵ�ַ  
//DataToWrite:���������׵�ַ
//Len        :Ҫд�����ݵĳ���2,4
void AT24CXX_WriteLenByte(uint16_t WriteAddr,uint32_t DataToWrite,uint8_t Len)
{  	
	uint8_t t;
	for(t=0;t<Len;t++)
	{
		AT24CXX_WriteOneByte(WriteAddr+t,(DataToWrite>>(8*t))&0xff);
	}												    
}

//��AT24CXX�����ָ����ַ��ʼ��������ΪLen������
//�ú������ڶ���16bit����32bit������.
//ReadAddr   :��ʼ�����ĵ�ַ 
//����ֵ     :����
//Len        :Ҫ�������ݵĳ���2,4
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

//ģ��I2C��ʼ������SCL�͵�ƽ��SDA�Ӹߵ��͵�����
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

//ģ��I2Cֹͣ������SCL�ߵ�ƽ��SDA�ӵ͵��ߵ�����
void AT_I2C_Stop(void)
{
//	AT_SDA_OUT();
	
	AT_IIC_SCL=0;
	AT_IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	AT_IIC_SCL=1; 
	AT_IIC_SDA=1;//����I2C���߽����ź�
	delay_us(4);							   	
}



//ģ��I2C����һ�ֽں�����ģ��I2C����һ�ֽں�����SCL�͵�ƽSDA׼�����ݣ�SCL�ߵ�ƽSDA��ȡ����
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

//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
uint8_t AT_I2C_Check_ACK(void)
{
	uint8_t ucErrTime=0;
	
//	AT_SDA_IN();      //SDA����Ϊ����  
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
	AT_IIC_SCL=0;//ʱ�����0 	   
	return 0;  
}

uint8_t AT_I2C_ReadByte(uint8_t ack)
{
	unsigned char i,receive=0;
	
//	AT_SDA_IN();//SDA����Ϊ����
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
			AT_I2C_NAck();//����nACK
	else
			AT_I2C_Ack(); //����ACK   
	return receive;
}


//ģ��I2C����ACK����,SCL��9�����壬SDA�͵�ƽ���
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

//ģ��I2C����NACK����,SCL��9�����壬SDA�ߵ�ƽ���
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

//	printf("д������\n\r");

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

//	printf("\n\r����������\r\n");

	AT24CXX_Read(0x50,&I2c_Buf_Read[0],100);

	for(i=0;i<100;i++)
	{
		if(I2c_Buf_Read[i] != I2c_Buf_Write[i])
		{
//		printf("0x%02X ",I2c_Buf_Read[i]);
			printf("����:I2C EEPROMд����������ݲ�һ��\r\n");
			return;
		}
//		printf("0x%02X ",I2c_Buf_Read[i]);
//		if(i%16 == 15)
//		{
//			printf("\r\n");
//		}
	}
	printf("\r\n��д����ͨ��PASSED\r\n");
}

*/
