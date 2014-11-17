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
