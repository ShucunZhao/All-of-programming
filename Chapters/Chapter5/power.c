#include<stdio.h>

double power(double x, int y){
    if(y==0){
	return 1;
    }
    else{
	for(int i=1; i<y; i++){
	    x*=x;
	}
	return x;
    }
}

double fun(double x, int y){
    int i;
    double s=1;
    for(i=1; i<=y; i++){
	s*=x;
    }
    return s;
}

int main(){
    for(int x=0; x<=5; x++){
	for(int y=0; y<=16; y++){
	    if((x==0)&&(y==0)){
		printf("0^0 is nonsense.\n");
	    }
	    else{
		printf("The result of %d^%d is: %.lf \n", x, y, fun(x, y));//'%.lf' means round the result.
	    //Some results look strange because the out of the maximum bits of int type.
	    }
	}
    }
    return 0;
}
