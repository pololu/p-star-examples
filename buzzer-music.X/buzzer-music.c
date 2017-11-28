#include "buzzer-music.h"

#include <stdint.h>

// The half periods of the notes in octave 0.
// Spot 12 holds the half period for a rest note (0).
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
// Spot 12 holds the timeout value to use for a rest note; the lower-level
// library treats it as a 1 kHz note for the purpose of setting timeouts.
const uint16_t buzzerTimeoutTableOctave6[12] =
{
    3520,  // 0 = A
    3729,  // 1 = A#
    3951,  // 2 = B
    4186,  // 3 = C
    4435,  // 4 = C#
    4699,  // 5 = D
    4978,  // 6 = D#
    5274,  // 7 = E
    5588,  // 8 = F
    5920,  // 9 = F#
    6272,  // 10 = G
    6645,  // 11 = G#
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

parseCharacter:

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
    case 'r':
        note = 12;
        break;
    case 0:
        buzzerMusicRunning = 0;
        return;
    default:
        goto parseCharacter;
    }

    uint8_t octave = 4;  // tmphax
    uint8_t durationShift = 4;  // tmphax

    uint16_t halfPeriod;
    uint16_t timeout;

    if (note == 12)
    {
        // Rest note
        halfPeriod = 0;
        timeout = 2000 >> durationShift;  // TODO: this is too long?
    }
    else
    {
        halfPeriod = buzzerHalfPeriodTableOctave0[note] >> octave;
        timeout = buzzerTimeoutTableOctave6[note] >> (6 - octave + durationShift);
    }

    buzzerPlayRawToneNext(halfPeriod, timeout);
}
