#include <xc.h>
#include "time.h"
#include "buzzer.h"

void interrupt low_priority lowIsr()
{
    buzzerIsr();
}

void main(void)
{
    timeInit();

    // Enable interrupts and interrupt priorities.
    IPEN = 1;
    GIEL = 1;
    GIEH = 1;

    while (1)
    {
        timeService();

        switch (timeMs >> 9 & 3)
        {
        case 0:
            buzzerSetPeriod(6000);  // 1 kHz
            break;

        case 1:
            buzzerSetPeriod(12000); // 500 Hz
            break;

        case 2:
            buzzerSetPeriod(48000); // 125 Hz
            break;

        case 3:
            buzzerStop();
            break;
        }

        // Start the bootloader if the user shorts RB6 to VDD.
        if (PORTBbits.RB6) { asm("goto 4"); }
    }
}
