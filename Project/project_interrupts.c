// Copyright (c) 2015-19, Joe Krachey
// All rights reserved.
//
// Redistribution and use in source or binary form, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions in source form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in 
//    the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "main.h"
#include "io_expander.h"
#include "i2c.h"
#include "project_interrupts.h"

static volatile BUTTON_t button = BUTTON_NONE;

BUTTON_t get_button_status()
{
	return button;
}

// Note: PF0 for io_expander GPIOB_R interrupt
void GPIOF_Handler(void)
{
		GPIOA_Type  *gpioPort;
		uint8_t * data;
		gpioPort = (GPIOA_Type *)IO_EXPANDER_IRQ_GPIO_BASE;
	
		// Read from MCP23017, it will auto clear its own interrupt status
		io_expander_read_reg(MCP23017_INTCAPB_R, data);
		switch((*data & 0x0F))
		{
			case 0x01	:
					button = BUTTON_UP;
					break;
			case 0x02	:
					button = BUTTON_DOWN;
					break;
			case 0x04	:
					button = BUTTON_LEFT;
					break;
			case 0x08	:	
					button = BUTTON_RIGHT;
					break;
			default:	
					button = BUTTON_NONE;
					break;
		}
		
    // Clear the interrupt status on PF0
    gpioPort->ICR |= 0x01;
    
}