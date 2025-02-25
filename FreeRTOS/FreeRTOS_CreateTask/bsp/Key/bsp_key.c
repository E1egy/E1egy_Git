#include "bsp_key.h"
#include "bsp_led.h"
#include "FreeRTOS.h"
#include "task.h"
#include "bsp_rtos.h"

TaskHandle_t AppTask_Handle_Key = NULL;
TaskHandle_t AppTask_Handle = NULL;

typedef struct 
{
    int frequency;  // ��˸Ƶ��
    char* message;  // ��Ϣ
} TaskParameters;

TaskParameters params = {1000, "LED Blinking"};

void key_init()
{
    // ����ʱ��
    RCC_APB2PeriphClockCmd(KEY_1_CLK, ENABLE);
    
    GPIO_InitTypeDef key_gpio_typedef;
    
    // Ĭ���������룬Ĭ�ϵ͵�ƽ
    key_gpio_typedef.GPIO_Mode = GPIO_Mode_IPD; // ������ʹĬ�ϵ͵�ƽ
    key_gpio_typedef.GPIO_Pin = KEY_1_Pin;
    key_gpio_typedef.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &key_gpio_typedef);
    
    // Ĭ���������룬Ĭ�ϸߵ�ƽ
    key_gpio_typedef.GPIO_Mode = GPIO_Mode_IPU;
    key_gpio_typedef.GPIO_Pin = KEY_2_Pin | KEY_3_Pin;
    key_gpio_typedef.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &key_gpio_typedef);    
    
    
    // �����ⲿ�ж�
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    EXTI_InitTypeDef key_inittypedef;
    key_inittypedef.EXTI_Line = EXTI_Line0;
    key_inittypedef.EXTI_LineCmd = ENABLE;
    key_inittypedef.EXTI_Mode = EXTI_Mode_Interrupt;
    key_inittypedef.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&key_inittypedef);
    
    // ����NVIC�ж�������
    NVIC_InitTypeDef key_nvic;
    key_nvic.NVIC_IRQChannel = EXTI0_IRQn; 
    key_nvic.NVIC_IRQChannelCmd = ENABLE;
    key_nvic.NVIC_IRQChannelPreemptionPriority = 0;
    key_nvic.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&key_nvic);
}


// �ⲿ�жϴ���
void EXTI0_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    if(EXTI_GetITStatus(EXTI_Line0) != RESET)
    {
        // ͨ�����������ISR����֪ͨһ�������������� AppTask_Handle_Key�������Ὣ�����֪ͨ����������1��ͨ����������ȴ�ĳ���¼����źŵ��龳��
        vTaskNotifyGiveFromISR(AppTask_Handle_Key, &xHigherPriorityTaskWoken);
        printf("EXTI����������������������������������������\n");
        EXTI_ClearFlag(EXTI_Line0);
    };
}

static void AppTask_Key(void *parameter)
{
    while(1)
    {
        // �ú�������������ֱ����ISR���յ�֪ͨ�������pdTRUE��ʾ������յ�֪ͨ��֪ͨ�������ᱻ���㡣
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        printf("Enter the FreeRTOS interrupt handler");
    }       
}

static void AppTask(void *parameter)
{
    // ������Ĳ���ת��Ϊ TaskParameters �ṹ��ָ��
    TaskParameters *params = (TaskParameters *)parameter;
    while (1)
    {
        LED_BLUE_OFF;
        vTaskDelay(pdMS_TO_TICKS(1000)); // ��ʱ500����
        LED_BLUE_ON;
        vTaskDelay(pdMS_TO_TICKS(1000)); // ��ʱ500����
        printf("%d\n", params -> frequency);
    }
}


uint8_t createTask_Key()
{
    uint8_t Task_state = 0;
    Task_state = createTask(AppTask_Key, "AppTask_Key", 60, NULL, 1, &AppTask_Handle_Key);
    Task_state = createTask( AppTask,              // ������ں���
                            "AppTask",             // ��������
                              60,                   // ����ջ��С
                              &params,              // ������ں�������
                              2,                    // ��������ȼ�
                              &AppTask_Handle);     // ������ƿ�ָ��    
    if(Task_state == pdPASS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



