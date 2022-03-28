#include "keypad.h"
#include "delay.h"
#include "jlx19264g.h"

//												0			1			2			3			4			5			6			7			8			9			.		11		12		13		14	 ENTER
const char keycode[16]={0xde, 0xb7, 0xd7, 0xe7, 0xbb, 0xdb, 0xeb, 0xbd, 0xdd, 0xed, 0xbe, 0x77, 0x7b, 0x7d, 0x7e, 0xee};


uint16_t keyscan(void)
{
	unsigned char i,j,k,lop;
	GPIOC->CRL = 0x88883333;   	//8 上拉/下拉输入 3 推挽输出   高4位输入	低4位推挽输出
	GPIOC->BSRR = 0xf0;        	//GPIOC->BSRR = 0x80; 置’1'		GPIOC->BRR = 0x80; 置'0'
	GPIOC->BRR = 0x0f;					//GPIOx_BSRR的高16位称作清除寄存器，而GPIOx_BSRR的低16位称作设置寄存器
	delay_ms(20);
	i = 0; lop = 1;
	
	while(lop)
	{
			while ((GPIOC->IDR & 0xf0) == 0xf0)
			{
					delay_ms(10);
			}
			i = GPIOC->IDR & 0xf0;
			delay_ms(20);
			if (i == (GPIOC->IDR & 0xf0)) lop=0;
	}
	GPIOC->CRL = 0X33338888;
	GPIOC->BSRR = 0xf;
	GPIOC->BRR = 0xf0;
	delay_ms(20);
	j = (GPIOC->IDR & 0x0f);
	j = j|i;
	k = 0xff;
	for (i = 0; i <= 15; i++)
	{
		if (j == keycode[i])
		{
				k = i; 
		}
	}
	GPIOC->CRL = 0x88883333;
	GPIOC->BSRR = 0xf0;
	GPIOC->BRR = 0xf;
	while ((GPIOC->IDR & 0xf0) != 0xf0);  //等待按键松开
	
	return k;
}

uint16_t keyread(void)
{
	unsigned char a;
	a=0xff;
	if((GPIOC->IDR & 0xf0) != 0xf0)
	{
			delay_ms(20);
			if((GPIOC->IDR & 0xf0) != 0xf0) a = keyscan();
	}
	return a;
}

uint8_t IsKeyDown(void)
{
	GPIOC->CRL = 0x88883333;   		//8 上拉/下拉输入 3 推挽输出   高4位端口7...第四位端口0
	GPIOC->BSRR = 0xf0;           //BSRR 高16位置1位低电平，低16位置一位高电平
	GPIOC->BRR = 0xf;
	
	delay_ms(10);
	
	if((GPIOC->IDR & 0xF0) != 0xF0)
	{
		return 1;
	}
	else 
		return 0;
}


uint16_t inputpasswd(unsigned char row, unsigned char col)
{
    uint16_t x;
    unsigned char k,i,numstr[]="                "; // 存放数字串(不大于9位)
    i=0;
    while(i < 4)
    {
				display_GB2312_string(row, col + i*8, cursor);
        k=keyscan();
        if(k<=9)
        {
					display_GB2312_int(row, col + i*8, k+0x30);
					numstr[i]=k+0x30;
					i++;
        }   // 显示0－9
				while(IsKeyDown());
    }

		numstr[i]=0;
		rstr=&numstr[0];
		x=atoi((const char *)rstr); //转换字符串为浮点数
		
    return x;	
}


float inputnum(unsigned char row,unsigned char col) 		// 读键盘，输入浮点数
{
    float x;
    unsigned char k,i,numstr[]="                "; // 存放数字串(不大于9位)
    i=0;x=-500011;
    while(1)
    {
				display_GB2312_string(row, col + i*8, cursor);
        k=keyscan();
        if(k<=9)
        {
					display_GB2312_int(row, col + i*8, k+0x30);
					numstr[i]=k+0x30;
					i++;
        }   // 显示0－9
        if(k==10)
        {
					display_GB2312_string(row, col + i*8, ".");
					numstr[i]=0x2e;
					i++;
        }   // 显示小数点
        if((i>9)&&(k<=10)) 
        {
					i--;
					display_GB2312_string(row, col + i*8, " ");
					numstr[i]=32;
        }   // 输入的数字超长(超过15位)清除最后1个字符
        if(k==11) // DISPLAY键(退格或返回上一级菜单)
        {
            if(i>0) // 清除最后1个字符
            {
							i--; 
							display_GB2312_string(row, col + i*8, " ");
							numstr[i]=32;
            }
            else break;
        }
        if(k==15) // ENTER键
        {
            if(i==0)goto ret; //未输入数字就按ENTER键，返回非法数字
            numstr[i]=0;
            rstr=&numstr[0];
            x=atof((const char *)rstr); 		//转换字符串为浮点数
						display_GB2312_string(row, col + i*8, " ");//清除光标
            break;
        }
				while(IsKeyDown());
    }
ret:
    return x;
}

//读键盘，输入浮点数,动态显示电容
float inputdsp(unsigned char row,unsigned char col)
{
    float x;
    unsigned char k,i,numstr[]="                ";
    i=0;x=0xff;		//x=-500011;
    dyn=1; 				//允许动态显示电容
    while(1)
    {
				lcd_col=col+i*8;lcd_row=row;
				display_GB2312_string(row,col + i*8,cursor);   //打开光标
        k=keyscan();
        if(k<=9) 	// 显示0－9
				{
					display_GB2312_int(row,col + i*8, k+0x30);
					numstr[i]=k+0x30;i++;
				}
        if(k==10) // 显示小数点
				{
					display_GB2312_int(row,col + i*8, 0x2e);
					numstr[i]=0x2e;i++;
				}
        if((i>9)&(k<=10))	// 输入的数字超长(超过15位)清除最后1个字符
        {
					i--;
					display_GB2312_int(row,col + i*8, 32);
					numstr[i]=32;
        }
        if(k==11) 	// DISPLAY键(退格或返回上一级菜单)
        {
            if(i>0) // 清除最后1个字符
            {
                i--; 
								display_GB2312_int(row,col + i*8, 32);
                numstr[i]=32;
            }
            else break;
        }
        if(k==15) 	// ENTER键
        {
            numstr[i]=0;
            rstr=&numstr[0];
            x=atof((const char *)rstr); 
            break;
        }
				while(IsKeyDown());
    }
    dyn=0; 		// 禁止动态显示电容
    return x;
}



/***************END OF FILE***********************************************/
