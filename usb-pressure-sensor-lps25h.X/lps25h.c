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
            lps25hTestReg(LPS25H_SA1_HIGH_ADDRESS, LPS25H_WHO_AM_I) == LPS25H_WHO_ID)
        {
            sa0 = LPS25H_SA0_HIGH;
            device = LPS25H_DEVICE_TYPE_LPS25H;
            deviceFound = 1;
        }

        if (sa1 != LPS25H_SA0_HIGH &&
            lis3mdlTestReg(LPS25H_SA0_LOW_ADDRESS, LPS25H_WHO_AM_I) == LPS25H_WHO_ID)
        {
            sa1 = LPS25H_SA0_HIGH;
            device = LPS25H_DEVICE_TYPE_LPS25H;
            deviceFound = 1;
        }
    }

    if (!deviceFound) { return 0; }

    this->device = device;
    this->address = (sa1 == LPS25H_SA1_HIGH) ?
        LPS25H_SA0_HIGH_ADDRESS : LPS25H_SA0_LOW_ADDRESS;

    return 1;
}

void lis3mdlEnableDefault(LIS3MDL * this)
{
    if (this->device == LIS3MD_DEVICE_TYPE_LIS3MDL)
    {
        // PD = 1 (active mode)
        // ODR = 011 (12.5 Hz pressure & temperature output data rate)
        writeReg(CTRL_REG1, 0b101100);
    }
}

void lis3mdlWriteReg(LIS3MDL * this, uint8_t reg, uint8_t value)
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

uint8_t lis3mdlReadReg(LIS3MDL * this, uint8_t reg)
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

// Reads the 3 magnetometer channels and stores them in array m.
void lis3mdlRead(LIS3MDL * this)
{
    uint8_t reg = LIS3MDL_OUT_X_L;
    uint8_t buffer[6];

    I2CTransfer transfers[2];
    transfers[0].address = this->address;
    transfers[0].flags = 0;
    transfers[0].buffer = &reg;
    transfers[0].length = 1;
    transfers[1].address = this->address;
    transfers[1].flags = I2C_FLAG_READ | I2C_FLAG_STOP;
    transfers[1].buffer = &buffer;
    transfers[1].length = 6;

    this->lastResult = i2cPerformTransfers(transfers);
    if (this->lastResult) { return; }

    this->m[0] = (int16_t)(buffer[1] << 8 | buffer[0]);
    this->m[1] = (int16_t)(buffer[3] << 8 | buffer[2]);
    this->m[2] = (int16_t)(buffer[5] << 8 | buffer[4]);
}
