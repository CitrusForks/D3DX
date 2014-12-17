/**
*     Copyright (C) 2010-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef CLASS_D3DXVECTOR3_INT
#define CLASS_D3DXVECTOR3_INT

/**
 * @brief The D3DXVECTOR3INT class
 */
class D3DXVECTOR3INT
{
public:
	int		x, y, z;
	
    /**
     * @brief D3DXVECTOR3INT
     */
	D3DXVECTOR3INT(){
	}

    /**
     * @brief D3DXVECTOR3INT
     * @param x
     * @param y
     * @param z
     */
    D3DXVECTOR3INT(int x, int y, int z)
    {
		this->x = x;
		this->y = y;
		this->z = z;
	}

    /**
     * @brief isTheSame
     * @param a
     * @return
     */
    bool isTheSame(const D3DXVECTOR3INT &a)
    {
        return ((a.x == x) && (a.y == y) && (a.z == z));
	}

    /**
     * @brief operator []
     * @param i
     * @return
     */
    int operator [](int i) const
    {
		switch(i){
			case 0:
				return x; break;
			case 1:
				return y; break;
			case 2:
				return z; break;
		}
		return -1;
	}

    /**
     * @brief operator []
     * @param i
     * @return
     */
    int &operator [](int i)
    {
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

#endif //CLASS_D3DXVECTOR3_INT
