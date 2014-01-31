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

#ifndef FUNCTIONS_D3DXGEOMETRY
#define FUNCTIONS_D3DXGEOMETRY

#include "D3DXConstants.h"
#include "D3DXFunctions.h"

/**D3DXTriangleNormal: computes the normal of a triangle*/
D3DXVECTOR3 *D3DXTriangleNormal(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *p1, const D3DXVECTOR3 *p2, const D3DXVECTOR3 *p3){
	D3DXVECTOR3 a, b;
	a.x=p1->x-p2->x;
	a.y=p1->y-p2->y;
	a.z=p1->z-p2->z;

	b.x=p2->x-p3->x;
	b.y=p2->y-p3->y;
	b.z=p2->z-p3->z;

	D3DXVec3Cross(pOut,&a,&b);
	D3DXVec3Normalize(pOut);
	return pOut;
}

/**D3DXTriangleNormal: computes the normal of a triangle*/
D3DXVECTOR3 *D3DXTriangleNormal2(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *p1, const D3DXVECTOR3 *p2, const D3DXVECTOR3 *p3){
	D3DXVECTOR3 a, b;
	a.x=p1->x-p2->x;
	a.y=p1->y-p2->y;
	a.z=p1->z-p2->z;

	b.x=p2->x-p3->x;
	b.y=p2->y-p3->y;
	b.z=p2->z-p3->z;

	D3DXVec3Cross(pOut,&a,&b);
	return pOut;
}

/**D3DXTriangleArea: calculates the area of a triangle*/
float D3DXTriangleArea(D3DXVECTOR3 *v0, D3DXVECTOR3 *v1, D3DXVECTOR3 *v2){
	float v01 = D3DXVecDistance(v0,v1);
	float v02 = D3DXVecDistance(v0,v2);
	float v12 = D3DXVecDistance(v1,v2);

	float s = (v01+v02+v12)/2.0f;

	float area2 = s*(s-v01)*(s-v02)*(s-v12);
	return (area2>0.0f) ? sqrtf(area2): 0.0f;
}

inline float D3DXTriangleArea(float v01, float v02, float v12){
	float s = (v01+v02+v12)/2.0f;

	float area2 = s*(s-v01)*(s-v02)*(s-v12);
	return (area2>0.0f) ? sqrtf(area2): 0.0f;
}

/**Convert a D3DXVECTOR2 into a D3DXVECTOR3*/
D3DXVECTOR3 D3DXVec2ToVec3(D3DXVECTOR2 *vec){
	D3DXVECTOR3 ret;

	ret.x = vec->x;
	ret.y = 0.0f;
	ret.z = vec->y;

	return ret;
}

/**Distance from ray-point*/
float D3DXVec3DistanceRayPoint(const D3DXVECTOR3 *rO, const D3DXVECTOR3 *rD, const D3DXVECTOR3 *p){
	D3DXVECTOR3 tmp0 = (*rO)-(*p);
	float tmp1 = D3DXVec3Dot(&tmp0,rD);
	D3DXVECTOR3 tmp2 = (*rD)*tmp1;

	return D3DXVecDistance(&tmp0,&tmp2);
}

/**Distance from ray-point*/
float D3DXVec3DistanceRayPointF(const D3DXVECTOR3 *rO, const D3DXVECTOR3 *rD, const D3DXVECTOR3 *p){
	D3DXVECTOR3 tmp0 = (*p)-(*rO);
	return D3DXVec3Dot(&tmp0,rD);
}

/**D3DXDiffuse*/
D3DXVECTOR3 *D3DXVec3Diffuse(float u1, float u2, D3DXVECTOR3 *out){
	float cosTheta = sqrtf(u1);
	float tmp = 1.0f-cosTheta*cosTheta;
	float sinTheta = tmp>0.0 ? sqrtf(tmp) : 0.0f;

	float phi = C_PI_2*u2;
	
	out->x = sinTheta*cosf(phi);
	out->y = cosTheta;
	out->z = sinTheta*sinf(phi);

	return out;
}

/**D3DXReflect: reflects a direction (dir) against a normal (nor)*/
D3DXVECTOR3 *D3DXVec3Reflect(const D3DXVECTOR3 *dir, const D3DXVECTOR3 *nor, D3DXVECTOR3 *out){
	if(out==NULL)
		out = new D3DXVECTOR3();

	float dotx = 2.0f*D3DXVec3Dot(nor,dir);

	out->x = dir->x - dotx*nor->x;
	out->y = dir->y - dotx*nor->y;
	out->z = dir->z - dotx*nor->z;
	D3DXVec3Normalize(out);

	return out;
}

/**D3DXReflectNeg: reflects a direction (-dir) against a normal (nor)*/
D3DXVECTOR3 *D3DXVec3ReflectNeg(const D3DXVECTOR3 *dir, const D3DXVECTOR3 *nor, D3DXVECTOR3 *out){
	if(out==NULL)
		out = new D3DXVECTOR3();

	float dotx = 2.0f*D3DXVec3Dot(nor,dir);

	out->x = dotx*nor->x-dir->x;
	out->y = dotx*nor->y-dir->y;
	out->z = dotx*nor->z-dir->z;
	D3DXVec3Normalize(out);

	return out;
}

/**D3DXRefract: refracts a directionr (dir) against a normal (nor) with (n1,n2)*/
bool D3DXVec3Refract(const D3DXVECTOR3 *dir,const D3DXVECTOR3 *nor, float n1, float n2, D3DXVECTOR3 *out){
	D3DXVECTOR3 I = (*dir);
	D3DXVECTOR3 N = (*nor);

	float NdotI = D3DXVec3Dot(&N, &I);
	float eta = n1/n2;

	float k = 1.0f - eta*eta * (1.0f - NdotI*NdotI);
	if(k<=0.0f){
		#ifdef D3DX_TOTAL_REFRACTION_OFF
			*out = *dir;
			return true;
		#else
			D3DXVec3Reflect(&I,&N,out);
			return false;
		#endif
	}else{
		*out =  I*eta - N*(sqrtf(k) + eta * NdotI);
		return true;
	}
}

/**D3DXRefract: refracts a directionr (-dir) against a normal (nor) with (n1,n2)*/
bool D3DXVec3RefractNeg(const D3DXVECTOR3 *dir,const D3DXVECTOR3 *nor, float n1, float n2, D3DXVECTOR3 *out){
	D3DXVECTOR3 I = (*dir);
	D3DXVECTOR3 N = (*nor);

	float NdotI = - D3DXVec3Dot(&N, &I);
	float eta = n1/n2;

	float k = 1.0f - eta*eta * (1.0f - NdotI*NdotI);
	if(k<=0.0f){
		#ifdef D3DX_TOTAL_REFRACTION_OFF
			*out = *dir;
			return true;
		#else
			D3DXVec3ReflectNeg(&I,&N,out);
			return false;
		#endif
	}else{
		*out =  - I*eta - N*(sqrtf(k) + eta*NdotI);
		return true;
	}
}
#endif
