#ifndef __ADS1115B_H
#define __ADS1115B_H

#include "stm32f4xx.h"

#include "sys.h"							//主函数头文件


////IO方向设置
//#define SDA2_IN()  {GPIOB->CRL&=0XFF0FFFFF;GPIOB->CRL|=8<<20;}
//#define SDA2_OUT() {GPIOB->CRL&=0XFF0FFFFF;GPIOB->CRL|=3<<20;}


//IO方向设置
#define SDA2_IN()  {GPIOB->MODER &= ~(3<<(11*2));GPIOB->MODER|=0<<11*2;}
#define SDA2_OUT() {GPIOB->MODER &= ~(3<<(11*2));GPIOB->MODER|=1<<11*2;}

//IO操作函数	 
#define IIC_SCL2    PBout(10) //SCL3
#define IIC_SDA2    PBout(11) //SDA3 
#define READ_SDA2   PBin(11)  //输入SDA 

//IIC所有操作函数
void ads1115b_Init(void);         //初始化IIC的IO口				 
void IIC2_Start(void);				//发送IIC开始信号
void IIC2_Stop(void);	  			//发送IIC停止信号
void IIC2_Send_Byte(uint8_t txd);			//IIC发送一个字节
uint8_t IIC2_Read_Byte(uint8_t ack);//IIC读取一个字节
uint8_t IIC2_Wait_Ack(void); 				//IIC等待ACK信号
void IIC2_Ack(void);					//IIC发送ACK信号
void IIC2_NAck(void);				//IIC不发送ACK信号

void IIC2_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t IIC2_Read_One_Byte(uint8_t daddr,uint8_t addr);	  
uint8_t IIC2_Write_NByte(uint8_t *writebuffer, uint8_t n);

uint16_t ADS1115b_Switch_Channl(uint8_t ch);

uint16_t ADS1115b_Switch_Analog1Voltage(void);
uint16_t ADS1115b_Switch_Analog2Voltage(void);
uint16_t ADS1115b_Switch_Analog1Current(void);
uint16_t ADS1115b_Switch_Analog2Current(void);

void ADS1115b_Config(u16 config);
s16 ADS1115b_Read(void);

#endif //
/***************END OF FILE************************************************************/
