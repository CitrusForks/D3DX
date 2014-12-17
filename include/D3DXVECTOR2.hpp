/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef CLASS_D3DXVECTOR2
#define CLASS_D3DXVECTOR2

/**
 * @brief The D3DXVECTOR2 class
 */
class D3DXVECTOR2
{
public:
	float x, y;

    /**
     * @brief D3DXVECTOR2
     */
    D3DXVECTOR2()
    {
	}

    /**
     * @brief D3DXVECTOR2
     * @param x
     * @param y
     */
	D3DXVECTOR2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

    /**
     * @brief operator -
     * @param v
     * @return
     */
	D3DXVECTOR2 operator -(const D3DXVECTOR2 &v)
	{
        return D3DXVECTOR2(x - v.x, y - v.y);
	}

    /**
     * @brief operator -=
     * @param v
     */
	void operator -=(const D3DXVECTOR2 &v)
	{
		x -= v.x;
		y -= v.y;
	}

    /**
     * @brief operator +
     * @param v
     * @return
     */
	D3DXVECTOR2 operator +(const D3DXVECTOR2 &v)
	{
        return D3DXVECTOR2(x + v.x, y + v.y);
	}

    /**
     * @brief operator +=
     * @param v
     */
	void operator +=(const D3DXVECTOR2 &v)
	{
		x += v.x;
		y += v.y;
	}

    /**
     * @brief operator *
     * @param v
     * @return
     */
	D3DXVECTOR2 operator *(const D3DXVECTOR2 &v)
	{
        return D3DXVECTOR2(x * v.x, y * v.y);
	}

    /**
     * @brief operator *
     * @param a
     * @return
     */
	D3DXVECTOR2 operator *(const float &a)
	{
        return D3DXVECTOR2(x * a, y * a);
	}

    /**
     * @brief operator *=
     * @param a
     * @return
     */
	D3DXVECTOR2 operator *=(const float &a)
	{
        return D3DXVECTOR2(x * a, y * a);
	}

    /**
     * @brief operator /
     * @param a
     * @return
     */
	D3DXVECTOR2 operator /(const float &a)
	{
        if(x != 0.0f)
            return D3DXVECTOR2(x / a, y / a);
		else
			return D3DXVECTOR2(x, y);
	}

    /**
     * @brief operator /=
     * @param v
     */
    void operator /=(const D3DXVECTOR2 &v)
    {
		x /= v.x;
		y /= v.y;
	}

    /**
     * @brief operator ==
     * @param v
     * @return
     */
    bool operator ==(const D3DXVECTOR2 &v)
    {
        return (v.x == x) && (v.y == y);
	}

};

#endif //CLASS_D3DXVECTOR2
