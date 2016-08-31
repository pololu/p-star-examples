/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license),
please contact mla_licensing@microchip.com
*******************************************************************************/

#include "usb.h"
#include "usb_device_cdc.h"

// Device Descriptor
const USB_DEVICE_DESCRIPTOR device_dsc =
{
    0x12,                   // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE,  // DEVICE descriptor type
    0x0200,                 // USB Spec Release Number in BCD format
    CDC_DEVICE,             // Class Code
    0x00,                   // Subclass code
    0x00,                   // Protocol code
    USB_EP0_BUFF_SIZE,      // Max packet size for EP0, see usb_config.h
    0x04D8,                 // Vendor ID
    0x000A,                 // Product ID: CDC RS-232 Emulation Demo
    0x0100,                 // Device release number in BCD format
    0x01,                   // Manufacturer string index
    0x02,                   // Product string index
    0x03,                   // Device serial number string index
    0x01                    // Number of possible configurations
};

const uint8_t configDescriptor1[67] =
{
    // Configuration descriptor
    sizeof(USB_CONFIGURATION_DESCRIPTOR),
    USB_DESCRIPTOR_CONFIGURATION,
    sizeof(configDescriptor1),0,
    2,                      // Number of interfaces in this cfg
    1,                      // Index value of this configuration
    0,                      // Configuration string index
    _DEFAULT | _SELF,       // Attributes, see usb_device.h
    50,                     // Max power consumption (2X mA)

    // CDC Interface Descriptor
    sizeof(USB_INTERFACE_DESCRIPTOR),
    USB_DESCRIPTOR_INTERFACE,
    0,                      // Interface Number
    0,                      // Alternate Setting Number
    1,                      // Number of endpoints in this intf
    COMM_INTF,              // Class code
    ABSTRACT_CONTROL_MODEL, // Subclass code
    V25TER,                 // Protocol code
    0,                      // Interface string index

    // CDC Class-Specific Descriptors
    sizeof(USB_CDC_HEADER_FN_DSC),
    CS_INTERFACE,
    DSC_FN_HEADER,
    0x10,0x01,

    sizeof(USB_CDC_ACM_FN_DSC),
    CS_INTERFACE,
    DSC_FN_ACM,
    USB_CDC_ACM_FN_DSC_VAL,

    sizeof(USB_CDC_UNION_FN_DSC),
    CS_INTERFACE,
    DSC_FN_UNION,
    CDC_COMM_INTF_ID,
    CDC_DATA_INTF_ID,

    sizeof(USB_CDC_CALL_MGT_FN_DSC),
    CS_INTERFACE,
    DSC_FN_CALL_MGT,
    0x00,
    CDC_DATA_INTF_ID,

    // CDC Notification Endpoint Descriptor
    sizeof(USB_ENDPOINT_DESCRIPTOR),
    USB_DESCRIPTOR_ENDPOINT,
    CDC_COMM_EP | _EP_IN,       // EndpointAddress
    _INTERRUPT,                 // Attributes
    0x08,0x00,                  // Endpoint size
    0x02,                       // Interval

    // CDC Data Interface Descriptor
    sizeof(USB_INTERFACE_DESCRIPTOR),
    // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,   // INTERFACE descriptor type
    1,                      // Interface Number
    0,                      // Alternate Setting Number
    2,                      // Number of endpoints in this intf
    DATA_INTF,              // Class code
    0,                      // Subclass code
    NO_PROTOCOL,            // Protocol code
    0,                      // Interface string index

    // CDC Data OUT Endpoint Descriptor
    sizeof(USB_ENDPOINT_DESCRIPTOR),
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    CDC_DATA_EP | _EP_OUT,      // EndpointAddress
    _BULK,                      // Attributes
    0x40,0x00,                  // Packet size
    0x00,                       // Interval

    // CDC Data IN Endpoint Descriptor
    sizeof(USB_ENDPOINT_DESCRIPTOR),
    USB_DESCRIPTOR_ENDPOINT,    // Endpoint Descriptor
    CDC_DATA_EP | _EP_IN,       // EndpointAddress
    _BULK,                      // Attributes
    0x40,0x00,                  // Packet size
    0x00,                       // Interval
};

// Language code string descriptor
const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[1];}sd000={
sizeof(sd000),USB_DESCRIPTOR_STRING,{0x0409}};

// Manufacturer string descriptor
const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[25];}sd001={
sizeof(sd001),USB_DESCRIPTOR_STRING,
{'M','i','c','r','o','c','h','i','p',' ',
'T','e','c','h','n','o','l','o','g','y',' ','I','n','c','.'
}};

// Product string descriptor
const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[25];}sd002={
sizeof(sd002),USB_DESCRIPTOR_STRING,
{'C','D','C',' ','R','S','-','2','3','2',' ',
'E','m','u','l','a','t','i','o','n',' ','D','e','m','o'}
};

const uint8_t * const USB_CD_Ptr[]=
{
    configDescriptor1
};

// Array of string descriptors
const uint8_t * const USB_SD_Ptr[USB_NUM_STRING_DESCRIPTORS]=
{
    (const uint8_t * const)&sd000,
    (const uint8_t * const)&sd001,
    (const uint8_t * const)&sd002,
    (const uint8_t * const)0x80,   // Serial number from the P-Star bootloader
};
