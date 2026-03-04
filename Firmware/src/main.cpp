#include "main.h"
#include "drivers.h"
#include "usb_stack.h"

extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss, _estack;

extern "C" void Reset_Handler() {
    volatile uint32_t *src = &_sidata;
    volatile uint32_t *dst = &_sdata;
    while(dst < &_edata) {
        *dst = *src;
        dst++;
        src++;
    }

    dst = &_sbss;
    while(dst < &_ebss) {
        *dst = 0;
        dst++;
    }

    REG32(0x40022000) = 0x04;
    REG32(RCC_BASE + 0x0C) = (1<<24) | (84<<8) | (2<<4) | 2;
    REG32(RCC_BASE) |= (1<<24);
    while(!(REG32(RCC_BASE) & (1<<25)));
    REG32(RCC_BASE + 0x08) |= 0x03;

    extern int main();
    main();
    while(1);
}

__attribute__((section(".isr_vector"))) uint32_t* isr[] = {
    &_estack,
    (uint32_t*)Reset_Handler
};

int main() {
    hw_init();

    ConfigSettings cfg = {1000, 1500, 32000, 0.0f, "Cobalt-X Zero", false, 1};

    if(!(REG32(GPIOB_BASE + 0x10) & (1<<6))) {
        run_stage_mode();
    }

    sensor_init(&cfg);
    usb_init();

    MouseState s = {0, 0, 0, 0, false};
    HID_MouseReport r = {0, 0, 0, 0};

    while(1) {
        read_hardware(&s, &cfg);
        set_rgb(s.macro ? COLOR_ROSE : COLOR_COBALT);

        r.buttons = s.buttons;
        r.dx = s.dx;
        r.dy = s.dy;
        r.wheel = s.wheel;

        if(usb_is_configured()) {
            usb_send_report(&r);
        }
    }
    return 0;
}
