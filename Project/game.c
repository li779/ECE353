#include "game.h"


volatile bool ALERT_SPACE_SHIP[10];
volatile bool ALERT_INVADER = true;
volatile bool BUTTON_PRESSED = false;
volatile bool SHELL_MOVE = false;
volatile bool PS2_MOVE = false;

volatile bool RESTART = false;
volatile bool CONTINUE = false;
volatile bool EXIT = false;
volatile bool GAME_OVER = false;
volatile bool IN_PROGRESS = false;

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
volatile bullet** shells;
volatile const uint8_t shell_size = 10;
volatile const uint8_t enermy_size = 2;

void set_dir(volatile tanks* tank, PS2_DIR_t dir){tank->dir = dir;set_image(tank);}
void set_x(uint16_t x){player->x = x;}
void set_y(uint16_t y){player->y = y;}

//*****************************************************************************
//*****************************************************************************
static void DisableInterrupts(void)
{
  __asm {
         CPSID  I
  }
}

//*****************************************************************************
//*****************************************************************************
static void EnableInterrupts(void)
{
  __asm {
    CPSIE  I
  }
}

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
// Determines if any part of the image would be off the screen or hit wall 
// if the image is moved in the specified direction.
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
		if(getMap()[map_index] == 1) return false;
	
    // Check if out of bound based on the direction requested.
    switch (direction)
    {
    case PS2_DIR_LEFT:{
        if ((map_index%12 == 0) || (getMap()[map_index-1] == 1)){
            return false;
				}
        break;
			}
    case PS2_DIR_RIGHT:
        if ((map_index%12 == 11) || (getMap()[map_index+1] == 1))
            return false;
        break;
    case PS2_DIR_UP:
        if ((map_index/12 == 0) || (getMap()[map_index-12] == 1))
            return false;
        break;
    case PS2_DIR_DOWN:
        if ((map_index/12 == 14) || (getMap()[map_index+12] == 1))
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
			20,       	// Image Horizontal Width
			y,          // Y Center Point
			20,      	// Image Vertical Height
			//shell_objBitmaps,           // Image
			blank_tileBitmaps,
			LCD_COLOR_BLACK,            // Foreground Color
			LCD_COLOR_BLACK           // Background Color
			);
}

//*****************************************************************************
// 1: game lost
// 2 : game win
// 0: game continue
// 
// 
//*****************************************************************************
uint8_t check_game_over()
{
	int count = 0;
	int i;
    if(player->health == 0 || player->health > 100){
			printf("Game lost\n");
			return 1;
	}
	
	for(i=0;i<enermy_size;i++){
		if(enermy[i]->health == 0 || enermy[i]->health > 100)
			count++;
	}
		
	if (count == enermy_size){
		printf("Game Win\n");
		return 2;
	}
	
	return 0;
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
	uint8_t ship_index = get_pos(ship_x_coord,ship_y_coord);
	uint8_t invader_index = get_pos(invader_x_coord,invader_y_coord);
	
    // Check if any margin of the space ship is within the x/y range of the invader.
	//bool left_margin = (int)(ship_x_coord - ship_width / 2) > (int)(invader_x_coord - invader_width / 2)
	//        && (int)(ship_x_coord - ship_width / 2) < (int)(invader_x_coord + invader_width / 2) && (*contact_dir ==PS2_DIR_LEFT);
	//bool right_margin = (int)(ship_x_coord + ship_width / 2) < (int)(invader_x_coord + invader_width / 2)
	//        && (int)(ship_x_coord + ship_width / 2) > (int)(invader_x_coord - invader_width / 2) && (*contact_dir ==PS2_DIR_UP);
	//bool up_margin = (int)(ship_y_coord + ship_height /2) < (int)(invader_y_coord + invader_height/2) 
	//        && (int)(ship_y_coord + ship_height / 2) > (int)(invader_y_coord - invader_height / 2) && (*contact_dir ==PS2_DIR_RIGHT);
	//bool down_margin = (int)(ship_y_coord - ship_height /2) > (int)(invader_y_coord - invader_height/2) 
	//        && (int)(ship_y_coord - ship_height / 2) < (int)(invader_y_coord + invader_height / 2) && (*contact_dir ==PS2_DIR_DOWN);
    switch (*contact_dir)
    {
    case PS2_DIR_LEFT:{
        if (ship_index-1 == invader_index){
            return true;
				}
        break;
			}
    case PS2_DIR_RIGHT:
			if (ship_index+1 == invader_index){
            return true;
				}
        break;
    case PS2_DIR_UP:
			if (ship_index-12 == invader_index){
            return true;
				}
        break;
    case PS2_DIR_DOWN:
			if (ship_index+12 == invader_index){
            return true;
				}
        break;
    default:
        return false;
    }
		
		return false;
}

/*
** Check if the bullet has hit an object or a wall
*/
bool check_shot_on_target(volatile bullet * i){
	uint16_t x_temp = i->x, y_temp = i->y;
	int index;
	
	if(!(i->valid))
		return false;
	
	// Check if hit wall
	switch(i->dir)
	{
		case PS2_DIR_UP:
			y_temp -= 20;
			break;
		case PS2_DIR_DOWN:
			y_temp += 20;
			break;
		case PS2_DIR_LEFT:
			x_temp -= 20;
			break;
		case PS2_DIR_RIGHT:
			x_temp += 20;
			break;
		default:
			//printf("Error! Bullet direction not defined!\n");
			break;
	}
	
	for(index = 0; index < enermy_size; index++){
		if(check_bump(&(i->dir),i->x,i->y,shell_objHeightPixels, shell_objWidthPixels,
			enermy[index]->x,enermy[index]->y,enermy[index]->height, enermy[index]->width))
		{
			
			if (enermy[index]->health > 0 && enermy[index] -> health < 100)
				enermy[index]->health -= 20;
			else 
				enermy[index]->health = 0;
			
			printf("enermy %d health",enermy[index]->health);
			printf("hit at enermy %d pos: (%d,%d)\n",index, i->x, i->y);
			return true;
		}
	}
	
	if(check_bump(&(i->dir),i->x,i->y,shell_objHeightPixels, shell_objWidthPixels,
			player->x,player->y,player->height, player->width))
	{
		
		if (player->health >0)
			player->health -= 5;
		
		printf("hit at player pos: (%d,%d)\n", i->x, i->y);			
		return true;
	}
	
	if(!check_moveable(i->dir, i->x, i->y, 20, 20))
	{
		//printf("Bullet hit the wall.");
		printf("hit at wall pos: (%d,%d)\n", i->x, i->y);
		return true;
	}
	
	return false;
}

void fire(uint16_t x, uint16_t y, PS2_DIR_t dir){
	
	int i;
	
	switch(dir)
	{
		case PS2_DIR_UP:
			y -= 20;
			break;
		case PS2_DIR_DOWN:
			y += 20;
			break;
		case PS2_DIR_LEFT:
			x -= 20;
			break;
		case PS2_DIR_RIGHT:
			x += 20;
			break;
		default:
			printf("Error: shell direction not detected!\n Failed to fire!");
			return;
			break;
	}
	
	printf("fired x:%d, y:%d\n", x,y);
	
	for (i = 0; i<shell_size; i++){
		if(!(shells[i]->valid)){
			shells[i]->valid = true;
			shells[i]->x = x;
			shells[i]->y = y;
			shells[i]->dir = dir;
			break;
		}
		else
		{
			printf("Shell Slot: %d Already in USE\n", i);
		}
	}
}

void initialize_obj(){
	int index;
	player = malloc(sizeof(tanks));
	set_pos(1,&(player->x),&(player->y));
	player->dir = PS2_DIR_CENTER;
	player->image = (uint8_t*)easytank_downBitmaps;
	player->height = easytank_downHeightPixels;
	player->width = easytank_downWidthPixels;
	player->health = 100;
	enermy = malloc(sizeof(tanks*)*enermy_size);
	
	for (index = 0; index < enermy_size; index++){
		enermy[index] = malloc(sizeof(tanks));
		set_pos(179-2*index, &(enermy[index]->x), &(enermy[index]->y));
		enermy[index]->dir = PS2_DIR_CENTER;
		enermy[index]->image = (uint8_t*)easytank_downBitmaps;
		enermy[index]->height = easytank_downHeightPixels;
		enermy[index]->width = easytank_downWidthPixels;
		enermy[index]->health = 100;
	}
	shells = malloc(sizeof(bullet*)*shell_size);
	for (index=0; index<shell_size; index++){
		shells[index] = malloc(sizeof(bullet));
		shells[index]->valid = false;
	}
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
	initialize_obj();
	
	printf("Drawing map...\n");

	lcd_clear_screen(LCD_COLOR_BLACK);
	drawMap(getMap());
	
	IN_PROGRESS = true;
	
	while(true)
	{	
	//				put_string("player statistics\n\r");
	//				sprintf(data,"%d\n\r",player->x);
	//				put_string(data);

		for (index = 0; index < enermy_size; index++){
			if(ALERT_SPACE_SHIP[index])
			{
				ALERT_SPACE_SHIP[index] = false;
				if (enermy[index]->health > 0 && enermy[index]->health < 101){
				lcd_draw_image(
					enermy[index]->x,       // X Center Point
					enermy[index]->width,   // Image Horizontal Width
					enermy[index]->y,       // Y Center Point
					enermy[index]->height,  // Image Vertical Height
					enermy[index]->image,   // Image
					LCD_COLOR_BLUE,         // Foreground Color
					LCD_COLOR_BLACK         // Background Color
				);
				}
				// Update player's HP display
				drawHP(player->health);
			}
		}

		if(ALERT_INVADER)
		{
			ALERT_INVADER = false;
			if (player->health > 0){
				lcd_draw_image(
					player->x,          // X Center Point
					player->width,      // Image Horizontal Width
					player->y,          // Y Center Point
					player->height,     // Image Vertical Height
					player->image,      // Image
					LCD_COLOR_RED,      // Foreground Color
					LCD_COLOR_BLACK     // Background Color
				);
			}

		}   
		
		if(GAME_OVER | CONTINUE | RESTART)
		{
			IN_PROGRESS = false;
			break;
		}	
		
	}
	
}
