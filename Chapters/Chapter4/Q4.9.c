#include<stdio.h>

unsigned int power(unsigned int x, unsigned int y){
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

int main(){
    unsigned int x, y;
    printf("Please enter x:\n");
    scanf("%d", &x);
    printf("Please enter y:\n");
    scanf("%d", &y);
    printf("The result of %d^%d is:\n %d", x, y, power(x,y));
    return 0;
}
