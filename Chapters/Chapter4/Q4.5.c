#include<stdio.h>

bool isPow2(int n){
	if(n==0){
	    return 0;
	}
	else{
	    if((n&(n-1))==0){
 	        return 1;
	    }
	    else{
			return 0;
	    }
	} 
}

int main(){
	int n;
	printf("Please enter an integer: \n");
	scanf("%d", &n);
	// printf("%d\n", n&(n-1));
	// printf("%d\n", isPow2(n));
	if(n<0){
	printf("Negative number is not a power of 2.");
	}
	else{
	    if(isPow2(n)==1){
	    printf("The number '%d' is a power of 2", n);
	    }
	    else{
	    printf("The number '%d'is not a power of 2\n", n);
	    }
	}
	return 0;
}
