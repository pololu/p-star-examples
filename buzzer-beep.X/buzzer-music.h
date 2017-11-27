// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This header file defines the interface to buzzer-music.c, a library that uses
// buzzer.c to play series of musical notes.
//
// To use this library, make sure you call buzzerIsr() in your low-priority ISR,
// and regularly call buzzerMusicService.

#ifndef _BUZZER_MUSIC_H
#define _BUZZER_MUSIC_H

// Include this so the user can get the prototype for buzzerIsr().
#include "buzzer.h"

// Returns true if the buzzer is currently playing music or a simple tone.
//
// TODO: make sure this also returns true if the buzzer is playing a simple tone
// that was commanded directly from buzzerPlayRawTone.
bit buzzerMusicIsPlaying();

void buzzerMusicPlay(const char * sequence);

// Stop playing music.
void buzzerMusicStop();

// You should call this regularly while playing music (and it is OK to call it
// at other times too).
void buzzerMusicSerivce();

#endif
