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

#ifndef CLASS_D3DXVECTOR3
#define CLASS_D3DXVECTOR3

//Classe per gestione dei vettori 3d simile a quella di Direct3DX
class D3DXVECTOR3{
public:
	float x,y,z;

	D3DXVECTOR3(){
	}

	D3DXVECTOR3(float a){
		this->x = a;
		this->y = a;
		this->z = a;
	}

	D3DXVECTOR3(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	D3DXVECTOR3 operator -(const D3DXVECTOR3 &v) const{
		return D3DXVECTOR3(x-v.x,y-v.y,z-v.z);
	}

	D3DXVECTOR3 operator -()const{
		return D3DXVECTOR3(-x,-y,-z);
	}

	void operator -=(const D3DXVECTOR3 &v){
		x-=v.x;
		y-=v.y;
		z-=v.z;
	}

	D3DXVECTOR3 operator +(const D3DXVECTOR3 &v) const{
		return D3DXVECTOR3(x+v.x,y+v.y,z+v.z);
	}

	void operator +=(const D3DXVECTOR3 &v){
		x+=v.x;
		y+=v.y;
		z+=v.z;
	}

	D3DXVECTOR3 operator /(const D3DXVECTOR3 &v) const{
		return D3DXVECTOR3(x/v.x,y/v.y,z/v.z);
	}

	void operator /=(const D3DXVECTOR3 &v){
		x/=v.x;
		y/=v.y;
		z/=v.z;
	}

	D3DXVECTOR3 operator *(const D3DXVECTOR3 &v)const{
		return D3DXVECTOR3(x*v.x,y*v.y,z*v.z);
	}

	D3DXVECTOR3 operator *(const float &a)const{
		return D3DXVECTOR3(x*a,y*a,z*a);
	}
	
	void operator *=(const float &a){
		x*=a;
		y*=a;
		z*=a;
	}

	D3DXVECTOR3 operator = (const float v[3]){
		return D3DXVECTOR3(v[0],v[1],v[2]);
	}
	
	D3DXVECTOR3 operator /(const float &a)const{
		if(a!=0.0f)
			return D3DXVECTOR3(x/a,y/a,z/a);
		else
			return D3DXVECTOR3(x,y,z);
	}

	void operator /=(const float &a){
		if(a!=0.0f){
			x/=a;
			y/=a;
			z/=a;
		}
	}

  	float operator [](int i) const{
		switch(i){
			case 0:
				return x; break;
			case 1:
				return y; break;
			case 2:
				return z; break;
		}
		return -1.0f;
	}

 	float &operator [](int i){
		switch(i){
			case 0:
				return x; break;
			case 1:
				return y; break;
			case 2:
				return z; break;
		}
		return x;
	}
};
#endif