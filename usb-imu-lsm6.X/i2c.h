// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This is the header file for i2c.c, a library for using the PIC18F25K50's
// Master Synchronous Serial Port (MSSP) in I2C Master mode to communicate with
// I2C devices.

#ifndef _I2C_H
#define _I2C_H

#include <stdint.h>

// This should be called at the beginning of the program.
void i2cInit();

// Generates an I2C Start condition.  This function can fail if there is a bus
// collision (see I2C_COLLISION()).
void i2cStart();

// Generates an I2C Repeated Start condition.  This function could cause an
// infinite loop if there is something forcing the SCL line high or low.
// This function can fail if there is a bus collision (see I2C_COLLISION()).
void i2cRepeatedStart();

// Generates an I2C Stop condition.  This function could cause an infinite loop
// if there is something forcing the SDA line high or low.
void i2cStop();

// Writes a byte to the I2C slave.  Use I2C_ACKED() if you want to know whether
// the slave acknowledged the byte or not.  This function could cause an
// infinite loop if there is something forcing the SCL line low.  This function
// can fail if there is a bus collision (see I2C_COLLISION()).
void i2cWriteByte(uint8_t b);

// Reads a byte from the I2C slave.  If the ack argument is 0, it does not
// acknowledge the byte (meaning this is the last byte to be read).  If the ack
// argument is 1, it acknowledges the byte.  This function could cause an
// infinite loop if there is something forcing the SCL line low.
uint8_t i2cReadByte(uint8_t ack);

// This function returns 1 if there was an I2C bus collision and 0 if there was
// not.  If you want to detect errors, call this after any function that can
// fail because of a bus collision.
#define I2C_COLLISION() (BCLIF)

// This function is meant to be called after i2cWriteByte and it returns 1 if
// an acknowledgment was received from the slave for the byte written.
#define I2C_ACKED() (!ACKSTAT)

#endif
