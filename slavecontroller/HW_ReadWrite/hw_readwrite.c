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
//------ For ADC&DAC&U485 data ע���ˣ����UALEVENT���ڲ��Ľṹ���壬����ṹ��װ�ں������ڹ������ļ����õ�
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
------    Global Interrupt settingȫ���жϵĿ��������ﶨ���˺� �ж��Ǳ߻�Ҫ����һ��
------
-----------------------------------------------------------------------------------------*/

#define    DISABLE_GLOBAL_INT             INTX_DISABLE() //ȫ���жϹرգ���������õ���sys����Ļ����룬��������궨��û���õ���ֱ���õ�INTX
#define    ENABLE_GLOBAL_INT              INTX_ENABLE()   
#define    DISABLE_AL_EVENT_INT           DISABLE_GLOBAL_INT
#define    ENABLE_AL_EVENT_INT            ENABLE_GLOBAL_INT


/*-----------------------------------------------------------------------------------------
------
------    ESC Interrupt ���Ǹ��ⲿ�жϣ�����һ�¾�����
------
-----------------------------------------------------------------------------------------*/

//void EXTI0_Init(void);
//void EXTI1_Init(void);
//void EXTI2_Init(void);
//void EXTI3_Init(void);

#define    INIT_ESC_INT                EXTI0_Init() //�ж���0 negative edge ; ������ȼ�;highest priority
#define    ESC_INT_REQ                 EXTI_GetFlagStatus(EXTI_Line0)         //ESC Interrupt (INT0) state �����ж���0�ϵ�״̬λ
                                          //ESC Interrupt input port ,��������ܽž������ж���0���棬���жϳ�ʼ����ʱ��ͳ�ʼ������
                                          //�����ⲿ�жϺ�������Ӧ����EXTI�����ң�������PDI���ݵĲ����ȵ�
//#define    ACK_ESC_INT                EXTI_ClearFlagStatus(EXTI_Line0) //���������жϱ�־λ��ʵ���ϣ�ֱ������ͺ���EXTI_Clear���
 

/*-----------------------------------------------------------------------------------------
------
------    SYNC0 Interrupt  ͬ���źŵ��ж� ������· ��STM32����ƥ��
------
-----------------------------------------------------------------------------------------*/

#define    INIT_SYNC0_INT                    EXTI1_Init()         //  negative edge ;  //highest priority�������ESC�ĳ�ʼ����һ���ģ����ǳ�ʼ���ж���1
#define    SYNC0_INT_REQ                     EXTI_GetFlagStatus(EXTI_Line1)//Sync1 Interrupt (INT2) state

#define    DISABLE_SYNC0_INT                EN_DISEN_EXTI( 0,1)//disable interrupt source INT1������������ж��ߵ�ʧ������һ������
#define    ENABLE_SYNC0_INT                 EN_DISEN_EXTI( 1,1) //enable interrupt source INT1�ж���ʹ�ܶ���
//#define    ACK_SYNC0_INT                    {(SYNC0_INT_REQ) = 0;}
//#define    SET_SYNC0_INT                    {(SYNC0_INT_REQ) = 1;}//�����Զ��ж��߱�־λ������λ���������㣬ʵ�����жϱ�־λ�ǲ��ܹ������λ�ģ�ֻ�ܸ�Ӳ����λ
#define    SYNC0_INT_PORT_IS_ACTIVE         ( EXTI_GetITStatus(EXTI_Line1)==1;)


#define    INIT_SYNC1_INT                    EXTI2_Init()                   //
#define    SYNC1_INT_REQ                    EXTI_GetFlagStatus(EXTI_Line2) //Sync1 Interrupt (INT3) state
                                                                         

#define    DISABLE_SYNC1_INT               EN_DISEN_EXTI( 0,2)//disable interrupt source INT3
#define    ENABLE_SYNC1_INT                EN_DISEN_EXTI( 1,2)//enable interrupt source INT3

//#define    ACK_SYNC1_INT                    {(SYNC1_INT_REQ) = 0;}
//#define    SET_SYNC1_INT                    {(SYNC1_INT_REQ) = 1;}
#define    SYNC1_INT_PORT_IS_ACTIVE       ( EXTI_GetITStatus(EXTI_Line2)==1;)//�ж�һ������ж��ߵı�־λ


/*-----------------------------------------------------------------------------------------
------
------    Hardware timer Ӳ����ʱ�����趨һ����ʱ������֪��ʲô��
------
-----------------------------------------------------------------------------------------*/



//#define INIT_ECAT_TIMER                TIM3_Int_Init(100-1,8400-1)//��Ӧ1ms����Ҫ�����1ms
         

#define STOP_ECAT_TIMER                TIM_Cmd(TIM3,DISABLE)

#define START_ECAT_TIMER               TIM_Cmd(TIM3,ENABLE)



/*-----------------------------------------------------------------------------------------
------
------    Configuration Bits ���þ����һЩʹ����ʹ�ܽŵģ��ⲿ�ֱַ��ڸ�Ӳ���ĳ�ʼ�������������
------
-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------
------
------    LED defines ����Ƕ���LED�Ƶģ�����ECAT��˵�����Բ�ȥ������
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
 \brief  The function operates a SPI access without addressing.�����޵�ַ���ʵĺ����������������ȷ���жϼĴ�����ֵ

        The first two bytes of an access to the EtherCAT ASIC always deliver the AL_Event register (0x220).Ҳ����˵����ǲ���Ҫ����ַ�����صľ������ֵ
        It will be saved in the global "EscALEvent"ȫ�ֱ���EscALEvent����ŵľ���0x0220��ʵ���ϣ�0x0220����Ĵ��������˺ܶ���Ҫ��ֵ
		��һ�������ʱ��һ�㶼��Ҫ�ȶ�ȡ���0x220��ֵ�ģ�����˵���ֵ��bit0����λʱ��˵��AL CONTROL����Ĵ�����д�ˣ�����������ȥ������Ĵ���0x0120��bit0���ͻ�����
		bit1����ͬ��ʱ��������ж��źţ�����ź��������λ�ˣ���ô����Ҫȥ������ʱ�䣬��Ȼ�������PDI��������ʹ��ʱ������
		bit2,bit3��ͬ��ʱ���źŵı�־λ������λ�ǲ��ǿ�����Ҫ������0x0151.3��0x0151.7��Ȼ�����Ҫȥ��0x098E��0x098F�Ĵ�����
		bit4���������Ҫ����˵�Ƿ���sync_manager�ı仯��Ϊʲô˵����Ҫ����Ϊ���ݵĴ������յľ��Ǳ�����sys_manager�����仯�ˣ��Ǽ���״̬����Ϊ�ڲ�ͬ��״̬�����棬����״̬��ͬ��
		����Ӧ�¼�������Ȼ������Ӧ�¼�����ʱ����8-23λ����Ӧ0-15��Ȼ��ȥ��0x0806�Ĵ�������ø�����Ϣ
		�ڶ����ֽڵ�������Ҫ��˵�������ĸ�sync_manager�仯��
		����˵��Ϊʲô������������жϼĴ���������һЩ�жϱ仯����Ϣ������Ĵ�������
*////////////////////////////////////////////////////////////////////////////////////////
static void GetInterruptRegister(void)
{
//	
//      GPIO_ResetBits(GPIOG,GPIO_Pin_4) ;  
//	    HW_EscReadIsr((UINT8*)&EscALEvent.Word,0x220,2);
//	    GPIO_SetBits(GPIOG,GPIO_Pin_4) ; 
	  UINT8        EscMbxReadEcatCtrl;

      INTX_DISABLE();                                                  //������Ҫ��������ж�ȫ���ص�
	
   	  GPIO_ResetBits(GPIOG,GPIO_Pin_4) ;                              //ʹ��SPI��������Ϊ�ж��Ѿ��ر��ˣ��������շ�SPI���ݵ�ʱ�򣬲��ᱻ���
	 
   	  delay_us(1);
    /* there have to be at least 15 ns after the PB14 signal was active (0) before
       the transmission shall be started��ʹ��SPI֮��Ӧ����һ��ʱ����ӳ�,������ֱ���ӳ�1us */
	
    /* write to SPI1_BUF register starts the SPI access�������������ֱ�ӷ���0��ȥ�ģ������㷢ȫ0��ȥ����Ѱַ���Ĳ���0220����Ĵ����������Ҫ��һ��*/
     EscALEvent.Byte[0]=SPI3_ReadWriteByte((u16)(0x0000) >> 5); 
  			     
    /* get first byte of AL Event register�ٷ���0xffȷ��һ�����AL�Ĵ�����ֵ����Ϊһ�Ѵ�8λ*/


    /* write to SPI1_BUF register starts the SPI access
       read the sm mailbox read ecatenable byte �����������и����⣬����˵���((0x0000 & 0x1F) << 3) ��ʵ����0������ô | ESC_RDֻ���൱�ڷ���һ�����������*/
	
     EscALEvent.Byte[1]=SPI3_ReadWriteByte((u8) (((0x1F) << 3) | ESC_RD));
    /* write to SPI1_BUF register starts the SPI access and get second byte of AL Event register */


    /* write to SPI1_BUF register starts the SPI access
       read the sm mailbox read ecatenable byte (last byte)��ʵ�������ﲻ���ж��Ǹ�mbxreadecat���Ǹ����Ͳ���Ҫ�ٷ�0xffȥ��spi������ʱ����ע�͵� */
  
    /* write to SPI1_BUF register starts the SPI access */

    /* get first byte of AL Event register �������֣����ɵ������ν��mbxreadecat������û���ù���û���κεط��õ���*/
    EscMbxReadEcatCtrl = SPI3_ReadWriteByte((u8)(0XFF));

    /* there has to be at least 15 ns + CLK/2 after the transmission is finished
       before the SPI1_SEL signal shall be 1 */
    delay_us(1);
    GPIO_SetBits(GPIOG,GPIO_Pin_4) ;                              //�ر�����  
	EscMbxReadEcatCtrl=EscMbxReadEcatCtrl;
	INTX_ENABLE();

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief  The function operates a SPI access without addressing.
        Shall be implemented if interrupts are supported else this function is equal to "GetInterruptRegsiter()"

        The first two bytes of an access to the EtherCAT ASIC always deliver the AL_Event register (0x220).
        It will be saved in the global "EscALEvent"�ޣ���֪���ˣ������˵�������жϵ�ʱ����������������ʵ������ĺ�����������һ����
        ͬ�����ﻹ��һ�����⣬���ǣ������ν���жϼ�Ȼ�Ǳ�������HW_GetALEventRegister_Isr�������棬���ǻ���ʲô�ж���Ҫ�õ����������
        �������ң�����ԭ����PDI_Isr��Sync-Isr�������жϷ���������õ����������HW_GetALEventRegister_Isr�����˵���ˣ����ж���ȷʵ���ȡ���ֵ
		��ʵ֤������Ȼ�����ܿڿ�����˵����������һ���ģ�ʵ���ϣ����벻��ƭ�ˣ��Ҹ�����Ϊ�����Ҳ����ISR_GetInterruptRegister��������Ĵ��������һЩ
*////////////////////////////////////////////////////////////////////////////////////////

static void ISR_GetInterruptRegister(void)

{
//	    GPIO_ResetBits(GPIOG,GPIO_Pin_4) ;  
//	    HW_EscReadIsr((UINT8*)&EscALEvent.Word,0x220,2);
//	    GPIO_SetBits(GPIOG,GPIO_Pin_4) ; 
		GPIO_ResetBits(GPIOG,GPIO_Pin_4) ;                              //ʹ������  

	delay_us(1);
	/* there have to be at least 15 ns after the PB14  signal was active (0) before
		 the transmission shall be started */
	/* write to SPI1_BUF register starts the SPI access��Ҳ��֪����ô���ӵ���((u8)(0x0000) >> 5)��ʲô��˼*/

	 EscALEvent.Byte[0]= SPI3_ReadWriteByte(0);  

	/* get first byte of AL Event register */

//   EscALEvent.Byte[0] =SPI3_ReadWriteByte((u8)(0XFF)); 
	/* write to SPI1_BUF register starts the SPI access
		 read the sm mailbox read ecatenable byte */
	 EscALEvent.Byte[1]= SPI3_ReadWriteByte(0);
	/* write to SPI1_BUF register starts the SPI access */

	/* get first byte of AL Event register */

 // EscALEvent.Byte[1] =SPI3_ReadWriteByte((u8)(0XFF)); 

	GPIO_SetBits(GPIOG,GPIO_Pin_4) ;                              //�ر�����  

}


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Command     ESC_WR performs a write access; ESC_RD performs a read access.

 \brief The function addresses the EtherCAT ASIC via SPI for a following SPI access.
   �����SPI��Ѱַ������ַ��16λ�ģ�������8λ��
*////////////////////////////////////////////////////////////////////////////////////////
static void AddressingEsc( u16 Address, u8	Command )
{
    
	UBYTETOWORD tmp;  	
	
    VARVOLATILE UINT8 dummy;
	
    tmp.Word  = ( Address << 3 ) |((u16) Command);   //ʹ������  

	GPIO_ResetBits(GPIOG,GPIO_Pin_4); 
	
	delay_us(1);
	
	EscALEvent.Byte[1]=SPI3_ReadWriteByte(tmp.Byte[1]); 
//	
//	EscALEvent.Word=SPI3_ReadWriteByte(tmp.Word);          //�ȶ�һ�£������Ͱ�DR�����
                                           
   // SPI3_ReadWriteByte((UINT8)(0xFF));          //�ȶ�һ�£������Ͱ�DR�����
                                           
 //   =SPI3_ReadWriteByte(0XFF);         //����16bit��ַ ������ĸ�8λ��Ȼ�������Ӧ��ֵ
	 EscALEvent.Byte[0]=SPI3_ReadWriteByte(tmp.Byte[0]); 
	 

  // SPI3_ReadWriteByte((UINT8)(0xFF));                 //�ٶ�һ�����DR
	
   // EscALEvent.Byte[1]= SPI3_ReadWriteByte(0XFF);                      //����16bit��ַ ������ĵ�8λ
	
	//dummy=SPI3_ReadWriteByte((UINT8)(0XFF));    //�����ݶ�����
	
	//GPIO_SetBits(GPIOG,GPIO_Pin_4);                       //ע�ⲻҪSPI���ٶ�̫�ߣ�Ӧ��С��15M���

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Command    ESC_WR performs a write access; ESC_RD performs a read access.

 \brief The function addresses the EtherCAT ASIC via SPI for a following SPI access.
        Shall be implemented if interrupts are supported else this function is equal to "AddressingEsc()"
        �ţ���������жϺ��������Ѱַ��д���ݲ����������������ײ�ģ����ᵽ�������أ��������ǿ�һ��
        HW_EscReadIsr��HW_EscWriteIsr������������һ�������ж������õ��ģ�Ҳ����˵���ж����д���ݿ�����ô�����ٸ��ʵ׵ľ���
        ���ھ�һ���������ж϶�д���������չ���HW_EscReadWordIsrHW_EscReadDWordIsr��������������ô��ʵ������������ʹ�ñ���Ҳ�����������HW_EscReadIsr
        ��ʵHW_EscReadIsr������Ѿ��ֽ���һ���������Ǳ�׼��Ӳ�����������õ�������PDO_OutputMapping��������ָ�����APPL_OutputMapping����������Ǹ�ɶ����
        ��������˵
        ��һ������Եľ��ǣ�AddressingEsc��ISR_AddressingEsc�����Ǻ�һ����ǰһ�����������ݸ���״̬�Ĵ��������Ǻ�һ������ֱ�Ӹ���һ���ֲ�����
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
        when the sample application stops���������û���� infinoen��Ҳû�����
*////////////////////////////////////////////////////////////////////////////////////////
void HW_Release(void)
{

}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    first two Bytes of ALEvent register (0x220)

 \brief  This function gets the current content of ALEvent register�ܼ򵥣����ǰ�һ�㣬����Ӳ����Ӳ����Ӳ�����ϵĶ�����
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
        The behaviour is equal to "HW_GetALEventRegister()"����һ�����жϺ����õ���
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
                     will be divided in 1-byte reads with disabled interrupt ����һЩ�����жϻ�Ӱ��SPI���ݴ��䣬������SPI�����ʱ��������ж�ʧ��*/

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
			
			//�ر������ж�   
         AddressingEsc( Address, ESC_RD );//�����ַ��16λ�İ�

        /* when reading the last byte the DI pin shall be 1 ��Ȼ��ǿ����һ�±��뷢һ��1����ô��ֻ����ר�ŷ���һ��*/
         GPIO_ResetBits(GPIOG,GPIO_Pin_4); 
		
          //SPI3_ReadWriteByte(0XFF);
		
         *pRDTmpData=SPI3_ReadWriteByte(0XFF);   
         pRDTmpData++;		
        /* get data byte������ֱ�Ӹ�0xff��Ȼ�����������ֵ������Ӧ��ָ�� */
        
        /* enable the ESC interrupt to get the AL Event ISR the chance to interrupt,
           if the next byte is the last the transmission shall not be interrupted,
           otherwise a sync manager could unlock the buffer, because the last was
           read internally */
        INTX_ENABLE();
        /* there has to be at least 15 ns + CLK/2 after the transmission is finished
           before the SPI1_SEL signal shall be 1 */
     	GPIO_SetBits(GPIOG,GPIO_Pin_4);                            //ʧ��SPI
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
                     will be divided in 1-byte reads with disabled interrupt ����һЩ�����жϻ�Ӱ��SPI���ݴ��䣬������SPI�����ʱ��������ж�ʧ��*/

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
//         INTX_DISABLE();                                              //�ر������ж�   
//         AddressingEsc( Address, ESC_RD );//�����ַ��16λ�İ�

//        /* when reading the last byte the DI pin shall be 1 ��Ȼ��ǿ����һ�±��뷢һ��1����ô��ֻ����ר�ŷ���һ��*/
//         GPIO_ResetBits(GPIOG,GPIO_Pin_4); 
//		
//          //SPI3_ReadWriteByte(0XFF);
//		
//         *pRDTmpData=SPI3_ReadWriteByte(0XFF);   
//         pRDTmpData++;		
//        /* get data byte������ֱ�Ӹ�0xff��Ȼ�����������ֵ������Ӧ��ָ�� */
//        
//        /* enable the ESC interrupt to get the AL Event ISR the chance to interrupt,
//           if the next byte is the last the transmission shall not be interrupted,
//           otherwise a sync manager could unlock the buffer, because the last was
//           read internally */
//        INTX_ENABLE();
//        /* there has to be at least 15 ns + CLK/2 after the transmission is finished
//           before the SPI1_SEL signal shall be 1 */
//     	GPIO_SetBits(GPIOG,GPIO_Pin_4);                            //ʧ��SPI
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

  \brief  This function operates the SPI write access to the EtherCAT ASIC.������������
*////////////////////////////////////////////////////////////////////////////////////////
void HW_EscWrite( UINT8  *pWRData, u16 Address, u16 Len )
{
    u16 i = Len;
    volatile UINT8 dummy;

    UINT8 *pWRTmpData = (UINT8 *)pWRData;

    /* loop for all bytes to be written */
    while ( i-- > 0 )
    {
		 INTX_DISABLE();//�ر����е��ж�
		
        /* the reading of data from the ESC can be interrupted by the
           AL Event ISR, so every byte will be written separate��Ϊ���ݶ�ȡ�ǿ��Ա�AL�жϵģ����������Ƿ��ֽڶ�ȡ�� */
        
         AddressingEsc( Address, ESC_WR );//���������ĵ�ַд��ȥ
        /* start transmission */
		
		    GPIO_ResetBits(GPIOG,GPIO_Pin_4);                                  //ʹ������   
		
        dummy=SPI3_ReadWriteByte( *pWRTmpData); 
		    pWRTmpData++;
        /* wait until transmission finished �������dummy���Ǳ���Ҫ�еģ�дһ�£��ٶ�һ�£�����ָ������һ����֤��������������ַ��д����*/
		
      //  AddressingEsc( Address, ESC_RD );//���������ĵ�ַд��ȥ
		
		//dummy=SPI3_ReadWriteByte( 0XFFFF);
        /* enable the ESC interrupt to get the AL Event ISR the chance to interrupt */
        /* SPI1_BUF must be read, otherwise the module will not transfer the next received data from SPIxSR to SPIxRXB.
		����˵�����data��д��֮��һ��Ҫ�ٶ�һ�£�������һ�����ݾͲ���Ҫ��������*/
         INTX_ENABLE();
		//������͸����������жϣ�����һζ������д��д���Ǳ��ж�����Ҳ����Ӧ���ǲ��Եģ��ɴ˿ɼ������ж����д���ǿ��Ա���ϵģ�������ȼ�����û��ֱ�Ӷ�д�ĸ�
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
	//	 INTX_DISABLE();//�ر����е��ж�
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

	GPIO_SetBits(GPIOC,GPIO_Pin_0);//��λ�����ø�
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);//ƬѡCSʹ��
	dummy=SPI2_ReadWriteWord(0xBFC4);//����ConversionRegister
	GPIO_SetBits(GPIOA,GPIO_Pin_0);//ƬѡCSʧ��		
	for(i=0;i<10;i++)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);//ƬѡCSʹ��
		delay_us(10);
		AD8028[i].Word=SPI2_ReadWriteWord(0x0000);		
        GPIO_SetBits(GPIOA,GPIO_Pin_0);//ƬѡCSʧ��			
	}
    AD8028WorkWell=~AD8028WorkWell;
	if(AD8028WorkWell) 
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
	else 
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);//��˸��ʾADC��������	
} 


u8 rs485_tx_start = 0; 
void U485_process_data(TOBJ7000 *OUT_GENERIC,TOBJ6000 *IN_GENERIC)
{
	   u16 i;
	 	rs485_tx_start = 1; 
	//��ʾ���������ˢ�����������
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
//	IN_GENERIC->Analog_Voltage_Inputs_channel1 = (AD8028[1].Word)*42/15;//10�����õ�AI42 15
//	IN_GENERIC->Analog_Voltage_Inputs_channel2 = ((AD8028[2].Word)&0x0fff)*42/15;
//	IN_GENERIC->Analog_Voltage_Inputs_channel3 = ((AD8028[3].Word)&0x0fff)*42/15;//10�����õ�AI
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
            Ӳ����ʼ������������ɵ������涨����һ��intmask�Ķ���
*////////////////////////////////////////////////////////////////////////////////////////
BOOL inputresult = 0;
UINT8 HW_Init(void)
{
	u32 intMask;
	u32 rs485_br[1];
	u32 can_br[1];
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	
	delay_init(168);                               //��ʼ����ʱ����
	LED_Init();				                             //��ʼ��LED 	
	DO_Init();									                   //��ʼ��DO
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
		/* 8 channel DI, ȡ�����Ǻ�����߼�����ʱ���յ��ߵ�ƽ����1���͵�ƽ����0 */
		inputresult=~input_filter(ST_IN4_I0_0,(uint16_t *)&a0,6,2,(BOOL *)&b0);
		inputresult=~input_filter(ST_IN3_I0_1,(uint16_t *)&a1,6,2,(BOOL *)&b1);
		inputresult=~input_filter(ST_IN2_I0_2,(uint16_t *)&a2,6,2,(BOOL *)&b2);
		inputresult=~input_filter(ST_IN1_I0_3,(uint16_t *)&a3,6,2,(BOOL *)&b3);
		inputresult=~input_filter(ST_IN5_I1_0,(uint16_t *)&a4,6,2,(BOOL *)&b4);
		inputresult=~input_filter(ST_IN6_I1_1,(uint16_t *)&a5,6,2,(BOOL *)&b5);
		inputresult=~input_filter(ST_IN7_I1_2,(uint16_t *)&a6,6,2,(BOOL *)&b6);
		inputresult=~input_filter(ST_IN8_I1_3,(uint16_t *)&a7,6,2,(BOOL *)&b7);
		
		/* 8 channel Function/User DI, ȡ�����Ǻ�����߼�����ʱ���յ��ߵ�ƽ����1���͵�ƽ����0 */
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


  //��EEPROM�ж�ȡ485������
	STMFLASH_Read(FLASH_SAVE_ADDR_baud,(u32*)rs485_br,1);
	if((rs485_br[0]!= 1200)&&(rs485_br[0]!= 2400)&&(rs485_br[0]!= 4800)&&(rs485_br[0]!= 9600)&&(rs485_br[0]!= 14400)&&(rs485_br[0]!= 19200)&&(rs485_br[0]!= 38400)\
		&&(rs485_br[0]!= 56000)&&(rs485_br[0]!= 57600)&&(rs485_br[0]!= 115200)&&(rs485_br[0]!= 128000)&&(rs485_br[0]!= 256000))
	{
    rs485_br[0] = 115200;
		
	}	
		RS485_Init(rs485_br[0]);
	
	 //��EEPROM�ж�ȡCAN������
	 STMFLASH_Read(FLASH_SAVE_ADDR_baud + 4,(u32*)can_br,1);
	if((can_br[0]!= 10)&&(can_br[0]!= 20)&&(can_br[0]!= 50)&&(can_br[0]!= 100)&&(can_br[0]!= 125)&&(can_br[0]!= 250)&&(can_br[0]!= 500)\
		&&(can_br[0]!= 1000))
	{
    can_br[0] = 500;
		
	}	
  CAN_Configuration(can_br[0]); 
	
	SPIHW_Init();			                        //SPI3��ʼ��

  GPIO_ResetBits(GPIOF,GPIO_Pin_5);
	delay_ms(2);
	GPIO_SetBits(GPIOF,GPIO_Pin_5);
	do
	{
			intMask = 0x93;
			HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
			intMask = 0;
			HW_EscReadDWord(intMask, ESC_AL_EVENTMASK_OFFSET);//��仰����˵��һ��Ҫ�����0x204�Ĵ�������0x093���� 10010011���淭����0x204����Ĵ�����һ��
	} while (intMask != 0x93);//����Ĵ������ǹ����ж����ε�����ģ�����˵������������ڵ�bit0��bit1��bit4��bit7�����ĸ��ǲ����Ե� ����Ϊ��������Ӧ�ļĴ���Ϊ0ʱ//
/*�Żᴥ�������ж��źţ�Ҳ����˵��2��3��5��6���ĸ��ǻ�����ж��źţ�����Ҫ��1��4λ���ǲ��ò�ѯ�ķ�ʽ���������ж�*/

	intMask = 0x00;
	HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);//����൱�ڰ��жϵ�0220�Ĵ��������ˣ���ʼ����

//	 EXTI1_Init();                  //��ʼ��ESC�ж�
	 EXTI2_Init();                  // ��ʼ��ͬ���ж��ź�0                    
	 EXTI3_Init();                  // ��ʼ��ͬ���ж��ź�1
	TIM2_Int_Init(10-1,8400-1);
//	TIM4_Int_Init(1000-1,84-1);  // DCʱ�ӡ���ʼ��ECAT��ʱ�� ��TIM4��APB1��ʱ����84M������84��Ƶ֮��ͱ�Ϊ1MHz��Ҳ��������1us������1000������1ms
	 INTX_ENABLE();

	return 0;
}

 


