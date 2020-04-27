#include "tanks.h"


volatile tanks* player;
volatile tanks** enermy;
volatile bullet** shells;
volatile const uint8_t shell_size = 10;
volatile const uint8_t enermy_size = 2;

void set_dir(volatile tanks* tank, PS2_DIR_t dir){tank->dir = dir;set_image(tank);}
void set_x(uint16_t x){player->x = x;}
void set_y(uint16_t y){player->y = y;}

void set_image(volatile tanks* tank){
	switch(tank->dir){
		case PS2_DIR_UP: 
		{
			tank->image = tanks_direction[tank->type][0];
			tank->height = easytank_upHeightPixels;
			tank->width = easytank_upWidthPixels;
			break;
		}
		case PS2_DIR_DOWN: 
		{
			tank->image = tanks_direction[tank->type][1];
			tank->height = easytank_downHeightPixels;
			tank->width = easytank_downWidthPixels;
			break;
		}
		case PS2_DIR_LEFT: 
		{
			tank->image = tanks_direction[tank->type][2];
			tank->height = easytank_leftHeightPixels;
			tank->width = easytank_leftWidthPixels;
			break;
		}
		case PS2_DIR_RIGHT: 
		{
			tank->image = tanks_direction[tank->type][3];
			tank->height = easytank_rightHeightPixels;
			tank->width = easytank_rightWidthPixels;
			break;
		}
		default: return; 
	}
	return;
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
			//printf("hit at enermy %d pos: (%d,%d)\n",index, i->x, i->y);
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
		//printf("hit at wall pos: (%d,%d)\n", i->x, i->y);
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
	}
	
	//printf("fired x:%d, y:%d\n", x,y);
	
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
