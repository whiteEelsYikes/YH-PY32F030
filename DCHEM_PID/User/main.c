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
  * 实验平台：野火 ebf_py32f030 PY32开发板 
  * 论坛      ：http://www.firebbs.cn
  * 官网      ：https://embedfire.com/
  * 淘宝      ：https://yehuosm.tmall.com/
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
 //  * @brief  应用程序入口函数.
 //  * @retval int
 //  */
 //int main(void)
 //{
 //    /* 初始化所有外设，Flash接口，SysTick */
 //    HAL_Init();
 //    
 //    /* 系统时钟配置 48M */
 //    APP_SystemClockConfig();
 //    
 //		// led();
 //		/* Tim1 PWM 初始化 */
 //    at8236x_init(1-1, 479-1);
 //    
 //    SetGeneralTIMxPWMOutputChannalDuty(4, 1, 100, 100 ,50);
 
 //    while (1)
 //    {
 
 //    }
 //}
 
 
 
 
 
 //int main(void)
 //{
 //    /* 初始化所有外设，Flash接口，SysTick */
 //    HAL_Init();
 //    /* 系统时钟配置 48M */
 //    APP_SystemClockConfig();
 
 //	/*OLED初始化*/
 //	OLED_Init();
 //	
 //	/*在(0, 0)位置显示字符'A'，字体大小为8*16点阵*/
 //	OLED_ShowChar(0, 0, 'A', OLED_8X16);
 //	
 //	/*在(16, 0)位置显示字符串"Hello World!"，字体大小为8*16点阵*/
 //	OLED_ShowString(16, 0, "Hello World!", OLED_8X16);
 //	
 //	/*在(0, 18)位置显示字符'A'，字体大小为6*8点阵*/
 //	OLED_ShowChar(0, 18, 'A', OLED_6X8);
 //	
 //	/*在(16, 18)位置显示字符串"Hello World!"，字体大小为6*8点阵*/
 //	OLED_ShowString(16, 18, "Hello World!", OLED_6X8);
 //	
 //	/*在(0, 28)位置显示数字12345，长度为5，字体大小为6*8点阵*/
 //	OLED_ShowNum(0, 28, 12345, 5, OLED_6X8);
 //	
 //	/*在(40, 28)位置显示有符号数字-66，长度为2，字体大小为6*8点阵*/
 //	OLED_ShowSignedNum(40, 28, -66, 2, OLED_6X8);
 //	
 //	/*在(96, 18)位置打印格式化字符串，字体大小为6*8点阵，格式化字符串为"[%02d]"*/
 //	OLED_Printf(96, 18, OLED_6X8, "[%02d]", 6);
 //	
 //	/*调用OLED_Update函数，将OLED显存数组的内容更新到OLED硬件进行显示*/
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
 //        // 获取编码器计数值
 //        int16_t encoder_value = Encoder_Get();
 //        // 你可以在这里使用encoder_value进行其他处理
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
// 		 // 初始化SG90伺服电机
//     SG90_Init();
// 
//     while (1) {
//         // 设置SG90伺服电机角度为0度
//         SG90_SetAngle(0);
//         HAL_Delay(1000);
// 
//         // 设置SG90伺服电机角度为90度
//         SG90_SetAngle(90);
//         HAL_Delay(1000);
// 
//         // 设置SG90伺服电机角度为180度
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
// 	// 初始化电机
//     Motor_Init();
// 
//     while (1) {
//        // 设置电机速度
////         Motor_SetSpeed(32767, 32767);  // 占空比为50%
////         HAL_Delay(1000);
//// 
////         Motor_SetSpeed(65535, 65535);  // 占空比为100%
////         HAL_Delay(1000);
// 
// Motor_SetSpeed(0, 60000);  // 占空比为0
//        HAL_Delay(1000);
//			
//			Motor_SetSpeed(60000, 0);  // 占空比为0
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
// char receivedString[50]; // 存储处理后的字符串
// 
// int main(void)
// {
//     HAL_Init();
//     APP_SystemClockConfig();
//	   OLED_Init();
//     DEBUG_USART_Config(115200);
//     printf("欢迎使用野火PY32开发板!!!\r\n");
//     Usart_SendString("这是一个串口中断接收回显实验!!!\r\n");
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
//        output[i] = '\0';  // 结束字符串
//        *start = 0;  // 重置起始位置
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
//        // 处理接收到的数据
//        handleReceivedData(data, &data_start, receivedString);
//				
//        // 打印处理后的字符串
//        if (receivedString[0] != '\0')
//        {
//            printf("Received String: %s\n", receivedString);
//					  oled_show(0, 0);
//        }

//        // 继续接收下一个数据包
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
 

 // LED 任务
void ledc(void *pvParameters) {
    // GPIO初始化
    __HAL_RCC_GPIOA_CLK_ENABLE(); // 启用GPIOA时钟

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // 推挽输出模式
    GPIO_InitStruct.Pull = GPIO_NOPULL; // 无上拉下拉
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // 低速
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    while(1) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
        vTaskDelay(pdMS_TO_TICKS(100)); // 延时 1000 毫秒
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
        vTaskDelay(pdMS_TO_TICKS(100)); // 再延时 1000 毫秒
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
 
     // 创建LED任务
     xTaskCreate(pf, "uart Task", 255, NULL, 1, NULL);
		 xTaskCreate(ledc, "led Task", 255, NULL, 1, NULL);
     
     // 启动调度器
     vTaskStartScheduler();
   
     while (1)
     {
 
     }
 }
 
 
// void vApplicationTickHook(void) {
//     HAL_IncTick();  // 手动调用HAL滴答计数
// }
 
 /* 定义 vApplicationStackOverflowHook 函数 */
 void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
     // 处理堆栈溢出错误的代码
 //    printf("Stack overflow detected in task: %s\n", pcTaskName);
     while(1); // 无限循环，通常用于调试
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
//		OLED_ShowSignedNum(85, 25, ev, 5, OLED_6X8); // 编码器
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
   * @brief  系统时钟配置函数 内部HSI倍频 主频48M
   * @param  无
   * @retval 无
   */
 static void APP_SystemClockConfig(void)
 {
     RCC_OscInitTypeDef RCC_OscInitStruct = {0};
     RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
     
     /* 振荡器配置 */
     RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_LSE; /* 选择振荡器HSE,HSI,LSI,LSE */
     RCC_OscInitStruct.HSIState = RCC_HSI_ON;                          /* 开启HSI */
     RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;                          /* HSI 1分频 */
     RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_24MHz;  /* 配置HSI时钟24MHz */
     RCC_OscInitStruct.HSEState = RCC_HSE_ON;                         /* 关闭HSE */
     RCC_OscInitStruct.HSEFreq = RCC_HSE_16_32MHz;
     RCC_OscInitStruct.LSIState = RCC_LSI_OFF;                         /* 关闭LSI */
     RCC_OscInitStruct.LSEState = RCC_LSE_OFF;                         /* 关闭LSE */
     /*RCC_OscInitStruct.LSEDriver = RCC_LSEDRIVE_MEDIUM;*/
     RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;                     /* 开启PLL */
     RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
     /* 配置振荡器 */
     if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
     {
         APP_ErrorHandler();
     }
     
     /* 时钟源配置 */
     RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1; /* 选择配置时钟 HCLK,SYSCLK,PCLK1 */
     RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; /* 选择PLLCLK作为系统时钟 */
     RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;     /* AHB时钟 1分频 */
     RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;      /* APB时钟 1分频 */
     /* 配置时钟源 */
     if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
     {
         APP_ErrorHandler();
     }
 }
 
 /**
   * @brief  错误执行函数
   * @param  无
   * @retval 无
   */
 void APP_ErrorHandler(void)
 {
   /* 无限循环 */
   while (1)
   {
     
   }
 }
 
 #ifdef  USE_FULL_ASSERT
 /**
   * @brief  输出产生断言错误的源文件名及行号
   * @param  file：源文件名指针
   * @param  line：发生断言错误的行号
   * @retval 无
   */
 void assert_failed(uint8_t *file, uint32_t line)
 {
   /* 用户可以根据需要添加自己的打印信息,
      例如: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
   /* 无限循环 */
   while (1)
   {
   }
 }
 #endif /* USE_FULL_ASSERT */
/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
