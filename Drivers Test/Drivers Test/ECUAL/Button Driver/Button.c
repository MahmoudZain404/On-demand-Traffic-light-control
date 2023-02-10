/*
 * Button.c
 *
 * Created: 1/29/2023 12:59:01 PM
 *  Author: Mahmoud Zain Salah
 */ 



#include "Button.h"



EN_BUTTONError_t Button_init(uint8_t ledport, uint8_t ledpin)
{
	EN_BUTTONError_t BUTTON_error = BUTTON_OK;
	
	DIO_init(ledport, ledpin, INPUT);
	
	if(1)
	{
		BUTTON_error = BUTTON_OK;
	}

	return BUTTON_error;
}

EN_BUTTONError_t Button_read(uint8_t ledport, uint8_t ledpin, uint8_t *state)
{
	EN_BUTTONError_t BUTTON_error = BUTTON_OK;
	
	DIO_read(ledport, ledpin, state);
	
	if(1)
	{
		 BUTTON_error = BUTTON_OK;
	}

	return BUTTON_error;
}

