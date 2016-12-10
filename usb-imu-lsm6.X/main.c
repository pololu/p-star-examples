// USB accelerometer/gyro example for the LSM6DS33 and P-Star 25K50
//
// For more information, see:
//
//   https://github.com/pololu/p-star-examples/usb-imu-lsm6.X/

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
#include "lsm6.h"

LSM6 imu;
uint8_t imuFound;

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

    // Turn the red LED on if we could not find the LSM6.
    LED_RED(!imuFound);
}

void interrupt high_priority highIsr()
{
    USBDeviceTasks();
}

void interrupt low_priority lowIsr()
{
}

void imuToUsbService()
{
    static uint8_t lastUpdateTime = 0;

    // If we already sent a report in the last 20 ms, don't send one now.
    if ((uint8_t)(timeMs - lastUpdateTime) < 20) { return; }

    // If we do not have buffer space available to send data to the USB host,
    // just return.
    if (cdcTxAvailable() < 64) { return; }

    lastUpdateTime = (uint8_t)timeMs;

    if (!imuFound)
    {
        // We failed to detect the IMU on startup.
        printf("not found\r\n");
        return;
    }

    // Try to read sensor data from the IMU.
    lsm6Read(&imu);

    if (imu.lastResult)
    {
        printf("error\r\n");
        return;
    }

    // Send the IMU data to the USB host.  This uses our definition of
    // putchar below.
    printf("A: %6d %6d %6d    G: %6d %6d %6d\r\n",
        imu.a[0], imu.a[1], imu.a[2],
        imu.g[0], imu.g[1], imu.g[2]);
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

    imuFound = lsm6Init(&imu, LSM6_DEVICE_TYPE_AUTO, LSM6_SA0_AUTO);

    if (imuFound)
    {
        lsm6EnableDefault(&imu);
    }

    while (1)
    {
        timeService();
        appUsbService();
        updateLeds();
        imuToUsbService();
    }
}
