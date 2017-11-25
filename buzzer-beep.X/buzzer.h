// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This header file defines the interface for buzzer.c, a library that lets you
// use Timer 3 and the CCP2 module to play simple beeps on pin RC1/CCP2.
//
// While the buzzer is not playing, you can use Timer 3 and CCP2 for other
// things.

#ifndef _BUZZER_H
#define _BUZZER_H

#include <stdint.h>

// You should call this in your low-priority ISR.
void buzzerIsr();

// Tells the buzzer to play a tone/note/beep.
//
// This function initializes the buzzer library if necessary, and interrupts any
// tone that is currently being played on the buzzer.
//
// halfPeriod is one half of the period of the tone, in units of 1/12 us.  The
// period is the reciprocal of the frequency.  A halfPeriod is 0 is a special
// value indicating that the next tone should be silent, and have a full period
// of 1 ms for the purposes of the timeout calculation.  If the halfPeriod is
// between 1 and 1199, this function changes it to 1200 to ensure that this
// library's ISRs do not run too often).
//
// The timeout is how long the tone should be, in units of full periods.
//
// For example, to play a tone with a frequency of 1 kHz, you would want a
// period of 1 ms and a half period of 500 us.  Therefore you would set the half
// period to 500*12 = 6000.  If you want it to play for 250 ms, tone that the
// period is 1 ms, and set the timeout to (250 ms) / (1 ms) = 250.
void buzzerPlayRawTone(uint16_t halfPeriod, uint16_t timeout);

void buzzerStop();

#endif

