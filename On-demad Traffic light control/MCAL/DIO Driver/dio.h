/*
 * dio.h
 *
 * Created: 1/28/2023 1:00:15 PM
 *  Author: Mahmod Zain Salah
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/Registers.h"

//DIO Macros

/*Macro Functions*/
#define SET_BIT(REG, BIT_NO)    (REG |= (1<< BIT_NO))
#define CLEAR_BIT(REG, BIT_NO)  (REG &=~(1<< BIT_NO))
#define CHECK_BIT(REG, BIT_NO)  ((REG &= (1<< BIT_NO))>>BIT_NO)
#define FLIP_BIT(REG, BIT_NO)   (REG ^= (1<< BIT_NO))

typedef enum EN_DIOError_t
{
	DIO_OK, DIO_ERROR
}EN_DIOError_t;


/*Port reference enum*/

typedef enum en_PORTS_t
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}en_PORTS_t;


/*Port direction*/
#define INPUT 0
#define OUTPUT 1

/*Port Value*/
#define LOW 0
#define  HIGH 1

/*DIO Functions*/
EN_DIOError_t DIO_init(uint8_t PortX, uint8_t PinNum, uint8_t direction); //Initialize DIO direction

EN_DIOError_t DIO_write(uint8_t PortX, uint8_t PinNum, uint8_t Value); //Write Data To DIO


EN_DIOError_t DIO_toggle(uint8_t PortX, uint8_t PinNum); //Toggle DIO Value

EN_DIOError_t DIO_read(uint8_t PortX, uint8_t PinNum, uint8_t* value); //Read DIO Input



#endif /* DIO_H_ */