#include "samd10c14a.h"

#define LED ((unsigned int) 5)

/*
 * Initialize the SysTick registers to provide a roughly 1-second interval
 * interrupt.
 */
void initialize_systick_timer(void) {
    SysTick_Config(500000);
}

/*
 * When the SysTick timer hits zero, Toggle the LED.
 */
void SysTick_Handler(void) {
    REG_PORT_OUTTGL0 |= 1<<LED;
}

void main(void) {
    REG_PORT_DIR0 |= (1<<LED);  // Set to output
    initialize_systick_timer(); // Start the SysTick timer/interrupt

    // Don't need to do anything, the interrupt will handle it
    while (1) { }
}
