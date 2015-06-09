/*
	HHKPS2USBDriver
	Keyboard driver for Happy Hacking Keyboard with PS/2-USB Converter
	
	Copyright (C) 2005 NAKAHASHI Ichiro
*/

#ifndef HHKPS2USBDRIVER_H
#define HHKPS2USBDRIVER_H

#include <IOKit/usb/IOUSBHIDDriver.h>

class HHKPS2USBDriver : public IOUSBHIDDriver
{
    OSDeclareDefaultStructors(HHKPS2USBDriver)

public:
    //virtual bool start(IOService * provider);
	
	virtual IOReturn handleReportWithTime(
			AbsoluteTime         timeStamp,
			IOMemoryDescriptor * report,
			IOHIDReportType      reportType = kIOHIDReportTypeInput,
			IOOptionBits         options    = 0);

// I do not think this class becomes superclass someday...
#if 0	
public:
	OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  0);
	OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  1);
    OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  2);
    OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  3);
    OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  4);
    OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  5);
    OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  6);
    OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  7);
    OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  8);
    OSMetaClassDeclareReservedUnused(HHKPS2USBDriver,  9);
#endif
};

#endif // HHKPS2USBDRIVER_H
