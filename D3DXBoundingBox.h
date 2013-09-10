/**
*     Copyright (C) 2008-2013  Francesco Banterle
* 
*     This program is free software: you can redistribute it and/or modify
*     it under the terms of the GNU General Public License as published by
*     the Free Software Foundation, either version 3 of the License, or
*     (at your option) any later version.
* 
*     This program is distributed in the hope that it will be useful,
*     but WITHOUT ANY WARRANTY; without even the implied warranty of
*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*     GNU General Public License for more details.
* 
*     You should have received a copy of the GNU General Public License
*     along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FUNCTIONS_D3DXBOUNDINGBOX
#define FUNCTIONS_D3DXBOUNDINGBOX
#include "D3DXVECTOR3.h"

/**D3DXExtendBBox: a bounding box (bmax,bmin) is expanded according p*/
void D3DXExtendBBox(D3DXVECTOR3 *bmax, D3DXVECTOR3 *bmin, const D3DXVECTOR3 *p){
	//Max
	bmax->x = MAX(p->x,bmax->x);
	bmax->y = MAX(p->y,bmax->y);
	bmax->z = MAX(p->z,bmax->z);
	//Min
	bmin->x = MIN(p->x,bmin->x);
	bmin->y = MIN(p->y,bmin->y);
	bmin->z = MIN(p->z,bmin->z);
};

/**D3DXMinBBox: calculates the minimum box*/
void D3DXMinBBox(D3DXVECTOR3 *max, D3DXVECTOR3 *min, const D3DXVECTOR3 *bMin,const D3DXVECTOR3 *bMax){
	if(bMax->x<max->x) max->x=bMax->x;
	if(bMax->y<max->y) max->y=bMax->y;
	if(bMax->z<max->z) max->z=bMax->z;

	if(bMin->x>min->x) min->x=bMin->x;
	if(bMin->y>min->y) min->y=bMin->y;
	if(bMin->z>min->z) min->z=bMin->z;
};

/**D3DXCheckPointBBox: checks if a point p is in a bounding box (bmax,bmin)*/
bool D3DXCheckPointBBox(const D3DXVECTOR2 *bmax, const D3DXVECTOR2 *bmin, const D3DXVECTOR2 *p){
	return((   p->x>=bmin->x)
			&&(p->y>=bmin->y)
			&&(p->x<=bmax->x)
			&&(p->y<=bmax->y));
};

/**D3DXCheckPointBBox: checks if a point p is in a bounding box (bmax,bmin)*/
bool D3DXCheckPointBBox(const D3DXVECTOR3 *bmax, const D3DXVECTOR3 *bmin, const D3DXVECTOR3 *p){
	return((   p->x>=bmin->x)
			&&(p->y>=bmin->y)
			&&(p->z>=bmin->z)
			&&(p->x<=bmax->x)
			&&(p->y<=bmax->y)
			&&(p->z<=bmax->z));
};

/**D3DXCheckPlaneBBox: checks if a plane (nor,d) intersects a bounding box (bmax,bmin)*/
bool D3DXCheckPlaneBBox(const D3DXVECTOR3 *bmax, const D3DXVECTOR3 *bmin, const D3DXVECTOR3 *nor, float d){

	D3DXVECTOR3 vMax, vMin;
	for(int i=0;i<3;i++){
		if((*nor)[i]>0.0f){
			vMax[i] = (*bmax)[i];
			vMin[i] = (*bmin)[i];
		}
		else{
			vMax[i] = (*bmin)[i];
			vMin[i] = (*bmax)[i];
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
void D3DXBBoxFromSphere(const D3DXVECTOR3 *center, float radius, D3DXVECTOR3 *bmax, D3DXVECTOR3 *bmin){
	D3DXVECTOR3 rVec = D3DXVECTOR3(radius,radius,radius); 
	*bmax = *center+rVec;
	*bmin = *center-rVec;
};

/**D3DXBBoxFromTri: bounding box from a triangle*/
void D3DXBBoxFromTri(const D3DXVECTOR3 *v0, const D3DXVECTOR3 *v1, const D3DXVECTOR3 *v2,
				D3DXVECTOR3 *bmax,D3DXVECTOR3 *bmin){
	bmax->x=v0->x;
	bmax->y=v0->y;
	bmax->z=v0->z;

	bmin->x=v0->x;
	bmin->y=v0->y;
	bmin->z=v0->z;

	//Min X
	bmin->x= bmin->x > v1->x ? v1->x : bmin->x;
	bmin->x= bmin->x > v2->x ? v2->x : bmin->x;
	//Min Y
	bmin->y= bmin->y > v1->y ? v1->y : bmin->y;
	bmin->y= bmin->y > v2->y ? v2->y : bmin->y;
	//Min Z
	bmin->z= bmin->z > v1->z ? v1->z : bmin->z;
	bmin->z= bmin->z > v2->z ? v2->z : bmin->z;

	//Max X
	bmax->x= bmax->x < v1->x ? v1->x : bmax->x;
	bmax->x= bmax->x < v2->x ? v2->x : bmax->x;
	//Max Y
	bmax->y= bmax->y < v1->y ? v1->y : bmax->y;
	bmax->y= bmax->y < v2->y ? v2->y : bmax->y;
	//Max Z
	bmax->z= bmax->z < v1->z ? v1->z : bmax->z;
	bmax->z= bmax->z < v2->z ? v2->z : bmax->z;
};

/**D3DXCheckBBoxBBox: */
bool D3DXCheckBBoxBBox(const D3DXVECTOR3 *amax, const D3DXVECTOR3 *amin,
					   const D3DXVECTOR3 *bmax,const  D3DXVECTOR3 *bmin){
	//Blocco X
	if(amin->x>bmin->x){
		if(amin->x>bmax->x) 
			return false;
	}
	else{
		if(bmin->x>amax->x) 
			return false;
	}

	//Blocco Y
	if(amin->y>bmin->y){
		if(amin->y>bmax->y) 
			return false;
	}
	else{
		if(bmin->y>amax->y) 
			return false;
	}

	//Blocco Z
	if(amin->z>bmin->z){
		if(amin->z>bmax->z) 
			return false;
	}
	else{
		if(bmin->z>amax->z) 
			return false;
	}

	return true;
};

/**D3DXAreaBBox: calculates the area of the bounding box*/
float D3DXAreaBBox(const D3DXVECTOR3 *bmax, const D3DXVECTOR3 *bmin){
	D3DXVECTOR3 size = *bmax-*bmin;

	float ret=	size.x*size.y+
				size.x*size.z+
				size.z*size.y;

	return ret*2.0f;
};

/**D3DXCheckSphereSphere:*/
bool D3DXCheckSphereSphere(const D3DXVECTOR3 *c0, const D3DXVECTOR3 *c1, float r0, float r1){
	return (D3DXVecDistance(c0,c1)<=(r0+r1));
};

//TODO: Check if this code works or not
bool D3DXCheckSphereBBox(const D3DXVECTOR3 *bmax, const D3DXVECTOR3 *bmin, const D3DXVECTOR3 *sph_center, float sph_radius2){
    float dmin = 0.0f;
	for(int i=0; i<3; i++){
		if((*sph_center)[i] < (*bmin)[i]){
			float tmp = (*sph_center)[i] - (*bmin)[i];
			dmin += tmp*tmp;
		}
		else{
			if((*sph_center)[i] > (*bmax)[i]){
				float tmp = (*sph_center)[i] - (*bmax)[i];
				dmin += tmp*tmp;     
			}
		}
    }

	return (dmin<=(sph_radius2));
};

/**D3DXClosestCube: the closest cube from a starting bounding box (bmax,bmin)*/
void D3DXClosestCube(const D3DXVECTOR3 *bmax, const D3DXVECTOR3 *bmin, D3DXVECTOR3 *amax, D3DXVECTOR3 *amin){
	D3DXVECTOR3 len = *bmax-*bmin;
	float maxLen = MAX(MAX(len.x,len.y),len.z)/2.0f+1e-6f;
	D3DXVECTOR3 c = (*bmax+*bmin)/2.0f;

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