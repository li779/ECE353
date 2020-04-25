#include "breathing_led.h"

uint8_t R = 0, G = 0, B = 0;

void breathing_led_init(void)
{
	lp_io_init();
	
	// Allow Timer1 to send interrupts out, but set a low priority
	NVIC_SetPriority(TIMER1A_IRQn, 5);
	NVIC_EnableIRQ(TIMER1A_IRQn);
	
	
	
}