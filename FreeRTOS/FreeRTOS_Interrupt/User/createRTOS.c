#include "createRTOS.h"

void createAppTasks(void)
{
    BaseType_t xReturn = pdPASS; // 定义一个创建信息返回值，默认为 pdPASS

    /* 创建 AppTask 任务 */
    xReturn = xTaskCreate(AppTask,          // 任务入口函数
                          "AppTask",        // 任务名字
                          128,              // 任务栈大小
                          NULL,             // 任务入口函数参数
                          3,                // 任务的优先级
                          &AppTask_Handle); // 任务控制块指针

    /* 启动任务调度 */
    if (pdPASS == xReturn)
    {
        vTaskStartScheduler(); // 启动任务调度
    }
    else
    {
        return -1;
    }
}