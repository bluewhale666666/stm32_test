

#include "Crc16.h"

uint16_t CRC16_CCITT(uint8_t *ptr, uint8_t len)
{
	uint16_t crc=0;
	uint8_t da;
	while (len-- != 0) 
	{
		da = (uint8_t) (crc >> 8); /* 取CRC高8位 */
		crc <<= 8; /* 取CRC低8位  */
		crc ^= crc_table[da ^ (*ptr)]; 
		ptr++;
	}
	return (crc);	
}

