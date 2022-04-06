#include "TemperatureDriver.h"




//3.418v
static uint16_t NTCTAB[25]=
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
static uint16_t NTCTAB2[25]=
{
0x91C7,0x8DD7,0x88F6,0x8313,0x7C29,0x7446,0x6B90,0x623E,
0x5897,0x4EE8,0x457B,0x3C90,0x3454,0x2CE4,0x264C,0x2088,
0x1B8F,0x174F,0x13B3,0x10A7,0x0E17,0x0BEF,0x0A21,0x089D,
0x0757
};


//查表函数
uint8_t look_up_table(uint16_t *a,uint8_t ArrayLong,uint16_t data)
{    
	uint16_t begin,end,middle ;  
	uint8_t i ;  
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


//输入表的序号值，得到温度值
float num_to_temperature(uint8_t num)
{
	float  data;
	data = 5*num-20;
	return data;
}


//
void save_ntc_data(uint16_t data)
{
	uint8_t num;
	float t1,tx;	
	
	if( (data<=NTCTAB[0]) && (data>NTCTAB[24]))
	{
		num=look_up_table(NTCTAB,25,data);
		t1=num_to_temperature(num);
		tx=5.0*(NTCTAB[num]-data)/(NTCTAB[num]-NTCTAB[num+1])+t1;
//		power_manage.temperature_ntc = tx*10;		//新版本未接	
	}
}

void save_ntc2_data(uint16_t data)
{
	uint8_t num;
	float t1,tx;	
	
	if( (data<=NTCTAB2[0]) && (data>NTCTAB2[24]))
	{
		num=look_up_table(NTCTAB2,25,data);
		t1=num_to_temperature(num);
		tx=5.0*(NTCTAB2[num]-data)/(NTCTAB2[num]-NTCTAB2[num+1])+t1;
		power_manage.temperature = tx*10;
	}
}

