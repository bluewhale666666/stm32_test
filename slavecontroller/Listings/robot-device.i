#line 1 "etherCAT\\Robot-Device.c"



 




 






 






 
#line 1 "etherCAT\\ecat_def.h"



 






 








 
#line 1 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
 
 
 




 
 



 






   














  


 








#line 54 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


  



    typedef unsigned int size_t;    
#line 70 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"






    



    typedef unsigned short wchar_t;  
#line 91 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { long long quot, rem; } lldiv_t;
    


#line 112 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   



 

   




 
#line 131 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) long long atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) long long strtoll(const char * __restrict  ,
                                  char ** __restrict  , int  )
                          __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned long long strtoull(const char * __restrict  ,
                                            char ** __restrict  , int  )
                                   __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 436 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 524 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 553 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __attribute__((const)) int abs(int  );
   



 

extern __declspec(__nothrow) __attribute__((const)) div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __attribute__((const)) long int labs(long int  );
   



 




extern __declspec(__nothrow) __attribute__((const)) ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __attribute__((const)) long long llabs(long long  );
   



 




extern __declspec(__nothrow) __attribute__((const)) lldiv_t lldiv(long long  , long long  );
   











 
#line 634 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"




 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 




 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 892 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"





 
#line 22 "etherCAT\\ecat_def.h"
#line 1 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"


  



    typedef unsigned int size_t;    
#line 54 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 193 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 209 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 232 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 247 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 270 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 502 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"



 

#line 23 "etherCAT\\ecat_def.h"





 








 







 






 






 





 





 





 






 






 





 





 





 






 







 






 





 





 





 





 





 







 






 





 






 






 





 





 





 





 






 





 






 






 





 





 






 






 








 





 






 





 







 





 







 







 





 





 





 





 






 





 






 






 






 





 





 





 





 









 


 





 





 





 





 





 





 





 





 





 





 





 





 





 





 





 





 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 





 






 






 






 






 






 






 






 





 





 






 






 






 





 





 





 






 






 





 





 






 






 





 





 





 





 





 





 





 





 





 





 





 





 





 





 









 


 





 







 





 





 





 





 





 





 





 





 





 





 






 






 






 






 





 





 





 





 





 





 





 





 






 





 





 






 






 





 










 




#line 25 "etherCAT\\Robot-Device.c"

#line 1 "etherCAT\\applInterface.h"




 




 

















 





 





#line 41 "etherCAT\\applInterface.h"
#line 42 "etherCAT\\applInterface.h"
#line 43 "etherCAT\\applInterface.h"
#line 1 "etherCAT\\esc.h"




 




 














 





 
#line 33 "etherCAT\\esc.h"








 








 




 




 




 













 





 









 



 
 


 


 
#line 117 "etherCAT\\esc.h"
 






 



 




 




 







 




 
 
typedef struct 
{
 

  unsigned short                        PhysicalStartAddress;  
  unsigned short                        Length;  

    unsigned short                        Settings[2];  






 

 
#line 178 "etherCAT\\esc.h"

 







 

 





 


 
}
TSYNCMAN;


 


 
#line 44 "etherCAT\\applInterface.h"
#line 1 "etherCAT\\ecatslv.h"




 




 



























 





 

#line 47 "etherCAT\\ecatslv.h"

 
#line 1 "etherCAT\\esc.h"




 




 














 





 
#line 33 "etherCAT\\esc.h"

#line 206 "etherCAT\\esc.h"
 
#line 50 "etherCAT\\ecatslv.h"
#line 1 "etherCAT\\9252_HW.h"




















 






















 







#line 1 "etherCAT\\esc.h"




 




 














 





 
#line 33 "etherCAT\\esc.h"

#line 206 "etherCAT\\esc.h"
 
#line 53 "etherCAT\\9252_HW.h"
#line 1 "etherCAT\\SPIDriver.h"



















 























 












#line 58 "etherCAT\\SPIDriver.h"
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal.h"


















  

 







 
#line 1 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"
 


















 
 

 







 
 

 


 


   
 

 
 
 
 
 
 
 
 
 
 
 
 
 

 
 
 
 
 
 
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 91 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"

 




 












 






 







 












 





 

 


 
#line 156 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"

#line 196 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"

 



 
 

 

 

 
#line 215 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"

 





 

 

 

 





 




#line 249 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"





 





 




 



 


 

#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

















 

 







 
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"





















 

 







 
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



 












 



 
  



 
#line 34 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


















 

 







 
 
 



 
#line 49 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 
#line 96 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 104 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"






 



 





 



 
#line 142 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 209 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 



 



 



 






 



 

#line 249 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"













 



 
#line 281 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"





#line 325 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 335 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 397 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 

#line 502 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 

#line 519 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 

#line 544 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 




 
#line 564 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 





 



 


















#line 614 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"





#line 625 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 632 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"










 



 
#line 656 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 665 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 676 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 788 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 805 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 
#line 828 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 





 



 






 



 















 
 










 



 














 



 










 



 







































 



 


#line 975 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"






 



 

 
#line 997 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

 












 



 




























#line 1053 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 




 















 




 
#line 1094 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 









#line 1124 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 



#line 1162 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1172 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1191 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"










#line 1218 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 




 



 

























 




 








 



 




 



 
#line 1298 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 

#line 1315 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1327 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1358 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 











 

#line 1406 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1420 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 

 



 



 



 








 




 




 



 
#line 1471 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

 





































 



 
#line 1538 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 
#line 1553 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 








#line 1581 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1592 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 

#line 1622 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1630 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"






#line 1646 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"





 



 





 



 



 



 
#line 1686 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 



 



 






 




 



 

 



 





 



 
#line 1747 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"









 




 
#line 1775 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1796 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1807 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1816 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1829 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1838 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 







 



 
#line 1874 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 1889 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


#line 1922 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 
#line 2089 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



#line 2099 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 

#line 2113 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 







 



 

#line 2136 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 



 

#line 2164 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 










 



 














 




 




 




 







 




 
#line 2242 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"



 




 
#line 2286 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 2300 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 




 








#line 2574 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 2588 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 2805 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 2819 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 2826 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 2847 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 2995 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

 



#line 3020 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3041 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3158 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3167 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3184 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3199 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"






#line 3228 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

















#line 3254 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"





#line 3281 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"







#line 3296 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3329 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3347 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"












#line 3365 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3386 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3408 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 




 



 
#line 3430 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3458 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3473 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"






 



 




#line 3496 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3518 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"
 




#line 3548 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3555 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3567 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 

#line 3581 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"








 



 
#line 3602 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 







 



 













 




 









#line 3656 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 












#line 3682 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3691 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"

#line 3700 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"








 



 








#line 3733 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"




 



 

#line 3750 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"






 



 




 



 
#line 3784 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 







 



 
#line 3811 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy/stm32_hal_legacy.h"


 



 





 



 



 







 

#line 35 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"
#line 1 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



    




   




  typedef long double max_align_t;









#line 114 "D:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stddef.h"



 

#line 36 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"

 



   
typedef enum 
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;



 
typedef enum 
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U  
} HAL_LockTypeDef;

 




























 


#line 106 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"







#line 121 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"


 
#line 143 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"




  









 


#line 176 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"



  



 


#line 193 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_def.h"







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

 
 
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"



 



  

 


 



 
typedef struct
{
  uint32_t PLLState;   
 

  uint32_t PLLSource;  
 

  uint32_t PLLM;       
 

  uint32_t PLLN;       

 

  uint32_t PLLP;       
 

  uint32_t PLLQ;       
 
#line 75 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
}RCC_PLLInitTypeDef;

#line 176 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 202 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 293 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 378 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"





 
typedef struct
{




                                
  uint32_t PLLI2SN;    


 

  uint32_t PLLI2SR;    

 

}RCC_PLLI2SInitTypeDef;
 


 
typedef struct
{
  uint32_t PeriphClockSelection; 
 

  RCC_PLLI2SInitTypeDef PLLI2S;  
 

  uint32_t RTCClockSelection;      
 




}RCC_PeriphCLKInitTypeDef;



  

 


 



 
 
#line 454 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 464 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 481 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 
    
 
#line 495 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 507 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 519 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 


 






 




 





 
#line 548 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 



 
#line 562 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 



 
#line 575 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 

#line 600 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
      
#line 629 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 722 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 777 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 856 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 890 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 907 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 922 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"








 






 




#line 954 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"



 
     
 


 
 
#line 2007 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 







 
#line 2099 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
#line 2135 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"



 
#line 2149 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
  






   
#line 2170 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2182 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
#line 2192 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
#line 2203 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
  






 



                                        


#line 2228 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2239 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2258 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 








 











#line 2288 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


   
  






 
#line 2307 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 







 




    
   






 
#line 2459 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
 






  
#line 2486 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2503 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
  

 
  






  
#line 2556 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2563 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 







 
#line 2580 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
  
#line 2587 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
    



 
#line 2603 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2612 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 




 








#line 2635 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
   







 




  







 




 
#line 2678 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2695 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 




 




                                          






 
                                        







 
#line 2740 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2757 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 








 











#line 2787 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
                                        







 




 
                                        







 
#line 2829 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2846 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 
                                        







 
#line 2864 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 2871 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"


 

 

 
#line 3256 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 3526 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 3902 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 4706 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 5719 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 5765 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"




























 
#line 5800 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 
                             
 








 



#line 5883 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"














 





#line 5928 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 5951 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 6041 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 
#line 6060 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
                                 
#line 6079 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6091 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
 

 











 








 


                                 
#line 6150 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6315 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
      
#line 6364 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6598 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6653 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
      
#line 6677 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

 

#line 6704 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6717 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"



 

 


 



 
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);

uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

#line 6742 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"
HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);







  



 
 
 
 


 




 
   
#line 6776 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"






 






 
#line 6802 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

 





 


      



      
#line 6827 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6837 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"




 



 

 


 


 


      



























      



      


#line 6910 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6918 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6938 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 6990 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 7011 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"

#line 7075 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc_ex.h"






      













 



 



  



   






 
#line 34 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"



 



 

 


 



 
typedef struct
{
  uint32_t OscillatorType;       
 

  uint32_t HSEState;             
 

  uint32_t LSEState;             
 

  uint32_t HSIState;             
 

  uint32_t HSICalibrationValue;  
 

  uint32_t LSIState;             
 

  RCC_PLLInitTypeDef PLL;         
}RCC_OscInitTypeDef;



 
typedef struct
{
  uint32_t ClockType;             
 

  uint32_t SYSCLKSource;          
 

  uint32_t AHBCLKDivider;         
 

  uint32_t APB1CLKDivider;        
 

  uint32_t APB2CLKDivider;        
 

}RCC_ClkInitTypeDef;



 

 


 



 







 



 





 



 





 



 






 



 




 



 





 



 






 



 




 



 






 





 






 





 






 



 
#line 236 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 



 







 



 
#line 289 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 



 




 



 






 



 







 



 
#line 335 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 









 
 





 


 
#line 366 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 



 

 


 







 
#line 428 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 435 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 







 
#line 452 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 459 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 







 
#line 519 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 527 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 







 
#line 545 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 553 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 







 
#line 620 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 629 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 







 
#line 648 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 657 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 




 
#line 672 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 680 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 




 
#line 696 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 705 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 




 
#line 722 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 732 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 








 
#line 750 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 757 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 








 
#line 776 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 784 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 








 
#line 804 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"

#line 813 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 



 















 









 




 



 








 




 



 





















 
#line 912 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 



 


















 
#line 955 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"


 



 



 























 













 






 






 




 



 







 










 










 



 



 









 










 







 



 



 















 




















 




 




 











 












 













 













 




 



















 





 



 

 
 

 



 
 
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);


 



 
 
void     HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void     HAL_RCC_EnableCSS(void);
void     HAL_RCC_DisableCSS(void);
uint32_t HAL_RCC_GetSysClockFreq(void);
uint32_t HAL_RCC_GetHCLKFreq(void);
uint32_t HAL_RCC_GetPCLK1Freq(void);
uint32_t HAL_RCC_GetPCLK2Freq(void);
void     HAL_RCC_GetOscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
void     HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency);

 
void HAL_RCC_NMI_IRQHandler(void);

 
void HAL_RCC_CSSCallback(void);



 



 

 
 
 


 




 

 
 



 


 



 
 



 



 
 




 


 


 


 












 



 

 


 



 






















#line 1411 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_rcc.h"































 



 



 



 







 
#line 276 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"


#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio.h"



 



  

 


 



  
typedef struct
{
  uint32_t Pin;       
 

  uint32_t Mode;      
 

  uint32_t Pull;      
 

  uint32_t Speed;     
 

  uint32_t Alternate;  
 
}GPIO_InitTypeDef;



 
typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
}GPIO_PinState;


 

 



  



 
#line 103 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio.h"




 









  







    



 






 




 






 

 


   





 
  


 

 


 






 







 







 







 







 



 

 
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"



 



  

 
 


 
  


 

 
#line 166 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 
#line 281 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 



  








  





  






  







  






  






  





  







  






  








  





  




  






  




  


 

 
#line 483 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

 

 
#line 573 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 
#line 682 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

 

 
#line 816 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

 
#line 908 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

 
#line 982 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

 
#line 1102 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 
#line 1225 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 


  



 

 


 


 

 


 


 

 
 
 


 


 

 


 


 
#line 1277 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

#line 1291 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"







#line 1305 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

#line 1333 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"



 



   
 
#line 1367 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 
#line 1394 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 
#line 1416 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"


 

 
#line 1441 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"

 

 
#line 1461 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 
 




 
#line 1486 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 
#line 1518 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 
#line 1547 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio_ex.h"
 

 



 

 



 



  



 

 


 



 



  



  
  






 
#line 215 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio.h"

 


 



 
 
void  HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void  HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);


 



 
 
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



  



  
 
 
 


 
#line 273 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio.h"



 

 


 
#line 300 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_gpio.h"


 

 


 



 



  



 







 
#line 280 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"


#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_exti.h"

















 

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_exti.h"



 




 

 



 
typedef enum
{
  HAL_EXTI_COMMON_CB_ID          = 0x00U
} EXTI_CallbackIDTypeDef;



 
typedef struct
{
  uint32_t Line;                     
  void (* PendingCallback)(void);    
} EXTI_HandleTypeDef;



 
typedef struct
{
  uint32_t Line;      
 
  uint32_t Mode;      
 
  uint32_t Trigger;   
 
  uint32_t GPIOSel;   

 
} EXTI_ConfigTypeDef;



 

 


 



 
#line 125 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_exti.h"



 



 





 



 







 




 
#line 183 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_exti.h"



 



 

 


 



 

 


 


 








 




 




 




 








 

 


 














#line 310 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_exti.h"




 

 



 




 
 
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);


 




 
 
void HAL_EXTI_IRQHandler(EXTI_HandleTypeDef *hexti);
uint32_t HAL_EXTI_GetPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_ClearPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void HAL_EXTI_GenerateSWI(EXTI_HandleTypeDef *hexti);



 



 



 



 







 
#line 284 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"


#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"



 



  

 




 
   


 
typedef struct
{
  uint32_t Channel;              
 

  uint32_t Direction;            

 

  uint32_t PeriphInc;            
 

  uint32_t MemInc;               
 

  uint32_t PeriphDataAlignment;  
 

  uint32_t MemDataAlignment;     
 

  uint32_t Mode;                 


 

  uint32_t Priority;             
 

  uint32_t FIFOMode;             


 

  uint32_t FIFOThreshold;        
 

  uint32_t MemBurst;             



 

  uint32_t PeriphBurst;          



 
}DMA_InitTypeDef;




 
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,   
  HAL_DMA_STATE_READY             = 0x01U,   
  HAL_DMA_STATE_BUSY              = 0x02U,   
  HAL_DMA_STATE_TIMEOUT           = 0x03U,   
  HAL_DMA_STATE_ERROR             = 0x04U,   
  HAL_DMA_STATE_ABORT             = 0x05U,   
}HAL_DMA_StateTypeDef;



 
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,   
  HAL_DMA_HALF_TRANSFER           = 0x01U    
}HAL_DMA_LevelCompleteTypeDef;



 
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID         = 0x00U,   
  HAL_DMA_XFER_HALFCPLT_CB_ID     = 0x01U,   
  HAL_DMA_XFER_M1CPLT_CB_ID       = 0x02U,   
  HAL_DMA_XFER_M1HALFCPLT_CB_ID   = 0x03U,   
  HAL_DMA_XFER_ERROR_CB_ID        = 0x04U,   
  HAL_DMA_XFER_ABORT_CB_ID        = 0x05U,   
  HAL_DMA_XFER_ALL_CB_ID          = 0x06U    
}HAL_DMA_CallbackIDTypeDef;



 
typedef struct __DMA_HandleTypeDef
{
  DMA_Stream_TypeDef         *Instance;                                                         

  DMA_InitTypeDef            Init;                                                               

  HAL_LockTypeDef            Lock;                                                                

  volatile HAL_DMA_StateTypeDef  State;                                                             

  void                       *Parent;                                                            

  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);          

  void                       (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);      

  void                       (* XferM1CpltCallback)( struct __DMA_HandleTypeDef * hdma);        
  
  void                       (* XferM1HalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);    
  
  void                       (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);         
  
  void                       (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);           

  volatile uint32_t              ErrorCode;                                                         
  
  uint32_t                   StreamBaseAddress;                                                 

  uint32_t                   StreamIndex;                                                       
 
}DMA_HandleTypeDef;



 

 




 




  
#line 194 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"


 




  
#line 220 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"


 




  





 
        



  




  




  




 




  





  




 





 




  





 




 






  




 




  




 






  




  






  




  






 




 







 




  
#line 383 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"


 



 
 
 




 













 






 






 


 





 
#line 448 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"





       
#line 468 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"





 
#line 488 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"





 
#line 508 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"





 
#line 528 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"













 

















 
















 














 














 




















 







 



 
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma_ex.h"

















 

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma_ex.h"



 



  

 



 
   


  
typedef enum
{
  MEMORY0      = 0x00U,     
  MEMORY1      = 0x01U      
}HAL_DMA_MemoryTypeDef;



 

 



 




 

 
HAL_StatusTypeDef HAL_DMAEx_MultiBufferStart(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t SecondMemAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMAEx_MultiBufferStart_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t SecondMemAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMAEx_ChangeMemory(DMA_HandleTypeDef *hdma, uint32_t Address, HAL_DMA_MemoryTypeDef memory);



 


 
         
 



 


 



 



 







 
#line 641 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"

 




 




 
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma); 
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);


 




 
HAL_StatusTypeDef HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel, uint32_t Timeout);
void              HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_CleanCallbacks(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)(DMA_HandleTypeDef *_hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);



  




 
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t             HAL_DMA_GetError(DMA_HandleTypeDef *hdma);


  


  
 



 


  

 



 
#line 730 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_dma.h"

















































  

 



 


 



  



 







 
#line 288 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"


#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"



 



  
 


 





 
typedef struct
{
  uint8_t                Enable;                
 
  uint8_t                Number;                
 
  uint32_t               BaseAddress;            
  uint8_t                Size;                  
 
  uint8_t                SubRegionDisable;      
          
  uint8_t                TypeExtField;          
                  
  uint8_t                AccessPermission;      
 
  uint8_t                DisableExec;           
 
  uint8_t                IsShareable;           
 
  uint8_t                IsCacheable;           
 
  uint8_t                IsBufferable;          
 
}MPU_Region_InitTypeDef;


 




 

 



 



 
#line 100 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"


 



 





 




 







 



 




 



 




 



 




 



 




 



 




 



 





 



 
#line 213 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"


 
   


 
#line 226 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"


 



 
#line 241 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"


 




 


 

 


 
  


 
 
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn);
void HAL_NVIC_SystemReset(void);
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb);


 



 
 
uint32_t HAL_NVIC_GetPriorityGrouping(void);
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority);
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn);
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource);
void HAL_SYSTICK_IRQHandler(void);
void HAL_SYSTICK_Callback(void);


void HAL_MPU_Enable(uint32_t MPU_Control);
void HAL_MPU_Disable(void);
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_Init);



 



 

 
 
 
 


 



































#line 347 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"

#line 356 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"

#line 385 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_cortex.h"






 

 



  



 
  





 

 
#line 292 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"






#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"

















 

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"



 




 

 


 


 
typedef enum
{
  HAL_CAN_STATE_RESET             = 0x00U,   
  HAL_CAN_STATE_READY             = 0x01U,   
  HAL_CAN_STATE_LISTENING         = 0x02U,   
  HAL_CAN_STATE_SLEEP_PENDING     = 0x03U,   
  HAL_CAN_STATE_SLEEP_ACTIVE      = 0x04U,   
  HAL_CAN_STATE_ERROR             = 0x05U    

} HAL_CAN_StateTypeDef;



 
typedef struct
{
  uint32_t Prescaler;                  
 

  uint32_t Mode;                       
 

  uint32_t SyncJumpWidth;              

 

  uint32_t TimeSeg1;                   
 

  uint32_t TimeSeg2;                   
 

  FunctionalState TimeTriggeredMode;   
 

  FunctionalState AutoBusOff;          
 

  FunctionalState AutoWakeUp;          
 

  FunctionalState AutoRetransmission;  
 

  FunctionalState ReceiveFifoLocked;   
 

  FunctionalState TransmitFifoPriority;
 

} CAN_InitTypeDef;



 
typedef struct
{
  uint32_t FilterIdHigh;          

 

  uint32_t FilterIdLow;           

 

  uint32_t FilterMaskIdHigh;      


 

  uint32_t FilterMaskIdLow;       


 

  uint32_t FilterFIFOAssignment;  
 

  uint32_t FilterBank;            



 

  uint32_t FilterMode;            
 

  uint32_t FilterScale;           
 

  uint32_t FilterActivation;      
 

  uint32_t SlaveStartFilterBank;  




 

} CAN_FilterTypeDef;



 
typedef struct
{
  uint32_t StdId;    
 

  uint32_t ExtId;    
 

  uint32_t IDE;      
 

  uint32_t RTR;      
 

  uint32_t DLC;      
 

  FunctionalState TransmitGlobalTime; 



 

} CAN_TxHeaderTypeDef;



 
typedef struct
{
  uint32_t StdId;    
 

  uint32_t ExtId;    
 

  uint32_t IDE;      
 

  uint32_t RTR;      
 

  uint32_t DLC;      
 

  uint32_t Timestamp; 

 

  uint32_t FilterMatchIndex; 
 

} CAN_RxHeaderTypeDef;



 
typedef struct __CAN_HandleTypeDef
{
  CAN_TypeDef                 *Instance;                  

  CAN_InitTypeDef             Init;                       

  volatile HAL_CAN_StateTypeDef   State;                      

  volatile uint32_t               ErrorCode;                 
 

#line 239 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"
} CAN_HandleTypeDef;

#line 272 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"


 

 



 



 
#line 308 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"








 



 




 



 






 




 






 



 
#line 369 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"


 



 
#line 384 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"


 



 




 



 




 



 




 



 




 



 




 



 




 



 




 



 





 



 
 
#line 483 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"

 





 






 





 




 
 


 
#line 519 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"

 



 







 



 

 


 




 
#line 556 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"







 








 







 







 
#line 595 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"
























 








 

 


 




 

 
HAL_StatusTypeDef HAL_CAN_Init(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_DeInit(CAN_HandleTypeDef *hcan);
void HAL_CAN_MspInit(CAN_HandleTypeDef *hcan);
void HAL_CAN_MspDeInit(CAN_HandleTypeDef *hcan);

#line 652 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"


 




 

 
HAL_StatusTypeDef HAL_CAN_ConfigFilter(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *sFilterConfig);



 




 

 
HAL_StatusTypeDef HAL_CAN_Start(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_Stop(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_RequestSleep(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_WakeUp(CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_IsSleepActive(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_AddTxMessage(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox);
HAL_StatusTypeDef HAL_CAN_AbortTxRequest(CAN_HandleTypeDef *hcan, uint32_t TxMailboxes);
uint32_t HAL_CAN_GetTxMailboxesFreeLevel(CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_IsTxMessagePending(CAN_HandleTypeDef *hcan, uint32_t TxMailboxes);
uint32_t HAL_CAN_GetTxTimestamp(CAN_HandleTypeDef *hcan, uint32_t TxMailbox);
HAL_StatusTypeDef HAL_CAN_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);
uint32_t HAL_CAN_GetRxFifoFillLevel(CAN_HandleTypeDef *hcan, uint32_t RxFifo);



 




 
 
HAL_StatusTypeDef HAL_CAN_ActivateNotification(CAN_HandleTypeDef *hcan, uint32_t ActiveITs);
HAL_StatusTypeDef HAL_CAN_DeactivateNotification(CAN_HandleTypeDef *hcan, uint32_t InactiveITs);
void HAL_CAN_IRQHandler(CAN_HandleTypeDef *hcan);



 




 
 

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox0AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox1AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox2AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0FullCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1FullCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_SleepCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_WakeUpFromRxMsgCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan);



 




 
 
HAL_CAN_StateTypeDef HAL_CAN_GetState(CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_GetError(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_ResetError(CAN_HandleTypeDef *hcan);



 



 

 


 



 

 


 



 

 


 



 

 


 

#line 825 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_can.h"



 
 



 





 








 
#line 300 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"






























#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash.h"



 



  

 


 
 


 
typedef enum 
{
  FLASH_PROC_NONE = 0U, 
  FLASH_PROC_SECTERASE,
  FLASH_PROC_MASSERASE,
  FLASH_PROC_PROGRAM
} FLASH_ProcedureTypeDef;



 
typedef struct
{
  volatile FLASH_ProcedureTypeDef ProcedureOnGoing;    
  
  volatile uint32_t               NbSectorsToErase;    
  
  volatile uint8_t                VoltageForErase;     
  
  volatile uint32_t               Sector;              
  
  volatile uint32_t               Bank;                
  
  volatile uint32_t               Address;             
  
  HAL_LockTypeDef             Lock;                

  volatile uint32_t               ErrorCode;           

}FLASH_ProcessTypeDef;



 

 


   



  
#line 97 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash.h"


 
  


  






 




  
#line 126 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash.h"


 
  



  




   



 







  



  







  



  
  
 


 





  






  





  





  





  





  





  





  






 








 










   









   
















 















 



 

 
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"



 



  

 


 



 
typedef struct
{
  uint32_t TypeErase;   
 

  uint32_t Banks;       
 

  uint32_t Sector;      
 

  uint32_t NbSectors;   
 

  uint32_t VoltageRange;
 

} FLASH_EraseInitTypeDef;



 
typedef struct
{
  uint32_t OptionType;   
 

  uint32_t WRPState;     
 

  uint32_t WRPSector;         
 

  uint32_t Banks;        
         

  uint32_t RDPLevel;     
 

  uint32_t BORLevel;     
 

  uint8_t  USERConfig;    

} FLASH_OBProgramInitTypeDef;



 
#line 133 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"


 

 



 



  




 
  


  






 
  


  




 
  


  






 
  


 






  
  


  




  
  


  




  




  




     



   






 

#line 249 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"



  






#line 266 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"


 



 
   
#line 293 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

  




     
#line 311 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 



  
  



 
#line 327 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"

#line 336 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"


  
    


 





#line 356 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"


  



 
    
#line 391 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

    
#line 412 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
       

  
#line 430 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

  
#line 441 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

  
#line 451 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

 
#line 464 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 



  



 
   
#line 502 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

  
#line 524 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
     
      
  
#line 543 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

 
#line 555 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 
 
 
#line 566 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

 
#line 580 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 


 
  


 
    
#line 617 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 
      
 
#line 639 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
       

 
#line 651 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

 
#line 662 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 

 
#line 677 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 



 
  


 







 



 
#line 708 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"


 



  
  
 

 


 



 
 
HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *SectorError);
HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);
HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void              HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);

#line 744 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"







 



 
 
 
 


 
  




 




  





  




  




 






  






 

 


 



 



























#line 849 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"







#line 863 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
  
#line 883 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"

#line 898 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"







#line 913 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"
 
#line 928 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"

#line 939 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"

#line 949 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"













#line 968 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"





  
























   


























#line 1034 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ex.h"


 



 

 


 
void FLASH_Erase_Sector(uint32_t Sector, uint8_t VoltageRange);
void FLASH_FlushCaches(void);


  



  



 







 
#line 298 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash.h"
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ramfunc.h"

















  

 



#line 75 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash_ramfunc.h"




 
#line 299 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_flash.h"

 


 


 
 
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
 
void HAL_FLASH_IRQHandler(void);
  
void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);


 



 
 
HAL_StatusTypeDef HAL_FLASH_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_Lock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);
 
HAL_StatusTypeDef HAL_FLASH_OB_Launch(void);


 



 
 
uint32_t HAL_FLASH_GetError(void);
HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout);


 



  
 
 


 



 
 


 



  



  



  



  



  




 

 


 



 






 



 

 


 



 



  



 







 
#line 332 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"


























#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"

















 

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"



 



 

 


 




 
typedef struct
{
  uint32_t ClockSpeed;       
 

  uint32_t DutyCycle;        
 

  uint32_t OwnAddress1;      
 

  uint32_t AddressingMode;   
 

  uint32_t DualAddressMode;  
 

  uint32_t OwnAddress2;      
 

  uint32_t GeneralCallMode;  
 

  uint32_t NoStretchMode;    
 

} I2C_InitTypeDef;



 



























 
typedef enum
{
  HAL_I2C_STATE_RESET             = 0x00U,    
  HAL_I2C_STATE_READY             = 0x20U,    
  HAL_I2C_STATE_BUSY              = 0x24U,    
  HAL_I2C_STATE_BUSY_TX           = 0x21U,    
  HAL_I2C_STATE_BUSY_RX           = 0x22U,    
  HAL_I2C_STATE_LISTEN            = 0x28U,    
  HAL_I2C_STATE_BUSY_TX_LISTEN    = 0x29U,   
 
  HAL_I2C_STATE_BUSY_RX_LISTEN    = 0x2AU,   
 
  HAL_I2C_STATE_ABORT             = 0x60U,    
  HAL_I2C_STATE_TIMEOUT           = 0xA0U,    
  HAL_I2C_STATE_ERROR             = 0xE0U     

} HAL_I2C_StateTypeDef;



 


















 
typedef enum
{
  HAL_I2C_MODE_NONE               = 0x00U,    
  HAL_I2C_MODE_MASTER             = 0x10U,    
  HAL_I2C_MODE_SLAVE              = 0x20U,    
  HAL_I2C_MODE_MEM                = 0x40U     

} HAL_I2C_ModeTypeDef;



 




 
#line 177 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"


 




 



typedef struct

{
  I2C_TypeDef                *Instance;       

  I2C_InitTypeDef            Init;            

  uint8_t                    *pBuffPtr;       

  uint16_t                   XferSize;        

  volatile uint16_t              XferCount;       

  volatile uint32_t              XferOptions;     

  volatile uint32_t              PreviousState;  
 

  DMA_HandleTypeDef          *hdmatx;         

  DMA_HandleTypeDef          *hdmarx;         

  HAL_LockTypeDef            Lock;            

  volatile HAL_I2C_StateTypeDef  State;           

  volatile HAL_I2C_ModeTypeDef   Mode;            

  volatile uint32_t              ErrorCode;       

  volatile uint32_t              Devaddress;      

  volatile uint32_t              Memaddress;      

  volatile uint32_t              MemaddSize;      

  volatile uint32_t              EventCount;      


#line 244 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"
} I2C_HandleTypeDef;

#line 274 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"


 



 
 



 



 




 



 




 



 




 



 




 



 




 



 




 



 




 



 
#line 359 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"



 




 






 





 



 

#line 402 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"


 



 

 



 




 
#line 429 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"









 











 
























 













 






 
#line 504 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"




 
#line 516 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"




 





 




 

 
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c_ex.h"

















 

 







#line 109 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c_ex.h"








 
#line 535 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"

 


 



 
 
HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c);

 
#line 558 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"


 



 
 
 
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout);

 
HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Mem_Write_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Mem_Read_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);

HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_EnableListen_IT(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_DisableListen_IT(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress);

 
HAL_StatusTypeDef HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);

HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);


 



 
 
void HAL_I2C_EV_IRQHandler(I2C_HandleTypeDef *hi2c);
void HAL_I2C_ER_IRQHandler(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode);
void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c);


 



 
 
HAL_I2C_StateTypeDef HAL_I2C_GetState(I2C_HandleTypeDef *hi2c);
HAL_I2C_ModeTypeDef HAL_I2C_GetMode(I2C_HandleTypeDef *hi2c);
uint32_t HAL_I2C_GetError(I2C_HandleTypeDef *hi2c);



 



 
 
 
 


 





 

 


 

#line 669 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"













 
#line 705 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_i2c.h"








 



 

 


 



 



 



 








 
#line 360 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"


















#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr.h"



 



  

 



 
   


 
typedef struct
{
  uint32_t PVDLevel;   
 

  uint32_t Mode;      
 
}PWR_PVDTypeDef;



 

 


 
  


 



 



  
#line 86 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr.h"


    
 


 
#line 100 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr.h"


 




 




 
    


 




 



 




 



 







 



  
  
 


 





















 







 





 





 





 





 





 





 





 






 






 








 







 





 





 




 

 
#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"

















  

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"



 



  

  
 


 
#line 66 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"



 
#line 80 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"


 
#line 99 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"



  
  
 


 










 
#line 145 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"

#line 193 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"


 

 


 
 


 
void HAL_PWREx_EnableFlashPowerDown(void);
void HAL_PWREx_DisableFlashPowerDown(void); 
HAL_StatusTypeDef HAL_PWREx_EnableBkUpReg(void);
HAL_StatusTypeDef HAL_PWREx_DisableBkUpReg(void); 
uint32_t HAL_PWREx_GetVoltageRange(void);
HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling);

#line 221 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"

#line 228 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"



 



 
 
 
 


 



 
 
 
 



 



 


    
 



 



 

 



   
 
 





 



 

 


 



 






#line 310 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"

#line 321 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr_ex.h"


 



 



  



 
  







 
#line 275 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr.h"

 


 
  


 
 
void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);


 



 
 
 
void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);

 
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);

 
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTANDBYMode(void);

 
void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVDCallback(void);

 
void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);


 



 

 
 
 


 



 



 



 
 







 



 
 
 



 



 




 



 
 
 




 



 
 


 



 
#line 408 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_pwr.h"


 



 



  



 
  







 
#line 380 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"


















#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"

















 

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"



 



 

 


 



 
typedef struct
{
  uint32_t Mode;                
 

  uint32_t Direction;           
 

  uint32_t DataSize;            
 

  uint32_t CLKPolarity;         
 

  uint32_t CLKPhase;            
 

  uint32_t NSS;                 

 

  uint32_t BaudRatePrescaler;   



 

  uint32_t FirstBit;            
 

  uint32_t TIMode;              
 

  uint32_t CRCCalculation;      
 

  uint32_t CRCPolynomial;       
 
} SPI_InitTypeDef;



 
typedef enum
{
  HAL_SPI_STATE_RESET      = 0x00U,     
  HAL_SPI_STATE_READY      = 0x01U,     
  HAL_SPI_STATE_BUSY       = 0x02U,     
  HAL_SPI_STATE_BUSY_TX    = 0x03U,     
  HAL_SPI_STATE_BUSY_RX    = 0x04U,     
  HAL_SPI_STATE_BUSY_TX_RX = 0x05U,     
  HAL_SPI_STATE_ERROR      = 0x06U,     
  HAL_SPI_STATE_ABORT      = 0x07U      
} HAL_SPI_StateTypeDef;



 
typedef struct __SPI_HandleTypeDef
{
  SPI_TypeDef                *Instance;       

  SPI_InitTypeDef            Init;            

  uint8_t                    *pTxBuffPtr;     

  uint16_t                   TxXferSize;      

  volatile uint16_t              TxXferCount;     

  uint8_t                    *pRxBuffPtr;     

  uint16_t                   RxXferSize;      

  volatile uint16_t              RxXferCount;     

  void (*RxISR)(struct __SPI_HandleTypeDef *hspi);    

  void (*TxISR)(struct __SPI_HandleTypeDef *hspi);    

  DMA_HandleTypeDef          *hdmatx;         

  DMA_HandleTypeDef          *hdmarx;         

  HAL_LockTypeDef            Lock;            

  volatile HAL_SPI_StateTypeDef  State;           

  volatile uint32_t              ErrorCode;       

#line 150 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"
} SPI_HandleTypeDef;

#line 177 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"


 

 


 



 
#line 200 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"


 



 




 



 





 



 




 



 




 



 




 



 





 



 
#line 271 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"


 



 




 



 




 



 




 



 





 



 
#line 324 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"


 



 

 


 





 
#line 351 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"










 











 











 
















 






 






 
#line 424 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"





 
#line 437 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"





 
#line 449 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"





 






 




 

 


 





 






 






 















 











 







 







 







 





 







 







 







 







 








 
#line 599 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_spi.h"





 







 







 







 







 




 

 


 



 
 
HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DeInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi);

 






 



 
 
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size,
                                          uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Transmit_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Receive_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData,
                                             uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Transmit_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Receive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData,
                                              uint16_t Size);
HAL_StatusTypeDef HAL_SPI_DMAPause(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DMAResume(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DMAStop(SPI_HandleTypeDef *hspi);
 
HAL_StatusTypeDef HAL_SPI_Abort(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Abort_IT(SPI_HandleTypeDef *hspi);

void HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi);


 



 
 
HAL_SPI_StateTypeDef HAL_SPI_GetState(SPI_HandleTypeDef *hspi);
uint32_t             HAL_SPI_GetError(SPI_HandleTypeDef *hspi);


 



 



 



 







 
#line 400 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"






#line 1 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"

















 

 







 
#line 30 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"



 



 

 


 



 
typedef struct
{
  uint32_t BaudRate;                  



 

  uint32_t WordLength;                
 

  uint32_t StopBits;                  
 

  uint32_t Parity;                    




 

  uint32_t Mode;                      
 

  uint32_t HwFlowCtl;                 
 

  uint32_t OverSampling;              
 
} UART_InitTypeDef;







































 
typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,    
 
  HAL_UART_STATE_READY             = 0x20U,    
 
  HAL_UART_STATE_BUSY              = 0x24U,    
 
  HAL_UART_STATE_BUSY_TX           = 0x21U,    
 
  HAL_UART_STATE_BUSY_RX           = 0x22U,    
 
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    

 
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    
 
  HAL_UART_STATE_ERROR             = 0xE0U     
 
} HAL_UART_StateTypeDef;







 
typedef uint32_t HAL_UART_RxTypeTypeDef;



 
typedef struct __UART_HandleTypeDef
{
  USART_TypeDef                 *Instance;         

  UART_InitTypeDef              Init;              

  uint8_t                       *pTxBuffPtr;       

  uint16_t                      TxXferSize;        

  volatile uint16_t                 TxXferCount;       

  uint8_t                       *pRxBuffPtr;       

  uint16_t                      RxXferSize;        

  volatile uint16_t                 RxXferCount;       

  volatile HAL_UART_RxTypeTypeDef ReceptionType;       

  DMA_HandleTypeDef             *hdmatx;           

  DMA_HandleTypeDef             *hdmarx;           

  HAL_LockTypeDef               Lock;              

  volatile HAL_UART_StateTypeDef    gState;           

 

  volatile HAL_UART_StateTypeDef    RxState;          
 

  volatile uint32_t                 ErrorCode;         

#line 200 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"

} UART_HandleTypeDef;

#line 231 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"



 

 


 



 
#line 253 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"


 



 




 



 




 



 





 



 






 



 





 



 




 



 




 



 




 



 




 





 
#line 357 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"


 









 













 



 




 



 

 


 






 
#line 422 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"





 



















 























 







 
#line 487 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"






 







 







 







 

















 



















 


















 
















 



















 



















 



















 









 





 






 





 



 

 


 



 

 
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

 
#line 713 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"



 



 

 
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

 
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);



 



 
 
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);


 



 
 
HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart);
uint32_t              HAL_UART_GetError(UART_HandleTypeDef *huart);


 



 
 
 
 


 


 







 

 


 
#line 835 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal_uart.h"






 









 






 

 


 

HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);



 



 



 







 
#line 408 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"






























































 
#line 486 "C:\\Users\\LENOVO\\Desktop\\slavecontroller\\RTE\\Device\\STM32F407ZETx\\STCubeGenerated\\Inc\\stm32f4xx_hal_conf.h"





#line 31 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal.h"



 



  

 
 



 



 
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;


 



 
   
 


 


 
#line 94 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal.h"

#line 117 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal.h"


 



 





 






 





#line 156 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal.h"

#line 186 "D:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F4xx_DFP\\2.16.0\\Drivers\\STM32F4xx_HAL_Driver\\Inc\\stm32f4xx_hal.h"


 



 





 

 



 
extern volatile uint32_t uwTick;
extern uint32_t uwTickPrio;
extern HAL_TickFreqTypeDef uwTickFreq;


 

 


 


 
 
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick (uint32_t TickPriority);


 



 
 
void HAL_IncTick(void);
void HAL_Delay(uint32_t Delay);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);
uint32_t HAL_GetHalVersion(void);
uint32_t HAL_GetREVID(void);
uint32_t HAL_GetDEVID(void);
void HAL_DBGMCU_EnableDBGSleepMode(void);
void HAL_DBGMCU_DisableDBGSleepMode(void);
void HAL_DBGMCU_EnableDBGStopMode(void);
void HAL_DBGMCU_DisableDBGStopMode(void);
void HAL_DBGMCU_EnableDBGStandbyMode(void);
void HAL_DBGMCU_DisableDBGStandbyMode(void);
void HAL_EnableCompensationCell(void);
void HAL_DisableCompensationCell(void);
uint32_t HAL_GetUIDw0(void);
uint32_t HAL_GetUIDw1(void);
uint32_t HAL_GetUIDw2(void);







 



 
 
 


 


 
 


 


 
 
 


 



  
  






 
#line 59 "etherCAT\\SPIDriver.h"




	
	
	
	
	
#line 79 "etherCAT\\SPIDriver.h"

#line 91 "etherCAT\\SPIDriver.h"







  




    typedef union {
        unsigned short Val;
        struct __attribute__((packed)) {
            unsigned char LB;
            unsigned char HB;
        } byte;
    } UINT16_VAL;

    typedef union {
        unsigned int Val;
        unsigned short w[2] __attribute__((packed));
        unsigned char  v[4];
        struct __attribute__((packed)) {
            unsigned short LW;
            unsigned short HW;
        } word;
        struct __attribute__((packed)) {
            unsigned char LB;
            unsigned char HB;
            unsigned char UB;
            unsigned char MB;
        } byte;
    } UINT32_VAL;

    typedef union {
        unsigned long long Val;
        unsigned short w[4];
        unsigned char  v[8];
    } UINT64_VAL;




		
extern SPI_HandleTypeDef *EcatHspiPtr;
extern unsigned char EcatSpiReadBuffer[512u];
extern unsigned char EcatSpiWriteBuffer[512u];
	
	
	
	
	

	void SPIWritePDRamRegister(unsigned char *WriteBuffer, unsigned short Address, unsigned short Count);
	void SPIReadPDRamRegister(unsigned char *ReadBuffer, unsigned short Address, unsigned short Count);
    void SPIReadRegUsingCSR(unsigned char *ReadBuffer, unsigned short Address, unsigned char Count);
    void SPIWriteRegUsingCSR( unsigned char *WriteBuffer, unsigned short Address, unsigned char Count);
	void SPIWriteDWord (unsigned short Address, unsigned int Val);
	unsigned int SPIReadDWord (unsigned short Address);
    void SPIWriteBurstMode (unsigned int Val);
    unsigned int SPIReadBurstMode (void);
    void SPISendAddr (unsigned short Address);
    void PDIWriteLAN9252DirectReg( unsigned int Val, unsigned short Address);
    unsigned int PDIReadLAN9252DirectReg( unsigned short Address);
    void PDIReadReg(unsigned char *ReadBuffer, unsigned short Address, unsigned short Count);
    void PDIWriteReg( unsigned char *WriteBuffer, unsigned short Address, unsigned short Count);






#line 54 "etherCAT\\9252_HW.h"
#line 1 "etherCAT\\PDIDriver.h"





 




#line 12 "etherCAT\\PDIDriver.h"
#line 13 "etherCAT\\PDIDriver.h"
#line 1 "etherCAT\\9252_HW.h"




















 






















 

#line 14 "etherCAT\\PDIDriver.h"
extern uint8_t PDI_Isr_enable;

void PDI_Enable_Global_interrupt(void);
void PDI_IRQ_Interrupt(void);
void PDI_Init_SYNC_Interrupts(void);
void PDI_Timer_Interrupt(void);
#line 55 "etherCAT\\9252_HW.h"




#line 65 "etherCAT\\9252_HW.h"





#line 76 "etherCAT\\9252_HW.h"


































#line 116 "etherCAT\\9252_HW.h"









































extern volatile unsigned int restore_intsts;




extern unsigned char LAN9252_Init(void);
extern void HW_Release(void);

extern unsigned short HW_GetALEventRegister(void);
extern unsigned short HW_GetALEventRegister_Isr(void);

extern void HW_ResetALEventMask(unsigned short intMask);
extern void HW_SetALEventMask(unsigned short intMask);

extern void HW_EscRead( unsigned char * pData, unsigned short Address, unsigned short Len );
extern void HW_EscReadIsr( unsigned char *pData, unsigned short Address, unsigned short Len );

extern void HW_EscWrite( unsigned char *pData, unsigned short Address, unsigned short Len );
extern void HW_EscWriteIsr( unsigned char *pData, unsigned short Address, unsigned short Len );

extern void HW_DisableSyncManChannel(unsigned char channel);
extern void HW_EnableSyncManChannel(unsigned char channel);
extern TSYNCMAN  *HW_GetSyncMan(unsigned char channel);
extern void HW_SetLed(unsigned char RunLed,unsigned char ErrLed);

extern unsigned int PDI_GetTimer();
extern void PDI_ClearTimer();

extern void PDI_Restore_Global_Interrupt(unsigned int int_sts);
extern unsigned int PDI_Disable_Global_Interrupt();



#line 51 "etherCAT\\ecatslv.h"









 


     
     



 































































































 














































 
 





 
#line 228 "etherCAT\\ecatslv.h"

#line 236 "etherCAT\\ecatslv.h"










 
#line 306 "etherCAT\\ecatslv.h"
                                                              

                                                              


 









 
#line 331 "etherCAT\\ecatslv.h"
 





 




 
#line 350 "etherCAT\\ecatslv.h"










 














 
extern    unsigned char                           bBootMode;  
extern    unsigned char                           bEcatOutputUpdateRunning;  
 

extern    unsigned char                            bEcatInputUpdateRunning;  
 

extern    unsigned char                           bEcatFirstOutputsReceived; 

 

extern    unsigned char                           bWdTrigger;  

extern    unsigned char                           bDcSyncActive;  

extern    short                          EsmTimeoutCounter; 
 



extern unsigned char                              bDcRunning;  

extern unsigned short                            u16SmSync0Counter;  
extern unsigned short                            u16SmSync0Value;  

extern unsigned char                              bSmSyncSequenceValid;  

extern short                             i16WaitForPllRunningTimeout;  

extern short                             i16WaitForPllRunningCnt;  

extern unsigned short                            Sync0WdCounter;  
extern unsigned short                            Sync0WdValue;  

extern unsigned short                            Sync1WdCounter;  
extern unsigned short                            Sync1WdValue;  

extern unsigned short                            LatchInputSync0Value;  
extern unsigned short                            LatchInputSync0Counter;  

extern unsigned char b32BitDc;

 


extern unsigned char                              bEscIntEnabled; 
 

extern unsigned char                              b3BufferMode;  

 
extern unsigned short                            u16LocalErrorCode;  
extern unsigned char                             u8LocalErrorState;  
 
extern unsigned char                              bApplEsmPending;  
extern unsigned char                              bEcatWaitForAlControlRes; 
 

extern unsigned short                            nEcatStateTrans;  

extern unsigned char                             u8EcatErrorLed;  

extern unsigned char                             u8EcatRunLed;  

extern unsigned short                            nPdInputSize;  

extern unsigned short                            nPdOutputSize;  

extern unsigned char                             nMaxSyncMan;  

extern unsigned short                            nMaxEscAddress;  

extern unsigned char                             nAlStatus;  

extern unsigned char                              bExplicitDevIdRequested;  

extern unsigned short                            EcatWdValue; 
 
 
extern    unsigned short                         nEscAddrOutputData;  
extern    unsigned short                         nEscAddrInputData;  






 
extern void EnableSyncManChannel(unsigned char channel);
extern void DisableSyncManChannel(unsigned char channel);
extern TSYNCMAN  *GetSyncMan(unsigned char channel);
extern void SetALStatus(unsigned char alStatus, unsigned short alStatusCode);
extern void AL_ControlInd(unsigned char alControl, unsigned short alStatusCode);
 
extern void DC_CheckWatchdog(void);
extern    void CheckIfEcatError(void);
extern void ECAT_Init(void);

extern void ECAT_Main(void);


 
#line 45 "etherCAT\\applInterface.h"
#line 1 "etherCAT\\objdef.h"




 




 






















 





 
#line 1 "etherCAT\\sdoserv.h"




 




 



















 






 
#line 1 "etherCAT\\ecatcoe.h"




 




 












 





 
#line 1 "etherCAT\\mailbox.h"




 




 
















 





 
#line 35 "etherCAT\\mailbox.h"









 
#line 51 "etherCAT\\mailbox.h"

#line 60 "etherCAT\\mailbox.h"
















 





 
#line 92 "etherCAT\\mailbox.h"




 
typedef struct 
{
    unsigned short                          Length;  
    unsigned short                          Address;  

    unsigned short                          Flags[1];  
 
#line 110 "etherCAT\\mailbox.h"
 
}
TMBXHEADER;









 
typedef struct 
{
    TMBXHEADER                      MbxHeader;  
    unsigned short                          Data[((0x0100 - 6) >> 1)];  
}
TMBX;




 
typedef struct
{
    unsigned short    firstInQueue;  
    unsigned short    lastInQueue;  
    unsigned short    maxQueueSize;  
    TMBX  * queue[(10)+1];  
} TMBXQUEUE;










 






extern unsigned char                    bReceiveMbxIsLocked;  
extern unsigned char                    bSendMbxIsFull;  
extern unsigned char                    bMbxRunning;  
extern unsigned char                    bMbxRepeatToggle;  
extern unsigned short                  u16SendMbxSize;  
extern unsigned short                  u16ReceiveMbxSize;  
extern unsigned short                  u16EscAddrReceiveMbx;  
extern unsigned short                  u16EscAddrSendMbx;  
extern unsigned char                   u8MbxWriteCounter;  
extern unsigned char                   u8MbxReadCounter;  
 
extern unsigned char                   u8MailboxSendReqStored;  
extern TMBX  *           psWriteMbx;  
extern TMBX  *           psReadMbx;  
extern TMBX  *           psRepeatMbx;  
extern TMBX  *           psStoreMbx;  
 
extern TMBXQUEUE         sMbxSendQueue;  
extern TMBXQUEUE         sMbxReceiveQueue;  






 

extern   void     MBX_Init(void);
extern   unsigned short    MBX_StartMailboxHandler(void);
extern   void     MBX_StopMailboxHandler(void);
extern   void     MBX_MailboxWriteInd(TMBX  *pMbx);
extern   void     MBX_MailboxReadInd(void);
extern   void     MBX_MailboxRepeatReq(void);
extern   unsigned char    MBX_MailboxSendReq(TMBX  * pMbx, unsigned char flags);
extern   void     MBX_CheckAndCopyMailbox(void);
extern   unsigned char    MBX_CopyToSendMailbox(TMBX  *pMbx);
extern   void     MBX_Main(void);


 
#line 31 "etherCAT\\ecatcoe.h"








 



 






 
#line 59 "etherCAT\\ecatcoe.h"





 
 





typedef unsigned short TCOEHEADER;  




 
typedef struct 
{
  TMBXHEADER        MbxHeader;  
  TCOEHEADER        CoeHeader;  
  unsigned short            Data[(((0x0100 - 6))-(2)) >> 1];  
}
TCOEMBX;














 
extern    TMBX  *  pCoeSendStored;                



 





 

extern   void     COE_Init(void);
extern   unsigned char    COE_ServiceInd(TCOEMBX  *pCoeMbx);
extern   unsigned char     COE_ContinueInd(TMBX  * pMbx);


 
#line 39 "etherCAT\\sdoserv.h"









 




 



 





 
#line 74 "etherCAT\\sdoserv.h"
 





 
#line 90 "etherCAT\\sdoserv.h"
 





 


 
typedef struct 
{
    unsigned short Sdo[2];  
 
#line 115 "etherCAT\\sdoserv.h"
 
}
TINITSDOHEADER;







 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TINITSDOHEADER        SdoHeader;  
}
TINITSDOMBX;






 
 









 
typedef struct 
{
    unsigned short      SegHeader;  
 
#line 165 "etherCAT\\sdoserv.h"
    unsigned short      Data[((((0x0100 - 6))-(( 2 + 1 )) - 1 ) >> 1)];   
 
}
TSDOSEGHEADERDATA;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TINITSDOHEADER        SdoHeader;  
  unsigned short                Data[(4) >> 1];  
}
TINITSDODOWNLOADEXPREQMBX;



 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TINITSDOHEADER        SdoHeader;  
  unsigned short                CompleteSize[2];  
  unsigned short                Data[((((0x0100 - 6))-(( 2 + 4 + 4 ))) >> 1)];  
}
TINITSDODOWNLOADNORMREQMBX;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TINITSDOHEADER        SdoHeader;  
}
TINITSDODOWNLOADRESMBX;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TSDOSEGHEADERDATA     SdoHeader;  
}
TDOWNLOADSDOSEGREQMBX;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  unsigned char                 SegHeader;  
}
TDOWNLOADSDOSEGRESMBX;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TINITSDOHEADER        SdoHeader;  
}
TINITSDOUPLOADREQMBX;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TINITSDOHEADER        SdoHeader;  
  unsigned short                Data[((4) >> 1)];  
}
TINITSDOUPLOADEXPRESMBX;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TINITSDOHEADER        SdoHeader;  
  unsigned short                CompleteSize[2];  
  unsigned short                Data[((((0x0100 - 6))-(( 2 + 4 + 4 ))) >> 1)];  
}
TINITSDOUPLOADNORMRESMBX;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  unsigned char                 SegHeader;  
}
TUPLOADSDOSEGREQMBX;



 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TSDOSEGHEADERDATA     SdoHeader;  
}
TUPLOADSDOSEGRESMBX;




 
typedef struct 
{
  TMBXHEADER            MbxHeader;  
  TCOEHEADER            CoeHeader;  
  TINITSDOHEADER        SdoHeader;  
  unsigned int             AbortCode;  
}
TABORTSDOTRANSFERREQMBX;



 





 
#line 346 "etherCAT\\sdoserv.h"






 
#line 383 "etherCAT\\sdoserv.h"
 
 





 
#line 399 "etherCAT\\sdoserv.h"
 





 


 
typedef struct 
{
    unsigned short                ListType;  
#line 419 "etherCAT\\sdoserv.h"
}
TSDOINFOLIST;




 
typedef struct 
{
    unsigned short            DataType;  
    unsigned short            ObjFlags;  

     










}
TSDOINFOOBJDESC;







 
typedef struct 
{
    unsigned short            Index;  
    TSDOINFOOBJDESC   Res;  
}
TSDOINFOOBJ;







 
typedef struct 
{
    unsigned short                DataType;  
    unsigned short                BitLength;  
    unsigned short                ObjAccess;  
                                     









 

#line 500 "etherCAT\\sdoserv.h"
}
TSDOINFOENTRYDESC;




 
typedef struct 
{
    unsigned short                Index;  
    unsigned short                 Info;  
 





    TSDOINFOENTRYDESC    Res;  
}
TSDOINFOENTRY;




 
typedef struct 
{
    unsigned int                ErrorCode;  
}
TSDOINFOERROR;







 
typedef struct 
{
    unsigned short InfoHead;  
 





    unsigned short                FragmentsLeft;  

    union 
    {
        TSDOINFOLIST    List; 
        TSDOINFOOBJ     Obj; 
        TSDOINFOENTRY   Entry; 
        TSDOINFOERROR   Error; 
        unsigned short          Data[1]; 
    }
    Data; 

}
TSDOINFOHEADER;




 
typedef struct 
{
  TMBXHEADER        MbxHeader;  
  TCOEHEADER        CoeHeader;  
  TSDOINFOHEADER    SdoHeader;  
}
TSDOINFORMATION;


#line 584 "etherCAT\\sdoserv.h"



 







 




 








 









 
extern unsigned char         u8PendingSdo;  
extern unsigned char          bStoreCompleteAccess;  
extern unsigned char         u8StoreSubindex;  
extern unsigned short        u16StoreIndex;  
extern unsigned int        u32StoreDataSize;  
extern unsigned short  *pStoreData;  
extern unsigned char (* pSdoPendFunc)( unsigned short Index, unsigned char Subindex, unsigned int Size, unsigned short  * pData, unsigned char bCompleteAccess );  
 


extern unsigned char                      aSdoInfoHeader[(((((( (6) + (2) + (4) ))+(2)))+3) >> 2)];  





 
extern unsigned short  *                 pSdoSegData;  
extern unsigned short                          nSdoInfoFragmentsLeft;  
 






 
extern    unsigned char SDOS_SdoInfoInd(TSDOINFORMATION  *pSdoInfoInd);
extern    unsigned char SDOS_SdoInd(TINITSDOMBX  *pSdoInd);

extern    void  SDOS_SdoRes(unsigned char abort, unsigned int objLength, unsigned short  *pData);
extern    void  SDOS_ClearPendingResponse(void);



 
#line 41 "etherCAT\\objdef.h"










 



 
#line 120 "etherCAT\\objdef.h"




 

#line 136 "etherCAT\\objdef.h"









 
typedef struct OBJ_ENTRY
{
    struct OBJ_ENTRY                      *pPrev;  
    struct OBJ_ENTRY                      *pNext;  

    unsigned short                                Index;  
    TSDOINFOOBJDESC                       ObjDesc;  
    const TSDOINFOENTRYDESC      *pEntryDesc;  
    const unsigned char                  *pName;  
    void                            *pVarPtr;  
    unsigned char (* Read)( unsigned short Index, unsigned char Subindex, unsigned int Size, unsigned short  * pData, unsigned char bCompleteAccess );  
    unsigned char (* Write)( unsigned short Index, unsigned char Subindex, unsigned int Size, unsigned short  * pData, unsigned char bCompleteAccess );  
    unsigned short                                 NonVolatileOffset;  
}
TOBJECT;




 
typedef struct 
{
    unsigned short    subindex0; 
    unsigned short    u16SyncType;  
    unsigned int    u32CycleTime; 
    unsigned int    u32Subindex003; 
    unsigned short    u16SyncTypesSupported; 
    unsigned int    u32MinCycleTime; 
    unsigned int    u32CalcAndCopyTime; 
    unsigned int    u32Si7Reserved; 
    unsigned short    u16GetCycleTime; 
    unsigned int    u32DelayTime;  
    unsigned int    u32Sync0CycleTime;  
    unsigned short    u16SmEventMissedCounter;  
    unsigned short    u16CycleExceededCounter;  
    unsigned short    u16ShiftTooShort;  
    unsigned short    u16Si14Reserved;  
    unsigned int    u32Si15Reserved;  
    unsigned int    u32Si16Reserved;  
    unsigned int    u32Si17Reserved;  
    unsigned int    u32Si18Reserved;  
    unsigned char    u8SyncError;  
}
TSYNCMANPAR;



 
typedef struct 
{
    unsigned short    syncFailedCounter;  
}
TCYCLEDIAG;




 
typedef struct  {
   unsigned short   u16SubIndex0;  
   unsigned int   u32LocalErrorReaction;  
   unsigned short   u16SyncErrorCounterLimit;  
} 
TOBJ10F1;








 









 
extern unsigned char bSyncSetByUser;



 
extern TCYCLEDIAG sCycleDiag;




 
extern TSYNCMANPAR  sSyncManOutPar;




 
extern TSYNCMANPAR  sSyncManInPar;








 
extern TOBJ10F1 sErrorSettings



;




 
extern    char          aSubindexDesc[13]



;






 

extern    const TOBJECT  *  OBJ_GetObjectHandle( unsigned short index );
extern    unsigned int  OBJ_GetObjectLength( unsigned short index, unsigned char subindex, const TOBJECT  * pObjEntry, unsigned char bCompleteAccess);
extern    unsigned short  OBJ_GetNoOfObjects(unsigned char listType);
extern    unsigned short  OBJ_GetObjectList(unsigned short listType, unsigned short *pIndex, unsigned short size, unsigned short  *pData,unsigned char *pAbort);
extern    unsigned short  OBJ_GetDesc( unsigned short index, unsigned char subindex, const TOBJECT  * pObjEntry, unsigned short  * pData );
extern    const TSDOINFOENTRYDESC  * OBJ_GetEntryDesc(const TOBJECT  * pObjEntry, unsigned char Subindex);
extern    const TSDOINFOOBJDESC  * OBJ_GetObjDesc(const TOBJECT  * pObjEntry);
extern    unsigned short  OBJ_GetEntryOffset(unsigned char subindex, const TOBJECT  * pObjEntry);
extern    unsigned char   CheckSyncTypeValue(unsigned short index, unsigned short NewSyncType);
extern    unsigned char   OBJ_Read(unsigned short index, unsigned char subindex, unsigned int objSize, const TOBJECT  * pObjEntry, unsigned short  * pData, unsigned char bCompleteAccess);
extern    unsigned char   OBJ_Write(unsigned short index, unsigned char subindex, unsigned int dataSize, const TOBJECT  * pObjEntry, unsigned short  * pData, unsigned char bCompleteAccess);
extern    void    COE_WriteBackupEntry(unsigned char subindex, const TOBJECT  * pObjEntry);


 
#line 46 "etherCAT\\applInterface.h"
#line 1 "etherCAT\\ecatappl.h"




 




 



















 








 





 

#line 48 "etherCAT\\ecatappl.h"









 

 
#line 85 "etherCAT\\ecatappl.h"
 














 


 

extern unsigned char bEcatWaitForInputUpdate;  
extern unsigned char bEtherCATRunLed;  
extern unsigned char bEtherCATErrorLed;  
extern unsigned char bRunApplication;  



 




 




extern    void       ECAT_CheckTimer(void);
extern    void       PDI_Isr(void);
extern    void       Sync0_Isr(void);
extern    void       Sync1_Isr(void);
extern    void       ECAT_Application(void);
extern    void       PDO_ResetOutputs(void);
extern    void       PDO_ReadInputs(void);
extern    void       PDO_InputMapping(void);

 
extern    void       CalcSMCycleTime(void);
extern    unsigned short     ESC_EepromAccess(unsigned int wordaddress, unsigned short wordsize, unsigned short  *pData, unsigned char access);
extern    unsigned short     ESC_EepromWriteCRC(void);

 




 
#line 47 "etherCAT\\applInterface.h"

 


 

#line 1 "etherCAT\\foeappl.h"




 




 











 





 
#line 30 "etherCAT\\foeappl.h"








 


 
#line 59 "etherCAT\\foeappl.h"














 






 
extern    unsigned short     FOE_Read(unsigned short  * pName, unsigned short nameSize, unsigned short  * pData, unsigned int password);
extern    unsigned short     FOE_Write(unsigned short  * pName, unsigned short nameSize, unsigned int password);
extern    unsigned short     FOE_Data(unsigned short  * pData, unsigned short Size);
extern    unsigned short     FOE_Ack(unsigned int fileOffset, unsigned short  * pData);
extern    unsigned short     FOE_Busy(unsigned short done, unsigned int fileOffset, unsigned short  * pData);
extern    void       FOE_Error(unsigned int errorCode);


 
#line 54 "etherCAT\\applInterface.h"













 

 


 































 
extern unsigned short (*pAPPL_FoeRead)(unsigned short  * pName, unsigned short nameSize, unsigned int password, unsigned short maxBlockSize, unsigned short *pData);




























 
extern unsigned short(*pAPPL_FoeReadData)(unsigned int offset, unsigned short maxBlockSize, unsigned short *pData);









 
extern void(*pAPPL_FoeError)(unsigned int errorCode);






















 
extern unsigned short (*pAPPL_FoeWrite)(unsigned short  * pName, unsigned short nameSize, unsigned int password);




















 
extern unsigned short(*pAPPL_FoeWriteData)(unsigned short  * pData, unsigned short Size, unsigned char bDataFollowing);

 







 
extern void(*pAPPL_CoeReadInd)(unsigned short Index, unsigned char Subindex, unsigned char CompleteAccess);








 
extern void(*pAPPL_CoeWriteInd)(unsigned short Index, unsigned char Subindex, unsigned char CompleteAccess);

 




 
extern void(*pAPPL_MainLoop)();





 









 
extern unsigned short MainInit(void);








 
extern void MainLoop(void);











 
extern void ECAT_StateChange(unsigned char alStatus, unsigned short alStatusCode);


 

#line 27 "etherCAT\\Robot-Device.c"

#line 1 "etherCAT\\Robot-Device.h"



 




 






 

 








 
#line 29 "etherCAT\\Robot-Device.h"

#line 1 "etherCAT\\ecatappl.h"




 




 



















 








 





 

#line 48 "etherCAT\\ecatappl.h"


#line 87 "etherCAT\\ecatappl.h"













 


 

extern unsigned char bEcatWaitForInputUpdate;  
extern unsigned char bEtherCATRunLed;  
extern unsigned char bEtherCATErrorLed;  
extern unsigned char bRunApplication;  



 




 




extern    void       ECAT_CheckTimer(void);
extern    void       PDI_Isr(void);
extern    void       Sync0_Isr(void);
extern    void       Sync1_Isr(void);
extern    void       ECAT_Application(void);
extern    void       PDO_ResetOutputs(void);
extern    void       PDO_ReadInputs(void);
extern    void       PDO_InputMapping(void);

 
extern    void       CalcSMCycleTime(void);
extern    unsigned short     ESC_EepromAccess(unsigned int wordaddress, unsigned short wordsize, unsigned short  *pData, unsigned char access);
extern    unsigned short     ESC_EepromWriteCRC(void);

 




 
#line 31 "etherCAT\\Robot-Device.h"





 




#line 1 "etherCAT\\Robot-DeviceObjects.h"



 




 







 








 




 
#line 241 "etherCAT\\Robot-DeviceObjects.h"




 
typedef struct  {
unsigned short u16SubIndex0;
unsigned int SI1;  
unsigned int SI2;  
unsigned int SI3;  
unsigned int SI4;  
unsigned int SI5;  
unsigned int SI6;  
unsigned int SI7;  
unsigned int SI8;  
unsigned int SI9;  
unsigned int SI10;  
unsigned int SI11;  
unsigned int SI12;  
unsigned int SI13;  
unsigned int SI14;  
unsigned int SI15;  
unsigned int SI16;  
unsigned int SI17;  
unsigned int SI18;  
unsigned int SI19;  
unsigned int SI20;  
unsigned int SI21;  
unsigned int SI22;  
unsigned int SI23;  
unsigned int SI24;  
unsigned int SI25;  
unsigned int SI26;  
unsigned int SI27;  
unsigned int SI28;  
unsigned int SI29;  
unsigned int SI30;  
unsigned int SI31;  
unsigned int SI32;  
unsigned int SI33;  
unsigned int SI34;  
unsigned int SI35;  
unsigned int SI36;  
unsigned int SI37;  
unsigned int SI38;  
unsigned int SI39;  
unsigned int SI40;  
unsigned int SI41;  
unsigned int SI42;  
unsigned int SI43;  
unsigned int SI44;  
unsigned int SI45;  
unsigned int SI46;  
unsigned int SI47;  
unsigned int SI48;  
unsigned int SI49;  
unsigned int SI50;  
unsigned int SI51;  
unsigned int SI52;  
unsigned int SI53;  
unsigned int SI54;  
unsigned int SI55;  
unsigned int SI56;  
unsigned int SI57;  
unsigned int SI58;  
unsigned int SI59;  
unsigned int SI60;  
unsigned int SI61;  
unsigned int SI62;  
unsigned int SI63;  
unsigned int SI64;  
unsigned int SI65;  
} 
TOBJ1600;




 
 TOBJ1600 OUT_GENERICProcessDataMapping0x1600

={65,0x70000101,0x70000201,0x70000301,0x70000401,0x70000501,0x70000601,0x70000701,0x70000801,0x70000901,0x70000A01,0x70000B01,0x70000C01,0x70000D01,0x70000E01,0x70000F01,0x70001001,0x70001110,0x70001210,0x70001308,0x70001408,0x70001508,0x70001608,0x70001708,0x70001808,0x70001908,0x70001A08,0x70001B08,0x70001C08,0x70001D08,0x70001E08,0x70001F08,0x70002008,0x70002108,0x70002208,0x70002308,0x70002408,0x70002508,0x70002608,0x70002708,0x70002808,0x70002908,0x70002A08,0x70002B08,0x70002C08,0x70002D08,0x70002E08,0x70002F08,0x70003008,0x70003108,0x70003208,0x70003310,0x70003410,0x70003510,0x70003608,0x70003708,0x70003808,0x70003908,0x70003A08,0x70003B08,0x70003C08,0x70003D08,0x70003E10,0x70003F10,0x70004010,0x70004110}

;
 





 




 
#line 555 "etherCAT\\Robot-DeviceObjects.h"




 
typedef struct  {
unsigned short u16SubIndex0;
unsigned int SI1;  
unsigned int SI2;  
unsigned int SI3;  
unsigned int SI4;  
unsigned int SI5;  
unsigned int SI6;  
unsigned int SI7;  
unsigned int SI8;  
unsigned int SI9;  
unsigned int SI10;  
unsigned int SI11;  
unsigned int SI12;  
unsigned int SI13;  
unsigned int SI14;  
unsigned int SI15;  
unsigned int SI16;  
unsigned int SI17;  
unsigned int SI18;  
unsigned int SI19;  
unsigned int SI20;  
unsigned int SI21;  
unsigned int SI22;  
unsigned int SI23;  
unsigned int SI24;  
unsigned int SI25;  
unsigned int SI26;  
unsigned int SI27;  
unsigned int SI28;  
unsigned int SI29;  
unsigned int SI30;  
unsigned int SI31;  
unsigned int SI32;  
unsigned int SI33;  
unsigned int SI34;  
unsigned int SI35;  
unsigned int SI36;  
unsigned int SI37;  
unsigned int SI38;  
unsigned int SI39;  
unsigned int SI40;  
unsigned int SI41;  
unsigned int SI42;  
unsigned int SI43;  
unsigned int SI44;  
unsigned int SI45;  
unsigned int SI46;  
unsigned int SI47;  
unsigned int SI48;  
unsigned int SI49;  
unsigned int SI50;  
unsigned int SI51;  
unsigned int SI52;  
unsigned int SI53;  
unsigned int SI54;  
unsigned int SI55;  
unsigned int SI56;  
unsigned int SI57;  
unsigned int SI58;  
unsigned int SI59;  
unsigned int SI60;  
unsigned int SI61;  
unsigned int SI62;  
unsigned int SI63;  
unsigned int SI64;  
unsigned int SI65;  
unsigned int SI66;  
unsigned int SI67;  
unsigned int SI68;  
} 
TOBJ1A00;




 
 TOBJ1A00 IN_GENERICProcessDataMapping0x1A00

={68,0x60000101,0x60000201,0x60000301,0x60000401,0x60000501,0x60000601,0x60000701,0x60000801,0x60000901,0x60000A01,0x60000B01,0x60000C01,0x60000D01,0x60000E01,0x60000F01,0x60001001,0x60001110,0x60001210,0x60001310,0x60001410,0x60001510,0x60001610,0x60001708,0x60001808,0x60001908,0x60001A08,0x60001B08,0x60001C08,0x60001D08,0x60001E08,0x60001F08,0x60002008,0x60002108,0x60002208,0x60002308,0x60002408,0x60002508,0x60002608,0x60002708,0x60002808,0x60002908,0x60002A08,0x60002B08,0x60002C08,0x60002D08,0x60002E08,0x60002F08,0x60003008,0x60003108,0x60003208,0x60003308,0x60003408,0x60003508,0x60003608,0x60003710,0x60003810,0x60003910,0x60003A08,0x60003B08,0x60003C08,0x60003D08,0x60003E08,0x60003F08,0x60004008,0x60004108,0x60004210,0x60004320,0x60004410}

;
 





 




 
#line 671 "etherCAT\\Robot-DeviceObjects.h"




 
typedef struct  {
unsigned short   u16SubIndex0;   
unsigned short aEntries[1];   
} 
TOBJ1C12;




 
 TOBJ1C12 sRxPDOassign

={1,{0x1600}}

;
 





 




 
#line 720 "etherCAT\\Robot-DeviceObjects.h"




 
typedef struct  {
unsigned short   u16SubIndex0;   
unsigned short aEntries[1];   
} 
TOBJ1C13;




 
 TOBJ1C13 sTxPDOassign

={1,{0x1A00}}

;
 





 




 
#line 970 "etherCAT\\Robot-DeviceObjects.h"




 
typedef struct  {
unsigned short u16SubIndex0;
unsigned short Digital_Inputs_channel1:1;  
unsigned short Digital_Inputs_channel2:1;  
unsigned short Digital_Inputs_channel3:1;  
unsigned short Digital_Inputs_channel4:1;  
unsigned short Digital_Inputs_channel5:1;  
unsigned short Digital_Inputs_channel6:1;  
unsigned short Digital_Inputs_channel7:1;  
unsigned short Digital_Inputs_channel8:1;  
unsigned short Digital_Inputs_channel9:1;  
unsigned short Digital_Inputs_channel10:1;  
unsigned short Digital_Inputs_channel11:1;  
unsigned short Digital_Inputs_channel12:1;  
unsigned short Digital_Inputs_channel13:1;  
unsigned short Digital_Inputs_channel14:1;  
unsigned short Digital_Inputs_channel15:1;  
unsigned short Digital_Inputs_channel16:1;  
unsigned short Analog_Voltage_Inputs_channel1;  
unsigned short Analog_Voltage_Inputs_channel2;  
unsigned short Analog_Current_Inputs_channel1;  
unsigned short Analog_Current_Inputs_channel2;  
unsigned short RS485_Inputs_Count;  
unsigned short RS485_Inputs_Len;  
unsigned char RS485_Inputs_Data_In_1;  
unsigned char RS485_Inputs_Data_In_2;  
unsigned char RS485_Inputs_Data_In_3;  
unsigned char RS485_Inputs_Data_In_4;  
unsigned char RS485_Inputs_Data_In_5;  
unsigned char RS485_Inputs_Data_In_6;  
unsigned char RS485_Inputs_Data_In_7;  
unsigned char RS485_Inputs_Data_In_8;  
unsigned char RS485_Inputs_Data_In_9;  
unsigned char RS485_Inputs_Data_In_10;  
unsigned char RS485_Inputs_Data_In_11;  
unsigned char RS485_Inputs_Data_In_12;  
unsigned char RS485_Inputs_Data_In_13;  
unsigned char RS485_Inputs_Data_In_14;  
unsigned char RS485_Inputs_Data_In_15;  
unsigned char RS485_Inputs_Data_In_16;  
unsigned char RS485_Inputs_Data_In_17;  
unsigned char RS485_Inputs_Data_In_18;  
unsigned char RS485_Inputs_Data_In_19;  
unsigned char RS485_Inputs_Data_In_20;  
unsigned char RS485_Inputs_Data_In_21;  
unsigned char RS485_Inputs_Data_In_22;  
unsigned char RS485_Inputs_Data_In_23;  
unsigned char RS485_Inputs_Data_In_24;  
unsigned char RS485_Inputs_Data_In_25;  
unsigned char RS485_Inputs_Data_In_26;  
unsigned char RS485_Inputs_Data_In_27;  
unsigned char RS485_Inputs_Data_In_28;  
unsigned char RS485_Inputs_Data_In_29;  
unsigned char RS485_Inputs_Data_In_30;  
unsigned char RS485_Inputs_Data_In_31;  
unsigned char RS485_Inputs_Data_In_32;  
unsigned short CAN_RX_Change_Count;  
unsigned short CAN_RX_ID;  
unsigned short CAN_RX_LEN;  
unsigned char CANInputsDataIn1;  
unsigned char CANInputsDataIn2;  
unsigned char CANInputsDataIn3;  
unsigned char CANInputsDataIn4;  
unsigned char CANInputsDataIn5;  
unsigned char CANInputsDataIn6;  
unsigned char CANInputsDataIn7;  
unsigned char CANInputsDataIn8;  
unsigned short ErrorCode;  
int INC_AB_CNT;  
unsigned short Board_Temperature;  
} 
TOBJ6000;




 
 TOBJ6000 IN_GENERIC0x6000

={68,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x00000000,0x0000}

;
 





 




 
#line 1278 "etherCAT\\Robot-DeviceObjects.h"




 
typedef struct  {
unsigned short u16SubIndex0;
unsigned short Digital_Outputs_channel_1:1;  
unsigned short Digital_Outputs_channel_2:1;  
unsigned short Digital_Outputs_channel_3:1;  
unsigned short Digital_Outputs_channel_4:1;  
unsigned short Digital_Outputs_channel_5:1;  
unsigned short Digital_Outputs_channel_6:1;  
unsigned short Digital_Outputs_channel_7:1;  
unsigned short Digital_Outputs_channel_8:1;  
unsigned short Digital_Outputs_channel_9:1;  
unsigned short Digital_Outputs_channel_10:1;  
unsigned short Digital_Outputs_channel_11:1;  
unsigned short Digital_Outputs_channel_12:1;  
unsigned short Digital_Outputs_channel_13:1;  
unsigned short Digital_Outputs_channel_14:1;  
unsigned short Digital_Outputs_channel_15:1;  
unsigned short Digital_Outputs_channel_16:1;  
unsigned short RS485_Outputs_Count;  
unsigned short RS485_Outputs_Len;  
unsigned char RS485_Outputs_Data_Out_1;  
unsigned char RS485_Outputs_Data_Out_2;  
unsigned char RS485_Outputs_Data_Out_3;  
unsigned char RS485_Outputs_Data_Out_4;  
unsigned char RS485_Outputs_Data_Out_5;  
unsigned char RS485_Outputs_Data_Out_6;  
unsigned char RS485_Outputs_Data_Out_7;  
unsigned char RS485_Outputs_Data_Out_8;  
unsigned char RS485_Outputs_Data_Out_9;  
unsigned char RS485_Outputs_Data_Out_10;  
unsigned char RS485_Outputs_Data_Out_11;  
unsigned char RS485_Outputs_Data_Out_12;  
unsigned char RS485_Outputs_Data_Out_13;  
unsigned char RS485_Outputs_Data_Out_14;  
unsigned char RS485_Outputs_Data_Out_15;  
unsigned char RS485_Outputs_Data_Out_16;  
unsigned char RS485_Outputs_Data_Out_17;  
unsigned char RS485_Outputs_Data_Out_18;  
unsigned char RS485_Outputs_Data_Out_19;  
unsigned char RS485_Outputs_Data_Out_20;  
unsigned char RS485_Outputs_Data_Out_21;  
unsigned char RS485_Outputs_Data_Out_22;  
unsigned char RS485_Outputs_Data_Out_23;  
unsigned char RS485_Outputs_Data_Out_24;  
unsigned char RS485_Outputs_Data_Out_25;  
unsigned char RS485_Outputs_Data_Out_26;  
unsigned char RS485_Outputs_Data_Out_27;  
unsigned char RS485_Outputs_Data_Out_28;  
unsigned char RS485_Outputs_Data_Out_29;  
unsigned char RS485_Outputs_Data_Out_30;  
unsigned char RS485_Outputs_Data_Out_31;  
unsigned char RS485_Outputs_Data_Out_32;  
unsigned short CAN_TX_Change_Count;  
unsigned short CAN_TX_ID;  
unsigned short CAN_TX_LEN;  
unsigned char CANOutputsDataOut1;  
unsigned char CANOutputsDataOut2;  
unsigned char CANOutputsDataOut3;  
unsigned char CANOutputsDataOut4;  
unsigned char CANOutputsDataOut5;  
unsigned char CANOutputsDataOut6;  
unsigned char CANOutputsDataOut7;  
unsigned char CANOutputsDataOut8;  
unsigned short Analog_Voltage_Output_Channel1;  
unsigned short Analog_Voltage_Output_Channel2;  
unsigned short Analog_Current_Output_Channel1;  
unsigned short Analog_Current_Output_Channel2;  
} 
TOBJ7000;




 
 TOBJ7000 OUT_GENERIC0x7000

={65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x0000,0x0000,0x0000}

;
 





 




 
#line 1448 "etherCAT\\Robot-DeviceObjects.h"




 
typedef struct  {
unsigned short u16SubIndex0;
unsigned int RS485_Baudrate;  
unsigned int CAN_Baudrate;  
unsigned short MotEncPerRotate;  
unsigned short Analog_Input_Switch_Channel1;  
unsigned short Analog_Input_Switch_Channel2;  
unsigned short Analog_Output_Switch_Channel1;  
unsigned short Analog_Output_Switch_Channel2;  
unsigned short Over_Voltage_48V;  
unsigned short Under_Voltage_48V;  
unsigned short Over_Current_48V;  
unsigned short Over_Voltage_24V;  
unsigned short Under_Voltage_24V;  
unsigned short Over_Current_24V;  
unsigned short Over_Temperature;  
unsigned short Res_Over_heat;  
unsigned short Consecutive_Failure_CNT;  
unsigned short Test_Mode;  
unsigned short Delay_Time;  
unsigned short Restart_Time;  
unsigned short Complete_Flag;  
} 
TOBJ8000;




 
 TOBJ8000 ParameterConfiguration0x8000

={20,0x0001C200,0x000001F4,0x07D0,0x0000,0x0000,0x0000,0x0000,0x004B,0x0006,0x0028,0x003C,0x0004,0x0000,0x0055,0x07D0,0x0005,0x0000,0x1388,0x03E8,0x0000}

;
 





 




 
#line 1519 "etherCAT\\Robot-DeviceObjects.h"




 
typedef struct  {
unsigned short u16SubIndex0;
unsigned short IndexDistance;  
unsigned short MaximumNumberOfModules;  
} 
TOBJF000;




 
 TOBJF000 ModularDeviceProfile0xF000

={2,0x0010,0}

;
 







#line 1568 "etherCAT\\Robot-DeviceObjects.h"



 
#line 42 "etherCAT\\Robot-Device.h"









 void APPL_Application(void);

 unsigned short APPL_GetDeviceID(void);


 void   APPL_AckErrorInd(unsigned short stateTrans);
 unsigned short APPL_StartMailboxHandler(void);
 unsigned short APPL_StopMailboxHandler(void);
 unsigned short APPL_StartInputHandler(unsigned short *pIntMask);
 unsigned short APPL_StopInputHandler(void);
 unsigned short APPL_StartOutputHandler(void);
 unsigned short APPL_StopOutputHandler(void);

 unsigned short APPL_GenerateMapping(unsigned short *pInputSize,unsigned short *pOutputSize);
 void APPL_InputMapping(unsigned short* pData);
 void APPL_OutputMapping(unsigned short* pData);


 

#line 30 "etherCAT\\Robot-Device.c"





 





 





 





 





 

void    APPL_AckErrorInd(unsigned short stateTrans)
{

}













 

unsigned short APPL_StartMailboxHandler(void)
{
    return 0x0000;
}










 

unsigned short APPL_StopMailboxHandler(void)
{
    return 0x0000;
}















 

unsigned short APPL_StartInputHandler(unsigned short *pIntMask)
{
    return 0x0000;
}










 

unsigned short APPL_StopInputHandler(void)
{
    return 0x0000;
}












 

unsigned short APPL_StartOutputHandler(void)
{
    return 0x0000;
}










 

unsigned short APPL_StopOutputHandler(void)
{
    return 0x0000;
}









 
unsigned short APPL_GenerateMapping(unsigned short *pInputSize,unsigned short *pOutputSize)
{
    unsigned short result = 0x0000;
    unsigned short InputSize = 0;
    unsigned short OutputSize = 0;


    unsigned short PDOAssignEntryCnt = 0;
    const TOBJECT  * pPDO = 0;
    unsigned short PDOSubindex0 = 0;
    unsigned int *pPDOEntry = 0;
    unsigned short PDOEntryCnt = 0;
   

     
    for(PDOAssignEntryCnt = 0; PDOAssignEntryCnt < sRxPDOassign.u16SubIndex0; PDOAssignEntryCnt++)
    {
        pPDO = OBJ_GetObjectHandle(sRxPDOassign.aEntries[PDOAssignEntryCnt]);
        if(pPDO != 0)
        {
            PDOSubindex0 = *((unsigned short *)pPDO->pVarPtr);
            for(PDOEntryCnt = 0; PDOEntryCnt < PDOSubindex0; PDOEntryCnt++)
            {
                pPDOEntry = (unsigned int *)(((unsigned short *)pPDO->pVarPtr) + (OBJ_GetEntryOffset((PDOEntryCnt+1),pPDO)>>4));    
                
                OutputSize += (unsigned short) ((*pPDOEntry) & 0xFF);
            }
        }
        else
        {
             
            OutputSize = 0;
            result = 0x0025;
            break;
        }
    }

    OutputSize = (OutputSize + 7) >> 3;



    if(result == 0)
    {
         
        for(PDOAssignEntryCnt = 0; PDOAssignEntryCnt < sTxPDOassign.u16SubIndex0; PDOAssignEntryCnt++)
        {
            pPDO = OBJ_GetObjectHandle(sTxPDOassign.aEntries[PDOAssignEntryCnt]);
            if(pPDO != 0)
            {
                PDOSubindex0 = *((unsigned short *)pPDO->pVarPtr);
                for(PDOEntryCnt = 0; PDOEntryCnt < PDOSubindex0; PDOEntryCnt++)
                {
                    pPDOEntry = (unsigned int *)(((unsigned short *)pPDO->pVarPtr) + (OBJ_GetEntryOffset((PDOEntryCnt+1),pPDO)>>4));    
                    
                    InputSize += (unsigned short) ((*pPDOEntry) & 0xFF);
                }
            }
            else
            {
                 
                InputSize = 0;
                result = 0x0024;
                break;
            }
        }
    }
    InputSize = (InputSize + 7) >> 3;


#line 257 "etherCAT\\Robot-Device.c"

    *pInputSize = InputSize;
    *pOutputSize = OutputSize;
    return result;
}







 
void APPL_InputMapping(unsigned short* pData)
{





		memcpy((unsigned char*)pData,(unsigned char*)&IN_GENERIC0x6000 + 2,sizeof(IN_GENERIC0x6000) - 2);
}







 
void APPL_OutputMapping(unsigned short* pData)
{





		memcpy((unsigned char*)&OUT_GENERIC0x7000 + 2,(unsigned char*)pData,sizeof(OUT_GENERIC0x7000) - 2);
}





 
void APPL_Application(void)
{





}







 
unsigned short APPL_GetDeviceID()
{





     
    return 0x5;
}


#line 377 "etherCAT\\Robot-Device.c"
 

