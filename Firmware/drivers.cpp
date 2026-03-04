#include "drivers.h"

static uint32_t last_click_time = 0;
static bool macro_toggle = false;
static bool wheel_mode_rmb = false;
static uint8_t last_button_state = 0;

void hw_init() {
    REG32(RCC_BASE + 0x4C) |= 0x03;
    REG32(GPIOA_BASE) = 0xAB950000;
    REG32(GPIOB_BASE + 0x00) &= ~(0x00003F00);
    REG32(GPIOB_BASE + 0x0C) |= 0x00001540;

    REG32(0xE000EDFC) |= 0x01000000;
    REG32(0xE0001000) |= 1;
    REG32(0xE0001004) = 0;
}

void sensor_init(ConfigSettings* cfg) {
    REG32(GPIOA_BASE + 0x18) = (1<<4);
    for(volatile int i=0; i<10000; i++);
    REG32(GPIOA_BASE + 0x28) = (1<<4);
}

void read_hardware(MouseState* s, ConfigSettings* cfg) {
    uint32_t current_ticks = REG32(0xE0001004);
    uint32_t pins = REG32(GPIOB_BASE + 0x10);

    bool macro_pressed = !(pins & (1<<6));
    if (macro_pressed && (current_ticks - last_click_time > (SYS_CLOCK_HZ / 5))) {
        macro_toggle = !macro_toggle;
        last_click_time = current_ticks;
    }

    s->macro = macro_toggle;
    uint8_t current_state = 0;

    if(!(pins & (1<<3))) current_state |= 0x01;
    if(!(pins & (1<<4))) current_state |= 0x02;

    if (macro_toggle) {
        if(!(pins & (1<<5))) {
            if (current_ticks - last_click_time > (SYS_CLOCK_HZ / 2000)) {
                wheel_mode_rmb = !wheel_mode_rmb;
                last_click_time = current_ticks;
            }
        }
        if (s->wheel != 0) {
            current_state |= (wheel_mode_rmb ? 0x02 : 0x01);
            s->wheel = 0;
        }
    } else {
        if(!(pins & (1<<5))) current_state |= 0x04;
    }

    if (current_state != last_button_state) {
        uint32_t delay_cycles = (SYS_CLOCK_HZ / 2000) + (uint32_t)(cfg->click_delay * (SYS_CLOCK_HZ / 1000));
        if ((current_ticks - last_click_time) > delay_cycles) {
            s->buttons = current_state;
            last_button_state = current_state;
            last_click_time = current_ticks;
        }
    } else {
        s->buttons = last_button_state;
    }

    REG32(GPIOA_BASE + 0x28) = (1<<4);
    s->dx = 0;
    s->dy = 0;
    REG32(GPIOA_BASE + 0x18) = (1<<4);
}

void set_rgb(uint32_t color) {
    (void)color;
}
