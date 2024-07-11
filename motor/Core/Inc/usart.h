/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys.h"
#include "tim.h"
/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
#define   TIM_START_MOTOT1  	{HAL_TIM_PWM_Start(&htim10,TIM_CHANNEL_1);\
									HAL_TIM_PWM_Start(&htim11,TIM_CHANNEL_1);}
#define   TIM_START_MOTOT2  	{HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_1);\
									HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_2);}

#define   TIM_STOP_MOTOT1		{HAL_TIM_PWM_Stop(&htim10,TIM_CHANNEL_1);\
									HAL_TIM_PWM_Stop(&htim11,TIM_CHANNEL_1);}
#define   TIM_STOP_MOTOT2		{HAL_TIM_PWM_Stop(&htim9,TIM_CHANNEL_1);\
									HAL_TIM_PWM_Stop(&htim9,TIM_CHANNEL_2);}

extern uint16_t set_number;
/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

