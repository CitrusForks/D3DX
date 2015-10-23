/**
*     Copyright (C) 2008-2014  Francesco Banterle
* 
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DX_INCLUDERS
#define D3DX_INCLUDERS

//by default we check pointers
#define D3DX_NORMALIZATION_POINTER_CHECK
#define D3DX_POINTER_CHECK

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
