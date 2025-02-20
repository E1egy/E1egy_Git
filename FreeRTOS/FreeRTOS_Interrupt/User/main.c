#include <stm32f10x.h>
#include "stm32f10x_conf.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


#include "bsp_led.h"
#include "stm32f10x_rcc.h"
#include "bsp_usart.h"
#include "bsp_key.h"

RCC_ClocksTypeDef RCC_Clocks;
/* 定义任务栈大小 */
#define TASK_STACK_SIZE configMINIMAL_STACK_SIZE // 这里你可以直接使用你的最小栈大小


typedef struct 
{
    int frequency;  // 闪烁频率
    char* message;  // 消息
} TaskParameters;
TaskParameters params = {1000, "LED Blinking"};

static void AppTask(void *parameter)
{
    // 将传入的参数转换为 TaskParameters 结构体指针
    TaskParameters *params = (TaskParameters *)parameter;
    while (1)
    {
        LED_BLUE_OFF;
        vTaskDelay(pdMS_TO_TICKS(1000)); // 延时500毫秒
        LED_BLUE_ON;
        vTaskDelay(pdMS_TO_TICKS(1000)); // 延时500毫秒
        printf("%d\n", params -> frequency);
    }
}

static void AppTask_Led(void *parameter)
{
    while(1)
    {
        LED_RED_OFF;                    // 熄灭红色 LED
        vTaskDelay(pdMS_TO_TICKS(500)); // 延时500毫秒
        LED_RED_ON;                     // 点亮红色 LED
        
        vTaskDelay(pdMS_TO_TICKS(500)); // 延时500毫秒
        printf("%s\n", (char *)parameter);
    }
}

static void AppTask_Key(void *parameter)
{
    while(1)
    {
        if(GPIO_ReadInputDataBit(KEY_1_GPIO, KEY_1_Pin) == 0)
        {
            printf("0000000000000000000000000");
        }
        else
        {
            printf("1111111111111111111111111");
        }
        vTaskDelay(pdMS_TO_TICKS(500));  // 添加延时，防止任务阻塞其他任务
    }       
}

// 任务控制块指针
static TaskHandle_t AppTask_Handle = NULL;
static TaskHandle_t AppTask_Handle2 = NULL;
static TaskHandle_t AppTask_Handle_Key = NULL;

int main(void)
{
    USART1_Init(9600);
    Led_Init(); // 初始化 LED
    key_init();
    
    // 查询时钟频率
    RCC_GetClocksFreq(&RCC_Clocks);
    
    //为什么加静态？因为main参与了调度器的调度
    
    char *str = "Hello,World!";
    BaseType_t xReturn = pdPASS; // 定义一个创建信息返回值，默认为 pdPASS(1)
    
    /* 创建  任务  任务名称为AppTask*/
    xReturn = xTaskCreate(AppTask,          // 任务入口函数
                          "AppTask",        // 任务名字
                          60,              // 任务栈大小
                          &params,         // 任务入口函数参数
                          2,                // 任务的优先级
                          &AppTask_Handle); // 任务控制块指针
    
    xReturn = xTaskCreate(AppTask_Led, "AppTask_Led", 60, str, 3, &AppTask_Handle2);
    xReturn = xTaskCreate(AppTask_Key, "AppTask_Key", 60, NULL, 1, &AppTask_Handle_Key);
    /* 启动任务调度，如果创建任务成功则启动任务调度 */
    if (pdPASS == xReturn)
    {
        vTaskStartScheduler(); // 启动任务调度, 任务开始运行（AppTask）
    }
    else
    {
        return -1;
    }
    

    while (1)
    {

    } // 正常情况下不会执行到这里
}
