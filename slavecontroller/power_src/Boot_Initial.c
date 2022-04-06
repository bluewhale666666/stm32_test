#include "Boot_Initial.h"

/*
//起始地址 0x0000
0x0000,//编码,		设备ID 2字节	
0x0002,//编码,		波特率1字节	
0x0004,//编码,		上传间隔2字节
0x0006,//编码,		温度设定值 2字节
0x0008,//编码,		48v电压设定值l 2字节
0x000a,//编码,		48v电压设定值h 2字节
0x000c,//编码,		48v电流设定值h 2字节
0x0010,//编码,		24V1电压设定值l,2字节
0x0012,//编码,		24V1电压设定值h,2字节
0x0014,//编码,		24V1电流设定值h 2字节
0x0018,//编码,		24V2电压设定值l,2字节
0x001a,//编码,		24V2电压设定值h,2字节
0x001c,//编码,		24V2电流设定值1h,2字节
0x001e,//编码,		24V2电流设定值2h 2字节	
0x0028,//编码,		累计工作时间4字节
0x0030,//编码,		版本号	6字节		1.0.1，1.0.1
*/


/** 
   *@brief   The status information is initialized
   *@note    p_constate: Control status Low bytes
					   p_state: Control status High bytes
						 p_breakdownl: Fault information Low bytes
						 p_breakdownh: Fault information High bytes
             work_mode: power work mode
   *@param   none
   *@return  none
   *@author  liu  
   *@date    2021/11/15    
   *@version V1.0.0
   */
void Reload_State_All_Value(void)
{	
	close_all_dr_save_state();			
	power_manage.p_breakdownh.val = 0;	
	power_manage.p_breakdownl.val = 0;	
	power_manage.p_state.val = 0;
	OCPROTECT_DR = 0;										
	power_manage.work_mode=0;						
}

//配置信息初始化
void Reload_Config_All_Value(void)
{
	power_manage.upload_time = 500;
	power_manage.temperature_h = 850;
	power_manage.alarm_cfc = 5;
	power_manage.dc48v_ul = 4300;
	power_manage.dc48v_uh = 6300;
//	power_manage.dc48v_ih = 4000;
	power_manage.dc48v_ih = 0;			//???
	power_manage.dc24v1_ul = 2200;
	power_manage.dc24v1_uh = 2640;
	power_manage.dc24v1_ih = 840;
	power_manage.dc24v2_ul = 2300;
	power_manage.dc24v2_uh = 2800;
	power_manage.dc24v2_i1h = 600;
	power_manage.dc24v2_i2h = 600;
	power_manage.uart1_bps = 19200;
}


//以下为各种数据处理子函数
//float转为4字节uint8_t型  
void Change_u16_to_2x8(uint16_t ff, uint8_t *pdata)
{
	uint8_t i;
	union packet16 data16;
	
	data16.a = ff;
	
	for(i=0;i<2;i++)
//		pdata[i] = data16.b[1-i];		//大端序
		pdata[i] = data16.b[i];		//小端序
}

//2字节uint8_t型转uint16_t型  
uint16_t Change_2x8_to_u16(uint8_t *pdata)
{
	uint8_t i;
	union packet16 data16;	
	
	for(i=0;i<2;i++)
//		data16.b[i] = pdata[1-i];	//大端序
		data16.b[i] = pdata[i];	//小端序
		
	return data16.a;
}

//4字节uint8_t型转u32型
uint32_t Change_4x8_to_u32(uint8_t *pdata)
{
	uint32_t dd=0;

//大端序	
	dd |= (uint32_t)pdata[0]<<24;
	dd |= (uint32_t)pdata[1]<<16;
	dd |= (uint32_t)pdata[2]<<8;
	dd |= (uint32_t)pdata[3];
	
	return dd;
}

//4字节uint8_t型转u32型
void Change_u32_to_4x8(uint32_t uu, uint8_t *pdata)
{
	uint8_t i;
	
	for(i=1;i<4;i++)
	{
		pdata[4-i] = uu&0x000000ff;
		uu = uu>>8;
	}
	pdata[0]=uu&0x000000ff;
}

//index EEROM_Config_Add_Table地址表索引 
void save_eeprom_int(uint16_t value, uint8_t index)
{
	uint8_t Config_Value_Temp[2];
	
	Change_u16_to_2x8(value,&Config_Value_Temp[0]);
	AT24CXX_Write(EEROM_Config_Add_Table[index],&Config_Value_Temp[0],2);
}

//index EEROM_Config_Add_Table地址表索引
void save_eeprom_u32(uint32_t value, uint8_t index)
{
	uint8_t  b[4];
	
	Change_u32_to_4x8(value, b);
	AT24CXX_Write(EEROM_Config_Add_Table[index],b,4);
}

/*
//4字节uint8_t型转float型
float Change_4x8_to_fdata(unsigned char *pdata)
{
	uint8_t i;
	union packetf fdata;	
	
	for(i=0;i<4;i++)
		fdata.b[i] = pdata[3-i];	//小端序
		
	return fdata.a;
}

//length必须<=8
void save_eeprom_char(uint8_t *b, uint8_t length, uint8_t index)
{
	AT24CXX_Write(EEROM_Config_Add_Table[index], &b[0], length);
}

//index EEROM_Config_Add_Table地址表索引
void save_eeprom_float(float ff, uint8_t index)
{
	uint8_t  b[4];
	
	Change_fdata_to_4x8(ff, b);
	AT24CXX_Write(EEROM_Config_Add_Table[index],b,4);
}

//float转为4字节uint8_t型
void Change_fdata_to_4x8(float ff, uint8_t *pdata)
{
	uint8_t i;
	union packetf fdata;
	
	fdata.a = ff;
	
	for(i=0;i<4;i++)
		pdata[i] = fdata.b[3-i];		//小端序
}

//4字节  ABCD>>>>DCBA			DCBA>>>>ABCD
void Change_4x8_DCBA_ABCD(unsigned char *data0, unsigned char *data1)
{
	uint8_t i;
	
	for(i=0;i<4;i++)
		data1[i] = data0[3-i];
}
*/

//CRC校验函数			//发送时低位在前，高位在后
uint16_t Get_ModbusCRC16(uint8_t *ptr, uint8_t len)
{ 
	uint8_t i; 
	uint16_t crc = 0xFFFF; 	//CRC寄存器初始值
	
	if(len==0) 
	{
		len = 1;
	} 
	while(len--)  
	{   
		crc ^= *ptr; 
		for(i=0; i<8; i++)  
		{ 
			if(crc&1) 
			{ 
				crc >>= 1;  
				crc ^= 0xA001; 	//异或多项式
			}  
			else 
			{
				crc >>= 1;
			} 
		}         
		ptr++; 
	}
	
	return(crc); 
}

//CRC校验检查，其中CRC低8位在前，高8位在后；
uint16_t GetCRC16(uint8_t *ptr, uint8_t len)		//unsigned short CRC_acc
{
	u16 crc=0;
	u8 da;
	while (len-- != 0) 
	{
		da = (u8) (crc >> 8); /* 取CRC高8位 */
		crc <<= 8; /* 取CRC低8位  */
		crc ^= crc_table[da ^ (*ptr)]; 
		ptr++;
	}
	return (crc);	
}

/***************END OF FILE***********************************************/
