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








//int main(void)
//{
//    HAL_Init();
//    APP_SystemClockConfig();
//		
//		// 初始化SG90伺服电机
//    SG90_Init();

//    while (1) {
//        // 设置SG90伺服电机角度为0度
//        SG90_SetAngle(0);
//        HAL_Delay(1000);

//        // 设置SG90伺服电机角度为90度
//        SG90_SetAngle(90);
//        HAL_Delay(1000);

//        // 设置SG90伺服电机角度为180度
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
//	// 初始化电机
//    Motor_Init();

//    while (1) {
//        // 设置电机速度
////        Motor_SetSpeed(32767, 32767);  // 占空比为50%
////        HAL_Delay(1000);

////        Motor_SetSpeed(65535, 65535);  // 占空比为100%
////        HAL_Delay(1000);

//        Motor_SetSpeed(0, 60000);  // 占空比为0
//        HAL_Delay(1000);
//			
//			Motor_SetSpeed(60000, 0);  // 占空比为0
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
//    printf("欢迎使用野火PY32开发板!!!\r\n");
//    Usart_SendString("这是一个串口中断接收回显实验!!!\r\n");
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
    HAL_IncTick();  // 手动调用HAL滴答计数
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

		// 创建LED任务
    xTaskCreate(pf, "LED Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    
    
    // 启动调度器
    vTaskStartScheduler();
	
    while (1)
    {

    }
}


/* 定义 vApplicationStackOverflowHook 函数 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    // 处理堆栈溢出错误的代码
//    printf("Stack overflow detected in task: %s\n", pcTaskName);
    while(1); // 无限循环，通常用于调试
}



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
