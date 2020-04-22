#include "samd10c14a.h"
// #include "LibrePTC.h"

/*

GPIO Mapping:

| GPIO_N | Port | MCU |
|        |      | pin |
|--------+------+-----+
| GPIO_1 | PA08 |  2  |
| GPIO_2 | PA09 |  3  |
| GPIO_3 | PA14 |  4  |
| GPIO_4 | PA15 |  5  |
| GPIO_5 | PA04 | 14  |
| GPIO_6 | PA02 | 13  |
| GPIO_7 | PA25 | 10  |
| GPIO_8 | PA24 | 09  |

*/

#define LED ((unsigned int) 5)
#define AUDIO ((unsigned int) 4) // GPIO_5 (pin 14)

int counter = 0;

/*
 * When the SysTick timer hits zero, Toggle the LED.
 */
void SysTick_Handler(void) {
    if (counter == 50000) {
        REG_PORT_OUTTGL0 |= 1<<LED;
        counter = 0;
    }
    REG_PORT_OUTTGL0 |= 1<<AUDIO;
    counter++;
}

void initPort(void) {
    REG_PORT_DIR0 |= 1<<AUDIO;      // configure GPIO_5 as output
    REG_PORT_OUTCLR0 = 1<<AUDIO;    // Initially set pin to zero
}

void main(void) {
    REG_PORT_DIR0 |= (1<<LED);  // Set to output
    initPort();
    SysTick_Config(1000);     // Initialize the SysTick registers
    // ptcConfigureClock();

    // Don't need to do anything, the interrupt will handle it
    while (1) { }
}
