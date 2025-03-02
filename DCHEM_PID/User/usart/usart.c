/**
  ******************************************************************************
  * @file    bsp_usart_debug.c
  * @author  embedfire
  * @version V1.0
  * @date    2023-xx-xx
  * @brief   �ض���c��printf������usart�˿�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨��Ұ�� GDF427-���컢 GD32������ 
  * ��̳      ��http://www.firebbs.cn
  * ����      ��https://embedfire.com/
  * �Ա�      ��https://yehuosm.tmall.com/
  *
  ******************************************************************************
  */
#include "usart.h"
#include "py32f0xx_hal.h"



UART_HandleTypeDef	Uart1_Handle;
DMA_HandleTypeDef hdma_usart_tx;



/**
 * @brief       ����X��ʼ������
 * @param       baudrate: ������, �����Լ���Ҫ���ò�����ֵ
 * @note        ע��: ����������ȷ��ʱ��Դ, ���򴮿ڲ����ʾͻ������쳣.
 * @retval      ��
 */
void DEBUG_USART_Config(uint32_t BaudRate)
{
	
	Uart1_Handle.Instance = USART1;
	Uart1_Handle.Init.BaudRate = BaudRate;
	Uart1_Handle.Init.WordLength = UART_WORDLENGTH_8B;
	Uart1_Handle.Init.StopBits = UART_STOPBITS_1;
	Uart1_Handle.Init.Parity = UART_PARITY_NONE;
	Uart1_Handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	Uart1_Handle.Init.Mode = UART_MODE_TX_RX;
	/*ʹ�ܴ��� */
	HAL_UART_Init(&Uart1_Handle);
	/*ʹ�ܴ��ڽ��ն� */
	__HAL_UART_ENABLE_IT(&Uart1_Handle,UART_IT_RXNE); 
  
}

/**
 * @brief       UART�ײ��ʼ������
 * @param       huart: UART�������ָ��
 * @note        �˺����ᱻHAL_UART_Init()����
 *              ���ʱ��ʹ�ܣ��������ã��ж�����z
 * @retval      ��
 */	 
void HAL_UART_MspInit(UART_HandleTypeDef *UartHandle)
{
	
	if(UartHandle->Instance == USART1)  
	{
		GPIO_InitTypeDef	Uart_GPIO_InitConfig;
	
		/*USART1ʱ��ʹ��*/
		DEBUG_UART_Rx_GPIO_CLK_ENABLE();
        DEBUG_UART_Tx_GPIO_CLK_ENABLE();
        __HAL_RCC_USART1_CLK_ENABLE();
            
            
        Uart_GPIO_InitConfig.Pin       = DEBUG_UART_Tx_GPIO_PIN;
        Uart_GPIO_InitConfig.Mode      = GPIO_MODE_AF_PP;
        Uart_GPIO_InitConfig.Pull      = GPIO_PULLUP;
        Uart_GPIO_InitConfig.Speed     = GPIO_SPEED_FREQ_HIGH;
        Uart_GPIO_InitConfig.Alternate = GPIO_AF0_USART1;
        HAL_GPIO_Init(DEBUG_UART_Tx_GPIO_PORT, &Uart_GPIO_InitConfig);
    
        Uart_GPIO_InitConfig.Pin 			 = DEBUG_UART_Rx_GPIO_PIN;
        Uart_GPIO_InitConfig.Mode      = GPIO_MODE_AF_PP;
        Uart_GPIO_InitConfig.Pull      = GPIO_PULLUP;
        Uart_GPIO_InitConfig.Speed     = GPIO_SPEED_FREQ_HIGH;
        Uart_GPIO_InitConfig.Alternate = GPIO_AF0_USART1;
        HAL_GPIO_Init(DEBUG_UART_Rx_GPIO_PORT, &Uart_GPIO_InitConfig);
    
    __HAL_RCC_DMA_CLK_ENABLE();
    hdma_usart_tx.Instance = DMA1_Channel1;
    hdma_usart_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart_tx.Init.Mode = DMA_NORMAL;
    hdma_usart_tx.Init.Priority = DMA_PRIORITY_HIGH;

    if (HAL_DMA_Init(&hdma_usart_tx) != HAL_OK)
    {
        // ��ʼ��������
//        Error_Handler();
    }

    __HAL_LINKDMA(&Uart1_Handle, hdmatx, hdma_usart_tx);
		
		HAL_SYSCFG_DMA_Req(0x05);
		
    /* DMA �жϳ�ʼ�� */
    HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
		
		HAL_NVIC_SetPriority(USART1_IRQn, 0, 1);              /* ��ռ���ȼ�0�������ȼ�1 */
		HAL_NVIC_EnableIRQ(USART1_IRQn);                      /* ʹ��USART1�ж�ͨ�� */	

	}
}

void USART_Transmit_DMA(uint8_t *pData, uint16_t Size)
{
//	printf("dma uart start\r\n");
	HAL_DMA_Init(&hdma_usart_tx);
	if (HAL_UART_Transmit_DMA(&Uart1_Handle, pData, Size) != HAL_OK)
    {
        // ���������
//        Error_Handler();
			printf("dma uart error\r\n");
    }
//		HAL_DMA_Start_IT((&Uart1_Handle)->hdmatx, *(uint32_t *)pData, (uint32_t)(&Uart1_Handle)->Instance->DR, Size);
//	HAL_UART_DMAResume(&Uart1_Handle);
//		printf("dma uart ok\r\n");
}
//	HAL_DMA_Start_IT(&Uart1_Handle, (uint32_t)&pDat, (uint32_t)&aDST_Buffer, BUFFER_SIZE);


void DMA1_Channel1_IRQHandler(void)
{
  HAL_DMA_IRQHandler(Uart1_Handle.hdmatx);
}

void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&Uart1_Handle);
}






void Usart_SendString(uint8_t *str)
{
	unsigned int k=0;
  do 
  {
    HAL_UART_Transmit(&Uart1_Handle,(uint8_t *)(str + k) ,1,1000);
    k++;
  } while(*(str + k)!='\0');
  
}


///* �������´���, ֧��printf���� */
#if (defined (__CC_ARM)) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
/**
  * @brief  writes a character to the usart
  * @param  ch
  *         *f
  * @retval the character
  */
int fputc(int ch, FILE *f)
{
  /* Send a byte to USART */
  HAL_UART_Transmit(&Uart1_Handle, (uint8_t *)&ch, 1, 1000);

  return (ch);
}

/**
  * @brief  get a character from the usart
  * @param  *f
  * @retval a character
  */
int fgetc(FILE *f)
{
  int ch;
  HAL_UART_Receive(&Uart1_Handle, (uint8_t *)&ch, 1, 1000);
  return (ch);
}

#elif defined(__ICCARM__)
/**
  * @brief  writes a character to the usart
  * @param  ch
  *         *f
  * @retval the character
  */
int putchar(int ch)
{
  /* Send a byte to USART */
  HAL_UART_Transmit(&DebugUartHandle, (uint8_t *)&ch, 1, 1000);

  return (ch);
}
#elif  defined(__GNUC__)
/**
  * @brief  writes a character to the usart
  * @param  ch
  * @retval the character
  */
int __io_putchar(int ch)
{
  /* Send a byte to USART */
  HAL_UART_Transmit(&DebugUartHandle, (uint8_t *)&ch, 1, 1000);

  return ch;
}

int _write(int file, char *ptr, int len)
{
  int DataIdx;
  for (DataIdx=0;DataIdx<len;DataIdx++)
  {
    __io_putchar(*ptr++);
  }
  return len;
}
#endif



