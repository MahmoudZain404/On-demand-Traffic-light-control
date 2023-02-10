/*
 * dio.c
 *
 * Created: 1/28/2023 1:00:05 PM
 *  Author: Mahmod Zain Salah
 */ 


#include "dio.h"



//DIO Functions
EN_DIOError_t DIO_init(uint8_t PortX, uint8_t PinNum, uint8_t direction)
{
	EN_DIOError_t DIO_error = DIO_OK;
	
	switch(PortX)
	{
		//case 1
		case PORT_A:
			if (direction == INPUT)
			{
				CLEAR_BIT(PORTA, PinNum); // SET Pin To INPUT State
			}
			else if (direction == OUTPUT)
			{
				SET_BIT(PORTA, PinNum);  //SET Pin To OUTPUT State
			}
			else
			{
			  // ERROR
			  return DIO_ERROR;
			}
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			break;
		
		//case 2 
		case PORT_B:
			if (direction == INPUT)
			{
				CLEAR_BIT(PORTB, PinNum); // SET Pin To INPUT State
			}
			else if (direction == OUTPUT)
			{
				SET_BIT(PORTB, PinNum);  //SET Pin To OUTPUT State
			}
			else
			{
				// ERROR
				 return DIO_ERROR;
			}
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
			break;
		
		//case 3
		case PORT_C:
			if (direction == INPUT)
			{
				CLEAR_BIT(PORTC, PinNum); // SET Pin To INPUT State
			}
			else if (direction == OUTPUT)
			{
				SET_BIT(PORTC, PinNum);  //SET Pin To OUTPUT State
			}
			else
			{
				// ERROR
				return DIO_ERROR;
			}
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
			break;
		
		//case 4
		case PORT_D:
			if (direction == INPUT)
			{
				CLEAR_BIT(PORTD, PinNum); // SET Pin To INPUT State
			}
			else if (direction == OUTPUT)
			{
				SET_BIT(PORTD, PinNum);  //SET Pin To OUTPUT State
			}
			else
			{
				// ERROR
				return DIO_ERROR;
			}
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
			break;
	}
	
	return DIO_error;
}

EN_DIOError_t DIO_write(uint8_t PortX, uint8_t PinNum, uint8_t Value)
{
	EN_DIOError_t DIO_error = DIO_OK;
	
	switch(PortX)
	{
		//case 1
		case PORT_A:
			if (Value == LOW)
			{
				CLEAR_BIT(DDRA, PinNum); // SET Pin To INPUT State
			}
			else if (Value == HIGH)
			{
				SET_BIT(DDRA, PinNum);  //SET Pin To OUTPUT State
			}
			else
			{
				// ERROR
				return DIO_ERROR;
			}
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
			break;
		
		//case 2
		case PORT_B:
			if (Value == LOW)
			{
				CLEAR_BIT(DDRB, PinNum); // SET Pin To INPUT State
			}
			else if (Value == HIGH)
			{
				SET_BIT(DDRB, PinNum);  //SET Pin To OUTPUT State
			}
			else
			{
				// ERROR
				return DIO_ERROR;
			}
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
			break;
		
		//case 3
			case PORT_C:
			if (Value == LOW)
			{
				CLEAR_BIT(DDRC, PinNum); // SET Pin To INPUT State
			}
			else if (Value == HIGH)
			{
				SET_BIT(DDRC, PinNum);  //SET Pin To OUTPUT State
			}
			else
			{
				// ERROR
				return DIO_ERROR;
			}
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
			break;
		
		//case 4
			case PORT_D:
			if (Value == LOW)
			{
				CLEAR_BIT(DDRD, PinNum); // SET Pin To INPUT State
			}
			else if (Value == HIGH)
			{
				SET_BIT(DDRD, PinNum);  //SET Pin To OUTPUT State
			}
			else
			{
				// ERROR
				return DIO_ERROR;
			}
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
			break;
	}
	
	return DIO_error;
}


EN_DIOError_t DIO_toggle(uint8_t PortX, uint8_t PinNum)
{
	EN_DIOError_t DIO_error = DIO_OK;
	
	switch(PortX)
	{
		case PORT_A:
		FLIP_BIT(DDRA, PinNum);
		
		if (1)
		{
			DIO_error = DIO_OK;
		}
		
		break;
		
		case PORT_B:
		FLIP_BIT(DDRB, PinNum);
		
		if (1)
		{
			DIO_error = DIO_OK;
		}
		
		break;
		
		case PORT_C:
		FLIP_BIT(DDRC, PinNum);
		
		if (1)
		{
			DIO_error = DIO_OK;
		}
		
		break;
		
		case PORT_D:
		FLIP_BIT(DDRD, PinNum);
		
		if (1)
		{
			DIO_error = DIO_OK;
		}
		
		break;
	}
	
	return DIO_error;
}

EN_DIOError_t DIO_read(uint8_t PortX, uint8_t PinNum, uint8_t* value)
{
	EN_DIOError_t DIO_error = DIO_OK;
	
	switch (PortX)
	{
		case PORT_A:
		
			 *value = CHECK_BIT(PINA, PinNum);
			 
			 if (1)
			 {
				 DIO_error = DIO_OK;
			 }
			 
		break;
		
		case PORT_B:
			*value = CHECK_BIT(PINB, PinNum);
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
		break;
		
		case PORT_C:
			*value = CHECK_BIT(PINC, PinNum);
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
		break;
		
		case PORT_D:
			*value = CHECK_BIT(PIND, PinNum);
			
			if (1)
			{
				DIO_error = DIO_OK;
			}
			
		break;
	}
	return DIO_error;
}
