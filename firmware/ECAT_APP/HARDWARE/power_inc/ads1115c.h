#ifndef __ADS1115C_H
#define __ADS1115C_H

#include "stm32f4xx.h"

#include "sys.h"							//主函数头文件

////IO方向设置			PB0
//#define SDA3_IN()  {GPIOB->CRL&=0XFFFFFF0F;GPIOB->CRL|=8<<4;}
//#define SDA3_OUT() {GPIOB->CRL&=0XFFFFFF0F;GPIOB->CRL|=3<<4;}

//IO方向设置
#define SDA3_IN()  {GPIOC->MODER &= ~(3<<(9*2));GPIOC->MODER|=0<<9*2;}
#define SDA3_OUT() {GPIOC->MODER &= ~(3<<(9*2));GPIOC->MODER|=1<<9*2;}

//IO操作函数	 
#define IIC_SCL3    PAout(8) //SCL3
#define IIC_SDA3    PCout(9) //SDA3 
#define READ_SDA3   PCin(9)  //输入SDA 

//IIC所有操作函数
void ads1115c_Init(void);         //初始化IIC的IO口				 
void IIC3_Start(void);				//发送IIC开始信号
void IIC3_Stop(void);	  			//发送IIC停止信号
void IIC3_Send_Byte(uint8_t txd);			//IIC发送一个字节
uint8_t IIC3_Read_Byte(uint8_t ack);//IIC读取一个字节
uint8_t IIC3_Wait_Ack(void); 				//IIC等待ACK信号
void IIC3_Ack(void);					//IIC发送ACK信号
void IIC3_NAck(void);				//IIC不发送ACK信号

void IIC3_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t IIC3_Read_One_Byte(uint8_t daddr,uint8_t addr);	  
uint8_t IIC3_Write_NByte(uint8_t *writebuffer, uint8_t n);

uint16_t ADS1115c_Switch_Channl(uint8_t ch);
void ADS1115c_Config(u16 config);
s16 ADS1115c_Read(void);

#endif //
/***************END OF FILE************************************************************/
