#include "buzzer-music.h"

#include <stdint.h>

// Each octave has 12 notes, numbered from 0 to 11.  The lowest is C (note 0)
// and the highest is B (note 11).  We set A4 (the note A in octave 4) to have a
// frequency of 440 Hz.
//
// Given a note number and an octave, these formulae define the quanties we need
// for our low-level buzzer library:
//
//   note_value = octave * 12 + note
//   frequency = 440/16 * (2**((note_value-9)/12))
//   half_period = 1500000 / frequency
//   whole note (2 s) timeout = frequency * 2
//
// The lowest octave we support is octave 1.  C1 has a freqency of 32.70 Hz, so
// its half period is 45867, which is almost too much to fit in the 16-bit CCPR2
// register.
//
// The highest octave we support is octave we support is 7.  The B7 note has a
// frequency of 3951 Hz, so it is almost too high for the 5 kHz limit of the
// low-level buzzer library we use.

#define OCTAVE_MIN 1
#define OCTAVE_MAX 7

// The half periods of the notes in octave 1.
const uint16_t buzzerHalfPeriodTableOctaveMin[12] =
{
    45867,
    43293,
    40863,
    38569,
    36405,
    34361,
    32433,
    30613,
    28894,
    27273,
    25742,
    24297,
};

// This table holds the timeouts of whole notes in octave 7 at a tempo of 120
// beats (quarter notes) per minute.  So this is the number of buzzer periods
// that happen in a whole note (2 s), so it is just the frequency of the note in
// Hz times 2.
const uint16_t buzzerTimeoutTableOctaveMaxTempo120[12] =
{
    4186, 4435, 4699, 4978, 5274, 5588,
    5920, 6272, 6645, 7040, 7458, 7902,
};

// This is a writable copy of the timeout table above that we modify if the user
// changes the tempo.
uint16_t buzzerTimeoutTableOctaveMax[12] =
{
    4186, 4435, 4699, 4978, 5274, 5588,
    5920, 6272, 6645, 7040, 7458, 7902,
};

uint8_t buzzerMusicRunning = 0;
const char * buzzerSequence;

// The octave number, from OCTAVE_MIN to OCTAVE_MAX.
uint8_t buzzerDefaultOctave = 4;

// The duration divider determines how long the notes are.
// 1 = whole, 2 = half, 3 = one third of a whole note, 4 = quarter note
uint8_t buzzerDefaultDurationDivider = 4;

// Sets the tempo (number of quarter notes per minute).  The tempo must be at
// least 15 or we will have an overflow in the calculations.
static void buzzerMusicSetTempo(uint16_t tempo)
{
    for (uint8_t i = 0; i < 11; i++)
    {
        buzzerTimeoutTableOctaveMax[i] =
            (uint32_t)buzzerTimeoutTableOctaveMaxTempo120[i] * 120 / tempo;
    }
}

static void buzzerMusicResetToDefaults()
{
    buzzerDefaultOctave = 4;
    buzzerDefaultDurationDivider = 4;
    buzzerMusicSetTempo(120);
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
    case '>':
        octave++;
        goto parseCharacter;
    case '<':
        octave--;
        goto parseCharacter;
    case 'c':
        note = 0;
        break;
    case 'd':
        note = 2;
        break;
    case 'e':
        note = 4;
        break;
    case 'f':
        note = 5;
        break;
    case 'g':
        note = 7;
        break;
    case 'a':
        note = 9;
        break;
    case 'b':
        note = 11;
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
    case 't':
        buzzerMusicSetTempo(buzzerMusicGetNumber());
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

    // Avoid invalid shifts below.
    if (octave < OCTAVE_MIN) { octave = OCTAVE_MIN; }
    if (octave > OCTAVE_MAX) { octave = OCTAVE_MAX; }

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
        halfPeriod = buzzerHalfPeriodTableOctaveMin[note] >> (octave - OCTAVE_MIN);
        timeout = (buzzerTimeoutTableOctaveMax[note] >> (OCTAVE_MAX - octave))
            / durationDivider;
    }

    buzzerPlayRawToneNext(halfPeriod, timeout);
}
