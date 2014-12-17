/**
*     Copyright (C) 2010-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef CLASS_D3DXVECTOR2_INT
#define CLASS_D3DXVECTOR2_INT

/**
 * @brief The D3DXVECTOR2INT class
 */
class D3DXVECTOR2INT
{
public:
	int		x, y;

    /**
     * @brief D3DXVECTOR2INT
     */
    D3DXVECTOR2INT()
    {
	}

    /**
     * @brief D3DXVECTOR2INT
     * @param x
     * @param y
     */
    D3DXVECTOR2INT(int x, int y)
    {
		this->x = x;
		this->y = y;
	}

    /**
     * @brief isTheSame
     * @param a
     * @return
     */
    bool isTheSame(const D3DXVECTOR2INT &a)
    {
        return ((a.x == x) && (a.y == y));
	}

    /**
     * @brief Clip cipls the vector in the bounding box [0, width - 1] x [0, height - 1]
     * @param width
     * @param height
     */
    void clip(int width, int height)
    {
		//X clipping
        x = x > (width - 1) ? (width - 1) : x;
        x = x < 0 ? 0 : x;
		//Y clipping
        y = y > (height - 1) ? (height - 1) : y;
        y = y < 0 ? 0 : x;
	}
};

#endif //CLASS_D3DXVECTOR2_INT
