#include "breathing_led.h"



void breathing_led_init(void)
{
	lp_io_init();
	
	// Allow Timer1 to send interrupts out, but set a low priority
	NVIC_SetPriority(TIMER1A_IRQn, 5);
	NVIC_EnableIRQ(TIMER1A_IRQn);
	
	
}