/*
 * INT0.c
 *
 * Created: 1/30/2023 10:17:50 PM
 *  Author: Mahmoud Zain Salah
 */ 


#include "INT0.h"


/* set interrupt function initialize */
EN_INTERRUPTSError_t set_interrupet_init(void)
{
	EN_INTERRUPTSError_t INTERRUPTS_error = INTERRUPTS_OK;
	/*set interrupt using assembly code*/
	
	__asm__ __volatile__ ("sei" ::: "memory");
	
	/*choosing the external interrupt sense - sense on rising edge*/
	
	MCUCR |=  (1<<ISC00) | (1<<ISC01);
	
	/*enabling the external interrupt 0 - INT0*/
	GICR |= (1<<INT0);
	
	if (1)
	{
		INTERRUPTS_error = INTERRUPTS_OK;
	}
	
	return INTERRUPTS_error;
}