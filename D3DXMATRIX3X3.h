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

#ifndef CLASS_D3DXMATRIX3X3
#define CLASS_D3DXMATRIX3X3

 class D3DXMATRIX3X3{
 public:
	float data[9];
	
	//Constructor
	D3DXMATRIX3X3(){
	    for(int i=0;i<9;i++)
		    data[i] = 0.0f;
    }

    D3DXMATRIX3X3(float *data){
        if(data!=NULL)
            memcpy(this->data,data,9*sizeof(float));
    }
	
	//Identity Matrix
	void Identity(){
	    for(int i=0;i<9;i++)
		    data[i] = 0.0f;

	    data[0] = 1.0f;
	    data[4] = 1.0f;
	    data[8] = 1.0f;
    }
	
	//Matrix vector mul
	float* Mul(float *vec, float *ret){
	    if(vec==NULL)
		    return ret;

	    if(ret==NULL)
		    ret = new float[3];

	    ret[0] = data[0]*vec[0] + data[1]*vec[1] + data[2]*vec[2]; 
	    ret[1] = data[3]*vec[0] + data[4]*vec[1] + data[5]*vec[2]; 
	    ret[2] = data[6]*vec[0] + data[7]*vec[1] + data[8]*vec[2]; 

	    return ret;
    }

	//Add constant diagonal
	void Add(float diag){
	    data[0] += diag;
	    data[4] += diag;
	    data[8] += diag;
    }
	
	//Determinant of the Matrix
    float Determinant(){
	    return	 data[0]*(data[4]*data[8]-data[5]*data[7])-
			     data[1]*(data[8]*data[3]-data[5]*data[6])+
			     data[2]*(data[3]*data[7]-data[4]*data[6]);
    }
	
	//Inverse of the Matrix
	D3DXMATRIX3X3 *Inverse(D3DXMATRIX3X3 *inv){
	    if(inv==NULL)
		    inv = new D3DXMATRIX3X3();

	    float det = Determinant();
	    if(fabsf(det)<=1e-9f){
		    printf("Error: Negative determinant\n");
		    return inv;
	    }

	    inv->data[0] =  (data[4]*data[8]-data[5]*data[7])/det;	inv->data[1] = -(data[1]*data[8]-data[2]*data[7])/det;	inv->data[2] =  (data[1]*data[5]-data[2]*data[4])/det;

	    inv->data[3] = -(data[3]*data[8]-data[5]*data[6])/det;	inv->data[4] =  (data[0]*data[8]-data[2]*data[6])/det;	inv->data[5] = -(data[0]*data[5]-data[2]*data[3])/det;
	
	    inv->data[6] =  (data[3]*data[7]-data[4]*data[6])/det;	inv->data[7] = -(data[0]*data[7]-data[1]*data[6])/det;	inv->data[8] =  (data[0]*data[4]-data[1]*data[3])/det;

	    return inv;
    }

	void Print(){
	    for(int i=0;i<9;i++){
		    if((i%3)==0)
			    printf("\n");
		    printf("%f \t",data[i]);
	    }
	    printf("\n");
    }
 };
#endif