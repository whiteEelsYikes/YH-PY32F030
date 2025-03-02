#ifndef AT8236X_PWM_H
#define AT8236X_PWM_H

#include "py32f0xx_hal.h"


/*
  下面是定义驱动at8236x必要引脚相关的一些宏
*/
#define AT8236X_PWM_AIN1 pa7
#define AT8236X_PWM_AIN2 pa8
#define AT8236X_PWM_AnFAULT 0

#define AT8236X_PWM_BIN1 2
#define AT8236X_PWM_BIN2 3
#define AT8236X_PWM_BnFAULT 4


/*
  下面是定义驱动at8236x必要（pwm）驱动时序相关的一些宏
*/
#define AT8236X_PWM_MAX_FREQ_HZ    100000  // at8236x逻辑信号最大PWM频率，单位Hz
#define AT8236X_PWM_FREQ_HZ AT8236X_PWM_MAX_FREQ_HZ  // at8236x逻辑信号PWM频率，单位Hz
// #define AT8236X_PWM_TIMER_COUNT (TIMER_CLOCK_FREQUENCY / PWM_FREQ_HZ)  // 根据频率计算计数器值的宏
#define AT8236X_PWM_TDEAD_TIME_NS  250


// AT8236初始化函数
void at8236x_init(uint16_t Prescaler, uint16_t Period);

// AT8236 PWM设置函数
void at8236x_set_pwm(uint8_t channel, uint16_t dutyCycle);



// 电机控制针定义
#define MOTOR_PIN_CH1 GPIO_PIN_8
#define MOTOR_PIN_CH2 GPIO_PIN_3
#define MOTOR_PORT GPIOA

void Motor_Init(void);
void Motor_SetSpeed(uint16_t speed_ch1, uint16_t speed_ch2);


#endif /* AT8236X_PWM_H */
