/*
 * LED.h
 *
 * Created: 1/29/2023 12:11:28 PM
 *  Author: Mahmod Zain Salah
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"

#include "../../MCAL/TimerCounter0 Driver/Timer0.h"

typedef enum EN_LEDError_t
{
	LED_OK, LED_ERROR
}EN_LEDError_t;

EN_LEDError_t LED_init(uint8_t ledport, uint8_t ledpin);
EN_LEDError_t LED_on(uint8_t ledport, uint8_t ledpin);
EN_LEDError_t LED_off(uint8_t ledport, uint8_t ledpin);
EN_LEDError_t LED_Blink(uint8_t ledport, uint8_t ledpin);


#endif /* LED_H_ */