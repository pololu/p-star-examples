#include "buzzer-music.h"

#include <stdint.h>

// The half periods of the notes in octave 0.
const uint16_t buzzerHalfPeriodTableOctave0[12] =
{
    54545,  // 0 = A    Half period of A = 1500000/(440/16)
    51484,  // 1 = A#   Half period of A# is smaller by a factor of 2^(1/12)
    48594,  // 2 = B
    45867,  // 3 = C
    43292,  // 4 = C#
    40862,  // 5 = D
    38569,  // 6 = D#
    36405,  // 7 = E
    34631,  // 8 = F
    32432,  // 9 = F#
    30612,  // 10 = G
    28894,  // 11 = G#
};

// The timeouts of whole notes in octave 6.  A whole note is 2 s, so this is
// really just 2 times the frequency.
const uint16_t buzzerTimeoutTableOctave6[12] =
{
    3520,
    3729,
    3951,
    4186,
    4435,
    4699,
    4978,
    5274,
    5588,
    5920,
    6272,
    6645,
};

uint8_t buzzerMusicRunning = 0;

const char * buzzerMusicPointer;

void buzzerMusicPlay(const char * sequence)
{
    buzzerMusicPointer = sequence;
    buzzerMusicRunning = 1;
}

void buzzerMusicStop()
{
    buzzerMusicRunning = 0;
    buzzerStop();
}

// buzzerMusicRunning will be zero if we have finished queuing up the last notes
// of the song and are just waiting for the low-level buzzer library to finish
// playing them.  buzzerIsPlaying() might be zero if there are more notes to
// play but we got delayed and have not queued up the next note yet.  So we must
// check both conditions.
bit buzzerMusicIsPlaying()
{
    return buzzerMusicRunning || buzzerIsPlaying();
}

void buzzerMusicService()
{
    if (!buzzerMusicRunning || buzzerNextToneReady())
    {
        return;
    }

    uint8_t c;

parse_character:
    c = *buzzerMusicPointer++;

    // Convert to lower case.
    if (c >= 'A' && c <= 'Z')
    {
        c += 'a' - 'A';
    }

    uint8_t note = 0xFF;

    switch (c)
    {
    case 'a':
        note = 0;
        break;
    case 'b':
        note = 2;
        break;
    case 'c':
        note = 3;
        break;
    case 'd':
        note = 5;
        break;
    case 'e':
        note = 7;
        break;
    case 'f':
        note = 8;
        break;
    case 'g':
        note = 10;
        break;
    // TODO: case 'r':
        // break;
    case 0:
        buzzerMusicRunning = 0;
        return;
    default:
        goto parse_character;
    }

    uint8_t octave = 4;  // tmphax
    uint8_t durationNum = 4;  // tmphax

    uint16_t halfPeriod = buzzerHalfPeriodTableOctave0[note] >> octave;
    uint16_t timeout = buzzerTimeoutTableOctave6[note] >> (6 - octave + durationNum);

    buzzerPlayRawToneNext(halfPeriod, timeout);
}
