/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx.h"
#include "stm32f4xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

/*
 * Exported functions
 *
 */ 
void NEC_Decoder_Init(void);


/*
 * Exported constants
 *
 */ 
#define RAM_Start_Adress                   0x20000000      


/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
#endif
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

// Functions for LED control
//
#define         Set_Green                  LL_GPIO_SetOutputPin(Green_Port, Green_Pin);
#define         Set_Orange                 LL_GPIO_SetOutputPin(Orange_Port, Orange_Pin);
#define         Set_Red                    LL_GPIO_SetOutputPin(Red_Port, Red_Pin);
#define         Set_Blue                   LL_GPIO_SetOutputPin(Blue_Port, Blue_Pin);
  
#define         Reset_Green                LL_GPIO_ResetOutputPin(Green_Port, Green_Pin);
#define         Reset_Orange               LL_GPIO_ResetOutputPin(Orange_Port, Orange_Pin);
#define         Reset_Red                  LL_GPIO_ResetOutputPin(Red_Port, Red_Pin);
#define         Reset_Blue                 LL_GPIO_ResetOutputPin(Blue_Port, Blue_Pin);

#define         Toggle_Green               LL_GPIO_TogglePin(Green_Port, Green_Pin);
#define         Toggle_Orange              LL_GPIO_TogglePin(Orange_Port, Orange_Pin);
#define         Toggle_Red                 LL_GPIO_TogglePin(Red_Port, Red_Pin);
#define         Toggle_Blue                LL_GPIO_TogglePin(Blue_Port, Blue_Pin);

// LEDs defines
//
#define         Green_Port                 GPIOD
#define         Green_Pin                  LL_GPIO_PIN_12

#define         Orange_Port                GPIOD
#define         Orange_Pin                 LL_GPIO_PIN_13

#define         Red_Port                   GPIOD
#define         Red_Pin                    LL_GPIO_PIN_14

#define         Blue_Port                  GPIOD
#define         Blue_Pin                   LL_GPIO_PIN_15


#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
