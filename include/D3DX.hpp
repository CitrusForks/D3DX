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

#ifndef D3DX_INCLUDERS
#define D3DX_INCLUDERS

//by default we check pointers
#define D3DX_NORMALIZATION_POINTER_CHECK

//classic math utils
#include "math_util.hpp"

//D3DX
#include "D3DXVECTOR2.hpp"
#include "D3DXVECTOR3.hpp"
#include "D3DXVECTOR4.hpp"
#include "D3DXQUATERNION.hpp"
#include "D3DXFunctions.hpp"

#include "D3DXVECTOR3INT.hpp"
#include "D3DXVECTOR2INT.hpp"

#include "D3DXIOFunctions.hpp"
#include "D3DXConstants.hpp"
#include "D3DXGeometry.hpp"
#include "D3DXCoordSys.hpp"
#include "D3DXBoundingBox.hpp"

//2x2 Matrix
#include "D3DXMATRIX2X2.hpp"

//3x3 Matrix
#include "D3DXMATRIX3X3.hpp"

//4x4 Matrix
#include "D3DXMATRIX.hpp"

#endif