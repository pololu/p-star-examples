// This file defines the interface for time.c, which provides some simple
// timing functions for the PIC18F25K50 using Timer0.

#include <stdint.h>

// You should call this function before using any other functions from this
// module.
void timeInit(void);

// This function should be called frequently if you are using millis().
// To ensure that millis() does not lose counts, you must call this at least
// every 170 ms.  The value of millis() only changes when this is called.
void timeService(void);

extern uint32_t timeMs;

// Returns a measurement of the time since timeInit was called, in milliseconds.
// This starts at 0 and counts up, resetting to 0 after about 49 days.
#define millis() (timeMs)

// Returns a higher resolution representation of the time since timeInit was called.  This starts at 0
// and counts up, and then resets to 0 after reaching 65535.
uint16_t timeTicks(void);

// The number of ticks (as returned by timeTicks) per millisecond.
#define TICKS_PER_MS 375
