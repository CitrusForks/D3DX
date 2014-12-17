/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef FUNCTIONS_D3DX_MATH_UTIL
#define FUNCTIONS_D3DX_MATH_UTIL

#include <math.h>

#include "math_constant.hpp"

#ifndef MIN
    #define MIN(a, b)       (a < b ? a : b)
#endif

#ifndef MAX
    #define MAX(a, b)       (a > b ? a : b)
#endif

#ifndef ABS
    #define ABS(a)          (a > 0   ? a : -a)
#endif

#ifndef CLAMP
    #define CLAMP(x, a)     ( x >= a ?  (a-1) : (x < 0 ? 0 : x))
#endif

#ifndef CLAMPi
    #define CLAMPi(x, a, b) (x < a ? a : (x > b ? b : x))
#endif


#endif //FUNCTIONS_D3DX_MATH_UTIL
