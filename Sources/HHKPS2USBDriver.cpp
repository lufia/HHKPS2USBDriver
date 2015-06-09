/*
	HHKPS2USBDriver
	Keyboard driver for Happy Hacking Keyboard with PS/2-USB Converter
	
	Copyright (C) 2005 NAKAHASHI Ichiro
*/

#include <IOKit/usb/IOUSBLog.h>
#include "HHKPS2USBDriver.h"

#define super IOUSBHIDDriver

OSDefineMetaClassAndStructors(HHKPS2USBDriver, IOUSBHIDDriver)


#pragma mark ････････ IOHIDSystem Methods ･････････

#if 0  // disabled
bool
HHKPS2USBDriver::start(IOService *provider)
{
	USBLog(5, "%s::start()", getName());
	if (!super::start(provider)) return false;
	
	// This saves some USB bandwidth and CPU time?  I'm not sure.
	SetIdleMillisecs(0);

	return true;
}
#endif

IOReturn
HHKPS2USBDriver::handleReportWithTime(
		AbsoluteTime         timeStamp,
		IOMemoryDescriptor * report,
		IOHIDReportType      reportType,
		IOOptionBits         options)
{
	static unsigned char buf[8];
	int i;
	
	if (reportType != kIOHIDReportTypeInput) goto do_super;

	if (report->getLength() != 8) {
		USBLog(3, "%s: Report length is not 8 bytes. I can't handle it.",
				getName());
		goto do_super;
	}
	
	report->readBytes(0, buf, 8);
	
	/*
	// I assume that the HID report data has the following structure:
	//                         Flgs ???? Array of key pressed_________
	USBLog(5, "%s: HID report: %02X %02X %02X %02X %02X %02X %02X %02X",
			getName(), 
			buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
	*/
	for (i = 2; i < 8; i++) {
		switch (buf[i]) {
		case 0x8B: // Muhenkan == Left Meta
			buf[i] = 0x00;
			buf[0] |= 0x08;  // Left Command
			break;
		case 0x8A: // Henkan == Right Meta
			buf[i] = 0x00;
			buf[0] |= 0x80;  // Right Command
			break;
		}
	}
	
	report->writeBytes(0, buf, 8);

do_super:
	return super::handleReportWithTime(
			timeStamp, report, reportType, options);
}


#pragma mark ････････ Padding Methods ･････････

// I do not think this class becomes superclass someday...
#if 0
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  0);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  1);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  2);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  3);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  4);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  5);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  6);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  7);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  8);
OSMetaClassDefineReservedUnused(HHKPS2USBDriver,  9);
#endif
