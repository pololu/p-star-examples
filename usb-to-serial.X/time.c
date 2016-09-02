// This file provides some simple timing functions for the PIC18F25K50
// using Timer0.  See time.h for more information.

#include "time.h"
#include <xc.h>

uint32_t timeMs;

// The Timer 0 value that corresponds to the current value of timeMs.
static uint16_t timer0Base;

void timeInit()
{
    // Turn off Timer 0 and reset the count to 0.
    T0CON = 0;
    TMR0H = 0;
    TMR0L = 0;

    timeMs = 0;
    timer0Base = 0;

    // 12 MHZ / 32 prescaler = 375 ticks per ms, overflow at ~174.76 ms.
    T0CON = 0b10000100;
}

uint16_t timeTicks()
{
    // TMR0L must be read before TMR0H.
    uint8_t t = TMR0L;
    return ((uint16_t)TMR0H << 8) | t;
}

void timeService()
{
    uint16_t timer0Now = timeTicks();
    while ((uint16_t)(timer0Now - timer0Base) >= TICKS_PER_MS)
    {
        timeMs++;
        timer0Base += TICKS_PER_MS;
    }
}
