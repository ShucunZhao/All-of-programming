#include <stdio.h>

unsigned power(unsigned x, unsigned y, unsigned acc){
	if(x==0){
		return 0;
	}
	else if(y==0){
		return acc;
	}
	else{
		return power(x,y-1,acc*x);
	}
}

int main(){
	unsigned x;
	unsigned y;
	printf("Input an integer x:\n");
	scanf("%d", &x);
	printf("Input an integer y:\n");
	scanf("%d", &y);
	printf("The result of %d^%d is: %d\n", x,y,power(x,y,1));
	return 0;
}
