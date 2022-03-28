#include "Debug_Data_Send.h"

//后台配置处理函数
void Postern_Config_Inquiry(void)
{
	uint8_t i;
	char Rev1_frame[RXD1_MAX_NUM],Send1_frame[TXD1_MAX_NUM];

	if(1==Rx1Status)
	{
		Rx1Status = 0;
	
		for(i=0;i<Rxd1_Da_Num;i++)
		{
			Rev1_frame[i] = Rxd1_Buff[i];
			Rxd1_Buff[i]=0;
		}

		Rxd1_Da_Num = 0;
	}
}



/***************END OF FILE***********************************************/

