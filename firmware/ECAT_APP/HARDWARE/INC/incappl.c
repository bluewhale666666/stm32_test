#include "incappl.h"
#include "timer.h"
#include "hw_readwrite.h" 

// 调试INC宏定义
#define DEBUG_INC  1

#ifdef DEBUG_INC
	INT32 g_nTestErrorValue = 0; // 拟定INC计数误差
	INT32 g_nTestABCountValue = 0;
	INT32 g_nTestZLaunchValue = 0;
	INT32 g_nTestABCountSource = 0;
#endif

INT32 g_nEncodeZLatch;  // INC编码器锁存值
uint32_t g_nIncDir;		// INC编码器旋转方向，注：目前未使用该功能，但已验证可用

// 获取AB相INC计数
INT32 INC_GetIncABValue(void)
{
	static UINT16 _s_nINCLastData = 0;
	static UINT16 _s_nINCNowData = 0;
	static INT32 _s_nABCount = 0;
	
	uint32_t _nIncCnt;
	ENCODER_Read(&g_nIncDir, &_nIncCnt); 
	_s_nINCNowData = (UINT16)_nIncCnt;
	_s_nABCount += (INT32)(INT16)(_s_nINCNowData - _s_nINCLastData);
	
#ifdef DEBUG_INC
	g_nTestABCountValue = _s_nABCount + g_nTestErrorValue;
	g_nTestZLaunchValue = g_nEncodeZLatch + g_nTestErrorValue;
	g_nTestABCountSource = _s_nABCount;
	INC_Process(g_nTestABCountValue, g_nTestZLaunchValue);
#else
	INC_Process(_s_nABCount, g_nEncodeZLatch);
#endif
	
	_s_nINCLastData = _s_nINCNowData;
	return _s_nABCount;
}


void INC_GetIncZLatch(void)
{
	static INT32 _s_nZLatch = 0;
	static INT16 _s_nINCLastLatchData = 0;
	static INT16 _s_nINCNowLatchData = 0;

	_s_nINCNowLatchData = (UINT16)(TIM_GetCapture3(TIM3));	
	_s_nZLatch += (INT32)(INT16)(_s_nINCNowLatchData - _s_nINCLastLatchData);
	g_nEncodeZLatch = _s_nZLatch;		
	_s_nINCLastLatchData = _s_nINCNowLatchData;
}

//----------------------参照伺服固件，优化INC功能------------------------
#define _ABS(A) ((A) > 0) ? (A) : (0 - (A))

HT_T_U16 WrapU16 (HT_T_I64 wInput, HT_T_I32 MotEncPerRotate)//(done)
{
    if(wInput >= 0)
    {
        wInput = wInput % MotEncPerRotate;
    }
    else
    {
        wInput = (wInput % MotEncPerRotate) + MotEncPerRotate;
    }
    return( (HT_T_U16)(wInput * 65536 / MotEncPerRotate));
}

BOOL StateofQEP = 0;
INT32 ValidQPOSCNT = 0;
INT32 ValidIncLatchByZ = 0;
INT32 IncWhenLatched_Pre = 0;
HT_T_U16 wTargetPosi = 0;
INT32 IncLatchByZ_Pre = 0;
INT32 InputIncrease = 0;
HT_T_U16 wFBKPosiTemp = 0;
HT_T_I32  INC_correct = 0;
HT_T_U16 Inc_temp = 0;//(for error check)
void INC_Process(INT32 QPOSCNT, INT32 IncLatchByZ)
{
	HT_T_I32 IncErrorIntegrator_now;
 //   HT_T_U16 Inc_temp = 0;//(for error check)
    HT_T_U16 PolePair = 8;
    HT_T_I32 MotEncPerRotate = 8000;//g_nEncoderPerRotate * 4;//8000;//15040;
    HT_T_I32 MaxErrorIntegrator = WrapU16 (MotEncPerRotate / (PolePair * 12), MotEncPerRotate);//U16 off limit
    HT_T_I32 IncErrorIntegrator = 0;
    HT_T_U16 FBKPosi[5] = {0,0,0,0,0};
   // static HT_T_I32  INC_correct = 0;
    /**************(done) execute adjust****************/
    QPOSCNT = QPOSCNT + INC_correct;
    IncLatchByZ = IncLatchByZ + INC_correct;
    ValidQPOSCNT = QPOSCNT;
    ValidIncLatchByZ = IncLatchByZ;

    if (1) //INC检测状态有效 (IsSysMode1ParaReq) (done) only check error after system on-power period, waiting for parameters
    {
        IncWhenLatched_Pre = (IncWhenLatched_Pre == 0) ? (QPOSCNT) : IncWhenLatched_Pre; //no error check if Pre = 0 time point.
        IncLatchByZ_Pre = (IncLatchByZ_Pre == 0 )? IncLatchByZ: IncLatchByZ_Pre;// no error check if IncLatchByZ_Pre = 0 time point.
        InputIncrease = IncLatchByZ - IncLatchByZ_Pre;
        switch(StateofQEP)
        {
        case 0:
            if ( _ABS(InputIncrease) > 10 ) //a real Z latch comes
            {
                wTargetPosi = WrapU16(IncLatchByZ,MotEncPerRotate); //(done)(update 1 wTargetPosi)(to be done)
                IncWhenLatched_Pre = QPOSCNT;//(done)(4 IncWhenLatched_Pre)//no error check if Pre = 0.
                IncLatchByZ_Pre = IncLatchByZ;//(done)(5 IncLatchByZ_Pre)// no error check if IncLatchByZ_Pre = 0
                StateofQEP = 1; //becoming the normal state
            }
            else
            {
                wTargetPosi = 0;//(done)(update 1 wTargetPosi)
                IncWhenLatched_Pre = IncWhenLatched_Pre;//(done)(4 IncWhenLatched_Pre)//no error check if Pre = 0.
                IncLatchByZ_Pre = IncLatchByZ_Pre;//(done)(5 IncLatchByZ_Pre)// no error check if IncLatchByZ_Pre = 0
                StateofQEP = StateofQEP;
            }
            IncErrorIntegrator = 0;//(update 2 IncErrorIntegrator) no error now
            INC_correct = INC_correct; //(done)(update 3 INC_correct) no action now
            break;
        case 1:
            wTargetPosi = wTargetPosi;//(update 1 wTargetPosi)
            if ( _ABS(InputIncrease) > 10 ) //triggered
            {
                wFBKPosiTemp = WrapU16(IncLatchByZ, MotEncPerRotate);
                //HT_T_I32 IncErrorIntegrator_now = (HT_T_I16)(wFBKPosiTemp - wTargetPosi); //(update 2 IncErrorIntegrator)
                IncErrorIntegrator_now = (HT_T_I16)(wFBKPosiTemp - wTargetPosi); //(update 2 IncErrorIntegrator)
							  if (    (IncErrorIntegrator_now != 0)
                        && (_ABS(_ABS(InputIncrease) - MotEncPerRotate) <= 40)
                   ) //(done)(update 3 INC_correct) (done)2019.1.3 no correction if too large error
                {
                    INC_correct = (IncErrorIntegrator_now > 0)? (INC_correct - 1):(INC_correct + 1);
                }
                else
                {
                    INC_correct = INC_correct;
                }
                //(delay the error check)

                if(1)  //没有INC报警(test)data logger
                {
                    FBKPosi[4] = FBKPosi[3];
                    FBKPosi[3] = FBKPosi[2];
                    FBKPosi[2] = FBKPosi[1];
                    FBKPosi[1] = FBKPosi[0];
                    FBKPosi[0] = wFBKPosiTemp;
                }

                Inc_temp =  (( _ABS((HT_T_I16)(FBKPosi[0] - wTargetPosi)) > (MaxErrorIntegrator) ) &&
                        ( _ABS((HT_T_I16)(FBKPosi[1] - wTargetPosi)) > (MaxErrorIntegrator) ) &&
                        ( _ABS((HT_T_I16)(FBKPosi[2] - wTargetPosi)) > (MaxErrorIntegrator) ) &&
                        ( _ABS((HT_T_I16)(FBKPosi[3] - wTargetPosi)) > (MaxErrorIntegrator) ) &&
                        ( _ABS((HT_T_I16)(FBKPosi[4] - wTargetPosi)) > (MaxErrorIntegrator) ) );
								// 根据temp进行INC报警;
                IncErrorIntegrator = IncErrorIntegrator_now;//update the previous error
                IncWhenLatched_Pre = QPOSCNT; //(done)(4 IncWhenLatched_Pre)
                IncLatchByZ_Pre = IncLatchByZ; //(done)(5 IncLatchByZ_Pre)
            }
            else
            {
                IncErrorIntegrator = IncErrorIntegrator;//(update 2 IncErrorIntegrator)
                INC_correct = INC_correct;//(done)(update 3 INC_correct)
                IncWhenLatched_Pre = IncWhenLatched_Pre;//(done)(4 IncWhenLatched_Pre)
                IncLatchByZ_Pre = IncLatchByZ_Pre;//(done)(5 IncLatchByZ_Pre)
            }
        default:
            break;
        }

       Inc_temp = _ABS(QPOSCNT - IncWhenLatched_Pre) > (MotEncPerRotate * 5 );//(done)(5 cycle detect no Z)
  //      根据temp进行NoZ报警;
    }
    else // doesn't change all when not checked.
    {
        wTargetPosi = wTargetPosi;//1
        StateofQEP = StateofQEP;//state
        IncErrorIntegrator = IncErrorIntegrator;//2
        INC_correct = INC_correct;//3
        IncLatchByZ_Pre = IncLatchByZ_Pre;//4
        IncWhenLatched_Pre = IncWhenLatched_Pre;//5
       // 所有INC相关故障清除;
    }
}




