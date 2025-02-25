#include "bsp_key.h"
#include "FreeRTOS.h"
#include "task.h"


extern TaskHandle_t AppTask_Handle_Key;

void key_init()
{
    // 开启时钟
    RCC_APB2PeriphClockCmd(KEY_1_CLK, ENABLE);
    
    GPIO_InitTypeDef key_gpio_typedef;
    
    // 默认下拉输入，默认低电平
    key_gpio_typedef.GPIO_Mode = GPIO_Mode_IPD; // 下拉，使默认低电平
    key_gpio_typedef.GPIO_Pin = KEY_1_Pin;
    key_gpio_typedef.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &key_gpio_typedef);
    
    // 默认上拉输入，默认高电平
    key_gpio_typedef.GPIO_Mode = GPIO_Mode_IPU;
    key_gpio_typedef.GPIO_Pin = KEY_2_Pin | KEY_3_Pin;
    key_gpio_typedef.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &key_gpio_typedef);    
    
    
    // 配置外部中断
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    EXTI_InitTypeDef key_inittypedef;
    key_inittypedef.EXTI_Line = EXTI_Line0;
    key_inittypedef.EXTI_LineCmd = ENABLE;
    key_inittypedef.EXTI_Mode = EXTI_Mode_Interrupt;
    key_inittypedef.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&key_inittypedef);
    
    // 配置NVIC中断向量表
    NVIC_InitTypeDef key_nvic;
    key_nvic.NVIC_IRQChannel = EXTI0_IRQn; 
    key_nvic.NVIC_IRQChannelCmd = ENABLE;
    key_nvic.NVIC_IRQChannelPreemptionPriority = 0;
    key_nvic.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&key_nvic);
}


// 外部中断处理
void EXTI0_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    if(EXTI_GetITStatus(EXTI_Line0) != RESET)
    {
        // 通过这个函数，ISR可以通知一个任务（在这里是 AppTask_Handle_Key）。它会将任务的通知计数器增加1，通常用于任务等待某个事件或信号的情境。
        vTaskNotifyGiveFromISR(AppTask_Handle_Key, &xHigherPriorityTaskWoken);
        printf("EXTI！！！！！！！！！！！！！！！！！！！！\n");
        EXTI_ClearFlag(EXTI_Line0);
    };
}

