#pragma once

#if defined(KOLIBRIOS_MSVC)
#  include "msvc/func.h"
#elif defined(KOLIBRIOS_GCC)
#  include "gcc/func.h"
#else
#  error Unknown KolibriOS compiller
#endif
