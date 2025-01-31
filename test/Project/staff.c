#include "game.h"
#include "staff.h"

static const uint16_t START_STATE = 0xACE7u;
static const uint16_t   MOVE_AMOUNT[] = {25, 50, 75, 100, 125, 150, 175, 200};
static const PS2_DIR_t  MOV_DIR[] = {PS2_DIR_UP, PS2_DIR_DOWN, PS2_DIR_LEFT, PS2_DIR_RIGHT};

//*****************************************************************************
// Generates a random number
// https://en.wikipedia.org/wiki/Linear-feedback_shift_register  -- DO NOT MODIFY
//*****************************************************************************
uint16_t generate_random_number(
)
{   
    static uint16_t lfsr = START_STATE;
    uint16_t bit;
    bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    lfsr =  (lfsr >> 1) | (bit << 15);
    return lfsr;
}

//*****************************************************************************
// Generates the the new direction and number of pixels  -- DO NOT MODIFY
//*****************************************************************************
PS2_DIR_t get_new_direction(bool* bump, int tank_index, PS2_DIR_t curr_direction)
{	
		
     PS2_DIR_t new_direction;
		 double horizontal_dist = fabs((double)(enermy[tank_index]->x - player->x));
		 double vertical_dist = fabs((double)(enermy[tank_index]->y - player->y));
			
		if(*bump){
			
		new_direction = (curr_direction+1)%4;
			*bump = false;
		
			return new_direction;
		}
		if(horizontal_dist>vertical_dist){
			if(enermy[tank_index]->x > player->x){
				new_direction = PS2_DIR_LEFT;
			} else{
				new_direction = PS2_DIR_RIGHT;
			}
		} else{
			if(enermy[tank_index]->y > player->y){
				new_direction = PS2_DIR_UP;
			} else{
				new_direction = PS2_DIR_DOWN;
			}
		}
//    
    
    return new_direction;
}

//*****************************************************************************
// Generates the the new direction and number of pixels  -- DO NOT MODIFY
//*****************************************************************************
uint16_t get_new_move_count(void)
{
    return MOVE_AMOUNT[generate_random_number()%8];
}


extern void initialize_serial_debug(void);
extern void put_string(char *data);

//*****************************************************************************
// Validates HW3 
//*****************************************************************************
