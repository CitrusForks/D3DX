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

#ifndef CLASS_D3DXMATRIX
#define CLASS_D3DXMATRIX

#include "D3DXVECTOR3.h"
#include "D3DXVECTOR4.h"
#include "D3DXQUATERNION.h"
#include "D3DXPLANE.h"
#include "D3DXMATRIX2X2.h"

#include "math_util.h"

class D3DXMATRIX
{
public:
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
	
	D3DXMATRIX(){
	}

    // assignment operators
    void operator += ( const D3DXMATRIX &pM){
        _11 += pM._11;
        _12 += pM._12;
        _13 += pM._13;
        _14 += pM._14;

        _21 += pM._21;
        _22 += pM._22;
        _23 += pM._23;
        _24 += pM._24;

        _31 += pM._31;
        _32 += pM._32;
        _33 += pM._33;
        _34 += pM._34;

        _41 += pM._41;
        _42 += pM._42;
        _43 += pM._43;
        _44 += pM._44;
    }

    void operator -= ( const D3DXMATRIX &pM){
        _11 -= pM._11;
        _12 -= pM._12;
        _13 -= pM._13;
        _14 -= pM._14;

        _21 -= pM._21;
        _22 -= pM._22;
        _23 -= pM._23;
        _24 -= pM._24;

        _31 -= pM._31;
        _32 -= pM._32;
        _33 -= pM._33;
        _34 -= pM._34;

        _41 -= pM._41;
        _42 -= pM._42;
        _43 -= pM._43;
        _44 -= pM._44;
    }

    void operator *= ( float v){
        _11 *= v;
        _12 *= v;
        _13 *= v;
        _14 *= v;

        _21 *= v;
        _22 *= v;
        _23 *= v;
        _24 *= v;

        _31 *= v;
        _32 *= v;
        _33 *= v;
        _34 *= v;

        _41 *= v;
        _42 *= v;
        _43 *= v;
        _44 *= v;
    }

    void operator /= ( float v){
        _11 /= v;
        _12 /= v;
        _13 /= v;
        _14 /= v;

        _21 /= v;
        _22 /= v;
        _23 /= v;
        _24 /= v;

        _31 /= v;
        _32 /= v;
        _33 /= v;
        _34 /= v;

        _41 /= v;
        _42 /= v;
        _43 /= v;
        _44 /= v;
    }

    D3DXMATRIX operator - () const{
        D3DXMATRIX pOut;

        pOut._11 = -_11;
        pOut._12 = -_12;
        pOut._13 = -_13;
        pOut._14 = -_14;

        pOut._21 = -_21;
        pOut._22 = -_22;
        pOut._23 = -_23;
        pOut._24 = -_24;

        pOut._31 = -_31;
        pOut._32 = -_32;
        pOut._33 = -_33;
        pOut._34 = -_34;

        pOut._41 = -_41;
        pOut._42 = -_42;
        pOut._43 = -_43;
        pOut._44 = -_44;
        
        return pOut;
    }

    // binary operators
    D3DXMATRIX operator + ( const D3DXMATRIX &pM) const{
        D3DXMATRIX pOut;

        pOut._11 = _11 + pM._11;
        pOut._12 = _12 + pM._12;
        pOut._13 = _13 + pM._13;
        pOut._14 = _14 + pM._14;

        pOut._21 = _21 + pM._21;
        pOut._22 = _22 + pM._22;
        pOut._23 = _23 + pM._23;
        pOut._24 = _24 + pM._24;

        pOut._31 = _31 + pM._31;
        pOut._32 = _32 + pM._32;
        pOut._33 = _33 + pM._33;
        pOut._34 = _34 + pM._34;

        pOut._41 = _41 + pM._41;
        pOut._42 = _42 + pM._42;
        pOut._43 = _43 + pM._43;
        pOut._44 = _44 + pM._44;

        return pOut;
    }

    D3DXMATRIX operator - ( const D3DXMATRIX  &pM) const{
        D3DXMATRIX pOut;

        pOut._11 = _11 - pM._11;
        pOut._12 = _12 - pM._12;
        pOut._13 = _13 - pM._13;
        pOut._14 = _14 - pM._14;

        pOut._21 = _21 - pM._21;
        pOut._22 = _22 - pM._22;
        pOut._23 = _23 - pM._23;
        pOut._24 = _24 - pM._24;

        pOut._31 = _31 - pM._31;
        pOut._32 = _32 - pM._32;
        pOut._33 = _33 - pM._33;
        pOut._34 = _34 - pM._34;

        pOut._41 = _41 - pM._41;
        pOut._42 = _42 - pM._42;
        pOut._43 = _43 - pM._43;
        pOut._44 = _44 - pM._44;

        return pOut;
    }

    D3DXMATRIX operator * ( float v) const{
        D3DXMATRIX pOut;

        pOut._11 = _11 * v;
        pOut._12 = _12 * v;
        pOut._13 = _13 * v;
        pOut._14 = _14 * v;

        pOut._21 = _21 * v;
        pOut._22 = _22 * v;
        pOut._23 = _23 * v;
        pOut._24 = _24 * v;

        pOut._31 = _31 * v;
        pOut._32 = _32 * v;
        pOut._33 = _33 * v;
        pOut._34 = _34 * v;

        pOut._41 = _41 * v;
        pOut._42 = _42 * v;
        pOut._43 = _43 * v;
        pOut._44 = _44 * v;

        return pOut;
    }

    D3DXMATRIX operator / ( float v) const{
        D3DXMATRIX pOut;

        pOut._11 = _11 / v;
        pOut._12 = _12 / v;
        pOut._13 = _13 / v;
        pOut._14 = _14 / v;

        pOut._21 = _21 / v;
        pOut._22 = _22 / v;
        pOut._23 = _23 / v;
        pOut._24 = _24 / v;

        pOut._31 = _31 / v;
        pOut._32 = _32 / v;
        pOut._33 = _33 / v;
        pOut._34 = _34 / v;

        pOut._41 = _41 / v;
        pOut._42 = _42 / v;
        pOut._43 = _43 / v;
        pOut._44 = _44 / v;

        return pOut;

    }
};

/**D3DXMatrixPrintf: outputs a D3DXMATRIX*/
void D3DXMatrixPrintf(const D3DXMATRIX *pM){
	printf("\n");
	printf("%3.3f %3.3f %3.3f %3.3f\n",pM->_11,pM->_12,pM->_13,pM->_14);
	printf("%3.3f %3.3f %3.3f %3.3f\n",pM->_21,pM->_22,pM->_23,pM->_24);
	printf("%3.3f %3.3f %3.3f %3.3f\n",pM->_31,pM->_32,pM->_33,pM->_34);
	printf("%3.3f %3.3f %3.3f %3.3f\n",pM->_41,pM->_42,pM->_43,pM->_44);
	printf("\n");
}

/**D3DXMatrixEmpty: creates an empty D3DXMATRIX*/
D3DXMATRIX *D3DXMatrixEmpty(D3DXMATRIX *pOut){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
		
	pOut->_11=0.0f; pOut->_12=0.0f; pOut->_13=0.0f; pOut->_14=0.0f;
	pOut->_21=0.0f; pOut->_22=0.0f; pOut->_23=0.0f; pOut->_24=0.0f;
	pOut->_31=0.0f; pOut->_32=0.0f; pOut->_33=0.0f; pOut->_34=0.0f;
	pOut->_41=0.0f; pOut->_42=0.0f; pOut->_43=0.0f; pOut->_44=0.0f;
	
	return pOut;
}

/**D3DXMatrickNotEmpty: checks if the matrix does not have zeros*/
bool D3DXMatrickNotEmpty(const D3DXMATRIX *pM){
	float acc;

	acc  = fabsf(pM->_11);
	acc += fabsf(pM->_12);
	acc += fabsf(pM->_13);
	acc += fabsf(pM->_14);

	acc += fabsf(pM->_21);
	acc += fabsf(pM->_22);
	acc += fabsf(pM->_23);
	acc += fabsf(pM->_24);

	acc += fabsf(pM->_31);
	acc += fabsf(pM->_32);
	acc += fabsf(pM->_33);
	acc += fabsf(pM->_34);

	acc += fabsf(pM->_41);
	acc += fabsf(pM->_42);
	acc += fabsf(pM->_43);
	acc += fabsf(pM->_44);

	return (acc>0.0f);
}

/**D3DXMatrixIdentity: creates an idetntiy matrix*/
D3DXMATRIX *D3DXMatrixIdentity(D3DXMATRIX *pOut){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
		
    pOut->_11 = 1.0f;
    pOut->_12 = 0.0f;
    pOut->_13 = 0.0f;
    pOut->_14 = 0.0f;
	
    pOut->_21 = 0.0f;
    pOut->_22 = 1.0f;
    pOut->_23 = 0.0f;
    pOut->_24 = 0.0f;
	
    pOut->_31 = 0.0f;
    pOut->_32 = 0.0f;
    pOut->_33 = 1.0f;
    pOut->_34 = 0.0f;
	
    pOut->_41 = 0.0f;
    pOut->_42 = 0.0f;
    pOut->_43 = 0.0f;
    pOut->_44 = 1.0f;
	
	return pOut;
}

/**D3DXMatrixTranspose: transposes a matrix*/
D3DXMATRIX *D3DXMatrixTranspose(D3DXMATRIX *pOut, const D3DXMATRIX *pM){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
	
    pOut->_11 = pM->_11;
    pOut->_12 = pM->_21;
    pOut->_13 = pM->_31;
    pOut->_14 = pM->_41;
	
	pOut->_21 = pM->_12;
    pOut->_22 = pM->_22;
    pOut->_23 = pM->_32;
    pOut->_24 = pM->_42;
	
	pOut->_31 = pM->_13;
    pOut->_32 = pM->_23;
    pOut->_33 = pM->_33;
    pOut->_34 = pM->_43;
	
	pOut->_41 = pM->_14;
    pOut->_42 = pM->_24;
    pOut->_43 = pM->_34;
    pOut->_44 = pM->_44;

	return pOut;
}

/**D3DXMatrixRotationX: creates a rotation matrix on the X axis*/
D3DXMATRIX * D3DXMatrixRotationX(D3DXMATRIX * pOut, float Angle){
	if(pOut==NULL)
		pOut=D3DXMatrixIdentity(pOut);
	else
		D3DXMatrixIdentity(pOut);
	
	float cosAng = cosf(Angle);
	float sinAng = sinf(Angle);
	
	pOut->_22 =  cosAng;
	pOut->_33 =  cosAng;
	pOut->_23 =  sinAng;
	pOut->_32 = -sinAng;
	return pOut;
}
	
/**D3DXMatrixRotationY: creates a rotation matrix on the Y axis*/
D3DXMATRIX * D3DXMatrixRotationY(D3DXMATRIX * pOut, float Angle){
	if(pOut==NULL)
		pOut = D3DXMatrixIdentity(pOut);
	else
		D3DXMatrixIdentity(pOut);

	float cosAng=cosf(Angle);
	float sinAng=sinf(Angle);
	
	pOut->_11 =  cosAng;
	pOut->_33 =  cosAng;
	pOut->_13 = -sinAng;
	pOut->_31 =  sinAng;
	return pOut;
}

/**D3DXMatrixRotationZ: creates a rotation matrix on the Z axis*/
D3DXMATRIX * D3DXMatrixRotationZ(D3DXMATRIX * pOut, float Angle){
	if(pOut==NULL)
		pOut = D3DXMatrixIdentity(pOut);
	else
		D3DXMatrixIdentity(pOut);

	float cosAng = cosf(Angle);
	float sinAng = sinf(Angle);

	pOut->_11 =  cosAng;
	pOut->_22 =  cosAng;
	pOut->_12 =  sinAng;
	pOut->_21 = -sinAng;
	return pOut;
}

/**D3DXMatrixMultiply: mul operator between matricies*/
D3DXMATRIX * D3DXMatrixMultiply(D3DXMATRIX * pOut, const D3DXMATRIX * pM1, const D3DXMATRIX * pM2){
	if(pOut==NULL)
		pOut = D3DXMatrixIdentity(pOut);

	pOut->_11 = pM1->_11*pM2->_11+pM1->_12*pM2->_21+pM1->_13*pM2->_31+pM1->_14*pM2->_41;
	pOut->_12 = pM1->_11*pM2->_12+pM1->_12*pM2->_22+pM1->_13*pM2->_32+pM1->_14*pM2->_42;
	pOut->_13 = pM1->_11*pM2->_13+pM1->_12*pM2->_23+pM1->_13*pM2->_33+pM1->_14*pM2->_43;
	pOut->_14 = pM1->_11*pM2->_14+pM1->_12*pM2->_24+pM1->_13*pM2->_34+pM1->_14*pM2->_44;
	pOut->_21 = pM1->_21*pM2->_11+pM1->_22*pM2->_21+pM1->_23*pM2->_31+pM1->_24*pM2->_41;
	pOut->_22 = pM1->_21*pM2->_12+pM1->_22*pM2->_22+pM1->_23*pM2->_32+pM1->_24*pM2->_42;
	pOut->_23 = pM1->_21*pM2->_13+pM1->_22*pM2->_23+pM1->_23*pM2->_33+pM1->_24*pM2->_43;
	pOut->_24 = pM1->_21*pM2->_14+pM1->_22*pM2->_24+pM1->_23*pM2->_34+pM1->_24*pM2->_44;
	pOut->_31 = pM1->_31*pM2->_11+pM1->_32*pM2->_21+pM1->_33*pM2->_31+pM1->_34*pM2->_41;
	pOut->_32 = pM1->_31*pM2->_12+pM1->_32*pM2->_22+pM1->_33*pM2->_32+pM1->_34*pM2->_42;
	pOut->_33 = pM1->_31*pM2->_13+pM1->_32*pM2->_23+pM1->_33*pM2->_33+pM1->_34*pM2->_43;
	pOut->_34 = pM1->_31*pM2->_14+pM1->_32*pM2->_24+pM1->_33*pM2->_34+pM1->_34*pM2->_44;
	pOut->_41 = pM1->_41*pM2->_11+pM1->_42*pM2->_21+pM1->_43*pM2->_31+pM1->_44*pM2->_41;
	pOut->_42 = pM1->_41*pM2->_12+pM1->_42*pM2->_22+pM1->_43*pM2->_32+pM1->_44*pM2->_42;
	pOut->_43 = pM1->_41*pM2->_13+pM1->_42*pM2->_23+pM1->_43*pM2->_33+pM1->_44*pM2->_43;
	pOut->_44 = pM1->_41*pM2->_14+pM1->_42*pM2->_24+pM1->_43*pM2->_34+pM1->_44*pM2->_44;

	return pOut;
}

/**D3DXVec3TransformCoord: applies a matrix to a vector; including division by w*/
D3DXVECTOR3 * D3DXVec3TransformCoord(D3DXVECTOR3 * pOut, const D3DXVECTOR3 * pV, const D3DXMATRIX * pM){

	if(pOut==NULL)
		pOut = new D3DXVECTOR3();

	float w;
	pOut->x = pV->x*pM->_11 + pV->y*pM->_21 + pV->z*pM->_31 + pM->_41;
	pOut->y = pV->x*pM->_12 + pV->y*pM->_22 + pV->z*pM->_32 + pM->_42;
	pOut->z = pV->x*pM->_13 + pV->y*pM->_23 + pV->z*pM->_33 + pM->_43;
	w       = pV->x*pM->_14 + pV->y*pM->_24 + pV->z*pM->_34 + pM->_44;

	pOut->x /= w;
	pOut->y /= w;
	pOut->z /= w;

	return pOut;
}

/**D3DXVec3Transform: applies a matrix to a vector*/
D3DXVECTOR4 * D3DXVec3Transform(D3DXVECTOR4 * pOut, const D3DXVECTOR3 * pV, const D3DXMATRIX * pM){
	
	if(pOut==NULL)
		pOut = new D3DXVECTOR4();

	pOut->x = pV->x*pM->_11 + pV->y*pM->_21 + pV->z*pM->_31 + pM->_41;
	pOut->y = pV->x*pM->_12 + pV->y*pM->_22 + pV->z*pM->_32 + pM->_42;
	pOut->z = pV->x*pM->_13 + pV->y*pM->_23 + pV->z*pM->_33 + pM->_43;
	pOut->w = pV->x*pM->_14 + pV->y*pM->_24 + pV->z*pM->_34 + pM->_44;

	return pOut;
}

/**D3DXVec3TransformNormal: applies a matrix to a normal vector*/
D3DXVECTOR3 * D3DXVec3TransformNormal(D3DXVECTOR3 * pOut, const D3DXVECTOR3 * pV, const D3DXMATRIX * pM){
	if(pOut==NULL)
		pOut=new D3DXVECTOR3();

	pOut->x = pV->x*pM->_11 + pV->y*pM->_21 + pV->z*pM->_31;
	pOut->y = pV->x*pM->_12 + pV->y*pM->_22 + pV->z*pM->_32;
	pOut->z = pV->x*pM->_13 + pV->y*pM->_23 + pV->z*pM->_33;
	return pOut;
}

/**D3DXMatrixRotationQuaternion: creates a rotation matrix based on a quatertion*/
D3DXMATRIX *D3DXMatrixRotationQuaternion(D3DXMATRIX * pOut, const D3DXQUATERNION * pQ){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();

	D3DXMatrixIdentity(pOut);

	float qx2 = pQ->x*pQ->x;
	float qy2 = pQ->y*pQ->y;
	float qz2 = pQ->z*pQ->z;

    pOut->_11 = 1.0f-2.0f*(qz2+qy2);
    pOut->_12 = 2.0f*(pQ->x*pQ->y-pQ->w*pQ->z);
    pOut->_13 = 2.0f*(pQ->x*pQ->z+pQ->w*pQ->y);

    pOut->_21 = 2.0f*(pQ->x*pQ->y+pQ->w*pQ->z);
    pOut->_22 = 1.0f-2.0f*(qx2+qz2);
    pOut->_23 = 2.0f*(pQ->y*pQ->z-pQ->w*pQ->x);

    pOut->_31 = 2.0f*(pQ->x*pQ->z-pQ->w*pQ->y);
    pOut->_32 = 2.0f*(pQ->y*pQ->z+pQ->w*pQ->x);
    pOut->_33 = 1.0f-2.0f*(qx2+qy2);

	return pOut;
}

/**D3DXMatrixTranslation: creates a translation matrix*/
D3DXMATRIX *D3DXMatrixTranslation(D3DXMATRIX *pOut, float x, float y, float z){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();

	D3DXMatrixIdentity(pOut);

	pOut->_41=x;
	pOut->_42=y;
	pOut->_43=z;

	return pOut;
}

/**D3DXMatrixLookAtLH: creates a left-handed view matrix*/
D3DXMATRIX* D3DXMatrixLookAtLH( D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt, const D3DXVECTOR3 *pUp ){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
		
	D3DXVECTOR3 x, y, z;
	z.x = pAt->x - pEye->x;
	z.y = pAt->y - pEye->y;
	z.z = pAt->z - pEye->z;
	
	D3DXVec3Normalize(&z);

	D3DXVec3Cross(&x,pUp,&z);
	D3DXVec3Normalize(&x);

	D3DXVec3Cross(&y,&z,&x);

    pOut->_11 = x.x;
    pOut->_12 = y.x;
    pOut->_13 = z.x;
    pOut->_14 = 0.0f;
	
    pOut->_21 = x.y;
    pOut->_22 = y.y;
    pOut->_23 = z.y;
    pOut->_24 = 0.0f;
	
    pOut->_31 = x.z;
    pOut->_32 = y.z;
    pOut->_33 = z.z;
    pOut->_34 = 0.0f;
	
    pOut->_41 = -D3DXVec3Dot(&x,pEye);
    pOut->_42 = -D3DXVec3Dot(&y,pEye);
    pOut->_43 = -D3DXVec3Dot(&z,pEye);
    pOut->_44 = 1.0f;
	
	return pOut;
}

/**D3DXMatrixLookAtRH: creates a right-handed view matrix*/
D3DXMATRIX* D3DXMatrixLookAtRH( D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt, const D3DXVECTOR3 *pUp ){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
		
	D3DXVECTOR3 x,y,z;
	z.x = pAt->x - pEye->x;
	z.y = pAt->y - pEye->y;
	z.z = pAt->z - pEye->z;
	
	D3DXVec3Normalize(&z);

	D3DXVec3Cross(&x,&z,pUp);
	D3DXVec3Normalize(&x);

	D3DXVec3Cross(&y,&x,&z);

    pOut->_11 = x.x;
    pOut->_12 = y.x;
    pOut->_13 = z.x;	
    pOut->_14 = 0.0f;
	
    pOut->_21 = x.y;
    pOut->_22 = y.y;
    pOut->_23 = z.y;
    pOut->_24 = 0.0f;
	
    pOut->_31 = x.z;
    pOut->_32 = y.z;
    pOut->_33 = z.z;
    pOut->_34 = 0.0f;
	
    pOut->_41 = D3DXVec3Dot(&x,pEye);
    pOut->_42 = D3DXVec3Dot(&y,pEye);
    pOut->_43 = D3DXVec3Dot(&z,pEye);
    pOut->_44 = 1.0f;
	
	return pOut;
}

/**D3DXMatrixPerspectiveFovLH: creates a perspective left-handed matrix*/
D3DXMATRIX* D3DXMatrixPerspectiveFovLH( D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf ){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
		
	D3DXMatrixIdentity(pOut);
     
	float f = 1.0f/tanf(fovy*0.5f);
	float d = zf - zn;

	pOut->_11 = f/Aspect;
	pOut->_22 = f;
	pOut->_33 = zf/d;
	pOut->_44 = 0.0f;
	pOut->_43 = -zn*zf/d;
	pOut->_34 = 1.0f;
	return pOut;
}

/**D3DXMatrixPerspectiveFovRH: creates a perspective right-handed matrix*/
D3DXMATRIX* D3DXMatrixPerspectiveFovRH( D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf ){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
		
	D3DXMatrixIdentity(pOut);

	float f = 1.0f/tanf(fovy*0.5f);
	float d = zn - zf;

	pOut->_11 = f/Aspect;
	pOut->_22 = f;
	pOut->_33 = zf/d;
	pOut->_44 = 0.0f;
	pOut->_43 = zn*zf/d;
	pOut->_34 = -1.0f;
	return pOut;
}

/**D3DXMatrixOrthoLH: creates an orthographic left-handed matrix*/
D3DXMATRIX *D3DXMatrixOrthoLH(D3DXMATRIX * pOut, float w, float h, float zn, float zf){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
		
	D3DXMatrixIdentity(pOut);

	float d = zf-zn;

	pOut->_11 = 2.0f/float(w);
	pOut->_22 = 2.0f/float(h);
	pOut->_33 = 1.0f/d;
	pOut->_43 = -zn/d;
	
	return pOut;
}

/**D3DXMatrixOrthoRH: creates an orthographic right-handed matrix*/
D3DXMATRIX *D3DXMatrixOrthoRH(D3DXMATRIX * pOut, float w, float h, float zn, float zf){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();
		
	D3DXMatrixIdentity(pOut);

	float d = zn-zf;

	pOut->_11 = 2.0f/float(w);
	pOut->_22 = 2.0f/float(h);
	pOut->_33 = 1.0f/d;
	pOut->_43 = zn/d;
	
	return pOut;
}

/**D3DXMatrixTrace: computes the trace of a matrix*/
float D3DXMatrixTrace(const D3DXMATRIX *pM){
    return pM->_11 + pM->_22 + pM->_33 + pM->_44;
}

/**D3DXMatrixDeterminant: computes the determinant of a matrix*/
float D3DXMatrixDeterminant(const D3DXMATRIX *pM){
    return  pM->_11 * pM->_22 * pM->_33 * pM->_44 +
            pM->_11 * pM->_23 * pM->_34 * pM->_42 +
            pM->_11 * pM->_24 * pM->_32 * pM->_43 +

            pM->_12 * pM->_21 * pM->_34 * pM->_43 +
            pM->_12 * pM->_23 * pM->_31 * pM->_44 +
            pM->_12 * pM->_24 * pM->_33 * pM->_41 +

            pM->_13 * pM->_21 * pM->_32 * pM->_44 +
            pM->_13 * pM->_22 * pM->_34 * pM->_41 +
            pM->_13 * pM->_24 * pM->_31 * pM->_42 +

            pM->_14 * pM->_21 * pM->_33 * pM->_42 +
            pM->_14 * pM->_22 * pM->_31 * pM->_43 +
            pM->_14 * pM->_23 * pM->_32 * pM->_41 -(

            pM->_11 * pM->_22 * pM->_34 * pM->_44 +
            pM->_11 * pM->_23 * pM->_32 * pM->_44 +
            pM->_11 * pM->_24 * pM->_33 * pM->_42 +

            pM->_12 * pM->_21 * pM->_33 * pM->_44 +
            pM->_12 * pM->_23 * pM->_34 * pM->_41 +
            pM->_12 * pM->_24 * pM->_32 * pM->_41 +

            pM->_13 * pM->_21 * pM->_34 * pM->_42 +
            pM->_13 * pM->_22 * pM->_31 * pM->_44 +
            pM->_13 * pM->_24 * pM->_32 * pM->_41 +

            pM->_14 * pM->_21 * pM->_32 * pM->_43 +
            pM->_14 * pM->_22 * pM->_33 * pM->_41 +
            pM->_14 * pM->_23 * pM->_31 * pM->_42 );

}


/**D3DXMatrixInversePartition: computes the inverse of a matrix using the partition method*/
D3DXMATRIX* D3DXMatrixInversePartition(D3DXMATRIX *pOut, float *pDeterminant, const D3DXMATRIX *pM){
    //KNOWN ISSUES 0: BUG when A0 determinant is 0
    //KNOWN ISSUES 1: inverting rotational matricies!!!
        
    if(pOut==NULL)
		pOut = new D3DXMATRIX();
	
	D3DXMATRIX2X2 A0 = D3DXMATRIX2X2(pM->_11, pM->_12, pM->_21, pM->_22);
	D3DXMATRIX2X2 A1 = D3DXMATRIX2X2(pM->_13, pM->_14, pM->_23, pM->_24);
	D3DXMATRIX2X2 A2 = D3DXMATRIX2X2(pM->_31, pM->_32, pM->_41, pM->_42);
	D3DXMATRIX2X2 A3 = D3DXMATRIX2X2(pM->_33, pM->_34, pM->_43, pM->_44);
	
    D3DXMATRIX2X2 InvA0, B3;
	
    A0.Inverse(&InvA0);
	D3DXMATRIX2X2 A2InvA0 = A2*InvA0;
	D3DXMATRIX2X2 InvA0A1 = InvA0*A1;

	//Calculate B3
	D3DXMATRIX2X2 tmp = A3 - (A2InvA0*A1);
    tmp.Inverse(&B3);

	//Calculate B2=-(InvA3-A2)*B0)
	D3DXMATRIX2X2 B2 = -(B3*A2InvA0);
	
	//Calculate B0
	D3DXMATRIX2X2 B0 = InvA0 - (InvA0A1*B2);

	//Calculate B1=-B0*(A1*InvA3)
	D3DXMATRIX2X2 B1 = - (InvA0A1 * B3);
		
	//Copying the blocks to the final result
	pOut->_11 = NegZero(B0.data[0]);
    pOut->_12 = NegZero(B0.data[1]);
	
    pOut->_21 = NegZero(B0.data[2]);
    pOut->_22 = NegZero(B0.data[3]);

	pOut->_13 = NegZero(B1.data[0]);
    pOut->_14 = NegZero(B1.data[1]);
	
    pOut->_23 = NegZero(B1.data[2]);
    pOut->_24 = NegZero(B1.data[3]);

	pOut->_31 = NegZero(B2.data[0]);
    pOut->_32 = NegZero(B2.data[1]);
	
    pOut->_41 = NegZero(B2.data[2]);
    pOut->_42 = NegZero(B2.data[2]);

	pOut->_33 = NegZero(B3.data[0]);
    pOut->_34 = NegZero(B3.data[1]);
	
    pOut->_43 = NegZero(B3.data[2]);
    pOut->_44 = NegZero(B3.data[3]);
		
	return pOut;
}

/**D3DXMatrixInverse: computes the inverse of a matrix*/
D3DXMATRIX* D3DXMatrixInverse(D3DXMATRIX *pOut, float *pDeterminant, const D3DXMATRIX *pM){
    return D3DXMatrixInversePartition(pOut, pDeterminant, pM);
}

/**D3DXMatrixToOpenGL: converts the matrix from the D3DXMATRIX format to the OpenGL format*/
float *D3DXMatrixToOpenGL(float *pOut, const D3DXMATRIX *pM){
	if(pOut==NULL)
		pOut=new float[16];

	pOut[0]  = pM->_11;
	pOut[1]  = pM->_12;
	pOut[2]  = pM->_13;
	pOut[3]  = pM->_14;

	pOut[4]  = pM->_21;
	pOut[5]  = pM->_22;
	pOut[6]  = pM->_23;
	pOut[7]  = pM->_24;

	pOut[8]  = pM->_31;
	pOut[9]  = pM->_32;
	pOut[10] = pM->_33;
	pOut[11] = pM->_34;

	pOut[12] = pM->_41;
	pOut[13] = pM->_42;
	pOut[14] = pM->_43;
	pOut[15] = pM->_44;

	return pOut;
}

/**OpenGLToD3DXMatrix: converts the matrix from the OpenGL format to the D3DXMATRIX format*/
D3DXMATRIX *OpenGLToD3DXMatrix(D3DXMATRIX *pOut, float *pM){
	if(pOut==NULL)
		pOut = new D3DXMATRIX();

	pOut->_11 = pM[0];
	pOut->_12 = pM[1];
	pOut->_13 = pM[2];
	pOut->_14 = pM[3];

	pOut->_21 = pM[4];
	pOut->_22 = pM[5];
	pOut->_23 = pM[6];
	pOut->_24 = pM[7];

	pOut->_31 = pM[8];
	pOut->_32 = pM[9];
	pOut->_33 = pM[10];
	pOut->_34 = pM[11];

	pOut->_41 = pM[12];
	pOut->_42 = pM[13];
	pOut->_43 = pM[14];
	pOut->_44 = pM[15];

	return pOut;
}

/**D3DXMatrixExtractPlanes: extracts planes from a view matrix*/
D3DXPLANE *D3DXMatrixExtractPlanes(D3DXPLANE *pOut, D3DXMATRIX *pM){
	if(pOut==NULL)
		pOut = new D3DXPLANE[6];

	//Left
	pOut[0].set(pM->_14+pM->_11, pM->_24+pM->_21, pM->_34+pM->_31, pM->_44+pM->_41);
	//Right
	pOut[1].set(pM->_14-pM->_11, pM->_24-pM->_21, pM->_34-pM->_31, pM->_44-pM->_41);

	//Bottom
	pOut[2].set(pM->_14+pM->_12, pM->_24+pM->_22, pM->_34+pM->_32, pM->_44+pM->_42);
	//Top
	pOut[3].set(pM->_14-pM->_12, pM->_24-pM->_22, pM->_34-pM->_32, pM->_44-pM->_42);

	//Near
	pOut[4].set(pM->_13, pM->_23, pM->_33, pM->_43);
	//Far
	pOut[5].set(pM->_14-pM->_13, pM->_24-pM->_23, pM->_34-pM->_33, pM->_44-pM->_43);

	return pOut;
}

#endif
