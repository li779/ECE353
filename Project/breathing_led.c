  
#include "breathing_led.h"

uint16_t R = 0, G = 0, B = 0;

uint16_t R_temp = 0, G_temp = 0, B_temp = 0;

bool RGB_direction = false, RGB_update = false;

/*
** Set up PWM M1PWM5, M1PWM6, M1PWM7	(Note: NOT working, changing to another way of implementing breathing led)
*/
void PWM_init(void)
{
		
	SYSCTL->RCGC0 |= SYSCTL_RCGC0_PWM0;		// Send clock signal to PWM module
	SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOF;	// RCGC enable clock to PortF
	GPIOF->AFSEL |= 0x0E;					// Select PF1, PF2, PF3 Alternate Function
	GPIOF->PCTL |= (0x05 << 4 | 0x05 << 8 | 0x05 << 12);	// PF1, PF2, PF3 select PWM
	
	SYSCTL->RCC &= (~0x001E0000);			// Set PWM clock frequency to be SysFreq
	
	delay(1000);	// Wait for PWM module to receive clock signal
	
	PWM1->CTL = 0x00000000;					// Disable PWM1
	
	PWM1->ENABLE = 0x00;
	
	// Set count-down mode for PWM1-GEN2 and PWM1-GEN3
	PWM1->_2_GENA |= 0x008C;
	PWM1->_2_GENB |= 0x080C;
	PWM1->_3_GENA |= 0x008C;
	PWM1->_3_GENB |= 0x080C;
	
	// Set PWM to count down from 255
	PWM1->_2_LOAD |= 255;
	PWM1->_3_LOAD |= 255;
	
	// These values should be later modified in timer1 interrupt handler
	PWM1->_2_CMPA = 0;
	PWM1->_3_CMPA = 0;
	PWM1->_2_CMPB = 255;
	PWM1->_3_CMPB = 255;
	
	PWM1->CTL |= 0x00000001;	// Enable PWM1
	
	PWM1->ENABLE = 0xE0;	// Enable M1PWM5, M1PWM6, M1PWM7
	
}

void breathing_led_init(void)
{
	lp_io_init();
	
	GPIOF->DATA = 0x0E;
	
	//PWM_init();
	
}