#ifndef _INCAPPL_H
#define _INCAPPL_H
#include "sys.h"
#include "ecat_def.h"

#define MAX_INC_COUNT	65535

void INC_GetIncZLatch(void);
INT32 INC_GetIncABValue(void);

extern u16 g_nEncoderPerRotate;

//----------------------�����ŷ��̼����Ż�INC����------------------------
typedef u16    HT_T_U16;
typedef INT16  HT_T_I16;
typedef u32    HT_T_U32;
typedef INT32  HT_T_I32;
typedef INT64  HT_T_I64;

HT_T_U16 WrapU16 (HT_T_I64 wInput, HT_T_I32 MotEncPerRotate);
void INC_Process(INT32 QPOSCNT, INT32 IncLatchByZ);

extern INT32 ValidQPOSCNT;

#endif
