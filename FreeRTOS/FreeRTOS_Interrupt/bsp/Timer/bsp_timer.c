#include "bsp_timer.h"





void SystemClock_Config(void) 
{
    // 1. ��λRCC�Ĵ���
    RCC_DeInit();

    // 2. �����ⲿ���پ���HSE��
    RCC_HSEConfig(RCC_HSE_ON);

    // 3. �ȴ�HSE����
    if (RCC_WaitForHSEStartUp() == SUCCESS) {
        // 4. ����PLL
        // HSE��8MHz�� -> PLL (8MHz / 1) * 9 = 72MHz
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);

        // 5. ����PLL
        RCC_PLLCmd(ENABLE);

        // 6. �ȴ�PLL�ȶ�
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

        // 7. ѡ��PLL��Ϊϵͳʱ��Դ
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

        // 8. ����AHB��APBʱ�ӷ�Ƶ
        RCC_HCLKConfig(RCC_HCLK_Div1);  // AHBʱ�� = SYSCLK
        RCC_PCLK1Config(RCC_HCLK_Div2); // APB1ʱ�� = AHB / 2
        RCC_PCLK2Config(RCC_HCLK_Div1); // APB2ʱ�� = AHB

        // 9. ����ϵͳʱ�ӱ���
        SystemCoreClockUpdate();
    }
}



void timer1_Init(void)
{
    // ʹ��APB1
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_TimeBaseInitTypeDef Tim_BaseStruct;
    Tim_BaseStruct.TIM_Prescaler = 35;
    Tim_BaseStruct.TIM_Period = 999; // 
    Tim_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;  // ���ϼ���
    Tim_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV2;  // ��Ƶ
    TIM_TimeBaseInit(TIM2, &Tim_BaseStruct);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    
    // ʹ��TIM2�ж�
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void) {
    // �������¼��ж��Ƿ���
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
    {
        // ��������¼��жϱ�־
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        printf("hello");
        // �����ﴦ��ʱ���жϣ�1�봥��һ��
    }
}
 
uint32_t get_elapsed_time_us(void)
{
    // ��ȡ��ʱ����ǰ����ֵ   
   volatile uint32_t counter_value = TIM_GetCounter(TIM2);

    // Ԥ��Ƶ�� + 1
    uint32_t prescaler_value = 35 + 1;

    // ���㾭����ʱ�� (΢��)
   volatile uint32_t elapsed_time_us = (counter_value * prescaler_value) / (36);  // f_TIM = 36 MHz

    return elapsed_time_us;
}



