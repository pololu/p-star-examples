# USB Magnetometer example for the LIS3MDL and P-Star 25K50

## Summary

This example code for the [P-Star 25K50 Micro][pstar25m] reads the raw values
from the LIS3MDL magnetometer.  The values are formatted as ASCII text and sent
to the P-Star's USB virtual COM port, so they can be viewed in a standard
terminal program and can be read from other software.

This example uses the [Microchip USB Stack][mla] to implement a USB device that
has one USB CDC ACM virtual serial port, and it uses the PIC18F25K50's I²C
module to communicate with the LIS3MDL.


## Setup instructions

For Windows users, we recommend installing the driver "p-star-serial.inf".
Download this repository to your computer, open the "drivers" folder,
right-click on "p-star-serial.inf", and select "Install".  If you are using
Windows 10 or later and choose not to install the drivers, the example will
still be usable, but its virtual serial port will have a generic name in your
Device Manager.

Linux and Mac OS X users do not need to install any drivers.

See [the top-level README](../README.md) for information about building this
example and writing it to the P-Star.

An LIS3MDL carrier can be purchased from Pololu's website.  This code supports
the following carrier boards:

* [LIS3MDL 3-Axis Magnetometer Carrier with Voltage Regulator](https://www.pololu.com/product/2737)
* [MinIMU-9 v5 (LSM6DS33 and LIS3MDL Carrier)](https://www.pololu.com/product/2738)
* [AltIMU-10 v5 (LSM6DS33, LIS3MDL, and LPS25H Carrier)](https://www.pololu.com/product/2739)

You should power the LIS3MDL carrier by connecting the P-Star's GND pin to the
carrier's GND and connecting the P-Star's VDD to the carrier's VIN.  You should
also connect the P-Star's RB0 pin to the carrier's SDA pin, and connect the
P-Star's RB1 pin to the carrier's SCL pin.


## Pinout

| Pin | Function                                        |
|-----|-------------------------------------------------|
| RB0 | SDA: I²C data line.                             |
| RB1 | SCL: I²C clock line.                            |


## Description

After you write this example to a P-Star 25K50, the P-Star will appear to the
computer as a USB device that has one USB CDC ACM virtual serial port, using the
Pololu Corporation vendor ID.

If you are using Windows, you should see an entry labeled "P-Star" in your
Device Manager in the "Ports (COM & LPT)" section.  However, if you have Windows
10 or later and did not install our driver before running this example, the name
you see might be "USB Serial Device" instead.

You can connect to the serial port using a terminal program in order to see the
sensor readings.  Each line in the serial data will have the raw readings from
the magnetometer in XYZ order.


## LED behavior

The P-Star's green LED is used in this example to indicate the state of the USB
connection.  In the Configured State (as defined in the USB 2.0 specification),
the green LED is on solid.  Otherwise, if USB power is detected but the device
is not in the Configured State, the LED blinks with a 50% duty cycle once per
second.  If USB power is not detected, the green LED is off.

The yellow LED will always be on while this example is running.

The red LED will be on if the LIS3MDL was not detected when starting up.


## Example uses

With proper calibration of the magnetometer, it might be possible to use this
code to sense nearby magnets or to sense the magnetic field of the earth to tell
which way is north.

It would also be possible to take pieces of this example, such as the USB code or the
I2C code, and reuse them in different applications.


## Source file organization

The primary file for this example is main.c.  It contains all of the
application-specific logic.

The file usb_descriptors.c contains the USB descriptors, which are reported to
the USB host over USB.

The following files are libraries that could be reused in other P-Star
applications:

- leds.h
- time.c, time.h
- i2c.c, i2c.h
- lis3mdl.c, lis3mdl.h
- system.h
- usb_helpers.c, usb_helpers.h
- usb_config.h

The following files are from the USB stack in the [Microchip Libraries for
Applications (MLA)][mla] v2016_08_08:

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
