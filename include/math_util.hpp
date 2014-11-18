/**
*     Copyright (C) 2008-2013  Francesco Banterle
* 
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
