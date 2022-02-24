#include<stdio.h>

bool isPerfect(int n){
    int j=1;//'1' is a minimum factor of all integer.
    for(int i=2; i<n; i++){
	if(n%i==0){
	    j=j+i;
	}
    }
    if(j==n){
	return 1;
    }
    else{
	return 0;
    }
}

int main(){
    int n;
    printf("Please enter an integer:\n");
    scanf("%d", &n);
    if(isPerfect(n)){
	printf("The number '%d' is perfect.\n", n);
    }
    else{
	printf("The number '%d' isn't perfect.\n", n);
    }
    return 0;
}
