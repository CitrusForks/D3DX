/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DX_COORDSYS
#define D3DX_COORDSYS

#include "math_constant.hpp"

#include "D3DXVECTOR2.hpp"
#include "D3DXVECTOR3.hpp"

#define D3DX_COORDSYS_EPSILON 1e-6f

/**
 * @brief D3DXVecToAng converts a D3DXVECTOR3 direction into a (theta, phi) direction.
 * @param dir
 * @param out
 * @return
 */
D3DXVECTOR2 *D3DXVecToAng(const D3DXVECTOR3 *dir, D3DXVECTOR2 *out)
{

	#ifdef GRT_POINTER_OUT_CHECK
        if(out == NULL)
			out = new D3DXVECTOR2();
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
D3DXVECTOR2 *D3DXVecToTexCoord(const D3DXVECTOR3 *dir, D3DXVECTOR2 *out)
{
    if(out == NULL)
		out = new D3DXVECTOR2();

	//(theta,phi)->(y,x)
    out->x = 1.0f - ((atan2f(dir->z, -dir->x) * C_INV_PI) * 0.5f + 0.5f);
    out->y = (acosf(dir->y) * C_INV_PI);

	return out;
}

/**
 * @brief D3DXAngToVec converts a (theta, phi) direction into a D3DXVECTOR3 direction.
 * @param dir
 * @param out
 * @return
 */
D3DXVECTOR3 *D3DXAngToVec(const D3DXVECTOR2 *dir, D3DXVECTOR3 *out)
{
	#ifdef GRT_POINTER_OUT_CHECK
        if(out == NULL)
			out = new D3DXVECTOR3();
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
inline D3DXVECTOR3 *D3DXImgCoordToVec(float x, float y, int width, int height, D3DXVECTOR3 *out)
{
	if(out == NULL)
		out = new D3DXVECTOR3();

    float phi   = (C_PI_2 * x) / float(width);
    float theta = (C_PI   * y) / float(height);

    float sinTheta = sinf(theta);

    out->x = sinTheta * cosf(phi);
	out->y = cosf(theta);
    out->z = sinTheta * sinf(phi);

	return out;
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
    if(pOut == NULL)
		pOut = new D3DXVECTOR3();

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
    if(pOut == NULL)
		pOut = new D3DXVECTOR3();

    *pOut =     (*V0) * pV->x +
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
    } else{
		n->z = 0.0f;
		D3DXVec3Normalize(n, n);
	}
}

#endif //D3DX_COORDSYS
