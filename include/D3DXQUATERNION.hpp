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

#ifndef CLASS_D3DXQUATERNION
#define CLASS_D3DXQUATERNION

class D3DXQUATERNION
{
public:

	float x,y,z,w;

	D3DXQUATERNION(){
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.0f;
	}
};

//D3DXQuaternionIdentity:: identity quaternion
D3DXQUATERNION *D3DXQuaternionIdentity(D3DXQUATERNION *pOut){
	if(pOut==NULL)
		pOut = new D3DXQUATERNION();

	pOut->x = 0.0f;
	pOut->y = 0.0f;
	pOut->z = 0.0f;
	pOut->w = 1.0f;

	return pOut;
}

/**Calculate a quaternion from an axis and an angle*/
D3DXQUATERNION *D3DXQuaternionRotationAxis(D3DXQUATERNION *pOut, const D3DXVECTOR3 * pV, float Angle){
	if(pOut==NULL)
		pOut=new D3DXQUATERNION();

	Angle /= 2.0f;

	float sinAngle = sinf(Angle);

	pOut->x = (sinAngle*pV->x);
	pOut->y = (sinAngle*pV->y);
	pOut->z = (sinAngle*pV->z);
	pOut->w = cosf(Angle);

	return pOut;
}

//D3DXQuaternionDot:: dot product between quaternions
inline float D3DXQuaternionDot(const D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2){
	return (pQ1->x*pQ2->x + pQ1->y*pQ2->y + pQ1->z*pQ2->z + pQ1->w*pQ2->w);
}

//D3DXQuaternionSlerp: spherical interpolation
inline D3DXQUATERNION* D3DXQuaternionSlerp(D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2, float t){
	if(pOut==NULL)
		pOut = new D3DXQUATERNION();

	float theta = acosf(D3DXQuaternionDot(pQ1,pQ2));

	float sinTheta = sinf(theta);

	float t1 = sinf((1.0f-t)*theta)/sinTheta;
	float t2 = sinf(t*theta)/sinTheta;

	pOut->x = pQ1->x*t1 + pQ2->x*t2;
	pOut->y = pQ1->y*t1 + pQ2->y*t2;
	pOut->z = pQ1->z*t1 + pQ2->z*t2;
	pOut->w = pQ1->w*t1 + pQ2->w*t2;

	return pOut;
}
#endif