/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
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
