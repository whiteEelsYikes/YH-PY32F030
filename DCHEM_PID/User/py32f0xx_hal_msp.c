/**
  ******************************************************************************
  * @file    py32f0xx_hal_msp.c
  * @author  MCU Application Team
  * @brief   This file provides code for the MSP Initialization
  *          and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h" 
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* External functions --------------------------------------------------------*/

/**
  * @brief ????????MSP
  */
void HAL_MspInit(void)
{
  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();
}



extern I2C_HandleTypeDef I2cHandle;
extern I2C_HandleTypeDef mpu6050;


void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_I2C_CLK_ENABLE();                                 /* I2C?????? */
	__HAL_RCC_GPIOA_CLK_ENABLE();                               /* GPIOA?????? */

	/**I2C ????????
	PA3     ------> I2C1_SCL
	PA2     ------> I2C1_SDA
	*/
	GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;                     /* ??? */
	GPIO_InitStruct.Pull = GPIO_PULLUP;                         /* ???? */
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF12_I2C;                   /* ?????I2C */
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);                     /* GPIO????? */
		
	if (hi2c == &I2cHandle){
		/*??λI2C*/
		__HAL_RCC_I2C_FORCE_RESET();
		__HAL_RCC_I2C_RELEASE_RESET();
		
		
		
		__HAL_RCC_SYSCFG_CLK_ENABLE();                              /* SYSCFG时钟使能 */
		__HAL_RCC_DMA_CLK_ENABLE();
		
		extern DMA_HandleTypeDef hdma_oled;
		
		hdma_oled.Instance                 = DMA1_Channel2;           /* 选择DMA通道1 */
		hdma_oled.Init.Direction           = DMA_MEMORY_TO_PERIPH;    /* 方向为从存储器到外设 */
		hdma_oled.Init.PeriphInc           = DMA_PINC_DISABLE;        /* 禁止外设地址增量 */
		hdma_oled.Init.MemInc              = DMA_MINC_ENABLE;         /* 使能存储器地址增量 */
		hdma_oled.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;     /* 外设数据宽度为8位 */
		hdma_oled.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;     /* 存储器数据宽度位8位 */
		hdma_oled.Init.Mode                = DMA_NORMAL;              /* 禁止循环模式 */
		hdma_oled.Init.Priority            = DMA_PRIORITY_VERY_HIGH;  /* 通道优先级为很高 */

		HAL_DMA_Init(&hdma_oled);                                     /* 初始化DMA通道1 */
		__HAL_LINKDMA(hi2c, hdmatx, hdma_oled);                       /* DMA1关联IIC_TX */
		
		/* I2C1中断初始化 */
		HAL_NVIC_SetPriority(I2C1_IRQn, 0, 0);                     /* 中断优先级设置 */
		HAL_NVIC_EnableIRQ(I2C1_IRQn);                              /* 使能I2C中断 */

		
		HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 0, 1);           /* 中断优先级设置 */
		HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);
		
		/* DMA配置请求映像 */
		/* DMA配置请求映像 */
		//  HAL_SYSCFG_DMA_Req(9);                                      /* DMA1_MAP选择为IIC_TX */
		HAL_SYSCFG_DMA_Req(0x0900);                                  /* DMA2_MAP选择为IIC_RX */
	}
	

	if(hi2c == &mpu6050){
		
		extern DMA_HandleTypeDef hdma_mpu6050;
		/*
			笑死，作为狗屎代码，这里就不考虑其他的了，这里必须先初始化oled，因为一些重复的配置操作在oled执行了，这边就懒得重新复制粘贴了
			不先初始化oled在初始化mpu6050就等着出问题吧，
			中断也是，py32f030的dma居然2和3通道是共用中断请求的，服了，罢了，摆烂了，mpu6050的中断在oled中执行，具体参考相关源代码
		*/
		
		hdma_mpu6050.Instance                 = DMA1_Channel3;           /* 选择DMA通道1 */
		hdma_mpu6050.Init.Direction           = DMA_PERIPH_TO_MEMORY;    /* 方向为从存储器到外设 */
		hdma_mpu6050.Init.PeriphInc           = DMA_PINC_DISABLE;        /* 禁止外设地址增量 */
		hdma_mpu6050.Init.MemInc              = DMA_MINC_ENABLE;         /* 使能存储器地址增量 */
		hdma_mpu6050.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;     /* 外设数据宽度为8位 */
		hdma_mpu6050.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;     /* 存储器数据宽度位8位 */
		hdma_mpu6050.Init.Mode                = DMA_NORMAL;              /* 禁止循环模式 */
		hdma_mpu6050.Init.Priority            = DMA_PRIORITY_VERY_HIGH;  /* 通道优先级为很高 */

		HAL_DMA_Init(&hdma_mpu6050);                                     /* 初始化DMA通道1 */
		__HAL_LINKDMA(hi2c, hdmarx, hdma_mpu6050);                       /* DMA1关联IIC_TX */
		
		/* I2C1中断初始化 */
		HAL_NVIC_SetPriority(I2C1_IRQn, 0, 0);                     /* 中断优先级设置 */
		HAL_NVIC_EnableIRQ(I2C1_IRQn);                              /* 使能I2C中断 */

		
		HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 0, 1);           /* 中断优先级设置 */
		HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);
		
		/* DMA配置请求映像 */
		/* DMA配置请求映像 */
//		HAL_SYSCFG_DMA_Req(0x90);                                      /* DMA1_MAP选择为IIC_TX */
		HAL_SYSCFG_DMA_Req(0xA0090);                                  /* DMA2_MAP选择为IIC_RX */
		
	}

}



