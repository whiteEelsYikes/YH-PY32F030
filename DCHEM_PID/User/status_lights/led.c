#include "led.h"

int led(void)
{
	
  __HAL_RCC_GPIOA_CLK_ENABLE(); // 启用GPIOA时钟

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // 推挽输出模式
    GPIO_InitStruct.Pull = GPIO_NOPULL; // 无上拉下拉
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // 低速
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
return 0;
}


