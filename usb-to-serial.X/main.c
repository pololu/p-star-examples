#include "usb.h"
#include "usb_device.h"
#include "usb_device_cdc.h"
#include <stdint.h>

static uint8_t readBuffer[CDC_DATA_OUT_EP_SIZE];
static uint8_t writeBuffer[CDC_DATA_IN_EP_SIZE];

void interrupt low_priority lowIsr(void)
{
    USBDeviceTasks();
}

void LineCodingInit()
{
    line_coding.bCharFormat = 0;
    line_coding.bDataBits = 8;
    line_coding.bParityType = 0;
    line_coding.dwDTERate = 9600;
}

void LoopbackService()
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
            // If we receive new line or carriage return, just echo it back.
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

    CDCTxService();
}

bool USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, uint16_t size)
{
    switch (event)
    {
    case EVENT_TRANSFER:
        break;

    case EVENT_SOF:
        break;

    case EVENT_SUSPEND:
        break;

    case EVENT_RESUME:
        break;

    case EVENT_CONFIGURED:
        CDCInitEP();
        break;

    case EVENT_SET_DESCRIPTOR:
        break;

    case EVENT_EP0_REQUEST:
        /* We have received a non-standard USB request.  The HID driver
         * needs to check to see if the request was for it. */
        USBCheckCDCRequest();
        break;

    case EVENT_BUS_ERROR:
        break;

    case EVENT_TRANSFER_TERMINATED:
        break;

    default:
        break;
    }
    return true;
}

void main(void)
{
    USBDeviceInit();
    USBDeviceAttach();
    LineCodingInit();

    while (1)
    {
        LoopbackService();
    }
}
