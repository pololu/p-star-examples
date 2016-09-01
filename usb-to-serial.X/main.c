// TODO: call USBDeviceAttach and USBDeviceDetach

#include <xc.h>
#include <stdint.h>
#include <usb.h>
#include <usb_device.h>
#include <usb_device_cdc.h>
#include "usb_helpers.h"

static uint8_t readBuffer[CDC_DATA_OUT_EP_SIZE];
static uint8_t writeBuffer[CDC_DATA_IN_EP_SIZE];

void loopbackService()
{
    if (USBGetDeviceState() < CONFIGURED_STATE) { return; }

    if (USBUSARTIsTxTrfReady())
    {
        uint8_t numBytesRead;

        // Read data from the USB serial port.
        numBytesRead = getsUSBUSART(readBuffer, sizeof(readBuffer));

        // For every byte that was read...
        for (uint8_t i = 0; i < numBytesRead; i++)
        {
            switch (readBuffer[i])
            {
            // If we receive a new line or carriage return, just echo it back.
            case '\n':
            case '\r':
                writeBuffer[i] = readBuffer[i];
                break;

            // If we receive something else, then echo it plus one.
            // For example, if we receive 'a', we echo 'b' so that the
            // user knows that it isn't the echo enabled on their
            // terminal program.
            default:
                writeBuffer[i] = readBuffer[i] + 1;
                break;
            }
        }

        // Send the data back to the USB host.
        if (numBytesRead > 0)
        {
            putUSBUSART(writeBuffer, numBytesRead);
        }
    }
}

void interrupt high_priority highIsr()
{
    USBDeviceTasks();
}

void interrupt low_priority lowIsr()
{
}

void main(void)
{
    appUsbInit();

    while (1)
    {
        loopbackService();
        appUsbService();
    }
}

