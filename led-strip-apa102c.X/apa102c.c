// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// See apa102c.h for more information about this file.

#include <xc.h>
#include "system.h"
#include "apa102c.h"
#include "apa102c_config.h"

void apa102c_write(rgb_color * colors, uint16_t count, uint8_t brightness)
{
    apa102c_start_frame();
    for (uint16_t i = 0; i < count; i++)
    {
        apa102c_send_color(colors->red, colors->green, colors->blue, brightness);
        colors++;
    }
    apa102c_end_frame(count);
}

static void apa102c_init()
{
    // Drive both outputs low.
    APA102C_CLOCK_LAT &= ~(1 << APA102C_CLOCK_BIT);
    APA102C_CLOCK_TRIS &= ~(1 << APA102C_CLOCK_BIT);
    APA102C_DATA_LAT &= ~(1 << APA102C_DATA_BIT);
    APA102C_DATA_TRIS &= ~(1 << APA102C_DATA_BIT);
}

#define SET_DATA(b) (b) ? (APA102C_DATA_LAT |= (1 << APA102C_DATA_BIT)) \
                        : (APA102C_DATA_LAT &= ~(1 << APA102C_DATA_BIT));
#define PULSE_CLOCK() { \
        APA102C_CLOCK_LAT |= (1 << APA102C_CLOCK_BIT); \
        APA102C_CLOCK_LAT &= ~(1 << APA102C_CLOCK_BIT); }

static void apa102c_transfer(uint8_t b)
{
    SET_DATA(b & (1 << 7)); PULSE_CLOCK();
    SET_DATA(b & (1 << 6)); PULSE_CLOCK();
    SET_DATA(b & (1 << 5)); PULSE_CLOCK();
    SET_DATA(b & (1 << 4)); PULSE_CLOCK();
    SET_DATA(b & (1 << 3)); PULSE_CLOCK();
    SET_DATA(b & (1 << 2)); PULSE_CLOCK();
    SET_DATA(b & (1 << 1)); PULSE_CLOCK();
    SET_DATA(b & (1 << 0)); PULSE_CLOCK();
}

void apa102c_start_frame()
{
    apa102c_init();
    apa102c_transfer(0);
    apa102c_transfer(0);
    apa102c_transfer(0);
    apa102c_transfer(0);
}

void apa102c_end_frame(uint16_t count)
{
    apa102c_transfer(0xFF);
    for (uint16_t i = 0; i < 5 + count / 16; i++)
    {
        apa102c_transfer(0);
    }
}

void apa102c_send_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness)
{
    apa102c_transfer(0b11100000 | brightness);
    apa102c_transfer(blue);
    apa102c_transfer(green);
    apa102c_transfer(red);
}
