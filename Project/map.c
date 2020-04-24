#include "map.h"
#include ""

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
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 
    1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 
    1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 
    1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 
    1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 
    1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0
};

void drawMap(uint8_t[] map)
{
	int i, j, x, y;
	ite = 0;
	x = 0, y = 0;

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (map[i * 12 + j] == 1)
			{
				lcd_draw_image(x, wall_tileWidthPixels, y, wall_tileHeightPixels, map, 0x0880, 0x0000);
			}
			x += 20;
		}
		y += 20;
	}

    return;
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