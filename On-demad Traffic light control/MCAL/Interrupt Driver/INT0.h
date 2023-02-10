/*
 * INT0.h
 *
 * Created: 1/30/2023 10:05:30 PM
 *  Author: Mahmoud Zain Salah
 */ 


#ifndef INT0_H_
#define INT0_H_

/*Include Registers.h*/
#include "../../Utilities/Registers.h"

/*bits number to control interrupt state*/
#define ISC00 0
#define ISC01 1

#define INT0 6

/* vector of INT0*/
#define EXT_INT_0   __vector_1


typedef enum EN_INTERRUPTSError_t
{
	INTERRUPTS_OK, INTERRUPTS_ERROR
}EN_INTERRUPTSError_t;



/* ISR function like macro*/
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)


/*SET Interrupt Function*/

EN_INTERRUPTSError_t set_interrupet_init(void);



#endif /* INT0_H_ */