#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "TM4C123.h"
#include "gpio_port.h"
#include "ps2.h"
#include "lcd.h"
#include "timers.h"
#include "images.h"
#include "io_expander.h"
#include "map.h"
#include "top_row_display.h"
#include "transition.h"

typedef enum{
  PS2_DIR_UP,
  PS2_DIR_DOWN,
  PS2_DIR_LEFT,
  PS2_DIR_RIGHT,
  PS2_DIR_CENTER,
  PS2_DIR_INIT
} PS2_DIR_t;

typedef enum BUTTON_t{
	BUTTON_LEFT, 
	BUTTON_RIGHT, 
	BUTTON_UP, 
	BUTTON_DOWN, 
	BUTTON_NONE
} BUTTON_t;




extern void initialize_serial_debug(void);
extern void put_string(char *data);


extern volatile bool ALERT_SPACE_SHIP[10];
extern volatile bool ALERT_INVADER;
extern volatile bool SHELL_MOVE;

extern char STUDENT_NAME[];


extern volatile bool PS2_MOVE;
extern volatile bool BUTTON_PRESSED;
extern volatile BUTTON_t button;

extern volatile bool IN_PROGRESS;
extern volatile bool RESTART;
extern volatile bool CONTINUE;
extern volatile bool EXIT;
extern volatile bool GAME_OVER;

//*****************************************************************************
// Determines if any part of the image would be off the screen if the image
// is moved in the specified direction.
//*****************************************************************************
bool contact_edge(
    volatile PS2_DIR_t direction,
    volatile uint16_t x_coord, 
    volatile uint16_t y_coord, 
    uint8_t image_height, 
    uint8_t image_width
);

//*****************************************************************************
// Moves the image by one pixel in the provided direction.  The second and 
// third parameter should modify the current location of the image (pass by
// reference)
//*****************************************************************************
void move_image(
    volatile PS2_DIR_t direction,
    volatile uint16_t *x_coord, 
    volatile uint16_t *y_coord, 
    uint8_t image_height, 
    uint8_t image_width
);

//*****************************************************************************
// 1: game lost
// 2 : game win
// 0: game continue
// 
// 
//*****************************************************************************
uint8_t check_game_over();
				
bool check_bump(
	volatile PS2_DIR_t* contact_dir,
    volatile uint16_t ship_x_coord, 
    volatile uint16_t ship_y_coord, 
    uint8_t ship_height, 
    uint8_t ship_width,
    volatile uint16_t invader_x_coord, 
    volatile uint16_t invader_y_coord, 
    uint8_t invader_height, 
    uint8_t invader_width
);
		
bool check_moveable(
    volatile PS2_DIR_t direction,
    volatile uint16_t x_coord, 
    volatile uint16_t y_coord, 
    uint8_t image_height, 
    uint8_t image_width
);
		
void clear_image(uint16_t x, uint16_t y);


//*****************************************************************************
// Main application for Game
//*****************************************************************************
void game(void);
				

#endif


