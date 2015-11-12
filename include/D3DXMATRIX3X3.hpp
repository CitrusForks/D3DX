/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef D3DXMATRIX_3X3_HPP
#define D3DXMATRIX_3X3_HPP

/**
 * @brief The D3DXMATRIX3X3 class
 */
class D3DXMATRIX3X3
{
 public:
	float data[9];

    /**
     * @brief D3DXMATRIX3X3
     */
    D3DXMATRIX3X3()
    {
        for(int i=0; i<9; i++) {
		    data[i] = 0.0f;
        }
    }

    /**
     * @brief D3DXMATRIX3X3
     * @param data
     */
    D3DXMATRIX3X3(float *data)
    {
        if(data != NULL) {
            memcpy(this->data, data, 9 * sizeof(float));
        }
    }

    /**
     * @brief Identity
     */
    void Identity()
    {
	    data[0] = 1.0f;
        data[1] = 0.0f;
        data[2] = 0.0f;

        data[3] = 0.0f;
        data[4] = 1.0f;
        data[5] = 0.0f;

        data[6] = 0.0f;
        data[7] = 0.0f;
	    data[8] = 1.0f;
    }
	
    /**
     * @brief Mul
     * @param vec
     * @param ret
     * @return
     */
    float* Mul(float *vec, float *ret)
    {
        if(vec == NULL) {
		    return ret;
        }

        if(ret == NULL) {
		    ret = new float[3];
        }

        ret[0] = data[0] * vec[0] + data[1] * vec[1] + data[2] * vec[2];
        ret[1] = data[3] * vec[0] + data[4] * vec[1] + data[5] * vec[2];
        ret[2] = data[6] * vec[0] + data[7] * vec[1] + data[8] * vec[2];

	    return ret;
    }

    /**
     * @brief Add
     * @param diag
     */
    void Add(float diag)
    {
	    data[0] += diag;
	    data[4] += diag;
	    data[8] += diag;
    }
	
    /**
     * @brief Determinant
     * @return
     */
    float Determinant()
    {
        return	 data[0] * (data[4] * data[8] - data[5] * data[7]) -
                 data[1] * (data[8] * data[3] - data[5] * data[6]) +
                 data[2] * (data[3] * data[7] - data[4] * data[6]);
    }

    /**
     * @brief Inverse
     * @param inv
     * @return
     */
    D3DXMATRIX3X3 *Inverse(D3DXMATRIX3X3 *inv)
    {
        if(inv == NULL) {
		    inv = new D3DXMATRIX3X3();
        }

	    float det = Determinant();
        if(fabsf(det) <= 1e-9f) {
            printf("Error: Near to zero determinant\n");
		    return inv;
	    }

        inv->data[0] =  (data[4] * data[8] - data[5] * data[7]) / det;
        inv->data[1] = -(data[1] * data[8] - data[2] * data[7]) / det;
        inv->data[2] =  (data[1] * data[5] - data[2] * data[4]) / det;

        inv->data[3] = -(data[3] * data[8] - data[5] * data[6]) / det;
        inv->data[4] =  (data[0] * data[8] - data[2] * data[6]) / det;
        inv->data[5] = -(data[0] * data[5] - data[2] * data[3]) / det;
	
        inv->data[6] =  (data[3] * data[7] - data[4] * data[6]) / det;
        inv->data[7] = -(data[0] * data[7] - data[1] * data[6]) / det;
        inv->data[8] =  (data[0] * data[4] - data[1] * data[3]) / det;

	    return inv;
    }

    /**
     * @brief Print
     */
    void Print()
    {
        for(int i=0; i<9; i++) {
            if((i%3) == 0)
			    printf("\n");

            printf("%f \t",data[i]);
	    }
	    printf("\n");
    }
 };

#endif //D3DXMATRIX_3X3_HPP