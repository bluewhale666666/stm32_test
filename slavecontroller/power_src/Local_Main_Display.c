#include "Local_Main_Display.h"

//
//�����ϴ������ַ�ʽ��һ�ֵ��ͻ��ˣ�һ�ֵ�������



//�Զ��ϴ����ݵ�web�˷����������30s
void Auto_Send_Data_To_X80X_30s(USART_TypeDef* USARTx)
{
	if(!Time_100ms2)
	{
		Auto_Send_XXXX_Data_To_X80X(USARTx);		//�ϴ�������������	����������������������������������
		Time_100ms2 = 300;					//��Ҫ30s����ٷ�	30*10
	}			
}

//�Զ��ϴ����ݵ��ͻ��ˣ�������������������趨
void Auto_Send_Data_To_Touchscreen_Timming(USART_TypeDef* USARTx)
{

	if(1==Send_Enable_Flag)							//����ʹ��
	{
		if((1==Alarm_Appear_Flag)&&(0==Alarm_Send_Over_Flag))			//�б�����������δ������ɣ���������
		{
			if(0==Alarm_Send_Repeat_Number)
			{
				Auto_Send_XXXX_Data(USARTx);							//�Զ��ϴ����ݷ���	����������������������������������
				Alarm_Send_Repeat_Number++;							//�ظ��ϴ�������һ
				Time_100ms = Alarm_Over_Updata_Time;		//��Ҫ����������ٷ�
			}
			else
			{
				if(!Time_100ms)
				{
					Auto_Send_XXXX_Data(USARTx);							//�Զ��ϴ����ݷ���	����������������������������������
					Alarm_Send_Repeat_Number++;					//�ظ��ϴ�������һ
					
					if(Alarm_Send_Repeat_Number < Alarm_Repeat_Send_Max_Number)		//�ظ������жϣ�δ�ﵽ���մ���
					{
						Time_100ms = Alarm_Over_Updata_Time;		//��Ҫ����������ٷ�
					}
					else			//�ﵽ�ϴ�������
					{
						Alarm_Send_Over_Flag = 1;							//�������
						Time_100ms = Send_UpLoad_Time;					//��Ҫ����ʱ�ϴ�����ٷ�
					}	
				}
			}			
		}
		else			//�Զ�����ʹ��,���ݶ�ʱ�ϴ�
		{
			Alarm_Send_Repeat_Number=0;						
			
			if(!Time_100ms)
			{
				Auto_Send_XXXX_Data(USARTx);							//�Զ��ϴ����ݷ���	����������������������������������
				Time_100ms = Send_UpLoad_Time;					//��Ҫ����ʱ�ϴ�����ٷ�
			}			
		}		
	}
}



//�Զ��ϴ����ݷ��ͺ���	Usart3 or Uart4	
void	Auto_Send_XXXX_Data_To_X80X(USART_TypeDef* USARTx)
{
	char 	Send_Data[1000];//,Temp_Data[6];
	
	uint8_t 	len;
	uint16_t 	i,k;

	memset(Send_Data,'0',1000);		//������'0'
  memmove(Send_Data,"MyID=",5);
	
//	Myboard.HT_f[3][0] = -12.34;
//	Myboard.HT_f[3][1] = 23.34;
//	Myboard.HT_f[2][0] = -12.34;
//	Myboard.HT_f[2][1] = 67.89;
	
	i=5;
	Send_Data[i++] = Myboard.HostNetID[0];
	Send_Data[i++] = Myboard.HostNetID[1];
	Send_Data[i++] = Myboard.HostNetID[2];
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'D';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 't';
	Send_Data[i++] = 'a';
	Send_Data[i++] = ';';

	Send_Data[i++] = 'T';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.HT_f[0][0],&Send_Data[i],2);	//000.00
	i = i+len;
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.HT_f[0][1],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.HT_f[1][0],&Send_Data[i],2);
	i = i+len;
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.HT_f[1][1],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = '3';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.HT_f[2][0],&Send_Data[i],2);
	i = i+len;
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = '3';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.HT_f[2][1],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = '4';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.HT_f[3][0],&Send_Data[i],2);
	i = i+len;
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = '4';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.HT_f[3][1],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';

	//SF6-1
	Send_Data[i++] = 'T';
	Send_Data[i++] = '5';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.SF_f[0],&Send_Data[i],2);
	i = i+len;
	Send_Data[i++] = ';';
	//SF6-2
	Send_Data[i++] = 'H';
	Send_Data[i++] = '5';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.SF_f[1],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	//SF6-3
	Send_Data[i++] = 'T';
	Send_Data[i++] = '6';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.SF_f[2],&Send_Data[i],2);
	i = i+len;
	Send_Data[i++] = ';';
	//SF6-4
	Send_Data[i++] = 'H';
	Send_Data[i++] = '6';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.SF_f[3],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	//O2-1
	Send_Data[i++] = 'T';
	Send_Data[i++] = '7';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.O2_f[0],&Send_Data[i],2);
	i = i+len;
	Send_Data[i++] = ';';
	//O2-2
	Send_Data[i++] = 'H';
	Send_Data[i++] = '7';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.O2_f[1],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';

	//O3-1
	Send_Data[i++] = 'T';
	Send_Data[i++] = '8';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.O3_f[0],&Send_Data[i],2);
	i = i+len;
	Send_Data[i++] = ';';
	//O3-2
	Send_Data[i++] = 'H';
	Send_Data[i++] = '8';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.O3_f[1],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	//WaterLev=1
	Send_Data[i++] = 'T';
	Send_Data[i++] = '9';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.WaterL_f[0],&Send_Data[i],2);
	i = i+len;
	Send_Data[i++] = ';';
	//WaterLev=2
	Send_Data[i++] = 'H';
	Send_Data[i++] = '9';
	Send_Data[i++] = '=';	
	len = Chage_fdata_to_fixed_ascii(Myboard.WaterL_f[1],&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';

	//ALM=
	Send_Data[i++] = 'A';
	Send_Data[i++] = 'M';
	Send_Data[i++] = '=';
	//a1b1a2b2a3b3a4b4a5b5a6b6a7b7a8b8a9b9c1c2c3c4c5c6c7c8c9defg1g2g3g4g5g6g7g8g9hijklmnopqrst
	//a1b1a2b2a3b3a4b4a5b5a6b6a7b7a8b8a9b9
	//a1��ʾ�¶�1������b1��ʾʪ��1����	
	//4·��ʪ��=8
	for(k=0;k<8;k++)
	{
		Send_Data[i++] = Myboard.Alarm_Value[k];		
	}
	//4·SF6
	Send_Data[i++] = Myboard.Alarm_Value[16];		
	Send_Data[i++] = Myboard.Alarm_Value[17];	
	Send_Data[i++] = Myboard.Alarm_Value[18];		
	Send_Data[i++] = Myboard.Alarm_Value[19];	
	//2·O2
	Send_Data[i++] = Myboard.Alarm_Value[24];		
	Send_Data[i++] = Myboard.Alarm_Value[25];		
	//2·O3
	Send_Data[i++] = Myboard.Alarm_Value[32];	
	Send_Data[i++] = Myboard.Alarm_Value[33];		
	//2·ˮλ
	Send_Data[i++] = Myboard.Alarm_Value[40];	
	Send_Data[i++] = Myboard.Alarm_Value[41];	
//	//2·res
//	Send_Data[i++] = '0';	
//	Send_Data[i++] = '0';	
	
	//c1c2c3c4c5c6c7c8c9�̸�
	Send_Data[i++] = Myboard.Alarm_Value[48];	
	Send_Data[i++] = Myboard.Alarm_Value[49];	
	Send_Data[i++] = Myboard.Alarm_Value[50];	
	Send_Data[i++] = Myboard.Alarm_Value[51];		
	Send_Data[i++] = Myboard.Alarm_Value[52];			//����˫��1
	Send_Data[i++] = Myboard.Alarm_Value[53];			//����˫��2
	Send_Data[i++] = Myboard.Alarm_Value[54];			//�������1
	Send_Data[i++] = Myboard.Alarm_Value[55];			//�������2
	Send_Data[i++] = '0';	
	//defԤ��
	Send_Data[i++] = Myboard.Alarm_Value[63];			//�ɽӵ�Ԥ��
	Send_Data[i++] = '0';	
	Send_Data[i++] = '0';	
	//g1g2g3g4g5g6g7g8g9ͣ��
	Send_Data[i++] = Myboard.Alarm_Value[45];			//ֱ���ϵ�
	Send_Data[i++] = Myboard.Alarm_Value[44];			//�����ϵ�
	Send_Data[i++] = Myboard.Alarm_Value[47];			//�Ŵ�2
	Send_Data[i++] = Myboard.Alarm_Value[57];			//©ˮ2
	Send_Data[i++] = Myboard.Alarm_Value[58];			//sf6
	Send_Data[i++] = Myboard.Alarm_Value[59];			//������1
	Send_Data[i++] = Myboard.Alarm_Value[60];			//������2
	Send_Data[i++] = Myboard.Alarm_Value[61];			//������3
	Send_Data[i++] = Myboard.Alarm_Value[62];			//������4
	//hijklmnopqrst
	//h©ˮ;
	Send_Data[i++] = Myboard.Alarm_Value[56];			//©ˮ1
	//i�����Ӧ/�Ŵ�/�Ž�;
	Send_Data[i++] = Myboard.Alarm_Value[46];			//�Ŵ�1
	//j����;
	Send_Data[i++] = '0';	
	//kUPS1;
	Send_Data[i++] = '0';	
	//LUPS2;
	Send_Data[i++] = '0';	
	//m�յ�1;
	Send_Data[i++] = '0';	
	//n�յ�2;
	Send_Data[i++] = '0';	
	//o�����/������1;
	Send_Data[i++] = '0';	
	//p�����/������2;
	Send_Data[i++] = '0';	
	//q�����
	Send_Data[i++] = '0';	
	//r����
	Send_Data[i++] = '0';	
	//stԤ����Ĭ��00��
	Send_Data[i++] = '0';	
	Send_Data[i++] = '0';		
	Send_Data[i++] = ';';
	
	//Viob1=380.11,380.11,380.11,380.11,380.11,380.11,002.11;Ao1=010.11;LF1=010.11;Tb1=+030.22;Fib1=059.90;
	Send_Data[i++] = 'V';
	Send_Data[i++] = 'i';
	Send_Data[i++] = 'o';
	Send_Data[i++] = 'b';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'A';
	Send_Data[i++] = 'o';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'L';
	Send_Data[i++] = 'F';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'b';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	Send_Data[i++] = '+';				//������!!!!!!!!!!!!!!!!!!!!!!!!!!!
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'F';
	Send_Data[i++] = 'i';
	Send_Data[i++] = 'b';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	//Viob2=380.11,380.11,380.11,380.11,380.11,380.11,002.11;Ao2=010.11;LF2=010.11;Tb2=+030.22;Fib2=059.90;
	Send_Data[i++] = 'V';
	Send_Data[i++] = 'i';
	Send_Data[i++] = 'o';
	Send_Data[i++] = 'b';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'A';
	Send_Data[i++] = 'o';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'L';
	Send_Data[i++] = 'F';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'b';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	Send_Data[i++] = '+';				//������!!!!!!!!!!!!!!!!!!!!!!!!!!!
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'F';
	Send_Data[i++] = 'i';
	Send_Data[i++] = 'b';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';	
	
	//Ts1=22.36;Hs1=85.74;Tr1=22.36;Hr1=85.74;Tl1=02.36;Th1=35.74;Hl1=02.36;Hh1=85.74;
	Send_Data[i++] = 'T';
	Send_Data[i++] = 's';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = 's';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'r';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = 'r';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'l';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'h';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = 'l';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = 'h';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	//Ts2=22.36;Hs2=85.74;Tr2=22.36;Hr2=85.74;Tl2=02.36;Th2=35.74;Hl2=02.36;Hh2=85.74;
	Send_Data[i++] = 'T';
	Send_Data[i++] = 's';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = 's';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'r';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = 'r';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'l';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'h';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = 'l';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'H';
	Send_Data[i++] = 'h';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	//Vabc1=380.00,380.00,380.00;Iabc1=110.11,110.11,110.11;P1=100.2;E1=1110000.2;
	Send_Data[i++] = 'V';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 'b';
	Send_Data[i++] = 'c';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'I';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 'b';
	Send_Data[i++] = 'c';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'P';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],1);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'E';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	len = Chage_Edata_to_fixed_ascii(0,&Send_Data[i],1);		//0000000.0
	i = i+len;	
	Send_Data[i++] = ';';
	
	//Vabc2=380.00,380.00,380.00;Iabc2=110.11,110.11,110.11;P2=100.2;E2=1110000.2;
	Send_Data[i++] = 'V';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 'b';
	Send_Data[i++] = 'c';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'I';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 'b';
	Send_Data[i++] = 'c';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ',';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'P';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],1);
	i = i+len;	
	Send_Data[i++] = ';';
	
	Send_Data[i++] = 'E';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	len = Chage_Edata_to_fixed_ascii(0,&Send_Data[i],1);
	i = i+len;	
	Send_Data[i++] = ';';
	
	//Vbat=211.01;CC\r\n
	Send_Data[i++] = 'V';
	Send_Data[i++] = 'b';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 't';
	Send_Data[i++] = '=';
	len = Chage_fdata_to_fixed_ascii(0,&Send_Data[i],2);
	i = i+len;	
	Send_Data[i++] = ';';

	Send_Data[i++] = 'C';
	Send_Data[i++] = 'C';
	Send_Data[i++] = 0x0d;		//�س�����
	Send_Data[i++] = 0x0a;

	USART3_4_TxCircle_String(USARTx, Send_Data,i);
}


//�Զ��ϴ����ݷ��ͺ��� Usart3 or Uart4	
void	Auto_Send_XXXX_Data(USART_TypeDef* USARTx)
{
	char 	Send_Data[1000];//,Temp_Data[6];
	
	uint8_t 	len;
	uint16_t 	i,k;
//	uint16_t 	j;

	memset(Send_Data,'0',1000);		//������'0'
  memmove(Send_Data,"HostID=",7);
	
//	Myboard.HT_f[0][0] = -12.34;
//	Myboard.HT_f[0][1] = 23.34;
//	Myboard.HT_f[1][0] = -12.34;
//	Myboard.HT_f[1][1] = 67.89;
	
	i=7;
	Send_Data[i++] = Myboard.HostID[0];
	Send_Data[i++] = Myboard.HostID[1];
	Send_Data[i++] = Myboard.HostID[2];
	Send_Data[i++] = ';';
	Send_Data[i++] = 'T';
	Send_Data[i++] = 'H';
	Send_Data[i++] = '=';
	
	for(k=0;k<8;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.HT_f[k][0],&Send_Data[i],2);
		i = i+len;
		Send_Data[i++] = ',';
		len = Chage_fdata_to_ascii(Myboard.HT_f[k][1],&Send_Data[i],2);
		i = i+len;	
		if(k<7)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	Send_Data[i++] = 'S';
	Send_Data[i++] = 'F';
	Send_Data[i++] = '=';
	for(k=0;k<8;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.SF_f[k],&Send_Data[i],1);
		i = i+len;
		if(k<7)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	Send_Data[i++] = 'O';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	for(k=0;k<8;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.O2_f[k],&Send_Data[i],1);
		i = i+len;
		if(k<7)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	Send_Data[i++] = 'O';
	Send_Data[i++] = '3';
	Send_Data[i++] = '=';
	for(k=0;k<8;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.O3_f[k],&Send_Data[i],1);
		i = i+len;	
		if(k<7)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	//WaterLev=
	Send_Data[i++] = 'W';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 't';
	Send_Data[i++] = 'e';
	Send_Data[i++] = 'r';
	Send_Data[i++] = 'L';
	Send_Data[i++] = 'e';
	Send_Data[i++] = 'v';
	Send_Data[i++] = '=';
	for(k=0;k<2;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.WaterL_f[k],&Send_Data[i],1);
		i = i+len;	
		if(k<1)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	//UIabc1=
	Send_Data[i++] = 'U';
	Send_Data[i++] = 'I';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 'b';
	Send_Data[i++] = 'c';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	for(k=0;k<8;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.UIabc[0][k],&Send_Data[i],1);
		i = i+len;	
		if(k<7)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	//UIabc2=
	Send_Data[i++] = 'U';
	Send_Data[i++] = 'I';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 'b';
	Send_Data[i++] = 'c';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	for(k=0;k<8;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.UIabc[1][k],&Send_Data[i],1);
		i = i+len;	
		if(k<7)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	//Res1=
	Send_Data[i++] = 'R';
	Send_Data[i++] = 'e';
	Send_Data[i++] = 's';
	Send_Data[i++] = '1';
	Send_Data[i++] = '=';
	for(k=0;k<6;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.Res[0][k],&Send_Data[i],1);
		i = i+len;
		if(k<5)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	//Res2=
	Send_Data[i++] = 'R';
	Send_Data[i++] = 'e';
	Send_Data[i++] = 's';
	Send_Data[i++] = '2';
	Send_Data[i++] = '=';
	for(k=0;k<6;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.Res[1][k],&Send_Data[i],1);
		i = i+len;	
		if(k<5)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	//Res3=
	Send_Data[i++] = 'R';
	Send_Data[i++] = 'e';
	Send_Data[i++] = 's';
	Send_Data[i++] = '3';
	Send_Data[i++] = '=';
	for(k=0;k<6;k++)
	{
		len = Chage_fdata_to_ascii(Myboard.Res[2][k],&Send_Data[i],1);
		i = i+len;	
		if(k<5)	Send_Data[i++] = ',';
		else	Send_Data[i++] = ';';
	}
	//ALM=
	Send_Data[i++] = 'A';
	Send_Data[i++] = 'L';
	Send_Data[i++] = 'M';
	Send_Data[i++] = '=';
	for(k=0;k<70;k++)
	{
		Send_Data[i++] = Myboard.Alarm_Value[k];		
	}
	Send_Data[i++] = ';';
	//Relay=
	Send_Data[i++] = 'R';
	Send_Data[i++] = 'e';
	Send_Data[i++] = 'l';
	Send_Data[i++] = 'a';
	Send_Data[i++] = 'y';
	Send_Data[i++] = '=';
	for(k=0;k<16;k++)
	{
		Send_Data[i++]=Myboard.Relay_Value[k];		
	}
	
	Send_Data[i++] = 'C';
	Send_Data[i++] = 'C';
	Send_Data[i++] = ';';
	Send_Data[i++] = ';';
	Send_Data[i++] = ';';	
	
//	UART4_TxCircle_String(Send_Data,i);
	USART3_4_TxCircle_String(USARTx, Send_Data,i);
}






/***************END OF FILE***********************************************/

