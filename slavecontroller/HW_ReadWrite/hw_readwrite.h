#ifndef __HW_READWRITE_H
#define __HW_READWRITE_H


#include "sys.h"
#include "ad_da_spi.h"
#include  "esc.h"







//#define	SPI_CS 		PBout(14)  		//SPI的片选信号

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/
#define ESC_RD                    0x02 /**< \brief Indicates a read access to ESC or EEPROM*/
#define ESC_WR                    0x04 /**< \brief Indicates a write access to ESC or EEPROM.*/

#define EOC 		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)  	//PC1
#define PNP 		GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15)  	//PG15
#define NPN 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)  	//PB5

/*---------------------------------------------
-    hardware timer settings
-----------------------------------------------*/

#define ECAT_TIMER_INC_P_MS                0x3e8 /**< \brief 1000 ticks per ms 这句话是说，1ms到底有多少计数，查一下定时器可以知道*/ 

extern BOOL AD8028WorkWell;


/*---------------------------------------------
-    Interrupt and Timer defines定时器的一些定义，这个到定时器的设定文件里找，我建议这个宏定义还是应该留着，看看具体别的函数里面定义再说
-----------------------------------------------*/
#ifndef DISABLE_ESC_INT
#define    DISABLE_ESC_INT()	   NVIC_DisableIRQ(EXTI1_IRQn)            /**< \brief Disable interrupt source INT1*/
#endif
#ifndef ENABLE_ESC_INT
#define    ENABLE_ESC_INT()      NVIC_EnableIRQ(EXTI1_IRQn)           /**< \brief Enable interrupt source INT1*/
#endif




//#ifndef HW_GetTimer
//#define HW_GetTimer()                    /**< \brief Access to the hardware timer*///就是定义这个获取定时器时间的值
//#endif

//#ifndef HW_ClearTimer
//#define HW_ClearTimer()                  /**< \brief Clear the hardware timer*/
//#endif





#define HW_EscReadWord(WordValue, Address) HW_EscRead(((UINT8 *)&(WordValue)),((u16)(Address)),2) /**< \brief 16Bit ESC read access*/
#define HW_EscReadDWord(DWordValue, Address) HW_EscRead(((UINT8 *)&(DWordValue)),((u16)(Address)),4) /**< \brief 32Bit ESC read access*/
#define HW_EscReadMbxMem(pData,Address,Len) HW_EscRead(((UINT8 *)(pData)),((u16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default read function is used.*/


#define HW_EscReadWordIsr(WordValue, Address) HW_EscReadIsr(((UINT8 *)&(WordValue)),((u16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC read access*/
#define HW_EscReadDWordIsr(DWordValue, Address) HW_EscReadIsr(((UINT8 *)&(DWordValue)),((u16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC read access*/



#define HW_EscWriteWord(WordValue, Address) HW_EscWrite(((UINT8 *)&(WordValue)),((u16)(Address)),2) /**< \brief 16Bit ESC write access*/
#define HW_EscWriteDWord(DWordValue, Address) HW_EscWrite(((UINT8 *)&(DWordValue)),((u16)(Address)),4) /**< \brief 32Bit ESC write access*/
#define HW_EscWriteMbxMem(pData,Address,Len) HW_EscWrite(((UINT8 *)(pData)),((u16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default write function is used.*/


#define HW_EscWriteWordIsr(WordValue, Address) HW_EscWriteIsr(((UINT8 *)&(WordValue)),((u16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC write access*/
#define HW_EscWriteDWordIsr(DWordValue, Address) HW_EscWriteIsr(((UINT8 *)&(DWordValue)),((u16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC write access*/


#endif


#if defined(__W25QXX_) && (__W25QXX_ == 1)

    #define PROTO
#else
    #define PROTO extern
#endif

/*-----------------------------------------------------------------------------------------
------
------    Global variables
------
-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------
------
------    Global functions
------
-----------------------------------------------------------------------------------------*/

PROTO  void SPIHW_Init(void);

PROTO  u8 HW_Init(void);

PROTO void HW_Release(void);

PROTO  u16 HW_GetALEventRegister(void);

PROTO  u16 HW_GetALEventRegister_Isr(void);


PROTO void HW_EscRead( UINT8  * pData, u16 Address, u16 Len );
PROTO void HW_EscReadIsr( UINT8  *pData, u16 Address, u16 Len );


PROTO void HW_EscWrite( UINT8  *pData, u16 Address, u16 Len );
PROTO void HW_EscWriteIsr( UINT8  *pData, u16 Address, u16 Len );

PROTO void AD8028_data(void);


PROTO void ADC_process_data(TOBJ6000 *IN_GENERIC);
PROTO void U485_process_data(TOBJ7000 *OUT_GENERIC,TOBJ6000 *IN_GENERIC);
PROTO void CAN_process_data(TOBJ7000 *OUT_GENERIC,TOBJ6000 *IN_GENERIC);

#undef    PROTO

	   














