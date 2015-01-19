#pragma once

#include "platform.h"

#if defined(__kos__)
#  include "kolibrios/kosSyst.h"
#elif defined(__sdl2__)
#  include "sdl2/kosSyst.h"
#else
#  error Unknown platform
#endif
