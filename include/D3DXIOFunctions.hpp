/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DX_IO_FUNCTIONS
#define D3DX_IO_FUNCTIONS

#include <stdio.h>

#include "D3DXVECTOR3.hpp"

/**
 * @brief fscanfVet
 * @param file
 * @param vet
 */
void fscanfVet(FILE *file, D3DXVECTOR3 *vet)
{
    if(vet == NULL)
		return;

	fscanf(file, "%f", &vet->x);
	fscanf(file, "%f", &vet->y);
	fscanf(file, "%f", &vet->z);
}

/**
 * @brief fscanfVet
 * @param file
 * @param vet
 */
void fscanfVet(FILE *file, float *vet)
{
    if(vet == NULL)
		return;

	fscanf(file, "%f", &vet[0]);
	fscanf(file, "%f", &vet[1]);
	fscanf(file, "%f", &vet[2]);
}

/**
 * @brief fscanfVet
 * @param file
 * @param vet
 */
void fscanfVet(FILE *file, D3DXVECTOR2 *vet)
{
	fscanf(file, "%f", &vet->x);
	fscanf(file, "%f", &vet->y);
}

/**
 * @brief printfVet
 * @param vet
 */
void printfVet(const D3DXVECTOR3 *vet)
{
    printf(" %f %f %f\n", vet->x, vet->y, vet->z);
}

/**
 * @brief printfVet
 * @param vet
 */
void printfVet(D3DXVECTOR2 *vet)
{
    printf(" %f %f\n", vet->x, vet->y);
}

#endif //D3DX_IO_FUNCTIONS
