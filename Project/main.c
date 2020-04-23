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

volatile bool BUTTON_PRESSED = false;

//*****************************************************************************
//*****************************************************************************
void DisableInterrupts(void)
{
  __asm {
         CPSID  I
  }
}

//*****************************************************************************
//*****************************************************************************
void EnableInterrupts(void)
{
  __asm {
    CPSIE  I
  }
}

//*****************************************************************************
//*****************************************************************************

void delay(int cnt)
{
	int i;
	for(i = 0; i < cnt * 7000; i++)
	{}
	return;
}


//*****************************************************************************
//*****************************************************************************
int 
main(void)
{
		uint8_t *data = (uint8_t *)malloc(sizeof(uint8_t));
		int i = 0;
		uint8_t cmd_cnt = 0;
		BUTTON_t button = BUTTON_NONE;
	
		DisableInterrupts();
	
		init_serial_debug(true, true);
		io_expander_init();

		printf("ECE 353 Final Project\nYichen Li and Marvin Zhang\n");
	
		EnableInterrupts();
		
		io_expander_write_reg(MCP23017_GPIOA_R, 0xFF);
		//io_expander_read_reg(MCP23017_GPIOB_R, data);
		
		while(1)
		{
				/*printf("Command Count: %d\n\r", cmd_cnt);
				printf("data: 0x%X\n\r", *data);
				while(i < 5000000){i++;}
				i = 0;
				cmd_cnt++;
				io_expander_write_reg(MCP23017_GPIOA_R, cmd_cnt);*/
				
			
				//printf("data: %d",data);
			
				if(BUTTON_PRESSED)
				{
					printf("Command Count: %d\n\r", cmd_cnt);

					cmd_cnt++;
				
					io_expander_write_reg(MCP23017_GPIOA_R, cmd_cnt);
					
					button = get_button_status();
					
					switch(button)
					{
						case BUTTON_UP	:
							printf("Button UP pressed!\n");
							break;
						case BUTTON_DOWN	:	
							printf("Button DOWN pressed!\n");
							break;
						case BUTTON_LEFT	:	
							printf("Button LEFT pressed!\n");
							break;
						case BUTTON_RIGHT	:	
							printf("Button RIGHT pressed!\n");
							break;
						case BUTTON_NONE	:	
							printf("No Button pressed!\n");
							break;
					}
					
					BUTTON_PRESSED = false;
				}
				else
				{
					printf("No Button pressed!\n");
					delay(1000);
				}
		}
    while(1){};
}
