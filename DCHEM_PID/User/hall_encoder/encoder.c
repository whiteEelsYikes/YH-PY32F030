// #include "encoder.h"
//  /**************************************************************************
// 作者：轮趣科技（东莞）有限公司
// 日期：2022.4.2
// 我的淘宝小店：http://shop114407458.taobao.com/
// **************************************************************************/
// /**************************************************************************
// 函数功能：把TIM2初始化为编码器接口模式
// 入口参数：无
// 返回  值：无
// **************************************************************************/
// void Encoder_Init_TIM2(void)
// {
// 	NVIC_InitTypeDef NVIC_InitStruct;
// 	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
//   TIM_ICInitTypeDef TIM_ICInitStructure;  
//   GPIO_InitTypeDef GPIO_InitStructure;
//	
//   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//使能定时器2的时钟
//   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能PA端口时钟
//	
//   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;	//端口配置 PA0 PA1
//   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入
//   GPIO_Init(GPIOA, &GPIO_InitStructure);					      //根据设定参数初始化GPIOA
//  
// 	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;  //定时器2中断
// 	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;  //使能IRQ通道
// 	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;//抢占优先级1 
// 	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;       //响应优先级3
// 	NVIC_Init(&NVIC_InitStruct);
//	
//   TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
//   TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // 预分频器 
//   TIM_TimeBaseStructure.TIM_Period = ENCODER_TIM_PERIOD; //设定计数器自动重装值
//   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
//   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//边沿计数模式 
//   TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);  //初始化定时器
//	
//   TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使用编码器模式3
//	
//   TIM_ICStructInit(&TIM_ICInitStructure); //把TIM_ICInitStruct 中的每一个参数按缺省值填入
//   TIM_ICInitStructure.TIM_ICFilter = 10;  //设置滤波器长度
//   TIM_ICInit(TIM2, &TIM_ICInitStructure);//根据 TIM_ICInitStruct 的参数初始化外设	TIMx
// 
//   TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除TIM的更新标志位
//   TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//使能定时器中断
//  
// 	//TIM_SetCounter(TIM2,0);
//	
// 	TIM_Cmd(TIM2, ENABLE); //使能定时器

// }
// /**************************************************************************
// 函数功能：把TIM3初始化为编码器接口模式
// 入口参数：无
// 返回  值：无
// **************************************************************************/
// void Encoder_Init_TIM3(void)
// {
// 	NVIC_InitTypeDef NVIC_InitStruct;
// 	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
//   TIM_ICInitTypeDef TIM_ICInitStructure;  
//   GPIO_InitTypeDef GPIO_InitStructure;
//	
//   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//使能定时器3的时钟
//   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能PA端口时钟
//	
//   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	//端口配置 PA6 PA7
//   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入
//   GPIO_Init(GPIOA, &GPIO_InitStructure);					      //根据设定参数初始化GPIOA  
//	
// 	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;             //TIM3中断
// 	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;             //使能IRQ通道
// 	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;   //抢占优先级 1
// 	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;          //响应优先级3       
// 	NVIC_Init(&NVIC_InitStruct);
//	
//   TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
//   TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // 预分频器 
//   TIM_TimeBaseStructure.TIM_Period = ENCODER_TIM_PERIOD; //设定计数器自动重装值
//   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
//   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//边沿计数模式 
//   TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);  //初始化定时器
//	
//   TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使用编码器模式3
//	
//   TIM_ICStructInit(&TIM_ICInitStructure); //把TIM_ICInitStruct 中的每一个参数按缺省值填入
//   TIM_ICInitStructure.TIM_ICFilter = 10;  //设置滤波器长度
//   TIM_ICInit(TIM3, &TIM_ICInitStructure);//根据 TIM_ICInitStruct 的参数初始化外设	TIMx
// 
//   TIM_ClearFlag(TIM3, TIM_FLAG_Update);//清除TIM的更新标志位
//   TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);//使能定时器中断
//	
// 	//TIM_SetCounter(TIM3,0);
//	
// 	TIM_Cmd(TIM3, ENABLE); //使能定时3
// }
// /**************************************************************************
// 函数功能：单位时间读取编码器计数
// 入口参数：定时器
// 返回  值：速度值
// **************************************************************************/
// int Read_Encoder(u8 TIMX)
// {
//     int Encoder_TIM;    
//    switch(TIMX)
// 	 {
// 	   case 2:  Encoder_TIM= (short)TIM2 -> CNT;  TIM2 -> CNT=0; break;
// 		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0; break;	
// 		 case 4:  Encoder_TIM= (short)TIM4 -> CNT;  TIM4 -> CNT=0; break;	
// 		 default:  Encoder_TIM=0;
// 	 }
// 		return Encoder_TIM;
// }
// /**************************************************************************
// 函数功能：TIM3中断服务函数
// 入口参数：无
// 返回  值：无
// **************************************************************************/
// void TIM3_IRQHandler(void)//中断处理函数为空，清除中断标志位后结束中断
// { 		    		  			    
//  if(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==SET)//溢出中断
//  {
//	 
//  } 
//  TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //清除中断标志位 	
// }
// /**************************************************************************
// 函数功能：TIM2中断服务函数
// 入口参数：无
// 返回  值：无
// **************************************************************************/
// void TIM2_IRQHandler(void)//中断处理函数为空，清除中断标志位后结束中断
// { 		    		  			    
//  if(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==SET)//溢出中断
//  {
//	 
//  } 
//  TIM_ClearITPendingBit(TIM2,TIM_IT_Update); //清除中断标志位 	  
// }




#include "encoder.h"

TIM_HandleTypeDef htim3;

void Encoder_Init(void)
{
    // 启用TIM3和GPIOB时钟
    __HAL_RCC_TIM3_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    // 配置GPIOB4和GPIOB5为复用功能
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.Pin = GPIO_PIN_4 | GPIO_PIN_5;
    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP; // 设置为复用模式
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Alternate = GPIO_AF1_TIM3; // 复用为TIM3
    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

    // 配置TIM3基本参数
    TIM_Encoder_InitTypeDef sEncoderConfig;
    TIM_MasterConfigTypeDef sMasterConfig;

    htim3.Instance = TIM3;
    htim3.Init.Prescaler = 0;
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = 65535;
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3.Init.RepetitionCounter = 0;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init(&htim3);

    sEncoderConfig.EncoderMode = TIM_ENCODERMODE_TI12;
    sEncoderConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
    sEncoderConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
    sEncoderConfig.IC1Prescaler = TIM_ICPSC_DIV1;
    sEncoderConfig.IC1Filter = 0xF;
    sEncoderConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
    sEncoderConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
    sEncoderConfig.IC2Prescaler = TIM_ICPSC_DIV1;
    sEncoderConfig.IC2Filter = 0xF;
    HAL_TIM_Encoder_Init(&htim3, &sEncoderConfig);

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);

    // 使能定时器
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}

int16_t Encoder_Get(void)
{
    return __HAL_TIM_GET_COUNTER(&htim3);
}
