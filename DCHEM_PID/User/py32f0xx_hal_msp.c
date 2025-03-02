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
		/*??��I2C*/
		__HAL_RCC_I2C_FORCE_RESET();
		__HAL_RCC_I2C_RELEASE_RESET();
		
		
		
		__HAL_RCC_SYSCFG_CLK_ENABLE();                              /* SYSCFGʱ��ʹ�� */
		__HAL_RCC_DMA_CLK_ENABLE();
		
		extern DMA_HandleTypeDef hdma_oled;
		
		hdma_oled.Instance                 = DMA1_Channel2;           /* ѡ��DMAͨ��1 */
		hdma_oled.Init.Direction           = DMA_MEMORY_TO_PERIPH;    /* ����Ϊ�Ӵ洢�������� */
		hdma_oled.Init.PeriphInc           = DMA_PINC_DISABLE;        /* ��ֹ�����ַ���� */
		hdma_oled.Init.MemInc              = DMA_MINC_ENABLE;         /* ʹ�ܴ洢����ַ���� */
		hdma_oled.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;     /* �������ݿ��Ϊ8λ */
		hdma_oled.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;     /* �洢�����ݿ��λ8λ */
		hdma_oled.Init.Mode                = DMA_NORMAL;              /* ��ֹѭ��ģʽ */
		hdma_oled.Init.Priority            = DMA_PRIORITY_VERY_HIGH;  /* ͨ�����ȼ�Ϊ�ܸ� */

		HAL_DMA_Init(&hdma_oled);                                     /* ��ʼ��DMAͨ��1 */
		__HAL_LINKDMA(hi2c, hdmatx, hdma_oled);                       /* DMA1����IIC_TX */
		
		/* I2C1�жϳ�ʼ�� */
		HAL_NVIC_SetPriority(I2C1_IRQn, 0, 0);                     /* �ж����ȼ����� */
		HAL_NVIC_EnableIRQ(I2C1_IRQn);                              /* ʹ��I2C�ж� */

		
		HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 0, 1);           /* �ж����ȼ����� */
		HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);
		
		/* DMA��������ӳ�� */
		/* DMA��������ӳ�� */
		//  HAL_SYSCFG_DMA_Req(9);                                      /* DMA1_MAPѡ��ΪIIC_TX */
		HAL_SYSCFG_DMA_Req(0x0900);                                  /* DMA2_MAPѡ��ΪIIC_RX */
	}
	

	if(hi2c == &mpu6050){
		
		extern DMA_HandleTypeDef hdma_mpu6050;
		/*
			Ц������Ϊ��ʺ���룬����Ͳ������������ˣ���������ȳ�ʼ��oled����ΪһЩ�ظ������ò�����oledִ���ˣ���߾��������¸���ճ����
			���ȳ�ʼ��oled�ڳ�ʼ��mpu6050�͵��ų�����ɣ�
			�ж�Ҳ�ǣ�py32f030��dma��Ȼ2��3ͨ���ǹ����ж�����ģ����ˣ����ˣ������ˣ�mpu6050���ж���oled��ִ�У�����ο����Դ����
		*/
		
		hdma_mpu6050.Instance                 = DMA1_Channel3;           /* ѡ��DMAͨ��1 */
		hdma_mpu6050.Init.Direction           = DMA_PERIPH_TO_MEMORY;    /* ����Ϊ�Ӵ洢�������� */
		hdma_mpu6050.Init.PeriphInc           = DMA_PINC_DISABLE;        /* ��ֹ�����ַ���� */
		hdma_mpu6050.Init.MemInc              = DMA_MINC_ENABLE;         /* ʹ�ܴ洢����ַ���� */
		hdma_mpu6050.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;     /* �������ݿ��Ϊ8λ */
		hdma_mpu6050.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;     /* �洢�����ݿ��λ8λ */
		hdma_mpu6050.Init.Mode                = DMA_NORMAL;              /* ��ֹѭ��ģʽ */
		hdma_mpu6050.Init.Priority            = DMA_PRIORITY_VERY_HIGH;  /* ͨ�����ȼ�Ϊ�ܸ� */

		HAL_DMA_Init(&hdma_mpu6050);                                     /* ��ʼ��DMAͨ��1 */
		__HAL_LINKDMA(hi2c, hdmarx, hdma_mpu6050);                       /* DMA1����IIC_TX */
		
		/* I2C1�жϳ�ʼ�� */
		HAL_NVIC_SetPriority(I2C1_IRQn, 0, 0);                     /* �ж����ȼ����� */
		HAL_NVIC_EnableIRQ(I2C1_IRQn);                              /* ʹ��I2C�ж� */

		
		HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 0, 1);           /* �ж����ȼ����� */
		HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);
		
		/* DMA��������ӳ�� */
		/* DMA��������ӳ�� */
//		HAL_SYSCFG_DMA_Req(0x90);                                      /* DMA1_MAPѡ��ΪIIC_TX */
		HAL_SYSCFG_DMA_Req(0xA0090);                                  /* DMA2_MAPѡ��ΪIIC_RX */
		
	}

}



