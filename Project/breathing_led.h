#ifndef __BREATHING_LED_H__
#define __BREATHING_LED_H__
#endif

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "TM4C123.h"
#include "driver_defines.h"
#include "launchpad_io.h"
#include "gpio_port.h"
#include "main.h"

extern uint16_t R, G, B;
extern uint16_t R_temp, G_temp, B_temp;
extern bool RGB_update, RGB_direction;

void breathing_led_init(void);