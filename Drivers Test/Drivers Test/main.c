/*
 * On-demand Traffic light control.c
 *
 * Created: 1/28/2023 12:40:08 PM
 
 * Author : Mahmoud Zain Salah
 */ 


#include "ECUAL/Button Driver/Button.h" //Button Driver
#include "ECUAL/LED Driver/LED.h" //LED Driver



int main(void)
{
	
		
		// DIO & LED Drivers Test init - Write - Toggle 
	
		LED_init(PORT_A, 0); // LED AND DIO init functions Test
	
		LED_on(PORT_A, 0);  // LED AND DIO Write functions Test
	
		Delay_ms(2000); // Timer0 Delay function Test
	
		LED_off(PORT_A, 0); // LED AND DIO Write functions Test
	
	
		for(int i = 0; i < 4; i++)
		{
			LED_Blink(PORT_A, 0);         //LED AND DIO Toggle Functions test
			Delay_ms(250); 
		}
	
	while(1)
	{
		// INT0 interrupt function test
		set_interrupet_init();
			
		Button_init(PORT_D, 2); // initialize portD - pin 2 as input

		// Button Driver Test
	
		uint8_t State = LOW; //Button state Variable
	
		Button_init(PORT_B, 0); //Button init Function test initialize pin 0 as input
	
		Button_read(PORT_B, 0, &State);
	
		if(State == HIGH)
		{
			for(int i = 0; i < 4; i++)
			{
				LED_Blink(PORT_A, 0);         //If Button is pressed Blink PortA - pin 0 LED
				Delay_ms(250);
			}
		}
	
	
	}	
	

	
}


//interrupt Function
ISR(EXT_INT_0)
{
	
	LED_init(PORT_C, 0);
	LED_on(PORT_C, 0);  
	Delay_ms(1000);         // if Button is pressed   PortA - Pin 0 LED Will Turn On For 1 Second
	LED_off(PORT_C, 0); 
	
	
	main();    // Back To main Function again
}