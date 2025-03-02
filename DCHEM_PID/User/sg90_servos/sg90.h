#ifndef SG90_H
#define SG90_H

#include "py32f0xx_hal.h"

// 定义全局变量
extern TIM_HandleTypeDef htim1;

// 函数原型声明
void SG90_Init(void);
void SG90_SetAngle(uint8_t angle);

#endif // SG90_H
