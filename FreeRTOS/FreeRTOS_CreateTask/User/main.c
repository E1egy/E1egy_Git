#include <stm32f10x.h>
#include "stm32f10x_conf.h"
#include "stm32f10x_rcc.h"

#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_key.h"
#include "bsp_rtos.h"
RCC_ClocksTypeDef RCC_Clocks;

int main(void)
{
    USART1_Init(9600);
    Led_Init(); // 初始化 LED
    key_init();
    
    // 查询时钟频率
    RCC_GetClocksFreq(&RCC_Clocks);
    
    
    
      // 创建 LED 控制任务
    if (createTask_Led() != 1)
    {
        printf("LED Task creation failed\n");
    }

    // 创建按键任务
    if (createTask_Key() != 1)
    {
        printf("Key Task creation failed\n");
    }


    vTaskStartScheduler(); // 启动任务调度, 任务开始运行（AppTask）
    
    while (1)
    {

    } // 正常情况下不会执行到这里
}
