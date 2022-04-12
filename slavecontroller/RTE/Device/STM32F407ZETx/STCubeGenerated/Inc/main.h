/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SPIDriver.h"
#include "9252_HW.h"
#include "ecatappl.h"
#include "applInterface.h"
#include "ADS1115Driver.h"
#include "Command.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SYNC0_Pin GPIO_PIN_2
#define SYNC0_GPIO_Port GPIOE
#define SYNC0_EXTI_IRQn EXTI2_IRQn
#define SYNC1_Pin GPIO_PIN_3
#define SYNC1_GPIO_Port GPIOE
#define SYNC1_EXTI_IRQn EXTI3_IRQn
#define AI_IU_SW1_Pin GPIO_PIN_6
#define AI_IU_SW1_GPIO_Port GPIOE
#define V24V_OUT4_Pin GPIO_PIN_2
#define V24V_OUT4_GPIO_Port GPIOF
#define LED6_Pin GPIO_PIN_3
#define LED6_GPIO_Port GPIOF
#define PHY_RESET_Pin GPIO_PIN_4
#define PHY_RESET_GPIO_Port GPIOF
#define ET_RESETN_Pin GPIO_PIN_5
#define ET_RESETN_GPIO_Port GPIOF
#define LED3_Pin GPIO_PIN_8
#define LED3_GPIO_Port GPIOF
#define LED4_Pin GPIO_PIN_9
#define LED4_GPIO_Port GPIOF
#define LED5_Pin GPIO_PIN_10
#define LED5_GPIO_Port GPIOF
#define IRQ_Pin GPIO_PIN_1
#define IRQ_GPIO_Port GPIOA
#define IRQ_EXTI_IRQn EXTI1_IRQn
#define RS485_RE_Pin GPIO_PIN_4
#define RS485_RE_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_5
#define LED1_GPIO_Port GPIOC
#define AI_IU_SW2_Pin GPIO_PIN_1
#define AI_IU_SW2_GPIO_Port GPIOB
#define SAFE_48V_SWITCH_Pin GPIO_PIN_11
#define SAFE_48V_SWITCH_GPIO_Port GPIOF
#define POWER24V_ON_Pin GPIO_PIN_12
#define POWER24V_ON_GPIO_Port GPIOF
#define ES_SHUTDOWN_Pin GPIO_PIN_13
#define ES_SHUTDOWN_GPIO_Port GPIOF
#define ACPower_OK_Pin GPIO_PIN_1
#define ACPower_OK_GPIO_Port GPIOG
#define ST_OUT_24_Pin GPIO_PIN_10
#define ST_OUT_24_GPIO_Port GPIOE
#define ST_OUT_23_Pin GPIO_PIN_11
#define ST_OUT_23_GPIO_Port GPIOE
#define ST_OUT_22_Pin GPIO_PIN_12
#define ST_OUT_22_GPIO_Port GPIOE
#define ST_OUT_20_Pin GPIO_PIN_13
#define ST_OUT_20_GPIO_Port GPIOE
#define ST_OUT_21_Pin GPIO_PIN_14
#define ST_OUT_21_GPIO_Port GPIOE
#define POWEROFF_REMOTEIN_Pin GPIO_PIN_15
#define POWEROFF_REMOTEIN_GPIO_Port GPIOE
#define ST_OUT_19_Pin GPIO_PIN_12
#define ST_OUT_19_GPIO_Port GPIOB
#define ST_OUT_18_Pin GPIO_PIN_13
#define ST_OUT_18_GPIO_Port GPIOB
#define ST_OUT_17_Pin GPIO_PIN_14
#define ST_OUT_17_GPIO_Port GPIOB
#define ST_OUT_8_Pin GPIO_PIN_15
#define ST_OUT_8_GPIO_Port GPIOB
#define ST_OUT_7_Pin GPIO_PIN_8
#define ST_OUT_7_GPIO_Port GPIOD
#define ST_OUT_6_Pin GPIO_PIN_9
#define ST_OUT_6_GPIO_Port GPIOD
#define ST_OUT_5_Pin GPIO_PIN_10
#define ST_OUT_5_GPIO_Port GPIOD
#define ST_IN_23_Pin GPIO_PIN_11
#define ST_IN_23_GPIO_Port GPIOD
#define ST_IN_22_Pin GPIO_PIN_12
#define ST_IN_22_GPIO_Port GPIOD
#define ST_IN_21_Pin GPIO_PIN_13
#define ST_IN_21_GPIO_Port GPIOD
#define ST_IN_24_Pin GPIO_PIN_14
#define ST_IN_24_GPIO_Port GPIOD
#define ST_IN_20_Pin GPIO_PIN_15
#define ST_IN_20_GPIO_Port GPIOD
#define ST_IN_19_Pin GPIO_PIN_2
#define ST_IN_19_GPIO_Port GPIOG
#define ST_IN_18_Pin GPIO_PIN_3
#define ST_IN_18_GPIO_Port GPIOG
#define LAN9252_CS_Pin GPIO_PIN_4
#define LAN9252_CS_GPIO_Port GPIOG
#define ST_IN_17_Pin GPIO_PIN_5
#define ST_IN_17_GPIO_Port GPIOG
#define ST_OUT_4_Pin GPIO_PIN_6
#define ST_OUT_4_GPIO_Port GPIOG
#define ST_OUT_3_Pin GPIO_PIN_7
#define ST_OUT_3_GPIO_Port GPIOG
#define ST_OUT_2_Pin GPIO_PIN_8
#define ST_OUT_2_GPIO_Port GPIOG
#define ST_OUT_1_Pin GPIO_PIN_8
#define ST_OUT_1_GPIO_Port GPIOC
#define ST_IN_8_Pin GPIO_PIN_6
#define ST_IN_8_GPIO_Port GPIOD
#define ST_IN_7_Pin GPIO_PIN_7
#define ST_IN_7_GPIO_Port GPIOD
#define ST_IN_6_Pin GPIO_PIN_9
#define ST_IN_6_GPIO_Port GPIOG
#define ST_IN_5_Pin GPIO_PIN_10
#define ST_IN_5_GPIO_Port GPIOG
#define ST_IN_1_Pin GPIO_PIN_11
#define ST_IN_1_GPIO_Port GPIOG
#define ST_IN_2_Pin GPIO_PIN_12
#define ST_IN_2_GPIO_Port GPIOG
#define ST_IN_3_Pin GPIO_PIN_13
#define ST_IN_3_GPIO_Port GPIOG
#define ST_IN_4_Pin GPIO_PIN_14
#define ST_IN_4_GPIO_Port GPIOG
#define POWERON_REMOTEIN_Pin GPIO_PIN_8
#define POWERON_REMOTEIN_GPIO_Port GPIOB
#define V24V_OUT1_Pin GPIO_PIN_9
#define V24V_OUT1_GPIO_Port GPIOB
#define POWERON_KEYIN_Pin GPIO_PIN_0
#define POWERON_KEYIN_GPIO_Port GPIOE
#define OC_PROTECT_Pin GPIO_PIN_1
#define OC_PROTECT_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
