#ifndef __BSP__RTOS__H__
#define __BSP__RTOS__H__

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

uint8_t createTask(TaskFunction_t pxTaskCode,const char * const pcName, 
                            const configSTACK_DEPTH_TYPE usStackDepth,
                            void * const pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t * const pxCreatedTask);

#endif
