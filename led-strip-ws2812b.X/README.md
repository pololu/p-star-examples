# WS2812B/SK6812 LED Strip Example for the P-Star

## Summary

This example shows how you can program a P-Star to
control an LED strip based on the [SK6812/WS281x addressable RGB LEDs][cat].

This example disables interrupts and uses PIC18 assembly code to ensure that the
signal sent to the LED strip has accurate timing.


## Getting started

The P-Star's GND pin should be connected to the ground pin of an LED strip and
the P-Star's RB1 pin should be connected to the data input pin of the LED strip.
You will also need to connect an appropriate power supply to the LED strip.

See [the top-level README](../README.md) for information about building this
example and writing it to the P-Star.


## Pinout

| Pin | Function                                        |
|-----|-------------------------------------------------|
| RB1 | Transmits data to the LED strip                 |


## LED behavior

This example does not use the P-Star's on-board LEDs.

A flowing rainbow pattern is displayed on the attached LED strip.


## Example uses

This app can be expanded to show custom patterns on your LED strip.  You could
add buttons or other controls to adjust the patterns on the LED strip.

The code in this example shows how to use the P-Star to do precise I/O using
bit-banging and assembly code.


## Source file organization

The primary file for this example is main.c.  It contains all of the
application-specific logic.

The following files are libraries that could be reused in other P-Star
applications:

- system.h
- time.c, time.h
- ws2812b.h, ws2812b.c

The file ws2812b_config.h defines what PIC pin to use for the LED strip.

[cat]: https://www.pololu.com/category/151