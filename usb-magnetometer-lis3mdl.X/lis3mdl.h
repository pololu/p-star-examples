// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This is the header file for lis3mdl.c, a library for reading data from the
// LIS3MDL accelerometer/gyro.

#ifndef _LIS3MDL_H
#define _LIS3MDL_H

#include <stdint.h>

enum LIS3MDLDeviceType {
    LIS3MDL_DEVICE_TYPE_AUTO,
    LIS3MDL_DEVICE_TYPE_LIS3MDL
};

enum LIS3MDLSA1State {
    LIS3MDL_SA1_AUTO,
    LIS3MDL_SA1_LOW,
    LIS3MDL_SA1_HIGH
};

// Addresses of LIS3MDL registers.
enum LIS3MDLRegAddr
{
    LIS3MDL_WHO_AM_I    = 0x0F,

    LIS3MDL_CTRL_REG1   = 0x20,
    LIS3MDL_CTRL_REG2   = 0x21,
    LIS3MDL_CTRL_REG3   = 0x22,
    LIS3MDL_CTRL_REG4   = 0x23,
    LIS3MDL_CTRL_REG5   = 0x24,

    LIS3MDL_STATUS_REG  = 0x27,
    LIS3MDL_OUT_X_L     = 0x28,
    LIS3MDL_OUT_X_H     = 0x29,
    LIS3MDL_OUT_Y_L     = 0x2A,
    LIS3MDL_OUT_Y_H     = 0x2B,
    LIS3MDL_OUT_Z_L     = 0x2C,
    LIS3MDL_OUT_Z_H     = 0x2D,
    LIS3MDL_TEMP_OUT_L  = 0x2E,
    LIS3MDL_TEMP_OUT_H  = 0x2F,
    LIS3MDL_INT_CFG     = 0x30,
    LIS3MDL_INT_SRC     = 0x31,
    LIS3MDL_INT_THS_L   = 0x32,
    LIS3MDL_INT_THS_H   = 0x33,
};

// Represents a single LIS3MDL device.
typedef struct LIS3MDL {
    enum LIS3MDLDeviceType device;
    uint8_t address;

    // Functions that perform I2C transfers to the LIS3MDL will modify this variable
    // to indicate whether they succeeded.  0 means success, non-zero indicates
    // an error.
    uint8_t lastResult;

    // The last set of raw magnetometer readings from the device, in XYZ order.
    int16_t m[3];
} LIS3MDL;

// Initializes the library and confirms that we can communicate with the device.
// Returns 1 for success and 0 for failure.
uint8_t lis3mdlInit(LIS3MDL *, enum LIS3MDLDeviceType, enum LIS3MDLSA1State);

// Enables the LIS3MDL's magnetometer. Also:
// - Selects ultra-high-performance mode for all axes
// - Sets ODR (output data rate) to default power-on value of 10 Hz
// - Sets magnetometer full scale (gain) to default power-on value of +/- 4 gauss
// - Enables continuous conversion mode
//
// Note that this function will also reset other settings controlled by the
// registers it writes to.
void lis3mdlEnableDefault(LIS3MDL *);

// Writes to one of the LIS3MDL registers.  The "reg" argument should be the
// register address and the "value" argument should be the value to write.
void lis3mdlWriteReg(LIS3MDL *, uint8_t reg, uint8_t value);

// Reads from an LIS3MDL register and returns the value.  The "reg" argument
// should be the register address.
uint8_t lis3mdlReadReg(LIS3MDL *, uint8_t reg);

// Reads from the magnetomter and stores the results in the "m" member of the
// LIS3MDL object.
void lis3mdlRead(LIS3MDL *);

#endif
