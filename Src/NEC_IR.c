/*******************************************************************************
********************************************************************************
***                                                                          ***
***     Name    -       IR Remote Controler NEC Decoder                      ***
***     Author  -       Noureddine AWLED BRAHIM                              ***
***     File    -       NEC_IR.c                                             ***
***                                                                          ***
********************************************************************************
*******************************************************************************/

#include "NEC_IR.h"

/* General System Init Function
 *
 */
void NEC_Decoder_Init(void)
{
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  SystemClock_Config();

  GPIO_Init();

  NEC_Timer_Init();
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);

  if (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_2)
  {
    Error_Handler();
  }

  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  LL_RCC_HSE_Enable();

  // Wait till HSE is ready
  while (LL_RCC_HSE_IsReady() != 1)
  {
  };

  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_4, 64, LL_RCC_PLLP_DIV_2);
  LL_RCC_PLL_Enable();

  // Wait till PLL is ready
  while (LL_RCC_PLL_IsReady() != 1)
  {
  };

  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

  // Wait till System clock is ready
  while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  };

  LL_Init1msTick(64000000);
  LL_SetSystemCoreClock(64000000);
}

/**
 * GPIO Initialization Function
 */
static void GPIO_Init(void)
{
  LL_EXTI_InitTypeDef EXTI_InitStruct = {0};
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  // GPIO Ports Clock Enable
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);

  LL_GPIO_ResetOutputPin(GPIOD, LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15 | LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15 | LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | LL_GPIO_PIN_4 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
  LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);

  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTC, LL_SYSCFG_EXTI_LINE1);

  EXTI_InitStruct.Line_0_31 = IR_RECEIVER_LINE;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  // Enable a pull-up resistor at the IR receiver's input pin
  LL_GPIO_SetPinPull(IR_RECEIVER_PORT, IR_RECEIVER_PIN, LL_GPIO_PULL_UP);

  // Configure the IR pin as an input
  LL_GPIO_SetPinMode(IR_RECEIVER_PORT, IR_RECEIVER_PIN, LL_GPIO_MODE_INPUT);

  // EXTI1_IRQn interrupt configuration
  NVIC_SetPriority(EXTI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 7, 0));
  NVIC_EnableIRQ(EXTI1_IRQn);
}

/**
 * Timer 3 Initialization Function
 */
static void NEC_Timer_Init(void)
{
}

/* This function returns the NEC
 * decoder to its initial state
 */
void NEC_Timer_IRQ_Handler(void)
{
}

/* This function handles
 * the IR receiver's output
 */
void NEC_External_IRQ_Handler(void)
{
  NVIC_ClearPendingIRQ(NEC_EXTI_IRQn);
  LL_EXTI_ClearFlag_0_31(IR_RECEIVER_LINE);

  Toggle_Orange
}
