// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This header file defines the interface for buzzer.c, a library that lets you
// use Timer 3 and the CCP2 module to play simple beeps on pin RC1/CCP2.

#ifndef _BUZZER_H
#define _BUZZER_H

#include <stdint.h>

// You should call this in your low-priority ISR.
void buzzerIsr(void);

// This function disables the buzzer library.  After calling this, you can use
// Timer 3, CCP2, and their interrupts for other purposes.  It is OK to keep
// calling buzzerIsr while the buzzer library is disabled.
void buzzerStop(void);

// Returns true if the buzzer is currently playing a note.
//
// When the note is done or buzzerStop is called, this will become 0.
//
// Note that if you are using the buzzer-music library, you should call
// buzzerMusicIsPlaying() instead of this.
bit buzzerIsPlaying(void);

// Returns true if the buzzer library is enabled and there is a tone queued up to
// be played after the current tone is finished.
bit buzzerNextToneReady(void);

// Tells the buzzer to play a tone/note/beep.
//
// This function initializes the buzzer library if necessary, and interrupts any
// tone that is currently being played on the buzzer.
//
// halfPeriod is one half of the period of the tone, in units of 1/3 us.  The
// period is the reciprocal of the frequency.  A halfPeriod of 0 indicaties that
// the next tone should be silent, and have a full period of 1 ms for the
// purposes of the timeout calculation.  If the halfPeriod is between 1 and 299,
// this function changes it to 300 to ensure that this library's ISRs do not run
// too often).  So the maximum allowed frequency is 5 kHz.
//
// The timeout is how long the tone should be, in units of full periods.
// It can be any number from 0 to 65535.
//
// For example, to play a tone with a frequency of 1 kHz, you would want a
// period of 1 ms and a half period of 500 us.  Therefore you would set the half
// period to 500*12 = 6000.  If you want it to play for 250 ms, tone that the
// period is 1 ms, and set the timeout to (250 ms) / (1 ms) = 250.
//
// To convert from frequency and duration to halfPeriod and timeout, you can use
// these formulae:
//
//   halfPeriod = (1500000) / (frequency in Hz)
//   timeout = (duration in s) * (frequency in Hz)
void buzzerPlayRawTone(uint16_t halfPeriod, uint16_t timeout);

// This is just like buzzerPlayRawTone, but it does not interrupt the tone that
// is currently being played on the buzzer.
void buzzerPlayRawToneNext(uint16_t halfPeriod, uint16_t timeout);

#endif

