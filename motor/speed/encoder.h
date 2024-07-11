#ifndef ENCODER_H
#define ENCODER_H

#include "stdint.h"
#include "gpio.h"
#include "tim.h"
#include "usart.h"


void Encoder_Init(void);
int Read_Encoder(u8 TIMX);
void Encoder_Display(void);
void sensor_control(void);
void Encoder_printf(int32_t Encode1Count,int32_t Encode2Count);
#endif
