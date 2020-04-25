#define __MAP_H__

#include <stdint.h>

extern const uint8_t Sevastopol[];
extern const uint8_t map_width;
extern const uint8_t map_height;

void drawMap(const uint8_t map[]);
uint8_t get_pos(uint16_t x, uint16_t y);