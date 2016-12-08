// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This is a library for using the PIC18F25K50's Master Synchronous
// Serial Port (MSSP) in I2C Master mode to communicate with I2C
// devices.

// TODO: allow setting the speed

#include "i2c.h"
#include "system.h"
#include <xc.h>

void i2cInit()
{
    // Set up the SCL and SDA pins as pulled-up inputs.
#if defined(__18F25K50) || defined(__18F45K50)
    // Note: This could have a side effect of enabling pull-ups on other pins on
    // Port B.  If you want to avoid that, set the WPUB register to 0 before
    // calling this.
    ANSB0 = 0;
    ANSB1 = 0;
    WPUB0 = 1;
    WPUB1 = 1;
    RBPU = 0;
#endif

    // SMP = 0: Slew rate control enabled.
    // CKE = 1: Enable input logic so that thresholds are compliant with SMBus.
    //   Looks like this means the input high voltage will be 2.1 V instead
    //   of 0.7 VDD = 3.5 V, so that's nice.  Also makes the input low voltage
    //   be 0.8 V instead of 0.3 VDD, according to the PIC18F25K50 datasheet.
    // The other 6 bits are read-only.
    SSP1STAT = 0b01000000;

    // Reset other MSSP registers to their default values.
    SSP1CON2 = 0;
    SSP1CON3 = 0;

    // Set the I2C frequency to 100 kHz.
#if _XTAL_FREQ == 48000000
    SSP1ADD = 119;
#else
#error Not sure how to handle this _XTAL_FREQ.
#endif

    // Set up I2C master mode, with clock = FOSC / 4 / (SSP1ADD+1).
    SSP1CON1 = 0b00101000;
}

// Generates an I2C Start condition.  This function can fail if there is a bus
// collision (see I2C_COLLISION()).
static void i2cStart()
{
    BCLIF = 0;
    SEN = 1;
    while (SEN);
}

// Generates an I2C Repeated Start condition.  This function could cause an
// infinite loop if there is something forcing the SCL line high or low.
// This function can fail if there is a bus collision (see I2C_COLLISION()).
static void i2cRepeatedStart()
{
    RSEN = 1;
    while (RSEN);
}

// Generates an I2C Stop condition.  This function could cause an infinite loop
// if there is something forcing the SDA line high or low.
void i2cStop()
{
    PEN = 1;
    while (PEN);
}

// Writes a byte to the I2C slave.  Use I2C_ACKED() if you want to know whether
// the slave acknowledged the byte or not.  This function could cause an
// infinite loop if there is something forcing the SCL line low.  This function
// can fail if there is a bus collision (see I2C_COLLISION()).
void i2cWriteByte(uint8_t b)
{
    SSPIF = 0;
    SSP1BUF = b;
    while (!SSPIF);
}

// Reads a byte from the I2C slave.  If the ack argument is 0, it does not
// acknowledge the byte (meaning this is the last byte to be read).  If the ack
// argument is 1, it acknowledges the byte.  This function could cause an
// infinite loop if there is something forcing the SCL line low.
uint8_t i2cReadByte(uint8_t ack)
{
    SSPIF = 0;
    RCEN = 1;
    while (!SSPIF);
    uint8_t r = SSP1BUF;
    ACKDT = !ack;
    ACKEN = 1;
    while (ACKEN);
    return r;
}

// Returns 1 if there was an I2C bus collision and 0 if there was not.
#define I2C_COLLISION() (BCLIF)

// This is meant to be called after i2cWriteByte and it returns 1 if
// an acknowledgment was received from the slave for the byte written.
#define I2C_ACKED() (!ACKSTAT)

uint8_t i2cPerformTransfers(const I2CTransfer * transfer)
{
    i2cStart();
    if (I2C_COLLISION())
    {
        return 1;  // tmphax error code
    }

    while (1)
    {
        if (transfer->flags & I2C_FLAG_READ)
        {
            i2cWriteByte((transfer->address << 1) | 1);
            if (!I2C_ACKED())
            {
                i2cStop();
                return 2;  // tmphax error code
            }

            for (uint8_t i = 0; i < transfer->length; i++)
            {
                uint8_t ack = i < transfer->length - 1;
                transfer->buffer[i] = i2cReadByte(ack);
            }
        }
        else
        {
            i2cWriteByte(transfer->address << 1);
            if (!I2C_ACKED())
            {
                i2cStop();
                return 4;  // tmphax error code
            }

            for (uint8_t i = 0; i < transfer->length; i++)
            {
                i2cWriteByte(transfer->buffer[i]);
                if (!I2C_ACKED())
                {
                    i2cStop();
                    return 5;  // tmphax error code
                }
            }
        }

        if (transfer->flags & I2C_FLAG_STOP) { break; }
        transfer++;

        i2cRepeatedStart();

        if (I2C_COLLISION())
        {
            return 6;  // tmphax error code
        }
    }

    i2cStop();
    return 0;
}
