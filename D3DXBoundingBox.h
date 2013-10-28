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

#ifndef FUNCTIONS_D3DXBOUNDINGBOX
#define FUNCTIONS_D3DXBOUNDINGBOX
#include "D3DXVECTOR3.h"

/**D3DXExtendBBox: a bounding box (bMax,bMin) is expanded according p*/
void D3DXExtendBBox(D3DXVECTOR3 *bMax, D3DXVECTOR3 *bMin, const D3DXVECTOR3 *p){
	//Max
	bMax->x = MAX(p->x,bMax->x);
	bMax->y = MAX(p->y,bMax->y);
	bMax->z = MAX(p->z,bMax->z);
	//Min
	bMin->x = MIN(p->x,bMin->x);
	bMin->y = MIN(p->y,bMin->y);
	bMin->z = MIN(p->z,bMin->z);
};

/**D3DXMinBBox: calculates the minimum box*/
void D3DXMinBBox(D3DXVECTOR3 *max, D3DXVECTOR3 *min, const D3DXVECTOR3 *bMax,const D3DXVECTOR3 *bMin){
	if(bMax->x<max->x) max->x=bMax->x;
	if(bMax->y<max->y) max->y=bMax->y;
	if(bMax->z<max->z) max->z=bMax->z;

	if(bMin->x>min->x) min->x=bMin->x;
	if(bMin->y>min->y) min->y=bMin->y;
	if(bMin->z>min->z) min->z=bMin->z;
};

/**D3DXCheckPointBBox: checks if a point p is in a bounding box (bMax,bMin)*/
bool D3DXCheckPointBBox(const D3DXVECTOR2 *bMax, const D3DXVECTOR2 *bMin, const D3DXVECTOR2 *p){
	return((   p->x>=bMin->x)
			&&(p->y>=bMin->y)
			&&(p->x<=bMax->x)
			&&(p->y<=bMax->y));
};

/**D3DXCheckPointBBox: checks if a point p is in a bounding box (bMax,bMin)*/
bool D3DXCheckPointBBox(const D3DXVECTOR3 *bMax, const D3DXVECTOR3 *bMin, const D3DXVECTOR3 *p){
	return((   p->x>=bMin->x)
			&&(p->y>=bMin->y)
			&&(p->z>=bMin->z)
			&&(p->x<=bMax->x)
			&&(p->y<=bMax->y)
			&&(p->z<=bMax->z));
};

/**D3DXCheckPlaneBBox: checks if a plane (nor,d) intersects a bounding box (bMax,bMin)*/
bool D3DXCheckPlaneBBox(const D3DXVECTOR3 *bMax, const D3DXVECTOR3 *bMin, const D3DXVECTOR3 *nor, float d){

	D3DXVECTOR3 vMax, vMin;
	for(int i=0;i<3;i++){
		if((*nor)[i]>0.0f){
			vMax[i] = (*bMax)[i];
			vMin[i] = (*bMin)[i];
		}
		else{
			vMax[i] = (*bMin)[i];
			vMin[i] = (*bMax)[i];
		}
	}

	if((D3DXVec3Dot(nor,&vMax)+d)<0.0f)
		return false;
	
	if((D3DXVec3Dot(nor,&vMin)+d)>0.0f)
		return false;
	else
		return true;
};

/**D3DXBBoxFromSphere: bounding box froma a sphere*/
void D3DXBBoxFromSphere(const D3DXVECTOR3 *center, float radius, D3DXVECTOR3 *bMax, D3DXVECTOR3 *bMin){
	D3DXVECTOR3 rVec = D3DXVECTOR3(radius,radius,radius); 
	*bMax = *center+rVec;
	*bMin = *center-rVec;
};

/**D3DXBBoxFromTri: bounding box from a triangle*/
void D3DXBBoxFromTri(const D3DXVECTOR3 *v0, const D3DXVECTOR3 *v1, const D3DXVECTOR3 *v2,
					D3DXVECTOR3 *bMax,D3DXVECTOR3 *bMin){

	bMax->x = v0->x;
	bMax->y = v0->y;
	bMax->z = v0->z;

	bMin->x = v0->x;
	bMin->y = v0->y;
	bMin->z = v0->z;

	//Min X
	bMin->x = bMin->x > v1->x ? v1->x : bMin->x;
	bMin->x = bMin->x > v2->x ? v2->x : bMin->x;
	//Min Y
	bMin->y = bMin->y > v1->y ? v1->y : bMin->y;
	bMin->y = bMin->y > v2->y ? v2->y : bMin->y;
	//Min Z
	bMin->z = bMin->z > v1->z ? v1->z : bMin->z;
	bMin->z = bMin->z > v2->z ? v2->z : bMin->z;

	//Max X
	bMax->x = bMax->x < v1->x ? v1->x : bMax->x;
	bMax->x = bMax->x < v2->x ? v2->x : bMax->x;
	//Max Y
	bMax->y = bMax->y < v1->y ? v1->y : bMax->y;
	bMax->y = bMax->y < v2->y ? v2->y : bMax->y;
	//Max Z
	bMax->z = bMax->z < v1->z ? v1->z : bMax->z;
	bMax->z = bMax->z < v2->z ? v2->z : bMax->z;
};

/**D3DXCheckBBoxBBox: */
bool D3DXCheckBBoxBBox(const D3DXVECTOR3 *amax, const D3DXVECTOR3 *amin,
					   const D3DXVECTOR3 *bMax,const  D3DXVECTOR3 *bMin){
	//X
	if(amin->x>bMin->x){
		if(amin->x>bMax->x) 
			return false;
	}
	else{
		if(bMin->x>amax->x) 
			return false;
	}

	//Y
	if(amin->y>bMin->y){
		if(amin->y>bMax->y) 
			return false;
	}
	else{
		if(bMin->y>amax->y) 
			return false;
	}

	//Z
	if(amin->z>bMin->z){
		if(amin->z>bMax->z) 
			return false;
	}
	else{
		if(bMin->z>amax->z) 
			return false;
	}

	return true;
};

/**D3DXAreaBBox: calculates the area of the bounding box*/
float D3DXAreaBBox(const D3DXVECTOR3 *bMax, const D3DXVECTOR3 *bMin){
	D3DXVECTOR3 size = *bMax-*bMin;

	float ret =	size.x*size.y+
				size.x*size.z+
				size.z*size.y;

	return ret*2.0f;
};

/**D3DXCheckSphereSphere:*/
bool D3DXCheckSphereSphere(const D3DXVECTOR3 *c0, const D3DXVECTOR3 *c1, float r0, float r1){
	return (D3DXVecDistance(c0,c1)<=(r0+r1));
};

//TODO: Check if this code works or not
bool D3DXCheckSphereBBox(const D3DXVECTOR3 *bMax, const D3DXVECTOR3 *bMin, const D3DXVECTOR3 *sph_center, float sph_radius2){
    float dmin = 0.0f;
	for(int i=0; i<3; i++){
		if((*sph_center)[i] < (*bMin)[i]){
			float tmp = (*sph_center)[i] - (*bMin)[i];
			dmin += tmp*tmp;
		}
		else{
			if((*sph_center)[i] > (*bMax)[i]){
				float tmp = (*sph_center)[i] - (*bMax)[i];
				dmin += tmp*tmp;     
			}
		}
    }

	return (dmin<=(sph_radius2));
};

/**D3DXClosestCube: the closest cube from a starting bounding box (bMax,bMin)*/
void D3DXClosestCube(const D3DXVECTOR3 *bMax, const D3DXVECTOR3 *bMin, D3DXVECTOR3 *amax, D3DXVECTOR3 *amin){
	D3DXVECTOR3 len = *bMax-*bMin;
	float maxLen = MAX(MAX(len.x,len.y),len.z)/2.0f+1e-6f;
	D3DXVECTOR3 c = (*bMax+*bMin)/2.0f;

	len = D3DXVECTOR3(maxLen,maxLen,maxLen);

	*amax = c+len;
	*amin = c-len;

	*amax =  D3DXVECTOR3(1.0f,1.0f,1.0f);
	*amin = -D3DXVECTOR3(1.0f,1.0f,1.0f);
};

//Bounding Box 3D
void D3DXBBoxClamp(const D3DXVECTOR3 *max, const D3DXVECTOR3 *min, D3DXVECTOR3 *p){
	p->x = (p->x < min->x) ? min->x : p->x;
	p->y = (p->y < min->y) ? min->y : p->y;
	p->z = (p->z < min->z) ? min->z : p->z;

	p->x = (p->x > max->x) ? max->x : p->x;
	p->y = (p->y > max->y) ? max->y : p->y;
	p->z = (p->z > max->z) ? max->z : p->z;
};

//Bounding Box 3D
void D3DXBBoxLocal(const D3DXVECTOR3 *max, const D3DXVECTOR3 *min, D3DXVECTOR3 *p){
	D3DXVECTOR3 len = *max - *min;
	*p = (*p - *min)/len;
};

//Bounding Box 3D
void D3DXBBoxClampLocal(const D3DXVECTOR3 *max, const D3DXVECTOR3 *min, D3DXVECTOR3 *p){
	D3DXBBoxClamp(max,min,p);
	D3DXBBoxLocal(max,min,p);
};

inline int Bool2Ind(bool x, bool y, bool z){
	return (x<<0)+(y<<1)+(z<<2);
};

inline bool Ind2Bool(int ind, int pos){
	return (ind>>pos)&0x1;
};

/**D3DXBoxOctant: calculates an octant of a box*/
void D3DXBoxOctant(D3DXVECTOR3 *max, D3DXVECTOR3 *min, D3DXVECTOR3 *maxOut, D3DXVECTOR3 *minOut, int ind){
	for(int i=0;i<3;i++){
		if(Ind2Bool(ind,i)){
			(*maxOut)[i] = ((*max)[i]+(*min)[i])/2.0f;
			(*minOut)[i] = (*min)[i];
		}
		else{
			(*maxOut)[i] = (*max)[i];
			(*minOut)[i] = ((*max)[i]+(*min)[i])/2.0f;
		}
	}
};

/**D3DXVec3ShiftOctant: calculates an octant shift vector*/
D3DXVECTOR3 *D3DXVec3ShiftOctant(D3DXVECTOR3 *vecOut, int ind){
	for(int i=0;i<3;i++){
		if(Ind2Bool(ind,i))
			(*vecOut)[i] = -1.0f;
		else
			(*vecOut)[i] =  1.0f;
	}

	return vecOut;
};
#endif