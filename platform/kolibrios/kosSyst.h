#pragma once

#if defined(KOLIBRIOS_MSVC)
#  include "msvc/kosSyst.h"
#elif defined(KOLIBRIOS_GCC)
#  include "gcc/kosSyst.h"
#else
#  error Unknown KolibriOS compiller
#endif
