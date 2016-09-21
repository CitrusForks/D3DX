/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DX_FUNCTIONS_HPP
#define D3DX_FUNCTIONS_HPP

#include <math.h>

#include "D3DXVECTOR2.hpp"
#include "D3DXVECTOR3.hpp"
#include "D3DXVECTOR4.hpp"

/**
 * @brief D3DXVec3Cross computes the cross product A x B
 * @param pOut
 * @param A
 * @param B
 */
D3DXVECTOR3 *D3DXVec3Cross(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *A, const D3DXVECTOR3 *B)
{
    #ifdef D3DX_POINTER_CHECK
        if(pOut == NULL) {
            pOut = new D3DXVECTOR3();
        }
    #endif

	pOut->x = A->y * B->z - B->y * A->z;
	pOut->y = A->z * B->x - B->z * A->x;
	pOut->z = A->x * B->y - B->x * A->y;
    return pOut;
}

/**
 * @brief D3DXVec2Dot
 * @param a
 * @param b
 * @return
 */
inline float D3DXVec2Dot(const D3DXVECTOR2 *a, const D3DXVECTOR2 *b)
{
    return (a->x * b->x +
            a->y * b->y);
}

/**
 * @brief D3DXVec3Dot
 * @param a
 * @param b
 * @return
 */
inline float D3DXVec3Dot(const D3DXVECTOR3 *a, const D3DXVECTOR3 *b)
{
    return (a->x * b->x +
            a->y * b->y +
            a->z * b->z);
}

/**
 * @brief D3DXVec4Dot
 * @param a
 * @param b
 * @return
 */
inline float D3DXVec4Dot(const D3DXVECTOR4 *a, const D3DXVECTOR4 *b)
{
    return (a->x * b->x +
            a->y * b->y +
            a->z * b->z +
            a->w * b->w);
}

/**
 * @brief D3DXVec2Normalize
 * @param pOut
 * @param pV
 * @return
 */
D3DXVECTOR2 *D3DXVec2Normalize(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV)
{
#ifdef D3DX_NORMALIZATION_POINTER_CHECK
    if(pOut == NULL) {
        pOut = new D3DXVECTOR2();
    }
#endif

    float length = (pV->x * pV->x + pV->y * pV->y);
	
    if(length > 0.0f) {
		length = sqrtf(length);
        pOut->x = pV->x / length;
        pOut->y = pV->y / length;
		return pOut;
    } else {
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR2 *D3DXVec2Normalize(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV): Normalization Error!\n");
		#endif
		return pOut;
	}
}

D3DXVECTOR2 *D3DXVec2Normalize(D3DXVECTOR2 *pOut)
{
    float length = (pOut->x * pOut->x + pOut->y * pOut->y);
	
    if(length > 0.0f) {
		length = sqrtf(length);
		pOut->x /= length;
		pOut->y /= length;
		return pOut;
    } else {
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR2 *D3DXVec2Normalize(D3DXVECTOR2 *pOut): Normalization Error!\n");
		#endif
		return pOut;
	}
}

/**
 * @brief D3DXVec3Normalize
 * @param pOut
 * @param pV
 * @return
 */
D3DXVECTOR3 *D3DXVec3Normalize(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV)
{
#ifdef D3DX_NORMALIZATION_POINTER_CHECK
	if(pOut == NULL) {
		pOut = new D3DXVECTOR3();
    }
#endif

    float length = (pV->x * pV->x+
                    pV->z * pV->z+
                    pV->y * pV->y);
	
    if(length > 0.0f){
		length = sqrtf(length);
        pOut->x = pV->x / length;
        pOut->y = pV->y / length;
        pOut->z = pV->z / length;
		return pOut;
    } else {
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR3 *D3DXVec3Normalize(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV): Normalization Error!\n");
		#endif
		return pOut;
	}
}

/**
 * @brief D3DXVec3Normalize normalizes a D3DXVECTOR3.
 * @param pOut
 * @return
 */
D3DXVECTOR3 *D3DXVec3Normalize(D3DXVECTOR3 *pOut)
{
    float length = (pOut->x * pOut->x +
                    pOut->z * pOut->z +
                    pOut->y * pOut->y);
	
    if(length > 0.0f) {
		length = sqrtf(length);
		pOut->x /= length;
		pOut->y /= length;
		pOut->z /= length;
		return pOut;
    } else {
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR3 *D3DXVec3Normalize(D3DXVECTOR3 *pOut): Normalization Error!\n");
		#endif
		return pOut;
	}
}

/**
 * @brief D3DXVec3Normalize2 normalizes a D3DXVECTOR3 and returns is magnitude.
 * @param pOut
 * @return
 */
float D3DXVec3Normalize2(D3DXVECTOR3 *pOut)
{
    float length = (pOut->x * pOut->x +
                    pOut->z * pOut->z +
                    pOut->y * pOut->y);
	
    if(length > 0.0f) {
		length = sqrtf(length);
		pOut->x /= length;
		pOut->y /= length;
		pOut->z /= length;
		return length;
    } else {
		return 0.0f;
    }
}

/**
 * @brief D3DXVec4Normalize normalizes a D3DXVECTOR4.
 * @param pOut
 * @param pV
 * @return
 */
D3DXVECTOR4 *D3DXVec4Normalize(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV)
{
#ifdef D3DX_NORMALIZATION_POINTER_CHECK
	if(pOut == NULL) {
		pOut = new D3DXVECTOR4();
    }
#endif
    float length = (pV->x * pV->x+
                    pV->z * pV->z+
                    pV->w * pV->w+
                    pV->y * pV->y);
	
    if(length > 0.0f) {
		length = sqrtf(length);
        pOut->x = pV->x / length;
        pOut->y = pV->y / length;
        pOut->z = pV->z / length;
        pOut->w = pV->w / length;
		return pOut;
    } else {
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR4 *D3DXVec4Normalize(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV): Normalization Error!\n");
		#endif
		return pOut;
	}
}

/**
 * @brief D3DXVec2LengthSq
 * @param pV
 * @return
 */
float D3DXVec2LengthSq(const D3DXVECTOR2 *pV)
{
    return	pV->x * pV->x+
            pV->y * pV->y;
}

/**
 * @brief D3DXVec3LengthSq
 * @param pV
 * @return
 */
float D3DXVec3LengthSq(const D3DXVECTOR3 *pV)
{
    return	pV->x * pV->x+
            pV->z * pV->z+
            pV->y * pV->y;
}

/**
 * @brief D3DXVec4LengthSq
 * @param pV
 * @return
 */
float D3DXVec4LengthSq(const D3DXVECTOR4 *pV)
{
    return	pV->x * pV->x +
            pV->z * pV->z +
            pV->w * pV->w +
            pV->y * pV->y;
}

/**
 * @brief D3DXVec2Length
 * @param pV
 * @return
 */
float D3DXVec2Length(const D3DXVECTOR2 *pV)
{
    return	sqrtf(  pV->x * pV->x +
                    pV->y * pV->y);
}

/**
 * @brief D3DXVec3Length
 * @param pV
 * @return
 */
float D3DXVec3Length(const D3DXVECTOR3 *pV)
{
    return	sqrtf(  pV->x * pV->x+
                    pV->z * pV->z+
                    pV->y * pV->y);
}

/**
 * @brief D3DXVec4Length
 * @param pV
 * @return
 */
float D3DXVec4Length(const D3DXVECTOR4 *pV)
{
    return	sqrtf(	pV->x * pV->x+
                    pV->z * pV->z+
                    pV->w * pV->w+
                    pV->y * pV->y);
}

/**
 * @brief D3DXVecDistance
 * @param a
 * @param b
 * @return
 */
float D3DXVecDistance(const D3DXVECTOR2 *a, const D3DXVECTOR2 *b)
{
	D3DXVECTOR2 c;
    c.x = a->x - b->x;
    c.y = a->y - b->y;
    return sqrtf(c.x * c.x + c.y * c.y);
}

/**
 * @brief D3DXVecDistance
 * @param a
 * @param b
 * @return
 */
float D3DXVecDistance(const D3DXVECTOR3 *a, const D3DXVECTOR3 *b)
{
	D3DXVECTOR3 c;
    c.x = a->x - b->x;
    c.y = a->y - b->y;
    c.z = a->z - b->z;

    return sqrtf(c.x * c.x +
                 c.y * c.y +
                 c.z * c.z);
}

/**
 * @brief D3DXVecDistanceSq
 * @param a
 * @param b
 * @return
 */
float D3DXVecDistanceSq(const D3DXVECTOR2 *a, const D3DXVECTOR2 *b)
{
	D3DXVECTOR2 c;
	c.x = a->x - b->x;
	c.y = a->y - b->y;
	return c.x * c.x + c.y * c.y;
}

/**
 * @brief D3DXVecDistanceSq
 * @param a
 * @param b
 * @return
 */
float D3DXVecDistanceSq(const D3DXVECTOR3 *a, const D3DXVECTOR3 *b)
{
	D3DXVECTOR3 c;
    c.x = a->x - b->x;
    c.y = a->y - b->y;
    c.z = a->z - b->z;
    return c.x * c.x + c.y * c.y + c.z * c.z;
}

/**
 * @brief D3DXFloat2Vec3
 * @param vec
 * @return
 */
D3DXVECTOR3 D3DXFloat2Vec3(float vec[3])
{
    return D3DXVECTOR3(vec[0], vec[1], vec[2]);
}

/**
 * @brief D3DXVec3Similar checks if two D3DXVECTOR3s are similar.
 * @param a
 * @param b
 * @return
 */
bool D3DXVec3Similar(const D3DXVECTOR3 *a, const D3DXVECTOR3 *b)
{
	D3DXVECTOR3 tmp = *a - *b;
    return sqrtf(MAX(D3DXVec3Dot(&tmp, &tmp), 0.0f)) < 1e-12f;
}

#endif //D3DX_FUNCTIONS_HPP
