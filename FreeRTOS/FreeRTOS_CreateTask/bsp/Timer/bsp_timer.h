#ifndef _BSP_TIMER_H_
#define _BSP_TIMER_H_
#include "stm32f10x_tim.h"
#include "stdio.h"

void timer1_Init(void);
void SystemClock_Config(void);
uint32_t get_elapsed_time_us(void);
#endif
