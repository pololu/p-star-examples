// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This header file defines the interface for ws2812b.c, a libary that
// allows you to control WS2812B and SK6812 LED strips from a PIC18 running
// at 48 MHz.

#ifndef _WS2812B_H
#define _WS2812B_H

#include <stdint.h>

typedef __pack struct rgb_color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} rgb_color;

void ws2812b_write(rgb_color *, uint16_t count);

#endif