// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This is the header file for i2c.c, a library for using the PIC18F25K50's
// Master Synchronous Serial Port (MSSP) in I2C Master mode to communicate with
// I2C devices.

#ifndef _I2C_H
#define _I2C_H

#include <stdint.h>

void i2cInit();
void i2cStart();
void i2cRepeatedStart();
void i2cStop();
void i2cWriteByte(uint8_t b);
uint8_t i2cReadByte(uint8_t ack);


#endif
