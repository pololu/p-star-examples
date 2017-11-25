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

volatile uint16_t buzzerTimeout;

// 0 - the next tone is not ready
// 1 - the next tone is ready, start it when the current tone finishes
// 2 - the next tone is ready, start as soon as possible
volatile uint8_t buzzerNextToneState = 0;

volatile uint16_t buzzerNextHalfPeriod;
volatile uint16_t buzzerNextTimeout;

void buzzerIsrStartNextToneIfNeeded()
{
    if (buzzerTimeout)
    {
        buzzerTimeout--;
    }

    if (buzzerNextToneState == 2)
    {
        buzzerNextToneState = 0;
        buzzerHalfPeriod = buzzerNextHalfPeriod;
        buzzerTimeout = buzzerNextTimeout;
    }
    else if (buzzerTimeout == 0)
    {
        // The current tone has expired.

        if (buzzerNextToneState == 1)
        {
            // The next tone is ready, so start playing it.
            buzzerNextToneState = 0;
            buzzerHalfPeriod = buzzerNextHalfPeriod;
            buzzerTimeout = buzzerNextTimeout;
        }
        else
        {
            // The next tone is not ready, so just stay silent for now.  We'll
            // leave buzzerTimeout set to 0, so we'll reach this code again in 1
            // ms and check for a new tone.
            buzzerHalfPeriod = 0;
        }
    }
    else
    {
        // Keep performing the current tone.
    }
}

void buzzerIsr()
{
    if (buzzerRunning && CCP2IE && CCP2IF)
    {
        // Clear the interrupt flag.
        CCP2IF = 0;

        if (CCP2M0)
        {
            // The match that just happened caused us to clear the output.
            // So we just finished a pulse for a tone, and we should consider
            // starting the next tone.

            buzzerIsrStartNextToneIfNeeded();

            if (buzzerHalfPeriod == 0)
            {
                // This is a silent tone.  Just schedule the next
                // match and interrupt for 1 ms from now.
                CCPR2 = 12000;
            }
            else
            {
                // Schedule the next match and interrupt and make it be a falling
                // edge.
                CCP2M0 = 0;
                CCPR2 += buzzerHalfPeriod;
            }
        }
        else
        {
            // The match that just happened caused the output to get set.
            // Don't change the period and set up the next match to clear the
            // output.
            CCP2M0 = 1;
            CCPR2 += buzzerHalfPeriod;
        }
    }
}

void buzzerStart()
{
    if (buzzerRunning) { return; }

    buzzerRunning = 1;
    buzzerHalfPeriod = 0;
    buzzerTimeout = 0;
    buzzerNextToneState = 0;

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
}

void buzzerStop()
{
    if (!buzzerRunning) { return; }

    CCP2IE = 0;
    TMR3ON = 0;
    CCP2CON = 0;
    buzzerRunning = 0;
}

void buzzerPlayTone(uint16_t halfPeriod, uint16_t timeout)
{
    buzzerStart();

    // Force the half period to be at least 100 us, so the maximum frequency is
    // 5 kHz.  We can't make the half period too small, or else, the interrupts
    // would start being scheduled too quickly and some of them would be missed,
    // resulting in a bad waveform.  It would also be possible for the
    // interrupts to take up all of the CPU time, preventing the P-Star from
    // doing anything in its main loop.
    if (halfPeriod && halfPeriod < 1200)
    {
        halfPeriod = 1200;
    }

    buzzerNextToneState = 0;
    buzzerNextHalfPeriod = halfPeriod;
    buzzerNextTimeout = timeout;
    buzzerNextToneState = 2;
}
