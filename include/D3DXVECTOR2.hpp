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
