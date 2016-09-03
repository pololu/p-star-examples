// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// Abstraction layer for the UART.
//
// Note: The PIC18F25K50 does not have an internal pull-up resistor for RX
// (RC7), so you should add an external one.

#include "uart.h"
#include <xc.h>

#if defined(__18F25K50) || defined(__18F45K50)
extern volatile uint16_t SPBRG16 @ 0xFAF;
#endif

volatile uint8_t uartRxBuffer[64];
volatile uint8_t uartRxBufferMainLoopIndex = 0;
volatile uint8_t uartRxBufferInterruptIndex = 0;

volatile uint8_t uartTxBuffer[64];
volatile uint8_t uartTxBufferMainLoopIndex = 0;
volatile uint8_t uartTxBufferInterruptIndex = 0;

void uartInit()
{
    // The PIC18F25K50 datasheet says the TRIS bits should be 1 for both
    // RX and TX.
    TRISC6 = 1;
    TRISC7 = 1;

    // Enable the digital input driver for RX.
    ANSC7 = 0;

    uartSetBaudRate(9600);

    // BRG16 = 1 : 16-bit baud rate generator
    BAUDCON = 0b00001000;

    // Enable transmitter and set BRGH (High Baud Rate Select Bit) to 1.
    TXSTA =  0b00100100;

    // Enable the serial port in general and the receiver.
    RCSTA = 0b10010000;

    // Set the interrupt priority.
    TXIP = 1;
    RCIP = 1;

    // Enable the reception interrupt.
    RCIE = 1;
}

void uartSetBaudRate(uint24_t baud)
{
    if (baud == 0)
    {
        // Avoid dividing by zero because we are not sure what would happen.
        return;
    }

    SPBRG16 = ((((uint24_t)(_XTAL_FREQ / 4)) - (baud >> 1))) / baud;
}

void uartIsr()
{
    // Receive bytes.
    if (RCIE && RCIF)
    {
        // A byte has been received on RX.
        // To clear RCIF, we must read RCREG exactly once.

        if (FERR)
        {
            // A framing error occurred.  Don't store the received byte.
            RCREG;
        }
        else if (uartRxBufferMainLoopIndex ==
            ((uartRxBufferInterruptIndex + 1) & (sizeof(uartRxBuffer) - 1)))
        {
            // A software receive overrun occurred.
            RCREG;
        }
        else
        {
            uartRxBuffer[uartRxBufferInterruptIndex] = RCREG;
            uartRxBufferInterruptIndex =
                (uartRxBufferInterruptIndex + 1) & (sizeof(uartRxBuffer) - 1);
        }

        // If all the bytes have been read, handle overrun errors.
        if (OERR && !RCIF)
        {
            CREN = 0;
            CREN = 1;
        }
    }

    // Transmit bytes.
    if (TXIE && TXIF)
    {
        if (uartTxBufferInterruptIndex == uartTxBufferMainLoopIndex)
        {
            // The txBuffer is empty now, so disable the transmission
            // interrupt.  It will be re-enabled the next time we need to
            // send some bytes.
            TXIE = 0;
        }
        else
        {
            // Transmit a byte from the txBuffer and increment the index.
            TXREG = uartTxBuffer[uartTxBufferInterruptIndex];
            uartTxBufferInterruptIndex =
                (uartTxBufferInterruptIndex + 1) & (sizeof(uartTxBuffer) - 1);
        }
    }
}

uint8_t uartRxAvailable()
{
    return (uartRxBufferInterruptIndex - uartRxBufferMainLoopIndex)
        & (sizeof(uartRxBuffer) - 1);
}

uint8_t uartRxReceiveByte()
{
    uint8_t byte = uartRxBuffer[uartRxBufferMainLoopIndex];
    uartRxBufferMainLoopIndex =
        (uartRxBufferMainLoopIndex + 1) & (sizeof(uartRxBuffer) - 1);
    return byte;
}

uint8_t uartTxAvailable()
{
    return (uartTxBufferInterruptIndex - uartTxBufferMainLoopIndex - 1)
        & (sizeof(uartTxBuffer) - 1);
}

void uartTxSendByte(uint8_t byte)
{
    uartTxBuffer[uartTxBufferMainLoopIndex] = byte;
    uartTxBufferMainLoopIndex =
        (uartTxBufferMainLoopIndex + 1) & (sizeof(uartTxBuffer) - 1);

    TXIE = 1;
}
