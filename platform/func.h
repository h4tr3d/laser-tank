#pragma once

#include "platform.h"

#if defined(__kos__)
#  include "kolibrios/func.h"
#elif defined(__sdl2__)
#  include "sdl2/func.h"
#else
#  error Unknown platform
#endif
