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

#include "project_hardware_init.h"

//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************
void init_hardware(void)
{
  lcd_config_gpio();
  lcd_config_screen();
  lcd_clear_screen(LCD_COLOR_BLACK);
  ps2_initialize();
	io_expander_init();
  init_serial_debug(true, true);
  // Update the Space Shipt 60 times per second.
  gp_timer_config_32(TIMER2_BASE,TIMER_TAMR_TAMR_PERIOD, 1000000, false, true);
  gp_timer_config_32(TIMER3_BASE,TIMER_TAMR_TAMR_PERIOD, 1000000, false, true);
  gp_timer_config_32(TIMER4_BASE,TIMER_TAMR_TAMR_PERIOD, 50000, false, true);
}

