// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// A library for reading data from the LPS25H pressure sensor.  See lps25h.h
// for documentation.

#include "lps25h.h"
#include "i2c.h"

#define SA0_LOW_ADDRESS  0b1011100
#define SA0_HIGH_ADDRESS 0b1011101

#define LPS25H_WHO_ID   0xBD

static int16_t lps25hTestReg(uint8_t address, uint8_t reg)
{
    uint8_t value = 0;
    I2CTransfer transfers[2];
    transfers[0].address = address;
    transfers[0].flags = 0;
    transfers[0].buffer = &reg;
    transfers[0].length = 1;
    transfers[1].address = address;
    transfers[1].flags = I2C_FLAG_READ | I2C_FLAG_STOP;
    transfers[1].buffer = &value;
    transfers[1].length = 1;
    if (i2cPerformTransfers(transfers)) { return -1; }
    return value;
}

uint8_t lps25hInit(LPS25H * this, enum LPS25HDeviceType device, enum LPS25HSA0State sa0)
{
    // Detect the device type and SA0 state if needed, and also see if we
    // can talk to the device.

    uint8_t deviceFound = 0;
    if (device == LPS25H_DEVICE_TYPE_AUTO || device == LPS25H_DEVICE_TYPE_LPS25H)
    {
        if (sa0 != LPS25H_SA0_LOW &&
            lps25hTestReg(SA0_HIGH_ADDRESS, LPS25H_WHO_AM_I) == LPS25H_WHO_ID)
        {
            sa0 = LPS25H_SA0_HIGH;
            device = LPS25H_DEVICE_TYPE_LPS25H;
            deviceFound = 1;
        }

        if (sa0 != LPS25H_SA0_HIGH &&
            lps25hTestReg(SA0_LOW_ADDRESS, LPS25H_WHO_AM_I) == LPS25H_WHO_ID)
        {
            sa0 = LPS25H_SA0_HIGH;
            device = LPS25H_DEVICE_TYPE_LPS25H;
            deviceFound = 1;
        }
    }

    if (!deviceFound) { return 0; }

    this->device = device;
    this->address = (sa0 == LPS25H_SA0_HIGH) ?
        SA0_HIGH_ADDRESS : SA0_LOW_ADDRESS;

    return 1;
}

void lps25hEnableDefault(LPS25H * this)
{
    if (this->device == LPS25H_DEVICE_TYPE_LPS25H)
    {
        // PD = 1 (active mode)
        // ODR = 011 (12.5 Hz pressure & temperature output data rate)
        lps25hWriteReg(this, LPS25H_CTRL_REG1, 0b10110000);
    }
}

void lps25hWriteReg(LPS25H * this, uint8_t reg, uint8_t value)
{
    uint8_t buffer[2];
    buffer[0] = reg;
    buffer[1] = value;

    I2CTransfer transfers[1];
    transfers[0].address = this->address;
    transfers[0].flags = I2C_FLAG_STOP;
    transfers[0].buffer = &buffer;
    transfers[0].length = 2;

    this->lastResult = i2cPerformTransfers(transfers);
}

uint8_t lps25hReadReg(LPS25H * this, uint8_t reg)
{
    uint8_t value = 0;

    I2CTransfer transfers[2];
    transfers[0].address = this->address;
    transfers[0].flags = 0;
    transfers[0].buffer = &reg;
    transfers[0].length = 1;
    transfers[1].address = this->address;
    transfers[1].flags = I2C_FLAG_READ | I2C_FLAG_STOP;
    transfers[1].buffer = &value;
    transfers[1].length = 1;

    this->lastResult = i2cPerformTransfers(transfers);
    return value;
}

float lps25hReadPressureMillibars(LPS25H * this)
{
    return (float)lps25hReadPressureRaw(this) / 4096;
}

float lps25hReadPressureInchesHg(LPS25H * this)
{
    return (float)lps25hReadPressureRaw(this) / 138706.5;
}

int24_t lps25hReadPressureRaw(LPS25H * this)
{
    // Set MSB to 1 to enable register address auto-increment.
    uint8_t reg = LPS25H_PRESS_OUT_XL | 0x80;
    uint8_t buffer[3];

    I2CTransfer transfers[2];
    transfers[0].address = this->address;
    transfers[0].flags = 0;
    transfers[0].buffer = &reg;
    transfers[0].length = 1;
    transfers[1].address = this->address;
    transfers[1].flags = I2C_FLAG_READ | I2C_FLAG_STOP;
    transfers[1].buffer = &buffer;
    transfers[1].length = 3;

    this->lastResult = i2cPerformTransfers(transfers);
    if (this->lastResult) { return 0; }

    return (int24_t)(
        (buffer[0]) |
        (buffer[1] << 8) |
        ((uint24_t)buffer[2] << 16));
}

float lps25hReadTemperatureC(LPS25H * this)
{
    return 42.5 + (float)lps25hReadTemperatureRaw(this) / 480;
}

float lps25hReadTemperatureF(LPS25H * this)
{
    return 108.5 + (float)lps25hReadTemperatureRaw(this) / 480 * 1.8;
}

int16_t lps25hReadTemperatureRaw(LPS25H * this)
{
    // Set MSB to 1 to enable register address auto-increment.
    uint8_t reg = LPS25H_TEMP_OUT_L | 0x80;
    uint8_t buffer[2];

    I2CTransfer transfers[2];
    transfers[0].address = this->address;
    transfers[0].flags = 0;
    transfers[0].buffer = &reg;
    transfers[0].length = 1;
    transfers[1].address = this->address;
    transfers[1].flags = I2C_FLAG_READ | I2C_FLAG_STOP;
    transfers[1].buffer = &buffer;
    transfers[1].length = 2;

    this->lastResult = i2cPerformTransfers(transfers);
    if (this->lastResult) { return 0; }

    return (int16_t)((uint16_t)buffer[0] | (uint16_t)buffer[1] << 8);
}
