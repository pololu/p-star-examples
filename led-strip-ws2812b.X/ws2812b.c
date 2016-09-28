// Copyright Pololu Corporation.  For more information, see https://www.pololu.com/

// See ws2812b.h for more information about this file.

#include <xc.h>
#include "system.h"
#include "ws2812b.h"
#include "ws2812b_config.h"

#if _XTAL_FREQ != 48000000
#error This code assumes that the PIC is running at 48 MHz.
#endif

void ws2812b_write(rgb_color * colors, uint16_t count)
{
    // Disable interrupts because the signal we are sending needs to be
    // sent with precise timing.
    GIE = 0;

#asm
    // Set the pin to be an output.
    bcf WS2812B_DATA_TRIS, WS2812B_DATA_BIT, c

    // Load our colors pointer into FSR0 so we can access color data using
    // registers like POSTINC0.  Here we assume that the pointer points to
    // RAM and not flash.
    movff ws2812b_write@colors + 0, FSR0L
    movff ws2812b_write@colors + 1, FSR0H

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
    movf PREINC0, w, c       // Advance the pointer to green and read it.
    rcall ws2812b_send_byte  // Send the green component.
    movf POSTDEC0, w, c      // Move the pointer back to red.
    movf POSTINC0, w, c      // Read red and advance the pointer to green.
    rcall ws2812b_send_byte  // Send the red component.
    movf POSTINC0, w, c      // Advance the pointer to blue.
    movf POSTINC0, w, c      // Read blue and advance pointer to the next red.
    rcall ws2812b_send_byte  // Send the blue component.

    // Subtracts 1 from the count.  If the count is 0, stops sending colors.
ws2812b_outer_loop_test:
    decf ws2812b_write@count + 0, f, b
    btfss STATUS, _STATUS_C_POSN, c
    decf ws2812b_write@count + 1, f, b
    btfsc STATUS, _STATUS_C_POSN, c
    bra ws28128b_outer_loop_top
#endasm

    // Re-enable interrupts.  The assumption here is that this function
    // is not called in an ISR, and that we generally want interrupts
    // to be enabled, so it is OK to re-enable them here in order to
    // undo the change we made earlier.
    GIE = 1;

    // Delay for 80 us so the LED strip receives a reset signal.
    __delay_us(80);
}


