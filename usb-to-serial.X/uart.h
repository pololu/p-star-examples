// These functions provide a simple way to send and receive asynchronous serial
// bytes on the EUSART (UART) on the PIC18F25K50.
//
// The TX line (RC6) is set up as an output, and the RX line (RC7) is set up
// as an input.
//
// Note that the RX line does not have a built-in pull-up resistor,
// so we recommend connecting a 10k resistor between RX and VDD to ensure that
// you do not receive invalid characters when the RX line is disconnected.
//
// Note that on the P-Star 25K50, the TX line controls the red LED, so the
// normal methods for controlling the red LED will not work, and you will see
// the red LED blink when transmitting bytes on the TX line.
//
// Bytes are received and sent using a high-priority interrupt, but the
// priority can be changed.

#ifndef _UART_H
#define _UART_H

#include <stdint.h>

// This should be called before you use any of the other functions here.
// It sets up the UART interrupts and sets their priority to be high, but it
// does not set the global interrupt enable bit (GIEH).  If you want to use
// a low-priority interrupt for the ISR, then set the TXIP and RCIP bits to 0
// after calling uartInit but before setting GIEH to 1.
void uartInit(void);

// Sets the baud rate of the UART (in bits per second).
void uartSetBaudRate(uint24_t);

// You should call this function in your application's high-priority interrupt
// service routine (ISR) to handle sending and receiving bytes on the UART.
// Alternatively, you could call it in the low-priority ISR as described in the
// comments for uartInit.
void uartIsr(void);

// Returns the number of bytes from the RX line available for immediate reading.
uint8_t uartRxAvailable(void);

// Reads one byte from the UART without blocking.  You MUST call uartRxAvailable
// to make sure bytes are available first, or else this function could
// return invalid data and cause data to be lost.
uint8_t uartRxReceiveByte(void);

// Returns the amount of free buffer space available for sending data on the TX
// line.
uint8_t uartTxAvailable(void);

// Queues one byte to be sent on the TX line.  You MUST call uartTxAvailable to
// make sure there is buffer space available first, or else this function could
// cause bytes queued for the TX line to be lost or corrupted.
void uartTxSendByte(uint8_t);

#endif
