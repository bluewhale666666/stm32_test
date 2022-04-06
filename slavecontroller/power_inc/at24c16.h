#ifndef __AT24C16_H
#define __AT24C16_H

#include "stm32f4xx.h"

#include "main.h"							//������ͷ�ļ�


//IO��������
#define AT_SDA_IN()  {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=8<<12;}
#define AT_SDA_OUT() {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=3<<12;}

//IO��������	 
#define AT_IIC_SCL    PBout(10) //SCL
#define AT_IIC_SDA    PBout(11) //SDA	 
#define AT_READ_SDA   PBin(11)  //����SDA 

#define AT24C01		127
#define AT24C02		255
#define AT24C04		511
#define AT24C08		1023
#define AT24C16		2047
#define AT24C32		4095
#define AT24C64	  8191
#define AT24C128	16383
#define AT24C256	32767  

//Mini STM32������ʹ�õ���24c02�����Զ���EE_TYPEΪAT24C02
//#define EE_TYPE AT24C02
//#define AT24_PAGE 8		//����ҳ�ĳ��� 256=64

#define EE_TYPE AT24C16
#define AT24_PAGE 16		//����ҳ�ĳ��� 256=64

//function define
void AT24C16_Init(void); //��ʼ��IIC

void AT24Cxx_Test(void);

void AT24CXX_NPage_Write(uint16_t Write_Address,uint8_t *Write_Data,uint16_t Write_Len);		//��ҳд����

uint8_t AT24CXX_ReadOneByte(uint16_t ReadAddr);							//ָ����ַ��ȡһ���ֽ�
void AT24CXX_WriteOneByte(uint16_t WriteAddr,uint8_t DataToWrite);		//ָ����ַд��һ���ֽ�
void AT24CXX_WriteLenByte(uint16_t WriteAddr,uint32_t DataToWrite,uint8_t Len);//ָ����ַ��ʼд��ָ�����ȵ�����
uint32_t AT24CXX_ReadLenByte(uint16_t ReadAddr,uint8_t Len);					//ָ����ַ��ʼ��ȡָ����������

void AT24CXX_Write(uint16_t WriteAddr,uint8_t *pBuffer,uint16_t NumToWrite);	//��ָ����ַ��ʼд��ָ�����ȵ�����
void AT24CXX_Read(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead);   	//��ָ����ַ��ʼ����ָ�����ȵ�����


void AT_I2C_Start(void);												//ģ��I2C��ʼ����
void AT_I2C_Stop(void); 												//ģ��I2Cֹͣ����
void AT_I2C_SendByte(uint8_t txd);
uint8_t AT_I2C_Check_ACK(void);
uint8_t AT_I2C_ReadByte(uint8_t ack);

void AT_I2C_Ack(void);
void AT_I2C_NAck(void);


#endif











