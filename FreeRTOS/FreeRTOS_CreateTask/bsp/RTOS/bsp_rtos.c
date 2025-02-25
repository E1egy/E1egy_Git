#include "bsp_rtos.h"
#include "bsp_led.h"
/* 定义任务栈大小 */
#define TASK_STACK_SIZE configMINIMAL_STACK_SIZE // 这里你可以直接使用你的最小栈大小

// 任务控制块指针




BaseType_t xReturn = pdPASS; // 定义一个创建信息返回值，默认为 pdPASS(1)





uint8_t createTask(TaskFunction_t pxTaskCode,const char * const pcName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                            const configSTACK_DEPTH_TYPE usStackDepth,
                            void * const pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t * const pxCreatedTask)
{
    xTaskCreate(pxTaskCode,
                pcName,
                usStackDepth,
                pvParameters,
                uxPriority,
                pxCreatedTask);
    
    if (pdPASS == xReturn)
    {
        return 1;
      
    }
    else
    {
        return 0;
    }
}








//xReturn = xTaskCreate(AppTask,          // 任务入口函数
//                          "AppTask",        // 任务名字
//                          60,              // 任务栈大小
//                          &params,         // 任务入口函数参数
//                          2,                // 任务的优先级
//                          &AppTask_Handle); // 任务控制块指针
//    
//xReturn = xTaskCreate(AppTask_Led, "AppTask_Led", 60, str, 3, &AppTask_Handle2);
//xReturn = xTaskCreate(AppTask_Key, "AppTask_Key", 60, NULL, 1, &AppTask_Handle_Key);

