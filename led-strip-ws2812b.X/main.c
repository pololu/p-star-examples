// WS2812B/SK6812 LED Strip Example for the P-Star 25K50
//
// For more information, see:
//
//   https://github.com/pololu/p-star-examples/led-strip-ws2812b.X/

#include <xc.h>
#include "time.h"
#include "ws2812b.h"

// Create a buffer for holding the colors (3 bytes per color).
#define LED_COUNT 60
rgb_color colors[LED_COUNT];

// Converts a color from HSV to RGB.
// h is hue, as a number between 0 and 360.
// s is the saturation, as a number between 0 and 255.
// v is the value, as a number between 0 and 255.
rgb_color hsvToRgb(uint16_t h, uint8_t s, uint8_t v)
{
    uint8_t f = (h % 60) * 255 / 60;
    uint8_t p = (255 - s) * (uint16_t)v / 255;
    uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t r = 0, g = 0, b = 0;
    switch((h / 60) % 6){
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        case 5: r = v; g = p; b = q; break;
    }

    rgb_color ret;
    ret.red = r;
    ret.green = g;
    ret.blue = b;
    return ret;
}

void updateLeds()
{
    // Update the colors.
    uint16_t time = millis() >> 2;
    for(uint16_t i = 0; i < LED_COUNT; i++)
    {
      uint8_t x = (time >> 2) - (i << 3);
      colors[i] = hsvToRgb((uint32_t)x * 359 / 256, 255, 255);
    }

    // Write the colors to the LED strip.
    ws2812b_write(colors, LED_COUNT);
}

void main(void)
{
    timeInit();

    while (1)
    {
        timeService();
        updateLeds();
    }
}
