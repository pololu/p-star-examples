// TODO: use LEDs for something
// TODO: CDC ACM control signals on GPIO pins

#include <xc.h>
#include <stdint.h>
#include <usb.h>
#include <usb_device.h>
#include <usb_device_cdc.h>
#include "usb_helpers.h"
#include "uart.h"

static uint8_t readBuffer[CDC_DATA_OUT_EP_SIZE];
static uint8_t writeBuffer[CDC_DATA_IN_EP_SIZE];

void usbToSerialService()
{
    // If we have not reached the USB configured state yet, we should not
    // be using the USB virtual serial port.
    if (USBGetDeviceState() < CONFIGURED_STATE) { return; }

    // When we receive bytes on the UART's RX line, send them on the
    // virtual serial port.
    // TODO: probably have to make this be much more efficient
    if (USBUSARTIsTxTrfReady() && uartRxAvailable())
    {
        writeBuffer[0] = uartRxReceiveByte();
        putUSBUSART(writeBuffer, 1);
    }

    // When we receive bytes on the virtual USB serial port, send them on
    // the UART's TX line.
    // TODO: fix this
    if (uartTxAvailable())
    {
        uint8_t byteCount = getsUSBUSART(readBuffer, sizeof(readBuffer));
        if (byteCount)
        {
            uartTxSendByte(readBuffer[0]);
        }
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

