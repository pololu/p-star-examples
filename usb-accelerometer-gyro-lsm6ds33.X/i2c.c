// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// This is a library for using the PIC18F25K50's Master Synchronous
// Serial Port (MSSP) in I2C Master mode to communicate with I2C
// devices.

#include "i2c.h"
#include "system.h"
#include <xc.h>

void i2cInit()
{
    // Allow digitial input on the SCL and SDA pins.
#if defined(__18F25K50) || defined(__18F45K50)
    ANSB0 = 0;
    ANSB1 = 0;
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
    SSPIF = 0;
    ACKDT = !ack;
    ACKEN = 1;
    while (!SSPIF);
    uint8_t r = SSP1BUF;
    if (BF) { __delay_us(100); }
    return r;
}