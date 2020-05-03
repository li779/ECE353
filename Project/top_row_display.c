#include <stdint.h>

#include "top_row_display.h"

// Character bitmaps for Unispace 6pt


const uint8_t colon[] = 
{
	// @0 ':' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x0C, 0x00, //     ##     
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x0C, 0x00, //     ##     
	0x00, 0x00, //           
	0x00, 0x00, //     
};

const uint8_t H[] = 
{
	// @0 'H' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x36, 0x00, //   ## ##   
	0x36, 0x00, //   ## ##   
	0x3E, 0x00, //   #####   
	0x36, 0x00, //   ## ##   
	0x36, 0x00, //   ## ##   
	0x36, 0x00, //   ## ##   
	0x00, 0x00, //           
	0x00, 0x00, //     
};

const uint8_t P[] = 
{
	// @0 'P' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x3C, 0x00, //   ####    
	0x34, 0x00, //   ## #    
	0x36, 0x00, //   ## ##   
	0x3C, 0x00, //   ####    
	0x30, 0x00, //   ##      
	0x30, 0x00, //   ##      
	0x00, 0x00, //           
	0x00, 0x00, //       
};

const uint8_t S[] = 
{
	// @0 'S' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x1C, 0x00, //    ###    
	0x30, 0x00, //   ##      
	0x1C, 0x00, //    ###    
	0x06, 0x00, //      ##   
	0x04, 0x00, //      #    
	0x1C, 0x00, //    ###    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t zero[] =
{
	// @0 '0' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x1C, 0x00, //    ###    
	0x26, 0x00, //   #  ##   
	0x2E, 0x00, //   # ###   
	0x2E, 0x00, //   # ###   
	0x36, 0x00, //   ## ##   
	0x1C, 0x00, //    ###    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t one[] =
{
	// @20 '1' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x18, 0x00, //    ##     
	0x08, 0x00, //     #     
	0x08, 0x00, //     #     
	0x08, 0x00, //     #     
	0x08, 0x00, //     #     
	0x3C, 0x00, //   ####    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t two[] =
{
	// @40 '2' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x1C, 0x00, //    ###    
	0x06, 0x00, //      ##   
	0x1C, 0x00, //    ###    
	0x30, 0x00, //   ##      
	0x30, 0x00, //   ##      
	0x3E, 0x00, //   #####   
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t three[] =
{
	// @60 '3' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x3C, 0x00, //   ####    
	0x04, 0x00, //      #    
	0x0C, 0x00, //     ##    
	0x04, 0x00, //      #    
	0x06, 0x00, //      ##   
	0x3C, 0x00, //   ####    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t four[] =
{
	// @80 '4' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x0C, 0x00, //     ##    
	0x0C, 0x00, //     ##    
	0x14, 0x00, //    # #    
	0x14, 0x00, //    # #    
	0x3E, 0x00, //   #####   
	0x04, 0x00, //      #    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t five[] =
{
	// @100 '5' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x3C, 0x00, //   ####    
	0x30, 0x00, //   ##      
	0x3C, 0x00, //   ####    
	0x06, 0x00, //      ##   
	0x04, 0x00, //      #    
	0x3C, 0x00, //   ####    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t six[] =
{
	// @120 '6' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x1C, 0x00, //    ###    
	0x30, 0x00, //   ##      
	0x3C, 0x00, //   ####    
	0x36, 0x00, //   ## ##   
	0x36, 0x00, //   ## ##   
	0x1C, 0x00, //    ###    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t seven[] =
{
	// @140 '7' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x3E, 0x00, //   #####   
	0x04, 0x00, //      #    
	0x0C, 0x00, //     ##    
	0x08, 0x00, //     #     
	0x18, 0x00, //    ##     
	0x10, 0x00, //    #      
	0x00, 0x00, //           
	0x00, 0x00, //           

};

const uint8_t eight[] =
{
	// @160 '8' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x1C, 0x00, //    ###    
	0x34, 0x00, //   ## #    
	0x1C, 0x00, //    ###    
	0x36, 0x00, //   ## ##   
	0x36, 0x00, //   ## ##   
	0x1C, 0x00, //    ###    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t nine[] =
{
	// @180 '9' (10 pixels wide)
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x1C, 0x00, //    ###    
	0x36, 0x00, //   ## ##   
	0x36, 0x00, //   ## ##   
	0x1E, 0x00, //    ####   
	0x06, 0x00, //      ##   
	0x1C, 0x00, //    ###    
	0x00, 0x00, //           
	0x00, 0x00, //           
};

const uint8_t font_width = 10, font_height = 10;

void drawHP(int HP)
{
	int i = 0, multiplier = 100;
	int num = 0;
	lcd_draw_image(10, font_width, 10, font_height, H, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
	lcd_draw_image(20, font_width, 10, font_height, P, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
	lcd_draw_image(30, font_width, 10, font_height, colon, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
	
	if (HP > 999)
		HP = 999;
	
	for(i = 0; i < 3; i++)
	{
		num = HP / multiplier;
		switch(num)
		{
			case 0	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, zero, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 1	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, one, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 2	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, two, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 3	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, three, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 4	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, four, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 5	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, five, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 6	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, six, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 7	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, seven, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 8	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, eight, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 9	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, nine, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			default	:	
				lcd_draw_image((40 + i * 10), font_width, 10, font_height, zero, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
		}
		HP -= num * multiplier;
		multiplier /= 10;
	}
	
	return;
}

void drawSCORE(int score)
{
	int i = 0, multiplier = 100;
	int num = 0;
	lcd_draw_image(180, font_width, 10, font_height, H, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
	lcd_draw_image(190, font_width, 10, font_height, S, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
	lcd_draw_image(200, font_width, 10, font_height, colon, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
	
	if (score > 999)
		score = 999;
	
	for(i = 0; i < 3; i++)
	{
		num = score / multiplier;
		switch(num)
		{
			case 0	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, zero, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 1	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, one, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 2	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, two, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 3	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, three, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 4	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, four, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 5	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, five, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 6	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, six, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 7	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, seven, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 8	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, eight, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			case 9	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, nine, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
			default	:	
				lcd_draw_image((210 + i * 10), font_width, 10, font_height, zero, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
				break;
		}
		score -= num * multiplier;
		multiplier /= 10;
	}
	
	return;
}