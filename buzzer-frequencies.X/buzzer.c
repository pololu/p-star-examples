// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

#include "buzzer.h"
#include <xc.h>

// This is non-zero if this buzzer library is active.  When this is zero, the
// buzzer ISR will not do anything, and functions that start playing the buzzer
// will reinitialize all of the needed peripherals.
volatile uint8_t buzzerRunning = 0;

// If the buzzer is running, this is the current half period of the frequency we
// are playing on the buzzer.
volatile uint16_t buzzerHalfPeriod;

void buzzerIsr()
{
    if (buzzerRunning && CCP2IE && CCP2IF)
    {
        // Clear the interrupt flag.
        CCP2IF = 0;

        // Switch from clear-on-match mode to set-on-match mode.
        CCP2M0 ^= 1;

        // Schedule the next compare match for one half period from now.
        CCPR2 += buzzerHalfPeriod;
    }
}

void buzzerStart()
{
    if (buzzerRunning) { return; }

    // Make RC1 be an output and drive low by default when CCP2 is not
    // connected.
    LATC1 = 0;
    TRISC1 = 0;

    // Timer 3: Turn on 16-bit reads/writes.  Leave the timer off for now.
    T3CON = 0b00000010;

    // CCP2: Use Timer 3.
    C2TSEL = 1;

    // Set up the match to happen soon.
    TMR3H = 0;
    TMR3L = 0;
    CCPR2 = 1;

    // Turn on CCP2 and configure it to clear the output when the compare
    // match happens.  When we do this, the CCP2 signal gets connected to RC1.
    // If that signal is high from previous operation of the CCP2 module,
    // then RC1 will go high at this point for 2 instruction cycles.
    CCP2CON = 0b00001001;

    // Turn on the timer.
    TMR3ON = 1;

    CCP2IP = 0;
    CCP2IF = 0;
    CCP2IE = 1;

    buzzerRunning = 0xFF;
}

void buzzerStop()
{
    if (!buzzerRunning) { return; }

    CCP2IE = 0;
    TMR3ON = 0;
    CCP2CON = 0;
    buzzerRunning = 0;
}

void buzzerSetPeriod(uint16_t halfPeriod)
{
    if (halfPeriod == 0)
    {
        buzzerStop();
        return;
    }

    // Force the half period to be at least 100 us, so the maximum frequency is
    // 5 kHz.  We can't make the half period too small, or else, the interrupts
    // would start being scheduled too quickly and some of them would be missed,
    // resulting in a bad waveform.  It would also be possible for the
    // interrupts to take up all of the CPU time, preventing the P-Star from
    // doing anything in its main loop.
    if (halfPeriod < 1200)
    {
        halfPeriod = 1200;
    }

    if (buzzerRunning)
    {
        CCP2IE = 0;
        buzzerHalfPeriod = halfPeriod;
        CCP2IE = 1;
    }
    else
    {
        buzzerHalfPeriod = halfPeriod;
        buzzerStart();
    }
}
