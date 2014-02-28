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

#ifndef FUNCTIONS_D3DXFUNCTIONS
#define FUNCTIONS_D3DXFUNCTIONS

#include <math.h>

#include "D3DXVECTOR2.hpp"
#include "D3DXVECTOR3.hpp"
#include "D3DXVECTOR4.hpp"
#include "D3DXQUATERNION.hpp"

//Cross Product
void D3DXVec3Cross(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *A, const D3DXVECTOR3 *B){
	pOut->x = A->y * B->z - B->y * A->z;
	pOut->y = A->z * B->x - B->z * A->x;
	pOut->z = A->x * B->y - B->x * A->y;
}

//Dot product
inline float D3DXVec2Dot(const D3DXVECTOR2 *a, const D3DXVECTOR2 *b){
	return (a->x*b->x+ a->y*b->y);
}

inline float D3DXVec3Dot(const D3DXVECTOR3 *a, const D3DXVECTOR3 *b){
	return (a->x*b->x+ a->y*b->y+ a->z*b->z);
}

inline float D3DXVec4Dot(const D3DXVECTOR4 *a, const D3DXVECTOR4 *b){
	return (a->x*b->x+ a->y*b->y+ a->z*b->z + a->w*b->w);
}

D3DXVECTOR2 *D3DXVec2Normalize(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV){
#ifdef D3DX_NORMALIZATION_POINTER_CHECK
	if(pOut == NULL)
		pOut = new D3DXVECTOR2();
#endif

	float length = (pV->x*pV->x + pV->y*pV->y);
	
	if(length>0.0f){
		length = sqrtf(length);
		pOut->x = pV->x/length;
		pOut->y = pV->y/length;
		return pOut;
	}
	else{
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR2 *D3DXVec2Normalize(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV): Normalization Error!\n");
		#endif
		return pOut;
	}
}

D3DXVECTOR2 *D3DXVec2Normalize(D3DXVECTOR2 *pOut){

	float length = (pOut->x*pOut->x + pOut->y*pOut->y);
	
	if(length>0.0f){
		length = sqrtf(length);
		pOut->x /= length;
		pOut->y /= length;
		return pOut;
	}
	else{
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR2 *D3DXVec2Normalize(D3DXVECTOR2 *pOut): Normalization Error!\n");
		#endif
		return pOut;
	}
}

/**Normalize a D3DXVECTOR3*/
D3DXVECTOR3 *D3DXVec3Normalize(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV){
#ifdef D3DX_NORMALIZATION_POINTER_CHECK
	if(pOut == NULL)
		pOut = new D3DXVECTOR3();
#endif

	float length = (pV->x*pV->x+
					pV->z*pV->z+
					pV->y*pV->y);
	
	if(length>0.0f){
		length = sqrtf(length);
		pOut->x = pV->x/length;
		pOut->y = pV->y/length;
		pOut->z = pV->z/length;
		return pOut;
	}
	else{
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR3 *D3DXVec3Normalize(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV): Normalization Error!\n");
		#endif
		return pOut;
	}
}

/**D3DXVec3Normalize: normalizes a D3DXVECTOR3*/
D3DXVECTOR3 *D3DXVec3Normalize(D3DXVECTOR3 *pOut){
	float length = (pOut->x*pOut->x+
					pOut->z*pOut->z+
					pOut->y*pOut->y);
	
	if(length>0.0f){
		length = sqrtf(length);
		pOut->x /= length;
		pOut->y /= length;
		pOut->z /= length;
		return pOut;
	}
	else{
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR3 *D3DXVec3Normalize(D3DXVECTOR3 *pOut): Normalization Error!\n");
		#endif
		return pOut;
	}
}

/**D3DXVec3Normalize2: normalizes a D3DXVECTOR3 and returns is magnitude*/
float D3DXVec3Normalize2(D3DXVECTOR3 *pOut){
	float length = (pOut->x*pOut->x + pOut->z*pOut->z + pOut->y*pOut->y);
	
	if(length>0.0f){
		length = sqrtf(length);
		pOut->x /= length;
		pOut->y /= length;
		pOut->z /= length;
		return length;
	}
	else
		return 0.0f;
}

/**D3DXVec4Normalize: normalizes a D3DXVECTOR4*/
D3DXVECTOR4 *D3DXVec4Normalize(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV){
#ifdef D3DX_NORMALIZATION_POINTER_CHECK
	if(pOut == NULL)
		pOut = new D3DXVECTOR4();
#endif
	float length = (pV->x*pV->x+
					pV->z*pV->z+
					pV->w*pV->w+
					pV->y*pV->y);
	
	if(length>0.0f){
		length = sqrtf(length);
		pOut->x = pV->x/length;
		pOut->y = pV->y/length;
		pOut->z = pV->z/length;
		pOut->w = pV->w/length;
		return pOut;
	}
	else{
		#ifdef D3DX_DEBUG_POINER_CHECK
			printf("D3DXVECTOR4 *D3DXVec4Normalize(D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV): Normalization Error!\n");
		#endif
		return pOut;
	}
}

/**Length Square*/
float D3DXVec2LengthSq(const D3DXVECTOR2 *pV){
	return	pV->x*pV->x+
			pV->y*pV->y;
}

float D3DXVec3LengthSq(const D3DXVECTOR3 *pV){
	return	pV->x*pV->x+
			pV->z*pV->z+
			pV->y*pV->y;
}

float D3DXVec4LengthSq(const D3DXVECTOR4 *pV){
	return	pV->x*pV->x+
			pV->z*pV->z+
			pV->w*pV->w+
			pV->y*pV->y;
}

/**Length*/
float D3DXVec2Length(const D3DXVECTOR2 *pV){
	return	sqrtf(	pV->x*pV->x+
					pV->y*pV->y);
}

float D3DXVec3Length(const D3DXVECTOR3 *pV){
	return	sqrtf(	pV->x*pV->x+
					pV->z*pV->z+
					pV->y*pV->y);
}

float D3DXVec4Length(const D3DXVECTOR4 *pV){
	return	sqrtf(	pV->x*pV->x+
					pV->z*pV->z+
					pV->w*pV->w+
					pV->y*pV->y);
}

/**Distance*/
float D3DXVecDistance(const D3DXVECTOR2 *a, const D3DXVECTOR2 *b){
	D3DXVECTOR2 c;
	c.x=a->x-b->x;
	c.y=a->y-b->y;
	return sqrtf(c.x*c.x + c.y*c.y);
}

float D3DXVecDistance(const D3DXVECTOR3 *a, const D3DXVECTOR3 *b){
	D3DXVECTOR3 c;
	c.x=a->x-b->x;
	c.y=a->y-b->y;
	c.z=a->z-b->z;
	return sqrtf(c.x*c.x+c.y*c.y+c.z*c.z);
}

/**Squared distance*/
float D3DXVecDistanceSq(const D3DXVECTOR2 *a, const D3DXVECTOR2 *b){
	D3DXVECTOR2 c;
	c.x=a->x-b->x;
	c.y=a->y-b->y;
	return (c.x*c.x+c.y*c.y);
}

float D3DXVecDistanceSq(const D3DXVECTOR3 *a, const D3DXVECTOR3 *b){
	D3DXVECTOR3 c;
	c.x=a->x-b->x;
	c.y=a->y-b->y;
	c.z=a->z-b->z;
	return c.x*c.x+c.y*c.y+c.z*c.z;
}

//Array to Vector
D3DXVECTOR3 D3DXFloat2Vec3(float vec[3]){
	return D3DXVECTOR3(vec[0],vec[1],vec[2]);
}

//Checking for similarity
bool D3DXVec3Similar(const D3DXVECTOR3 *a, const D3DXVECTOR3 *b){
	D3DXVECTOR3 tmp = *a - *b;
	return sqrtf(D3DXVec3Dot(&tmp,&tmp))<1e-12f;
}
#endif