#ifndef CLASS_D3DXVECTOR2INT
#define CLASS_D3DXVECTOR2INT

class D3DXVECTOR2INT{
public:
	int		x, y;

	D3DXVECTOR2INT(){
	}

	D3DXVECTOR2INT(int x, int y){
		this->x = x;
		this->y = y;
	}

	bool isTheSame(const D3DXVECTOR2INT &a){
		return ((a.x==x)&&(a.y==y));
	}

	//Clip the vertex to a box [0,w-1] x [0,h-1]
	void Clip(int width, int height){
		//X clipping
		x = x>(width-1) ? (width-1) : x;
		x = x<0 ? 0 : x;
		//Y clipping
		y = y>(height-1) ? (height-1) : y;
		y = y<0 ? 0 : x;
	}
};
#endif