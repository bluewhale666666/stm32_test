/*
 * PDIDriver.c
 *
 *  Created on: 2021Äê10ÔÂ8ÈÕ
 *      Author: siasun
 */

#include "PDIDriver.h"

static uint32_t LastPDITimer = 0u;
uint8_t PDI_Isr_enable = 0u;      /*0:enable; 1:disable*/
/*
 *  Function Name:  PDI_GetTimer
 *
 *  Company:    SIASUN CO., LTD.
 *
 *  Author: XiLiang
 *
 *  Modify:
 *      1st:
 *      2nd:
 *
 *  Description:    Read the current register value of hardware timer.
 *
 *  Inputs:
 *      none
 *
 *  Outputs:
 *      current register value of hardware timer
 *
 *  Configuration management history:
 *      Created:    2021-10-08
 *      1st Modified:
 *      2nd Modified:
 */
uint32_t PDI_GetTimer(void)
{
    uint32_t nowTime;
    uint32_t elapseTime;
    nowTime = HAL_GetTick();

    elapseTime = nowTime - LastPDITimer;

    return elapseTime;
}

/*
 *  Function Name:  PDI_GetTimer
 *
 *  Company:    SIASUN CO., LTD.
 *
 *  Author: XiLiang
 *
 *  Modify:
 *      1st:
 *      2nd:
 *
 *  Description:    Clear the current register value of hardware timer.
 *
 *  Inputs:
 *      none
 *
 *  Outputs:
 *      none
 *
 *  Configuration management history:
 *      Created:    2021-10-08
 *      1st Modified:
 *      2nd Modified:
 */
void PDI_ClearTimer(void)
{
    LastPDITimer = HAL_GetTick();
}


/*
 *  Function Name:  PDI_Disable_Global_interrupt
 *
 *  Company:    SIASUN CO., LTD.
 *
 *  Author: XiLiang
 *
 *  Modify:
 *      1st:
 *      2nd:
 *
 *  Description:    Disable global PDI interrupt
 *
 *  Inputs:
 *      1:  Disable Global Interrupt Manually, the condition to restore the interrupt shall the restore_intsts be clear to 0 manually
 *      0:  Disable Global Interrupt Manually, the condition to restore the interrupt is just to call PDI_Restore_Global_Interrupt()
 *
 *  Outputs:
 *      none
 *
 *  Configuration management history:
 *      Created:    2021-10-08
 *      1st Modified:
 *      2nd Modified:
 */
uint32_t PDI_Disable_Global_Interrupt(void)
{
		HAL_NVIC_DisableIRQ(EXTI1_IRQn);
		HAL_NVIC_DisableIRQ(EXTI2_IRQn);
		HAL_NVIC_DisableIRQ(EXTI3_IRQn);

    return 0u;
}


/*
 *  Function Name:  PDI_Enable_Global_interrupt
 *
 *  Company:    SIASUN CO., LTD.
 *
 *  Author: XiLiang
 *
 *  Modify:
 *      1st:
 *      2nd:
 *
 *  Description:    This routine enables the core to handle any pending interrupt requests.
 *
 *  Precondition:   Need to configure system using interrupt (IRQ, SYNC0 and SYNC1- if they are using)
 *
 *  Inputs:
 *      none
 *
 *  Outputs:
 *      none
 *
 *  Configuration management history:
 *      Created:    2021-10-08
 *      1st Modified:
 *      2nd Modified:
 */
void PDI_Enable_Global_interrupt(void)
{
		HAL_NVIC_EnableIRQ(EXTI1_IRQn);
		HAL_NVIC_EnableIRQ(EXTI2_IRQn);
		HAL_NVIC_EnableIRQ(EXTI3_IRQn);
}

/*
 *  Function Name:  PDI_IRQ_Interrupt
 *
 *  Company:    SIASUN CO., LTD.
 *
 *  Author: XiLiang
 *
 *  Modify:
 *      1st:
 *      2nd:
 *
 *  Description:    This function configure and enable the interrupt for IRQ
 *
 *  Inputs:
 *      none
 *
 *  Outputs:
 *      none
 *
 *  Configuration management history:
 *      Created:    2021-10-08
 *      1st Modified:
 *      2nd Modified:
 */
void PDI_IRQ_Interrupt(void)
{
		HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}

/*
 *  Function Name:  PDI_Restore_Global_Interrupt
 *
 *  Company:    SIASUN CO., LTD.
 *
 *  Author: XiLiang
 *
 *  Modify:
 *      1st:
 *      2nd:
 *
 *  Description:    This routine restores the core to the previous interrupt handling state.
 *
 *  Inputs:
 *      Int_sts      - the state of the previous interrupt handling state.
 *
 *  Outputs:
 *      none
 *
 *  Configuration management history:
 *      Created:    2021-10-08
 *      1st Modified:
 *      2nd Modified:
 */
void PDI_Restore_Global_Interrupt(uint32_t Int_sts)
{
    if (Int_sts == 0u)
    {
			PDI_Enable_Global_interrupt();
    }
}

void PDI_Init_SYNC_Interrupts(void)
{
    //already initialized in other module
}

void PDI_Timer_Interrupt(void)
{
    //already initialized in other module
}
