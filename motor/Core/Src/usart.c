/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "speed.h"
#define USE_PRINT
#ifdef USE_PRINT
uint8_t rx_Buffer[1000];
uint8_t RX_buffer[4];
uint8_t FLAG=0;
uint8_t Dir[] ={0,0};//Ĭ�Ͽ�ʼ��˳ʱ��ת
uint8_t Flag[] ={0,0};//Ĭ�϶���������ֻ��ʹ�ܶ�ʱ����Ӧͨ������ʹ�����־λ����Ϊ1��
							//ʧ�ܶ�ʱ����Ӧͨ������Ϊ0
uint8_t RxBuff[1];      //�����жϽ������ݵ�����
uint8_t DataBuff[5000]; //������յ������ݵ�����
int RxLine=0;           //���յ������ݳ���
//��������ʹ��MicroLib��
#pragma import(__use_no_semihosting)
//���� _sys_exit() ����ʹ�ð�����
void _sys_exit(int x)
{
x = x;
}
struct __FILE
{
int handle;
};
FILE __stdout;
//��ӳ��fputc
int fputc(int ch, FILE *f)
{
	/* ����һ���ֽ����ݵ�����DEBUG_USART */
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 1000);	
	
	return (ch);
}
#endif
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void UART_Handle(uint8_t *rx_Buffer)
{
		/*  �������PWM���Ķ�ʱ��ͨ��  */
		if(rx_Buffer[0] == 'E')//����PWM���
		{
			switch(rx_Buffer[1])
			{
				case 49://1:PB14,PB13
					Flag[0] = 1;
					TIM_START_MOTOT1
					printf("E1\r\n");
					break;
				case 50://2:PE5,PE6
					Flag[1] = 1;
					TIM_START_MOTOT2
					printf("E2\r\n");
					break;				
				default:
					printf("error\r\n");
					break;			
			}
			
		}
		
		/*  ֹͣ���PWM���Ķ�ʱ��ͨ��  */
		if(rx_Buffer[0] == 'D')//ֹͣPWM���
		{
			/*  ֹͣ���PWM���Ķ�ʱ��ͨ��  */			
			switch(rx_Buffer[1])
			{
				case 49://1:PB14,PB13
					Flag[0] = 0;
					set_number = 0;
					TIM_STOP_MOTOT1
					printf("D1\r\n");
					break;
				case 50://2:PE5,PE6
					Flag[1] = 0;
					set_number = 0;
					TIM_STOP_MOTOT2
					printf("D2\r\n");
					break;				
				default:
					break;			
			}
		}
		
		
		/*  �������PWM����ת������  */
		if(rx_Buffer[0] == 'I')//���÷���
		{
			/*  �������PWM����ת������  */
			switch(rx_Buffer[2])
			{
				case 49://1:PB14,PB13
					switch(rx_Buffer[1])
					{
						case 'S':
							Dir[0] = 0;
							printf("IS1\r\n");
							break;
						case 'N':
							Dir[0] = 1;
							printf("IN1\r\n");
							break;
						default:
							break;
					}
					break;
				case 50://2:PE5,PE6
					switch(rx_Buffer[1])
					{
						case 'S':
							Dir[1] = 0;
							printf("IS2\r\n");
							break;
						case 'N':
							Dir[1] = 1;
							printf("IN2\r\n");
							break;
						default:
							break;
					}
					break;					
				default:
					printf("error\r\n");
					break;			
			}
		}			
		/*  �������PWM��Ϊ����ֵ  */
		if(rx_Buffer[0] == 'S'&&rx_Buffer[1] == 'P')//�������PWM��Ϊ����ֵ
		{		
			/*  �������PWM��Ϊ����ֵ  */
			RX_buffer[0]=rx_Buffer[3] - 48;
			if(RX_buffer[0] == 0){set_number = 0;}
			switch(rx_Buffer[2])
			{
				case 49://1:PB14,PB13
					switch(Dir[0])
					{
						case 0://˳ʱ��ת��
							Motor_speed(1,0,RX_buffer[0]);
							printf("SP1S:%d\r\n",RX_buffer[0]);
							break;
						case 1://��ʱ��ת��
							Motor_speed(1,1,RX_buffer[0]);
							printf("SN1N:%d\r\n",RX_buffer[0]);
							break;
						default:
							break;
					}
					break;
				case 50://2:PE5,PE6
					switch(Dir[1])
					{
						case 0://˳ʱ��ת��
							Motor_speed(2,0,RX_buffer[0]);
							printf("SP2S:%d\r\n",RX_buffer[0]);
							break;
						case 1://��ʱ��ת��
							Motor_speed(2,1,RX_buffer[0]);
							printf("SN2N:%d\r\n",RX_buffer[0]);
							break;
						default:
							break;
					}					
					break;			
				default:
					printf("error\r\n");
					break;			
			}

		}
		/*  ����ˮ��  */
		if(rx_Buffer[0] == 'O'&&rx_Buffer[1] == 'P')//����ˮ��
		{
			HAL_GPIO_WritePin(GPIOB,WATER_Pin,GPIO_PIN_RESET);
			printf("OP\r\n");
		}
				/*  ����ˮ��  */
		if(rx_Buffer[0] == 'D'&&rx_Buffer[1] == 'P')//����ˮ��
		{
			HAL_GPIO_WritePin(GPIOB,WATER_Pin,GPIO_PIN_SET);
			printf("DP\r\n");
		}
		
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART2) //USART1
	{	
		RxLine++;                      
		DataBuff[RxLine-1]=RxBuff[0];  
		
		if(RxBuff[0]==0x58)//�������λ��X���յ�X����һ���������       
		{
			printf("RXLen=%d\r\n",RxLine); 
			for(int i=0;i<RxLine;i++)
			{rx_Buffer[i] = DataBuff[i];printf("%c",rx_Buffer[i]);}
			printf("\r\n");
			UART_Handle(rx_Buffer);
			
			memset(rx_Buffer,0,sizeof(rx_Buffer));
			memset(RX_buffer,0,sizeof(RX_buffer));			
			memset(DataBuff,0,sizeof(DataBuff));  //��ջ�������
			RxLine=0;  //��ս��ճ���
		}	
	
	}
	HAL_UART_Receive_IT(&huart2, (uint8_t*)RxBuff, sizeof(RxBuff)); // ����������һ���ֽ�
}
/* USER CODE END 1 */
