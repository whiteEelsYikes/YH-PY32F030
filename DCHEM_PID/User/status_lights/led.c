#include "led.h"

int led(void)
{
	
  __HAL_RCC_GPIOA_CLK_ENABLE(); // ����GPIOAʱ��

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // �������ģʽ
    GPIO_InitStruct.Pull = GPIO_NOPULL; // ����������
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // ����
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
return 0;
}


