/**
  ******************************************************************************
  * @file     main.c
  * @author   embedfire
  * @version  V1.0
  * @date     2024
  * @brief    
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨��Ұ�� ebf_py32f030 PY32������ 
  * ��̳      ��http://www.firebbs.cn
  * ����      ��https://embedfire.com/
  * �Ա�      ��https://yehuosm.tmall.com/
  *
  ******************************************************************************
  */
#include "main.h"
// #include "status_lights/led.h"
#include "motor_drive/at8236x_motor.h"
#include "oled/oled.h"
#include "hall_encoder/encoder.h"
#include "sg90_servos/sg90.h"
#include "mpu6050/MPU6050.h"
#include "usart/usart.h"

#include "FreeRTOS.h"
#include "task.h"


static void APP_SystemClockConfig(void);

///**
//  * @brief  Ӧ�ó�����ں���.
//  * @retval int
//  */
//int main(void)
//{
//    /* ��ʼ���������裬Flash�ӿڣ�SysTick */
//    HAL_Init();
//    
//    /* ϵͳʱ������ 48M */
//    APP_SystemClockConfig();
//    
//		// led();
//		/* Tim1 PWM ��ʼ�� */
//    at8236x_init(1-1, 479-1);
//    
//    SetGeneralTIMxPWMOutputChannalDuty(4, 1, 100, 100 ,50);

//    while (1)
//    {

//    }
//}





//int main(void)
//{
//    /* ��ʼ���������裬Flash�ӿڣ�SysTick */
//    HAL_Init();
//    /* ϵͳʱ������ 48M */
//    APP_SystemClockConfig();

//	/*OLED��ʼ��*/
//	OLED_Init();
//	
//	/*��(0, 0)λ����ʾ�ַ�'A'�������СΪ8*16����*/
//	OLED_ShowChar(0, 0, 'A', OLED_8X16);
//	
//	/*��(16, 0)λ����ʾ�ַ���"Hello World!"�������СΪ8*16����*/
//	OLED_ShowString(16, 0, "Hello World!", OLED_8X16);
//	
//	/*��(0, 18)λ����ʾ�ַ�'A'�������СΪ6*8����*/
//	OLED_ShowChar(0, 18, 'A', OLED_6X8);
//	
//	/*��(16, 18)λ����ʾ�ַ���"Hello World!"�������СΪ6*8����*/
//	OLED_ShowString(16, 18, "Hello World!", OLED_6X8);
//	
//	/*��(0, 28)λ����ʾ����12345������Ϊ5�������СΪ6*8����*/
//	OLED_ShowNum(0, 28, 12345, 5, OLED_6X8);
//	
//	/*��(40, 28)λ����ʾ�з�������-66������Ϊ2�������СΪ6*8����*/
//	OLED_ShowSignedNum(40, 28, -66, 2, OLED_6X8);
//	
//	/*��(96, 18)λ�ô�ӡ��ʽ���ַ����������СΪ6*8���󣬸�ʽ���ַ���Ϊ"[%02d]"*/
//	OLED_Printf(96, 18, OLED_6X8, "[%02d]", 6);
//	
//	/*����OLED_Update��������OLED�Դ���������ݸ��µ�OLEDӲ��������ʾ*/
//	OLED_Update();
//	
//	while (1);
//}






//int main(void)
//{
//    HAL_Init();
//    APP_SystemClockConfig();
//		OLED_Init();

//    Encoder_Init();

//    while (1)
//    {
//        // ��ȡ����������ֵ
//        int16_t encoder_value = Encoder_Get();
//        // �����������ʹ��encoder_value������������
//			
//			OLED_Printf(0, 18, OLED_6X8, "encoder:%d", encoder_value);
//			OLED_Update();
//    }
//}








//int main(void)
//{
//    HAL_Init();
//    APP_SystemClockConfig();
//		
//		// ��ʼ��SG90�ŷ����
//    SG90_Init();

//    while (1) {
//        // ����SG90�ŷ�����Ƕ�Ϊ0��
//        SG90_SetAngle(0);
//        HAL_Delay(1000);

//        // ����SG90�ŷ�����Ƕ�Ϊ90��
//        SG90_SetAngle(90);
//        HAL_Delay(1000);

//        // ����SG90�ŷ�����Ƕ�Ϊ180��
//        SG90_SetAngle(180);
//        HAL_Delay(1000);
//    }
//    
//}







//int main(void)
//{
//    HAL_Init();
//    APP_SystemClockConfig();
//		
//	// ��ʼ�����
//    Motor_Init();

//    while (1) {
//        // ���õ���ٶ�
////        Motor_SetSpeed(32767, 32767);  // ռ�ձ�Ϊ50%
////        HAL_Delay(1000);

////        Motor_SetSpeed(65535, 65535);  // ռ�ձ�Ϊ100%
////        HAL_Delay(1000);

//        Motor_SetSpeed(0, 60000);  // ռ�ձ�Ϊ0
//        HAL_Delay(1000);
//			
//			Motor_SetSpeed(60000, 0);  // ռ�ձ�Ϊ0
//        HAL_Delay(1000);
//    }
//    
//}



//uint8_t ID;
//int16_t AX, AY, AZ, GX, GY, GZ;

//int main(void)
//{
//	
//	HAL_Init();
//  APP_SystemClockConfig();
//	
//	
//	OLED_Init();

////	OLED_Printf(0, 0, OLED_6X8, "ID: %d", ID);OLED_Update();
//	
//	MPU6050_Init();
//	
////	OLED_Printf(0, 0, OLED_6X8, "ID: %d", ID);OLED_Update();
//	ID = MPU6050_GetID();
//	OLED_Printf(0, 0, OLED_6X8, "ID: %d", ID);OLED_Update();
////	int a =0;
//	while (1)
//	{
////		if (a>500)a=0;
////		a +=1;
////		OLED_Printf(0, 10, OLED_6X8, "int a:%d", a);
////		OLED_Update();
//		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
//		OLED_ShowSignedNum(2, 1, AX, 5, OLED_6X8);
//		OLED_ShowSignedNum(3, 1, AY, 5, OLED_6X8);
//		OLED_ShowSignedNum(4, 1, AZ, 5, OLED_6X8);
//		OLED_ShowSignedNum(0, 10, GX, 5, OLED_6X8);
//		OLED_ShowSignedNum(0, 20, GY, 5, OLED_6X8);
//		OLED_ShowSignedNum(0, 30, GZ, 5, OLED_6X8);
//		float GXF, GYF;
//		MPU6050_GetAngle(&GXF, &GYF);
//		OLED_ShowSignedNum(0, 40, GXF, 5, OLED_6X8);
//		OLED_ShowSignedNum(0, 50, GYF, 5, OLED_6X8);
//		
//		OLED_Update();
//	}
//}






//int main(void)
//{
//    HAL_Init();
//    APP_SystemClockConfig();
//    DEBUG_USART_Config(115200);
//    printf("��ӭʹ��Ұ��PY32������!!!\r\n");
//    Usart_SendString("����һ�������жϽ��ջ���ʵ��!!!\r\n");
//    uint8_t data[] = "Hello, DMA USART!\r\n";
//		HAL_Delay(1000);
//    while (1)
//    {
//        USART_Transmit_DMA(data, sizeof(data) - 1);
//        HAL_Delay(1000);
////			(uint32_t)(&Uart1_Handle)->Instance->DR = 65;
////        Usart_SendString("abc\r\n");
//    }
//}



void pf(void *pvParameters){
	DEBUG_USART_Config(115200);
	while(1){
	  Usart_SendString("FreeRTOS TEST ok!\r\n");
	}
}

void vApplicationTickHook(void) {
    HAL_IncTick();  // �ֶ�����HAL�δ����
}


int main(void)
{
    HAL_Init();
    APP_SystemClockConfig();
		DEBUG_USART_Config(115200);
	
		#include "FreeRTOS.h"
		#include "task.h"
		#include "queue.h"
		#include "semphr.h"
		#include "timers.h"
		#include "stdio.h"
	
		//printf("FreeRTOS TEST START ...");

		// ����LED����
    xTaskCreate(pf, "LED Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    
    
    // ����������
    vTaskStartScheduler();
	
    while (1)
    {

    }
}


/* ���� vApplicationStackOverflowHook ���� */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    // �����ջ�������Ĵ���
//    printf("Stack overflow detected in task: %s\n", pcTaskName);
    while(1); // ����ѭ����ͨ�����ڵ���
}



/**
	* @brief  ϵͳʱ�����ú��� �ڲ�HSI��Ƶ ��Ƶ48M
  * @param  ��
  * @retval ��
  */
static void APP_SystemClockConfig(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    
    /* �������� */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_LSE; /* ѡ������HSE,HSI,LSI,LSE */
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;                          /* ����HSI */
    RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;                          /* HSI 1��Ƶ */
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_24MHz;  /* ����HSIʱ��24MHz */
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;                         /* �ر�HSE */
    RCC_OscInitStruct.HSEFreq = RCC_HSE_16_32MHz;
    RCC_OscInitStruct.LSIState = RCC_LSI_OFF;                         /* �ر�LSI */
    RCC_OscInitStruct.LSEState = RCC_LSE_OFF;                         /* �ر�LSE */
    /*RCC_OscInitStruct.LSEDriver = RCC_LSEDRIVE_MEDIUM;*/
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;                     /* ����PLL */
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    /* �������� */
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        APP_ErrorHandler();
    }
    
    /* ʱ��Դ���� */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1; /* ѡ������ʱ�� HCLK,SYSCLK,PCLK1 */
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; /* ѡ��PLLCLK��Ϊϵͳʱ�� */
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;     /* AHBʱ�� 1��Ƶ */
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;      /* APBʱ�� 1��Ƶ */
    /* ����ʱ��Դ */
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
    {
        APP_ErrorHandler();
    }
}

/**
  * @brief  ����ִ�к���
  * @param  ��
  * @retval ��
  */
void APP_ErrorHandler(void)
{
  /* ����ѭ�� */
  while (1)
  {
		
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  ����������Դ����Դ�ļ������к�
  * @param  file��Դ�ļ���ָ��
  * @param  line���������Դ�����к�
  * @retval ��
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* �û����Ը�����Ҫ����Լ��Ĵ�ӡ��Ϣ,
     ����: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* ����ѭ�� */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
