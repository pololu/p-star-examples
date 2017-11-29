#include <xc.h>
#include "time.h"
#include "leds.h"

void main()
{
    timeInit();
    LEDS_INIT();

    while (1)
    {
        timeService();

        // Blink the green LED with a period of 1 s.
        LED_GREEN(timeMs >> 9 & 1);

        // Blink the yellow LED with a period of 0.5 s.
        LED_YELLOW(timeMs >> 8 & 1);

        // Blink the red LED with a period of 0.25 s.
        LED_RED(timeMs >> 7 & 1);
    }
}
