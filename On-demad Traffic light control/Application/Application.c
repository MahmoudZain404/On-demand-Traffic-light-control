/*
 * Application.c
 *
 * Created: 1/29/2023 12:31:29 PM
 *  Author: Mahmoud Zain Salah
 */ 


#include "Application.h"

#define Red 0
#define Yellow 1
#define Green 2

uint8_t Yellow_State = LOW;
uint8_t Red_State = LOW;
uint8_t Green_State = LOW;

void APP_START(void)
{
	
	/* external interrupt initialization INT0 */
	set_interrupet_init();
	
	/* Initialize Interrupt Button */
	Button_init(PORT_C, 0);
	
	/* Initialize Cars' Traffic Light LEDs */
	LED_init(PORT_A, Red); //Red
	LED_init(PORT_A, Yellow); //Yellow
	LED_init(PORT_A, Green); //Green
	
	/* Initialize Peoples' Traffic Light LEDs */
	LED_init(PORT_B, Red); //Red
	LED_init(PORT_B, Yellow); //Yellow
	LED_init(PORT_B, Green); //Green
	
	while (1)
	{
		
		/* cars green on for 5 seconds */
		
		LED_on(PORT_A, Green); //Green On
		Green_State = HIGH;
		Delay_ms(5000);
		LED_off(PORT_A, Green); //Green Off
		Green_State = LOW;
		
		/* cars Yellow on for 5 seconds */
		
		for(int i = 0; i < 10; i++)
		{
			Yellow_State = HIGH;
			LED_Blink(PORT_A, Yellow);    // Blink Yellow LED
			Delay_ms(500);
		}
		
		Yellow_State = LOW;
		
		/* cars Red on for 5 seconds */
		
		LED_on(PORT_A, Red); //Red On
		Red_State = HIGH;
		Delay_ms(5000);
		
		LED_off(PORT_A, Red); //Red On
	    Red_State = LOW;
		
		/* cars Yellow on for 5 seconds */
		
		for(int i = 0; i < 10; i++)
		{
			Yellow_State = HIGH;
			
			LED_Blink(PORT_A, Yellow);	 // Blink Yellow LED
			Delay_ms(500);
		}
		
		   Yellow_State = LOW;
	}
}


void Set_Cars_TrafficOff(void)
{
	/*SET CARS' Traffic Off*/
	LED_off(PORT_A, Red); //Red Off
	LED_off(PORT_A, Yellow); //Yellow Off
	LED_off(PORT_A, Green); //Green Off
}

void Set_Pedestrians_TrafficOff(void)
{
	/*SET CARS' Traffic Off*/
	LED_off(PORT_B, Red); //Red Off
	LED_off(PORT_B, Yellow); //Yellow Off
	LED_off(PORT_B, Green); //Green Off
}


 void pedestrain_mode(void)
{
	
	/*SET CARS' & Pedestrian Traffic Off*/
	Set_Cars_TrafficOff();
	Set_Pedestrians_TrafficOff();

	if(Red_State == HIGH) // If Red LED Is On
	{
		/*cars red on and pedestrian green on for 5 seconds*/
		
		LED_on(PORT_B, Green); //pedestrian Green On
		LED_on(PORT_A, Red); //Cars' Red On
		
		/*Delay for 5 seconds*/
		Delay_ms(5000);
		
		/*cars red off and Both Cars' & pedestrian Yellow is Blinking for 5 seconds*/
		
		LED_off(PORT_A, Red); //Cars' Red Off
		
		for(int i = 0; i < 10; i++)
		{
			LED_Blink(PORT_B, Yellow);	 // Blink pedestrian Yellow LED
			LED_Blink(PORT_A, Yellow);	 // Blink Cars' Blink Yellow LED
			Delay_ms(500);
		}
		
		LED_off(PORT_B, Green); //pedestrian Green Off
		
		LED_on(PORT_B, Red); //pedestrian Red On
		LED_on(PORT_A, Green); //Cars' Green On
		
		/*Go Back To Normal Mode*/
		APP_START();
	}
	else if(Green_State == HIGH || Yellow_State == HIGH )
	{
		/*pedestrian red on and Both cars & pedestrian Yellow is Blinking for 5 seconds*/
		
		LED_on(PORT_B, Red); //pedestrian Red LED  on
		
		for(int i = 0; i < 10; i++)
		{
			LED_Blink(PORT_B, Yellow);	 // Blink pedestrian Yellow LED
			LED_Blink(PORT_A, Yellow);	 // Blink Cars' Blink Yellow LED
			Delay_ms(500);
		}
		
		LED_off(PORT_B, Red); //pedestrian Red LED  off
		
		LED_on(PORT_A, Red); //Cars' Red On
		LED_on(PORT_B, Green); //pedestrian' Green On
		Delay_ms(5000);
		
		/*cars red off and Both Cars' & pedestrian Yellow is Blinking for 5 seconds*/
		
		LED_off(PORT_A, Red); //Cars' Red Off
		
		for(int i = 0; i < 10; i++)
		{
			LED_Blink(PORT_B, Yellow);	 // Blink pedestrian Yellow LED
			LED_Blink(PORT_A, Yellow);	 // Blink Cars' Blink Yellow LED
			Delay_ms(500);
		}
		
		LED_off(PORT_B, Green); //pedestrian Green Off
		
		LED_on(PORT_B, Red); //pedestrian Red On
		LED_on(PORT_A, Green); //Cars' Green On
		
		/*Go Back To Normal Mode*/
		APP_START();
	}
	 else
	 {
		 /*Go Back To Normal Mode*/
		 APP_START();
	 }
}

ISR(EXT_INT_0)
{
	
	 pedestrain_mode();
	
}



