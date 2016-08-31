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

/** INCLUDES *******************************************************/
#include "usb.h"
#include "usb_device_cdc.h"

/** CONSTANTS ******************************************************/
#if defined(__18CXX)
#pragma romdata
#endif

/* Device Descriptor */
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
    0x00,                   // Device serial number string index
    0x01                    // Number of possible configurations
};

/* Configuration 1 Descriptor */
const uint8_t configDescriptor1[]={
    /* Configuration Descriptor */
    0x09,//sizeof(USB_CFG_DSC),    // Size of this descriptor in bytes
    USB_DESCRIPTOR_CONFIGURATION,                // CONFIGURATION descriptor type
    67,0,                   // Total length of data for this cfg
    2,                      // Number of interfaces in this cfg
    1,                      // Index value of this configuration
    0,                      // Configuration string index
    _DEFAULT | _SELF,               // Attributes, see usb_device.h
    50,                     // Max power consumption (2X mA)

    /* Interface Descriptor */
    9,//sizeof(USB_INTF_DSC),   // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,               // INTERFACE descriptor type
    0,                      // Interface Number
    0,                      // Alternate Setting Number
    1,                      // Number of endpoints in this intf
    COMM_INTF,              // Class code
    ABSTRACT_CONTROL_MODEL, // Subclass code
    V25TER,                 // Protocol code
    0,                      // Interface string index

    /* CDC Class-Specific Descriptors */
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

    /* Endpoint Descriptor */
    //sizeof(USB_EP_DSC),DSC_EP,_EP02_IN,_INT,CDC_INT_EP_SIZE,0x02,
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT,    //Endpoint Descriptor
    _EP01_IN,            //EndpointAddress
    _INTERRUPT,                       //Attributes
    0x08,0x00,                  //size
    0x02,                       //Interval

    /* Interface Descriptor */
    9,//sizeof(USB_INTF_DSC),   // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE,               // INTERFACE descriptor type
    1,                      // Interface Number
    0,                      // Alternate Setting Number
    2,                      // Number of endpoints in this intf
    DATA_INTF,              // Class code
    0,                      // Subclass code
    NO_PROTOCOL,            // Protocol code
    0,                      // Interface string index

    /* Endpoint Descriptor */
    //sizeof(USB_EP_DSC),DSC_EP,_EP03_OUT,_BULK,CDC_BULK_OUT_EP_SIZE,0x00,
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT,    //Endpoint Descriptor
    _EP02_OUT,            //EndpointAddress
    _BULK,                       //Attributes
    0x40,0x00,                  //size
    0x00,                       //Interval

    /* Endpoint Descriptor */
    //sizeof(USB_EP_DSC),DSC_EP,_EP03_IN,_BULK,CDC_BULK_IN_EP_SIZE,0x00
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT,    //Endpoint Descriptor
    _EP02_IN,            //EndpointAddress
    _BULK,                       //Attributes
    0x40,0x00,                  //size
    0x00,                       //Interval
};


//Language code string descriptor
const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[1];}sd000={
sizeof(sd000),USB_DESCRIPTOR_STRING,{0x0409}};

//Manufacturer string descriptor
const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[25];}sd001={
sizeof(sd001),USB_DESCRIPTOR_STRING,
{'M','i','c','r','o','c','h','i','p',' ',
'T','e','c','h','n','o','l','o','g','y',' ','I','n','c','.'
}};

//Product string descriptor
const struct{uint8_t bLength;uint8_t bDscType;uint16_t string[25];}sd002={
sizeof(sd002),USB_DESCRIPTOR_STRING,
{'C','D','C',' ','R','S','-','2','3','2',' ',
'E','m','u','l','a','t','i','o','n',' ','D','e','m','o'}
};

//Serial number string descriptor.  If a serial number string is implemented,
//it should be unique for every single device coming off the production assembly
//line.  Plugging two devices with the same serial number into a computer
//simultaneously will cause problems (in extreme cases BSOD).
//Note: Common OSes put restrictions on the possible values that are allowed.
//For best OS compatibility, the serial number string should only consist
//of UNICODE encoded numbers 0 through 9 and capital letters A through F.
//ROM struct{BYTE bLength;BYTE bDscType;WORD string[10];}sd003={
//sizeof(sd003),USB_DESCRIPTOR_STRING,
//{'0','1','2','3','4','5','6','7','8','9'}};

//Array of configuration descriptors
const uint8_t * const USB_CD_Ptr[]=
{
    (const uint8_t * const)configDescriptor1
};

//Array of string descriptors
const uint8_t * const USB_SD_Ptr[USB_NUM_STRING_DESCRIPTORS]=
{
    (const uint8_t * const)&sd000,
    (const uint8_t * const)&sd001,
    (const uint8_t * const)&sd002
};
