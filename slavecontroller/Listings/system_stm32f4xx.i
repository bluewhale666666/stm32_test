#line 1 "RTE\\Device\\STM32F407ZETx\\system_stm32f4xx.c"

































 



 



   
  


 


#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"



























 



 



 
    






   


 
  


 






 
#line 95 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"
   


 





 
   




 
#line 119 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"



 



 

#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"























 



 



 
    









 



 








 
  


 




 
typedef enum
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      
 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMP_STAMP_IRQn             = 2,       
  RTC_WKUP_IRQn               = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Stream0_IRQn           = 11,      
  DMA1_Stream1_IRQn           = 12,      
  DMA1_Stream2_IRQn           = 13,      
  DMA1_Stream3_IRQn           = 14,      
  DMA1_Stream4_IRQn           = 15,      
  DMA1_Stream5_IRQn           = 16,      
  DMA1_Stream6_IRQn           = 17,      
  ADC_IRQn                    = 18,      
  CAN1_TX_IRQn                = 19,      
  CAN1_RX0_IRQn               = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_TIM9_IRQn          = 24,      
  TIM1_UP_TIM10_IRQn          = 25,      
  TIM1_TRG_COM_TIM11_IRQn     = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTC_Alarm_IRQn              = 41,      
  OTG_FS_WKUP_IRQn            = 42,      
  TIM8_BRK_TIM12_IRQn         = 43,      
  TIM8_UP_TIM13_IRQn          = 44,      
  TIM8_TRG_COM_TIM14_IRQn     = 45,      
  TIM8_CC_IRQn                = 46,      
  DMA1_Stream7_IRQn           = 47,      
  FSMC_IRQn                   = 48,      
  SDIO_IRQn                   = 49,      
  TIM5_IRQn                   = 50,      
  SPI3_IRQn                   = 51,      
  UART4_IRQn                  = 52,      
  UART5_IRQn                  = 53,      
  TIM6_DAC_IRQn               = 54,      
  TIM7_IRQn                   = 55,      
  DMA2_Stream0_IRQn           = 56,      
  DMA2_Stream1_IRQn           = 57,      
  DMA2_Stream2_IRQn           = 58,      
  DMA2_Stream3_IRQn           = 59,      
  DMA2_Stream4_IRQn           = 60,      
  ETH_IRQn                    = 61,      
  ETH_WKUP_IRQn               = 62,      
  CAN2_TX_IRQn                = 63,      
  CAN2_RX0_IRQn               = 64,      
  CAN2_RX1_IRQn               = 65,      
  CAN2_SCE_IRQn               = 66,      
  OTG_FS_IRQn                 = 67,      
  DMA2_Stream5_IRQn           = 68,      
  DMA2_Stream6_IRQn           = 69,      
  DMA2_Stream7_IRQn           = 70,      
  USART6_IRQn                 = 71,      
  I2C3_EV_IRQn                = 72,      
  I2C3_ER_IRQn                = 73,      
  OTG_HS_EP1_OUT_IRQn         = 74,      
  OTG_HS_EP1_IN_IRQn          = 75,      
  OTG_HS_WKUP_IRQn            = 76,      
  OTG_HS_IRQn                 = 77,      
  DCMI_IRQn                   = 78,      
  RNG_IRQn                    = 80,      
  FPU_IRQn                    = 81       
} IRQn_Type;
 




 

#line 1 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"
 




 

























 











#line 1 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 45 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"

















 




 



 

 













#line 120 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"



 
#line 135 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"

#line 209 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"

#line 1 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmInstr.h"
 




 

























 












 



 

 
#line 1 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\cmsis_armcc.h"
 




 

























 










 



 

 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}








 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1);
}










 
static __inline uint32_t __get_FPSCR(void)
{

  register uint32_t __regfpscr         __asm("fpscr");
  return(__regfpscr);



}






 
static __inline void __set_FPSCR(uint32_t fpscr)
{

  register uint32_t __regfpscr         __asm("fpscr");
  __regfpscr = (fpscr);

}





 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}







 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 455 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\cmsis_armcc.h"







 










 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 




   


 



 



#line 720 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\cmsis_armcc.h"











 


#line 54 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmInstr.h"

 
#line 84 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmInstr.h"

   

#line 211 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"
#line 1 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmFunc.h"
 




 

























 












 



 

 
#line 54 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmFunc.h"

 
#line 84 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmFunc.h"

 

#line 212 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"
#line 1 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmSimd.h"
 




 

























 
















 



 

 
#line 58 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmSimd.h"

 
#line 88 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cmSimd.h"

 






#line 213 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"
















 
#line 256 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"

 






 
#line 272 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"

 




 













 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:16;               
    uint32_t GE:4;                        
    uint32_t _reserved1:7;                
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:7;                
    uint32_t GE:4;                        
    uint32_t _reserved1:4;                
    uint32_t T:1;                         
    uint32_t IT:2;                        
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 






























 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 









 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 



 





















 









 


















 










































 









 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    
  volatile uint32_t ACTLR;                   
} SCnSCB_Type;

 



 















 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   








 



 
typedef struct
{
  volatile const  uint32_t TYPE;                    
  volatile uint32_t CTRL;                    
  volatile uint32_t RNR;                     
  volatile uint32_t RBAR;                    
  volatile uint32_t RASR;                    
  volatile uint32_t RBAR_A1;                 
  volatile uint32_t RASR_A1;                 
  volatile uint32_t RBAR_A2;                 
  volatile uint32_t RASR_A2;                 
  volatile uint32_t RBAR_A3;                 
  volatile uint32_t RASR_A3;                 
} MPU_Type;

 









 









 



 









 






























 









 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;                   
  volatile uint32_t FPCAR;                   
  volatile uint32_t FPDSCR;                  
  volatile const  uint32_t MVFR0;                   
  volatile const  uint32_t MVFR1;                   
} FPU_Type;

 



























 



 












 
























 












 








 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1541 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"

#line 1550 "D:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\core_cm4.h"











 










 


 



 





 









 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U)                      );               
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}






 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}






 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}






 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}








 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}








 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) < 0)
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) < 0)
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4U)));
  }
  else
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               >> (8U - 4U)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}





 
static __inline void NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  NVIC_SetPriority (SysTick_IRQn, (1UL << 4U) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                     










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != 0x5AA55AA5U)
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5U;        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == 0x5AA55AA5U)
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 










#line 168 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\system_stm32f4xx.h"

































  



 



   
  


 









 



 




 
  






 
extern uint32_t SystemCoreClock;           

extern const uint8_t  AHBPrescTable[16];     
extern const uint8_t  APBPrescTable[8];      



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 









 
  


   
 
#line 169 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
#line 170 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



    



 

typedef struct
{
  volatile uint32_t SR;      
  volatile uint32_t CR1;     
  volatile uint32_t CR2;     
  volatile uint32_t SMPR1;   
  volatile uint32_t SMPR2;   
  volatile uint32_t JOFR1;   
  volatile uint32_t JOFR2;   
  volatile uint32_t JOFR3;   
  volatile uint32_t JOFR4;   
  volatile uint32_t HTR;     
  volatile uint32_t LTR;     
  volatile uint32_t SQR1;    
  volatile uint32_t SQR2;    
  volatile uint32_t SQR3;    
  volatile uint32_t JSQR;    
  volatile uint32_t JDR1;    
  volatile uint32_t JDR2;    
  volatile uint32_t JDR3;    
  volatile uint32_t JDR4;    
  volatile uint32_t DR;      
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CSR;     
  volatile uint32_t CCR;     
  volatile uint32_t CDR;    
 
} ADC_Common_TypeDef;




 

typedef struct
{
  volatile uint32_t TIR;   
  volatile uint32_t TDTR;  
  volatile uint32_t TDLR;  
  volatile uint32_t TDHR;  
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;   
  volatile uint32_t RDTR;  
  volatile uint32_t RDLR;  
  volatile uint32_t RDHR;  
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;  
  volatile uint32_t FR2;  
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t              MCR;                  
  volatile uint32_t              MSR;                  
  volatile uint32_t              TSR;                  
  volatile uint32_t              RF0R;                 
  volatile uint32_t              RF1R;                 
  volatile uint32_t              IER;                  
  volatile uint32_t              ESR;                  
  volatile uint32_t              BTR;                  
  uint32_t                   RESERVED0[88];        
  CAN_TxMailBox_TypeDef      sTxMailBox[3];        
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];      
  uint32_t                   RESERVED1[12];        
  volatile uint32_t              FMR;                  
  volatile uint32_t              FM1R;                 
  uint32_t                   RESERVED2;            
  volatile uint32_t              FS1R;                 
  uint32_t                   RESERVED3;            
  volatile uint32_t              FFA1R;                
  uint32_t                   RESERVED4;            
  volatile uint32_t              FA1R;                 
  uint32_t                   RESERVED5[8];          
  CAN_FilterRegister_TypeDef sFilterRegister[28];  
} CAN_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;          
  volatile uint8_t  IDR;         
  uint8_t       RESERVED0;   
  uint16_t      RESERVED1;   
  volatile uint32_t CR;          
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;        
  volatile uint32_t SWTRIGR;   
  volatile uint32_t DHR12R1;   
  volatile uint32_t DHR12L1;   
  volatile uint32_t DHR8R1;    
  volatile uint32_t DHR12R2;   
  volatile uint32_t DHR12L2;   
  volatile uint32_t DHR8R2;    
  volatile uint32_t DHR12RD;   
  volatile uint32_t DHR12LD;   
  volatile uint32_t DHR8RD;    
  volatile uint32_t DOR1;      
  volatile uint32_t DOR2;      
  volatile uint32_t SR;        
} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;   
  volatile uint32_t CR;       
  volatile uint32_t APB1FZ;   
  volatile uint32_t APB2FZ;   
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;        
  volatile uint32_t SR;        
  volatile uint32_t RISR;      
  volatile uint32_t IER;       
  volatile uint32_t MISR;      
  volatile uint32_t ICR;       
  volatile uint32_t ESCR;      
  volatile uint32_t ESUR;      
  volatile uint32_t CWSTRTR;   
  volatile uint32_t CWSIZER;   
  volatile uint32_t DR;        
} DCMI_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;      
  volatile uint32_t NDTR;    
  volatile uint32_t PAR;     
  volatile uint32_t M0AR;    
  volatile uint32_t M1AR;    
  volatile uint32_t FCR;     
} DMA_Stream_TypeDef;

typedef struct
{
  volatile uint32_t LISR;    
  volatile uint32_t HISR;    
  volatile uint32_t LIFCR;   
  volatile uint32_t HIFCR;   
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;              
  uint32_t      RESERVED0[2];
  volatile uint32_t MACRWUFFR;              
  volatile uint32_t MACPMTCSR;
  uint32_t      RESERVED1;
  volatile uint32_t MACDBGR;
  volatile uint32_t MACSR;                  
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;                
  uint32_t      RESERVED2[40];
  volatile uint32_t MMCCR;                  
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;                
  uint32_t      RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;             
  volatile uint32_t MMCTGFMSCCR;
  uint32_t      RESERVED4[5];
  volatile uint32_t MMCTGFCR;
  uint32_t      RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
  uint32_t      RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
  uint32_t      RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
  volatile uint32_t RESERVED8;
  volatile uint32_t PTPTSSR;
  uint32_t      RESERVED9[565];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
  volatile uint32_t DMARSWTR;
  uint32_t      RESERVED10[8];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;     
  volatile uint32_t EMR;     
  volatile uint32_t RTSR;    
  volatile uint32_t FTSR;    
  volatile uint32_t SWIER;   
  volatile uint32_t PR;      
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;       
  volatile uint32_t KEYR;      
  volatile uint32_t OPTKEYR;   
  volatile uint32_t SR;        
  volatile uint32_t CR;        
  volatile uint32_t OPTCR;     
  volatile uint32_t OPTCR1;    
} FLASH_TypeDef;





 

typedef struct
{
  volatile uint32_t BTCR[8];        
} FSMC_Bank1_TypeDef;



 

typedef struct
{
  volatile uint32_t BWTR[7];     
} FSMC_Bank1E_TypeDef;



 
  
typedef struct
{
  volatile uint32_t PCR2;        
  volatile uint32_t SR2;         
  volatile uint32_t PMEM2;       
  volatile uint32_t PATT2;       
  uint32_t      RESERVED0;   
  volatile uint32_t ECCR2;       
  uint32_t      RESERVED1;   
  uint32_t      RESERVED2;   
  volatile uint32_t PCR3;        
  volatile uint32_t SR3;         
  volatile uint32_t PMEM3;       
  volatile uint32_t PATT3;       
  uint32_t      RESERVED3;   
  volatile uint32_t ECCR3;       
} FSMC_Bank2_3_TypeDef;



 

typedef struct
{
  volatile uint32_t PCR4;        
  volatile uint32_t SR4;         
  volatile uint32_t PMEM4;       
  volatile uint32_t PATT4;       
  volatile uint32_t PIO4;        
} FSMC_Bank4_TypeDef; 



 

typedef struct
{
  volatile uint32_t MODER;     
  volatile uint32_t OTYPER;    
  volatile uint32_t OSPEEDR;   
  volatile uint32_t PUPDR;     
  volatile uint32_t IDR;       
  volatile uint32_t ODR;       
  volatile uint32_t BSRR;      
  volatile uint32_t LCKR;      
  volatile uint32_t AFR[2];    
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t MEMRMP;        
  volatile uint32_t PMC;           
  volatile uint32_t EXTICR[4];     
  uint32_t      RESERVED[2];   
  volatile uint32_t CMPCR;         
} SYSCFG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t OAR1;        
  volatile uint32_t OAR2;        
  volatile uint32_t DR;          
  volatile uint32_t SR1;         
  volatile uint32_t SR2;         
  volatile uint32_t CCR;         
  volatile uint32_t TRISE;       
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;    
  volatile uint32_t PR;    
  volatile uint32_t RLR;   
  volatile uint32_t SR;    
} IWDG_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CSR;   
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t PLLCFGR;        
  volatile uint32_t CFGR;           
  volatile uint32_t CIR;            
  volatile uint32_t AHB1RSTR;       
  volatile uint32_t AHB2RSTR;       
  volatile uint32_t AHB3RSTR;       
  uint32_t      RESERVED0;      
  volatile uint32_t APB1RSTR;       
  volatile uint32_t APB2RSTR;       
  uint32_t      RESERVED1[2];   
  volatile uint32_t AHB1ENR;        
  volatile uint32_t AHB2ENR;        
  volatile uint32_t AHB3ENR;        
  uint32_t      RESERVED2;      
  volatile uint32_t APB1ENR;        
  volatile uint32_t APB2ENR;        
  uint32_t      RESERVED3[2];   
  volatile uint32_t AHB1LPENR;      
  volatile uint32_t AHB2LPENR;      
  volatile uint32_t AHB3LPENR;      
  uint32_t      RESERVED4;      
  volatile uint32_t APB1LPENR;      
  volatile uint32_t APB2LPENR;      
  uint32_t      RESERVED5[2];   
  volatile uint32_t BDCR;           
  volatile uint32_t CSR;            
  uint32_t      RESERVED6[2];   
  volatile uint32_t SSCGR;          
  volatile uint32_t PLLI2SCFGR;     
} RCC_TypeDef;



 

typedef struct
{
  volatile uint32_t TR;       
  volatile uint32_t DR;       
  volatile uint32_t CR;       
  volatile uint32_t ISR;      
  volatile uint32_t PRER;     
  volatile uint32_t WUTR;     
  volatile uint32_t CALIBR;   
  volatile uint32_t ALRMAR;   
  volatile uint32_t ALRMBR;   
  volatile uint32_t WPR;      
  volatile uint32_t SSR;      
  volatile uint32_t SHIFTR;   
  volatile uint32_t TSTR;     
  volatile uint32_t TSDR;     
  volatile uint32_t TSSSR;    
  volatile uint32_t CALR;     
  volatile uint32_t TAFCR;    
  volatile uint32_t ALRMASSR; 
  volatile uint32_t ALRMBSSR; 
  uint32_t RESERVED7;     
  volatile uint32_t BKP0R;    
  volatile uint32_t BKP1R;    
  volatile uint32_t BKP2R;    
  volatile uint32_t BKP3R;    
  volatile uint32_t BKP4R;    
  volatile uint32_t BKP5R;    
  volatile uint32_t BKP6R;    
  volatile uint32_t BKP7R;    
  volatile uint32_t BKP8R;    
  volatile uint32_t BKP9R;    
  volatile uint32_t BKP10R;   
  volatile uint32_t BKP11R;   
  volatile uint32_t BKP12R;   
  volatile uint32_t BKP13R;   
  volatile uint32_t BKP14R;   
  volatile uint32_t BKP15R;   
  volatile uint32_t BKP16R;   
  volatile uint32_t BKP17R;   
  volatile uint32_t BKP18R;   
  volatile uint32_t BKP19R;   
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;                  
  volatile uint32_t CLKCR;                  
  volatile uint32_t ARG;                    
  volatile uint32_t CMD;                    
  volatile const uint32_t  RESPCMD;         
  volatile const uint32_t  RESP1;           
  volatile const uint32_t  RESP2;           
  volatile const uint32_t  RESP3;           
  volatile const uint32_t  RESP4;           
  volatile uint32_t DTIMER;                 
  volatile uint32_t DLEN;                   
  volatile uint32_t DCTRL;                  
  volatile const uint32_t  DCOUNT;          
  volatile const uint32_t  STA;             
  volatile uint32_t ICR;                    
  volatile uint32_t MASK;                   
  uint32_t      RESERVED0[2];           
  volatile const uint32_t  FIFOCNT;         
  uint32_t      RESERVED1[13];          
  volatile uint32_t FIFO;                   
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t SR;          
  volatile uint32_t DR;          
  volatile uint32_t CRCPR;       
  volatile uint32_t RXCRCR;      
  volatile uint32_t TXCRCR;      
  volatile uint32_t I2SCFGR;     
  volatile uint32_t I2SPR;       
} SPI_TypeDef;




 

typedef struct
{
  volatile uint32_t CR1;          
  volatile uint32_t CR2;          
  volatile uint32_t SMCR;         
  volatile uint32_t DIER;         
  volatile uint32_t SR;           
  volatile uint32_t EGR;          
  volatile uint32_t CCMR1;        
  volatile uint32_t CCMR2;        
  volatile uint32_t CCER;         
  volatile uint32_t CNT;          
  volatile uint32_t PSC;          
  volatile uint32_t ARR;          
  volatile uint32_t RCR;          
  volatile uint32_t CCR1;         
  volatile uint32_t CCR2;         
  volatile uint32_t CCR3;         
  volatile uint32_t CCR4;         
  volatile uint32_t BDTR;         
  volatile uint32_t DCR;          
  volatile uint32_t DMAR;         
  volatile uint32_t OR;           
} TIM_TypeDef;



 
 
typedef struct
{
  volatile uint32_t SR;          
  volatile uint32_t DR;          
  volatile uint32_t BRR;         
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t CR3;         
  volatile uint32_t GTPR;        
} USART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CFR;   
  volatile uint32_t SR;    
} WWDG_TypeDef;



 
  
typedef struct 
{
  volatile uint32_t CR;   
  volatile uint32_t SR;   
  volatile uint32_t DR;   
} RNG_TypeDef;



 
typedef struct
{
  volatile uint32_t GOTGCTL;               
  volatile uint32_t GOTGINT;               
  volatile uint32_t GAHBCFG;               
  volatile uint32_t GUSBCFG;               
  volatile uint32_t GRSTCTL;               
  volatile uint32_t GINTSTS;               
  volatile uint32_t GINTMSK;               
  volatile uint32_t GRXSTSR;               
  volatile uint32_t GRXSTSP;               
  volatile uint32_t GRXFSIZ;               
  volatile uint32_t DIEPTXF0_HNPTXFSIZ;    
  volatile uint32_t HNPTXSTS;              
  uint32_t Reserved30[2];              
  volatile uint32_t GCCFG;                 
  volatile uint32_t CID;                   
  uint32_t  Reserved40[48];            
  volatile uint32_t HPTXFSIZ;              
  volatile uint32_t DIEPTXF[0x0F];         
} USB_OTG_GlobalTypeDef;



 
typedef struct 
{
  volatile uint32_t DCFG;             
  volatile uint32_t DCTL;             
  volatile uint32_t DSTS;             
  uint32_t Reserved0C;            
  volatile uint32_t DIEPMSK;          
  volatile uint32_t DOEPMSK;          
  volatile uint32_t DAINT;            
  volatile uint32_t DAINTMSK;         
  uint32_t  Reserved20;           
  uint32_t Reserved9;             
  volatile uint32_t DVBUSDIS;         
  volatile uint32_t DVBUSPULSE;       
  volatile uint32_t DTHRCTL;          
  volatile uint32_t DIEPEMPMSK;       
  volatile uint32_t DEACHINT;         
  volatile uint32_t DEACHMSK;         
  uint32_t Reserved40;            
  volatile uint32_t DINEP1MSK;        
  uint32_t  Reserved44[15];       
  volatile uint32_t DOUTEP1MSK;       
} USB_OTG_DeviceTypeDef;



 
typedef struct 
{
  volatile uint32_t DIEPCTL;            
  uint32_t Reserved04;              
  volatile uint32_t DIEPINT;            
  uint32_t Reserved0C;              
  volatile uint32_t DIEPTSIZ;           
  volatile uint32_t DIEPDMA;            
  volatile uint32_t DTXFSTS;            
  uint32_t Reserved18;              
} USB_OTG_INEndpointTypeDef;



 
typedef struct 
{
  volatile uint32_t DOEPCTL;        
  uint32_t Reserved04;          
  volatile uint32_t DOEPINT;        
  uint32_t Reserved0C;          
  volatile uint32_t DOEPTSIZ;       
  volatile uint32_t DOEPDMA;        
  uint32_t Reserved18[2];       
} USB_OTG_OUTEndpointTypeDef;



 
typedef struct 
{
  volatile uint32_t HCFG;              
  volatile uint32_t HFIR;              
  volatile uint32_t HFNUM;             
  uint32_t Reserved40C;            
  volatile uint32_t HPTXSTS;           
  volatile uint32_t HAINT;             
  volatile uint32_t HAINTMSK;          
} USB_OTG_HostTypeDef;



 
typedef struct
{
  volatile uint32_t HCCHAR;            
  volatile uint32_t HCSPLT;            
  volatile uint32_t HCINT;             
  volatile uint32_t HCINTMSK;          
  volatile uint32_t HCTSIZ;            
  volatile uint32_t HCDMA;             
  uint32_t Reserved[2];            
} USB_OTG_HostChannelTypeDef;



 



 
#line 922 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 



 





 
#line 961 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 971 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 980 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1017 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 



 






 

 



#line 1047 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"






 



   
#line 1094 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 1143 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 



 



 



 

  

 
    
 
 
 

 
 
 
 
 


 


 
#line 1197 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1251 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
  
 
#line 1301 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1357 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1419 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 




 




 
#line 1490 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1540 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1590 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1629 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 
#line 1657 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1713 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 1754 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1762 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 



 
 
 
 
 
 
 
#line 1804 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 1832 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1882 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 1895 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 1908 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1922 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1936 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1981 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 1992 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 1999 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 2006 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2035 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 
 
#line 2054 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2065 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2079 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2093 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2110 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2121 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2135 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2149 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2166 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

   
#line 2177 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2191 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2205 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2219 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2230 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2244 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2258 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2272 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2283 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2297 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2311 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
#line 2320 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2409 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2498 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2587 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2676 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 
#line 2775 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2873 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 2971 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3069 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3167 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3265 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3363 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3461 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3559 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3657 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3755 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3853 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 3951 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4049 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4147 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4245 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4343 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4441 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4539 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4637 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4735 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4833 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 4931 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5029 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5127 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5225 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5323 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5421 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 
 





 





 




 
 
 
 
 


 

 
#line 5463 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 5470 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 5484 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 5500 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 5507 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 5521 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 5528 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5536 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 




 




 
#line 5574 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5582 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5590 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 
#line 5608 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 
 
#line 5649 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5660 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5677 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 5684 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5701 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 


 
#line 5720 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 






 
#line 5744 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 


 
#line 5761 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5775 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5783 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5791 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 5805 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 
 
#line 5884 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 5910 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

  
#line 5929 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

  
#line 5991 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

  
#line 6053 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

  
#line 6115 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

  
#line 6177 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 





 
 
 
 
 
 
#line 6269 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6297 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6368 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6393 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6464 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6535 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6606 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6677 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 
 
#line 6695 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


#line 6718 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6741 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6777 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6785 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 6826 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
                                             
 
#line 6843 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 
 
#line 6856 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"













#line 6905 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6913 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"













#line 6962 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 6970 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"













#line 7019 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7027 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"













#line 7076 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7085 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7093 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7105 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7113 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7121 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7129 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 7144 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7152 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7164 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7172 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7180 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7188 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 7203 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7211 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7223 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7231 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7239 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7247 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 7262 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7270 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7282 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7290 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7298 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7306 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 7321 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7329 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7341 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7349 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 7364 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7372 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7384 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7392 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 7407 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7415 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7427 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7435 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 7450 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7458 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7470 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7478 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 7495 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"











#line 7513 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7521 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7528 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7539 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"











#line 7557 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7565 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7572 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7583 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"











#line 7601 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7609 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7616 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7639 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7662 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7685 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7698 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7710 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7722 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7734 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7747 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7759 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7771 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7783 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7796 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7808 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7820 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7832 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7845 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7857 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7869 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7881 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7894 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7906 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7918 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7930 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7943 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7955 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7967 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 7979 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 7992 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 8004 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 8016 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 8028 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 
 
 
 
 
 
#line 8125 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8207 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8257 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8275 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8357 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8407 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8489 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8539 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8589 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8607 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8657 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 8674 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8772 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 8854 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 8906 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 8963 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9005 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9063 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9105 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 
 
 
 
 
 
#line 9155 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9166 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9182 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 



#line 9217 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"





 
#line 9229 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 9278 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9304 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9315 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 





 
 
 
 
 
 




 
#line 9339 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 9352 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
 
 
 
 
 
#line 9376 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9383 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9402 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 


 
#line 9428 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 


 
 
 
 
 
 
#line 9444 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9453 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9465 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9484 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 


#line 9495 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9506 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9519 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 9533 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9541 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 
 










 










 
#line 9574 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9584 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9592 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 9606 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 9622 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 










#line 9640 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9647 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 9673 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9695 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 9714 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"





 
#line 9762 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9773 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 





 
#line 9849 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 9884 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 


 
#line 9949 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 


 


#line 9964 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 


 






 
#line 10045 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10086 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10136 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 10155 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10166 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 10242 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10283 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10294 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 10307 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10339 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 



 
#line 10356 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10370 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 10377 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 
 
 
 
 
 
#line 10391 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10408 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 


 


 
#line 10461 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10505 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10575 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 


 
#line 10628 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10636 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 10649 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10719 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10789 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 
#line 10807 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10850 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10880 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 10908 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10956 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 


 
#line 10971 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 10983 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 




 



 
 
 
 
 
 






 
#line 11113 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 11126 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 










#line 11164 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 




 




 




 




 
#line 11218 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 11226 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 11239 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 11318 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11359 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11433 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 
 
 
 
 


 
#line 11461 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 11468 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 11499 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11522 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11551 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 






























#line 11609 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11620 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 
 





 



 


 
#line 11652 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 
#line 11664 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11677 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11690 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11703 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11717 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11730 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11743 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11756 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11769 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11783 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11796 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11809 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11822 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11835 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11849 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11861 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11873 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11885 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



 
#line 11897 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11905 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 
 
#line 11927 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

















 
#line 11954 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 11961 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 11986 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 11994 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 12001 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"





#line 12013 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 12026 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12073 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12111 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12137 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 






#line 12151 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 12158 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"











#line 12175 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 12182 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"





 







#line 12202 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 12216 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 






#line 12230 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 12237 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"











#line 12254 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 12261 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"





 







#line 12281 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 12295 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12342 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 




 




 




 




 
#line 12395 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 12420 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12430 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 12439 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 






#line 12462 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 
 
 
 
 
 
#line 12500 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 12513 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12560 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12583 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"











 
#line 12631 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12644 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"





 
 
 
 
 
 
#line 12665 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 12673 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"





 
#line 12689 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 12697 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"






 







 





 
 
 
 
 
 
#line 12729 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12743 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 12802 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 


 
#line 12821 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 
 
 
 
#line 12886 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 12930 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 
#line 12970 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 13008 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13016 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

  




 








 

  
#line 13055 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13135 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13152 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13160 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 
#line 13190 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 13215 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 13240 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
 
 

 
#line 13269 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13280 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13291 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13302 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13313 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 




 




 
 
 

 
#line 13376 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 13395 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 
#line 13413 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 13426 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 
#line 13449 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
 

 
#line 13516 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 
#line 13550 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
   
#line 13643 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13693 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13740 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13754 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 




 
 
 
 
 
 
#line 13811 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 

#line 13822 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 

#line 13833 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 13844 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"





















 
#line 13875 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13895 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13909 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 13931 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 13944 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




#line 13961 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 13983 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 

#line 14047 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14064 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


#line 14080 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14106 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14122 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14134 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 14177 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 14256 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14336 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14344 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 14363 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14371 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 
#line 14395 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




#line 14417 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14428 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14436 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14452 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14468 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 14481 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14501 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14509 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 14543 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14572 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14581 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14589 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 14630 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14638 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14652 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14661 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14687 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




#line 14706 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"













#line 14738 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 

#line 14751 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14762 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 14774 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14809 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14850 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 14885 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 

#line 14897 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 14912 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 




 




 
#line 14935 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 

#line 14976 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15011 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 

#line 15019 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







 
#line 15036 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
 
#line 15049 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"







#line 15063 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 15071 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

#line 15079 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


  



 



 

 








 


 


 


 


 
#line 15129 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15140 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 


 




 


 


 


 



 





 
#line 15188 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15202 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15212 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15220 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15228 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 



 
#line 15240 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15250 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15258 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15266 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15274 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15284 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15294 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 



 
#line 15305 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 15368 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15380 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15388 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15402 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 




 
#line 15415 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15425 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15433 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15443 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 
#line 15453 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 



 
#line 15467 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 
#line 15474 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"
 



 





 
#line 15491 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"

 


 




 


 





 
#line 15516 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"


 



 



 


 


 


 







 



#line 15554 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f407xx.h"



















 
 
 
 
 
 
 
 


 




 



 



 









 
#line 134 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"
#line 177 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"



 



  
typedef enum 
{
  RESET = 0U, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0U, 
  ENABLE = !DISABLE
} FunctionalState;


typedef enum
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;



 




 
















 
 
#line 237 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"

 
#line 246 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"

 
#line 255 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"

 
#line 264 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"

 
#line 273 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"

 
#line 282 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include\\stm32f4xx.h"



 












 



 
  



 
#line 50 "RTE\\Device\\STM32F407ZETx\\system_stm32f4xx.c"











 



 



 



 

 
 



 


 







 


 
 

#line 113 "RTE\\Device\\STM32F407ZETx\\system_stm32f4xx.c"
 



 



 



 



 
  






 
uint32_t SystemCoreClock = 16000000;
const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};


 



 







 



 







 
void SystemInit(void)
{
   

    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->CPACR |= ((3UL << 10*2)|(3UL << 11*2));   






   



}




































 
void SystemCoreClockUpdate(void)
{
  uint32_t tmp = 0, pllvco = 0, pllp = 2, pllsource = 0, pllm = 2;
  
   
  tmp = ((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->CFGR & (0x3UL << (2U));

  switch (tmp)
  {
    case 0x00:   
      SystemCoreClock = ((uint32_t)16000000);
      break;
    case 0x04:   
      SystemCoreClock = ((uint32_t)25000000);
      break;
    case 0x08:   

      

     
      pllsource = (((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->PLLCFGR & (0x1UL << (22U))) >> 22;
      pllm = ((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->PLLCFGR & (0x3FUL << (0U));
      
      if (pllsource != 0)
      {
         
        pllvco = (((uint32_t)25000000) / pllm) * ((((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->PLLCFGR & (0x1FFUL << (6U))) >> 6);
      }
      else
      {
         
        pllvco = (((uint32_t)16000000) / pllm) * ((((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->PLLCFGR & (0x1FFUL << (6U))) >> 6);
      }

      pllp = (((((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->PLLCFGR & (0x3UL << (16U))) >>16) + 1 ) *2;
      SystemCoreClock = pllvco/pllp;
      break;
    default:
      SystemCoreClock = ((uint32_t)16000000);
      break;
  }
   
   
  tmp = AHBPrescTable[((((RCC_TypeDef *) ((0x40000000UL + 0x00020000UL) + 0x3800UL))->CFGR & (0xFUL << (4U))) >> 4)];
   
  SystemCoreClock >>= tmp;
}

#line 738 "RTE\\Device\\STM32F407ZETx\\system_stm32f4xx.c"


 



 



 
 
