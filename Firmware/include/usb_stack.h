#ifndef USB_STACK_H
#define USB_STACK_H

#include "main.h"

struct HID_MouseReport {
    uint8_t buttons;
    int16_t dx;
    int16_t dy;
    int8_t wheel;
};

void usb_init();
void run_stage_mode();
void usb_send_report(HID_MouseReport* r);
bool usb_is_configured();

#endif
