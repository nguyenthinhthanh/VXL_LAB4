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
#define SEG13_A_Pin GPIO_PIN_0
#define SEG13_A_GPIO_Port GPIOA
#define SEG13_B_Pin GPIO_PIN_1
#define SEG13_B_GPIO_Port GPIOA
#define SEG13_C_Pin GPIO_PIN_2
#define SEG13_C_GPIO_Port GPIOA
#define SEG13_D_Pin GPIO_PIN_3
#define SEG13_D_GPIO_Port GPIOA
#define SEG13_E_Pin GPIO_PIN_4
#define SEG13_E_GPIO_Port GPIOA
#define SEG13_F_Pin GPIO_PIN_5
#define SEG13_F_GPIO_Port GPIOA
#define SEG13_G_Pin GPIO_PIN_6
#define SEG13_G_GPIO_Port GPIOA
#define SEG24_A_Pin GPIO_PIN_7
#define SEG24_A_GPIO_Port GPIOA
#define SEG24_B_Pin GPIO_PIN_8
#define SEG24_B_GPIO_Port GPIOA
#define SEG24_C_Pin GPIO_PIN_9
#define SEG24_C_GPIO_Port GPIOA
#define SEG24_D_Pin GPIO_PIN_10
#define SEG24_D_GPIO_Port GPIOA
#define SEG24_E_Pin GPIO_PIN_11
#define SEG24_E_GPIO_Port GPIOA
#define SEG24_F_Pin GPIO_PIN_12
#define SEG24_F_GPIO_Port GPIOA
#define SEG24_G_Pin GPIO_PIN_13
#define SEG24_G_GPIO_Port GPIOA
#define LED13_RED_Pin GPIO_PIN_3
#define LED13_RED_GPIO_Port GPIOB
#define LED13_YELLOW_Pin GPIO_PIN_4
#define LED13_YELLOW_GPIO_Port GPIOB
#define LED13_GREEN_Pin GPIO_PIN_5
#define LED13_GREEN_GPIO_Port GPIOB
#define LED24_RED_Pin GPIO_PIN_6
#define LED24_RED_GPIO_Port GPIOB
#define LED24_YELLOW_Pin GPIO_PIN_7
#define LED24_YELLOW_GPIO_Port GPIOB
#define LED24_GREEN_Pin GPIO_PIN_8
#define LED24_GREEN_GPIO_Port GPIOB

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
