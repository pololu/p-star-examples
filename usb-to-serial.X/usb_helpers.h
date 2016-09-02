#ifndef _USB_HELPERS_H_
#define _USB_HELPERS_H_

void appUsbInit(void);
void appUsbService(void);
bit usbPowerPresent(void);

uint8_t cdcRxAvailable(void);
uint8_t cdcRxReceiveByte();

uint8_t cdcTxAvailable(void);
void cdcTxSendByte(uint8_t);

// This is called from usb_helpers.c but not defined there.
void cdcSetBaudRateHandler(void);

#endif
