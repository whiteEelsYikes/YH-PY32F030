#include "py32f0xx_hal.h"
#include "MPU6050_Reg.h"    // MPU6050寄存器定义头文件

#define MPU6050_ADDRESS     0xD0  // MPU6050 I2C地址

I2C_HandleTypeDef mpu6050;  // 声明I2C句柄
DMA_HandleTypeDef hdma_mpu6050;


// 初始化I2C
void MPU6050_I2C_Init(void)
{
    mpu6050.Instance             = I2C;                       /* I2C */
    mpu6050.Mode                 = HAL_I2C_MODE_MASTER;       /* 主机模式 */
    mpu6050.Init.ClockSpeed      = 400000;            /* I2C通讯速度 */
    mpu6050.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;             /* I2C占空比 */
    mpu6050.Init.OwnAddress1     = MPU6050_ADDRESS;               /* I2C地址 */
    mpu6050.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;   /* 禁止广播呼叫 */
    mpu6050.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;     /* 允许时钟延长 */
    
    HAL_I2C_Init(&mpu6050);
}

extern I2C_HandleTypeDef I2cHandle;

// 向MPU6050寄存器写入数据
void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data)
{		
		while (HAL_I2C_GetState(&mpu6050) != HAL_I2C_STATE_READY){};
    HAL_I2C_Mem_Write(&mpu6050, MPU6050_ADDRESS, RegAddress, I2C_MEMADD_SIZE_8BIT, &Data, 1, HAL_MAX_DELAY);
//		HAL_I2C_Mem_Write_DMA(&I2cHandle, MPU6050_ADDRESS, RegAddress, I2C_MEMADD_SIZE_8BIT, &Data, 1);
//		/*判断当前I2C状态*/
//		while (HAL_I2C_GetState(&I2cHandle) != HAL_I2C_STATE_READY);
}


#include "../oled/oled.h"
// 从MPU6050寄存器读取数据
uint8_t MPU6050_ReadReg(uint8_t RegAddress)
{
    uint8_t Data;
		while (HAL_I2C_GetState(&mpu6050) != HAL_I2C_STATE_READY){};
//    HAL_I2C_Mem_Read(&mpu6050, MPU6050_ADDRESS, RegAddress, I2C_MEMADD_SIZE_8BIT, &Data, 1, HAL_MAX_DELAY);
		HAL_I2C_Mem_Read_DMA(&mpu6050, MPU6050_ADDRESS, RegAddress, I2C_MEMADD_SIZE_8BIT, &Data, 1);
//		while(1){OLED_Printf(0, 0, OLED_6X8, "Data: %d", Data);OLED_Update();};
		while (HAL_I2C_GetState(&mpu6050) != HAL_I2C_STATE_READY){};
    return Data;
}

// 初始化MPU6050
void MPU6050_Init(void)
{		
		while (HAL_I2C_GetState(&I2cHandle) != HAL_I2C_STATE_READY){};  // 等oled的I2cHandle的dma执行完，直接初始化会影响oled那边的操作
    MPU6050_I2C_Init();
    MPU6050_WriteReg(MPU6050_PWR_MGMT_1, 0x01);  // 解除睡眠模式
    MPU6050_WriteReg(MPU6050_PWR_MGMT_2, 0x00);  // 配置电源管理
    MPU6050_WriteReg(MPU6050_SMPLRT_DIV, 0x09);  // 设置采样率分频器
    MPU6050_WriteReg(MPU6050_CONFIG, 0x06);      // 设置低通滤波器
    MPU6050_WriteReg(MPU6050_GYRO_CONFIG, 0x18); // 配置陀螺仪
    MPU6050_WriteReg(MPU6050_ACCEL_CONFIG, 0x18); // 配置加速度计
}

// 读取MPU6050设备ID
uint8_t MPU6050_GetID(void)
{
    return MPU6050_ReadReg(MPU6050_WHO_AM_I);
}

// 获取MPU6050传感器数据
void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ, int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ)
{
    uint8_t DataH, DataL;

    // 读取加速度计X轴数据
    DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L);
    *AccX = (DataH << 8) | DataL;

    // 读取加速度计Y轴数据
    DataH = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L);
    *AccY = (DataH << 8) | DataL;

    // 读取加速度计Z轴数据
    DataH = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L);
    *AccZ = (DataH << 8) | DataL;

    // 读取陀螺仪X轴数据
    DataH = MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);
    *GyroX = (DataH << 8) | DataL;

    // 读取陀螺仪Y轴数据
    DataH = MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);
    *GyroY = (DataH << 8) | DataL;

    // 读取陀螺仪Z轴数据
    DataH = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);
    *GyroZ = (DataH << 8) | DataL;
}




#include <math.h>   // 包含math.h头文件以使用数学函数

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define DT 0.01      // 采样时间间隔，单位：秒
#define ALPHA 0.98   // 互补滤波系数

void MPU6050_GetAngle(float *AngleX, float *AngleY)
{
    int16_t AccX, AccY, AccZ;
    int16_t GyroX, GyroY, GyroZ;

    // 静态变量用于存储上一次计算的角度值
    static float angleX = 0, angleY = 0;

    // 获取传感器数据
    MPU6050_GetData(&AccX, &AccY, &AccZ, &GyroX, &GyroY, &GyroZ);

    // 计算加速度计倾斜角度（单位：度）
    float accAngleX = atan2f(AccY, sqrtf(AccX * AccX + AccZ * AccZ)) * 180 / M_PI;
    float accAngleY = atan2f(-AccX, sqrtf(AccY * AccY + AccZ * AccZ)) * 180 / M_PI;

    // 将陀螺仪数据转换为角速度（单位：度/秒）
    float gyroRateX = GyroX / 131.0;
    float gyroRateY = GyroY / 131.0;

    // 使用互补滤波器融合加速度计和陀螺仪数据
    angleX = ALPHA * (angleX + gyroRateX * DT) + (1 - ALPHA) * accAngleX;
    angleY = ALPHA * (angleY + gyroRateY * DT) + (1 - ALPHA) * accAngleY;

    // 更新输出角度值
    *AngleX = angleX;
    *AngleY = angleY;
}



