// USB inertial measurement unit example for the LSM6DS33 and P-Star 25K50
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

    // Turn the red LED off.
    LED_RED(0);
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
    LEDS_INIT();
    timeInit();
    appUsbInit();

    i2cInit();   // must be before lsm6Init
    lsm6Init(&imu, LSM6_DEVICE_TYPE_AUTO, LSM6_SA0_AUTO);

    // Enable interrupts with both high and low priority.
    IPEN = 1;
    GIEL = 1;
    GIEH = 1;

    uint8_t lastUpdateTime = 0;
    while (1)
    {
        timeService();
        appUsbService();
        updateLeds();

        if ((uint8_t)(timeMs - lastUpdateTime) >= 100)
        {
            lastUpdateTime = (uint8_t)timeMs;

            uint8_t found = lsm6Init(&imu, LSM6_DEVICE_TYPE_AUTO, LSM6_SA0_AUTO);

            if (cdcTxAvailable() >= 64)
            {
                printf("found: %d %d %d\r\n", found, imu.device, imu.address);
            }
        }
    }
}

void putch(char data)
{
    cdcTxSendByte(data);
}
