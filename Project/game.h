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

typedef struct 
{
	PS2_DIR_t dir;
	uint16_t x;
	uint16_t y;
	uint8_t* image;
	uint8_t width;
	uint8_t height;
} tanks;

typedef struct
{
    PS2_DIR_t dir;
	uint16_t x;
	uint16_t y;
    bool player;
} bullet;

extern void initialize_serial_debug(void);
extern void put_string(char *data);

extern volatile uint16_t SHIP_X_COORD;
extern volatile uint16_t SHIP_Y_COORD;
extern volatile uint16_t INVADER_X_COORD;
extern volatile uint16_t INVADER_Y_COORD;
extern volatile bool ALERT_SPACE_SHIP[10];
extern volatile bool ALERT_INVADER;

extern char STUDENT_NAME[];
extern volatile tanks* player;
extern volatile const uint8_t enermy_size;
extern volatile tanks** enermy;

extern volatile bool BUTTON_PRESSED;
extern volatile BUTTON_t button;
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
// Determines is any portion of the two images are overlapping.  An image is
// considered to be overlapping if the two rectangles determined by the image
// height and widths are overlapping.  An overlap occurs even if the area that
// overlaps are portions of the images where the pixels do not display on the
// screen.
//*****************************************************************************
bool check_game_over(
    volatile uint16_t ship_x_coord, 
    volatile uint16_t ship_y_coord, 
    uint8_t ship_height, 
    uint8_t ship_width,
    volatile uint16_t invader_x_coord, 
    volatile uint16_t invader_y_coord, 
    uint8_t invader_height, 
    uint8_t invader_width
);
				
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
//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************
void init_hardware(void);
        
//*****************************************************************************
// Main application for Game
//*****************************************************************************
void game(void);
				
void set_dir(volatile tanks* tank, PS2_DIR_t dir);
void set_x(uint16_t x);
void set_y(uint16_t y);
void set_image(volatile tanks* tank);
#endif


