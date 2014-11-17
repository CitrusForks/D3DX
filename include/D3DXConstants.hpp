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

#ifndef D3DX_CONSTANTS
#define D3DX_CONSTANTS

#include "D3DXVECTOR3.hpp"
#include "D3DXVECTOR4.hpp"

//Empty D3DXVECTOR3
const D3DXVECTOR3 VecNull   = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

//Empty D3DXVECTOR4
const D3DXVECTOR4 Vec4Null  = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);

//Constant Vector
const D3DXVECTOR3 VecHalf   = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
const D3DXVECTOR3 VecOne    = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

//Space Axis
const D3DXVECTOR3 E0        = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
const D3DXVECTOR3 E1        = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
const D3DXVECTOR3 E2        = D3DXVECTOR3(0.0f, 0.0f, 1.0f);

#endif //D3DX_CONSTANTS
