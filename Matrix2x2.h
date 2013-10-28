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

#ifndef CLASS_MATRIX2X2
#define CLASS_MATRIX2X2

 class Matrix2x2{

 public:
	float data[2][2];
	
	//Constructor
	Matrix2x2();
	
	//Constructor
	Matrix2x2(float a00, float a01, float a10, float a11);


	//Identity Matrix
	void Identity();
	
	//Scaling
	void Scale(float val);

	//Addition of matricies
	Matrix2x2 *Add(Matrix2x2 *m, Matrix2x2 *out);
	
	//Negate
	void	  Negate();

	//Subtraction of matricies
	Matrix2x2 *Sub(Matrix2x2 *m, Matrix2x2 *out);
	
	//Multiplication of matricies
	Matrix2x2 *Mul(Matrix2x2 *m, Matrix2x2 *out);

	//Inverse of the Matrix
	Matrix2x2 *Inverse();
	
	//Determinant of the Matrix
	float Matrix2x2::Determinant(){
		return data[0][0]*data[1][1]-data[1][0]*data[0][1];
	}

	
	//Print Matrix
	void Print(){
		printf("\n%3.3f %3.3f \n %3.3f %3.3f\n\n",data[0][0],data[0][1],data[1][0],data[1][1]);
	}
 };

//Constructor
Matrix2x2::Matrix2x2(){
};

//Constructor
Matrix2x2::Matrix2x2(float a00, float a01, float a10, float a11){
	data[0][0]=a00;
	data[1][0]=a10;
	data[0][1]=a01;
	data[1][1]=a11;
};

//Identity Matrix
void Matrix2x2::Identity(){
	data[0][0]=1.0f;
	data[1][1]=1.0f;
	data[0][1]=0.0f;
	data[1][0]=0.0f;
};

//Negate
void Matrix2x2::Negate(){
	data[0][0]=-data[0][0];
	data[0][1]=-data[0][1];
	data[1][0]=-data[1][0];
	data[1][1]=-data[1][1];
};

//Scaling
void Matrix2x2::Scale(float val){
	data[0][0]*=val;
	data[1][1]*=val;
	data[0][1]*=val;
	data[1][0]*=val;
};

//Addition of matricies
Matrix2x2 *Matrix2x2::Add(Matrix2x2 *m, Matrix2x2 *out=NULL){
	if(out==NULL)
		out = new Matrix2x2();

	out->data[0][0] = data[0][0]+m->data[0][0];
	out->data[1][0] = data[1][0]+m->data[1][0];
	out->data[0][1] = data[0][1]+m->data[0][1];
	out->data[1][1] = data[1][1]+m->data[1][1];
	return out;
};

//Subtraction of matricies
Matrix2x2 *Matrix2x2::Sub(Matrix2x2 *m, Matrix2x2 *out=NULL){
	if(out==NULL)
		out = new Matrix2x2();

	out->data[0][0] = data[0][0]-m->data[0][0];
	out->data[1][0] = data[1][0]-m->data[1][0];
	out->data[0][1] = data[0][1]-m->data[0][1];
	out->data[1][1] = data[1][1]-m->data[1][1];
	return out;
};


//Multiplication of matricies
Matrix2x2 *Matrix2x2::Mul(Matrix2x2 *m, Matrix2x2 *out=NULL){
	if(out==NULL)
		out = new Matrix2x2();

	out->data[0][0] = data[0][0]*m->data[0][0]+data[0][1]*m->data[1][0];
	out->data[0][1] = data[0][0]*m->data[0][1]+data[0][1]*m->data[1][1];

	out->data[1][0] = data[1][0]*m->data[0][0]+data[1][1]*m->data[1][0];
	out->data[1][1] = data[1][0]*m->data[0][1]+data[1][1]*m->data[1][1];

	return out;
};

//Determinant of the Matrix
Matrix2x2 *Matrix2x2::Inverse(){
	float det = Determinant();

	if(fabsf(det)<1e-9f){
		printf("Determinant is near zero: Matrix2x2 *Matrix2x2::Inverse()\n");
		return new Matrix2x2(0.0f,0.0f,0.0f,0.0f);
	}
		
	Matrix2x2 *ret=new Matrix2x2(data[1][1], -data[0][1], -data[1][0], data[0][0]);
	ret->Scale(1.0f/det);
	return ret;
};
#endif