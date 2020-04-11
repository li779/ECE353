#include "hw3_interrupts.h"

static volatile uint16_t PS2_X_DATA = 0;
static volatile uint16_t PS2_Y_DATA = 0;
static volatile PS2_DIR_t PS2_DIR = PS2_DIR_CENTER;
static volatile uint16_t MOVE_COUNT = 0;
static volatile PS2_DIR_t SHIP_DIRECTION = PS2_DIR_CENTER;


//*****************************************************************************
// Returns the most current direction that was pressed.
//*****************************************************************************
PS2_DIR_t ps2_get_direction(void)
{
    if (PS2_X_DATA>(2.4/3.3*0xfff))
      return PS2_DIR_LEFT;
    else if (PS2_X_DATA<(0.85/3.3*0xfff))
      return PS2_DIR_RIGHT;
    else if (PS2_Y_DATA>(2.4/3.3*0xfff))
      return PS2_DIR_UP;
    else if (PS2_Y_DATA<(0.85/3.3*0xfff))
      return PS2_DIR_DOWN;
    else 
      return PS2_DIR_CENTER;
}

//*****************************************************************************
// TIMER2 ISR is used to determine when to move the Invader
//*****************************************************************************
void TIMER2A_Handler(void)
{	
    // Check if the edge contact.
    if (!contact_edge(PS2_DIR, INVADER_X_COORD, INVADER_Y_COORD, invaderHeightPixels, invaderWidthPixels))
    {
        move_image(PS2_DIR, &INVADER_X_COORD, &INVADER_Y_COORD, invaderHeightPixels, invaderWidthPixels);
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
    if (MOVE_COUNT == 0)
    {
        MOVE_COUNT = get_new_move_count();
        SHIP_DIRECTION = get_new_direction(SHIP_DIRECTION);
    }
    // Check if edge contact.
    if(!contact_edge(SHIP_DIRECTION, SHIP_X_COORD, SHIP_Y_COORD, space_shipHeightPixels, space_shipWidthPixels))
    {
        move_image(SHIP_DIRECTION, &SHIP_X_COORD, &SHIP_Y_COORD, space_shipHeightPixels, space_shipWidthPixels);
        ALERT_SPACE_SHIP = true;
    }
    // Decrement MOVE_COUNT
    MOVE_COUNT--;
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
    PS2_X_DATA = ADC0->SSFIFO2;
    PS2_Y_DATA = ADC0->SSFIFO2;
    PS2_DIR = ps2_get_direction();
    // Clear the interrupt
    ADC0->ISC |= ADC_ISC_IN2;
    
}
