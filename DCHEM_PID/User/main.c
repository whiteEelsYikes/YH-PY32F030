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
 
 
 
 
 
 
 
 
// int main(void)
// {
//     HAL_Init();
//     APP_SystemClockConfig();
// 		
// 		 // ��ʼ��SG90�ŷ����
//     SG90_Init();
// 
//     while (1) {
//         // ����SG90�ŷ�����Ƕ�Ϊ0��
//         SG90_SetAngle(0);
//         HAL_Delay(1000);
// 
//         // ����SG90�ŷ�����Ƕ�Ϊ90��
//         SG90_SetAngle(90);
//         HAL_Delay(1000);
// 
//         // ����SG90�ŷ�����Ƕ�Ϊ180��
//         SG90_SetAngle(180);
//         HAL_Delay(1000);
//     }
//     
// }
 
 
 
 
 
 
 
//int main(void)
// {
//     HAL_Init();
//    APP_SystemClockConfig();
// 		
// 	// ��ʼ�����
//     Motor_Init();
// 
//     while (1) {
//        // ���õ���ٶ�
////         Motor_SetSpeed(32767, 32767);  // ռ�ձ�Ϊ50%
////         HAL_Delay(1000);
//// 
////         Motor_SetSpeed(65535, 65535);  // ռ�ձ�Ϊ100%
////         HAL_Delay(1000);
// 
// Motor_SetSpeed(0, 60000);  // ռ�ձ�Ϊ0
//        HAL_Delay(1000);
//			
//			Motor_SetSpeed(60000, 0);  // ռ�ձ�Ϊ0
//        HAL_Delay(1000);
//    }
//    
//}
 
 
 
//uint8_t ID;
//int16_t AX, AY, AZ, GX, GY, GZ;
// 
//int main(void)
//{
// HAL_Init();
// APP_SystemClockConfig();	
// OLED_Init();
// OLED_Printf(0, 0, OLED_6X8, "ID: %d", ID);OLED_Update();	
// MPU6050_Init();	
////	OLED_Printf(0, 0, OLED_6X8, "ID: %d", ID);OLED_Update();
//	ID = MPU6050_GetID();
//	OLED_Printf(0, 0, OLED_6X8, "ID: %d", ID);OLED_Update();
// //	int a =0;
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
 
 
 
// typedef uint8_t data_;
// data_ data[50];
// int data_start=0, data_binary=-1;
// char receivedString[50]; // �洢�������ַ���
// 
// int main(void)
// {
//     HAL_Init();
//     APP_SystemClockConfig();
//	   OLED_Init();
//     DEBUG_USART_Config(115200);
//     printf("��ӭʹ��Ұ��PY32������!!!\r\n");
//     Usart_SendString("����һ�������жϽ��ջ���ʵ��!!!\r\n");
//     
//  		HAL_Delay(1000);
//			printf("uart rx -> tx test start!");
//			HAL_UART_Receive_IT(&Uart1_Handle, &(data[data_start]), sizeof((data[data_start])));
//     while (1)
//     {
////			 HAL_UART_Receive_IT(&Uart1_Handle, data, sizeof(data)/sizeof(uint8_t));

////         USART_Transmit_DMA(data, sizeof(data) - 1);
////         HAL_Delay(1000);
//   //			(uint32_t)(&Uart1_Handle)->Instance->DR = 65;
//	 //     Usart_SendString("abc\r\n");
//     }
// }
 
 
//void handleReceivedData(uint8_t *buffer, int *start, char *output)
//{
//    uint16_t i = 0;
//    while (i < *start && buffer[i] != '\r')
//    {
//        output[i] = buffer[i];
//        i++;
//    }

//    if (buffer[i] == '\r')
//    {
//        output[i] = '\0';  // �����ַ���
//        *start = 0;  // ������ʼλ��
//    }
//}

//void oled_show(uint8_t *buffer, int index){
//	int lin = 0;
//	for (;lin <= 64;){
//		handleReceivedData(data, &index, receivedString);
//		OLED_Printf(0, lin, OLED_6X8, "test");
//		lin += 8;
//	}
//	OLED_Update();
//}

// 
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//    if (huart->Instance == USART1)
//    {
//        // ������յ�������
//        handleReceivedData(data, &data_start, receivedString);
//				
//        // ��ӡ�������ַ���
//        if (receivedString[0] != '\0')
//        {
//            printf("Received String: %s\n", receivedString);
//					  oled_show(0, 0);
//        }

//        // ����������һ�����ݰ�
//        int data_len = sizeof(data) / sizeof(data[0]);
//        if(data_start >= data_len) {
//            data_start = 0;
//            data_binary = 0;
//        }
//        data_binary = data_binary != -1 ? data_start : data_binary;
//        HAL_UART_Receive_IT(&Uart1_Handle, &(data[data_start]), 1);
//        data_start += 1;
//    }
//}


 
 
 
 
 void pf(void *pvParameters){
	 APP_SystemClockConfig();
//   DEBUG_USART_Config(115200);
	 DEBUG_USART_Config(1500000);
   while(1){
     printf("FreeRTOS TEST ok!\r\n");
   }
 }
 

 // LED ����
void ledc(void *pvParameters) {
    // GPIO��ʼ��
    __HAL_RCC_GPIOA_CLK_ENABLE(); // ����GPIOAʱ��

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // �������ģʽ
    GPIO_InitStruct.Pull = GPIO_NOPULL; // ����������
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // ����
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    while(1) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
        vTaskDelay(pdMS_TO_TICKS(100)); // ��ʱ 1000 ����
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
        vTaskDelay(pdMS_TO_TICKS(100)); // ����ʱ 1000 ����
    }
}
 
 
 int main(void)
 {
     HAL_Init();
	   
//     APP_SystemClockConfig();
//     DEBUG_USART_Config(115200);
   
     #include "FreeRTOS.h"
     #include "task.h"
     #include "queue.h"
     #include "semphr.h"
     #include "timers.h"
     #include "stdio.h"
   
     //printf("FreeRTOS TEST START ...");
 
     // ����LED����
     xTaskCreate(pf, "uart Task", 255, NULL, 1, NULL);
		 xTaskCreate(ledc, "led Task", 255, NULL, 1, NULL);
     
     // ����������
     vTaskStartScheduler();
   
     while (1)
     {
 
     }
 }
 
 
// void vApplicationTickHook(void) {
//     HAL_IncTick();  // �ֶ�����HAL�δ����
// }
 
 /* ���� vApplicationStackOverflowHook ���� */
 void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
     // �����ջ�������Ĵ���
 //    printf("Stack overflow detected in task: %s\n", pcTaskName);
     while(1); // ����ѭ����ͨ�����ڵ���
 }
 
 
 
 
 
 
 
 
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
 



//	void oled_ui(void){
//	OLED_Printf(20, -2, OLED_8X16, "<Info Show>");
//	OLED_DrawLine(0, 13, 127, 13);
//	OLED_ReverseArea(0, 0, 128, 16);

//	OLED_Printf(0, 15, OLED_6X8, "Motor PWM:");OLED_ReverseArea(102, 15, 26, 1);

//	//	OLED_DrawLine(0, 23, 127, 23);
//	OLED_Printf(0, 25, OLED_6X8, "Encoder Value:");

//	//	OLED_DrawLine(0, 33, 127, 33);
//	OLED_Printf(0, 35, OLED_6X8, "SG90 Angle:");

//	uint8_t ID = MPU6050_GetID();
//	//	OLED_DrawLine(0, 43, 127, 43);
//	OLED_Printf(53, 50, OLED_6X8, "MPU6050");
//	//	OLED_DrawLine(108, 45, 108, 61);
//	//	OLED_DrawLine(107, 45, 107, 61);
//	//	OLED_DrawLine(106, 45, 106, 61);
//	OLED_DrawTriangle(108, 45, 108, 61, 97, 53, OLED_FILLED);
//	OLED_Printf(110, 45, OLED_6X8, "ID:");
//	OLED_Printf(110, 55, OLED_6X8, "%d", ID);
//	OLED_Printf(0, 45, OLED_6X8, "X:");
//	OLED_Printf(0, 55, OLED_6X8, "Y:");
//	OLED_Update();
//	}


//	int main(void){

//	HAL_Init(); 
//	APP_SystemClockConfig();


//	OLED_Init();
//	DEBUG_USART_Config(1500000);

//	Encoder_Init();
//	MPU6050_Init();

//	Motor_Init();
//	SG90_Init();

//	oled_ui();

//	int ev = 0;

//	while(1){
//		float GXF, GYF;
//		MPU6050_GetAngle(&GXF, &GYF);
//		OLED_ShowSignedNum(13, 45, GXF, 3, OLED_6X8);
//		OLED_ShowSignedNum(13, 55, GYF, 3, OLED_6X8);
//		
//		int sg = (int) GXF;
//		OLED_ShowSignedNum(66, 35, sg, 3, OLED_6X8); // sg90
//		
//		SG90_SetAngle((uint8_t) sg);
//		
//		ev = (int) Encoder_Get();
//		OLED_ShowSignedNum(85, 25, ev, 5, OLED_6X8); // ������
//		
//		OLED_ShowSignedNum(61, 15, ev, 6, OLED_6X8); // pwm
//		
//		ev>0 ? Motor_SetSpeed(0, (ev)*10) :Motor_SetSpeed((ev)*10, 0);
////		Motor_SetSpeed(65535,0);HAL_Delay(100);
////		Motor_SetSpeed(0,65535);HAL_Delay(100);
//		
//		OLED_Update();
//		
//	}

//	}
 
 
 
 
 
 
 
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
