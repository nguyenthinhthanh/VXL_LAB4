/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define ERROR_0_Pin GPIO_PIN_0
#define ERROR_0_GPIO_Port GPIOB
#define ERROR_1_Pin GPIO_PIN_1
#define ERROR_1_GPIO_Port GPIOB
#define ERROR_2_Pin GPIO_PIN_2
#define ERROR_2_GPIO_Port GPIOB
#define LED_PB13_Pin GPIO_PIN_13
#define LED_PB13_GPIO_Port GPIOB
#define LED_PB14_Pin GPIO_PIN_14
#define LED_PB14_GPIO_Port GPIOB
#define LED_PB15_Pin GPIO_PIN_15
#define LED_PB15_GPIO_Port GPIOB
#define ERROR_3_Pin GPIO_PIN_3
#define ERROR_3_GPIO_Port GPIOB
#define ERROR_4_Pin GPIO_PIN_4
#define ERROR_4_GPIO_Port GPIOB
#define ERROR_5_Pin GPIO_PIN_5
#define ERROR_5_GPIO_Port GPIOB
#define ERROR_6_Pin GPIO_PIN_6
#define ERROR_6_GPIO_Port GPIOB
#define ERROR_7_Pin GPIO_PIN_7
#define ERROR_7_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

// Comment this line out if error reporting isNOT required
#define SCH_REPORT_ERRORS
//Where error reporting is required, the port onwhich error codes will be displayed
//is also determined viamain.h:
#ifdef SCH_REPORT_ERRORS
// The port onwhich error codes will be displayed
//ONLYUSEDIFERRORSAREREPORTED
#define Error_port GPIOB
#endif

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
