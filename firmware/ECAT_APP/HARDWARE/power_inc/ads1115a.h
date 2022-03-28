#ifndef __ADS1115A_H
#define __ADS1115A_H

#include "stm32f4xx.h"

#include "sys.h"							//主函数头文件



////IO方向设置
//#define SDA1_IN()  {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)8<<28;}
//#define SDA1_OUT() {GPIOB->CRL&=0X0FFFFFFF;GPIOB->CRL|=(u32)3<<28;}

//IO方向设置
#define SDA1_IN()  {GPIOB->MODER &= ~(3<<(7*2));GPIOB->MODER|=0<<7*2;}
#define SDA1_OUT() {GPIOB->MODER &= ~(3<<(7*2));GPIOB->MODER|=1<<7*2;}

//IO操作函数	 
#define IIC_SCL1    PBout(6) //SCL1
#define IIC_SDA1    PBout(7) //SDA1 
#define READ_SDA1   PBin(7)  //输入SDA1

//IIC所有操作函数
void ads1115a_Init(void);         //初始化IIC的IO口				 
void IIC1_Start(void);				//发送IIC开始信号
void IIC1_Stop(void);	  			//发送IIC停止信号
void IIC1_Send_Byte(uint8_t txd);			//IIC发送一个字节
uint8_t IIC1_Read_Byte(uint8_t ack);//IIC读取一个字节
uint8_t IIC1_Wait_Ack(void); 				//IIC等待ACK信号
void IIC1_Ack(void);					//IIC发送ACK信号
void IIC1_NAck(void);				//IIC不发送ACK信号

void IIC1_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t IIC1_Read_One_Byte(uint8_t daddr,uint8_t addr);	  
uint8_t IIC1_Write_NByte(uint8_t *writebuffer, uint8_t n);

void ADS1115a_Config(u16 config);
s16 ADS1115a_Read(void);
uint16_t ADS1115a_Switch_Channl(uint8_t ch);

#endif //
/***************END OF FILE************************************************************/
