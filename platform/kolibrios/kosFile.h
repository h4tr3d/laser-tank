#pragma once

#if defined(KOLIBRIOS_MSVC)
#  include "msvc/kosFile.h"
#elif defined(KOLIBRIOS_GCC)
#  include "gcc/kosFile.h"
#else
#  error Unknown KolibriOS compiller
#endif
