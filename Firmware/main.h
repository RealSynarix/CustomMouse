#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

#define REG32(addr) (*(volatile uint32_t *)(addr))
#define GPIOA_BASE 0x48000000
#define GPIOB_BASE 0x48000400
#define RCC_BASE   0x40021000
#define SYS_CLOCK_HZ 170000000

#define COLOR_COBALT 0x0032FF
#define COLOR_ROSE 0xFF007F

struct MouseState {
    int16_t dx;
    int16_t dy;
    uint8_t buttons;
    int8_t wheel;
    bool macro;
};

struct ConfigSettings {
    uint32_t polling_rate;
    uint32_t dpi;
    uint32_t internal_sampling;
    float click_delay;
    char device_name[32];
    bool surface_smoothing;
    uint32_t lift_off_dist;
};

#endif
