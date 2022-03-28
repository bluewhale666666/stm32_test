#include "READ_SENSOR_DATA.h"

//����Chage_SF6data_to_float()��Ӧ��ͨ�ɹ��ķ�����SF6���ݸ�ʽ
//����Chage_SF6data2_to_float()��Ӧ��������SF6���ݸ�ʽ

//�޸�ͨ����ӳ���ʱDelay_ms(1)��Delay_ms(3)
//���ͼ���ӳ�Sensor_Sample_Rate����10��15

//Sensor_Send_Over_Flag��1�ŵ�case 16���棬��֤�ɼ���һ�鴫�������ݣ��ٽ���̵������ƺ�������֤������ֵ���Ѿ���ȡ������



//���ڲɼ���������������ʹ���
void UART2_TXD_Data_Refresh(void)
{
	u8 	i;
	u8	Txd_Max_Num, Txd_Buff[TXD2_MAX_NUM];
	
	Txd2_Table_Num++;
	if(Txd2_Table_Num>7)	{Txd2_Table_Num=0;}
	
	UART2_RS485_TXD_EN;									//RS485����ʹ��		
	Delay_ms(3);

	Txd_Max_Num = Uart5_Data_Command[Txd5_Table_Num][0];			//��Ҫ�������ݸ�������������һλ
	for(i=0;i<Txd_Max_Num;i++)
		Txd_Buff[i]=Uart5_Data_Command[Txd5_Table_Num][i+1];	//ȡ��ӦTable���ݲɼ�������ͻ���
	
	UART2_Tx_String(Txd_Buff, Txd_Max_Num);
	Delay_ms(Txd_Max_Num+2);
	
	UART2_RS485_RXD_EN;									//RS485����ʹ��		
	
	Rxd2_Da_Num=0;											//�����ֽ���0	
}


//���ڲɼ�����������������մ���ÿ����һ�βŽ���һ�θú���
void UART2_RXD_Data_Refresh(void)
{
	u8	i,j,k;
	u8	CheckSum;//,len;
//	u16	crc16check;
	u8 	Rxd_Data[14];
	static u8 dataok_flag2[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	Rx2Status = 0;

	switch (Txd2_Table_Num)
	{
		//								5.....................................18
		//aa 00 01 06 0e 01 00 01 02 03 04 00 06 07 08 09 02 00 01 6b 55
		case 0:		//HT1
		{
			for(i=0;i<10;i++)
			{
				if((Rxd2_Buff[i]==0xaa)&&(Rxd2_Buff[i+1]==0x00)&&(Rxd2_Buff[i+2]==0x01)&&(Rxd2_Buff[i+3]==0x06))   //�յ�������������
				{
					CheckSum = 0;
					for(j=0;j<19;j++)				//����У���
					{
						CheckSum = CheckSum + Rxd2_Buff[i+j];
					}
					CheckSum = CheckSum & 0x7f;
					if(CheckSum == Rxd2_Buff[i+19]) 	//У����ȷ��������
					{
//						LED3_ON;												//485�ɹ����յ�һ�����ݣ�����ָʾ��
//						LED3_ON_Time=0;									//ָʾ�Ƶ�����ʱ��0
						dataok_flag2[0] = 0;
						
						for(k=0; k < 14; k++)				//!!!!!!!!!!!!!!!!!!!!!!!!!!ע��!!!!!!
						{
							Rxd_Data[k] = Rxd2_Buff[i+5+k];  			//ת��Ϸ����ݰ�
						}						
						Chage_HTdata_to_float(&Rxd_Data[0],&Myboard.HT_f[Txd2_Table_Num][0],&Myboard.HT_f[Txd2_Table_Num][1],&Myboard.Alarm_Value[Txd2_Table_Num*2],&Myboard.Alarm_Value[Txd2_Table_Num*2+1]);
					}
					break;
				}
				else			//δ�յ�����,��0
				{
					dataok_flag2[0]++;
					if(dataok_flag2[0]>DataErr_Num)
					{
						Myboard.HT_f[Txd2_Table_Num][0]=0;
						Myboard.HT_f[Txd2_Table_Num][1]=0;
						Myboard.Alarm_Value[Txd2_Table_Num*2]='0';
						Myboard.Alarm_Value[Txd2_Table_Num*2+1]='0';	
					}						
				}
			}
			break;
		}
		case 1:		//HT2
		{
			for(i=0;i<10;i++)
			{
				if((Rxd2_Buff[i]==0xaa)&&(Rxd2_Buff[i+1]==0x00)&&(Rxd2_Buff[i+2]==0x02)&&(Rxd2_Buff[i+3]==0x06))   //�յ�������������
				{
					CheckSum = 0;
					for(j=0;j<19;j++)				//����У���
					{
						CheckSum = CheckSum + Rxd2_Buff[i+j];
					}
					CheckSum = CheckSum & 0x7f;
					if(CheckSum == Rxd2_Buff[i+19]) 	//У����ȷ��������
					{
//						LED3_ON;												//485�ɹ����յ�һ�����ݣ�����ָʾ��
//						LED3_ON_Time=0;									//ָʾ�Ƶ�����ʱ��0
						dataok_flag2[1] = 0;
						
						for(k=0; k < 14; k++)				//!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��!!!!!!
						{
							Rxd_Data[k] = Rxd2_Buff[i+5+k];  			//ת��Ϸ����ݰ�
						}						
						Chage_HTdata_to_float(&Rxd_Data[0],&Myboard.HT_f[Txd2_Table_Num][0],&Myboard.HT_f[Txd2_Table_Num][1],&Myboard.Alarm_Value[Txd2_Table_Num*2],&Myboard.Alarm_Value[Txd2_Table_Num*2+1]);
					}
					break;
				}
				else			//δ�յ�����,��0
				{
					dataok_flag2[1]++;
					if(dataok_flag2[1]>DataErr_Num)
					{
						Myboard.HT_f[Txd2_Table_Num][0]=0;
						Myboard.HT_f[Txd2_Table_Num][1]=0;
						Myboard.Alarm_Value[Txd2_Table_Num*2]='0';
						Myboard.Alarm_Value[Txd2_Table_Num*2+1]='0';		
					}
				}				
			}
			break;
		}
		case 2://HT3
		{
			for(i=0;i<10;i++)
			{
				if((Rxd2_Buff[i]==0xaa)&&(Rxd2_Buff[i+1]==0x00)&&(Rxd2_Buff[i+2]==0x03)&&(Rxd2_Buff[i+3]==0x06))   //�յ�������������
				{
					CheckSum = 0;
					for(j=0;j<19;j++)				//����У���
					{
						CheckSum = CheckSum + Rxd2_Buff[i+j];
					}
					CheckSum = CheckSum & 0x7f;
					if(CheckSum == Rxd2_Buff[i+19]) 	//У����ȷ��������
					{
//						LED3_ON;												//485�ɹ����յ�һ�����ݣ�����ָʾ��
//						LED3_ON_Time=0;									//ָʾ�Ƶ�����ʱ��0
						dataok_flag2[2] = 0;
						
						for(k=0; k < 14; k++)				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��!!!!!!
						{
							Rxd_Data[k] = Rxd2_Buff[i+5+k];  			//ת��Ϸ����ݰ�
						}						
						Chage_HTdata_to_float(&Rxd_Data[0],&Myboard.HT_f[Txd2_Table_Num][0],&Myboard.HT_f[Txd2_Table_Num][1],&Myboard.Alarm_Value[Txd2_Table_Num*2],&Myboard.Alarm_Value[Txd2_Table_Num*2+1]);
					}
					break;
				}
				else			//δ�յ�����,��0
				{
					dataok_flag2[2]++;
					if(dataok_flag2[2]>DataErr_Num)
					{
						Myboard.HT_f[Txd2_Table_Num][0]=0;
						Myboard.HT_f[Txd2_Table_Num][1]=0;
						Myboard.Alarm_Value[Txd2_Table_Num*2]='0';
						Myboard.Alarm_Value[Txd2_Table_Num*2+1]='0';	
					}						
				}				
			}
			break;
		}
		case 3://HT4
		{
			for(i=0;i<10;i++)
			{
				if((Rxd2_Buff[i]==0xaa)&&(Rxd2_Buff[i+1]==0x00)&&(Rxd2_Buff[i+2]==0x04)&&(Rxd2_Buff[i+3]==0x06))   //�յ�������������
				{
					CheckSum = 0;
					for(j=0;j<19;j++)				//����У���
					{
						CheckSum = CheckSum + Rxd2_Buff[i+j];
					}
					CheckSum = CheckSum & 0x7f;
					if(CheckSum == Rxd2_Buff[i+19]) 	//У����ȷ��������
					{
//						LED3_ON;												//485�ɹ����յ�һ�����ݣ�����ָʾ��
//						LED3_ON_Time=0;									//ָʾ�Ƶ�����ʱ��0
						dataok_flag2[3] = 0;
						
						for(k=0; k < 14; k++)				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��!!!!!!
						{
							Rxd_Data[k] = Rxd2_Buff[i+5+k];  			//ת��Ϸ����ݰ�
						}						
						Chage_HTdata_to_float(&Rxd_Data[0],&Myboard.HT_f[Txd2_Table_Num][0],&Myboard.HT_f[Txd2_Table_Num][1],&Myboard.Alarm_Value[Txd2_Table_Num*2],&Myboard.Alarm_Value[Txd2_Table_Num*2+1]);
					}
					break;
				}
				else			//δ�յ�����,��0
				{
					dataok_flag2[3]++;
					if(dataok_flag2[3]>DataErr_Num)
					{
						Myboard.HT_f[Txd2_Table_Num][0]=0;
						Myboard.HT_f[Txd2_Table_Num][1]=0;
						Myboard.Alarm_Value[Txd2_Table_Num*2]='0';
						Myboard.Alarm_Value[Txd2_Table_Num*2+1]='0';
					}
				}				
			}
			break;
		}
		case 4://HT5
		{
			for(i=0;i<10;i++)
			{
				if((Rxd2_Buff[i]==0xaa)&&(Rxd2_Buff[i+1]==0x00)&&(Rxd2_Buff[i+2]==0x05)&&(Rxd2_Buff[i+3]==0x06))   //�յ�������������
				{
					CheckSum = 0;
					for(j=0;j<19;j++)				//����У���
					{
						CheckSum = CheckSum + Rxd2_Buff[i+j];
					}
					CheckSum = CheckSum & 0x7f;
					if(CheckSum == Rxd2_Buff[i+19]) 	//У����ȷ��������
					{
//						LED3_ON;												//485�ɹ����յ�һ�����ݣ�����ָʾ��
//						LED3_ON_Time=0;									//ָʾ�Ƶ�����ʱ��0
						dataok_flag2[4] = 0;
						
						for(k=0; k < 14; k++)				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��!!!!!!
						{
							Rxd_Data[k] = Rxd2_Buff[i+5+k];  			//ת��Ϸ����ݰ�
						}						
						Chage_HTdata_to_float(&Rxd_Data[0],&Myboard.HT_f[Txd2_Table_Num][0],&Myboard.HT_f[Txd2_Table_Num][1],&Myboard.Alarm_Value[Txd2_Table_Num*2],&Myboard.Alarm_Value[Txd2_Table_Num*2+1]);
					}
					break;
				}
				else			//δ�յ�����,��0
				{
					dataok_flag2[4]++;
					if(dataok_flag2[4]>DataErr_Num)
					{
						Myboard.HT_f[Txd2_Table_Num][0]=0;
						Myboard.HT_f[Txd2_Table_Num][1]=0;
						Myboard.Alarm_Value[Txd2_Table_Num*2]='0';
						Myboard.Alarm_Value[Txd2_Table_Num*2+1]='0';			
					}
				}				
			}
			break;
		}
		case 5://HT6
		{
			for(i=0;i<10;i++)
			{
				if((Rxd2_Buff[i]==0xaa)&&(Rxd2_Buff[i+1]==0x00)&&(Rxd2_Buff[i+2]==0x06)&&(Rxd2_Buff[i+3]==0x06))   //�յ�������������
				{
					CheckSum = 0;
					for(j=0;j<19;j++)				//����У���
					{
						CheckSum = CheckSum + Rxd2_Buff[i+j];
					}
					CheckSum = CheckSum & 0x7f;
					if(CheckSum == Rxd2_Buff[i+19]) 	//У����ȷ��������
					{
//						LED3_ON;												//485�ɹ����յ�һ�����ݣ�����ָʾ��
//						LED3_ON_Time=0;									//ָʾ�Ƶ�����ʱ��0
						dataok_flag2[5] = 0;
						
						for(k=0; k < 14; k++)				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��!!!!!!
						{
							Rxd_Data[k] = Rxd2_Buff[i+5+k];  			//ת��Ϸ����ݰ�
						}						
						Chage_HTdata_to_float(&Rxd_Data[0],&Myboard.HT_f[Txd2_Table_Num][0],&Myboard.HT_f[Txd2_Table_Num][1],&Myboard.Alarm_Value[Txd2_Table_Num*2],&Myboard.Alarm_Value[Txd2_Table_Num*2+1]);
					}
					break;
				}
				else			//δ�յ�����,��0
				{
					dataok_flag2[5]++;
					if(dataok_flag2[5]>DataErr_Num)
					{
						Myboard.HT_f[Txd2_Table_Num][0]=0;
						Myboard.HT_f[Txd2_Table_Num][1]=0;
						Myboard.Alarm_Value[Txd2_Table_Num*2]='0';
						Myboard.Alarm_Value[Txd2_Table_Num*2+1]='0';			
					}
				}				
			}
			break;
		}
		case 6://HT7
		{
			for(i=0;i<10;i++)
			{
				if((Rxd2_Buff[i]==0xaa)&&(Rxd2_Buff[i+1]==0x00)&&(Rxd2_Buff[i+2]==0x07)&&(Rxd2_Buff[i+3]==0x06))   //�յ�������������
				{
					CheckSum = 0;
					for(j=0;j<19;j++)				//����У���
					{
						CheckSum = CheckSum + Rxd2_Buff[i+j];
					}
					CheckSum = CheckSum & 0x7f;
					if(CheckSum == Rxd2_Buff[i+19]) 	//У����ȷ��������
					{
//						LED3_ON;												//485�ɹ����յ�һ�����ݣ�����ָʾ��
//						LED3_ON_Time=0;									//ָʾ�Ƶ�����ʱ��0
						dataok_flag2[6] = 0;
						
						for(k=0; k < 14; k++)				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��!!!!!!
						{
							Rxd_Data[k] = Rxd2_Buff[i+5+k];  			//ת��Ϸ����ݰ�
						}						
						Chage_HTdata_to_float(&Rxd_Data[0],&Myboard.HT_f[Txd2_Table_Num][0],&Myboard.HT_f[Txd2_Table_Num][1],&Myboard.Alarm_Value[Txd2_Table_Num*2],&Myboard.Alarm_Value[Txd2_Table_Num*2+1]);
					}
					break;
				}
				else			//δ�յ�����,��0
				{
					dataok_flag2[6]++;
					if(dataok_flag2[6]>DataErr_Num)
					{
						Myboard.HT_f[Txd2_Table_Num][0]=0;
						Myboard.HT_f[Txd2_Table_Num][1]=0;
						Myboard.Alarm_Value[Txd2_Table_Num*2]='0';
						Myboard.Alarm_Value[Txd2_Table_Num*2+1]='0';	
					}
				}				
			}
			break;
		}
		case 7://HT8
		{
			for(i=0;i<10;i++)
			{
				if((Rxd2_Buff[i]==0xaa)&&(Rxd2_Buff[i+1]==0x00)&&(Rxd2_Buff[i+2]==0x08)&&(Rxd2_Buff[i+3]==0x06))   //�յ�������������
				{
					CheckSum = 0;
					for(j=0;j<19;j++)				//����У���
					{
						CheckSum = CheckSum + Rxd2_Buff[i+j];
					}
					CheckSum = CheckSum & 0x7f;
					if(CheckSum == Rxd2_Buff[i+19]) 	//У����ȷ��������
					{
//						LED3_ON;												//485�ɹ����յ�һ�����ݣ�����ָʾ��
//						LED3_ON_Time=0;									//ָʾ�Ƶ�����ʱ��0
						dataok_flag2[7] = 0;
						
						for(k=0; k < 14; k++)				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ע��!!!!!!
						{
							Rxd_Data[k] = Rxd2_Buff[i+5+k];  			//ת��Ϸ����ݰ�
						}						
						Chage_HTdata_to_float(&Rxd_Data[0],&Myboard.HT_f[Txd2_Table_Num][0],&Myboard.HT_f[Txd2_Table_Num][1],&Myboard.Alarm_Value[Txd2_Table_Num*2],&Myboard.Alarm_Value[Txd2_Table_Num*2+1]);
					}
					break;
				}
				else			//δ�յ�����,��0
				{
					dataok_flag2[7]++;
					if(dataok_flag2[7]>DataErr_Num)
					{
						Myboard.HT_f[Txd2_Table_Num][0]=0;
						Myboard.HT_f[Txd2_Table_Num][1]=0;
						Myboard.Alarm_Value[Txd2_Table_Num*2]='0';
						Myboard.Alarm_Value[Txd2_Table_Num*2+1]='0';
					}
				}				
			}
			break;
		}
		default:
			break;
	}
	
	for(i=0;i<RXD2_MAX_NUM;i++)
	{	Rxd2_Buff[i]=0;}		//����ܻ���
}

//�������ݰ�		��ѯ����
void UART2_Tx_String(vu8 *data, u8 len)
{
	u8 i;
	
	for(i=0;i<len;i++)
	{
		while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)==RESET){};		//���ͻ�����Ϊ��
//		Delay(50);	
		USART_SendData(USART2, data[i]);
//		Delay(50);
	}
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)==RESET);		//���ͻ�����Ϊ��
}


//								5.....................................18
//aa 00 01 06 0e 01 00 01 02 03 04 00 06 07 08 09 02 00 01 6b 55
void Chage_HTdata_to_float(u8 *pdata, float *t_f, float *h_f, char *t_a, char *h_a)
{
	u8 i,data[14];
//	float f_tmp;
	
	for(i=0;i<14;i++)
	{
		data[i] = pdata[i];
	}

	*t_f = data[1]*10000+data[2]*1000+data[3]*100+data[4]*10+data[5];
	*t_f = *t_f/100.0;	
	if(1==data[0])
	{
		*t_f = (-1)*(*t_f);
	}
	*h_f = data[6]*10000+data[7]*1000+data[8]*100+data[9]*10+data[10];
	*h_f = *h_f/100.0;	
	
	*t_a = 0x30+data[11];
	
	*h_a	= 0x30+data[12];	
}


//01 03 00 03 00 03 F5 CB
//							 5  6  7  8
//01 03 06 00 01 XX XX XX XX CC CC
void Chage_WaterLevdata_to_float(u8 *pdata, float *w_f, char *w_a)
{
	u8 i,data[6];
	u16	temp;
	
	for(i=0;i<6;i++)
	{
		data[i] = pdata[i];
	}
	temp = ((u16)data[2]<<8)|(u16)data[3];
	
	if(temp<2000)
	{
		*w_f = temp/10.0;				//cm
		
		if(*w_f > Myboard.WaterL_Threshold[1])	//10cm
		{
			*w_a = '1';
		}
		else
		{
			*w_a = '0';
		}
	}
}


//03 03 00 14 00 01 c5 ec
//				 3  4
//03 03 02 XX XX CC CC
void Chage_O2data_to_float(u8 *pdata, float *o_f, char *o_a)
{
	u8 i,data[2];
	u16	temp;
	
	for(i=0;i<2;i++)
	{
		data[i] = pdata[i];
	}
	temp = ((u16)data[0]<<8)|(u16)data[1];
	
	*o_f = temp/100.0;	
	
	if((*o_f > Myboard.O2_Threshold[1])||(*o_f < Myboard.O2_Threshold[0]))		//С�ڵ�ֵ�����ڸ�ֵ
	{
		*o_a = '1';
	}
	else
	{
		*o_a = '0';
	}
}

//��ͨSF6������
//01 03 00 02 00 02 CC CC
//				 3  4  5  6
//01 03 04 XX XX XX XX CC CC
void Chage_SF6data_to_float(u8 *pdata, float *sf6_f, char *sf6_a)
{
	u8 	i,data[4];
	u32	temp;
	
	for(i=0;i<4;i++)
	{
		data[i] = pdata[i];
	}
	if(data[0]&0xf0)
	{
		*sf6_f = 0.0;
		*sf6_a = '0';
	}
	else
	{
		temp = (((u32)data[0]<<24)&0x0f000000)|(((u32)data[1]<<16)&0x00ff0000)|(((u32)data[2]<<8)&0x0000ff00)|((u32)data[3]&0x000000ff);
		
		*sf6_f = temp/1000.0;	
		
		if((*sf6_f > Myboard.SF_Threshold[1])||(*sf6_f < Myboard.SF_Threshold[0]))		//С�ڵ�ֵ�����ڸ�ֵ
		{
			*sf6_a = '1';
		}
		else
		{
			*sf6_a = '0';
		}
	}
}

//��������SF6������
//01 03 00 00 00 01 CC CC
//				 3  4  5  6
//01 03 02 XX XX CC CC
void Chage_SF6data2_to_float(u8 *pdata, float *sf6_f, char *sf6_a)
{
	u8 	i,data[2];
	u16	temp;
	
	for(i=0;i<2;i++)
	{
		data[i] = pdata[i];
	}
	temp = (((u16)data[0]<<24)&0xff00)|(((u16)data[1]<<16)&0x00ff);
	
	*sf6_f = temp/10.0;	
	
	if((*sf6_f > Myboard.SF_Threshold[1])||(*sf6_f < Myboard.SF_Threshold[0]))		//С�ڵ�ֵ�����ڸ�ֵ
	{
		*sf6_a = '1';
	}
	else
	{
		*sf6_a = '0';
	}
}


/***************END OF FILE***********************************************/

