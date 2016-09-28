// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This header file defines the interface for ws2812b.c, a libary that
// allows you to control WS2812B and SK6812 LED strips from a PIC18 running
// at 48 MHz.
//
// To use this library, you must provide a file named ws2812b_config.h
// that defines what PIC pin to use for the LED strip.

#ifndef _WS2812B_H
#define _WS2812B_H

#include <stdint.h>

// This struct represents the color of a single LED.
typedef __pack struct rgb_color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} rgb_color;

// Writes an array of colors to the LED strip.  The colors argument should be a
// pointer to an array of colors, and the count argument specifies the size of
// the array.  This function disables interrupts by setting GIE to 0 and then it
// sets GIE to 1 before returning.  Therefore, this function is not meant to be
// called within an ISR, and you should modify the function if you do not want
// it to enable interrupts.
void ws2812b_write(rgb_color * colors, uint16_t count);

#endif