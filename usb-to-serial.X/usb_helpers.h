// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// These functions help you use the Microchip USB Stack on the P-Star.

#ifndef _USB_HELPERS_H_
#define _USB_HELPERS_H_

// This should be called at the beginning of your program.
void appUsbInit(void);

// This should be called regularly.
void appUsbService(void);

// Return 0 if USB power is detected, 1 if it is not detected.
bit usbPowerPresent(void);

// Returns the number of bytes available for immediate reading from the
// USB virtual serial port.
uint8_t cdcRxAvailable(void);

// Reads one byte from the USB virtual serial port.  You MUST call
// cdcRxAvailable to make sure bytes are available first, or else this
// function could return invalid data.
uint8_t cdcRxReceiveByte();

// Returns the amount of free buffer space available for sending data to
// the USB virtual serial port.  Note: this value gets invalidated
// when you call appUsbService.
uint8_t cdcTxAvailable(void);

// Queues one byte to be sent on the USB virtual serial port.
// You MUST call cdcTxAvailable to make sure there is buffer space available
// first, or else this function could corrupt your program's memory.
// The bytes will be passed to the PIC's USB module by appUsbService.
// For maximum throughput, you should structure your program so that
// cdcTxSendByte can be called many times before appUsbService.
void cdcTxSendByte(uint8_t);

// This is called from usb_helpers.c but not defined there.
void cdcSetBaudRateHandler(void);

#endif
