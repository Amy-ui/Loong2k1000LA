#include "speed.h"

uint16_t set_number = 0;

void Speed_gear(uint8_t gear)//速度档位判断
{
	switch(gear)
	{
		case 0:
			set_number = Speed_0;
			break;
		case 1:
			set_number = Speed_1;
			break;
		case 2:
			set_number = Speed_2;
			break;
		case 3:
			set_number = Speed_3;
			break;
		case 4:
			set_number = Speed_4;
			break;
		case 5:
			set_number = Speed_5;
			break;
		case 6:
			set_number = Speed_6;
			break;
		case 7:
			set_number = Speed_7;
			break;
		case 8:
			set_number = Speed_8;
			break;
		case 9:
			set_number = Speed_9;
			break;
		default:
			set_number = Speed_0;
			break;	
	}
}
void Motor_speed(uint8_t motor,uint8_t Dir,uint8_t gear)
{
	Speed_gear(gear);
	
	switch(motor)
	{
		case 1:
			switch(Dir)//0顺时针，1逆时针
			{
				case 0:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_RESET);
					printf("%d\r\n",set_number);
					TIM_CLOCKWISE(set_number)
					set_number = 0;
					break;
				case 1:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_RESET);
					if(gear != 0){set_number += 500;}
					else{}
					printf("%d\r\n",set_number);
					TIM_ANTICLOCKWISE(set_number)
					set_number = 0;
					break;
				default:
					break;
			}
			break;
		case 2:
			switch(Dir)//0顺时针，1逆时针
			{
				case 0:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_RESET);
					printf("%d\r\n",set_number);
					TIM_CLOCKWISE2(set_number)
					set_number = 0;
					break;
				case 1:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_RESET);
					printf("%d\r\n",set_number);
					TIM_ANTICLOCKWISE2(set_number)
					set_number = 0;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	

}
