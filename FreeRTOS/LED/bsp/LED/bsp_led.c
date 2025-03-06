/***********************************************************************************************************************************
 ** ���ļ����ơ�  led.c
 ** ����д��Ա��  ħŮ�������Ŷ�
 ** ����    ����  ħŮ������      https://demoboard.taobao.com
 ***********************************************************************************************************************************
 ** ���ļ����ܡ�  ʵ��LEDָʾ�Ƴ��õĳ�ʼ�����������ܺ���
 **                 
 ** ����ֲ˵����  
 **             
 ** �����¼�¼��  
 **
***********************************************************************************************************************************/  
#include "bsp_led.h"
#include "FreeRTOS.h"
#include "task.h"
#include "bsp_rtos.h"

TaskHandle_t AppTask_Handle_Led = NULL;

void Led_Init(void)
{    
    GPIO_InitTypeDef GPIO_InitStructure;                    // ����һ��GPIO_InitTypeDef���͵Ľṹ��
    
    // ʹ��LED_RED�������Ŷ˿�ʱ��;ʹ�ö˿��жϵķ���ʹ��ʱ��, ��ʹ������ֲ������
    if(LED_RED_GPIO == GPIOA)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
    if(LED_RED_GPIO == GPIOB)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
    if(LED_RED_GPIO == GPIOC)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
    if(LED_RED_GPIO == GPIOD)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);
    if(LED_RED_GPIO == GPIOE)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE , ENABLE);
    if(LED_RED_GPIO == GPIOF)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF , ENABLE);
    if(LED_RED_GPIO == GPIOG)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF , ENABLE);
    // ʹ��LED_RED�������Ŷ˿�ʱ��;ʹ�ö˿��жϵķ���ʹ��ʱ��, ��ʹ������ֲ������
    if(LED_BLUE_GPIO == GPIOA)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
    if(LED_BLUE_GPIO == GPIOB)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
    if(LED_BLUE_GPIO == GPIOC)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
    if(LED_BLUE_GPIO == GPIOD)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);
    if(LED_BLUE_GPIO == GPIOE)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE , ENABLE);
    if(LED_BLUE_GPIO == GPIOF)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF , ENABLE);
    if(LED_BLUE_GPIO == GPIOG)  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF , ENABLE);
    
    // ����LED_RED���Ź���ģʽ
    GPIO_InitStructure.GPIO_Pin   = LED_RED_PIN;            // ѡ��Ҫ���Ƶ�GPIO����       
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;       // ��������ģʽΪͨ���������   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       // ������������Ϊ50MHz            
    GPIO_Init(LED_RED_GPIO , &GPIO_InitStructure);          // ���ÿ⺯������ʼ��GPIO  
    
    // ����LED_RED���Ź���ģʽ
    GPIO_InitStructure.GPIO_Pin   = LED_BLUE_PIN;           // ѡ��Ҫ���Ƶ�GPIO����       
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;       // ��������ģʽΪͨ���������   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       // ������������Ϊ50MHz            
    GPIO_Init(LED_BLUE_GPIO , &GPIO_InitStructure);         // ���ÿ⺯������ʼ��GPIO    
    
    LED_RED_GPIO -> BRR = LED_RED_PIN ;                     // ����LED_RED�� �͵�ƽ����
    LED_BLUE_GPIO ->BRR = LED_BLUE_PIN ;                    // ����LED_BLUE���͵�ƽ����             

}

static void AppTask_Led(void *parameter)
{
    while(1)
    {
        LED_RED_OFF;                    // Ϩ���ɫ LED
        vTaskDelay(pdMS_TO_TICKS(500)); // ��ʱ500����
        LED_RED_ON;                     // ������ɫ LED
        
        vTaskDelay(pdMS_TO_TICKS(500)); // ��ʱ500����
        printf("%s\n", "���");
    }
}

uint8_t createTask_Led()
{
    uint8_t Task_state = 0;
    Task_state = createTask(AppTask_Led, "AppTask_Led", 60, NULL, 1, &AppTask_Handle_Led);
    
    if(Task_state == pdPASS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

