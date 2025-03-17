#include "bsp_pwm.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
void PWM_init()
{
    // 开启定时器2时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // 开启GPIOB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // 先设置定时器
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
    
    // 设置输出捕获
    TIM_OCInitTypeDef TIM_OCStructure;

    


    // // 配置 PWM TIM_ICInitTypeDef
    // TIM_ICInitTypeDef tim_icinittypedef;
    // tim_icinittypedef.TIM_Channel = TIM_Channel_2;                      // 选择通道
    // tim_icinittypedef.TIM_ICFilter = 0x03;                              // 抗干扰 滤波器
    // tim_icinittypedef.TIM_ICPolarity = TIM_ICPolarity_Rising;           // 捕获极性
    // tim_icinittypedef.TIM_ICPrescaler = TIM_ICPSC_DIV4;            // 分频器
    // tim_icinittypedef.TIM_ICSelection = TIM_ICSelection_DirectTI;       // 


      
    
    // 初始化
    //TIM_PWMIConfig(TIM2, &TIM_OCStructure);




    // 部分重映射  PB3
    GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);
  

}