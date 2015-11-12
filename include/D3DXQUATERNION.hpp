/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DXQUATERNION_HPP
#define D3DXQUATERNION_HPP

/**
 * @brief The D3DXQUATERNION class
 */
class D3DXQUATERNION
{
public:

    float x, y, z, w;

    /**
     * @brief D3DXQUATERNION
     */
    D3DXQUATERNION()
    {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.0f;
	}
};

/**
 * @brief D3DXQuaternionIdentity creates the identity quaternion.
 * @param pOut
 * @return
 */
D3DXQUATERNION *D3DXQuaternionIdentity(D3DXQUATERNION *pOut)
{
    #ifdef D3DX_POINTER_CHECK
        if(pOut == NULL) {
		    pOut = new D3DXQUATERNION();
        }
    #endif
	
    pOut->x = 0.0f;
	pOut->y = 0.0f;
	pOut->z = 0.0f;
	pOut->w = 1.0f;

	return pOut;
}

/**
 * @brief D3DXQuaternionRotationAxis calculates a quaternion given an axis and an angle.
 * @param pOut
 * @param pV
 * @param Angle
 * @return
 */
D3DXQUATERNION *D3DXQuaternionRotationAxis(D3DXQUATERNION *pOut, const D3DXVECTOR3 * pV, float Angle)
{
    #ifdef D3DX_POINTER_CHECK
        if(pOut == NULL) {
		    pOut = new D3DXQUATERNION();
        }
    #endif

	Angle /= 2.0f;

	float sinAngle = sinf(Angle);

    pOut->x = (sinAngle * pV->x);
    pOut->y = (sinAngle * pV->y);
    pOut->z = (sinAngle * pV->z);
	pOut->w = cosf(Angle);

	return pOut;
}

/**
 * @brief D3DXQuaternionDot evaluates dot product between quaternions.
 * @param pQ1
 * @param pQ2
 * @return
 */
inline float D3DXQuaternionDot(const D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2)
{
    return (pQ1->x * pQ2->x +
            pQ1->y * pQ2->y +
            pQ1->z * pQ2->z +
            pQ1->w * pQ2->w);
}

/**
 * @brief D3DXQuaternionSlerp performs spherical interpolation.
 * @param pOut
 * @param pQ1
 * @param pQ2
 * @param t
 * @return
 */
inline D3DXQUATERNION* D3DXQuaternionSlerp(D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2, float t)
{
    #ifdef D3DX_POINTER_CHECK
        if(pOut == NULL) {
		    pOut = new D3DXQUATERNION();
        }
    #endif

    float theta = acosf(D3DXQuaternionDot(pQ1, pQ2));

	float sinTheta = sinf(theta);

    float t1 = sinf((1.0f - t) * theta) / sinTheta;
    float t2 = sinf(t * theta) / sinTheta;

    pOut->x = pQ1->x * t1 + pQ2->x * t2;
    pOut->y = pQ1->y * t1 + pQ2->y * t2;
    pOut->z = pQ1->z * t1 + pQ2->z * t2;
    pOut->w = pQ1->w * t1 + pQ2->w * t2;

	return pOut;
}

#endif //D3DXQUATERNION_HPP
