#ifndef __TESTMODE_H__
#define __TESTMODE_H__

#include "sys.h"		    

#define RS485_TMTX_LEN	16
#define RS485_TMRXACK_LEN		8

#define CAN_TMTX_LEN	8
#define CAN_TMRXACK_LEN		8
#define TX_TINTERV		2		//


extern u8 rs485_tm_rxack[RS485_TMRXACK_LEN];
extern u8 can_tm_rxack[CAN_TMRXACK_LEN];
extern u8 tm_rs485_rxflag;
extern u8 tm_can_rxflag;

extern void rs485_tm_senddata(void);
extern void rs485_tm_sendack(void);
extern void can_tm_senddata(void);
extern void can_tm_sendack(void);

#endif
