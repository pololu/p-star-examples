// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This header file defines the interface for buzzer.c, a library that lets you
// use Timer 3 and the CCP2 module to play simple beeps on pin RC1/CCP2.

#ifndef _BUZZER_H
#define _BUZZER_H

#include <stdint.h>

// You should call this in your low-priority ISR.
void buzzerIsr();

// Tells the buzzer to start running and play a note with the specified half
// period in units of 1/12 us.
//
// For example, to get a frequency of 1 kHz, you would want a period of 1 ms
// and a half period of 500 us.  Therefore you would set the half period to
// 500*12 = 6000.
//
// If the half period is 0, this is equivalent to buzzerStop().
// Otherwise, the half period should be between 1200 and 65535.
// Half periods from 1 to 1199 are equivalent to 1200.
void buzzerSetPeriod(uint16_t halfPeriod);

void buzzerStop();

#endif

