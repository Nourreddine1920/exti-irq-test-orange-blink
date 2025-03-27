/*******************************************************************************
********************************************************************************
***                                                                          ***
***     Name    -       IR Remote Controler NEC Decoder                      ***
***     Author  -       Timofey Chashurin                                    ***
***     Date    -       10.07.2014                                           ***
***     File    -       NEC_IR.h                                             ***
***                                                                          ***
********************************************************************************
*******************************************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NEC_IR_H
#define __NEC_IR_H

#include "main.h"

/*
 * Exported functions
 */
void NEC_Decoder_Init(void);


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void GPIO_Init(void);
static void NEC_Timer_Init(void);

/*
 * Exported constants
 */ 
// NEC Decoder TypeDefs
#define         IR_RECEIVER_PORT           GPIOC
#define         IR_RECEIVER_PIN            LL_GPIO_PIN_1
#define         IR_RECEIVER_LINE           LL_EXTI_LINE_1 
#define         NEC_Timer                  TIM3
#define         RCC_APB_Periph_NEC_Timer   LL_APB1_GRP1_PERIPH_TIM3 
#define         NEC_Timer_IRQ_Handler      TIM3_IRQHandler 
#define         NEC_Timer_IRQn             TIM3_IRQn
#define         NEC_External_IRQ_Handler   EXTI1_IRQHandler
#define 	    NEC_EXTI_IRQn 	           EXTI1_IRQn


#endif /* __NEC_IR_H */
