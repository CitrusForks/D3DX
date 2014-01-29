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

class D3DXMATRIX
{
public:
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
	
	D3DXMATRIX(){
	}
};

//Print a Matrix
void D3DXMatrixPrintf(const D3DXMATRIX *pM)
{
	printf("\n");
	printf("%3.3f %3.3f %3.3f %3.3f\n",pM->_11,pM->_12,pM->_13,pM->_14);
	printf("%3.3f %3.3f %3.3f %3.3f\n",pM->_21,pM->_22,pM->_23,pM->_24);
	printf("%3.3f %3.3f %3.3f %3.3f\n",pM->_31,pM->_32,pM->_33,pM->_34);
	printf("%3.3f %3.3f %3.3f %3.3f\n",pM->_41,pM->_42,pM->_43,pM->_44);
	printf("\n");
}

//Empty Matrix
D3DXMATRIX *D3DXMatrixEmpty(D3DXMATRIX *pOut){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
		
	pOut->_11=0.0f; pOut->_12=0.0f; pOut->_13=0.0f; pOut->_14=0.0f;
	pOut->_21=0.0f; pOut->_22=0.0f; pOut->_23=0.0f; pOut->_24=0.0f;
	pOut->_31=0.0f; pOut->_32=0.0f; pOut->_33=0.0f; pOut->_34=0.0f;
	pOut->_41=0.0f; pOut->_42=0.0f; pOut->_43=0.0f; pOut->_44=0.0f;
	
	return pOut;
}

//Check empty
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

//Identity Matrix
D3DXMATRIX *D3DXMatrixIdentity(D3DXMATRIX *pOut){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
		
	pOut->_11=1.0f; pOut->_12=0.0f; pOut->_13=0.0f; pOut->_14=0.0f;
	pOut->_21=0.0f; pOut->_22=1.0f; pOut->_23=0.0f; pOut->_24=0.0f;
	pOut->_31=0.0f; pOut->_32=0.0f; pOut->_33=1.0f; pOut->_34=0.0f;
	pOut->_41=0.0f; pOut->_42=0.0f; pOut->_43=0.0f; pOut->_44=1.0f;
	
	return pOut;
}

D3DXMATRIX *D3DXMatrixTranspose(D3DXMATRIX *pOut, const D3DXMATRIX *pM){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
	
	pOut->_11=pM->_11;	pOut->_12=pM->_21;	pOut->_13=pM->_31;	pOut->_14=pM->_41;
	
	pOut->_21=pM->_12;	pOut->_22=pM->_22;	pOut->_23=pM->_32;	pOut->_24=pM->_42;
	
	pOut->_31=pM->_13;	pOut->_32=pM->_23;	pOut->_33=pM->_33;	pOut->_34=pM->_43;
	
	pOut->_41=pM->_14;	pOut->_42=pM->_24;	pOut->_43=pM->_34;	pOut->_44=pM->_44;

	return pOut;
}

//X axis rotation
D3DXMATRIX * D3DXMatrixRotationX(D3DXMATRIX * pOut, float Angle){
	if(pOut==NULL)
		pOut=D3DXMatrixIdentity(pOut);
	else
		D3DXMatrixIdentity(pOut);
	
	float cosAng=cosf(Angle);
	float sinAng=sinf(Angle);
	
	pOut->_22 =  cosAng;
	pOut->_33 =  cosAng;
	pOut->_23 =  sinAng;
	pOut->_32 = -sinAng;
	return pOut;
}
	
//Y axis rotation
D3DXMATRIX * D3DXMatrixRotationY(D3DXMATRIX * pOut, float Angle){
	if(pOut==NULL)
		pOut=D3DXMatrixIdentity(pOut);
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

//Z axis rotation
D3DXMATRIX * D3DXMatrixRotationZ(D3DXMATRIX * pOut, float Angle){
	if(pOut==NULL)
		pOut=D3DXMatrixIdentity(pOut);
	else
		D3DXMatrixIdentity(pOut);

	float cosAng=cosf(Angle);
	float sinAng=sinf(Angle);

	pOut->_11 =  cosAng;
	pOut->_22 =  cosAng;
	pOut->_12 =  sinAng;
	pOut->_21 = -sinAng;
	return pOut;
}

D3DXMATRIX * D3DXMatrixMultiply(D3DXMATRIX * pOut, const D3DXMATRIX * pM1, const D3DXMATRIX * pM2){
	if(pOut==NULL)
		pOut=D3DXMatrixIdentity(pOut);

	pOut->_11=pM1->_11*pM2->_11+pM1->_12*pM2->_21+pM1->_13*pM2->_31+pM1->_14*pM2->_41;
	pOut->_12=pM1->_11*pM2->_12+pM1->_12*pM2->_22+pM1->_13*pM2->_32+pM1->_14*pM2->_42;
	pOut->_13=pM1->_11*pM2->_13+pM1->_12*pM2->_23+pM1->_13*pM2->_33+pM1->_14*pM2->_43;
	pOut->_14=pM1->_11*pM2->_14+pM1->_12*pM2->_24+pM1->_13*pM2->_34+pM1->_14*pM2->_44;
	pOut->_21=pM1->_21*pM2->_11+pM1->_22*pM2->_21+pM1->_23*pM2->_31+pM1->_24*pM2->_41;
	pOut->_22=pM1->_21*pM2->_12+pM1->_22*pM2->_22+pM1->_23*pM2->_32+pM1->_24*pM2->_42;
	pOut->_23=pM1->_21*pM2->_13+pM1->_22*pM2->_23+pM1->_23*pM2->_33+pM1->_24*pM2->_43;
	pOut->_24=pM1->_21*pM2->_14+pM1->_22*pM2->_24+pM1->_23*pM2->_34+pM1->_24*pM2->_44;
	pOut->_31=pM1->_31*pM2->_11+pM1->_32*pM2->_21+pM1->_33*pM2->_31+pM1->_34*pM2->_41;
	pOut->_32=pM1->_31*pM2->_12+pM1->_32*pM2->_22+pM1->_33*pM2->_32+pM1->_34*pM2->_42;
	pOut->_33=pM1->_31*pM2->_13+pM1->_32*pM2->_23+pM1->_33*pM2->_33+pM1->_34*pM2->_43;
	pOut->_34=pM1->_31*pM2->_14+pM1->_32*pM2->_24+pM1->_33*pM2->_34+pM1->_34*pM2->_44;
	pOut->_41=pM1->_41*pM2->_11+pM1->_42*pM2->_21+pM1->_43*pM2->_31+pM1->_44*pM2->_41;
	pOut->_42=pM1->_41*pM2->_12+pM1->_42*pM2->_22+pM1->_43*pM2->_32+pM1->_44*pM2->_42;
	pOut->_43=pM1->_41*pM2->_13+pM1->_42*pM2->_23+pM1->_43*pM2->_33+pM1->_44*pM2->_43;
	pOut->_44=pM1->_41*pM2->_14+pM1->_42*pM2->_24+pM1->_43*pM2->_34+pM1->_44*pM2->_44;

	return pOut;
}

D3DXVECTOR3 * D3DXVec3TransformCoord(D3DXVECTOR3 * pOut, const D3DXVECTOR3 * pV, const D3DXMATRIX * pM){

	if(pOut==NULL)
		pOut=new D3DXVECTOR3();

	float w;
	pOut->x= pV->x*pM->_11 + pV->y*pM->_21 + pV->z*pM->_31 + pM->_41;
	pOut->y= pV->x*pM->_12 + pV->y*pM->_22 + pV->z*pM->_32 + pM->_42;
	pOut->z= pV->x*pM->_13 + pV->y*pM->_23 + pV->z*pM->_33 + pM->_43;
	w =      pV->x*pM->_14 + pV->y*pM->_24 + pV->z*pM->_34 + pM->_44;

	pOut->x/=w;
	pOut->y/=w;
	pOut->z/=w;

	return pOut;
}

D3DXVECTOR4 * D3DXVec3Transform(D3DXVECTOR4 * pOut, const D3DXVECTOR3 * pV, const D3DXMATRIX * pM){
	
	if(pOut==NULL)
		pOut = new D3DXVECTOR4();

	pOut->x= pV->x*pM->_11 + pV->y*pM->_21 + pV->z*pM->_31 + pM->_41;
	pOut->y= pV->x*pM->_12 + pV->y*pM->_22 + pV->z*pM->_32 + pM->_42;
	pOut->z= pV->x*pM->_13 + pV->y*pM->_23 + pV->z*pM->_33 + pM->_43;
	pOut->w= pV->x*pM->_14 + pV->y*pM->_24 + pV->z*pM->_34 + pM->_44;

	return pOut;
}

D3DXVECTOR3 * D3DXVec3TransformNormal(D3DXVECTOR3 * pOut, const D3DXVECTOR3 * pV, const D3DXMATRIX * pM){
	if(pOut==NULL)
		pOut=new D3DXVECTOR3();

	pOut->x= pV->x*pM->_11 + pV->y*pM->_21 + pV->z*pM->_31;
	pOut->y= pV->x*pM->_12 + pV->y*pM->_22 + pV->z*pM->_32;
	pOut->z= pV->x*pM->_13 + pV->y*pM->_23 + pV->z*pM->_33;
	return pOut;
}

//Create a rotation matrix from a Quaternion
D3DXMATRIX *D3DXMatrixRotationQuaternion(D3DXMATRIX * pOut, const D3DXQUATERNION * pQ){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();

	D3DXMatrixIdentity(pOut);

	float qx2 = pQ->x*pQ->x;
	float qy2 = pQ->y*pQ->y;
	float qz2 = pQ->z*pQ->z;

	pOut->_11=1.0f-2.0f*(qz2+qy2);				pOut->_12=2.0f*(pQ->x*pQ->y-pQ->w*pQ->z);		pOut->_13=2.0f*(pQ->x*pQ->z+pQ->w*pQ->y);

	pOut->_21=2.0f*(pQ->x*pQ->y+pQ->w*pQ->z);	pOut->_22=1.0f-2.0f*(qx2+qz2);					pOut->_23=2.0f*(pQ->y*pQ->z-pQ->w*pQ->x);

	pOut->_31=2.0f*(pQ->x*pQ->z-pQ->w*pQ->y);	pOut->_32=2.0f*(pQ->y*pQ->z+pQ->w*pQ->x);		pOut->_33=1.0f-2.0f*(qx2+qy2);

	return pOut;
}

D3DXMATRIX *D3DXMatrixTranslation(D3DXMATRIX *pOut, float x, float y, float z){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();

	D3DXMatrixIdentity(pOut);

	pOut->_41=x;
	pOut->_42=y;
	pOut->_43=z;

	return pOut;
}

//View Matrix: left-handed
D3DXMATRIX* D3DXMatrixLookAtLH( D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt, const D3DXVECTOR3 *pUp ){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
		
	D3DXVECTOR3 x,y,z;
	z.x=pAt->x-pEye->x;
	z.y=pAt->y-pEye->y;
	z.z=pAt->z-pEye->z;
	
	D3DXVec3Normalize(&z);

	D3DXVec3Cross(&x,pUp,&z);
	D3DXVec3Normalize(&x);

	D3DXVec3Cross(&y,&z,&x);

	pOut->_11=x.x;						pOut->_12=y.x;						pOut->_13=z.x;						pOut->_14=0.0f;
	pOut->_21=x.y;						pOut->_22=y.y;						pOut->_23=z.y;						pOut->_24=0.0f;
	pOut->_31=x.z;						pOut->_32=y.z;						pOut->_33=z.z;						pOut->_34=0.0f;
	pOut->_41=-D3DXVec3Dot(&x,pEye);	pOut->_42=-D3DXVec3Dot(&y,pEye);	pOut->_43=-D3DXVec3Dot(&z,pEye);	pOut->_44=1.0f;
	
	return pOut;
}

//View Matrix: right-handed; TODO: check if it is correct
D3DXMATRIX* D3DXMatrixLookAtRH( D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt, const D3DXVECTOR3 *pUp ){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
		
	D3DXVECTOR3 x,y,z;
	z.x=pAt->x-pEye->x;
	z.y=pAt->y-pEye->y;
	z.z=pAt->z-pEye->z;
	
	D3DXVec3Normalize(&z);

	D3DXVec3Cross(&x,&z,pUp);
	D3DXVec3Normalize(&x);

	D3DXVec3Cross(&y,&x,&z);

	pOut->_11=x.x;						pOut->_12=y.x;						pOut->_13=z.x;						pOut->_14=0.0f;
	pOut->_21=x.y;						pOut->_22=y.y;						pOut->_23=z.y;						pOut->_24=0.0f;
	pOut->_31=x.z;						pOut->_32=y.z;						pOut->_33=z.z;						pOut->_34=0.0f;
	pOut->_41=D3DXVec3Dot(&x,pEye);		pOut->_42=D3DXVec3Dot(&y,pEye);		pOut->_43=D3DXVec3Dot(&z,pEye);		pOut->_44=1.0f;
	
	return pOut;
}

//Perspective Matrix: left-handed
D3DXMATRIX* D3DXMatrixPerspectiveFovLH( D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf ){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
		
	D3DXMatrixIdentity(pOut);

	float f=1.0f/tanf(fovy*0.5f);
	float d=(zf-zn);
	pOut->_11=f/Aspect;
	pOut->_22=f;
	pOut->_33=zf/d;
	pOut->_44=0.0f;
	pOut->_43=-zn*zf/d;
	pOut->_34=1.0f;
	return pOut;
}

//Perspective Matrix: right-handed
D3DXMATRIX* D3DXMatrixPerspectiveFovRH( D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf ){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
		
	D3DXMatrixIdentity(pOut);

	float f=1.0f/tanf(fovy*0.5f);
	float d=(zn-zf);

	pOut->_11=f/Aspect;
	pOut->_22=f;
	pOut->_33=zf/d;
	pOut->_44=0.0f;
	pOut->_43=zn*zf/d;
	pOut->_34=-1.0f;
	return pOut;
}

//Orthographic Matrix: left-handed
D3DXMATRIX *D3DXMatrixOrthoLH(D3DXMATRIX * pOut, float w, float h, float zn, float zf){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
		
	D3DXMatrixIdentity(pOut);

	float d=zf-zn;

	pOut->_11=2.0f/float(w);
	pOut->_22=2.0f/float(h);
	pOut->_33=1.0f/d;
	pOut->_43=-zn/d;
	
	return pOut;
}

//Orthographic Matrix: right-handed
D3DXMATRIX *D3DXMatrixOrthoRH(D3DXMATRIX * pOut, float w, float h, float zn, float zf){
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
		
	D3DXMatrixIdentity(pOut);

	float d=zn-zf;

	pOut->_11=2.0f/float(w);
	pOut->_22=2.0f/float(h);
	pOut->_33=1.0f/d;
	pOut->_43=zn/d;
	
	return pOut;
}
/*D3DXMATRIX* D3DXMATRIXMultiply( D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2 )
{
	return NULL;
}

D3DXMATRIX* D3DXMATRIXRotationQuaternion( D3DXMATRIX *pOut, const D3DXQUATERNION *pQ)
{
	return NULL;
}


D3DXVECTOR4* D3DXVec3Transform( D3DXVECTOR4 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM )
{
	return NULL;
}*/

//Inverse of a Matrix using partition method
//TO DO: BUG when A0 determinant is 0
//TO DO: another bug when inverting rotational matricies!!!
D3DXMATRIX* D3DXMatrixInverse(D3DXMATRIX *pOut, float *pDeterminant, const D3DXMATRIX *pM)
{
	if(pOut==NULL)
		pOut=new D3DXMATRIX();
	
	D3DXMATRIX2X2 A0 = D3DXMATRIX2X2(pM->_11,pM->_12,pM->_21,pM->_22);
	D3DXMATRIX2X2 A1 = D3DXMATRIX2X2(pM->_13,pM->_14,pM->_23,pM->_24);
	D3DXMATRIX2X2 A2 = D3DXMATRIX2X2(pM->_31,pM->_32,pM->_41,pM->_42);
	D3DXMATRIX2X2 A3 = D3DXMATRIX2X2(pM->_33,pM->_34,pM->_43,pM->_44);
	
	D3DXMATRIX2X2 *InvA0   = A0.Inverse();
	D3DXMATRIX2X2 *A2InvA0 = A2.Mul(InvA0);
	D3DXMATRIX2X2 *InvA0A1 = InvA0->Mul(&A1);

	//Calculate B3
	D3DXMATRIX2X2 *B3 = A3.Sub(A2InvA0->Mul(&A1));
	B3 = B3->Inverse();

	//Calculate B2=-(InvA3-A2)*B0)
	D3DXMATRIX2X2 *B2 = B3->Mul(A2InvA0);
	B2->Negate();
	
	//Calculate B0
	D3DXMATRIX2X2 *B0 = InvA0->Sub(InvA0A1->Mul(B2));

	//Calculate B1=-B0*(A1*InvA3)
	D3DXMATRIX2X2 *B1 = InvA0A1->Mul(B3);
	B1->Negate();
		
	//Copying the blocks to the final result
	pOut->_11=NegZero(B0->data[0][0]); pOut->_12=NegZero(B0->data[0][1]);
	pOut->_21=NegZero(B0->data[1][0]); pOut->_22=NegZero(B0->data[1][1]);

	pOut->_13=NegZero(B1->data[0][0]); pOut->_14=NegZero(B1->data[0][1]);
	pOut->_23=NegZero(B1->data[1][0]); pOut->_24=NegZero(B1->data[1][1]);

	pOut->_31=NegZero(B2->data[0][0]); pOut->_32=NegZero(B2->data[0][1]);
	pOut->_41=NegZero(B2->data[1][0]); pOut->_42=NegZero(B2->data[1][1]);

	pOut->_33=NegZero(B3->data[0][0]); pOut->_34=NegZero(B3->data[0][1]);
	pOut->_43=NegZero(B3->data[1][0]); pOut->_44=NegZero(B3->data[1][1]);
		
	return pOut;
}

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

void D3DXMatrixTestFunction(){
	D3DXMATRIX m,mOut;
	
	D3DXMatrixIdentity(&m);
//	m.Translate(1.0f,-4.0f,10.0f);
	
	D3DXMatrixRotationX(&m,2.4f);
	D3DXMatrixPrintf(&m);
	D3DXMatrixInverse(&mOut,NULL,&m);
	D3DXMatrixPrintf(&mOut);

	D3DXMatrixRotationY(&m,-1.4f);
	D3DXMatrixPrintf(&m);
	D3DXMatrixInverse(&mOut,NULL,&m);
	D3DXMatrixPrintf(&mOut);
	
	D3DXMatrixRotationZ(&m,0.9f);
	D3DXMatrixPrintf(&m);
	D3DXMatrixInverse(&mOut,NULL,&m);
	D3DXMatrixPrintf(&mOut);
}
#endif