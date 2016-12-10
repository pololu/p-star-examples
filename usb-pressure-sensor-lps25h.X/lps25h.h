// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This is the header file for lps25h.c, a library for reading data from the
// LPS25H pressure/altitude sensor.

#ifndef _LPS25H_H
#define _LPS25H_H

#include <stdint.h>

enum LPS25HDeviceType {
    LPS25H_DEVICE_TYPE_AUTO,
    LPS25H_DEVICE_TYPE_LPS25H
};

enum LPS25HSA0State {
    LPS25H_SA0_AUTO,
    LPS25H_SA0_LOW,
    LPS25H_SA0_HIGH
};

// Addresses of LPS25H registers.
enum LPS25HRegAddr
{
    LPS25H_REF_P_XL       = 0x08,
    LPS25H_REF_P_L        = 0x09,
    LPS25H_REF_P_H        = 0x0A,
    LPS25H_WHO_AM_I       = 0x0F,
    LPS25H_RES_CONF       = 0x10,
    LPS25H_CTRL_REG1      = 0x20,
    LPS25H_CTRL_REG2      = 0x21,
    LPS25H_CTRL_REG3      = 0x22,
    LPS25H_CTRL_REG4      = 0x23,
    LPS25H_INTERRUPT_CFG  = 0x24,
    LPS25H_INT_SOURCE     = 0x25,
    LPS25H_STATUS_REG     = 0x27,
    LPS25H_PRESS_OUT_XL   = 0x28,
    LPS25H_PRESS_OUT_L    = 0x29,
    LPS25H_PRESS_OUT_H    = 0x2A,
    LPS25H_TEMP_OUT_L     = 0x2B,
    LPS25H_TEMP_OUT_H     = 0x2C,
    LPS25H_FIFO_CTRL      = 0x2E,
    LPS25H_FIFO_STATUS    = 0x2F,
    LPS25H_THS_P_L        = 0x30,
    LPS25H_THS_P_H        = 0x31,
    LPS25H_RPDS_L         = 0x39,
    LPS25H_RPDS_H         = 0x3A
};

// Represents a single LPS25H device.
typedef struct LPS25H {
    enum LPS25HDeviceType device;
    uint8_t address;

    // Functions that perform I2C transfers will modify this variable to
    // indicate whether they succeeded.  0 means success, non-zero indicates an
    // error.
    uint8_t lastResult;

    // Raw pressure reading.
    int24_t p;
} LPS25H;

// Initializes the library and confirms that we can communicate with the device.
// Returns 1 for success and 0 for failure.
uint8_t lps25hInit(LPS25H *, enum LPS25HDeviceType, enum LPS25HSA0State);

// Enables the pressure sensor and sets the ODR (output data rate) to 12.5 Hz.
//
// Note that this function will also reset other settings controlled by the
// registers it writes to.
void lps25hEnableDefault(LPS25H *);

// Writes to one of the LPS25H registers.  The "reg" argument should be the
// register address and the "value" argument should be the value to write.
void lps25hWriteReg(LPS25H *, uint8_t reg, uint8_t value);

// Reads from an LPS25H register and returns the value.  The "reg" argument
// should be the register address.
uint8_t lps25hReadReg(LPS25H *, uint8_t reg);

// Reads from the pressure sensor and stores the results in the "p" member of the
// LPS25H object.
void lps25hReadPressure(LPS25H *);

#endif
