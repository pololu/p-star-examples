// TODO: use LEDs for something
// TODO: CDC ACM control signals on GPIO pins

#include <xc.h>
#include <stdint.h>
#include <usb.h>
#include <usb_device.h>
#include <usb_device_cdc.h>
#include "usb_helpers.h"
#include "uart.h"
#include "leds.h"
#include "time.h"

void usbToSerialService()
{
    // When we receive bytes on the UART's RX line, send them on the
    // virtual serial port.
    while (uartRxAvailable() && cdcTxAvailable())
    {
        cdcTxSendByte(uartRxReceiveByte());
    }

    // When we receive bytes on the virtual USB serial port, send them on
    // the UART's TX line.
    while (cdcRxAvailable() && uartTxAvailable())
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

void updateLeds()
{
    uint8_t blinkPhase = millis() >> 3;

    if (USBGetDeviceState() == CONFIGURED_STATE)
    {
        // In the USB configured state, turn on the green LED.
        LED_GREEN(1);
    }
    else if (USBGetDeviceState() != DETACHED_STATE)
    {
        // If we have USB power but are not configured,
        // do a 50% duty cycle blink once per second.
        LED_GREEN(blinkPhase & 64);
    }
    else
    {
        // Otherwise, turn the LED off.
        LED_GREEN(0);
    }

    // Turn the yellow LED on.
    LED_YELLOW(1);

    // The red LED is on the TX line (RC6), so we cannot control it.
    // The TRISC6 bit is managed by uart.c.
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
    LEDS_INIT();
    timeInit();
    uartInit();
    appUsbInit();

    while (1)
    {
        timeService();
        usbToSerialService();
        appUsbService();
        updateLeds();
    }
}

