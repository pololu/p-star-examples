#include <xc.h>
#include "time.h"

volatile uint16_t buzzerPeriod;

void interrupt low_priority lowIsr()
{
    if (CCP2IE && CCP2IF)
    {
        // Clear the interrupt flag.
        CCP2IF = 0;

        // Switch from clear-on-match mode to set-on-match mode.
        CCP2M0 ^= 1;

        CCPR2 += buzzerPeriod;
    }
}

void buzzerInit()
{
    // Timer 3: Turn on 16-bit reads/writes.  Leave the timer off for now.
    T3CON = 0b00000010;

    // CCP2: Use Timer 3.
    C2TSEL = 1;

    // CCP2: Clear the output when the compare match happens.
    // (Bit 0 gets toggled later.)
    CCP2CON = 0b00001001;

    // Set the CCP2 interrupt to be low priority.
    CCP2IP = 0;

    LATC1 = 0;
    TRISC1 = 0;
}

void buzzerSetPeriod(uint16_t period)
{
    if (TMR3ON)
    {
        CCP2IE = 0;
        buzzerPeriod = period;
        CCP2IE = 1;
    }
    else
    {
        buzzerPeriod = period;

        // Set up the match to happen soon.
        TMR3H = 0;
        TMR3L = 0;
        CCPR2 = 1;

        // Turn on CCP2 and configure it to clear the output when the compare
        // match happens.  At this point, the CCP2 signal is connected to RC1.
        // If that signal is high from previous operation of the CCP2 module,
        // then RC1 will go high at this point for 2 instruction cycles.
        CCP2CON = 0b00001001;

        TMR3ON = 1;
        CCP2IF = 0;
        CCP2IE = 1;
    }
}

void buzzerStop()
{
    if (TMR3ON)
    {
        CCP2IE = 0;
        TMR3ON = 0;
        CCP2CON = 0;
    }
}


void main(void)
{
    timeInit();
    buzzerInit();

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
            buzzerSetPeriod(6000);
            break;
        case 1:
            buzzerSetPeriod(12000);
            break;

        case 2:
            buzzerSetPeriod(24000);
            break;

        case 3:
            buzzerStop();
            break;
        }

        // Start the bootloader if the user shorts RB6 to VDD.
        if (PORTBbits.RB6) { asm("goto 4"); }
    }
}
