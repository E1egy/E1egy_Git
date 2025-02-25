#include "bsp_timer.h"





void SystemClock_Config(void) 
{
    // 1. 复位RCC寄存器
    RCC_DeInit();

    // 2. 启动外部高速晶振（HSE）
    RCC_HSEConfig(RCC_HSE_ON);

    // 3. 等待HSE启动
    if (RCC_WaitForHSEStartUp() == SUCCESS) {
        // 4. 配置PLL
        // HSE（8MHz） -> PLL (8MHz / 1) * 9 = 72MHz
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);

        // 5. 启用PLL
        RCC_PLLCmd(ENABLE);

        // 6. 等待PLL稳定
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

        // 7. 选择PLL作为系统时钟源
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

        // 8. 配置AHB和APB时钟分频
        RCC_HCLKConfig(RCC_HCLK_Div1);  // AHB时钟 = SYSCLK
        RCC_PCLK1Config(RCC_HCLK_Div2); // APB1时钟 = AHB / 2
        RCC_PCLK2Config(RCC_HCLK_Div1); // APB2时钟 = AHB

        // 9. 更新系统时钟变量
        SystemCoreClockUpdate();
    }
}



void timer1_Init(void)
{
    // 使能APB1
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_TimeBaseInitTypeDef Tim_BaseStruct;
    Tim_BaseStruct.TIM_Prescaler = 35;
    Tim_BaseStruct.TIM_Period = 999; // 
    Tim_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;  // 向上计数
    Tim_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV2;  // 分频
    TIM_TimeBaseInit(TIM2, &Tim_BaseStruct);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    
    // 使能TIM2中断
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void) {
    // 检查更新事件中断是否发生
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
    {
        // 清除更新事件中断标志
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        printf("hello");
        // 在这里处理定时器中断，1秒触发一次
    }
}
 
uint32_t get_elapsed_time_us(void)
{
    // 读取定时器当前计数值   
   volatile uint32_t counter_value = TIM_GetCounter(TIM2);

    // 预分频器 + 1
    uint32_t prescaler_value = 35 + 1;

    // 计算经过的时间 (微秒)
   volatile uint32_t elapsed_time_us = (counter_value * prescaler_value) / (36);  // f_TIM = 36 MHz

    return elapsed_time_us;
}



