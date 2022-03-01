#include<stdio.h>

void printFactors(int n){//This problem is up to if u can use the right type of loop 'for-loop'. 
    if(n>1){
	for(int i=2; i<=n; i++){
	    while(n%i==0){
		printf("%d", i);
		n/=i;
		if(n!=1){
		    printf(" * ");
		}
	    }
	}
    }
    else{
    printf("Warning: The minimum prime number is 2, please enter an integer larger than 1.");
    }
}

int main(){
    for(int i=2; i<=1000; i++){
	printf("The factors of '%d' is:", i);
	printFactors(i);
	printf("\n");
    }
    return 0;
}
