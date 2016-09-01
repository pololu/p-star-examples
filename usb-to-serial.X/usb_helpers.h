#ifndef _USB_HELPERS_H_
#define _USB_HELPERS_H_

void appUsbInit();
void appUsbService();
bit usbPowerPresent();

// This is called from usb_helpers.c but not defined there.
void cdcSetBaudRateHandler();

#endif
