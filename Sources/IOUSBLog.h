//
//  IOUSBLog.h
//  HHKPS2USBDriver
//
//  Created by Kyohei Kadota on 2018/12/20.
//

#ifndef IOUSBLog_h
#define IOUSBLog_h

#include <IOKit/IOService.h>
#include <IOKit/IOLib.h>

#define DEBUG_LEVEL_PRODUCTION  0
#define DEBUG_LEVEL_DEVELOPMENT 1
#define DEBUG_LEVEL_ALPHA       2
#define DEBUG_LEVEL_BETA        3
#define DEBUG_LEVEL_FINAL       DEBUG_LEVEL_PRODUCTION

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_LEVEL_PRODUCTION
#endif

#if DEBUG_LEVEL != DEBUG_LEVEL_PRODUCTION
#define USBLog(level, args...) KernelDebugLogInternal((level), 'USBF', ## args)
#else
#define USBLog(level, args...)
#endif

#endif /* IOUSBLog_h */
