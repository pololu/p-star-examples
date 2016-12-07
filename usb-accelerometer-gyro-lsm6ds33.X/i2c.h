// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This is the header file for i2c.c, a library for using the PIC18F25K50's
// Master Synchronous Serial Port (MSSP) in I2C Master mode to communicate with
// I2C devices.

#ifndef _I2C_H
#define _I2C_H

#include <stdint.h>

// This should be called at the beginning of the program.
void i2cInit();

// Initiates an I2C Start condition.  If the SDA and SCL lines are not sampled
// high for some period of time during this function call, that is called a
// bus collision and this function will fail.  You can check for this failure
// using I2C_COLLISION().
void i2cStart();

// Initiates and I2C Repeated Start condition.  This could cause an infinite
// loop or silently fail.
void i2cRepeatedStart();
void i2cStop();

// Use I2C_ACKED() if you want to know whether the slave acknowledged or not.
void i2cWriteByte(uint8_t b);

uint8_t i2cReadByte(uint8_t ack);

#define I2C_COLLISION() (BCLIF)
#define I2C_ACKED() (!ACKSTAT)


#endif
