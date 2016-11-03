// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// See apa102c.h for more information about this file.

#include <xc.h>
#include "system.h"
#include "apa102c.h"
#include "apa102c_config.h"

#if _XTAL_FREQ != 48000000
#error This code assumes that the PIC is running at 48 MHz.
#endif

void apa102c_write(rgb_color * colors, uint16_t count, uint8_t brightness)
{
    apa102c_start_frame();
    for (uint16_t i = 0; i < count; i++)
    {
        apa102c_send_color(colors[i].red, colors[i].green, colors[i].blue, brightness);
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
        APA102C_CLOCK_LAT |= (1 << APA102C_DATA_BIT);           \
        APA102C_CLOCK_LAT &= ~(1 << APA102C_DATA_BIT); }

static void apa102c_transfer(uint8_t b)
{
    SET_DATA(b >> 7 & 1); PULSE_CLOCK();
    SET_DATA(b >> 6 & 1); PULSE_CLOCK();
    SET_DATA(b >> 5 & 1); PULSE_CLOCK();
    SET_DATA(b >> 4 & 1); PULSE_CLOCK();
    SET_DATA(b >> 3 & 1); PULSE_CLOCK();
    SET_DATA(b >> 2 & 1); PULSE_CLOCK();
    SET_DATA(b >> 1 & 1); PULSE_CLOCK();
    SET_DATA(b >> 0 & 1); PULSE_CLOCK();
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
    for (uint16_t i = 0; i < (count + 14)/16; i++)
    {
        apa102c_transfer(0);
    }

    /* We call init() here to make sure we leave the data line driving low
     * even if count is 0. */
    apa102c_init();
}

void apa102c_send_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness)
{
    apa102c_transfer(0b11100000 | brightness);
    apa102c_transfer(blue);
    apa102c_transfer(green);
    apa102c_transfer(red);
}
