#include <xc.h>
#include "time.h"
#include "buzzer-music.h"

void interrupt low_priority lowIsr()
{
    buzzerIsr();
}

void main()
{
    timeInit();

    // Enable interrupts and interrupt priorities.
    IPEN = 1;
    GIEL = 1;
    GIEH = 1;

    uint16_t lastPlayTime = 0;

    while (1)
    {
        timeService();
        buzzerMusicService();

        // Play a song periodically.
        if ((uint16_t)(timeMs - lastPlayTime) > 2000 && !buzzerMusicIsPlaying())
        {
            lastPlayTime = timeMs;
            buzzerMusicPlay("!L16 cdegreg4");
        }
    }
}
