#ifndef __SAMD10C14A__
#define __SAMD10C14A__
#endif

#include <stdint.h>
#include "/Applications/Microchip/xc32/v2.30/pic32c/include_mcc/proc/SAMD10/samd10c14a.h"

#define LED     ((uint32_t)(1<<5))

#define GPIO_1  ((uint32_t)(1<<8))
#define GPIO_2  ((uint32_t)(1<<9))
#define GPIO_3  ((uint32_t)(1<<14))
#define GPIO_4  ((uint32_t)(1<<15))

#define GPIO_5  ((uint32_t)(1<<4))
#define GPIO_6  ((uint32_t)(1<<2))
#define GPIO_7  ((uint32_t)(1<<25))
#define GPIO_8  ((uint32_t)(1<<24))

void port_init(void) {
    PORT_REGS->GROUP[0].PORT_DIRSET = LED;   // Set GPIO_1 to output
    PORT_REGS->GROUP[0].PORT_OUTSET = LED;   // Initially, turn it on
    PORT_REGS->GROUP[0].PORT_PINCFG[5] = 0;     // Disable all configs (see datasheet)
}

void led_toggle(void) {
    PORT_REGS->GROUP[0].PORT_OUTTGL = LED;
}

void delay(uint32_t msec) {
    uint32_t n = 50000;
    while (msec > 0) {
        while (n > 0) {
            n--;
        }
        msec--;
    }
}

void main(void) {
    port_init();

    while (1) {
        led_toggle();
        delay(1000);
    }
}
