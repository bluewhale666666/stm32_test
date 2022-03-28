#ifndef __ADS1115C_H
#define __ADS1115C_H

#include "stm32f4xx.h"

#include "sys.h"							//������ͷ�ļ�

////IO��������			PB0
//#define SDA3_IN()  {GPIOB->CRL&=0XFFFFFF0F;GPIOB->CRL|=8<<4;}
//#define SDA3_OUT() {GPIOB->CRL&=0XFFFFFF0F;GPIOB->CRL|=3<<4;}

//IO��������
#define SDA3_IN()  {GPIOC->MODER &= ~(3<<(9*2));GPIOC->MODER|=0<<9*2;}
#define SDA3_OUT() {GPIOC->MODER &= ~(3<<(9*2));GPIOC->MODER|=1<<9*2;}

//IO��������	 
#define IIC_SCL3    PAout(8) //SCL3
#define IIC_SDA3    PCout(9) //SDA3 
#define READ_SDA3   PCin(9)  //����SDA 

//IIC���в�������
void ads1115c_Init(void);         //��ʼ��IIC��IO��				 
void IIC3_Start(void);				//����IIC��ʼ�ź�
void IIC3_Stop(void);	  			//����IICֹͣ�ź�
void IIC3_Send_Byte(uint8_t txd);			//IIC����һ���ֽ�
uint8_t IIC3_Read_Byte(uint8_t ack);//IIC��ȡһ���ֽ�
uint8_t IIC3_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC3_Ack(void);					//IIC����ACK�ź�
void IIC3_NAck(void);				//IIC������ACK�ź�

void IIC3_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t IIC3_Read_One_Byte(uint8_t daddr,uint8_t addr);	  
uint8_t IIC3_Write_NByte(uint8_t *writebuffer, uint8_t n);

uint16_t ADS1115c_Switch_Channl(uint8_t ch);
void ADS1115c_Config(u16 config);
s16 ADS1115c_Read(void);

#endif //
/***************END OF FILE************************************************************/
