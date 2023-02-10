/*
 * Timer0.c
 *
 * Created: 1/30/2023 8:15:48 PM
 *  Author: Mahmoud Zain Salah
 */ 

#include "Timer0.h"

#include <math.h>

#define FCPU 1 // Defining CPU Frequency

// TIMER0 initialization
EN_TIMERSError_t Delay_Rgisters_init(void)
{
	EN_TIMERSError_t TIMER_Error = TIMERS_OK;
	
	TCCR0 = 0x00; // normal mode
	
	TCNT0 = 0x00;
	
	if(1)
	{
		TIMER_Error = TIMERS_OK;
	}

	return TIMER_Error;
}

EN_TIMERSError_t Delay_ms(uint32_t delay)
{
	EN_TIMERSError_t TIMER_Error = TIMERS_OK;
	
	Delay_Rgisters_init();
	
	uint32_t Num_Of_Overflowes = (uint32_t)ceil( ((delay * pow(10,3)) / (pow(2, 8) * FCPU)) ); // calculate number of Overflows based on desired Delay (mile second)
	
	int Overflowes_Counter = 0; // initialize overflow counter
	
	TCCR0 |= (1<<0); // Timer start
	
	while(Overflowes_Counter < Num_Of_Overflowes)
	{
		while((TIFR & (1<<0)) == 0); //wait until overflow Flag is High
		
		TIFR |= (1<<0); //clear Overflow Flag
		
		Overflowes_Counter++;
	}
	
	Overflowes_Counter = 0;
	
	TCCR0 =0x00; //Timer stop
	
	if(1)
	{
		TIMER_Error = TIMERS_OK;
	}

	return TIMER_Error;
}


