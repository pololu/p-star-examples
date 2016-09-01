#ifndef _UART_H
#define _UART_H

#include <stdint.h>

void uartInit(void);
void uartSetBaudRate(uint24_t);
void uartIsr(void);

uint8_t uartRxAvailable(void);
uint8_t uartRxReceiveByte(void);

uint8_t uartTxAvailable(void);
void uartTxSendByte(uint8_t);

#endif
