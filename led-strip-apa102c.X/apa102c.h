// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This header file defines the interface for apa102c.c, a libary that
// allows you to control APA102C LED strips from a PIC18 running
// at 48 MHz.
//
// To use this library, you must provide a file named apa102c_config.h
// that defines what PIC pin to use for the LED strip.

#ifndef _APA102C_H
#define _APA102C_H

#include <stdint.h>

// This struct represents the color of a single LED.
typedef __pack struct rgb_color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} rgb_color;

// Writes an array of colors to the LED strip.  The colors argument should be a
// pointer to an array of colors, and the count argument specifies the size of
// the array.  The brightness argument should be a number between 0 and 31.
void apa102c_write(rgb_color * colors, uint16_t count, uint8_t brightness);

// Initializes the I/O lines and sends a "Start Frame" signal to the LED strip.
//
// This is part of the low-level interface provided by this class, which allows
// you to send LED colors as you are computing them instead of storing them in
// an array.  To use the low-level interface, first call apa102c_start_frame(),
// then call apa102c_send_color() some number of times, then call
// apa102c_end_frame().
void apa102c_start_frame();

// Sends an "End Frame" signal to the LED strip.  This is the last step in
// updating the LED strip if you are using the low-level interface described in
// the apa102c_start_frame() documentation.
//
// After this function returns, the clock and data lines will both be outputs
// that are driving low.  This makes it easier to use one clock pin to control
// multiple LED strips.
void apa102c_end_frame(uint16_t count);

// Sends a single 24-bit color and a 5-bit brightness value.  This is part of
// the low-level interface described in the apa102c_start_frame() documentation.
void apa102c_send_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness);

#endif
