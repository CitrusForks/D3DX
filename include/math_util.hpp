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
           (value ==  std::numeric_limits<T>::infinity() ||
            value == -std::numeric_limits<T>::infinity());
}
#endif

/**
 * @brief SFunction evaluates a cubic s-function
 * @param x is a value in [0, 1]
 * @return
 */
inline float SFunction(float x)
{
    float x2 = x * x;
	return 3.0f*x2-2.0f*x2*x;
}

/**SCurve5: a quintic S-Shape: 6x^5-15x^4+10x^3*/

/**
 * @brief SCurve5
 * @param t
 * @return
 */
float SCurve5(float t)
{
	float t2=t*t;
	float t4=t2*t2;

	return (6.0f*t-15.0f)*t4+10.0f*t2*t;
}

//Clamp a value, x, in the bound [a,b]

/**
 * @brief Clamp
 * @param x
 * @param a
 * @param b
 * @return
 */
template < class T >
inline T Clamp(T x, T a, T b) {
    if(x > b) {
		return b;
    }

    if(x < a) {
		return a;
    }
		
	return x;
}

/**lround: double rounding*/
/**
 * @brief lround computes double rounding
 * @param x is a value to round
 * @return It returns a rounded version of x
 */
inline long lround(double x)
{
   if(x > 0) {
      return (x-floor(x) < 0.5)  ? (long)floor(x) : (long)ceil(x);
   } else {
      return (x-floor(x) <= 0.5) ? (long)floor(x) : (long)ceil(x);
   }
}

/**
 * @brief lerp evaluates linear interpolation.
 * @param t is a value in [0, 1]
 * @param x0
 * @param x1
 * @return
 */
inline float lerp(float t, float x0, float x1)
{
    return x0 + t * (x1 - x0);
}

/**
 * @brief SmoothStep
 * @param a
 * @param b
 * @param value
 * @return
 */
inline float SmoothStep(float a, float b, float value)
{
	float x = Clamp<float>((value - a) / (b - a), 0.0f, 1.0f);
    return  x * x * (-2.0f * x + 3.0f);
}

/**
 * @brief Deg2Rad converts an angle from degrees to radians.
 * @param deg is an angle expressed in degrees.
 * @return It returns an angle expressed in radians.
 */
inline float Deg2Rad(float deg)
{
    return deg * C_PI_OVER_ONE_80;
}

/**
 * @brief Rad2Deg converts an angle from radians to degrees.
 * @param rad is an angle expressed in radians.
 * @return It returns an angle expressed in degrees.
 */
inline float Rad2Deg(float rad)
{
    return rad * C_ONE_80_OVER_PI;
}

/**
 * @brief log2 computes logarithm in base 2 for integers.
 * @param n is an integer value.
 * @return It returns a value, x, such that 2 ^ x = n.
 */
inline int log2(int n)
{
	int val = 1;
	int lg  = 0;

    while(val<n) {
        val = val << 1;
		lg++;
	}
	
    if(val != n) {
		lg--;
    }

	return lg;
}

/**
 * @brief pow2 computes power of two.
 * @param n
 * @return
 */
inline int pow2(int n)
{
	return 1<<n;
}

/**
 * @brief log2f computes logarithm in base 2 for floating point.
 * @param x
 * @return
 */
inline float log2f(float x)
{
    return logf(x) * C_INV_LOG_NAT_2;
}

/**
 * @brief NegZero
 * @param val
 * @return
 */
inline float NegZero(float val)
{
    return (fabsf(val) < 1e-6f) ? 0.0f : val;
}

#endif //FUNCTIONS_D3DX_MATH_UTIL
