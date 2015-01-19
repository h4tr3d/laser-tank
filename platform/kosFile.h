#pragma once

#include "platform.h"

#if defined(__kos__)
#  include "kolibrios/kosFile.h"
#elif defined(__sdl2__)
#  include "sdl2/kosFile.h"
#else
#  error Unknown platform
#endif
