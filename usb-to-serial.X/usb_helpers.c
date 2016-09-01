#include <xc.h>
#include "usb.h"
#include "usb_device.h"
#include "usb_device_cdc.h"
#include "usb_helpers.h"

static void lineCodingInit()
{
    line_coding.bCharFormat = 0;
    line_coding.bDataBits = 8;
    line_coding.bParityType = 0;
    line_coding.dwDTERate = 9600;
}

static void usbPowerSenseInit()
{
    // We use pin RA0 to detect whether USB power is present or not,
    // so we need to enable its digital input buffer.
    ANSELAbits.ANSA0 = 0;
}

bool usbPowerPresent()
{
    return PORTAbits.RA0;
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

void cdcSetLineCodingHandler()
{
    // Store the new line coding from the USB host.
    line_coding = cdc_notice.SetLineCoding;
}