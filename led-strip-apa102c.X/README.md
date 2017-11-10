# APA102C LED Strip Example for the P-Star

## Summary

This example shows how you can program a P-Star to
control an LED strip based on the [APA102C addressable RGB LEDs][cat].


## Getting started

The P-Star's GND pin should be connected to the ground pin of an LED strip.
The P-Star's RB1 pin should be connected to the clock input pin of the LED strip.
The P-Star's RB2 pin should be connected to the data input pin of the LED strip.
You will also need to connect an appropriate power supply to the LED strip.

See [the top-level README](../README.md) for information about building this
example and writing it to the P-Star.


## Pinout

| Pin | Function                                        |
|-----|-------------------------------------------------|
| RB1 | Transmits the clock signal to the LED strip     |
| RB2 | Transmits data to the LED strip                 |


## LED behavior

This example does not use the P-Star's on-board LEDs.

A flowing rainbow pattern is displayed on the attached LED strip.


## Example uses

This app can be expanded to show custom patterns on your LED strip.  You could
add buttons or other controls to adjust the patterns on the LED strip.


## Source file organization

The primary file for this example is main.c.  It contains all of the
application-specific logic.

The following files are libraries that could be reused in other P-Star
applications:

- system.h
- time.c, time.h
- apa102c.h, apa102c.c

The file apa102c_config.h defines what PIC pins to use for the LED strip.

[cat]: https://www.pololu.com/category/181