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
    int n;
    printf("Please enter a integer:\n");
    scanf("%d", &n);
    printFactors(n);
    return 0;
}
