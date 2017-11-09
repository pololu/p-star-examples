// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This file provides some functions that help you use the Microchip USB Stack
// on the P-Star.  For more information, see usb_helpers.h.

#include <xc.h>
#include "usb.h"
#include "usb_device.h"
#include "usb_device_cdc.h"
#include "usb_helpers.h"

static uint8_t cdcRxBufferLength = 0;
static uint8_t cdcRxBufferIndex = 0;
static uint8_t cdcTxBufferLength = 0;
static uint8_t cdcRxBuffer[CDC_DATA_OUT_EP_SIZE];
static uint8_t cdcTxBuffer[128];

static void lineCodingInit()
{
    line_coding.bCharFormat = 0;
    line_coding.bDataBits = 8;
    line_coding.bParityType = 0;
    line_coding.dwDTERate = 9600;
}

static void usbPowerSenseInit()
{
    // Enable the digital input buffer on the pin we use for detecting USB power.
#if defined(__18F25K50)
    ANSELAbits.ANSA0 = 0;
#elif defined(__18F45K50)
    ANSELEbits.ANSE2 = 0;
#else
#error
#endif
}

bit usbPowerPresent()
{
#if defined(__18F25K50)
    return PORTAbits.RA0;
#elif defined(__18F45K50)
    return PORTEbits.RE2;
#else
#error
#endif
}

void appUsbInit()
{
    usbPowerSenseInit();
    lineCodingInit();
    USBDeviceInit();
}

void appUsbService()
{
    if (usbPowerPresent())
    {
        USBDeviceAttach();
    }
    else
    {
        USBDeviceDetach();
    }

    if (USBGetDeviceState() == CONFIGURED_STATE)
    {
        CDCTxService();

        // If there is data in our buffer to be send to the computer on
        // the virtual serial port, send it.
        if (USBUSARTIsTxTrfReady() && cdcTxBufferLength)
        {
            putUSBUSART(cdcTxBuffer, cdcTxBufferLength);
            cdcTxBufferLength = 0;
        }
    }
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
        cdcRxBufferLength = 0;
        cdcRxBufferIndex = 0;
        cdcTxBufferLength = 0;
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

void cdcSetLineCodingHandler()
{
    // Store the new line coding from the USB host.
    line_coding = cdc_notice.SetLineCoding;

    cdcSetBaudRateHandler();
}

uint8_t cdcRxAvailable(void)
{
    if (USBGetDeviceState() != CONFIGURED_STATE)
    {
        // We are not in the USB Configured state, so we should not
        // be using the USB virtual serial port.
        return 0;
    }

    if (cdcRxBufferIndex >= cdcRxBufferLength)
    {
        // We are done processing the data in cdcRxBuffer, so get more
        // data if it is available.
        cdcRxBufferLength = getsUSBUSART(cdcRxBuffer, sizeof(cdcRxBuffer));
        cdcRxBufferIndex = 0;
    }

    return cdcRxBufferLength - cdcRxBufferIndex;
}

uint8_t cdcRxReceiveByte(void)
{
    return cdcRxBuffer[cdcRxBufferIndex++];
}

uint8_t cdcTxAvailable(void)
{
    if (USBGetDeviceState() != CONFIGURED_STATE)
    {
        // We are not in the USB Configured state, so we should not
        // be using the USB virtual serial port.
        return 0;
    }

    if (!USBUSARTIsTxTrfReady())
    {
        // The CDC stack is busy sending data, probably from our cdcTxBuffer,
        // so we cannot accept any more data right now.
        return 0;
    }

    return sizeof(cdcTxBuffer) - cdcTxBufferLength;
}

void cdcTxSendByte(uint8_t data)
{
    cdcTxBuffer[cdcTxBufferLength++] = data;
}
