/*
 * Application.h
 *
 * Created: 1/29/2023 12:31:13 PM
 *  Author: Mahmoud Zain Salah
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


#include "../ECUAL/Button Driver/Button.h" // include Button Driver
#include "../ECUAL/LED Driver/LED.h" // include LED Driver



void APP_START(void);

void pedestrain_mode(void);

void Set_Cars_TrafficOff(void);

void Set_Pedestrians_TrafficOff(void);


#endif /* APPLICATION_H_ */