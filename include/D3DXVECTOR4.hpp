/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DXVECTOR4_HPP
#define D3DXVECTOR4_HPP

/**
 * @brief The D3DXVECTOR4 class
 */
class D3DXVECTOR4{
public:
    float x, y, z, w;

    D3DXVECTOR4()
    {
	}

    /**
     * @brief D3DXVECTOR4
     * @param a
     */
    D3DXVECTOR4(float a)
    {
        x = y = z = w = a;
	}

    /**
     * @brief D3DXVECTOR4
     * @param x
     * @param y
     * @param z
     * @param w
     */
    D3DXVECTOR4(float x, float y, float z, float w)
    {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

    /**
     * @brief operator -
     * @param v
     * @return
     */
    D3DXVECTOR4 operator -(const D3DXVECTOR4 &v) const
    {
        return D3DXVECTOR4(x - v.x, y - v.y, z - v.z, w - v.w);
	}

    /**
     * @brief operator -
     * @return
     */
    D3DXVECTOR4 operator -()const
    {
		return D3DXVECTOR4(-x, -y, -z, -w);
	}

    /**
     * @brief operator -=
     * @param v
     */
    void operator -=(const D3DXVECTOR4 &v)
    {
		x -= v.x;
		y -= v.y;
		z -= v.z;
        w -= v.w;
	}

    /**
     * @brief operator +
     * @param v
     * @return
     */
    D3DXVECTOR4 operator +(const D3DXVECTOR4 &v) const
    {
        return D3DXVECTOR4(x + v.x, y + v.y, z + v.z, w + v.w);
	}

    /**
     * @brief operator +=
     * @param v
     */
    void operator +=(const D3DXVECTOR4 &v)
    {
		x += v.x;
		y += v.y;
		z += v.z;
        w += v.w;
	}

    /**
     * @brief operator /
     * @param v
     * @return
     */
    D3DXVECTOR4 operator /(const D3DXVECTOR4 &v) const
    {
		return D3DXVECTOR4(x/v.x, y/v.y, z/v.z, w/v.w);
	}

    /**
     * @brief operator /=
     * @param v
     * @return
     */
    void operator /=(const D3DXVECTOR4 &v)
    {
		x /= v.x;
		y /= v.y;
		z /= v.z;
		w /= v.w;
	}

    /**
     * @brief operator *
     * @param v
     * @return
     */
    D3DXVECTOR4 operator *(const D3DXVECTOR4 &v)const
    {
        return D3DXVECTOR4(x * v.x, y * v.y, z * v.z, w * v.w);
	}

    /**
     * @brief operator *
     * @param a
     * @return
     */
    D3DXVECTOR4 operator *(const float &a)const
    {
        return D3DXVECTOR4(x * a, y * a, z * a, w * a);
	}
	
    /**
     * @brief operator *=
     * @param a
     */
    void operator *=(const float &a)
    {
		x *= a;
		y *= a;
		z *= a;
		w *= a;
	}

    /**
     * @brief operator =
     * @param v
     * @return
     */
    D3DXVECTOR4 operator = (const float v[4])
    {
		return D3DXVECTOR4(v[0], v[1], v[2], v[3]);
	}
	
    /**
     * @brief operator /
     * @param a
     * @return
     */
    D3DXVECTOR4 operator /(const float &a)const
    {
		if(a!=0.0f)
            return D3DXVECTOR4(x / a, y / a, z / a, w / a);
		else
			return D3DXVECTOR4(x, y, z, w);
	}

    /**
     * @brief operator /=
     * @param a
     */
    void operator /=(const float &a)
    {
		if(a!=0.0f){
			x /= a;
			y /= a;
			z /= a;
			w /= a;
		}
	}

    /**
     * @brief operator []
     * @param i
     * @return
     */
    float operator [](int i) const
    {
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

    /**
     * @brief operator []
     * @param i
     * @return
     */
    float &operator [](int i)
    {
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

#endif //D3DXVECTOR4_HPP
