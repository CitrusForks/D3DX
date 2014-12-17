/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef CLASS_D3DXD3DXMATRIX_2X2
#define CLASS_D3DXD3DXMATRIX_2X2

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
        for(int i=0;i<4;i++)
            data[i] += pM.data[i];
    }

    /**
     * @brief operator +
     * @param pM
     * @return
     */
    D3DXMATRIX2X2 operator +(const D3DXMATRIX2X2 &pM) const
    {
        D3DXMATRIX2X2 pOut;

        for(int i=0;i<4;i++)
            pOut.data[i] =  data[i] + pM.data[i];

        return pOut;
	}

  	/** - operator*/

    /**
     * @brief operator -=
     * @param pM
     */
    void operator -= ( const D3DXMATRIX2X2 &pM)
    {
        for(int i=0;i<4;i++)
            data[i] -= pM.data[i];
    }

    /**
     * @brief operator -
     * @param pM
     * @return
     */
    D3DXMATRIX2X2 operator -(const D3DXMATRIX2X2 &pM) const
    {
        D3DXMATRIX2X2 pOut;

        for(int i=0;i<4;i++)
            pOut.data[i] =  data[i] - pM.data[i];

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
	    if(out==NULL)
		    out = new D3DXMATRIX2X2();

	    out->data[0] = mA.data[0]*mB.data[0] + mA.data[1]*mB.data[2];
	    out->data[1] = mA.data[0]*mB.data[1] + mA.data[1]*mB.data[3];

	    out->data[2] = mA.data[2]*mB.data[0] + mA.data[3]*mB.data[2];
	    out->data[3] = mA.data[2]*mB.data[1] + mA.data[3]*mB.data[3];

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

        for(int i=0;i<4;i++)
            data[i] = pOut.data[i];
    }

    /**
     * @brief operator *=
     * @param v
     */
    void operator *= (float v)
    {
        for(int i=0;i<4;i++)
            data[i] *= v;
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
     * @brief operator /=
     * @param v
     */
    void operator /= (float v)
    {
        for(int i=0;i<4;i++)
            data[i] /= v;
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
    D3DXMATRIX2X2 *Inverse(D3DXMATRIX2X2 *out=NULL)
    {
	    float det = Determinant();

        if(fabsf(det) < 1e-9f) {
		    printf("Determinant is near zero: D3DXMATRIX2X2 *D3DXMATRIX2X2::Inverse()\n");
            return new D3DXMATRIX2X2(0.0f, 0.0f, 0.0f, 0.0f);
	    }
		
        if(out == NULL)
            out = new D3DXMATRIX2X2(data[3], -data[1], -data[2], data[0]);
        else
            out->Init(data[3], -data[1], -data[2], data[0]);

	    *out /= det;
	    return out;
    }
    	
    /**
     * @brief Print prints the matrix.
     */
    void Print()
    {
        printf("\n%3.3f %3.3f \n %3.3f %3.3f\n\n",data[0], data[1], data[2], data[3]);
	}
};

#endif //CLASS_D3DXD3DXMATRIX_2X2
