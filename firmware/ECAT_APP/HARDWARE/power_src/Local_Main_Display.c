#include "Local_Main_Display.h"

//
//数据上传分两种方式，一种到客户端，一种到服务器



//自动上传数据到web端服务器，间隔30s
void Auto_Send_Data_To_X80X_30s(USART_TypeDef* USARTx)
{
	if(!Time_100ms2)
	{
		Auto_Send_XXXX_Data_To_X80X(USARTx);		//上传数据至服务器	！！！！！！！！！！！！！！！！！
		Time_100ms2 = 300;					//需要30s间隔再发	30*10
	}			
}

//自动上传数据到客户端（触摸屏），间隔可以设定
void Auto_Send_Data_To_Touchscreen_Timming(USART_TypeDef* USARTx)
{

	if(1==Send_Enable_Flag)							//发送使能
	{
		if((1==Alarm_Appear_Flag)&&(0==Alarm_Send_Over_Flag))			//有报警发生，且未发送完成，立即发送
		{
			if(0==Alarm_Send_Repeat_Number)
			{
				Auto_Send_XXXX_Data(USARTx);							//自动上传数据发送	！！！！！！！！！！！！！！！！！
				Alarm_Send_Repeat_Number++;							//重复上传次数加一
				Time_100ms = Alarm_Over_Updata_Time;		//需要按报警间隔再发
			}
			else
			{
				if(!Time_100ms)
				{
					Auto_Send_XXXX_Data(USARTx);							//自动上传数据发送	！！！！！！！！！！！！！！！！！
					Alarm_Send_Repeat_Number++;					//重复上传次数加一
					
					if(Alarm_Send_Repeat_Number < Alarm_Repeat_Send_Max_Number)		//重复次数判断，未达到最终次数
					{
						Time_100ms = Alarm_Over_Updata_Time;		//需要按报警间隔再发
					}
					else			//达到上传次数了
					{
						Alarm_Send_Over_Flag = 1;							//发送完成
						Time_100ms = Send_UpLoad_Time;					//需要按定时上传间隔再发
					}	
				}
			}			
		}
		else			//自动发送使能,数据定时上传
		{
			Alarm_Send_Repeat_Number=0;						
			
			if(!Time_100ms)
			{
				Auto_Send_XXXX_Data(USARTx);							//自动上传数据发送	！！！！！！！！！！！！！！！！！
				Time_100ms = Send_UpLoad_Time;					//需要按定时上传间隔再发
			}			
		}		
	}
}



//自动上传数据发送函数	Usart3 or Uart4	
void	Auto_Send_XXXX_Data_To_X80X(USART_TypeDef* USARTx)
{
	char 	Send_Data[1000];//,Temp_Data[6];
	
	uint8_t 	len;
	uint16_t 	i,k;

	memset(Send_Data,'0',1000);		//数组清'0'
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
	//a1表示温度1报警，b1表示湿度1报警	
	//4路温湿度=8
	for(k=0;k<8;k++)
	{
		Send_Data[i++] = Myboard.Alarm_Value[k];		
	}
	//4路SF6
	Send_Data[i++] = Myboard.Alarm_Value[16];		
	Send_Data[i++] = Myboard.Alarm_Value[17];	
	Send_Data[i++] = Myboard.Alarm_Value[18];		
	Send_Data[i++] = Myboard.Alarm_Value[19];	
	//2路O2
	Send_Data[i++] = Myboard.Alarm_Value[24];		
	Send_Data[i++] = Myboard.Alarm_Value[25];		
	//2路O3
	Send_Data[i++] = Myboard.Alarm_Value[32];	
	Send_Data[i++] = Myboard.Alarm_Value[33];		
	//2路水位
	Send_Data[i++] = Myboard.Alarm_Value[40];	
	Send_Data[i++] = Myboard.Alarm_Value[41];	
//	//2路res
//	Send_Data[i++] = '0';	
//	Send_Data[i++] = '0';	
	
	//c1c2c3c4c5c6c7c8c9烟感
	Send_Data[i++] = Myboard.Alarm_Value[48];	
	Send_Data[i++] = Myboard.Alarm_Value[49];	
	Send_Data[i++] = Myboard.Alarm_Value[50];	
	Send_Data[i++] = Myboard.Alarm_Value[51];		
	Send_Data[i++] = Myboard.Alarm_Value[52];			//红外双鉴1
	Send_Data[i++] = Myboard.Alarm_Value[53];			//红外双鉴2
	Send_Data[i++] = Myboard.Alarm_Value[54];			//红外对射1
	Send_Data[i++] = Myboard.Alarm_Value[55];			//红外对射2
	Send_Data[i++] = '0';	
	//def预留
	Send_Data[i++] = Myboard.Alarm_Value[63];			//干接点预留
	Send_Data[i++] = '0';	
	Send_Data[i++] = '0';	
	//g1g2g3g4g5g6g7g8g9停电
	Send_Data[i++] = Myboard.Alarm_Value[45];			//直流断电
	Send_Data[i++] = Myboard.Alarm_Value[44];			//交流断电
	Send_Data[i++] = Myboard.Alarm_Value[47];			//门磁2
	Send_Data[i++] = Myboard.Alarm_Value[57];			//漏水2
	Send_Data[i++] = Myboard.Alarm_Value[58];			//sf6
	Send_Data[i++] = Myboard.Alarm_Value[59];			//主变温1
	Send_Data[i++] = Myboard.Alarm_Value[60];			//主变温2
	Send_Data[i++] = Myboard.Alarm_Value[61];			//主变温3
	Send_Data[i++] = Myboard.Alarm_Value[62];			//主变温4
	//hijklmnopqrst
	//h漏水;
	Send_Data[i++] = Myboard.Alarm_Value[56];			//漏水1
	//i红外感应/门磁/门禁;
	Send_Data[i++] = Myboard.Alarm_Value[46];			//门磁1
	//j消防;
	Send_Data[i++] = '0';	
	//kUPS1;
	Send_Data[i++] = '0';	
	//LUPS2;
	Send_Data[i++] = '0';	
	//m空调1;
	Send_Data[i++] = '0';	
	//n空调2;
	Send_Data[i++] = '0';	
	//o市配电/电量仪1;
	Send_Data[i++] = '0';	
	//p市配电/电量仪2;
	Send_Data[i++] = '0';	
	//q电池组
	Send_Data[i++] = '0';	
	//r防雷
	Send_Data[i++] = '0';	
	//st预留，默认00；
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
	Send_Data[i++] = '+';				//不能少!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
	Send_Data[i++] = '+';				//不能少!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
	Send_Data[i++] = 0x0d;		//回车换行
	Send_Data[i++] = 0x0a;

	USART3_4_TxCircle_String(USARTx, Send_Data,i);
}


//自动上传数据发送函数 Usart3 or Uart4	
void	Auto_Send_XXXX_Data(USART_TypeDef* USARTx)
{
	char 	Send_Data[1000];//,Temp_Data[6];
	
	uint8_t 	len;
	uint16_t 	i,k;
//	uint16_t 	j;

	memset(Send_Data,'0',1000);		//数组清'0'
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

