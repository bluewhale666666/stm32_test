#include "hw_readwrite.h" 
#include "ad_da_spi.h"
#include "delay.h"	   

#include "stm32f4xx.h" 
#include "sys.h"	 

#include "timer.h"	
#include "do_led.h"
#include "di_key.h"
#include "rs485.h"
#include "exti.h"
#include "ecat_def.h"
#include "ecatslv.h"
#include "ecatappl.h"
#include "CAN_DATA.h"
#include "stmflash.h"

#include "gpio.h"
#include "usart.h"
#include "Boot_Initial.h"
#include "ads1115a.h"
#include "ads1115b.h"
#include "ads1115c.h"


#define FPU_EXCEPTION_MASK 0x0000009F
#define    __HW_READWRITE_ 1
#include "hw_readwrite.h"
#undef    __HW_READWRITE_
extern u8 Flag_485Rx;

#define    FLASH_SAVE_ADDR_baud                0X080E0000

/*--------------------------------------------------------------------------------------
------
------    internal Types and Defines
------
--------------------------------------------------------------------------------------*/

typedef union
{
    unsigned short    Word;
    unsigned char    Byte[2];
} UBYTETOWORD;

typedef union 
{
    UINT8           Byte[2];
    UINT16          Word;
}
UALEVENT;

BOOL AD8028WorkWell=0;
BOOL DA5306WorkWell=0;
///*----------------------------------------------------------------------------------------
//------
//------ For ADC&DAC&U485 data 注意了，这个UALEVENT是内部的结构定义，将其结构封装在函数体内供其它文件调用的
//------
//-----------------------------------------------------------------------------------------*/
UALEVENT AD8028[12];//
u8 Ecat_Work_Well_add=0;
u32 SDO_Work_Well_add =0;
//#define    FLASH_SAVE_ADDR                0X080E0000
///*-----------------------------------------------------------------------------------------
//------
//------    SPI defines/macros
//------
//-----------------------------------------------------------------------------------------*/

#define SPI1_STAT_VALUE                    0x8000
#define SPI1_CON1_VALUE                    0x027E
#define SPI1_CON1_VALUE_16BIT              0x047E



/*-----------------------------------------------------------------------------------------
------
------    Global Interrupt setting全局中断的开关在这里定义了宏 中断那边还要配置一下
------
-----------------------------------------------------------------------------------------*/

#define    DISABLE_GLOBAL_INT             INTX_DISABLE() //全局中断关闭，这个函数用的是sys里面的汇编代码，不过这个宏定义没有用到，直接用的INTX
#define    ENABLE_GLOBAL_INT              INTX_ENABLE()   
#define    DISABLE_AL_EVENT_INT           DISABLE_GLOBAL_INT
#define    ENABLE_AL_EVENT_INT            ENABLE_GLOBAL_INT


/*-----------------------------------------------------------------------------------------
------
------    ESC Interrupt 这是个外部中断，开启一下就行了
------
-----------------------------------------------------------------------------------------*/

//void EXTI0_Init(void);
//void EXTI1_Init(void);
//void EXTI2_Init(void);
//void EXTI3_Init(void);

#define    INIT_ESC_INT                EXTI0_Init() //中断线0 negative edge ; 最高优先级;highest priority
#define    ESC_INT_REQ                 EXTI_GetFlagStatus(EXTI_Line0)         //ESC Interrupt (INT0) state 看看中断线0上的状态位
                                          //ESC Interrupt input port ,这里这个管脚就是在中断线0上面，在中断初始化的时候就初始化过了
                                          //关于外部中断函数的响应，在EXTI里面找，包括对PDI数据的操作等等
//#define    ACK_ESC_INT                EXTI_ClearFlagStatus(EXTI_Line0) //就是清零中断标志位，实际上，直接清零就好了EXTI_Clear这个
 

/*-----------------------------------------------------------------------------------------
------
------    SYNC0 Interrupt  同步信号的中断 共有两路 跟STM32进行匹配
------
-----------------------------------------------------------------------------------------*/

#define    INIT_SYNC0_INT                    EXTI1_Init()         //  negative edge ;  //highest priority这跟上面ESC的初始化是一样的，就是初始化中断线1
#define    SYNC0_INT_REQ                     EXTI_GetFlagStatus(EXTI_Line1)//Sync1 Interrupt (INT2) state

#define    DISABLE_SYNC0_INT                EN_DISEN_EXTI( 0,1)//disable interrupt source INT1这个函数对于中断线的失能做了一个定义
#define    ENABLE_SYNC0_INT                 EN_DISEN_EXTI( 1,1) //enable interrupt source INT1中断线使能定义
//#define    ACK_SYNC0_INT                    {(SYNC0_INT_REQ) = 0;}
//#define    SET_SYNC0_INT                    {(SYNC0_INT_REQ) = 1;}//还可以对中断线标志位进行置位或者是清零，实际上中断标志位是不能够软件置位的，只能给硬件置位
#define    SYNC0_INT_PORT_IS_ACTIVE         ( EXTI_GetITStatus(EXTI_Line1)==1;)


#define    INIT_SYNC1_INT                    EXTI2_Init()                   //
#define    SYNC1_INT_REQ                    EXTI_GetFlagStatus(EXTI_Line2) //Sync1 Interrupt (INT3) state
                                                                         

#define    DISABLE_SYNC1_INT               EN_DISEN_EXTI( 0,2)//disable interrupt source INT3
#define    ENABLE_SYNC1_INT                EN_DISEN_EXTI( 1,2)//enable interrupt source INT3

//#define    ACK_SYNC1_INT                    {(SYNC1_INT_REQ) = 0;}
//#define    SET_SYNC1_INT                    {(SYNC1_INT_REQ) = 1;}
#define    SYNC1_INT_PORT_IS_ACTIVE       ( EXTI_GetITStatus(EXTI_Line2)==1;)//判断一下这个中断线的标志位


/*-----------------------------------------------------------------------------------------
------
------    Hardware timer 硬件定时器，设定一个定时器，不知道什么用
------
-----------------------------------------------------------------------------------------*/



//#define INIT_ECAT_TIMER                TIM3_Int_Init(100-1,8400-1)//对应1ms，他要求就是1ms
         

#define STOP_ECAT_TIMER                TIM_Cmd(TIM3,DISABLE)

#define START_ECAT_TIMER               TIM_Cmd(TIM3,ENABLE)



/*-----------------------------------------------------------------------------------------
------
------    Configuration Bits 配置晶振和一些使测试使能脚的，这部分分别在各硬件的初始化函数里面完成
------
-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------
------
------    LED defines 这个是定义LED灯的，对于ECAT来说，可以不去定义它
------
-----------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------
------
------    internal Variables
------
--------------------------------------------------------------------------------------*/
UALEVENT         EscALEvent;            //contains the content of the ALEvent register (0x220), this variable is updated on each Access to the Esc

/*--------------------------------------------------------------------------------------
------
------    internal functions
------
--------------------------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief  The function operates a SPI access without addressing.这是无地址访问的函数，这个函数用来确定中断寄存器的值

        The first two bytes of an access to the EtherCAT ASIC always deliver the AL_Event register (0x220).也就是说这个是不需要给地址，返回的就是这个值
        It will be saved in the global "EscALEvent"全局变量EscALEvent里面放的就是0x0220，实际上，0x0220这个寄存器保留了很多重要的值
		在一般操作的时候，一般都是要先读取这个0x220的值的，比如说这个值的bit0，置位时就说明AL CONTROL这个寄存器被写了，你必须接下来去读这个寄存器0x0120，bit0随后就会清零
		bit1，是同步时钟输入的中断信号，这个信号如果是置位了，那么就需要去读锁存时间，当然这个是在PDI控制锁存使能时才有用
		bit2,bit3是同步时钟信号的标志位，这两位是不是可用需要先设置0x0151.3和0x0151.7，然后就需要去读0x098E和0x098F寄存器了
		bit4，这个很重要，是说是否有sync_manager的变化，为什么说它重要，因为数据的传送最终的就是表现在sys_manager产生变化了，是激活状态，因为在不同的状态机里面，激活状态不同，
		有相应事件发生，然后又相应事件发生时读，8-23位，对应0-15，然后去读0x0806寄存器，获得更多信息
		第二个字节的数据主要是说到底是哪个sync_manager变化了
		所以说，为什么这个函数叫做中断寄存器，就是一些中断变化的信息在这个寄存器里面
*////////////////////////////////////////////////////////////////////////////////////////
static void GetInterruptRegister(void)
{
//	
//      GPIO_ResetBits(GPIOG,GPIO_Pin_4) ;  
//	    HW_EscReadIsr((UINT8*)&EscALEvent.Word,0x220,2);
//	    GPIO_SetBits(GPIOG,GPIO_Pin_4) ; 
	  UINT8        EscMbxReadEcatCtrl;

      INTX_DISABLE();                                                  //这里需要把其余的中断全部关掉
	
   	  GPIO_ResetBits(GPIOG,GPIO_Pin_4) ;                              //使能SPI器件，因为中断已经关闭了，所以在收发SPI数据的时候，不会被打断
	 
   	  delay_us(1);
    /* there have to be at least 15 ns after the PB14 signal was active (0) before
       the transmission shall be started，使能SPI之后应该有一定时间的延迟,这里我直接延迟1us */
	
    /* write to SPI1_BUF register starts the SPI access，这个读命令是直接发的0下去的，但是你发全0下去明显寻址到的不是0220这个寄存器，这个需要试一下*/
     EscALEvent.Byte[0]=SPI3_ReadWriteByte((u16)(0x0000) >> 5); 
  			     
    /* get first byte of AL Event register再发个0xff确定一下这个AL寄存器的值，因为一把传8位*/


    /* write to SPI1_BUF register starts the SPI access
       read the sm mailbox read ecatenable byte ？？？这里有个问题，就是说这个((0x0000 & 0x1F) << 3) 其实就是0啊，那么 | ESC_RD只是相当于发了一个读命令而已*/
	
     EscALEvent.Byte[1]=SPI3_ReadWriteByte((u8) (((0x1F) << 3) | ESC_RD));
    /* write to SPI1_BUF register starts the SPI access and get second byte of AL Event register */


    /* write to SPI1_BUF register starts the SPI access
       read the sm mailbox read ecatenable byte (last byte)其实假如这里不再有读那个mbxreadecat，那根本就不需要再发0xff去读spi，我暂时把它注释掉 */
  
    /* write to SPI1_BUF register starts the SPI access */

    /* get first byte of AL Event register 这个很奇怪，生成的这个所谓的mbxreadecat根本就没有用过，没有任何地方用到过*/
    EscMbxReadEcatCtrl = SPI3_ReadWriteByte((u8)(0XFF));

    /* there has to be at least 15 ns + CLK/2 after the transmission is finished
       before the SPI1_SEL signal shall be 1 */
    delay_us(1);
    GPIO_SetBits(GPIOG,GPIO_Pin_4) ;                              //关闭器件  
	EscMbxReadEcatCtrl=EscMbxReadEcatCtrl;
	INTX_ENABLE();

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief  The function operates a SPI access without addressing.
        Shall be implemented if interrupts are supported else this function is equal to "GetInterruptRegsiter()"

        The first two bytes of an access to the EtherCAT ASIC always deliver the AL_Event register (0x220).
        It will be saved in the global "EscALEvent"噢，我知道了，这个是说，在有中断的时候调用这个函数，其实跟上面的函数的内容是一样的
        同样这里还有一个问题，就是，这个所谓的中断既然是被包裹在HW_GetALEventRegister_Isr函数里面，但是会有什么中断需要用到这个函数呢
        经过查找，发现原来在PDI_Isr和Sync-Isr这两个中断服务函数里，都用到了这个裹在HW_GetALEventRegister_Isr，这就说明了，在中断里确实会读取这个值
		事实证明，虽然程序框架口口声声说两个函数是一样的，实际上，代码不会骗人，我个人认为下面的也就是ISR_GetInterruptRegister这个函数的代码更靠谱一些
*////////////////////////////////////////////////////////////////////////////////////////

static void ISR_GetInterruptRegister(void)

{
//	    GPIO_ResetBits(GPIOG,GPIO_Pin_4) ;  
//	    HW_EscReadIsr((UINT8*)&EscALEvent.Word,0x220,2);
//	    GPIO_SetBits(GPIOG,GPIO_Pin_4) ; 
		GPIO_ResetBits(GPIOG,GPIO_Pin_4) ;                              //使能器件  

	delay_us(1);
	/* there have to be at least 15 ns after the PB14  signal was active (0) before
		 the transmission shall be started */
	/* write to SPI1_BUF register starts the SPI access，也不知道这么复杂的用((u8)(0x0000) >> 5)是什么意思*/

	 EscALEvent.Byte[0]= SPI3_ReadWriteByte(0);  

	/* get first byte of AL Event register */

//   EscALEvent.Byte[0] =SPI3_ReadWriteByte((u8)(0XFF)); 
	/* write to SPI1_BUF register starts the SPI access
		 read the sm mailbox read ecatenable byte */
	 EscALEvent.Byte[1]= SPI3_ReadWriteByte(0);
	/* write to SPI1_BUF register starts the SPI access */

	/* get first byte of AL Event register */

 // EscALEvent.Byte[1] =SPI3_ReadWriteByte((u8)(0XFF)); 

	GPIO_SetBits(GPIOG,GPIO_Pin_4) ;                              //关闭器件  

}


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Command     ESC_WR performs a write access; ESC_RD performs a read access.

 \brief The function addresses the EtherCAT ASIC via SPI for a following SPI access.
   这就是SPI的寻址啦，地址是16位的，命令是8位的
*////////////////////////////////////////////////////////////////////////////////////////
static void AddressingEsc( u16 Address, u8	Command )
{
    
	UBYTETOWORD tmp;  	
	
    VARVOLATILE UINT8 dummy;
	
    tmp.Word  = ( Address << 3 ) |((u16) Command);   //使能器件  

	GPIO_ResetBits(GPIOG,GPIO_Pin_4); 
	
	delay_us(1);
	
	EscALEvent.Byte[1]=SPI3_ReadWriteByte(tmp.Byte[1]); 
//	
//	EscALEvent.Word=SPI3_ReadWriteByte(tmp.Word);          //先读一下，正常就把DR清空了
                                           
   // SPI3_ReadWriteByte((UINT8)(0xFF));          //先读一下，正常就把DR清空了
                                           
 //   =SPI3_ReadWriteByte(0XFF);         //发送16bit地址 和命令的高8位，然后读出相应的值
	 EscALEvent.Byte[0]=SPI3_ReadWriteByte(tmp.Byte[0]); 
	 

  // SPI3_ReadWriteByte((UINT8)(0xFF));                 //再读一下清空DR
	
   // EscALEvent.Byte[1]= SPI3_ReadWriteByte(0XFF);                      //发送16bit地址 和命令的低8位
	
	//dummy=SPI3_ReadWriteByte((UINT8)(0XFF));    //把数据读出来
	
	//GPIO_SetBits(GPIOG,GPIO_Pin_4);                       //注意不要SPI的速度太高，应该小于15M最好

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Command    ESC_WR performs a write access; ESC_RD performs a read access.

 \brief The function addresses the EtherCAT ASIC via SPI for a following SPI access.
        Shall be implemented if interrupts are supported else this function is equal to "AddressingEsc()"
        嗯，这就是在中断函数里面的寻址读写数据操作，这个函数是最底层的，最后会到哪里用呢，来让我们看一下
        HW_EscReadIsr和HW_EscWriteIsr这两个函数，一看就是中断里面用到的，也就是说在中断里读写数据咯，那么本着刨根问底的精神
        再挖掘一下这两个中断读写函数的最终归宿HW_EscReadWordIsrHW_EscReadDWordIsr这两个函数，那么其实这两个函数的使用本质也还是这个函数HW_EscReadIsr
        其实HW_EscReadIsr本身就已经又进了一步，它就是标准的硬件读函数，用到它的是PDO_OutputMapping，把他的指针给了APPL_OutputMapping，这个函数是干啥的呢
        接下来再说
        有一点很明显的就是，AddressingEsc和ISR_AddressingEsc并不是很一样，前一个读到的数据给了状态寄存器，但是后一个就是直接给了一个局部变量
*////////////////////////////////////////////////////////////////////////////////////////

static void ISR_AddressingEsc( UINT16 Address, UINT8 Command )
{
     VARVOLATILE UINT8 dummy;
	
     UBYTETOWORD tmp;
	
     tmp.Word  = ( Address << 3 ) |((u16) Command);

    /* select the SPI */

     GPIO_ResetBits(GPIOG,GPIO_Pin_4); 
    /* reset transmission flag */
     delay_us(1);
    /* send the first address/command byte to the ESC */
     dummy=SPI3_ReadWriteByte(tmp.Byte[1]);
    /* wait until the transmission of the byte is finished */

    /* reset transmission flag */


    /* send the second address/command byte to the ESC */
    dummy = SPI3_ReadWriteByte(tmp.Byte[0]); 
    /* wait until the transmission of the byte is finished */
   // dummy =SPI3_ReadWriteByte((u8)(0XFF));

    /* reset transmission flag */


}


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    This function shall be implemented if hardware resources need to be release
        when the sample application stops这个基本上没人用 infinoen的也没用这个
*////////////////////////////////////////////////////////////////////////////////////////
void HW_Release(void)
{

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    first two Bytes of ALEvent register (0x220)

 \brief  This function gets the current content of ALEvent register很简单，就是包一层，这样硬件归硬件，硬件顶上的都不变
*////////////////////////////////////////////////////////////////////////////////////////
u16 HW_GetALEventRegister(void)
{
    GetInterruptRegister();
  return EscALEvent.Word;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    first two Bytes of ALEvent register (0x220)

 \brief  The SPI PDI requires an extra ESC read access functions from interrupts service routines.
        The behaviour is equal to "HW_GetALEventRegister()"道理一样，中断函数用到的
*////////////////////////////////////////////////////////////////////////////////////////

u16 HW_GetALEventRegister_Isr(void)
{
     ISR_GetInterruptRegister();
   return EscALEvent.Word;
}



/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param pData        Pointer to a byte array which holds data to write or saves read data.
 \param Address      EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Len          Access size in Bytes.

 \brief  This function operates the SPI read access to the EtherCAT ASIC.
*////////////////////////////////////////////////////////////////////////////////////////
void HW_EscRead( UINT8 *pRDData, u16 Address, u16 Len )
{
    /* HBu 24.01.06: if the SPI will be read by an interrupt routine too the
                     mailbox reading may be interrupted but an interrupted
                     reading will remain in a SPI transmission fault that will
                     reset the internal Sync Manager status. Therefore the reading
                     will be divided in 1-byte reads with disabled interrupt 由于一些邮箱中断会影响SPI数据传输，所以在SPI传输的时候把所有中断失能*/

	UINT16 i = Len;
    UINT8 *pRDTmpData = (UINT8 *)pRDData;  
 
	while ( i-- > 0 )
    {
        /* the reading of data from the ESC can be interrupted by the
           AL Event ISR, in that case the address has to be reinitialized,
           in that case the status flag will indicate an error because
           the reading operation was interrupted without setting the last
           sent byte to 0xFF */
         INTX_DISABLE();  
			
			//关闭所有中断   
         AddressingEsc( Address, ESC_RD );//这个地址是16位的啊

        /* when reading the last byte the DI pin shall be 1 既然你强调了一下必须发一个1，那么就只有再专门发送一次*/
         GPIO_ResetBits(GPIOG,GPIO_Pin_4); 
		
          //SPI3_ReadWriteByte(0XFF);
		
         *pRDTmpData=SPI3_ReadWriteByte(0XFF);   
         pRDTmpData++;		
        /* get data byte这里我直接给0xff，然后读这个输出的值给到相应的指针 */
        
        /* enable the ESC interrupt to get the AL Event ISR the chance to interrupt,
           if the next byte is the last the transmission shall not be interrupted,
           otherwise a sync manager could unlock the buffer, because the last was
           read internally */
        INTX_ENABLE();
        /* there has to be at least 15 ns + CLK/2 after the transmission is finished
           before the SPI1_SEL signal shall be 1 */
     	GPIO_SetBits(GPIOG,GPIO_Pin_4);                            //失能SPI
        /* next address */
        Address++;
        
      
    }
     

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param pData        Pointer to a byte array which holds data to write or saves read data.
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Len            Access size in Bytes.

\brief  The SPI PDI requires an extra ESC read access functions from interrupts service routines.
        The behaviour is equal to "HW_EscRead()"
*////////////////////////////////////////////////////////////////////////////////////////

void HW_EscReadIsr( UINT8 *pData, u16 Address, u16 Len )
{
    /* HBu 24.01.06: if the SPI will be read by an interrupt routine too the
                     mailbox reading may be interrupted but an interrupted
                     reading will remain in a SPI transmission fault that will
                     reset the internal Sync Manager status. Therefore the reading
                     will be divided in 1-byte reads with disabled interrupt 由于一些邮箱中断会影响SPI数据传输，所以在SPI传输的时候把所有中断失能*/

	UINT16 i = Len;
	UINT8 data = 0;
  UINT8 *pRDTmpData = (UINT8 *)pData;  
	ISR_AddressingEsc( Address, ESC_RD );
 
	while ( i-- > 0 )
   {
		 if(i == 0)
		 {
		   data = 0XFF;
		 
		 }	
		 *pRDTmpData++=SPI3_ReadWriteByte(data);
	 }
			GPIO_SetBits(GPIOG,GPIO_Pin_4);    	 
//        /* the reading of data from the ESC can be interrupted by the
//           AL Event ISR, in that case the address has to be reinitialized,
//           in that case the status flag will indicate an error because
//           the reading operation was interrupted without setting the last
//           sent byte to 0xFF */
//         INTX_DISABLE();                                              //关闭所有中断   
//         AddressingEsc( Address, ESC_RD );//这个地址是16位的啊

//        /* when reading the last byte the DI pin shall be 1 既然你强调了一下必须发一个1，那么就只有再专门发送一次*/
//         GPIO_ResetBits(GPIOG,GPIO_Pin_4); 
//		
//          //SPI3_ReadWriteByte(0XFF);
//		
//         *pRDTmpData=SPI3_ReadWriteByte(0XFF);   
//         pRDTmpData++;		
//        /* get data byte这里我直接给0xff，然后读这个输出的值给到相应的指针 */
//        
//        /* enable the ESC interrupt to get the AL Event ISR the chance to interrupt,
//           if the next byte is the last the transmission shall not be interrupted,
//           otherwise a sync manager could unlock the buffer, because the last was
//           read internally */
//        INTX_ENABLE();
//        /* there has to be at least 15 ns + CLK/2 after the transmission is finished
//           before the SPI1_SEL signal shall be 1 */
//     	GPIO_SetBits(GPIOG,GPIO_Pin_4);                            //失能SPI
//        /* next address */
//        Address++;
//        
//      
//    }
//     


}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param pData        Pointer to a byte array which holds data to write or saves write data.
 \param Address      EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Len           Access size in Bytes.

  \brief  This function operates the SPI write access to the EtherCAT ASIC.这个问题就在于
*////////////////////////////////////////////////////////////////////////////////////////
void HW_EscWrite( UINT8  *pWRData, u16 Address, u16 Len )
{
    u16 i = Len;
    volatile UINT8 dummy;

    UINT8 *pWRTmpData = (UINT8 *)pWRData;

    /* loop for all bytes to be written */
    while ( i-- > 0 )
    {
		 INTX_DISABLE();//关闭所有的中断
		
        /* the reading of data from the ESC can be interrupted by the
           AL Event ISR, so every byte will be written separate因为数据读取是可以被AL中断的，所以数据是分字节读取的 */
        
         AddressingEsc( Address, ESC_WR );//将传下来的地址写进去
        /* start transmission */
		
		    GPIO_ResetBits(GPIOG,GPIO_Pin_4);                                  //使能器件   
		
        dummy=SPI3_ReadWriteByte( *pWRTmpData); 
		    pWRTmpData++;
        /* wait until transmission finished 下面这个dummy还是必须要有的，写一下，再读一下，这样指针增加一，保证可以连续的往地址里写数据*/
		
      //  AddressingEsc( Address, ESC_RD );//将传下来的地址写进去
		
		//dummy=SPI3_ReadWriteByte( 0XFFFF);
        /* enable the ESC interrupt to get the AL Event ISR the chance to interrupt */
        /* SPI1_BUF must be read, otherwise the module will not transfer the next received data from SPIxSR to SPIxRXB.
		这是说，这个data在写过之后一定要再读一下，这样下一个数据就不需要再做处理*/
         INTX_ENABLE();
		//在这里就给机会允许中断，否则一味地在这写啊写，那边中断来了也不响应，是不对的，由此可见，在中断里读写都是可以被打断的，这个优先级明显没有直接读写的高
        GPIO_SetBits(GPIOG,GPIO_Pin_4); 
        /* next address */
        Address++;
        /* reset transmission flag */
    }
	
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param pData        Pointer to a byte array which holds data to write or saves write data.
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Len            Access size in Bytes.

 \brief  The SPI PDI requires an extra ESC write access functions from interrupts service routines.
        The behaviour is equal to "HW_EscWrite()"
*////////////////////////////////////////////////////////////////////////////////////////

void HW_EscWriteIsr( UINT8  *pData, u16 Address, u16 Len )
{
    u16 i = Len;
    VARVOLATILE UINT8 dummy;
    UINT8 *pTmpData = (UINT8 *)pData;
	
	/* send the address and command to the ESC */
	ISR_AddressingEsc( Address, ESC_WR );
	
    while ( i-- > 0 )
    {
	//	 INTX_DISABLE();//关闭所有的中断
        /* loop for all bytes to be written */
//		GPIO_ResetBits(GPIOG,GPIO_Pin_4);  
        /* start transmission */
        dummy= SPI3_ReadWriteByte( *pTmpData); 
        pTmpData++;
		
		INTX_ENABLE();
//		GPIO_SetBits(GPIOG,GPIO_Pin_4); 
    }
	
	GPIO_SetBits(GPIOG,GPIO_Pin_4);
    /* reset transmission flag */

}

/** 
   *@brief  SPI init 
   *@note   Init spi2 and spi3
   *@param  None
   *@return None
   *@author liuguiqing  
   *@date   2021/10/21      
   *@version  V1.0.0
   */													 
void SPIHW_Init(void)
{ 
  SPI3_Init();		   			
  SPI2_Init();
}  

/** 
   *@brief  Read AD8028 data
   *@note   five slave not use
   *@param  None
   *@return None
   *@author liuguiqing  
   *@date   2021/10/21      
   *@version  V1.0.0
   */
void AD8028_data(void)
{
	int i=0;
	volatile u16 dummy;

	GPIO_SetBits(GPIOC,GPIO_Pin_0);//复位引脚置高
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);//片选CS使能
	dummy=SPI2_ReadWriteWord(0xBFC4);//设置ConversionRegister
	GPIO_SetBits(GPIOA,GPIO_Pin_0);//片选CS失能		
	for(i=0;i<10;i++)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);//片选CS使能
		delay_us(10);
		AD8028[i].Word=SPI2_ReadWriteWord(0x0000);		
        GPIO_SetBits(GPIOA,GPIO_Pin_0);//片选CS失能			
	}
    AD8028WorkWell=~AD8028WorkWell;
	if(AD8028WorkWell) 
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
	else 
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);//闪烁表示ADC工作正常	
} 


u8 rs485_tx_start = 0; 
void U485_process_data(TOBJ7000 *OUT_GENERIC,TOBJ6000 *IN_GENERIC)
{
	   u16 i;
	 	rs485_tx_start = 1; 
	//表示输出的数据刷新在这里进行
		RS485_tx_CON =(u8)OUT_GENERIC->RS485_Outputs_Count;
		RS485_tx_LEN=(u8)OUT_GENERIC->RS485_Outputs_Len;
		RS485_TX[0]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_1;	
		RS485_TX[1]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_2;		
		RS485_TX[2]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_3;
		RS485_TX[3]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_4;	
		RS485_TX[4]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_5;
		RS485_TX[5]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_6;	
		RS485_TX[6]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_7;
		RS485_TX[7]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_8;		
		RS485_TX[8]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_9;
		RS485_TX[9]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_10;
		RS485_TX[10]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_11;
		RS485_TX[11]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_12;
		RS485_TX[12]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_13;
		RS485_TX[13]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_14;
		RS485_TX[14]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_15;
		RS485_TX[15]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_16;	
		RS485_TX[16]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_17;		
		RS485_TX[17]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_18;
		RS485_TX[18]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_19;	
		RS485_TX[19]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_20;
		RS485_TX[20]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_21;	
		RS485_TX[21]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_22;
		RS485_TX[22]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_23;		
		RS485_TX[23]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_24;
		RS485_TX[24]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_25;
		RS485_TX[25]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_26;
		RS485_TX[26]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_27;
		RS485_TX[27]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_28;
		RS485_TX[28]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_29;
		RS485_TX[29]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_30;
		RS485_TX[30]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_31;
		RS485_TX[31]=(u8)OUT_GENERIC->RS485_Outputs_Data_Out_32;
		
//		RS485_tx_CON =2; 
//		RS485_tx_LEN=2; 
//		RS485_TX[0]=3;	 
//		RS485_TX[1]=0;		 
//		RS485_TX[2]=0; 
//		RS485_TX[3]=0;	 
//		RS485_TX[4]=0; 
//		RS485_TX[5]=0;	 
//		RS485_TX[6]=0; 
//		RS485_TX[7]=0;		 
//		RS485_TX[8]=0; 
//		RS485_TX[9]=0; 
//		RS485_TX[10]=0; 
//		RS485_TX[11]=0; 
//		RS485_TX[12]=0; 
//		RS485_TX[13]=0; 
//		RS485_TX[14]=0; 
//		RS485_TX[15]=0;	 
//		RS485_TX[16]=0;		 
//		RS485_TX[17]=0; 
//		RS485_TX[18]=0;	 
//		RS485_TX[19]=0; 
//		RS485_TX[20]=0;	 
//		RS485_TX[21]=0; 
//		RS485_TX[22]=0;		 
//		RS485_TX[23]=0; 
//		RS485_TX[24]=0; 
//		RS485_TX[25]=0; 
//		RS485_TX[26]=0; 
//		RS485_TX[27]=0; 
//		RS485_TX[28]=0; 
//		RS485_TX[29]=0; 
//		RS485_TX[30]=0; 
//		RS485_TX[31]=0; 
		 
		rs485_tx_start = 0; 
		
 if(Flag_485Rx)
		{	  
			for(i=RS485_rx_LEN;i<32;i++)
			{
				RS485_RX[i] =0;
			}
		Flag_485Rx =0;
			
		IN_GENERIC->RS485_Inputs_Count = RS485_CON;
		IN_GENERIC->RS485_Inputs_Len = RS485_rx_LEN;
		
		IN_GENERIC->RS485_Inputs_Data_In_1=RS485_RX[0];
		IN_GENERIC->RS485_Inputs_Data_In_2=RS485_RX[1];
		IN_GENERIC->RS485_Inputs_Data_In_3=RS485_RX[2];					
		IN_GENERIC->RS485_Inputs_Data_In_4=RS485_RX[3];
		IN_GENERIC->RS485_Inputs_Data_In_5=RS485_RX[4];
		IN_GENERIC->RS485_Inputs_Data_In_6=RS485_RX[5];
		IN_GENERIC->RS485_Inputs_Data_In_7=RS485_RX[6];		
		IN_GENERIC->RS485_Inputs_Data_In_8=RS485_RX[7];
		IN_GENERIC->RS485_Inputs_Data_In_9=RS485_RX[8];
		IN_GENERIC->RS485_Inputs_Data_In_10=RS485_RX[9];
		IN_GENERIC->RS485_Inputs_Data_In_11=RS485_RX[10];					
		IN_GENERIC->RS485_Inputs_Data_In_12=RS485_RX[11];
		IN_GENERIC->RS485_Inputs_Data_In_13=RS485_RX[12];
		IN_GENERIC->RS485_Inputs_Data_In_14=RS485_RX[13];
		IN_GENERIC->RS485_Inputs_Data_In_15=RS485_RX[14];		
		IN_GENERIC->RS485_Inputs_Data_In_16=RS485_RX[15];
		IN_GENERIC->RS485_Inputs_Data_In_17=RS485_RX[16];
		IN_GENERIC->RS485_Inputs_Data_In_18=RS485_RX[17];
		IN_GENERIC->RS485_Inputs_Data_In_19=RS485_RX[18];					
		IN_GENERIC->RS485_Inputs_Data_In_20=RS485_RX[19];
		IN_GENERIC->RS485_Inputs_Data_In_21=RS485_RX[20];
		IN_GENERIC->RS485_Inputs_Data_In_22=RS485_RX[21];
		IN_GENERIC->RS485_Inputs_Data_In_23=RS485_RX[22];		
		IN_GENERIC->RS485_Inputs_Data_In_24=RS485_RX[23];
		IN_GENERIC->RS485_Inputs_Data_In_25=RS485_RX[24];
		IN_GENERIC->RS485_Inputs_Data_In_26=RS485_RX[25];
		IN_GENERIC->RS485_Inputs_Data_In_27=RS485_RX[26];					
		IN_GENERIC->RS485_Inputs_Data_In_28=RS485_RX[27];
		IN_GENERIC->RS485_Inputs_Data_In_29=RS485_RX[28];
		IN_GENERIC->RS485_Inputs_Data_In_30=RS485_RX[29];
		IN_GENERIC->RS485_Inputs_Data_In_31=RS485_RX[30];		
		IN_GENERIC->RS485_Inputs_Data_In_32=RS485_RX[31];
	}
}

u8 can_tx_start = 0; 
void CAN_process_data(TOBJ7000 *OUT_GENERIC,TOBJ6000 *IN_GENERIC)
{
	if(Flag_canRx == 1)
	{
		IN_GENERIC->CAN_RX_Change_Count = can_rx_cnt;
		IN_GENERIC->CAN_RX_ID = can_rx_ID;
		IN_GENERIC->CAN_RX_LEN = can_rx_len;
		IN_GENERIC->CANInputsDataIn1=CAN_DATA[0];
		IN_GENERIC->CANInputsDataIn2=CAN_DATA[1];
		IN_GENERIC->CANInputsDataIn3=CAN_DATA[2];					
		IN_GENERIC->CANInputsDataIn4=CAN_DATA[3];
		IN_GENERIC->CANInputsDataIn5=CAN_DATA[4];
		IN_GENERIC->CANInputsDataIn6=CAN_DATA[5];
		IN_GENERIC->CANInputsDataIn7=CAN_DATA[6];		
		IN_GENERIC->CANInputsDataIn8=CAN_DATA[7];
		Flag_canRx = 0;
	}

	can_tx_start = 1;
	can_tx_cnt = OUT_GENERIC->CAN_TX_Change_Count;
	can_tx_ID = OUT_GENERIC->CAN_TX_ID;
	can_tx_len = OUT_GENERIC->CAN_TX_LEN;
	can_send_data[0] = OUT_GENERIC->CANOutputsDataOut1;
	can_send_data[1] = OUT_GENERIC->CANOutputsDataOut2;
	can_send_data[2] = OUT_GENERIC->CANOutputsDataOut3;
	can_send_data[3] = OUT_GENERIC->CANOutputsDataOut4;
	can_send_data[4] = OUT_GENERIC->CANOutputsDataOut5;
	can_send_data[5] = OUT_GENERIC->CANOutputsDataOut6;
	can_send_data[6] = OUT_GENERIC->CANOutputsDataOut7;
	can_send_data[7] = OUT_GENERIC->CANOutputsDataOut8;
  can_tx_start = 0;
}

void ADC_process_data(TOBJ6000 *IN_GENERIC)
{	
//	IN_GENERIC->Analog_Voltage_Inputs_channel1 = (AD8028[1].Word)*42/15;//10个内置的AI42 15
//	IN_GENERIC->Analog_Voltage_Inputs_channel2 = ((AD8028[2].Word)&0x0fff)*42/15;
//	IN_GENERIC->Analog_Voltage_Inputs_channel3 = ((AD8028[3].Word)&0x0fff)*42/15;//10个内置的AI
//	IN_GENERIC->Analog_Voltage_Inputs_channel4 = ((AD8028[4].Word)&0x0fff)*42/15;
//	
//	IN_GENERIC->Analog_Current_Inputs_channel1 = ((AD8028[5].Word)&0x0fff)/1.6;
//	IN_GENERIC->Analog_Current_Inputs_channel2 = ((AD8028[6].Word)&0x0fff)/1.6;	
//	IN_GENERIC->Analog_Current_Inputs_channel3 = ((AD8028[7].Word)&0x0fff)/1.6;
//	IN_GENERIC->Analog_Current_Inputs_channel4 = ((AD8028[8].Word)&0x0fff)/1.6;	
	
	
	IN_GENERIC->Analog_Voltage_Inputs_channel1 = (AD8028[1].Word)*42/15;
  IN_GENERIC->Analog_Voltage_Inputs_channel2 = ((AD8028[2].Word)&0x0fff)*42/15;

	IN_GENERIC->Analog_Current_Inputs_channel1 = ((AD8028[5].Word)&0x0fff)/1.6;
	IN_GENERIC->Analog_Current_Inputs_channel2 = ((AD8028[6].Word)&0x0fff)/1.6;	
}

/*--------------------------------------------------------------------------------------
------
------    exported hardware access functions
------
--------------------------------------------------------------------------------------*/


/////////////////////////////////////////////////////////////////////////////////////////
/**
\return     0 if initialization was successful

 \brief    This function intialize the Process Data Interface (PDI) and the host controller.
            硬件初始化都在这里完成的这里面定义了一个intmask的东西
*////////////////////////////////////////////////////////////////////////////////////////
BOOL inputresult = 0;
UINT8 HW_Init(void)
{
	u32 intMask;
	u32 rs485_br[1];
	u32 can_br[1];
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	
	delay_init(168);                               //初始化延时函数
	LED_Init();				                             //初始化LED 	
	DO_Init();									                   //初始化DO
	DI_Init(); 

	gpio_init();
  Reload_State_All_Value();
  Reload_Config_All_Value();	
  usart1_init(power_manage.uart1_bps);
	ads1115a_Init();
	ads1115b_Init();
	ads1115c_Init();

	uint16_t a0=3,a1=3,a2=3,a3=3,a4=3,a5=3,a6=3,a7=3,a16=3,a17=3,a18=3,a19=3,a20=3,a21=3,a22=3,a23=3;
	BOOL b0=0,b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b16=0,b17=0,b18=0,b19=0,b20=0,b21=0,b22=0,b23=0;
	
	for(int i=0; i<32; i++)
	{
		/* 8 channel DI, 取反才是合理的逻辑，这时接收到高电平就是1，低电平就是0 */
		inputresult=~input_filter(ST_IN4_I0_0,(uint16_t *)&a0,6,2,(BOOL *)&b0);
		inputresult=~input_filter(ST_IN3_I0_1,(uint16_t *)&a1,6,2,(BOOL *)&b1);
		inputresult=~input_filter(ST_IN2_I0_2,(uint16_t *)&a2,6,2,(BOOL *)&b2);
		inputresult=~input_filter(ST_IN1_I0_3,(uint16_t *)&a3,6,2,(BOOL *)&b3);
		inputresult=~input_filter(ST_IN5_I1_0,(uint16_t *)&a4,6,2,(BOOL *)&b4);
		inputresult=~input_filter(ST_IN6_I1_1,(uint16_t *)&a5,6,2,(BOOL *)&b5);
		inputresult=~input_filter(ST_IN7_I1_2,(uint16_t *)&a6,6,2,(BOOL *)&b6);
		inputresult=~input_filter(ST_IN8_I1_3,(uint16_t *)&a7,6,2,(BOOL *)&b7);
		
		/* 8 channel Function/User DI, 取反才是合理的逻辑，这时接收到高电平就是1，低电平就是0 */
		inputresult=~input_filter(ST_IN17_I2_0,(uint16_t *)&a16,6,2,(BOOL *)&b16);
		inputresult=~input_filter(ST_IN18_I2_1,(uint16_t *)&a17,6,2,(BOOL *)&b17);
		inputresult=~input_filter(ST_IN19_I2_2,(uint16_t *)&a18,6,2,(BOOL *)&b18);
		inputresult=~input_filter(ST_IN20_I2_3,(uint16_t *)&a19,6,2,(BOOL *)&b19);
		inputresult=~input_filter(ST_IN24_I3_0,(uint16_t *)&a20,6,2,(BOOL *)&b20);
		inputresult=~input_filter(ST_IN23_I3_1,(uint16_t *)&a21,6,2,(BOOL *)&b21);
		inputresult=~input_filter(ST_IN22_I3_2,(uint16_t *)&a22,6,2,(BOOL *)&b22);
		inputresult=~input_filter(ST_IN21_I3_3,(uint16_t *)&a23,6,2,(BOOL *)&b23);	
	}

  TIM_ENCODER_Configuration();	


  //从EEPROM中读取485波特率
	STMFLASH_Read(FLASH_SAVE_ADDR_baud,(u32*)rs485_br,1);
	if((rs485_br[0]!= 1200)&&(rs485_br[0]!= 2400)&&(rs485_br[0]!= 4800)&&(rs485_br[0]!= 9600)&&(rs485_br[0]!= 14400)&&(rs485_br[0]!= 19200)&&(rs485_br[0]!= 38400)\
		&&(rs485_br[0]!= 56000)&&(rs485_br[0]!= 57600)&&(rs485_br[0]!= 115200)&&(rs485_br[0]!= 128000)&&(rs485_br[0]!= 256000))
	{
    rs485_br[0] = 115200;
		
	}	
		RS485_Init(rs485_br[0]);
	
	 //从EEPROM中读取CAN波特率
	 STMFLASH_Read(FLASH_SAVE_ADDR_baud + 4,(u32*)can_br,1);
	if((can_br[0]!= 10)&&(can_br[0]!= 20)&&(can_br[0]!= 50)&&(can_br[0]!= 100)&&(can_br[0]!= 125)&&(can_br[0]!= 250)&&(can_br[0]!= 500)\
		&&(can_br[0]!= 1000))
	{
    can_br[0] = 500;
		
	}	
  CAN_Configuration(can_br[0]); 
	
	SPIHW_Init();			                        //SPI3初始化

  GPIO_ResetBits(GPIOF,GPIO_Pin_5);
	delay_ms(2);
	GPIO_SetBits(GPIOF,GPIO_Pin_5);
	do
	{
			intMask = 0x93;
			HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
			intMask = 0;
			HW_EscReadDWord(intMask, ESC_AL_EVENTMASK_OFFSET);//这句话就是说，一定要让这个0x204寄存器等于0x093，即 10010011下面翻出来0x204这个寄存器看一下
	} while (intMask != 0x93);//这个寄存器就是关于中断屏蔽的掩码的，就是说，这个掩码是掩的bit0，bit1，bit4，bit7，这四个是不可以的 ，因为你设置相应的寄存器为0时//
/*才会触发产生中断信号，也就是说，2，3，5，6这四个是会产生中断信号，最主要的1和4位都是采用查询的方式，而不是中断*/

	intMask = 0x00;
	HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);//这个相当于把中断的0220寄存器清零了，初始化了

//	 EXTI1_Init();                  //初始化ESC中断
	 EXTI2_Init();                  // 初始化同步中断信号0                    
	 EXTI3_Init();                  // 初始化同步中断信号1
	TIM2_Int_Init(10-1,8400-1);
//	TIM4_Int_Init(1000-1,84-1);  // DC时钟。初始化ECAT定时器 ，TIM4的APB1的时钟是84M，所以84分频之后就变为1MHz，也就是周期1us，乘以1000，即：1ms
	 INTX_ENABLE();

	return 0;
}

 


