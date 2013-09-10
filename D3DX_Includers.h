/**
*     Copyright (C) 2008-2013  Francesco Banterle
* 
*     This program is free software: you can redistribute it and/or modify
*     it under the terms of the GNU General Public License as published by
*     the Free Software Foundation, either version 3 of the License, or
*     (at your option) any later version.
* 
*     This program is distributed in the hope that it will be useful,
*     but WITHOUT ANY WARRANTY; without even the implied warranty of
*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*     GNU General Public License for more details.
* 
*     You should have received a copy of the GNU General Public License
*     along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GRT_D3DX_INCLUDERS
#define GRT_D3DX_INCLUDERS

//2x2 Matrix
#include "math_util.h"
#include "Matrix2x2.h"

//D3DX
#ifndef GRT_D3DX
	#include "D3DXVECTOR2.h"
	#include "D3DXVECTOR3.h"
	#include "D3DXVECTOR4.h"
	#include "D3DXQUATERNION.h"
	#include "D3DXFunctions.h"
#endif

#include "D3DXIOFunctions.h"
#include "D3DXConstants.h"
#include "D3DXGeometry.h"
#include "D3DXCoordSys.h"
#include "D3DXBoundingBox.h"

#ifndef GRT_D3DX
	#include "D3DXMATRIX.h"
#endif

#endif