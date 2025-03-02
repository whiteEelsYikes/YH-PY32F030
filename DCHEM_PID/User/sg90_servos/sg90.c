#include "sg90.h"

// TIM16句柄
TIM_HandleTypeDef htim16;

// 获取TIM16时钟频率
uint32_t GetTIM16ClockFreq(void) {
    // 获取TIM16时钟频率的方式取决于具体的MCU，请根据具体情况进行调整
    // 这里假设时钟频率为系统时钟频率
    return HAL_RCC_GetSysClockFreq();
}

void SG90_Init(void) {
    // GPIO初始化
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    // 配置TIM16通道对应的GPIO
    GPIO_InitStruct.Pin = GPIO_PIN_6;  // 假设TIM16_CH1在PA6上，请根据具体MCU情况进行调整
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_TIM16;  // 根据具体MCU的替代功能选择，请进行调整
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 获取TIM16时钟频率
    uint32_t tim16ClockFreq = GetTIM16ClockFreq();

    // TIM16初始化
    __HAL_RCC_TIM16_CLK_ENABLE();
    htim16.Instance = TIM16;
    htim16.Init.Prescaler = (tim16ClockFreq / 1000000) - 1; // 设置PWM频率为1MHz基础
    htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim16.Init.Period = 19999; // 设置周期为20ms
    htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_PWM_Init(&htim16);

    // TIM16通道配置
    TIM_OC_InitTypeDef sConfigOC = {0};
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 1500;  // 初始脉冲宽度设置为1.5ms（90度）
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    
    HAL_TIM_PWM_ConfigChannel(&htim16, &sConfigOC, TIM_CHANNEL_1);  // TIM16只有一个通道

    HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
}

void SG90_SetAngle(uint8_t angle) {
    // 计算脉冲宽度
    uint16_t pulseWidth = 544 + ((uint16_t)angle * (2400 - 544) / 180);

    // 设置通道的脉冲宽度
    __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, pulseWidth);
}
