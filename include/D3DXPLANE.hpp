/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef CLASS_D3DXPLANE
#define CLASS_D3DXPLANE

/**
 * @brief The D3DXPLANE class
 */
class D3DXPLANE
{
public:
    float a, b, c, d;

    /**
     * @brief D3DXPLANE
     */
    D3DXPLANE()
    {
	}

    /**
     * @brief set
     * @param a
     * @param b
     * @param c
     * @param d
     */
    void set(float a, float b, float c, float d)
    {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
};

#endif //CLASS_D3DXPLANE
