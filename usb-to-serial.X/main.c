// TODO: use LEDs for something
// TODO: CDC ACM control signals on GPIO pins

#include <xc.h>
#include <stdint.h>
#include <usb.h>
#include <usb_device.h>
#include <usb_device_cdc.h>
#include "usb_helpers.h"
#include "uart.h"

void usbToSerialService()
{
    // If we have not reached the USB configured state yet, we should not
    // be using the USB virtual serial port.
    if (USBGetDeviceState() < CONFIGURED_STATE) { return; }

    // When we receive bytes on the UART's RX line, send them on the
    // virtual serial port.
    // TODO: probably have to make this be much more efficient
    if (uartRxAvailable() && cdcTxAvailable())
    {
        cdcTxSendByte(uartRxReceiveByte());
    }

    // When we receive bytes on the virtual USB serial port, send them on
    // the UART's TX line.
    // TODO: fix this
    if (cdcRxAvailable() && uartTxAvailable())
    {
        uartTxSendByte(cdcRxReceiveByte());
    }
}

// When the computer sets the baud rate of the virtual USB serial port, we
// set the baud rate of the UART to match it.
void cdcSetBaudRateHandler()
{
    uartSetBaudRate(line_coding.dwDTERate);
}

void interrupt high_priority highIsr()
{
    USBDeviceTasks();
    uartIsr();
}

void interrupt low_priority lowIsr()
{
}

void main(void)
{
    uartInit();
    appUsbInit();

    while (1)
    {
        usbToSerialService();
        appUsbService();
    }
}

