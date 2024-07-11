#ifndef __SPEED_H__
#define __SPEED_H__

#include "stdint.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"


#define   TIM_CLOCKWISE(set1_number)   {__HAL_TIM_SetCompare(&htim10,TIM_CHANNEL_1,0);\
										__HAL_TIM_SetCompare(&htim11,TIM_CHANNEL_1,set1_number);}
#define   TIM_ANTICLOCKWISE(set1_number)   {__HAL_TIM_SetCompare(&htim10,TIM_CHANNEL_1,set1_number);\
											__HAL_TIM_SetCompare(&htim11,TIM_CHANNEL_1,0);}

#define   TIM_CLOCKWISE2(set1_number)   {__HAL_TIM_SetCompare(&htim9,TIM_CHANNEL_1,0);\
										__HAL_TIM_SetCompare(&htim9,TIM_CHANNEL_2,set1_number);}
#define   TIM_ANTICLOCKWISE2(set1_number)   {__HAL_TIM_SetCompare(&htim9,TIM_CHANNEL_1,set1_number);\
											__HAL_TIM_SetCompare(&htim9,TIM_CHANNEL_2,0);}
#define   Speed_0   0
#define   Speed_1   1000
#define   Speed_2   1500
#define   Speed_3   2000
#define   Speed_4   2500
#define   Speed_5   3000
#define   Speed_6   3500
#define   Speed_7   4000
#define   Speed_8   4500
#define   Speed_9   5000


void Motor_speed(uint8_t motor,uint8_t Dir,uint8_t gear);
void Speed_gear(uint8_t gear);//ËÙ¶ÈµµÎ»ÅÐ¶Ï												
#endif
