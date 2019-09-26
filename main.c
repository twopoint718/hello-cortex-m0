#include "samd10c14a.h"

#define LED ((unsigned int) 5)

void delay(unsigned int msec) {
    unsigned int n = 50000;
    while (msec > 0) {
        while (n > 0) {
            n--;
        }
        msec--;
    }
}

void main(void) {
    REG_PORT_DIR0 |= (1<<LED);  // Set to output

    while (1) {
        REG_PORT_OUTTGL0 |= (1<<LED);   // Toggle LED
        delay(1000);
    }
}
