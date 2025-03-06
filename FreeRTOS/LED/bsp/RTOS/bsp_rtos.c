#include "bsp_rtos.h"
#include "bsp_led.h"
/* ��������ջ��С */
#define TASK_STACK_SIZE configMINIMAL_STACK_SIZE // ���������ֱ��ʹ�������Сջ��С

// ������ƿ�ָ��




BaseType_t xReturn = pdPASS; // ����һ��������Ϣ����ֵ��Ĭ��Ϊ pdPASS(1)





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








//xReturn = xTaskCreate(AppTask,          // ������ں���
//                          "AppTask",        // ��������
//                          60,              // ����ջ��С
//                          &params,         // ������ں�������
//                          2,                // ��������ȼ�
//                          &AppTask_Handle); // ������ƿ�ָ��
//    
//xReturn = xTaskCreate(AppTask_Led, "AppTask_Led", 60, str, 3, &AppTask_Handle2);
//xReturn = xTaskCreate(AppTask_Key, "AppTask_Key", 60, NULL, 1, &AppTask_Handle_Key);

