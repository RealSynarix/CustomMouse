#include "usb_stack.h"

void usb_init() {
    REG32(RCC_BASE + 0x60) |= (1<<0);
    REG32(0x40005C00 + 0x40) = 0x800;
    REG32(0x40005C00 + 0x44) = 0x1;
}

bool usb_is_configured() {
    return (REG32(0x40005C00 + 0x44) & 0x80) != 0;
}

void usb_send_report(HID_MouseReport* r) {
    uint16_t* pma = (uint16_t*)0x40006000;
    pma[0] = r->buttons;
    pma[1] = r->dx;
    pma[2] = r->dy;
    pma[3] = r->wheel;
    REG32(0x40005C00 + 0x04) = 0x30;
}

void run_stage_mode() {
    usb_init();
    while(1) {
    }
}
