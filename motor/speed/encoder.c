#include "encoder.h"
#include "usart.h"
#include "tim.h"

int32_t  Encode1Count = 0;
long  SumEncode1Count;
int32_t  Encode2Count = 0;
long  SumEncode2Count;

void Encoder_Init(void)
{
	/*  开启编码器的定时器通道  */
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_2);
	
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim3);
	
}

int Read_Encoder(u8 TIMX)
{
 int Encoder_TIM;    
 switch(TIMX)
 {
	case 2:  Encoder_TIM= (short)TIM2 -> CNT;   TIM2 -> CNT=0;  break;
	case 3:  Encoder_TIM= (short)TIM3 -> CNT;   TIM3 -> CNT=0;  break;
	default: Encoder_TIM=0;
 }
	return Encoder_TIM;
}

void Encoder_printf(int32_t Encode1Count,int32_t Encode2Count)
{
	printf("Encode1Count = %d\t",Encode1Count);
	printf("Encode2Count = %d\r\n",Encode2Count);
}
void Encoder_Display(void)//
{
	Encode1Count = Read_Encoder(2);
	Encode2Count = Read_Encoder(3);
	SumEncode1Count += Encode1Count;
	SumEncode2Count += Encode2Count;
	Encoder_printf(Encode1Count,Encode2Count);

}

