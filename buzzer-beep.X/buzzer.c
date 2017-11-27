// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

#include "buzzer.h"
#include <xc.h>

volatile uint8_t buzzerRunning = 0;

// If the buzzer is running, this is the current half period of the frequency we
// are playing on the buzzer.
volatile uint16_t buzzerHalfPeriod;

volatile uint16_t buzzerTimeout;

#define BUZZER_NEXT_TONE_NOT_READY 0
#define BUZZER_NEXT_TONE_READY 1
#define BUZZER_NEXT_TONE_ASAP 2
volatile uint8_t buzzerNextToneState = BUZZER_NEXT_TONE_NOT_READY;

volatile uint16_t buzzerNextHalfPeriod;
volatile uint16_t buzzerNextTimeout;

// This function is called frequently by the ISR to decide whether to keep
// playing the current tone, play the next tone, or stop.  It sets
// buzzerHalfPeriod and buzzerTimeout to indicate its decision.  If
// buzzerTimeout is 0, it means that the decision is to stop playing.
void buzzerIsrDecideNextTone()
{
    if (buzzerTimeout)
    {
        buzzerTimeout--;
    }

    if (buzzerNextToneState == BUZZER_NEXT_TONE_ASAP ||
        (buzzerTimeout == 0 && buzzerNextToneState))
    {
        buzzerNextToneState = 0;
        buzzerHalfPeriod = buzzerNextHalfPeriod;
        buzzerTimeout = buzzerNextTimeout;
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
            // The match that just happened caused us to clear the output.  So
            // we just finished a pulse for a tone (or we just started running),
            // and we should consider starting the next tone.

            buzzerIsrDecideNextTone();

            if (buzzerTimeout == 0)
            {
                // Stop the buzzer.
                CCP2IE = 0;
                TMR3ON = 0;
                CCP2CON = 0;
                buzzerRunning = 0;
            }
            else if (buzzerHalfPeriod == 0)
            {
                // This is a silent tone.  Just schedule the next
                // match and interrupt for 1 ms from now.
                CCPR2 += 12000;
            }
            else
            {
                // Schedule the next match and make it set the CCP2 output.
                CCP2M0 = 0;
                CCPR2 += buzzerHalfPeriod;
            }
        }
        else
        {
            // The match that just happened caused the output to get set.  Don't
            // change the period and set up the next match and make it clear the
            // CCP2 output.
            CCP2M0 = 1;
            CCPR2 += buzzerHalfPeriod;
        }
    }
}

// Make sure to set buzzerNextToneState properly before calling this.
static void buzzerStartRunning()
{
    if (buzzerRunning) { return; }

    buzzerRunning = 1;

    // Make RC1 be an output and drive low by default when CCP2 is not
    // connected.
    LATC1 = 0;
    TRISC1 = 0;

    // Timer 3: Turn on 16-bit reads/writes.  Leave the timer off for now.
    T3CON = 0b00000010;

    // CCP2: Use Timer 3.
    C2TSEL = 1;

    // CCP2 interrupt priority: low.
    CCP2IP = 0;

    buzzerHalfPeriod = 0;
    buzzerTimeout = 0;

    // Set up the match to happen soon.
    TMR3H = 0;
    TMR3L = 0;
    CCPR2 = 1;

    // Turn on CCP2 and configure it to clear the output when the compare match
    // happens.  When we set CCP2CON, the CCP2 signal gets connected to RC1.  If
    // that signal is high from previous operation of the CCP2 module, then RC1
    // will go high at this point for 2 instruction cycles.
    CCP2CON = 0b00001001;

    // Turn on the timer.
    TMR3ON = 1;

    CCP2IE = 1;
}

void buzzerStop()
{
    if (!buzzerRunning) { return; }

    CCP2IE = 0;
    TMR3ON = 0;
    CCP2CON = 0;
    buzzerRunning = 0;
    buzzerNextToneState = 0;
}

bit buzzerIsPlaying()
{
    return buzzerRunning;
}

bit buzzerNextToneReady()
{
    return buzzerNextToneState ? 1 : 0;
}

void buzzerPlayRawTone(uint16_t halfPeriod, uint16_t timeout)
{
    // Force the half period to be at least 100 us, so the maximum frequency is
    // 5 kHz.  We can't make the half period too small, or else the interrupts
    // would start being scheduled too quickly and some of them would be missed,
    // resulting in a bad waveform.  It would also be possible for the
    // interrupts to take up all of the CPU time, preventing the P-Star from
    // doing anything in its main loop.
    if (halfPeriod && halfPeriod < 1200)
    {
        halfPeriod = 1200;
    }

    buzzerNextToneState = BUZZER_NEXT_TONE_NOT_READY;
    buzzerNextHalfPeriod = halfPeriod;
    buzzerNextTimeout = timeout;
    buzzerNextToneState = BUZZER_NEXT_TONE_ASAP;

    buzzerStartRunning();
}

void buzzerPlayRawToneNext(uint16_t halfPeriod, uint16_t timeout)
{
    if (halfPeriod && halfPeriod < 1200)
    {
        halfPeriod = 1200;
    }

    buzzerNextToneState = BUZZER_NEXT_TONE_NOT_READY;
    buzzerNextHalfPeriod = halfPeriod;
    buzzerNextTimeout = timeout;
    buzzerNextToneState = BUZZER_NEXT_TONE_READY;

    buzzerStartRunning();
}
