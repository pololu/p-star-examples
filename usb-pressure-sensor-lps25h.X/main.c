// USB pressure sensor example for the LPS25H and P-Star 25K50
//
// For more information, see:
//
//   https://github.com/pololu/p-star-examples/usb-pressure-sensor-lps25h.X/

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "usb.h"
#include "usb_device.h"
#include "usb_device_cdc.h"
#include "usb_helpers.h"
#include "leds.h"
#include "time.h"
#include "i2c.h"
#include "lps25h.h"

LPS25H ps;
uint8_t psFound;

void cdcSetBaudRateHandler()
{
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

    // Turn the red LED on if we could not find the sensor.
    LED_RED(!psFound);
}

void interrupt high_priority highIsr()
{
    USBDeviceTasks();
}

void interrupt low_priority lowIsr()
{
}

void magToUsbService()
{
    static uint8_t lastUpdateTime = 0;

    // If we already sent a report in the last 100 ms, don't send one now.
    if ((uint8_t)(timeMs - lastUpdateTime) < 100) { return; }

    // If we do not have buffer space available to send data to the USB host,
    // just return.
    if (cdcTxAvailable() < 64) { return; }

    lastUpdateTime = (uint8_t)timeMs;

    if (!psFound)
    {
        // We failed to detect the magnetometer on startup.
        printf("not found\r\n");
        return;
    }

    // Try to read sensor data from the pressure sensor.
    lps25hRead(&ps);

    if (ps.lastResult)
    {
        printf("error\r\n");
        return;
    }

    // Send the data to the USB host.  This uses our definition of putchar below.
    printf("%6d %6d %6d\r\n", ps.p);
}

void putch(char data)
{
    cdcTxSendByte(data);
}

void main(void)
{
    LEDS_INIT();
    timeInit();
    appUsbInit();
    i2cInit();

    // Enable interrupts and interrupt priorities.
    IPEN = 1;
    GIEL = 1;
    GIEH = 1;

    psFound = lps25hInit(&ps, LPS25H_DEVICE_TYPE_AUTO, LPS25H_SA0_AUTO);

    if (psFound)
    {
        lps25hEnableDefault(&ps);
    }

    while (1)
    {
        timeService();
        appUsbService();
        updateLeds();
        magToUsbService();
    }
}
