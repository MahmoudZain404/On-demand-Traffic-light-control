/*
 * Timer0.h
 *
 * Created: 1/30/2023 8:15:58 PM
 *  Author: Mahmoud Zain Salah
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../Utilities/Registers.h"

typedef enum EN_TIMERSError_t
{
	TIMERS_OK, TIMERS_ERROR
}EN_TIMERSError_t;

EN_TIMERSError_t Delay_Rgisters_init(void);


EN_TIMERSError_t Delay_ms(uint32_t delay);


#endif /* TIMER0_H_ */