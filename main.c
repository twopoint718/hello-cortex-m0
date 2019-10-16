#include "samd10c14a.h"

#define LED ((unsigned int) 5)

/*
 * When the SysTick timer hits zero, Toggle the LED.
 */
void SysTick_Handler(void) {
    REG_PORT_OUTTGL0 |= 1<<LED;
}

void main(void) {
    REG_PORT_DIR0 |= (1<<LED);  // Set to output
    SysTick_Config(1000000);     // Initialize the SysTick registers

    // Don't need to do anything, the interrupt will handle it
    while (1) { }
}
