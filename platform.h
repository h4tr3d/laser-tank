#ifndef _LASER_TANK_PLATFORM_H
#define _LASER_TANK_PLATFORM_H

#ifdef _WIN32
	// define something for Windows (32-bit and 64-bit)
	#include <windows.h>
	#ifdef _WIN64
	//define something for Windows (64-bit only)
	#endif
#elif __APPLE__
	#include <mach-o/dyld.h>
	#include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
        // iOS Simulator
    #elif TARGET_OS_IPHONE
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
        // Unsupported platform
    #endif
#elif __linux__
	// linux	
#else
    // kolibri os 
	#define __KILIBRI_OS_
#endif

int getexepath(char *exepath);

#endif
