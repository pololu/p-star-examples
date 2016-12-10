// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// A library for reading data from the LIS3MDL magnetometer.  See lis3mdl.h
// for documentation.

#include "lis3mdl.h"
#include "i2c.h"

#define LIS3MDL_SA1_HIGH_ADDRESS  0b0011110
#define LIS3MDL_SA1_LOW_ADDRESS   0b0011100

#define LIS3MDL_WHO_ID 0x3D

static int16_t lis3mdlTestReg(uint8_t address, uint8_t reg)
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

uint8_t lis3mdlInit(LIS3MDL * this, enum LIS3MDLDeviceType device, enum LIS3MDLSA1State sa1)
{
    // Detect the device type and SA1 state if needed, and also see if we
    // can talk to the device.
    uint8_t deviceFound = 0;
    if (device == LIS3MDL_DEVICE_TYPE_AUTO || device == LIS3MDL_DEVICE_TYPE_LIS3MDL)
    {
        if (sa1 != LIS3MDL_SA1_LOW &&
            lis3mdlTestReg(LIS3MDL_SA1_HIGH_ADDRESS, LIS3MDL_WHO_AM_I) == LIS3MDL_WHO_ID)
        {
            sa1 = LIS3MDL_SA1_HIGH;
            device = LIS3MDL_DEVICE_TYPE_LIS3MDL;
            deviceFound = 1;
        }

        if (sa1 != LIS3MDL_SA1_HIGH &&
            lis3mdlTestReg(LIS3MDL_SA1_LOW_ADDRESS, LIS3MDL_WHO_AM_I) == LIS3MDL_WHO_ID)
        {
            sa1 = LIS3MDL_SA1_HIGH;
            device = LIS3MDL_DEVICE_TYPE_LIS3MDL;
            deviceFound = 1;
        }
    }

    if (!deviceFound) { return 0; }

    this->device = device;
    this->address = (sa1 == LIS3MDL_SA1_HIGH) ?
        LIS3MDL_SA1_HIGH_ADDRESS : LIS3MDL_SA1_LOW_ADDRESS;

    return 1;
}

void lis3mdlEnableDefault(LIS3MDL * this)
{
    if (this->device == LIS3MDL_DEVICE_TYPE_LIS3MDL)
    {
        // OM = 11 (ultra-high-performance mode for X and Y); DO = 100 (10 Hz ODR)
        lis3mdlWriteReg(this, LIS3MDL_CTRL_REG1, 0b01110000);
        if (this->lastResult) { return; }

        // FS = 00 (+/- 4 gauss full scale)
        lis3mdlWriteReg(this, LIS3MDL_CTRL_REG2, 0b00000000);
        if (this->lastResult) { return; }

        // MD = 00 (continuous-conversion mode)
        lis3mdlWriteReg(this, LIS3MDL_CTRL_REG3, 0b00000000);
        if (this->lastResult) { return; }

        // OMZ = 11 (ultra-high-performance mode for Z)
        lis3mdlWriteReg(this, LIS3MDL_CTRL_REG4, 0b00001100);
        if (this->lastResult) { return; }
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
