#ifndef __TRANSITION_H__
#define __TRANSITION_H__
#endif

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "TM4C123.h"
#include "driver_defines.h"
#include "launchpad_io.h"
//#include "project_interrupts.h"
#include "gpio_port.h"
#include "lcd.h"
#include "io_expander.h"
#include "map.h"

extern const uint8_t start_pageBitmaps[];
extern const uint16_t start_pageWidthPixels;
extern const uint16_t start_pageHeightPixels;

void game_start_page(void);
void game_transition_success_page(void);
void game_transition_fail_page(void);
void game_transition_victory_page(void);
void game_story_page(void);
