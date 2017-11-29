# Buzzer Music Example for the P-Star

## Summary

This example shows how you can program a P-Star to play musical melodies on a
buzzer.  It uses Timer 3, the CCP2 module in compare mode, the RC1/CCP2 pin, and
a low-priority interrupt.

See `buzzer-music.h` for more information about how to write music for the
buzzer.  Except for the allowed range of notes and the volume feature, the
buzzer music library used in this example is compatible with the
[OrangutanBuzzer] module in libpololu-avr and the [PololuBuzzer library for
Arduino][PololuBuzzer], so most of the songs in the [3pi Tune Library forum
thread][tunes] should work, and most songs written for the A-Star 32U4
controllers, Zumo 32U4 Robot, Balboa 32U4 Robot, or 3pi Robot should also work.


## Getting started

A [buzzer] should be connected such that current flows through the buzzer
whenever RC1 (also known as CCP2) drives high.  One option is to simply connect
one lead of the buzzer to CCP2 and connect another lead of the buzzer to GND.

See [the top-level README](../README.md) for information about building this
example and writing it to the P-Star.


## Pinout

| Pin | Function                                        |
|-----|-------------------------------------------------|
| RC1 | Sends PWM signals to the buzzer.                |


## LED behavior

This example does not use the P-Star's on-board LEDs.


## Source file organization

The primary file for this example is main.c.  It contains all of the
application-specific logic.

The following files are libraries that could be reused in other P-Star
applications:

- system.h
- time.c, time.h
- buzzer.h, buzzer.c
- buzzer-music.h, buzzer-music.c

[buzzer]: https://www.pololu.com/product/1484
[OrangutanBuzzer]: https://github.com/pololu/libpololu-avr/blob/master/src/OrangutanBuzzer/OrangutanBuzzer.h
[PololuBuzzer]: https://github.com/pololu/pololu-buzzer-arduino
[tunes]: https://forum.pololu.com/t/3pi-tune-library/1305
