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
    #define MIN(a, b)			(a < b ? a : b)
#endif

#ifndef MAX
    #define MAX(a, b)			(a > b ? a : b)
#endif

#ifndef ABS
    #define ABS(a)				(a>0   ? a : -a)
#endif

#ifndef CLAMP
    #define CLAMP(x, a)			(x>=a ?	(a-1)	:	(x<0?0:x))
#endif

#ifndef CLAMPi
    #define CLAMPi(x, a, b)		(x<a ?	a		:	(x>b?b:x))
#endif

/**isnan: is it a NaN?*/
#ifndef isnan
template< typename T > inline bool isnan(T value)
{
    return value != value ;
}
#endif

/**isnan: is it a Inf value?*/
#ifndef isnan
template< typename T > inline bool isinf(T value)
{
    return std::numeric_limits<T>::has_infinity &&
           (value == std::numeric_limits<T>::infinity() ||
            value == -std::numeric_limits<T>::infinity());
}
#endif


/**SFunction: a cubic s-function*/
inline float SFunction(float x){
	float x2 = x*x;
	return 3.0f*x2-2.0f*x2*x;
}

/**SCurve5: a quintic S-Shape: 6x^5-15x^4+10x^3*/
float SCurve5(float t){
	float t2=t*t;
	float t4=t2*t2;

	return (6.0f*t-15.0f)*t4+10.0f*t2*t;
}

//Clamp a value, x, in the bound [a,b]
template < class T >
inline T Clamp(T x, T a, T b) {
	if(x>b)
		return b;

	if(x<a)
		return a;
		
	return x;
}

/**lround: double rounding*/
inline long lround(double x){
   if(x>0)
      return (x-floor(x)<0.5) ? (long)floor(x) : (long)ceil(x);
   else
      return (x-floor(x)<=0.5) ? (long)floor(x) : (long)ceil(x);
}

/**lerp: Linear interpolation*/
inline float lerp(float t, float x0, float x1){
	return x0+t*(x1-x0);
}

/**SmoothStep: smoothes a value from a to b using a cube S-Shape: -2x^3+3x^2*/
inline float SmoothStep(float a, float b, float value){
	float x = Clamp<float>((value - a) / (b - a), 0.0f, 1.0f);
	return  x*x*(-2.0f*x + 3.0f);
}

/**Deg2Rad: from degrees to radiants*/
inline float Deg2Rad(float deg){
	return deg*C_PI_OVER_ONE_80;
}

/**Rad2Deg: from radiants to degrees*/
inline float Rad2Deg(float rad){
	return rad*C_ONE_80_OVER_PI;
}

/**log2: logarithm in base 2 for integers*/
inline int log2(int n){
	int val = 1;
	int lg  = 0;
	while(val<n){
		val=val<<1;
		lg++;
	}
	
	if(val!=n)
		lg--;

	return lg;
}

/**pow2: Power of Two*/
inline int pow2(int n){
	return 1<<n;
}

/**log2f: logarithm in base 2 for floating point*/
inline float log2f(float x){
    return logf(x) * C_INV_LOG_NAT_2;
}

/**NegZero: a small value is set to zero*/
inline float NegZero(float val){
	return (fabsf(val)<1e-6f) ? 0.0f : val;
}
#endif