#ifndef CLASS_D3DXVECTOR3INT
#define CLASS_D3DXVECTOR3INT

class D3DXVECTOR3INT{
public:
	int		x, y, z;
	
	D3DXVECTOR3INT(){
	}

	D3DXVECTOR3INT(int x, int y, int z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	bool isTheSame(const D3DXVECTOR3INT &a){
		return ((a.x==x)&&(a.y==y)&&(a.z==z));
	}

  	int operator [](int i) const{
		switch(i){
			case 0:
				return x; break;
			case 1:
				return y; break;
			case 2:
				return z; break;
		}
		return -1;
	}

 	int &operator [](int i){
		switch(i){
			case 0:
				return x; break;
			case 1:
				return y; break;
			case 2:
				return z; break;
		}
		return x;
	}
};

#endif