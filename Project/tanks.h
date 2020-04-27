#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "images.h"
#include "game.h"

typedef struct 
{
	PS2_DIR_t dir;
	uint16_t x;
	uint16_t y;
	const uint8_t* image;
	uint8_t width;
	uint8_t height;
	uint8_t health;
	uint8_t type;
} tanks;

typedef struct
{
	bool valid;
   PS2_DIR_t dir;
	uint16_t x;
	uint16_t y;
    bool player;
} bullet;

extern volatile tanks* player;
extern volatile const uint8_t enermy_size;
extern volatile tanks** enermy;
extern volatile bullet** shells;
extern volatile const uint8_t shell_size;

bool check_shot_on_target(volatile bullet * i);
void fire(uint16_t x, uint16_t y, PS2_DIR_t dir);

void set_dir(volatile tanks* tank, PS2_DIR_t dir);
void set_x(uint16_t x);
void set_y(uint16_t y);
void set_image(volatile tanks* tank);
