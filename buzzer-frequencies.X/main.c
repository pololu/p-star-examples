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

    uint16_t lastBeepTime = 0;

    while (1)
    {
        timeService();

        // Beep once per second.
        if ((uint16_t)(timeMs - lastBeepTime) > 1000)
        {
            lastBeepTime = timeMs;
            buzzerSetNote(12000, 25);  // 500 Hz, 50 ms
        }

        // Start the bootloader if the user shorts RB6 to VDD.
        if (PORTBbits.RB6) { asm("goto 4"); }
    }
}
