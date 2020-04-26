#include <stdint.h>

#include "map.h"
#include "lcd.h"

const uint8_t wall_tileBitmaps[] =
{
	0xFF, 0xDF, 0xF0, // ########## #########
	0xFF, 0xDF, 0xF0, // ########## #########
	0xFF, 0xDF, 0xF0, // ########## #########
	0x00, 0x00, 0x00, //                     
	0xEF, 0xFF, 0x70, // ### ############ ###
	0xEF, 0xFF, 0x70, // ### ############ ###
	0xEF, 0xFF, 0x70, // ### ############ ###
	0x00, 0x00, 0x00, //                     
	0xFF, 0xDF, 0xF0, // ########## #########
	0xFF, 0xDF, 0xF0, // ########## #########
	0xFF, 0xDF, 0xF0, // ########## #########
	0x00, 0x00, 0x00, //                     
	0xEF, 0xFF, 0x70, // ### ############ ###
	0xEF, 0xFF, 0x70, // ### ############ ###
	0xEF, 0xFF, 0x70, // ### ############ ###
	0x00, 0x00, 0x00, //                     
	0xFF, 0xDF, 0xF0, // ########## #########
	0xFF, 0xDF, 0xF0, // ########## #########
	0xFF, 0xDF, 0xF0, // ########## #########
	0xEF, 0xFF, 0x70, // ### ############ ###
};

const uint8_t wall_tileWidthPixels = 20;
const uint8_t wall_tileHeightPixels = 20;

const uint8_t water_tileBitmaps[] =
{
	0xFF, 0xFF, 0xF0, // ####################
	0xC7, 0x8F, 0x10, // ##   ####   ####   #
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
	0xF1, 0xF1, 0xF0, // ####   #####   #####
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
	0xC7, 0x8F, 0x10, // ##   ####   ####   #
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
	0xF1, 0xF1, 0xF0, // ####   #####   #####
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
	0xC7, 0x8F, 0x10, // ##   ####   ####   #
	0xFF, 0xFF, 0xF0, // ####################
	0xFF, 0xFF, 0xF0, // ####################
};

const uint8_t water_tileWidthPixels = 20;
const uint8_t water_tileHeightPixels = 20;

const uint8_t Sevastopol[] =
{
    1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 
    1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 
    1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 
    1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 
    1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 
    1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 
    1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 
    1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 
    1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0
};

const uint8_t Kursk[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 
    0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const uint8_t Berlin[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0,
    0, 1, 0, 2, 2, 0, 0, 0, 2, 0, 1, 0, 
    0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
    2, 0, 2, 2, 0, 0, 0, 0, 2, 2, 0, 2, 
    2, 0, 2, 2, 2, 0, 0, 2, 2, 2, 0, 2, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

uint8_t MAP_SEL = 0;	// 0 - Sevastopol    1 - Kursk     2 - Berlin

void drawMap(const uint8_t map[])
{
	int i, j, x, y;
	x = -10, y = 10;
	
	//lcd_draw_image(230, wall_tileWidthPixels, 310, wall_tileHeightPixels, wall_tileBitmaps, 0xFFFF, 0x0000);
	
	for (i = 0; i < 15; i++)
	{
		y += 20;
		x = -10;
		for (j = 0; j < 12; j++)
		{
			x += 20;
			if (map[i * 12 + j] == 1 && MAP_SEL == 0)
			{
				lcd_draw_image(x, wall_tileWidthPixels, y, wall_tileHeightPixels, wall_tileBitmaps, LCD_COLOR_GRAY, LCD_COLOR_BLACK);
			}
			else if (map[i * 12 + j] == 1 && MAP_SEL == 1)
			{
				lcd_draw_image(x, wall_tileWidthPixels, y, wall_tileHeightPixels, wall_tileBitmaps, LCD_COLOR_BROWN, LCD_COLOR_BLACK);
			}
			else if (map[i * 12 + j] == 1 && MAP_SEL == 2)
			{
				lcd_draw_image(x, wall_tileWidthPixels, y, wall_tileHeightPixels, wall_tileBitmaps, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
			}
			else if (map[i * 12 + j] == 2)
			{
				lcd_draw_image(x, water_tileWidthPixels, y, water_tileHeightPixels, water_tileBitmaps, LCD_COLOR_BLUE, LCD_COLOR_BLACK);
			}
		}
	}

    return;
}

const uint8_t * getMap(void)
{
	switch(MAP_SEL)
	{
		case 0:
			return Sevastopol;
			break;
		case 1:
			return Kursk;
			break;
		case 2:
			return Berlin;
			break;
	}
}

uint8_t get_pos(uint16_t x, uint16_t y){
	return (uint8_t)((x/20)+((y-20)/20)*12);
}
void set_pos(uint8_t index, volatile uint16_t* x, volatile uint16_t* y){
	*x = (index%12)*20 + 10;
	*y = (index/12)*20 + 30;
	return;
}
uint16_t get_x(uint8_t index){
	return (index%12)*20 + 10;
}
uint16_t get_y(uint8_t index){
	return (index/12)*20 + 30;
}
/*
void lcd_draw_image(
	uint16_t x_start,                 // X coordinate starting address
	uint16_t image_width_bits,        // image width
	uint16_t y_start,                 // Y coordinate starting address
	uint16_t image_height_pixels,     // image height
	const uint8_t* image,             // bitmap of the image
	uint16_t fColor,                  // foreground color
	uint16_t bColor                   // background color
);*/