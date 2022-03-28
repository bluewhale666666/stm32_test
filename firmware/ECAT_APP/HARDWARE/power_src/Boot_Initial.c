#include "Boot_Initial.h"

/*
//��ʼ��ַ 0x0000
0x0000,//����,		�豸ID 2�ֽ�	
0x0002,//����,		������1�ֽ�	
0x0004,//����,		�ϴ����2�ֽ�
0x0006,//����,		�¶��趨ֵ 2�ֽ�
0x0008,//����,		48v��ѹ�趨ֵl 2�ֽ�
0x000a,//����,		48v��ѹ�趨ֵh 2�ֽ�
0x000c,//����,		48v�����趨ֵh 2�ֽ�
0x0010,//����,		24V1��ѹ�趨ֵl,2�ֽ�
0x0012,//����,		24V1��ѹ�趨ֵh,2�ֽ�
0x0014,//����,		24V1�����趨ֵh 2�ֽ�
0x0018,//����,		24V2��ѹ�趨ֵl,2�ֽ�
0x001a,//����,		24V2��ѹ�趨ֵh,2�ֽ�
0x001c,//����,		24V2�����趨ֵ1h,2�ֽ�
0x001e,//����,		24V2�����趨ֵ2h 2�ֽ�	
0x0028,//����,		�ۼƹ���ʱ��4�ֽ�
0x0030,//����,		�汾��	6�ֽ�		1.0.1��1.0.1
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

//������Ϣ��ʼ��
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


//����Ϊ�������ݴ����Ӻ���
//floatתΪ4�ֽ�uint8_t��  
void Change_u16_to_2x8(uint16_t ff, uint8_t *pdata)
{
	uint8_t i;
	union packet16 data16;
	
	data16.a = ff;
	
	for(i=0;i<2;i++)
//		pdata[i] = data16.b[1-i];		//�����
		pdata[i] = data16.b[i];		//С����
}

//2�ֽ�uint8_t��תuint16_t��  
uint16_t Change_2x8_to_u16(uint8_t *pdata)
{
	uint8_t i;
	union packet16 data16;	
	
	for(i=0;i<2;i++)
//		data16.b[i] = pdata[1-i];	//�����
		data16.b[i] = pdata[i];	//С����
		
	return data16.a;
}

//4�ֽ�uint8_t��תu32��
uint32_t Change_4x8_to_u32(uint8_t *pdata)
{
	uint32_t dd=0;

//�����	
	dd |= (uint32_t)pdata[0]<<24;
	dd |= (uint32_t)pdata[1]<<16;
	dd |= (uint32_t)pdata[2]<<8;
	dd |= (uint32_t)pdata[3];
	
	return dd;
}

//4�ֽ�uint8_t��תu32��
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

//index EEROM_Config_Add_Table��ַ������ 
void save_eeprom_int(uint16_t value, uint8_t index)
{
	uint8_t Config_Value_Temp[2];
	
	Change_u16_to_2x8(value,&Config_Value_Temp[0]);
	AT24CXX_Write(EEROM_Config_Add_Table[index],&Config_Value_Temp[0],2);
}

//index EEROM_Config_Add_Table��ַ������
void save_eeprom_u32(uint32_t value, uint8_t index)
{
	uint8_t  b[4];
	
	Change_u32_to_4x8(value, b);
	AT24CXX_Write(EEROM_Config_Add_Table[index],b,4);
}

/*
//4�ֽ�uint8_t��תfloat��
float Change_4x8_to_fdata(unsigned char *pdata)
{
	uint8_t i;
	union packetf fdata;	
	
	for(i=0;i<4;i++)
		fdata.b[i] = pdata[3-i];	//С����
		
	return fdata.a;
}

//length����<=8
void save_eeprom_char(uint8_t *b, uint8_t length, uint8_t index)
{
	AT24CXX_Write(EEROM_Config_Add_Table[index], &b[0], length);
}

//index EEROM_Config_Add_Table��ַ������
void save_eeprom_float(float ff, uint8_t index)
{
	uint8_t  b[4];
	
	Change_fdata_to_4x8(ff, b);
	AT24CXX_Write(EEROM_Config_Add_Table[index],b,4);
}

//floatתΪ4�ֽ�uint8_t��
void Change_fdata_to_4x8(float ff, uint8_t *pdata)
{
	uint8_t i;
	union packetf fdata;
	
	fdata.a = ff;
	
	for(i=0;i<4;i++)
		pdata[i] = fdata.b[3-i];		//С����
}

//4�ֽ�  ABCD>>>>DCBA			DCBA>>>>ABCD
void Change_4x8_DCBA_ABCD(unsigned char *data0, unsigned char *data1)
{
	uint8_t i;
	
	for(i=0;i<4;i++)
		data1[i] = data0[3-i];
}
*/

//CRCУ�麯��			//����ʱ��λ��ǰ����λ�ں�
uint16_t Get_ModbusCRC16(uint8_t *ptr, uint8_t len)
{ 
	uint8_t i; 
	uint16_t crc = 0xFFFF; 	//CRC�Ĵ�����ʼֵ
	
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
				crc ^= 0xA001; 	//������ʽ
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

//CRCУ���飬����CRC��8λ��ǰ����8λ�ں�
uint16_t GetCRC16(uint8_t *ptr, uint8_t len)		//unsigned short CRC_acc
{
	u16 crc=0;
	u8 da;
	while (len-- != 0) 
	{
		da = (u8) (crc >> 8); /* ȡCRC��8λ */
		crc <<= 8; /* ȡCRC��8λ  */
		crc ^= crc_table[da ^ (*ptr)]; 
		ptr++;
	}
	return (crc);	
}

/***************END OF FILE***********************************************/
