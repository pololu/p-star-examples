// This file sets the options needed for a single USB CDC ACM virtual serial
// port.
//
// The definitions in this file are used by the Microchip USB Stack.
// For more information, see the Microchip Libraries for Applications, which
// can be downloaded from Microchip's website.

#define USB_SUPPORT_DEVICE
#define USB_INTERRUPT
#define USB_SPEED_OPTION              USB_FULL_SPEED
#define USB_PING_PONG_MODE            USB_PING_PONG__FULL_PING_PONG
#define USB_TRANSCEIVER_OPTION        USB_INTERNAL_TRANSCEIVER
#define USB_PULLUP_OPTION             USB_PULLUP_ENABLE
#define USB_EP0_BUFF_SIZE             8
#define USB_MAX_NUM_INT               2
#define USB_MAX_EP_NUMBER             2
#define USB_NUM_STRING_DESCRIPTORS    4

#define USB_USE_CDC
#define CDC_COMM_INTF_ID              0
#define CDC_DATA_INTF_ID              1
#define CDC_COMM_EP                   1
#define CDC_DATA_EP                   2
#define CDC_COMM_IN_EP_SIZE           10
#define CDC_DATA_OUT_EP_SIZE          64
#define CDC_DATA_IN_EP_SIZE           64
#define USB_CDC_SUPPORT_ABSTRACT_CONTROL_MANAGEMENT_CAPABILITIES_D1
#define USB_CDC_SET_LINE_CODING_HANDLER cdcSetLineCodingHandler

#define FIXED_ADDRESS_MEMORY
#define IN_DATA_BUFFER_ADDRESS_TAG    @0x440
#define OUT_DATA_BUFFER_ADDRESS_TAG   @0x480
