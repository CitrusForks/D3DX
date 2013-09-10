/**
*     Copyright (C) 2008-2013  Francesco Banterle
* 
*     This program is free software: you can redistribute it and/or modify
*     it under the terms of the GNU General Public License as published by
*     the Free Software Foundation, either version 3 of the License, or
*     (at your option) any later version.
* 
*     This program is distributed in the hope that it will be useful,
*     but WITHOUT ANY WARRANTY; without even the implied warranty of
*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*     GNU General Public License for more details.
* 
*     You should have received a copy of the GNU General Public License
*     along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FUNCTIONS_D3DX_MATH_UTIL
#define FUNCTIONS_D3DX_MATH_UTIL

#include <math.h>

#include "math_constant.h"

#define equalf(a, b)		( fabsf(a-b)< C_EPSILON)

#define MIN(a, b)			(a < b ? a : b)
#define MAX(a, b)			(a > b ? a : b)
#define ABS(a)				(a>0 ? a : -a)

#define CLAMP(x, a)			(x>=a ?	(a-1)	:	(x<0?0:x))
#define CLAMPi(x, a, b)		(x<a ?	a		:	(x>b?b:x))

/**S-function*/
inline float SFunction(float x){
	float x2 = x*x;
	return 3.0f*x2-2.0f*x2*x;
};

/**Deg2Rad: from degrees to radiants*/
inline float Deg2Rad(float deg){
	return deg*C_PI_OVER_ONE_80;
};

/**Rad2Deg: from radiants to degrees*/
inline float Rad2Deg(float rad){
	return rad*C_ONE_80_OVER_PI;
};

/**log2: logarithm in base 2*/
inline int log2(int n){
	int val=1;
	int lg=0;
	while(val<n){
		val=val<<1;
		lg++;
	}
	return lg;
};

//Power of Two
inline int pow2(int n){
	return 1<<n;
};

#endif