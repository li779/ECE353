#ifndef __HW3_STAFF_H__
#define __HW3_STAFF_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "TM4C123.h"
#include "project_interrupts.h"
#include "game.h"
#include "ps2.h"
#include "images.h"

extern void initialize_serial_debug(void);
extern void put_string(char *data);

//*****************************************************************************
// Generates a random number
// https://en.wikipedia.org/wiki/Linear-feedback_shift_register  -- DO NOT MODIFY
//*****************************************************************************
uint16_t generate_random_number(void);

//*****************************************************************************
// Generates the the new direction and number of pixels  -- DO NOT MODIFY
//*****************************************************************************
PS2_DIR_t get_new_direction(bool* bump, int tank_index, PS2_DIR_t curr_direction);

void auto_shoot(int index);

//*****************************************************************************
// Generates the the new direction and number of pixels  -- DO NOT MODIFY
//*****************************************************************************
uint16_t get_new_move_count(void);

//*****************************************************************************
// Validates HW3 Hardware -- DO NOT MODIFY
//*****************************************************************************
bool hw3_hardware_validate(void);

#endif
