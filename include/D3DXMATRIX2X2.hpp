/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DXMATRIX_2X2_HPP
#define D3DXMATRIX_2X2_HPP

#include "D3DXVECTOR2.hpp"

/**
 * @brief The D3DXMATRIX2X2 class
 */
class D3DXMATRIX2X2
{
 public:
	float data[4];
	
    /**
     * @brief D3DXMATRIX2X2
     */
    D3DXMATRIX2X2()
    {
    }
	
    /**
     * @brief D3DXMATRIX2X2 creates and sets the matrix to (a00, a01; a10, a11).
     * @param a00
     * @param a01
     * @param a10
     * @param a11
     */
    D3DXMATRIX2X2(float a00, float a01, float a10, float a11)
    {
        Init(a00, a01, a10, a11);
    }

    /**
     * @brief Init sets the matrix to (a00, a01; a10, a11).
     * @param a00
     * @param a01
     * @param a10
     * @param a11
     */
    void Init(float a00, float a01, float a10, float a11){
	    data[0] = a00;
	    data[2] = a10;
	    data[1] = a01;
	    data[3] = a11;
    }

    /**
     * @brief Identity sets the matrix to identity.
     */
    void Identity()
    {
        data[0] = 1.0f;
	    data[3] = 1.0f;
	    data[1] = 0.0f;
	    data[2] = 0.0f;
    }
	
  	/** + operator*/

    /**
     * @brief operator +=
     * @param pM
     */
    void operator += ( const D3DXMATRIX2X2 &pM)
    {
        for(int i=0; i<4; i++) {
            data[i] += pM.data[i];
        }
    }

    /**
     * @brief operator +
     * @param pM
     * @return
     */
    D3DXMATRIX2X2 operator +(const D3DXMATRIX2X2 &pM) const
    {
        D3DXMATRIX2X2 pOut;

        for(int i=0; i<4; i++) {
            pOut.data[i] =  data[i] + pM.data[i];
        }

        return pOut;
    }

  	/** - operator*/

    /**
     * @brief operator -=
     * @param pM
     */
    void operator -= ( const D3DXMATRIX2X2 &pM)
    {
        for(int i=0; i<4; i++) {
            data[i] -= pM.data[i];
        }
    }

    /**
     * @brief operator -
     * @param pM
     * @return
     */
    D3DXMATRIX2X2 operator -(const D3DXMATRIX2X2 &pM) const
    {
        D3DXMATRIX2X2 pOut;

        for(int i=0; i<4; i++) {
            pOut.data[i] =  data[i] - pM.data[i];
        }

        return pOut;
    }

    /**
     * @brief operator -
     * @return
     */
    D3DXMATRIX2X2 operator -()const
    {
		return D3DXMATRIX2X2(-data[0], -data[1], -data[2], -data[3]);
    }

    /** * operator */
	
    /**
     * @brief Mul
     * @param mA
     * @param mB
     * @param out
     * @return
     */
    static D3DXMATRIX2X2 *Mul(const D3DXMATRIX2X2 &mA, const D3DXMATRIX2X2 &mB, D3DXMATRIX2X2 *out = NULL)
    {
        if(out == NULL) {
            out = new D3DXMATRIX2X2();
        }

	    out->data[0] = mA.data[0] * mB.data[0] + mA.data[1] * mB.data[2];
	    out->data[1] = mA.data[0] * mB.data[1] + mA.data[1] * mB.data[3];

	    out->data[2] = mA.data[2] * mB.data[0] + mA.data[3] * mB.data[2];
	    out->data[3] = mA.data[2] * mB.data[1] + mA.data[3] * mB.data[3];

	    return out;
    }

    /**
     * @brief operator *=
     * @param pM
     */
    void operator *= ( const D3DXMATRIX2X2 &pM)
    {
        D3DXMATRIX2X2 pOut;
        Mul(*this, pM, &pOut);

        for(int i=0;i<4;i++) {
            data[i] = pOut.data[i];
        }
    }

    /**
     * @brief operator *=
     * @param v
     */
    void operator *= (float v)
    {
        for(int i=0; i<4; i++) {
            data[i] *= v;
        }
    }

    /**
     * @brief operator *
     * @param pM
     * @return
     */
    D3DXMATRIX2X2 operator *(const D3DXMATRIX2X2 &pM) const
    {
        D3DXMATRIX2X2 pOut;
        Mul(*this, pM, &pOut);
        return pOut;
    }

    /**
     * @brief operator *
     * @param pM
     * @return
     */
    D3DXVECTOR2 operator *(const D3DXVECTOR2 &pV) const
    {
        D3DXVECTOR2 pOut;

        pOut.x = data[0] * pV.x + data[1] * pV.y;
        pOut.y = data[2] * pV.x + data[3] * pV.y;

        return pOut;
    }

    /**
     * @brief operator /=
     * @param v
     */
    void operator /= (float v)
    {
        for(int i=0;i<4;i++) {
            data[i] /= v;
        }
    }
    	
    /**
     * @brief Determinant computes the determinant of the matrix.
     * @return
     */
    float Determinant()
    {
        return data[0] * data[3] - data[2] * data[1];
    }

    /**
     * @brief Inverse computes the inverse of the matrix.
     * @param out
     * @return
     */
    D3DXMATRIX2X2 *Inverse(D3DXMATRIX2X2 *out = NULL)
    {
        #ifdef D3DX_POINTER_CHECK
            if(out == NULL) {
                out =  new D3DXMATRIX2X2();
            }
        #endif

	    float det = Determinant();

        if(fabsf(det) < 1e-9f) {
            printf("Determinant is near zero: D3DXMATRIX2X2 *D3DXMATRIX2X2::Inverse()\n");
            return new D3DXMATRIX2X2(0.0f, 0.0f, 0.0f, 0.0f);
	    }
		
        out->Init(data[3] / det, -data[1] / det, -data[2] / det, data[0] / det);
	    return out;
    }
    	

    D3DXVECTOR2 *getRow(D3DXVECTOR2 *pOut, unsigned int row)
    {
        row = row % 2;

        #ifdef D3DX_POINTER_CHECK
            if(pOut == NULL) {
                pOut =  new D3DXVECTOR2();
            }
        #endif

            pOut->x = data[row * 2];
            pOut->y = data[row * 2 + 1];

            return pOut;
    }

    /**
     * @brief Print prints the matrix.
     */
    void Print()
    {
        printf("\n%3.5f %3.5f \n %3.5f %3.5f\n\n",data[0], data[1], data[2], data[3]);
    }
};

#endif //D3DXMATRIX_2X2_HPP
