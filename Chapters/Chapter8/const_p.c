#include <stdio.h>

int main(){
	const int y = 3;
	int * q = &y;
	printf("int:%d\n", y);
	printf("int * q :%*d\n", *q);
	*q = 4;
	printf("int:%d\n", y);
	printf("int * q:%*d\n", *q);
	return 0;
}
