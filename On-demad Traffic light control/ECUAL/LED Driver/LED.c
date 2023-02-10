/*
 * LED.c
 *
 * Created: 1/29/2023 12:11:39 PM
 *  Author: Mahmoud Zain Salah
 */ 






#include "LED.h"



EN_LEDError_t LED_init(uint8_t ledport, uint8_t ledpin)
{
	EN_LEDError_t LED_error = LED_OK;
	
	DIO_init(ledport, ledpin, OUTPUT);
	
	if(1)
	{
		LED_error = LED_OK;
	}

	return LED_error;
}



EN_LEDError_t LED_on(uint8_t ledport, uint8_t ledpin)
{
	EN_LEDError_t LED_error = LED_OK;
	
	DIO_write(ledport, ledpin, HIGH);
	
	if(1)
	{
		LED_error = LED_OK;
	}

	return LED_error;
}

EN_LEDError_t LED_off(uint8_t ledport, uint8_t ledpin)
{
	EN_LEDError_t LED_error = LED_OK;
	
	DIO_write(ledport, ledpin, LOW);
	
	if(1)
	{
		LED_error = LED_OK;
	}

	return LED_error;
}

EN_LEDError_t LED_Blink(uint8_t ledport, uint8_t ledpin)
{
		EN_LEDError_t LED_error = LED_OK;
	
		DIO_toggle(ledport, ledpin);
		
		if(1)
		{
			LED_error = LED_OK;
		}

		return LED_error;
}