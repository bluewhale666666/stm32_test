#include "ds18b20.h"



////��λDS18B20
//void DS18B20_Rst(void)	   
//{                 
//	DS18B20_IO_OUT(); //SET PA0 OUTPUT
//	DS18B20_DQ_OUT=0; //����DQ
//	delay_us(750);    //����750us
//	DS18B20_DQ_OUT=1; //DQ=1 
//	delay_us(15);     //15US
//}

//�ȴ�DS18B20�Ļ�Ӧ
//����1:δ��⵽DS18B20�Ĵ���
//����0:����
//u8 DS18B20_Check(void) 
//{   
//	u8 retry=0;
//	
//	DS18B20_IO_IN();//SET PA0 INPUT
//	
//  while (DS18B20_DQ_IN&&retry<200)
//	{
//		retry++;
//		delay_us(1);
//	};	 
//	if(retry>=200)	return 1;
//	else retry=0;
//  
//	while (!DS18B20_DQ_IN&&retry<240)
//	{
//		retry++;
//		delay_us(1);
//	};
//	
//	if(retry>=240)
//	{
//		printf("\n\rδ��⵽DS18B20�Ĵ���\r\n");
//		return 1;	 
//	}		
//	return 0;
//}

////��DS18B20��ȡһ��λ
////����ֵ��1/0
//u8 DS18B20_Read_Bit(void) 			 // read one bit
//{
//  u8 data;
//	
//	DS18B20_IO_OUT();//SET PA0 OUTPUT
//  DS18B20_DQ_OUT=0; 
//	delay_us(2);
//  DS18B20_DQ_OUT=1; 
//	DS18B20_IO_IN();//SET PA0 INPUT
//	delay_us(12);
//	
//	if(DS18B20_DQ_IN)
//		data=1;
//  else 
//		data=0;	 
//  delay_us(50);
//	
//  return data;
//}

//��DS18B20��ȡһ���ֽ�
//����ֵ������������
//u8 DS18B20_Read_Byte(void)    // read one byte
//{        
//	u8 i,j,dat;
//	dat=0;
//	
//	for (i=1;i<=8;i++) 
//	{
//		j=DS18B20_Read_Bit();
//		dat=(j<<7)|(dat>>1);
//  }						    
//  return dat;
//}
//дһ���ֽڵ�DS18B20
//dat��Ҫд����ֽ�
//void DS18B20_Write_Byte(u8 dat)     
//{             
//	u8 j;
//	u8 testb;
//	
//	DS18B20_IO_OUT();//SET PA0 OUTPUT;
//  for (j=1;j<=8;j++) 
//	{
//		testb=dat&0x01;
//		dat=dat>>1;
//		if (testb) 
//		{
//				DS18B20_DQ_OUT=0;// Write 1
//				delay_us(2);                            
//				DS18B20_DQ_OUT=1;
//				delay_us(60);             
//		}
//		else 
//		{
//				DS18B20_DQ_OUT=0;// Write 0
//				delay_us(60);             
//				DS18B20_DQ_OUT=1;
//				delay_us(2);                          
//		}
//  }
//}

////��ʼ�¶�ת��
//void DS18B20_Start(void)// ds1820 start convert
//{   						               
//  DS18B20_Rst();	   
//	DS18B20_Check();	 
//  DS18B20_Write_Byte(0xcc);// skip rom
//  DS18B20_Write_Byte(0x44);// convert
//} 
////��ʼ��DS18B20��IO�� DQ ͬʱ���DS�Ĵ���
////����1:������
////����0:����    	 
//u8 DS18B20_Init(void)
//{
// 	GPIO_InitTypeDef  GPIO_InitStructure;
// 	
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PORTA��ʱ�� 
//	
// 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				//PORTA0 PORTA11�������
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(GPIOA, &GPIO_InitStructure);

// 	GPIO_SetBits(GPIOA,GPIO_Pin_11);    //���11

//	DS18B20_Rst();

//	return DS18B20_Check();
//} 

////��ds18b20�õ��¶�ֵ
////���ȣ�0.1C
////����ֵ���¶�ֵ ��-550~1250�� 
//short DS18B20_Get_Temp(void)
//{
//  u8 temp;
//  u8 TL,TH;
//	short tem;
//	
//	DS18B20_Start ();                    // ds1820 start convert
//	DS18B20_Rst();
//	DS18B20_Check();	 
//	DS18B20_Write_Byte(0xcc);// skip rom
//	DS18B20_Write_Byte(0xbe);// convert	    
//	TL=DS18B20_Read_Byte(); // LSB   
//	TH=DS18B20_Read_Byte(); // MSB  
//				
//	if(TH>7)		//�¶�Ϊ��  
//	{
//			TH=~TH;
//			TL=~TL; 
//			temp=0;
//	}
//	else 				//�¶�Ϊ��	  	
//		temp=1; 
//	
//	tem=TH; //��ø߰�λ
//	tem<<=8;    
//	tem+=TL;//��õװ�λ
//	tem=(float)tem*0.625;//ת��     
//	if(temp)
//		return tem; //�����¶�ֵ
//	else 
//		return -tem;    
//} 

 
//��λֵ�˲���
//A������
//    ��������N�Σ�Nȡ������
//    ��N�β���ֵ����С����
//    ȡ�м�ֵΪ������Чֵ
//B�ŵ㣺
//    ����Ч�˷���żȻ��������Ĳ�������
//    ���¶ȡ�Һλ�ı仯�����ı�����������õ��˲�Ч��
//Cȱ�㣺
//    ���������ٶȵȿ��ٱ仯�Ĳ�������


//�洢ds18b20����		
//void mode_save_ds18b20_data(u8 mode)
//{

//	if(0==mode)		//����ģʽ
//	{
//		if(time_ds18b_flag)			//1s
//		{
//			time_ds18b_flag=0;
//			
//			save_ds18b20_data();			
//		}		
//	}
//	else					//����ģʽ���ŵ������ϴ��������棬�ɼ�Ƶ�ʺ��ϴ�Ƶ��һ��
//	{
//		save_ds18b20_data();
//	}
//}


////u8 const duty0[7]={0,30,40,60,80,95};
//u8 last_duty=0;

////�洢ds18b20����
//void save_ds18b20_data(void)
//{
//	static short value_buf[7];
//	static u8 count=0;
//	short temp;
//  u8 i,j;

//	if(count<7)
//	{
//		value_buf[count++]=DS18B20_Get_Temp();
//	}
//	else
//	{
//		//��λֵ�˲���
//		for(j=0;j<6;j++)
//		{
//			for(i=0;i<7-j;i++)
//			{
//				 if(value_buf[i]>value_buf[i+1])
//				 {
//						temp = value_buf[i];
//						value_buf[i] = value_buf[i+1]; 
//						value_buf[i+1] = temp;
//				 }
//			}
//		}
//		
//		power_manage.temperature_ntc = value_buf[3];
//		
//		//���ȿ���������£���ִ���������
//		if(power_manage.p_constate.b.FAN_RUN)		//���ȿ���
//		{
//			//���ȣ�0.1C	�¶�ֵ ��-550~1250��
//			if(power_manage.temperature_ntc<250)			//	<25.0		-------->30%
//			{
//				if(30 != last_duty)
//				{
//					tim8_PWM_init(30);
//					last_duty = 30;
//				}						
//			}
//			if((power_manage.temperature_ntc>255)&&(power_manage.temperature_ntc<350))		//	25.5-35.0		-------->40%
//			{
//				if(40 != last_duty)
//				{
//					tim8_PWM_init(40);
//					last_duty = 40;
//				}
//			}				
//			if((power_manage.temperature_ntc>355)&&(power_manage.temperature_ntc<450))		//	35.5-45.0		-------->60%
//			{
//				if(60 != last_duty)
//				{
//					tim8_PWM_init(60);
//					last_duty = 60;
//				}
//			}
//			if((power_manage.temperature_ntc>455)&&(power_manage.temperature_ntc<550))		//	45.5-55.0		-------->80%
//			{
//				if(80 != last_duty)
//				{
//					tim8_PWM_init(80);
//					last_duty = 80;
//				}
//			}
//			if((power_manage.temperature_ntc>555))		//	>55.5		-------->95%
//			{
//				if(95 != last_duty)
//				{
//					tim8_PWM_init(95);
//					last_duty = 95;
//				}
//			}			
//		}
//		else				//�ر�PWM���
//		{
//			if(10 != last_duty)			//<20���ر�
//			{
//				tim8_PWM_init(10);
//				last_duty = 10;
//			}
//		}		
//		
////�¶��ж���Alarm_Manage()
////			if(power_manage.temperature>power_manage.temperature_h)	
////			{
////				power_manage.p_breakdownl.b.TEMP_H = 1;
////			}
////			else
////			{
////				power_manage.p_breakdownl.b.TEMP_H = 0;	
////			}
//		
//		count=0;
//		value_buf[count++] = DS18B20_Get_Temp();
//	}
//}

//3.418v
static u16 NTCTAB[25]=
{
//0x67C7,0x66FB,0x6604,0x64DF,0x6385,0x61F2,0x601F,0x5E08,
//0x5BA9,0x5902,0x5615,0x52E5,0x4F7A,0x4BDC,0x4817,0x4434,
//0x403E,0x3C43,0x384C,0x3464,0x3096,0x2CEA,0x2967,0x2614,
//0x22F4
	
//3.35v	
0x65B6,0x64EE,0x63FD,0x62DD,0x618A,0x5FFF,0x5E35,0x5C29,
0x59D6,0x573D,0x545E,0x513F,0x4DE5,0x4A5A,0x46A7,0x42D8,
0x3EF7,0x3B10,0x372D,0x335A,0x2F9F,0x2C05,0x2894,0x2552,
0x2242
	
//0x66FC,0x6661,0x6598,0x6495,0x634D,0x61B4,0x5FBD,0x5D5D,
//0x5A89,0x573D,0x5377,0x4F3D,0x4A9B,0x45A6,0x4075,0x3B24,
//0x35D1,0x3099,0x2B95,0x26D8,0x226F,0x1E64,0x1ABB,0x1773,
//0x1488
};


//5.05v
static u16 NTCTAB2[25]=
{
0x91C7,0x8DD7,0x88F6,0x8313,0x7C29,0x7446,0x6B90,0x623E,
0x5897,0x4EE8,0x457B,0x3C90,0x3454,0x2CE4,0x264C,0x2088,
0x1B8F,0x174F,0x13B3,0x10A7,0x0E17,0x0BEF,0x0A21,0x089D,
0x0757
};


//�����
u8 look_up_table(u16 *a,u8 ArrayLong,u16 data)
{    
	u16 begin,end,middle ;  
	u8 i ;  
	begin = 0 ;  
	end = ArrayLong-1 ;  
	i = 0  ;  
	if(data >= a[begin]) return begin ;  
	else if(data <= a[end]) return end ;  
	while(begin < end)  
	{  
		middle = (begin+end)/2 ;  
		if(data == a[middle] ) break ;  
		if(data < a[middle] && data > a[middle+1]) break ;   
		if(data > a[middle])  end = middle ;                      
		else begin = middle ;      
		if(i++ > ArrayLong) break ;  
	}  
	if(begin > end ) return 0 ;   
	return middle ;  
}


//���������ֵ���õ��¶�ֵ
float num_to_temperature(u8 num)
{
	float  data;
	data = 5*num-20;
	return data;
}


//
void save_ntc_data(u16 data)
{
	u8 num;
	float t1,tx;	
	
	if( (data<=NTCTAB[0]) && (data>NTCTAB[24]))
	{
		num=look_up_table(NTCTAB,25,data);
		t1=num_to_temperature(num);
		tx=5.0*(NTCTAB[num]-data)/(NTCTAB[num]-NTCTAB[num+1])+t1;
		power_manage.temperature_ntc = tx*10;		//�°汾δ��
		
		
//		if(adcok_flag==1)
//		{
//			//���ȿ���������£���ִ���������
////			if(power_manage.p_constate.b.FAN_RUN)		//���ȿ���
//			{
//				//���ȣ�0.1C	�¶�ֵ ��-550~1250��
//				if(power_manage.temperature_ntc<250)			//	<25.0		-------->30%
//				{
//					if(30 != last_duty)
//					{
//						tim8_PWM_init(30);
//						last_duty = 30;
//					}						
//				}
//				if((power_manage.temperature_ntc>255)&&(power_manage.temperature_ntc<350))		//	25.5-35.0		-------->40%
//				{
//					if(40 != last_duty)
//					{
//						tim8_PWM_init(40);
//						last_duty = 40;
//					}
//				}				
//				if((power_manage.temperature_ntc>355)&&(power_manage.temperature_ntc<450))		//	35.5-45.0		-------->60%
//				{
//					if(60 != last_duty)
//					{
//						tim8_PWM_init(60);
//						last_duty = 60;
//					}
//				}
//				if((power_manage.temperature_ntc>455)&&(power_manage.temperature_ntc<550))		//	45.5-55.0		-------->80%
//				{
//					if(80 != last_duty)
//					{
//						tim8_PWM_init(80);
//						last_duty = 80;
//					}
//				}
//				if((power_manage.temperature_ntc>555))		//	>55.5		-------->95%
//				{
//					if(95 != last_duty)
//					{
//						tim8_PWM_init(95);
//						last_duty = 95;
//					}
//				}			
//			}
//			else				//�ر�PWM���
//			{
//				if(0 != last_duty)			//<20���ر�
//				{
//					tim8_PWM_init(0);
//					last_duty = 0;
//				}
//			}
//		}
	}
}

void save_ntc2_data(u16 data)
{
	u8 num;
	float t1,tx;	
	
	if( (data<=NTCTAB2[0]) && (data>NTCTAB2[24]))
	{
		num=look_up_table(NTCTAB2,25,data);
		t1=num_to_temperature(num);
		tx=5.0*(NTCTAB2[num]-data)/(NTCTAB2[num]-NTCTAB2[num+1])+t1;
		power_manage.temperature_ntc2 = tx*10;
	}
}

