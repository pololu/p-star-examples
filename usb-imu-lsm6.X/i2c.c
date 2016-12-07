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

void i2cStart()
{
    BCLIF = 0;
    SEN = 1;
    while (SEN);
}

void i2cRepeatedStart()
{
    RSEN = 1;
    while (RSEN);
}

void i2cStop()
{
    PEN = 1;
    while (PEN);
}

void i2cWriteByte(uint8_t b)
{
    SSPIF = 0;
    SSP1BUF = b;
    while (!SSPIF);
}

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