#include "hw3_interrupts.h"

static volatile uint16_t PS2_X_DATA = 0;
static volatile uint16_t PS2_Y_DATA = 0;
static volatile uint16_t MOVE_COUNT [10];
static volatile PS2_DIR_t SHIP_DIRECTION = PS2_DIR_CENTER;
static bool bump [10];


//*****************************************************************************
// Returns the most current direction that was pressed.
//*****************************************************************************
void ps2_get_direction(void)
{
    // convert adc data to its direction
    if (PS2_X_DATA>(2.4/3.3*0xfff)){
			set_dir(player,PS2_DIR_LEFT);
      return;
    }else if (PS2_X_DATA<(0.85/3.3*0xfff)){
			set_dir(player,PS2_DIR_RIGHT);
      return;
    }else if (PS2_Y_DATA>(2.4/3.3*0xfff)){
			set_dir(player,PS2_DIR_UP);
      return;
		}else if (PS2_Y_DATA<(0.85/3.3*0xfff)){
			set_dir(player,PS2_DIR_DOWN);
      return;
		}else {
			set_dir(player,PS2_DIR_CENTER);
      return;
		}
}

//*****************************************************************************
// TIMER2 ISR is used to determine when to move the Invader
//*****************************************************************************
void TIMER2A_Handler(void)
{	
    // Check if the edge contact, if not then move the image
    if (!contact_edge(player->dir, player->x, player->y, player->height, player->width))
    {
        move_image(player->dir, &player->x, &player->y, player->height, player->width);
        ALERT_INVADER = true;
    }
    // Clear the interrupt
	TIMER2->ICR |= TIMER_ICR_TATOCINT;
}

//*****************************************************************************
// TIMER3 ISR is used to determine when to move the spaceship
//*****************************************************************************
void TIMER3A_Handler(void)
{	
	int index;
	int i;
	char data[80];
	for(i = 0; i < 10; i++){ bump[i] = false;}
	for (index = 0; index < enermy_size; index++){
    if (MOVE_COUNT[index] == 0)   // if moved, then look for new values
    {
        MOVE_COUNT[index] = get_new_move_count();
//        SHIP_DIRECTION = get_new_direction(SHIP_DIRECTION);
			
    }
		set_dir(enermy[index],get_new_direction(&bump[index],index,enermy[index]->dir));
    // Check if edge contact, if not then move the image
		
		for(i = 0; i < enermy_size; i++){
			if(i != index){
			bump[index] |= check_bump(&(enermy[index]->dir),enermy[index]->x,enermy[index]->y,enermy[index]->height, enermy[index]->width,
													enermy[i]->x,enermy[i]->y,enermy[i]->height, enermy[i]->width);
			}
		}
		bump[index] |= check_bump(&(enermy[index]->dir),enermy[index]->x,enermy[index]->y,enermy[index]->height, enermy[index]->width,
													player->x,player->y,player->height, player->width);
		bump[index] |= contact_edge(enermy[index]->dir, enermy[index]->x, enermy[index]->y, enermy[index]->height, enermy[index]->width);
		if (bump[index]){
			sprintf(data,"tank: %d is bumping at dir: %d\r", index,enermy[index]->dir);
			put_string(data);
			
		}
    if(!bump[index])
    {
        move_image(enermy[index]->dir, &(enermy[index]->x), &(enermy[index]->y), enermy[index]->height, enermy[index]->width);
        ALERT_SPACE_SHIP[index] = true;
    }
    // Decrement MOVE_COUNT
    MOVE_COUNT[index]--;
	}
	// Clear the interrupt
	TIMER3->ICR |= TIMER_ICR_TATOCINT;  
}

//*****************************************************************************
// TIMER4 ISR is used to trigger the ADC
//*****************************************************************************
void TIMER4A_Handler(void)
{	
    ADC0->PSSI |= ADC_PSSI_SS2;
	// Clear the interrupt
    TIMER4->ICR |= TIMER_ICR_TATOCINT;
}

//*****************************************************************************
// ADC0 SS2 ISR
//*****************************************************************************
void ADC0SS2_Handler(void)
{
    // Read data from FIFO
    PS2_X_DATA = ADC0->SSFIFO2;
    PS2_Y_DATA = ADC0->SSFIFO2;
    // Check the direction based on PS data
    ps2_get_direction();
    // Clear the interrupt
    ADC0->ISC |= ADC_ISC_IN2;
    
}
