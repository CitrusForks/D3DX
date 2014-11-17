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

#ifndef D3DX_IO_FUNCTIONS
#define

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
