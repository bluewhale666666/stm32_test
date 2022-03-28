#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f4xx.h"
//#include "head_conf.h"

#define RELEASE_TEST 1

//#define   BIG_ENDIAN 			SET					//大端序
//#define   LITTLE_ENDIAN		RESET				//小端序
//#define   CURRENT_ENDIAN	BIG_ENDIAN	//当前端序，大端序

#define RXD1_MAX_NUM			100				//USART1接收最大缓存数
#define TXD1_MAX_NUM			100						//USART1接收最大缓存数

#define	CODE3_TIMES				3												//请求指令重发次数

#define ADS1115_CONVERSION_REG      0x00	//Convertion register
#define ADS1115_CONFIG_REG          0x01	//Config register
#define ADS1115_Lo_THRESH_REG       0x02	//Lo_thresh register
#define ADS1115_Ho_THRESH_REG       0x03	//Hi_thresh register

#define ADS1115_ADDR_0  0x90  	//ADDR PIN ->GND
#define ADS1115_ADDR_1  0x92  	//ADDR PIN ->VDD
#define ADS1115_ADDR_2  0x94  	//ADDR PIN ->SDA
#define ADS1115_ADDR_3  0x96  	//ADDR PIN ->SCL

#define CH0 0xc2e3 
#define CH1 0xd2e3
#define CH2 0xe2e3
#define CH3 0xf2e3

#define ADC_Accuracy 		32768   //定义ADC精度，ADS1115单端输入时15位

typedef union
{
	struct 
	{
		uint16_t COMP_QUE 		:2;
		uint16_t COMP_LAT 		:1;
		uint16_t COMP_POL 		:1;
		uint16_t COMP_MODE  	:1;
		uint16_t DR         	:3;  	//转换速率，000:8SPS,001:16SPS,010:32SPS,011:64SPS,100:128SPS(默认),101:250SPS,110:475SPS,111:860SPS
		uint16_t MODE     		:1;  	//0:连续转换模式，1:单个转换模式
		uint16_t PGA        	:3;  	//可编程放大系数000:FSR=6.144V,001:FSR=4.096V,010:FSR=2.048V
		uint16_t MUX        	:3;  	//通道切换100:AIN0,101:AIN1,110:AIN2,111:AIN3
		uint16_t OS         	:1;		//
	}b;
	uint16_t val;
}_DEF_ADS1115_CFG;

//控制状态uint型
//控制状态H字节
typedef union		//由低至高
{
	struct 
	{
		uint8_t SYSTEM_RUN		:1; 	//系统运行
		uint8_t DC48V_OC 			:1; 	//过流防护启动
//		uint8_t DC24V1_FK 		:1; 	//24v反馈输出
//		uint8_t MCON_FKIN 		:1; 	//主控反馈输入
		uint8_t BIT6B		  		:6; 
	}b;
	uint8_t val;
}_DEF_STATE;

//控制状态L字节
typedef union		//由低至高
{
	struct 
	{
		uint8_t DC24V1A  		       :1; 	//24v1a输出
		uint8_t DC24V2A  		       :1; 	//24v2a输出
		uint8_t DC48V_ES_shutdown  :1; 	//48V异常控制
		uint8_t DC24V1_FK 		     :1; 	//示教器指示灯状态
		uint8_t AI_SW1             :1;  //模拟量输入1电流电压切换
	  uint8_t AI_SW2             :1;  //模拟量输入2电流电压切换
		uint8_t BIT2B  			       :2; 
	}b;
	uint8_t val;
}_DEF_CONSTATE;

//故障信息uint型
//故障字节H
typedef union			//由低至高
{
	struct 
	{
//		uint8_t DC24V2_OV		:1; 	//24v2过压
//		uint8_t DC24V2A_OC	:1; 	//24v2A过流
//		uint8_t DC24V2B_OC	:1; 	//24v2B过流
//		uint8_t MCON_FKIN		:1; 	//主控反馈故障
//		uint8_t COMU	 			:1; 	//通讯故障
		uint8_t Res_overheat:1;   //预充电电阻过热
		uint8_t BIT7B				:7; 	//
	}b;
	uint8_t val;
}_DEF_BREAKDOWNH;

//故障字节L
typedef union			//由低至高
{
	struct 
	{
		uint8_t TEMP_H	 		:1; 	//温度过高
		uint8_t DC48V_UV		:1; 	//48v欠压
		uint8_t DC48V_OV		:1; 	//48v过压
		uint8_t DC48V_OC		:1; 	//48v过流
		uint8_t DC24V1_UV		:1; 	//24v1欠压
		uint8_t DC24V1_OV		:1; 	//24v1过压
		uint8_t DC24V1_OC		:1; 	//24v1过流
		uint8_t BIT1				:1;   
//		uint8_t DC24V2_UV		:1; 	//24v2欠压
	}b;
	uint8_t val;
}_DEF_BREAKDOWNL;

//
enum EEPROM_ADDR_INDEX {
	ID,
	UART1_BPS,
	UPLOAD_TIME,	
	TEMP_H,	
	DC48V_UL,
	DC48V_UH,
	DC48V_IH,
	DC24V1_UL,
	DC24V1_UH,	
	DC24V1_IH,
	DC24V2_UL,
	DC24V2_UH,	
	DC24V2_I1H,
	DC24V2_I2H,	
	WORK_TIME,
	VERSION,
	TEST
};

//
union packetf
{
	float a;
	uint8_t  b[4];
};

//
union packet16
{
	uint16_t a;
	uint8_t  b[2];
};

struct POWER_MANAGE_BOARD
{
  uint8_t my_ver_flag;	//
	uint8_t	my_ver[6];
	uint8_t	my_ver_write;	//记录写版本号标志
	uint32_t uart1_bps;		//串口1波特率,注意，存储时只存一个字节
	uint8_t uart1_bps_id;	//存储时的一个字节
	uint16_t upload_time;	//上传时间间隔

	short alarm_cfc;	//consecutive failure count
	
	short temperature_ntc;	//no use in new version
	short temperature_h;
	short temperature_ntc2;

	uint16_t dc48v_uh;
	uint16_t dc48v_ul;
	uint16_t dc48v_u;
	uint16_t dc48v_ih;
	uint16_t dc48v_i;
	uint16_t dc48v_ir;
	uint16_t dc48v_i0;

	uint16_t dc24v1_uh;
	uint16_t dc24v1_ul;
	uint16_t dc24v1_u;
	uint16_t dc24v1_ih;
	uint16_t dc24v1_i;

	uint16_t dc24v2_uh;
	uint16_t dc24v2_ul;
	uint16_t dc24v2_u;
	uint16_t dc24v2_i1h;
	uint16_t dc24v2_i1;
	uint16_t dc24v2_i2h;
	uint16_t dc24v2_i2;

	uint32_t work_time;	
	
	_DEF_STATE p_state;					//控制H
	_DEF_CONSTATE p_constate;		//控制L
	_DEF_BREAKDOWNH p_breakdownh;	//故障H
	_DEF_BREAKDOWNL p_breakdownl;	//故障L
	
	uint8_t work_mode;
	uint8_t test_mode;
};

extern struct POWER_MANAGE_BOARD power_manage;

//UART1
//extern 	uint8_t 	dma_receive_data[RXD1_MAX_NUM];
extern 	uint8_t 	Rxd1_Buff[RXD1_MAX_NUM];
extern 	uint16_t	Rxd1_Da_Num;
extern 	uint8_t 	Rx1Status,Rx1appStatus;
extern 	uint8_t 	Txd1_Buff[TXD1_MAX_NUM];

//时间标志
extern uint8_t time_2s_flag;

extern uint8_t upload_flag;
extern uint8_t ad_fast_flag,ad_slow_flag;
extern uint8_t led_blink_flag;
extern uint8_t adcok_flag;
extern uint16_t fk_times;

extern uint8_t time_ds18b_flag;

//报警出现标志	
extern uint8_t   Alarm_Appear_Flag;

extern 	uint16_t const EEROM_Config_Add_Table[96];
extern  uint32_t const BPS_Table[7];

extern uint8_t send_code3_flag;						//发送请求关机指令
extern uint8_t receive_code3_flag;				//收到请求关机的确认
extern uint8_t receive_code4_flag;				//收到关机指令

extern uint8_t	code3_delay_st; 					//正在延时标志(0-未延时，1-正在延时)
extern uint8_t	poweroff_st; 								//继电器是否吸合状态(0-释放，1-已经吸合)
extern uint16_t	delay_count; 								//在延时时的中断计数器(每5毫秒加一)

extern uint16_t	oc_st_count;								//


extern uint8_t	last_workmode;
extern uint8_t	code3_times;								//重发次数计数

#endif /* __MAIN_H*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
