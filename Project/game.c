#include "game.h"

volatile uint16_t SHIP_X_COORD = 190;
volatile uint16_t SHIP_Y_COORD = 270;
volatile uint16_t INVADER_X_COORD = 50;
volatile uint16_t INVADER_Y_COORD = 40;
volatile bool ALERT_SPACE_SHIP[10];
volatile bool ALERT_INVADER = true;
volatile bool BUTTON_PRESSED = false;
char STUDENT_NAME[] = "Yichen Li and Marvin Zhang";
int i;


typedef struct
{
    int top;
    int bottom;
    int left;
    int right;
} Rectangle;

volatile tanks* player;
volatile tanks** enermy;
<<<<<<< Updated upstream
=======
volatile bullet** shells;
volatile const uint8_t shell_size = 4;
>>>>>>> Stashed changes
volatile const uint8_t enermy_size = 2;

void set_dir(volatile tanks* tank, PS2_DIR_t dir){tank->dir = dir;set_image(tank);}
void set_x(uint16_t x){player->x = x;}
void set_y(uint16_t y){player->y = y;}
void set_image(volatile tanks* tank){
	switch(tank->dir){
		case PS2_DIR_UP: 
		{
			tank->image = (uint8_t*)easytank_upBitmaps;
			tank->height = easytank_upHeightPixels;
			tank->width = easytank_upWidthPixels;
			break;
		}
		case PS2_DIR_DOWN: 
		{
			tank->image = (uint8_t*)&easytank_downBitmaps;
			tank->height = easytank_downHeightPixels;
			tank->width = easytank_downWidthPixels;
			break;
		}
		case PS2_DIR_LEFT: 
		{
			tank->image = (uint8_t*)&easytank_leftBitmaps;
			tank->height = easytank_leftHeightPixels;
			tank->width = easytank_leftWidthPixels;
			break;
		}
		case PS2_DIR_RIGHT: 
		{
			tank->image = (uint8_t*)&easytank_rightBitmaps;
			tank->height = easytank_rightHeightPixels;
			tank->width = easytank_rightWidthPixels;
			break;
		}
		default: return; 
	}
	return;
}


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
)
{
    // Check if out of bound based on the direction requested.
    switch (direction)
    {
    case PS2_DIR_LEFT:
        if (x_coord - 1 < image_width / 2)
            return true;
        break;
    case PS2_DIR_RIGHT:
        if (x_coord + 1 > (COLS - image_width / 2 - 1))     // -1 to adjust for the boundary (max = COLS - 1)
            return true;
       
        break;
    case PS2_DIR_UP:
        if (y_coord - 1 < image_height / 2)
            return true;
        break;
    case PS2_DIR_DOWN:
        if (y_coord + 1 > (ROWS - image_height / 2 - 1))    // -1 to adjust for the boundary (max = ROWS - 1)
            return true;
        break;
    default:
        return false;
    }
    return false;
}

//*****************************************************************************
// Determines if any part of the image would be off the screen if the image
// is moved in the specified direction.
//*****************************************************************************
bool check_moveable(
    volatile PS2_DIR_t direction,
    volatile uint16_t x_coord, 
    volatile uint16_t y_coord, 
    uint8_t image_height, 
    uint8_t image_width
)
{
		uint8_t map_index = get_pos(x_coord,y_coord);
	printf("map_index:%d, x:%d, y:%d\r",map_index,x_coord,y_coord);
    // Check if out of bound based on the direction requested.
    switch (direction)
    {
    case PS2_DIR_LEFT:
        if ((map_index%12 == 0) || (Sevastopol[map_index-1] == 1))
            return false;
        break;
    case PS2_DIR_RIGHT:
        if ((map_index%12 == 11) || (Sevastopol[map_index+1] == 1))
            return false;
        break;
    case PS2_DIR_UP:
        if ((map_index/12 == 0) || (Sevastopol[map_index-12] == 1))
            return false;
        break;
    case PS2_DIR_DOWN:
        if ((map_index/12 == 14) || (Sevastopol[map_index+12] == 1))
            return false;
        break;
    default:
        return true;
    }
    return true;
}

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
)
{
	clear_image(*x_coord, *y_coord);
    switch (direction)   // move images according to direction
    {
        case PS2_DIR_LEFT:
            (*x_coord)-=20;
            break;
        case PS2_DIR_RIGHT:
            (*x_coord)+=20;
            break;
        case PS2_DIR_UP:
            (*y_coord)-=20;
            break;
        case PS2_DIR_DOWN:
            (*y_coord)+=20;
            break;
        default:
            break;
    }

    return;
}

void clear_image(uint16_t x, uint16_t y){
	lcd_draw_image(
			x,          // X Center Point
			20,       // Image Horizontal Width
			y,          // Y Center Point
			20,      // Image Vertical Height
			shell_objBitmaps,           // Image
			LCD_COLOR_BLACK,            // Foreground Color
			LCD_COLOR_BLACK           // Background Color
			);
}

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
)
{
    // Check if any margin of the space ship is within the x/y range of the invader.
    bool left_margin = (int)(ship_x_coord - ship_width / 2) > (int)(invader_x_coord - invader_width / 2)
        && (int)(ship_x_coord - ship_width / 2) < (int)(invader_x_coord + invader_width / 2);
    bool right_margin = (int)(ship_x_coord + ship_width / 2) < (int)(invader_x_coord + invader_width / 2)
        && (int)(ship_x_coord + ship_width / 2) > (int)(invader_x_coord - invader_width / 2);
    bool up_margin = (int)(ship_y_coord + ship_height /2) < (int)(invader_y_coord + invader_height/2) 
        && (int)(ship_y_coord + ship_height / 2) > (int)(invader_y_coord - invader_height / 2);
    bool down_margin = (int)(ship_y_coord - ship_height /2) > (int)(invader_y_coord - invader_height/2) 
        && (int)(ship_y_coord - ship_height / 2) < (int)(invader_y_coord + invader_height / 2);

    // Based on the margin conditions specified above, check if the invader and space ship has overlapped.
    bool over = (left_margin) ? up_margin | down_margin : (right_margin) ? up_margin | down_margin : false;

    return over;
}

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
)
{
    // Check if any margin of the space ship is within the x/y range of the invader.
    bool left_margin = (int)(ship_x_coord - ship_width / 2) > (int)(invader_x_coord - invader_width / 2)
        && (int)(ship_x_coord - ship_width / 2) < (int)(invader_x_coord + invader_width / 2) && (*contact_dir ==PS2_DIR_LEFT);
    bool right_margin = (int)(ship_x_coord + ship_width / 2) < (int)(invader_x_coord + invader_width / 2)
        && (int)(ship_x_coord + ship_width / 2) > (int)(invader_x_coord - invader_width / 2) && (*contact_dir ==PS2_DIR_UP);
    bool up_margin = (int)(ship_y_coord + ship_height /2) < (int)(invader_y_coord + invader_height/2) 
        && (int)(ship_y_coord + ship_height / 2) > (int)(invader_y_coord - invader_height / 2) && (*contact_dir ==PS2_DIR_RIGHT);
    bool down_margin = (int)(ship_y_coord - ship_height /2) > (int)(invader_y_coord - invader_height/2) 
        && (int)(ship_y_coord - ship_height / 2) < (int)(invader_y_coord + invader_height / 2) && (*contact_dir ==PS2_DIR_DOWN);
		
		bool over;
		

    // Based on the margin conditions specified above, check if the invader and space ship has overlapped.
     over = left_margin || up_margin || down_margin || right_margin;

    return over;
}

bool check_shot_on_target(){
	
<<<<<<< Updated upstream
=======
	int i;
	printf("fired x:%d, y:%d\n", x,y);
	
	switch(dir)
	{
		case PS2_DIR_UP:
			
			break;
		case PS2_DIR_DOWN:
			break;
		case PS2_DIR_LEFT:
			break;
		case PS2_DIR_RIGHT:
			break;
		default:
			break;
	}
	
	for (i = 0; i<shell_size; i++){
		if(!(shells[i]->valid)){
			shells[i]->valid = true;
			shells[i]->x = x;
			shells[i]->y = y;
			shells[i]->dir = dir;
		}
	}
>>>>>>> Stashed changes
}

//*****************************************************************************
// Main application for HW3
//*****************************************************************************
void game(void)
{		
	char data[80];
	int index;
	bool game_over = false;
	for (i = 0; i<10;i++){ ALERT_SPACE_SHIP[i] = true;}
	player = malloc(sizeof(tanks));
	set_pos(1,&(player->x),&(player->y));
	player->dir = PS2_DIR_CENTER;
	player->image = (uint8_t*)easytank_downBitmaps;
	player->height = easytank_downHeightPixels;
	player->width = easytank_downWidthPixels;
	enermy = malloc(sizeof(tanks*)*enermy_size);
	
	for (index = 0; index < enermy_size; index++){
		enermy[index] = malloc(sizeof(tanks));
		enermy[index]->x = 190-index*60;
		enermy[index]->y = 270;
		enermy[index]->dir = PS2_DIR_CENTER;
		enermy[index]->image = (uint8_t*)easytank_downBitmaps;
		enermy[index]->height = easytank_downHeightPixels;
		enermy[index]->width = easytank_downWidthPixels;
	}
	
	printf("Drawing map...\n");
	// Map Test
	drawMap(Sevastopol);
	drawHP(100);
	//while (true){};
	
	while(true)
	{	
	//				put_string("player statistics\n\r");
	//				sprintf(data,"%d\n\r",player->x);
	//				put_string(data);

//		for (index = 0; index < enermy_size; index++){
//		if(ALERT_SPACE_SHIP[index])
//		{
//			ALERT_SPACE_SHIP[index] = false;
//			lcd_draw_image(
//				enermy[index]->x,                       // X Center Point
//				enermy[index]->width,   // Image Horizontal Width
//				enermy[index]->y,                       // Y Center Point
//				enermy[index]->height,  // Image Vertical Height
//				enermy[index]->image,       // Image
//				LCD_COLOR_BLUE,           // Foreground Color
//				LCD_COLOR_BLACK          // Background Color
//			);

//		//            game_over = check_game_over(
//		//                                        SHIP_X_COORD,
//		//                                        SHIP_Y_COORD,
//		//                                        space_shipHeightPixels,
//		//                                        space_shipWidthPixels,
//		//                                        INVADER_X_COORD,
//		//                                        INVADER_Y_COORD,
//		//                                        easytank_rightHeightPixels,
//		//                                        easytank_rightWidthPixels
//		//                                    );
//		}
//		}

		if(ALERT_INVADER)
		{
			ALERT_INVADER = false;

			lcd_draw_image(
			player->x,          // X Center Point
			player->width,       // Image Horizontal Width
			player->y,          // Y Center Point
			player->height,      // Image Vertical Height
			player->image,           // Image
			LCD_COLOR_RED,            // Foreground Color
			LCD_COLOR_BLACK           // Background Color
			);

			//             game_over = check_game_over(
			//                                            SHIP_X_COORD,
			//                                            SHIP_Y_COORD,
			//                                            space_shipHeightPixels,
			//                                            space_shipWidthPixels,
			//                                            player->x,
			//                                            player->y,
			//                                            player->height,
			//                                            player->width
			//                                        );
			}

			if(BUTTON_PRESSED)
			{
				BUTTON_PRESSED = false;	// Deassert BUTTON_PRESSED flag
				switch(button)
				{
<<<<<<< Updated upstream
					case(BUTTON_UP)	:	
=======
					case(BUTTON_UP)	:	{
						fire(player->x,player->y,player->dir);
						//printf("pressed button\n");
>>>>>>> Stashed changes
						break;
					case(BUTTON_DOWN):
						break;
					case(BUTTON_LEFT):
						break;
					case(BUTTON_RIGHT):
						break;
					default:
						break;
				}
			}

	}   
}
