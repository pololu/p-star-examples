# Buzzer Beep Example for the P-Star

## Summary

This example shows how you can program a P-Star to play simple beeps on a
buzzer.  It uses Timer 3, the CCP2 module in compare mode, the RC1/CCP2 pin, and
a low-priority interrupt.


## Getting started

A [buzzer] should be connected such that current flows through the buzzer
whenever RC1 (also known as CCP2) drives high.  You can simply connect one lead of the buzzer to CCP2 and connect another lead of the buzzer to GND.

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

[buzzer]: https://www.pololu.com/product/1484
