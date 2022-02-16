#include <iostream>
#include <math.h>
using namespace std;

int euclid(int x, int y){
	printf("euclid(%d, %d)\n", x, y);
	int l = max(x,y);
	int m = min(x, y);
	if (m==0){
		return l;
	}	
	return euclid(m, l%m);
}

int main(){
	int a = euclid(9135, 426);
	printf("a = %d\n", a);
	return EXIT_SUCCESS;
}
