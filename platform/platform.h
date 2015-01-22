#ifndef _LASER_TANK_PLATFORM_H
#define _LASER_TANK_PLATFORM_H

#if defined(KOLIBRIOS_MSVC) || defined(KOLIBRIOS_GCC)
   // kolibri os
   #define __kolibrios__
   #define __kos__

#elif defined(_WIN32)
    #define __sdl2__
    // define something for Windows (32-bit and 64-bit)
    #include <windows.h>
    #ifdef _WIN64
    //define something for Windows (64-bit only)
    #endif
#elif defined(__APPLE__)
    #define __sdl2__
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
#elif defined(__linux__)
    #define __sdl2__
    // linux
#else
    #error Unknown build target
#endif

#endif // _LASER_TANK_PLATFORM_H
