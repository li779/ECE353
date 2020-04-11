#include "hw3.h"

volatile uint16_t SHIP_X_COORD = 190;
volatile uint16_t SHIP_Y_COORD = 270;
volatile uint16_t INVADER_X_COORD = 50;
volatile uint16_t INVADER_Y_COORD = 40;
volatile bool ALERT_SPACE_SHIP = true;
volatile bool ALERT_INVADER = true;
char STUDENT_NAME[] = "Yichen Li and Marvin Zhang";

typedef struct
{
    int top;
    int bottom;
    int left;
    int right;
} Rectangle;

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
    switch (direction)   // move images according to direction
    {
        case PS2_DIR_LEFT:
            (*x_coord)--;
            break;
        case PS2_DIR_RIGHT:
            (*x_coord)++;
            break;
        case PS2_DIR_UP:
            (*y_coord)--;
            break;
        case PS2_DIR_DOWN:
            (*y_coord)++;
            break;
        default:
            break;
    }

    return;
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

//*****************************************************************************
// Initializes all of the peripherls used in HW3
//*****************************************************************************
void init_hardware(void)
{
  lcd_config_gpio();
  lcd_config_screen();
  lcd_clear_screen(LCD_COLOR_BLACK);
  ps2_initialize();
  
  // Update the Space Shipt 60 times per second.
  gp_timer_config_32(TIMER2_BASE,TIMER_TAMR_TAMR_PERIOD, 1000000, false, true);
  gp_timer_config_32(TIMER3_BASE,TIMER_TAMR_TAMR_PERIOD, 500000, false, true);
  gp_timer_config_32(TIMER4_BASE,TIMER_TAMR_TAMR_PERIOD, 50000, false, true);
}

//*****************************************************************************
// Main application for HW3
//*****************************************************************************
void hw3_main(void)
{
    bool game_over = false;
    init_hardware();
   

      while(!game_over)
      {
          if(ALERT_SPACE_SHIP)
          {
            ALERT_SPACE_SHIP = false;
            
            lcd_draw_image(
                          SHIP_X_COORD,                       // X Center Point
                          space_shipWidthPixels,   // Image Horizontal Width
                          SHIP_Y_COORD,                       // Y Center Point
                          space_shipHeightPixels,  // Image Vertical Height
                          space_shipBitmaps,       // Image
                          LCD_COLOR_BLUE,           // Foreground Color
                          LCD_COLOR_BLACK          // Background Color
                        );
              
            game_over = check_game_over(
                                        SHIP_X_COORD,
                                        SHIP_Y_COORD,
                                        space_shipHeightPixels,
                                        space_shipWidthPixels,
                                        INVADER_X_COORD,
                                        INVADER_Y_COORD,
                                        invaderHeightPixels,
                                        invaderWidthPixels
                                    );
          }
          
          if(ALERT_INVADER)
          {
            ALERT_INVADER = false;
            
            lcd_draw_image(
                          INVADER_X_COORD,          // X Center Point
                          invaderWidthPixels,       // Image Horizontal Width
                          INVADER_Y_COORD,          // Y Center Point
                          invaderHeightPixels,      // Image Vertical Height
                          invaderBitmaps,           // Image
                          LCD_COLOR_RED,            // Foreground Color
                          LCD_COLOR_BLACK           // Background Color
                        );
              
             game_over = check_game_over(
                                            SHIP_X_COORD,
                                            SHIP_Y_COORD,
                                            space_shipHeightPixels,
                                            space_shipWidthPixels,
                                            INVADER_X_COORD,
                                            INVADER_Y_COORD,
                                            invaderHeightPixels,
                                            invaderWidthPixels
                                        );
          }
          
      }   
}
