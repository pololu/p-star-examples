// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This header file defines the interface to buzzer-music.c, a library for the
// P-Star that uses buzzer.c to play series of musical notes.
//
// To use this library, make sure you call buzzerIsr() in your low-priority ISR,
// and regularly call buzzerMusicService in your main loop.

#ifndef _BUZZER_MUSIC_H
#define _BUZZER_MUSIC_H

// Include this so the user can get the prototype for buzzerIsr().
#include "buzzer.h"

// Starts playing the specificied musical sequence of notes.  This function is
// non-blocking and will return quickly.  You can do other tasks while the music
// is playing as long as you call buzzerMusicService regularly.
//
// The sequence should be a null-terminated string.
//
// The syntax of the string is based on the PLAY commands in GW-BASIC and the
// OrangutanBuzzer module in the Pololu AVR Library (libpololu-avr).
//
// The notes are specified by the characters C, D, E, F, G, A, and
// B, and they are played by default as "quarter notes" with a
// length of 500 ms.  This corresponds to a tempo of 120
// beats/min.  Other durations can be specified by putting a number
// immediately after the note.  For example, C8 specifies C played as an
// eighth note, with half the duration of a quarter note. The special
// note R plays a rest (no sound).
//
// Various control characters alter the sound:
//
//   '>' plays the next note one octave higher
//
//   '<' plays the next note one octave lower
//
//   '+' or '#' after a note raises any note one half-step
//
//   '-' after a note lowers any note one half-step
//
//   TODO: '.' after a note "dots" it, increasing the length by
//       50%.  Each additional dot adds half as much as the
//       previous dot, so that "A.." is 1.75 times the length of
//       "A".
//
//   'O' followed by a number sets the octave (default: O4).
//       The octave number must be between 1 and 7.
//
//   TODO: 'T' followed by a number sets the tempo (default: T120).
//
//   'L' followed by a number sets the default note duration to
//       the type specified by the number: 4 for quarter notes, 8
//       for eighth notes, 16 for sixteenth notes, etc.
//       (default: L4)
//
//   TODO: 'MS' sets all subsequent notes to play staccato - each note is played
//       for 1/2 of its allotted time, followed by an equal period
//       of silence.
//
//   TODO: 'ML' sets all subsequent notes to play legato - each note is played
//       for its full length.  This is the default setting.
//
//   '!' resets all persistent settings to their defaults.
//
// The following plays a c major scale up and back down:
//   play("!L16 cdefgab>cbagfedc");
//
// Here is an example from Bach:
//   play("!L8 a gafaeada c+adaeafa <aa<bac#ada c#adaeaf4");
void buzzerMusicPlay(const char * sequence);

// Stop playing music.
void buzzerMusicStop();

// Returns true if the buzzer is currently playing music or a simple tone.
bit buzzerMusicIsPlaying();

// You should call this regularly while playing music (and it is OK to call it
// at other times too).
void buzzerMusicSerivce();

#endif
