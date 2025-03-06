#ifndef BSP_KEY_H
#define BSP_KEY_H

#include "stm32f10x_gpio.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stdio.h"


#define KEY_1_GPIO  GPIOA
#define KEY_2_GPIO  GPIOA
#define KEY_3_GPIO  GPIOA

#define KEY_1_Pin   GPIO_Pin_0
#define KEY_2_Pin   GPIO_Pin_1
#define KEY_3_Pin   GPIO_Pin_4

#define KEY_1_CLK   RCC_APB2Periph_GPIOA

void key_init(void);

uint8_t createTask_Key(void);

#endif
