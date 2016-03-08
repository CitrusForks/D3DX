/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DX_COORDSYS_HPP
#define D3DX_COORDSYS_HPP

#include <math.h>
#include <cmath>

#include "math_constant.hpp"
#include "D3DXFunctions.hpp"
#include "D3DXVECTOR2.hpp"
#include "D3DXVECTOR3.hpp"
#include "D3DXMATRIX2X2.hpp"

#define D3DX_COORDSYS_EPSILON   1e-6f

#define D3DX_FB_SQRT_5          2.2360679774997896964091736687313f
#define D3DX_FB_PHI             1.6180339887498948482045868343656f
#define D3DX_FB_PHI_MINUS_ONE   0.6180339887498948482045868343656f

/**
 * @brief D3DXVecToAng converts a D3DXVECTOR3 direction into a (theta, phi) direction.
 * @param dir
 * @param out
 * @return
 */
D3DXVECTOR2 *D3DXVecToAng(const D3DXVECTOR3 *dir, D3DXVECTOR2 *out)
{

    #ifdef D3DX_POINTER_CHECK
        if(out == NULL) {
			out = new D3DXVECTOR2();
        }
	#endif

	out->x = acosf( dir->y);
	out->y = atan2f(dir->z, dir->x);

	return out;
}

/**
 * @brief D3DXVecToTexCoord converts a D3DXVECTOR3 direction into (theta, phi) direction.
 * @param dir
 * @param out
 * @return
 */
D3DXVECTOR2 *D3DXVecToTexCoord(const D3DXVECTOR3 *dir, D3DXVECTOR2 *pOut)
{
    #ifdef D3DX_POINTER_CHECK
        if(pOut == NULL) {
	        pOut = new D3DXVECTOR2();
        }
    #endif

	//(theta,phi)->(y,x)
    pOut->x = 1.0f - ((atan2f(dir->z, -dir->x) * C_INV_PI) * 0.5f + 0.5f);
    pOut->y = (acosf(dir->y) * C_INV_PI);

	return pOut;
}

/**
 * @brief D3DXAngToVec converts a (theta, phi) direction into a D3DXVECTOR3 direction.
 * @param dir
 * @param out
 * @return
 */
D3DXVECTOR3 *D3DXAngToVec(const D3DXVECTOR2 *dir, D3DXVECTOR3 *out)
{
	#ifdef D3DX_POINTER_CHECK
        if(out == NULL) {
			out = new D3DXVECTOR3();
        }
	#endif

	float sinTheta = sinf(dir->x);
    out->x = cosf(dir->y) * sinTheta;
	out->y = cosf(dir->x);
    out->z = sinf(dir->y) * sinTheta;

	return out;
}

/**
 * @brief D3DXImgCoordToVec converts from a pixel position (x,y) to a D3DXVECTOR3 direction.
 * @param x
 * @param y
 * @param width
 * @param height
 * @param out
 * @return
 */
inline D3DXVECTOR3 *D3DXImgCoordToVec(float x, float y, int width, int height, D3DXVECTOR3 *pOut)
{
  	#ifdef D3DX_POINTER_CHECK
        if(pOut == NULL) {
	        pOut = new D3DXVECTOR3();
        }
    #endif

    float phi   = (C_PI_2 * x) / float(width);
    float theta = (C_PI   * y) / float(height);

    float sinTheta = sinf(theta);

    pOut->x = sinTheta * cosf(phi);
	pOut->y = cosf(theta);
    pOut->z = sinTheta * sinf(phi);

	return pOut;
}

/**
 * @brief CreateOrthoNormalBase create an orthonormal base from a vector (n).
 * @param n
 * @param u
 * @param v
 */
void CreateOrthoNormalBase(const D3DXVECTOR3 *n, D3DXVECTOR3 *u, D3DXVECTOR3 *v)
{
    if(fabsf(n->z) > D3DX_COORDSYS_EPSILON) {
        v->x =  0.0f;
        v->y =  n->z;
        v->z = -n->y;
    } else {
        if(fabsf(n->x)>D3DX_COORDSYS_EPSILON) {
            v->x =  n->z;
            v->y =  0.0f;
            v->z = -n->x;
        } else {
            v->x = n->y;
            v->y = 0.0f;
            v->z = 0.0f;
		}
	}

	D3DXVec3Normalize(v);
    D3DXVec3Cross(u, v, n);
	
	//NOTE: This should not be required
	D3DXVec3Normalize(u);
}

/**
 * @brief D3DXVecProjBase projects onto a base.
 * @param V0
 * @param V1
 * @param V2
 * @param pV
 * @param pOut
 * @return
 */
D3DXVECTOR3 *D3DXVecProjBase(	const D3DXVECTOR3 *V0,
								const D3DXVECTOR3 *V1,
								const D3DXVECTOR3 *V2,
								const D3DXVECTOR3 *pV,
                                D3DXVECTOR3 *pOut)
{
  	#ifdef D3DX_POINTER_CHECK
        if(pOut == NULL) {
	        pOut = new D3DXVECTOR3();
        }
    #endif

    pOut->x = D3DXVec3Dot(V0, pV);
    pOut->y = D3DXVec3Dot(V1, pV);
    pOut->z = D3DXVec3Dot(V2, pV);

	return pOut;
}

/**
 * @brief D3DXVecApplyBase applies a base.
 * @param V0
 * @param V1
 * @param V2
 * @param pV
 * @param pOut
 * @return
 */
D3DXVECTOR3 *D3DXVecApplyBase(	const D3DXVECTOR3 *V0,
								const D3DXVECTOR3 *V1,
								const D3DXVECTOR3 *V2,
								const D3DXVECTOR3 *pV,
                                D3DXVECTOR3 *pOut)
{
  	#ifdef D3DX_POINTER_CHECK
        if(pOut == NULL) {
	        pOut = new D3DXVECTOR3();
        }
    #endif

    *pOut = (*V0) * pV->x +
            (*V1) * pV->y +
            (*V2) * pV->z;
    return pOut;
}

/**
 * @brief DecompressNormals decompresses normals.
 * @param n
 */
void DecompressNormals(D3DXVECTOR3 *n)
{
    float tmp = 1.0f - n->x * n->x - n->y * n->y;

    if(tmp > 0.0f) {
		n->z = sqrtf(tmp);
    } else {
        n->z = 0.0f;
        D3DXVec3Normalize(n, n);
    }
}

/**
 * @brief FibonacciNormals
 * @param pOut is the output unit vector
 * @param i is the encoded value of the vector
 * @param n is the precision encoding value such that n < 2^{21} due to 32-bit floating point
 * @return
 */
D3DXVECTOR3 *FibonacciNormals(D3DXVECTOR3 *pOut, unsigned int i, unsigned int n)
{
#ifdef D3DX_POINTER_CHECK
    if(pOut == NULL) {
	    pOut = new D3DXVECTOR3();
    }
#endif

    float i_f = float(i);

    float tmp = i_f * D3DX_FB_PHI_MINUS_ONE;
    float phi = C_PI_2 * (tmp - floorf(tmp));

    float cosTheta = 1.0f - (2.0f * i_f + 1.0f) / float(n);
    float sinTheta = sqrtf(MAX(1.0f - cosTheta * cosTheta, 0.0f));

    pOut->x = cosf(phi) * sinTheta;
    pOut->y = cosTheta;
    pOut->z = sinf(phi) * sinTheta;

    return pOut;
}

/**
 * @brief FibonacciNormalsInv
 * @param pA is the input unit vector
 * @param n is the precision encoding value such that n < 2^{21} due to 32-bit floating point
 * @return
 */
unsigned int FibonacciNormalsInv(const D3DXVECTOR3 *pA, unsigned int n)
{
#ifdef D3DX_POINTER_CHECK
    if(pA == NULL) {
        pA = new D3DXVECTOR3();
    }
#endif

    float phi = MIN(atan2(pA->z, pA->x), C_PI);
    float cosTheta = pA->y;

    float n_f = float(n);
    float k = log_base(n_f * C_PI * D3DX_FB_SQRT_5 * (1.0f - cosTheta * cosTheta), D3DX_FB_PHI * D3DX_FB_PHI);
    k = MAX(floorf(k), 2.0f);

    float Fk = pow(D3DX_FB_PHI, k) / D3DX_FB_SQRT_5;
      
    float tmp;

#ifdef std::round
    float F0 = std::round(Fk);
    float F1 = std::round(Fk * PHI);
#else
    float F0 = floorf(fabsf(Fk  + 0.5f)) * (Fk >= 0.0f ? 1.0f : -1.0f);
    tmp = Fk * D3DX_FB_PHI;
    float F1 = floorf(fabsf(tmp + 0.5f)) * (tmp >= 0.0f ? 1.0f : -1.0f);
#endif

    D3DXMATRIX2X2 B = D3DXMATRIX2X2(
        C_PI_2 * (madfrac(F0 + 1.0f, D3DX_FB_PHI_MINUS_ONE) -  D3DX_FB_PHI_MINUS_ONE),
        C_PI_2 * (madfrac(F1 + 1.0f, D3DX_FB_PHI_MINUS_ONE) -  D3DX_FB_PHI_MINUS_ONE),
        -2.0f * F0 / n_f,
        -2.0f * F1 / n_f);

    D3DXVECTOR2 B1; 
    B.getRow(&B1, 1);

    D3DXMATRIX2X2 B_inv;
    B.Inverse(&B_inv);

    D3DXVECTOR2 vec = D3DXVECTOR2(phi, cosTheta - (1.0f - 1.0f / n_f));

    D3DXVECTOR2 c = B_inv * vec;
    c.x = floorf(c.x);
    c.y = floorf(c.y);

    float n_f_rcp = 1.0f / n_f;

	float d = 1024.0f; 
    unsigned int j = 0;
	for (unsigned int s = 0; s < 4; ++s) {

        D3DXVECTOR2 tmp_v2 = D3DXVECTOR2(float(s % 2), float(s / 2));
        tmp_v2 += c;
        float bias = (1.0f - n_f_rcp);
        float cosTheta = D3DXVec2Dot(&B1, &tmp_v2) + bias; 

        cosTheta = CLAMPi(cosTheta, -1.0f, 1.0f) * 2.0f - cosTheta;            
		float i = floorf(n_f * 0.5f * (1.0f - cosTheta));

		float phi = C_PI_2 * madfrac(i, D3DX_FB_PHI_MINUS_ONE);
		cosTheta = 1.0f - (2.0f * i + 1.0f) * n_f_rcp;
		float sinTheta = sqrtf(MAX(1.0f - cosTheta * cosTheta, 0.0f));

        D3DXVECTOR3 q;
        q.x = sinTheta * cosf(phi);
        q.y = cosTheta;
        q.z = sinTheta * sinf(phi);

        float dist_sq = D3DXVecDistanceSq(&q, pA);
		if (dist_sq < d) {
			d = dist_sq;
			j = i;
		}
	}
    
    return j;
}

#endif //D3DX_COORDSYS_HPP
