#define __MAP_H__

#include <stdint.h>
#include "lcd.h"

extern const uint8_t Sevastopol[];
extern const uint8_t map_width;
extern const uint8_t map_height;

void drawMap(const uint8_t map[]);
uint8_t get_pos(uint16_t x, uint16_t y);
void set_pos(uint8_t index, volatile uint16_t* x, volatile uint16_t* y);
uint16_t get_x(uint8_t index);
uint16_t get_y(uint8_t index);
