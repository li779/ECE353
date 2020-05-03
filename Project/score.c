#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "score.h"

uint16_t EEPROM_SCORE_ADDR = 0x0000;
uint8_t SCORE = 100;
uint8_t LAST_SCORE = 0;
