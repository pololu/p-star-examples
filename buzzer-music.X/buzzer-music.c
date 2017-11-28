#include "buzzer-music.h"

#include <stdint.h>

// We set A4 (the note A in octave 4) to have a frequency of 440 Hz.
//
// The lowest octave we support is octave 0; A0 has a freqency of 440/16 =
// 27.50 Hz, so its half period is 54545, which is almost too much to fit in the
// 16-bit CCPR2 register.
//
// The highest octave we support is octave we support is 6.  The G#6 note has a
// frequency of 3322 Hz, so it is almost too high for the 5 kHz limit of the
// buzzer.c library we use.

#define OCTAVE_MAX 6

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
const char * buzzerSequence;

// The octave number, from 0 to OCTAVE_MAX.
uint8_t buzzerDefaultOctave = 4;

// The duration divider determines how long the notes are.
// 1 = whole, 2 = half, 3 = one third of a whole note, 4 = quarter note
uint8_t buzzerDefaultDurationDivider = 4;

static void buzzerMusicResetToDefaults()
{
    buzzerDefaultOctave = 4;
    buzzerDefaultDurationDivider = 4;
}

void buzzerMusicPlay(const char * sequence)
{
    buzzerSequence = sequence;
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

static uint16_t buzzerMusicGetNumber()
{
    uint16_t n = 0;
    while (1)
    {
        uint8_t c = *buzzerSequence;
        if (!(c >= '0' && c <= '9')) { break; }
        n = (n * 10) + (c - '0');
        buzzerSequence++;
    }
    return n;
}

void buzzerMusicService()
{
    if (!buzzerMusicRunning || buzzerNextToneReady())
    {
        return;
    }

    uint8_t c;
    uint8_t note = 0;
    uint8_t rest = 0;
    uint8_t octave = buzzerDefaultOctave;
    uint8_t durationDivider = buzzerDefaultDurationDivider;

parseCharacter:
    c = *buzzerSequence++;

    // Convert to lower case.
    if (c >= 'A' && c <= 'Z')
    {
        c += 'a' - 'A';
    }

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
        rest = 1;
        break;
    case 'l':
        buzzerDefaultDurationDivider = durationDivider = buzzerMusicGetNumber();
        goto parseCharacter;
    case 'o':
        buzzerDefaultOctave = octave = buzzerMusicGetNumber();
        goto parseCharacter;
    case '!':
        buzzerMusicResetToDefaults();
        goto parseCharacter;
    case 0:
        // Stop playing when we reach the null byte that end of the string.
        buzzerMusicRunning = 0;
        return;
    default:
        // Ignore unknown/unsupported characters.
        goto parseCharacter;
    }

    // We found a note.  Now peek at the next character in the sequence so we
    // can detect modifiers.
    c = *buzzerSequence;

    // Handle sharps and flats.  If 'note' overflows outside of the 0 to 11
    // range, we correct it and change the octave.
    while (c == '+' || c == '#')
    {
        note++;
        if (note >= 12)
        {
            note = 0;
            octave++;
        }
        c = *++buzzerSequence;
    }
    while (c == '-')
    {
        note--;
        if (note >= 12)
        {
            note = 11;
            octave--;
        }
        c = *++buzzerSequence;
    }

    // Check for a duration divider after the note.
    // (e.g. 'c16' is a sixteenth note).
    if (c >= '0' && c <= '9')
    {
        durationDivider = buzzerMusicGetNumber();
    }

    if (octave > OCTAVE_MAX)
    {
        octave = OCTAVE_MAX;
    }

    // Now calculate 'halfPeriod' and 'timeout' from
    // 'octave', 'note', 'durationDivider', and 'rest'.
    uint16_t halfPeriod;
    uint16_t timeout;
    if (rest)
    {
        // Rest note
        halfPeriod = 0;
        timeout = 2000 / durationDivider;
    }
    else
    {
        halfPeriod = buzzerHalfPeriodTableOctave0[note] >> octave;
        timeout = (buzzerTimeoutTableOctave6[note] >> (OCTAVE_MAX - octave))
            / durationDivider;
    }

    buzzerPlayRawToneNext(halfPeriod, timeout);
}
