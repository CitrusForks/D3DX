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

#ifndef FUNCTIONS_D3DXCOORDSYS
#define FUNCTIONS_D3DXCOORDSYS

#include "math_constant.h"
#include "D3DXVECTOR2.h"
#include "D3DXVECTOR3.h"

#define D3DX_COORDSYS_EPSILON 1e-6f

/**Convert a D3DXVECTOR3 direction into (theta,phi) direction*/
D3DXVECTOR2 *D3DXVecToAng(const D3DXVECTOR3 *dir, D3DXVECTOR2 *out){

	#ifdef GRT_POINTER_OUT_CHECK
		if(out==NULL)
			out = new D3DXVECTOR2();
	#endif

	out->x = acosf( dir->y);
	out->y = atan2f(dir->z, dir->x);

	return out;
};

/**Convert a D3DXVECTOR3 direction into (theta,phi) direction*/
D3DXVECTOR2 *D3DXVecToTexCoord(const D3DXVECTOR3 *dir, D3DXVECTOR2 *out){
	if(out==NULL)
		out = new D3DXVECTOR2();

	//(theta,phi)->(y,x)
	out->x = 1.0f-((atan2f(dir->z,-dir->x)*C_INV_PI)*0.5f+0.5f);
	out->y = (acosf(dir->y)*C_INV_PI);

	return out;
};

/**Convert a (theta,phi) direction into a D3DXVECTOR3 direction*/
D3DXVECTOR3 *D3DXAngToVec(const D3DXVECTOR2 *dir, D3DXVECTOR3 *out){
	#ifdef GRT_POINTER_OUT_CHECK
		if(out==NULL)
			out = new D3DXVECTOR3();
	#endif

	float sinTheta = sinf(dir->x);
	out->x = cosf(dir->y)*sinTheta;
	out->y = cosf(dir->x);
	out->z = sinf(dir->y)*sinTheta;

	return out;
};

/**D3DXPixelToVec: Conversion from pixel position (x,y) to D3DXVECTOR3*/
inline D3DXVECTOR3 *D3DXImgCoordToVec(float x, float y, int width, int height, D3DXVECTOR3 *out){
	if(out == NULL)
		out = new D3DXVECTOR3();

	float phi   = (C_PI_2*x)/float(width);
	float theta = (C_PI  *y)/float(height);

	float sinTheta=sinf(theta);

	out->x = sinTheta*cosf(phi);
	out->y = cosf(theta);
	out->z = sinTheta*sinf(phi);

	return out;
};

/**Create an orthonormal base from a vector*/
void CreateOrthoNormalBase(const D3DXVECTOR3 *n, D3DXVECTOR3 *u, D3DXVECTOR3 *v){
	if(fabsf(n->z)>D3DX_COORDSYS_EPSILON){
		v->x= 0.0f;
		v->y= n->z;
		v->z=-n->y;
	}
	else{
		if(fabsf(n->x)>D3DX_COORDSYS_EPSILON){
			v->x= n->z;
			v->y= 0.0f;
			v->z= -n->x;
		}
		else{
			v->x= n->y;
			v->y= 0.0f;
			v->z= 0.0f;
		}
	}
	D3DXVec3Normalize(v);
	D3DXVec3Cross(u,v,n);
	
	//NOTE: This should not be required
	D3DXVec3Normalize(u);
};

/**Project into a base*/
D3DXVECTOR3 *D3DXVecProjBase(	const D3DXVECTOR3 *V0,
								const D3DXVECTOR3 *V1,
								const D3DXVECTOR3 *V2,
								const D3DXVECTOR3 *pV,
								D3DXVECTOR3 *pOut){
	if(pOut==NULL)
		pOut = new D3DXVECTOR3();

	pOut->x = D3DXVec3Dot(V0,pV);
	pOut->y = D3DXVec3Dot(V1,pV);
	pOut->z = D3DXVec3Dot(V2,pV);

	return pOut;
};

/**Apply a base*/
D3DXVECTOR3 *D3DXVecApplyBase(	const D3DXVECTOR3 *V0,
								const D3DXVECTOR3 *V1,
								const D3DXVECTOR3 *V2,
								const D3DXVECTOR3 *pV,
								D3DXVECTOR3 *pOut){
	if(pOut==NULL)
		pOut = new D3DXVECTOR3();

	*pOut =		(*V0) * pV->x+
				(*V1) * pV->y+
				(*V2) * pV->z;
	return pOut;
};

//Decompression of a normal
void DecompressNormals(D3DXVECTOR3 *n){
	float tmp = 1.0f - n->x*n->x - n->y*n->y;

	if(tmp>=0.0f)
		n->z = sqrtf(tmp);
	else{
		n->z = 0.0f;
		D3DXVec3Normalize(n, n);
	}
};
#endif