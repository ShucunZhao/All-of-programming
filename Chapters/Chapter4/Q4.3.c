#include <stdio.h>
int myRound(double d){
	int m;
	if(d>=0.0){
	m=(int)(d+0.5);
	}
	else{
	m=(int)(d-0.5);
	}
	return m;
}

int main(){
	double d;
	printf("Please enter a double type number:\n");
	scanf("%lf",&d);
	printf("The rounded value from myRound of '%lf' is: %d\n", d, myRound(d));
	return 0;
}
