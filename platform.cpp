// platform specific functions
#include <stdio.h>
#include <iostream>

#include "platform.h"

#ifdef _WIN32
    // define something for Windows (32-bit and 64-bit)
	int getexepath(char *exepath)
	{
		int size = GetModuleFileName( NULL, exepath, 1024);
		return return size > 0 ? size : -1;
	}
   #ifdef _WIN64
    //define something for Windows (64-bit only)
   #endif
#elif __APPLE__
	int getexepath(char *exepath)
	{
		char path[1024];
		uint32_t size = sizeof(path);
		if(_NSGetExecutablePath(path, &size) == 0) {
			memcpy(exepath, path, size);
		}
		return size > 0 ? size : -1;
	}	
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
	int getexepath(char *exepath)
	{
		ssize_t count = readlink( "/proc/self/exe", exepath, 1024);
		return count > 0 ? count : -1;
	}
#else
    // kolibri os 
#endif

