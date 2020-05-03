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
	
	uint16_t EEPROM_SCORE_ADDR = 0x0000;
	

	RESTART = true;		// For 1st-time
	
	hardwareInit();		// Initialize all hardware
	
	printf("======ECE 353 Final Project=======\nBy: Yichen Li and Marvin Zhang\n");
	
	delay(10);
	
	MAP_SEL = 0;
	
	DisableInterrupts();

	while(1)
	{
		if(RESTART | CONTINUE)
		{
			
			eeprom_byte_read(EEPROM_I2C_BASE, EEPROM_SCORE_ADDR, &LAST_SCORE);
			printf("Last Score (%d / 255) read from EEPROM. \n", LAST_SCORE);
			delay(50);
			
			if(RESTART | GAME_OVER)
			{
				RESTART = false;
				GAME_OVER = false;
				game_start_page();
			}
	
			if(CONTINUE)
				CONTINUE = false;
			
			game_story_page();
			EnableInterrupts();
			printf("Press SPACE to pause the game. Another press will continue the game. \n");
			drawSCORE(LAST_SCORE);
			delay(10);
			game();
			
			if(SCORE > LAST_SCORE)
			{
				eeprom_byte_write(EEPROM_I2C_BASE, EEPROM_SCORE_ADDR, SCORE);
				delay(50);
				printf("Score: (%d / 255) saved into EEPROM. \n", SCORE);
				delay(50);
			}
			DisableInterrupts();
	}
	}
}
