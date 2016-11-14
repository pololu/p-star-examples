// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This file provides macros for using LEDs on the P-Star.

#ifndef _LEDS_H
#define _LEDS_H

// This must be called before you try to use any of the LEDs.
#define LEDS_INIT() { LATB7 = 1; LATB6 = 1; LATC6 = 0; }

// Each of these macros takes an integer argument, turns on the corresponding
// LED if it is non-zero, and turns off the corresponding LED if it is zero.
#define LED_GREEN(v) { TRISB7 = !(v); }
#define LED_YELLOW(v) { TRISB6 = !(v); }
#define LED_RED(v) { TRISC6 = !(v); }

#endif