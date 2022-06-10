#include <cstdio>
#include <cstdlib>
#include <cassert>

class Square{
private:
	double edgeLength;
public:
	void setEdgeLength(double inputLength){
		assert(("The edge length must be non-negative.", inputLength>=0));
		edgeLength = inputLength;	
	}
	double getEdgeLength() const {
		return edgeLength;
	}
	double getArea() const {
		return edgeLength*edgeLength;
	}
	double getPerimeter() const {
		return 4*edgeLength;
	}
};

int main(void){
	Square square[4];
	for(int i=0;i<4;i++){
		square[i].setEdgeLength(2*i+2);
	}
	for(int i=0;i<4;i++){
		printf("Square %d has edge length %f\n", i, square[i].getEdgeLength());
		printf("   and area %f\n", square[i].getArea());
		printf("   and perimeter %f\n", square[i].getPerimeter());
	}
	printf("Trying to set a negative edge length (should abort)\n");
	square[0].setEdgeLength(-1);
	return EXIT_FAILURE;
}
