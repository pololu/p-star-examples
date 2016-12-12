// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This is the header file for i2c.c, a library for using the PIC18F25K50's
// Master Synchronous Serial Port (MSSP) in I2C Master mode to communicate with
// I2C devices.

#ifndef _I2C_H
#define _I2C_H

#include <stdint.h>

// This should be called at the beginning of the program.
void i2cInit(void);

// This struct represents a one-way transfer of data to or from an I2C device.
typedef struct I2CTransfer {
  uint8_t address;
  uint8_t flags;
  uint8_t * buffer;
  uint8_t length;
} I2CTransfer;

// The flags field should be a bitwise combination of a subset of these flags:
#define I2C_FLAG_READ  0x01
#define I2C_FLAG_STOP  0x02

// Performs a series of transfers to I2C devices.
//
// The argument should point to an array of transfers where the last transfer is
// indicated with I2C_FLAG_STOP in its flags field.
//
// The return value will be one of these:
// - 0: success
// - 1:  Error occurred on the first start.
// - 4 + N*4 + 0: Error with transfer N: Repeated start for transfer failed.
// - 4 + N*4 + 1: Error with transfer N: Device did not ACK its address.
// - 4 + N*4 + 2: Error with transfer N: Device did not ACK data written.
//
// Because of the way errors are encoded, you should not do more than
// 63 transfers with this function.
//
// If there are multiple transfers, this function uses I2C
// repeated starts between the transfers.  This function could cause an
// infinite loop if there is something wrong with the I2C bus or the devices on it.
uint8_t i2cPerformTransfers(const I2CTransfer * transfers);

#endif
