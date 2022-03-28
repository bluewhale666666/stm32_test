#include "Recieve_Send_Command_Done.h"

#include "string.h"					//memcpy

#include "usart.h"
#include "stmflash.h"
#include "iap.h"
#include "ds18b20.h"
#include "Boot_Initial.h"


//
uint8_t const soi[4]={0xff,0xaa,0xaa,0xff};
uint8_t const eoi[4]={0xee,0x55,0x55,0xee};
//


//处理接收到得数据
void USART1_Data_Recieve(void)
{	
	uint8_t 	i,j;
	uint8_t 	Current_Data_Num;
	uint8_t		Rx_Data[RXD1_MAX_NUM],Wr_data[50];
	uint8_t 	frame_code;	
	uint8_t 	info_len;	
	
	uint8_t data_manage_flag=0;		//数据处理标志，每次都是初始值0（即默认不处理）
	
//	if((1==Rx1Status)&&(1==Rx1appStatus))  			//接收app代码
//	{
//		Rx1Status=0;
//		Rx1appStatus=0;
//		
//		IAP_WriteBin(FLASH_DOWNLOAD_ADDR,Rxd1_Buff,Rxd1_Da_Num);		//里面有复位单片机函数，注释掉，不让随便复位，等待关机
//		memset(Rxd1_Buff,0,Rxd1_Da_Num);														//清空数组
//		Rxd1_Da_Num = 0;			
//	}	
	
	if(1==Rx1Status)  			//接收完成标志=1处理，否则退出
	{
		Rx1Status = 0;
	
		if(Rxd1_Da_Num>=12)			//当前数据长度>=12
		{
			Current_Data_Num = Rxd1_Da_Num;				//接收长度
			for(i=0;i<Current_Data_Num;i++)				//转存数据，并且清空接收数组
			{
				Rx_Data[i] = Rxd1_Buff[i];
				Rxd1_Buff[i] = 0;
			}			
			data_manage_flag = 1;
		}
		Rxd1_Da_Num = 0;		//完成后清接收长度
	}
	
	if(data_manage_flag)	//接收到合适的数据包才进入下面的处理函数
	{
		for(i=0;i<20;i++)
		{
			//对自己ID操作
			if((Rx_Data[i]==soi[0])&&(Rx_Data[i+1]==soi[1])&&(Rx_Data[i+2]==soi[2])&&(Rx_Data[i+3]==soi[3])&&(Rx_Data[i+4]<0x1f))	//数据帧头和功能码
			{
				info_len = Rx_Data[i+5];
				if((Rx_Data[i+info_len+8]==eoi[0])&&(Rx_Data[i+info_len+9]==eoi[1])&&(Rx_Data[i+info_len+10]==eoi[2])&&(Rx_Data[i+info_len+11]==eoi[3]))
				{
					//CRC校验正确		低字节在前，高字节在后
					if(GetCRC16(&Rx_Data[i],info_len+6)==((uint16_t)Rx_Data[i+info_len+6]|(((uint16_t)Rx_Data[i+info_len+7]<<8)&0xff00)))
					{
						frame_code = Rx_Data[i+4];		//获取帧类型
						
						if(info_len)
						{
							for(j=0;j<info_len;j++)
							{
								Wr_data[j] = Rx_Data[i+j+6];					
							}							
							data_frame_code_handle(frame_code, &Wr_data[0], info_len);
						}
						else		//长度区为0，即无数据区
						{
							query_frame_code_handle(frame_code);							
						}
						break;
					}
				}
			}
		}
	}
}

//处理，命令帧02 08 0a 0b  03(请求后的确认)
//02-处理控制指令
//03-收到请求关机的确认帧
//04-收到关机指令
//

void data_frame_code_handle(uint8_t code, uint8_t *pdata, uint8_t len)
{
	switch(code)
	{
		case 2:		//控制指令 
		{
			if(2==len)
			{
				//uint  顺序  L,H低字节在前
				
		//		pdata[0] = pdata[0]|0x02;		//控制命令不能把主控制器关闭
					pdata[0] = pdata[0]|0x09;		//控制命令不能把主控制器、示教器灯、48V异常MOS关闭
				
				save_control_state_to_dr(pdata[0]);
				
				usart1_save_cmd_ok(pdata);		
					
			}		
			break;
		}
		case 3:		//请求后的确认
		{	
			if(1==pdata[0])
			{
				if(4==power_manage.work_mode)
				{
					send_code3_flag = 0;		//clear send flag  
					code3_times = 0;		//clear send times
					receive_code3_flag = 1;
					power_manage.work_mode = 5;					
				}
//				else
//				{
//					receive_code3_flag = 0;
//				}
//				power_manage.work_mode = 5;
//				receive_poweroff_flag = 1;			//已收到，回到mode=0时 复位receive_poweroff_flag = 0;	
			}
			break;			
		}
		case 4:		//确认关机指令
		{	
			if(1==pdata[0])
			{
//				if(5==power_manage.work_mode)
//				{
					power_manage.work_mode = 5;
					usart1_reply_code4_cmd();
					receive_code4_flag = 1;			//mode=0,复位receive_code4_flag = 0;
				
//				}
			}
			break;			
		}
		case 5:   //重启指令
		{
			if(1==pdata[0])
			{
				usart1_reply_code5_cmd();
				delay_ms(10000);
				force_shutdown(1);			
			}	
			break;
		}
		case 6:	//normal shutdown
		{
			if(1==pdata[0])
			{
				delay_ms(10000);
				force_shutdown(0);	
			}	
			break;
		}
		default:
			break;		
	}
}


//返回控制命令数据的通讯帧  2btye
//
void usart1_save_cmd_ok(uint8_t *data)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;	
	
	memcpy(send_frame,soi,4);				
	send_frame[4] = 2;
	send_frame[5] = 0x02;
	send_frame[6] = data[0];
	send_frame[7] = data[1];				
	
	CRC16Temp = GetCRC16(send_frame, 8);
	send_frame[8] = CRC16Temp & 0xff; 				//低字节
	send_frame[9] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[10],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,14);
}

//返回无回复数据的通讯帧
void usart1_save_ok_none_data(uint8_t code)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;	
	
	memcpy(send_frame,soi,4);				
	send_frame[4] = code;
	send_frame[5] = 0x00;
	
	CRC16Temp = GetCRC16(send_frame, 6);
	send_frame[6] = CRC16Temp & 0xff; 				//低字节
	send_frame[7] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[8],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,12);
}

//返回bps数据的通讯帧  00 01 02 03 04 05 06
void usart1_save_bps_ok(uint8_t data)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;	
	
	memcpy(send_frame,soi,4);				
	send_frame[4] = 10;
	send_frame[5] = 0x01;
	send_frame[6] = data;
	
	CRC16Temp = GetCRC16(send_frame, 7);
	send_frame[7] = CRC16Temp & 0xff; 				//低字节
	send_frame[8] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[9],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,13);	
}


//处理，查询帧 01 07 09 0c 10
void query_frame_code_handle(uint8_t code)
{
	switch(code)
	{
		case 1:			//查询数据和状态		20byte
		{	
			usart1_send_upload_data();			
			break;
		}
		case 7:			//查询阈值		24byte
		{	
			usart1_send_threshold();			
			break;
		}
		case 12:		//查询波特率和工作时间
		{	
			usart1_send_bps_worktime();		
			break;
		}	
		case 16:		//查询版本号
		{	
			usart1_ver_worktime();		
			break;
		}
		default:
			break;	
	}
}

//发送数据和状态  20byte
void usart1_send_upload_data(void)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;

//	if(power_manage.p_state.b.MCON_FKIN)
	{
		memcpy(send_frame,soi,4);				
		send_frame[4] = 0x01;
		send_frame[5] = 0x14;
		
		//注意低字节在前！！！！！！！！！！！！！！！！！！！！！！！！！！
		send_frame[7] = power_manage.p_state.val;					//状态
		send_frame[6] = power_manage.p_constate.val;			//控制状态
		send_frame[9] = power_manage.p_breakdownh.val;		//故障态h
		send_frame[8] = power_manage.p_breakdownl.val;		//故障态l
		
		Change_u16_to_2x8((uint16_t)power_manage.temperature_ntc,&send_frame[10]);
				
		Change_u16_to_2x8(power_manage.dc48v_u, &send_frame[12]);	
		Change_u16_to_2x8(power_manage.dc48v_i, &send_frame[14]);		
		
		Change_u16_to_2x8(power_manage.dc24v1_u, &send_frame[16]);	
		Change_u16_to_2x8(power_manage.dc24v1_i, &send_frame[18]);	
		
		Change_u16_to_2x8(power_manage.dc24v2_u, &send_frame[20]);			
		Change_u16_to_2x8(power_manage.dc24v2_i1, &send_frame[22]);
		Change_u16_to_2x8(power_manage.dc24v2_i2, &send_frame[24]);
		
		CRC16Temp = GetCRC16(send_frame, 26);
		send_frame[26] = CRC16Temp & 0xff; 				//低字节
		send_frame[27] = (CRC16Temp >> 8) & 0xff;	//高字节
		
		memcpy(&send_frame[28],eoi,4);	
		
		//串口发送返回数据
		USART1_Send(send_frame,32);	
	}
}
//发送阈值数据   24byte
void usart1_send_threshold(void)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;
	
	memcpy(send_frame,soi,4);				
	send_frame[4] = 7;
	send_frame[5] = 0x18;
	
	Change_u16_to_2x8(power_manage.temperature_h,&send_frame[6]);
	
	Change_u16_to_2x8(power_manage.dc48v_ul, &send_frame[8]);			
	Change_u16_to_2x8(power_manage.dc48v_uh, &send_frame[10]);
	Change_u16_to_2x8(power_manage.dc48v_ih, &send_frame[12]);
	
	Change_u16_to_2x8(power_manage.dc24v1_ul, &send_frame[14]);			
	Change_u16_to_2x8(power_manage.dc24v1_uh, &send_frame[16]);
	Change_u16_to_2x8(power_manage.dc24v1_ih, &send_frame[18]);
	
	Change_u16_to_2x8(power_manage.dc24v2_ul, &send_frame[20]);			
	Change_u16_to_2x8(power_manage.dc24v2_uh, &send_frame[22]);
	Change_u16_to_2x8(power_manage.dc24v2_i1h, &send_frame[24]);
	Change_u16_to_2x8(power_manage.dc24v2_i2h, &send_frame[26]);
	
	Change_u16_to_2x8(power_manage.upload_time, &send_frame[28]);
	
	CRC16Temp = GetCRC16(send_frame, 30);
	send_frame[30] = CRC16Temp & 0xff; 				//低字节
	send_frame[31] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[32],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,36);	
}

//发送波特率和工作时间
void usart1_send_bps_worktime(void)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;
	
	memcpy(send_frame,soi,4);				
	send_frame[4] = 12;
	send_frame[5] = 0x05;
	
	send_frame[6] = power_manage.uart1_bps_id;			
	Change_u32_to_4x8(power_manage.work_time,&send_frame[7]);
	
	CRC16Temp = GetCRC16(send_frame, 11);
	send_frame[11] = CRC16Temp & 0xff; 				//低字节
	send_frame[12] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[13],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,17);	
}

//发送版本号信息			
void usart1_ver_worktime(void)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;
	
	memcpy(send_frame,soi,4);
	send_frame[4] = 16;
	send_frame[5] = 0x06;
	
	send_frame[6] = power_manage.my_ver[0];		//hare
	send_frame[7] = power_manage.my_ver[1];	
	send_frame[8] = power_manage.my_ver[2];
	send_frame[9] = power_manage.my_ver[3];		//soft
	send_frame[10] = power_manage.my_ver[4];
	send_frame[11] = power_manage.my_ver[5];	
	
	CRC16Temp = GetCRC16(send_frame, 12);
	send_frame[12] = CRC16Temp & 0xff; 				//低字节
	send_frame[13] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[14],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,18);	
}

//发送请求关机指令
void usart1_send_code3_cmd(void)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;
	
	memcpy(send_frame,soi,4);				
	send_frame[4] = 0x03;
	send_frame[5] = 0x01;
	send_frame[6] = 0x01;
	
	CRC16Temp = GetCRC16(send_frame, 7);
	send_frame[7] = CRC16Temp & 0xff; 				//低字节
	send_frame[8] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[9],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,13);		
}

//收到关机指令的响应
void usart1_reply_code4_cmd(void)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;
	
	memcpy(send_frame,soi,4);				
	send_frame[4] = 0x04;
	send_frame[5] = 0x01;
	send_frame[6] = 0x01;
	
	CRC16Temp = GetCRC16(send_frame, 7);
	send_frame[7] = CRC16Temp & 0xff; 				//低字节
	send_frame[8] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[9],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,13);		
}

//收到重启指令的响应
void usart1_reply_code5_cmd(void)
{
	uint8_t	send_frame[100];
	uint16_t CRC16Temp;
	
	memcpy(send_frame,soi,4);				
	send_frame[4] = 0x05;
	send_frame[5] = 0x01;
	send_frame[6] = 0x01;
	
	CRC16Temp = GetCRC16(send_frame, 7);
	send_frame[7] = CRC16Temp & 0xff; 				//低字节
	send_frame[8] = (CRC16Temp >> 8) & 0xff;	//高字节
	
	memcpy(&send_frame[9],eoi,4);	
	
	//串口发送返回数据
	USART1_Send(send_frame,13);		
}

//返回接收到的数据，原路返回
void USART1_Send_RecData(void)
{
	if(1==Rx1Status)  			//接收完成标志=1处理，否则退出
	{
		Rx1Status = 0;
		
		USART1_Send(Rxd1_Buff,Rxd1_Da_Num);		
		
		memset(Rxd1_Buff, 0, Rxd1_Da_Num);
		Rxd1_Da_Num = 0;		//完成后清接收长度
	}	
}



//发送指定长度字符串
void USART1_Send(uint8_t *RxBuffer, uint8_t len)
{
	uint8_t i;
	
	for(i=0;i<len;i++)
	{
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET);
		USART_SendData(USART1, RxBuffer[i]);
	}
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET);
}

/***************END OF FILE***********************************************/
