// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

#include <xc.h>
#include "system.h"
#include "ws2812b.h"
#include "ws2812b_config.h"

#if _XTAL_FREQ != 48000000
#error This code assumes that the PIC is running at 48 MHz.
#endif

void ws2812b_write(rgb_color * colors, uint16_t count)
{
    TRISB1 = 0;
    GIE = 0;
    FSR0 = (uint16_t)colors;
#asm
    movlb (ws2812b_write@count >> 8)
            
    bra ws2812b_outer_loop_test

ws2812b_send_byte:
    rcall ws2812b_send_bit
    rcall ws2812b_send_bit
    rcall ws2812b_send_bit
    rcall ws2812b_send_bit
    rcall ws2812b_send_bit
    rcall ws2812b_send_bit
    rcall ws2812b_send_bit
    rcall ws2812b_send_bit
    return

    // Pulse for "0" is 4/(12 MHz) = 0.33 us
    // Pulse for "1" is 10/(12 MHz) = 0.83 us
    // Shortest period is 15/(12 MHz) = 1.25 us
ws2812b_send_bit:
    bsf WS2812B_DATA_LAT, WS2812B_DATA_BIT, c
    nop
    nop
    btfss WREG, 7
    bcf WS2812B_DATA_LAT, WS2812B_DATA_BIT, c     
    nop
    nop
    nop
    nop
    rlcf WREG, f, c
    bcf WS2812B_DATA_LAT, WS2812B_DATA_BIT, c
    return

ws28128b_outer_loop_top:
    movf PREINC0, w, c   // Advance the pointer to green and read it.
    rcall ws2812b_send_byte
    movf POSTDEC0, w, c  // Move the pointer back to red.
    movf POSTINC0, w, c  // Read red and advance the pointer to green.
    rcall ws2812b_send_byte
    movf POSTINC0, w, c   // Advance the pointer to blue.
    movf POSTINC0, w, c   // Read blue and advance pointer to the next red.
    rcall ws2812b_send_byte
ws2812b_outer_loop_test:
    decf ws2812b_write@count, f, b
    btfss STATUS, _STATUS_C_POSN, c
    decf ws2812b_write@count + 1, f, b
    btfsc STATUS, _STATUS_C_POSN, c
    bra ws28128b_outer_loop_top
#endasm
    GIE = 1;
}


