#include <cstdio>
#include <cstdlib>

class Point {
private:
	int x;
	int y;
public:
	void setLocation(int newX, int newY){
		x = newX;
		y = newY;
	}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	//The return type is a reference of an object.
	Point & operator+=(const Point & rhs){
		x+=rhs.x;
		y+=rhs.y;
		return *this;
	}
	/*
	Point & operator==(const Point & rhs){
		if((x==rhs.getX())&&(y==rhs.getY())){
			return true;
		}
		else{
			return false;
		}
	}
	*/
	//The return type should be bool.
	bool operator==(const Point & rhs) const {
		return x==rhs.getX()&&y==rhs.getY();
	}
	Point & operator*=(int scale){
		x*=scale;
		y*=scale;
		return *this;
	}
};

int main(void){
	Point A;
	A.setLocation(3,4);
	printf("First of A: A.x:%d,A.y:%d\n", A.getX(), A.getY());
	Point B;
	B.setLocation(1,1);
	printf("The B is: B.x:%d,B.y:%d\n", B.getX(), B.getY());
	A+=B;
	printf("After plus: A.x:%d,A.y:%d\n", A.getX(), A.getY());
	Point C;
	C.setLocation(4,5);
	if(A==C){
		printf("A==C\n");
	}
	else{
		printf("A!=C\n");
	}
	return EXIT_SUCCESS;
}
