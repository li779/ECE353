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

BUTTON_t button = BUTTON_NONE;

uint8_t data;

BUTTON_t get_button_status()
{
	return button;
}

// Note: PF0 for io_expander GPIOB_R interrupt
void GPIOF_Handler(void)
{
		// Read from MCP23017
		io_expander_read_reg(MCP23017_GPIOB_R, &data);
	
		// Assert button_pressed flag only if flag has been de-asserted
		if(BUTTON_PRESSED)
		{
			GPIOF->ICR |= 0xFF;
			return;
		}
			
		else
		{
			if((data & 0x0F) != 0x0F)
				BUTTON_PRESSED = true;
		}
	
		switch((data & 0x0F))
		{
			case 0x0E	:
					button = BUTTON_UP;
					break;
			case 0x0D	:
					button = BUTTON_DOWN;
					break;
			case 0x0B	:
					button = BUTTON_LEFT;
					break;
			case 0x07	:	
					button = BUTTON_RIGHT;
					break;
			default:	
					button = BUTTON_NONE;
					break;
		}
		
		printf("Data received: %X \n", data);
		
    // Clear the interrupt status on PF0
    GPIOF->ICR |= 0xFF;
		
		// Clear the interrupt status on MCP23017
		//io_expander_read_reg(MCP23017_GPIOB_R, data);
    
}