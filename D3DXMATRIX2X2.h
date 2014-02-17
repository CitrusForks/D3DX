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

#ifndef CLASS_D3DXD3DXMATRIX2X2
#define CLASS_D3DXD3DXMATRIX2X2

 class D3DXMATRIX2X2{

 public:
	float data[4];
	
	/**Constructor*/
	D3DXMATRIX2X2(){
    }
	
	/**Constructor: creates and sets the matrix to (a00,a01,a10,a11)*/
	D3DXMATRIX2X2(float a00, float a01, float a10, float a11){
        Init(a00, a01, a10, a11);
    }

    /**Init: sets the matrix to (a00,a01,a10,a11)*/
    void Init(float a00, float a01, float a10, float a11){
	    data[0] = a00;
	    data[2] = a10;
	    data[1] = a01;
	    data[3] = a11;
    }

    /**Identity: sets the matrix to identity*/
	void Identity(){
	    data[0] = 1.0f;
	    data[3] = 1.0f;
	    data[1] = 0.0f;
	    data[2] = 0.0f;
    }
	
	/**Scale: scales the matrix by val*/
	void Scale(float val){
	    data[0] *= val;
	    data[3] *= val;
	    data[1] *= val;
	    data[2] *= val;
    }
	
	/**Negate: negates the matrix*/
	void Negate(){
	    data[0] = -data[0];
	    data[1] = -data[1];
	    data[2] = -data[2];
	    data[3] = -data[3];
    }

  	/**Add: add operator*/
	D3DXMATRIX2X2 *Add(const D3DXMATRIX2X2 *m, D3DXMATRIX2X2 *out=NULL){
	    if(out==NULL)
		    out = new D3DXMATRIX2X2();

	    out->data[0] = data[0] + m->data[0];
	    out->data[2] = data[2] + m->data[2];
	    out->data[1] = data[1] + m->data[1];
	    out->data[3] = data[3] + m->data[3];
	    return out;
    }

	/**Sub: sub operator*/
	D3DXMATRIX2X2 *Sub(const D3DXMATRIX2X2 *m, D3DXMATRIX2X2 *out=NULL){
	    if(out==NULL)
		    out = new D3DXMATRIX2X2();

	    out->data[0] = data[0] - m->data[0];
	    out->data[2] = data[2] - m->data[2];
	    out->data[1] = data[1] - m->data[1];
	    out->data[3] = data[3] - m->data[3];
	    return out;
    }
	
	/**Mul: mul operator*/
	D3DXMATRIX2X2 *Mul(const D3DXMATRIX2X2 *m, D3DXMATRIX2X2 *out=NULL){
	    if(out==NULL)
		    out = new D3DXMATRIX2X2();

	    out->data[0] = data[0]*m->data[0] + data[1]*m->data[2];
	    out->data[1] = data[0]*m->data[1] + data[1]*m->data[3];

	    out->data[2] = data[2]*m->data[0] + data[3]*m->data[2];
	    out->data[3] = data[2]*m->data[1] + data[3]*m->data[3];

	    return out;
    }
	
	/**Determinant: computes the determinant of the matrix*/
	float D3DXMATRIX2X2::Determinant(){
		return data[0]*data[3] - data[2]*data[1];
	}

	//Inverse of the Matrix
	D3DXMATRIX2X2 *Inverse(D3DXMATRIX2X2 *out=NULL){
	    float det = Determinant();

	    if(fabsf(det)<1e-9f){
		    printf("Determinant is near zero: D3DXMATRIX2X2 *D3DXMATRIX2X2::Inverse()\n");
		    return new D3DXMATRIX2X2(0.0f,0.0f,0.0f,0.0f);
	    }
		
        if(out==NULL)
            out = new D3DXMATRIX2X2(data[3], -data[1], -data[2], data[0]);
        else
            out->Init(data[3], -data[1], -data[2], data[0]);

	    out->Scale(1.0f/det);
	    return out;
    }
    	
	/**Print: outputs the matrix*/
	void Print(){
		printf("\n%3.3f %3.3f \n %3.3f %3.3f\n\n",data[0],data[1],data[2],data[3]);
	}
};
#endif