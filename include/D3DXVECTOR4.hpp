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

#ifndef CLASS_D3DXVECTOR4
#define CLASS_D3DXVECTOR4

class D3DXVECTOR4{
public:
	float x,y,z,w;

	D3DXVECTOR4(){
	}

    D3DXVECTOR4(float a){
        x = y = z = w = a;
	}

	D3DXVECTOR4(float x, float y, float z, float w){
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	D3DXVECTOR4 operator -(const D3DXVECTOR4 &v) const{
		return D3DXVECTOR4(x-v.x, y-v.y, z-v.z, w-v.w);
	}

	D3DXVECTOR4 operator -()const{
		return D3DXVECTOR4(-x, -y, -z, -w);
	}

	void operator -=(const D3DXVECTOR4 &v){
		x -= v.x;
		y -= v.y;
		z -= v.z;
        w -= v.w;
	}

	D3DXVECTOR4 operator +(const D3DXVECTOR4 &v) const{
		return D3DXVECTOR4(x+v.x, y+v.y, z+v.z, w+v.w);
	}

	void operator +=(const D3DXVECTOR4 &v){
		x += v.x;
		y += v.y;
		z += v.z;
        w += v.w;
	}

	D3DXVECTOR4 operator /(const D3DXVECTOR4 &v) const{
		return D3DXVECTOR4(x/v.x, y/v.y, z/v.z, w/v.w);
	}

	D3DXVECTOR4& operator /=(const D3DXVECTOR4 &v){
		x /= v.x;
		y /= v.y;
		z /= v.z;
		w /= v.w;
	}

	D3DXVECTOR4 operator *(const D3DXVECTOR4 &v)const{
		return D3DXVECTOR4(x*v.x, y*v.y, z*v.z, w*v.w);
	}

	D3DXVECTOR4 operator *(const float &a)const{
		return D3DXVECTOR4(x*a, y*a, z*a, w*a);
	}
	
	void operator *=(const float &a){
		x *= a;
		y *= a;
		z *= a;
		w *= a;
	}

	D3DXVECTOR4 operator = (const float v[4]){
		return D3DXVECTOR4(v[0], v[1], v[2], v[3]);
	}
	
	D3DXVECTOR4 operator /(const float &a)const{
		if(a!=0.0f)
			return D3DXVECTOR4(x/a, y/a, z/a, w/a);
		else
			return D3DXVECTOR4(x, y, z, w);
	}

	void operator /=(const float &a){
		if(a!=0.0f){
			x /= a;
			y /= a;
			z /= a;
			w /= a;
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
			case 3:
				return w; break;
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
			case 3:
				return w; break;
		}
		return x;
	}
};
#endif