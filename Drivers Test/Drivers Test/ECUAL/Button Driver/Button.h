/*
 * Button.h
 *
 * Created: 1/29/2023 12:58:49 PM
 *  Author: Mahmoud Zain Salah
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"

#include "../../MCAL/Interrupt Driver/INT0.h" // Interrupt Driver

typedef enum EN_BUTTONError_t
{
	BUTTON_OK, BUTTON_ERROR
}EN_BUTTONError_t;



EN_BUTTONError_t Button_init(uint8_t ledport, uint8_t ledpin);

EN_BUTTONError_t Button_read(uint8_t ledport, uint8_t ledpin, uint8_t* state);




#endif /* BUTTON_H_ */