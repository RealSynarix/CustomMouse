#ifndef DRIVERS_H
#define DRIVERS_H

#include "main.h"

void hw_init();
void sensor_init(ConfigSettings* c);
void read_hardware(MouseState* s, ConfigSettings* c);
void set_rgb(uint32_t color);

#endif
