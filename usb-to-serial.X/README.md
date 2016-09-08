# USB-to-serial adapter example for the P-Star 25K50

## Summary

This example shows how you can program a [P-Star 25K50 Micro][pstar25m] to be a
USB-to-Serial adapter that is capable of baud rates from 300 bps to 115200 bps.

This example uses the [Microchip USB Stack][mla] to implement a USB device that
has one USB CDC ACM virtual serial port, and it uses the PIC18F25K50's UART to
send and receive serial data.


## Installation instructions

For Windows users, we recommend installing the driver "p-star-serial.inf".
Download the [entire repository](../) to your computer, open the "drivers"
folder, right-click on "p-star-serial.inf", and select "Install".  If you are
using Windows 10 or later and choose not to install the drivers, the example
will still be usable, but its virtual serial port will have a generic name in
your Device Manager.

Linux and Mac OS X users do not need to install any drivers.

See [the top-level README.md](../README.md) for information about building this
example in the MPLAB XPress IDE or MPLAB X IDE and uploading it to the P-Star.


## Pinout

| Pin | Function                                        |
|-----|-------------------------------------------------|
| RC7 | RX: receives data and sends it to the computer  |
| RC6 | TX: transmits serial data from computer         |


## Description

After you write this example onto a P-Star 25K50, the P-Star will appear to the
computer as a USB device that has one USB CDC ACM virtual serial port, using the
Pololu Corporation vendor ID and a product ID of 0x2400.

If you are using Windows, you should see an entry labeled "P-Star" in your
Device Manage in the "Ports (COM & LPT)" section.  However, if you have Windows
10 or later and did not install our driver before running this example, the name
you see might be "USB Serial Device" instead.

You can connect to the serial port using a terminal program in order to send and
receive data on the TX and RX lines.  Typical terminal programs will allow you
to set the baud rate of the serial port.  This example always uses one stop bit
and does not support any type of parity bit.


## LED behavior

The P-Star's green LED is used in this example to indicate the state of the USB
connection.  In the Configured State (as defined in the USB 2.0 specification),
the green LED is on solid.  Otherwise, if USB power is detected but the device
is not in the Configured State, the LED blinks with a 50% duty cycle once per
second.  If USB power is not detected, the green LED is off.

The yellow LED will always be on while this example is running.

The red LED is on the TX/RC6 line, so it blink when data is being sent on the TX
line and be off otherwise.


## Caveats

The RX/RC7 line of the P-Star 25K50 does not have an internal pull-up resistor,
so you could receive invalid data when the RX line is not connected.  We
recommend connecting a 10 kilohm resistor between RC7 and VDD.


## Example uses

The TX line can be used to send commands to a microcontroller or other serial
device.  The RX line can be used to receive data from a microcontroller or other
serial device.

It would be possible to take pieces of this example, such as the USB code or the
UART code, and reuse them in different applications.

It would be possible to enhance this example to support advanced features of
serial ports, such as handshaking lines, flow control, break sending, and
reporting errors to the computer.

It would also be possible to modify this example to make a customized
USB-to-Serial adapter with application-specific behavior.


## Source file structure

The primary file for this example is main.c.  It contains all of the
application-specific logic.

The file usb_descriptors.c contains the USB descriptors, which are reported to
the USB host over USB.

The following files are libraries that could be reused in other P-Star
applications:

- leds.h
- time.c, time.h
- system.h
- uart.c, uart.h
- usb_helpers.c, usb_helpers.h

The following files are from the USB stack in the Microchip Libraries for
Applications (MLA) v2016_08_08:

- usb.h
- usb_ch9.h
- usb_common.h
- usb_device.c, usb_device.h
- usb_device_cdc.c, usb_device_cdc.h
- usb_device_local.h
- usb_hal.h
- usb_hal_pic18.h

[pstar25m]: https://www.pololu.com/product/3150
[mla]: http://www.microchip.com/mplab/microchip-libraries-for-applications