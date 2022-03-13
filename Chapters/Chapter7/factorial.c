#include<stdio.h>

int factorial_loop(int n){
	if(n==0){
		return 1;
	}
	int j = 1;
	for(int i=n;i>0;i--){
		j*=i;
	}
	return j;
}

int factorial_tailRecur(int n, int acc){
	if(n==0){
		return acc;
	}
	return factorial_tailRecur(n-1, n*acc);
}

int main(){
	int n;
	printf("Enter a integer:\n");
	scanf("%d", &n);
	printf("factorial_loop(%d) is: %d \n", n,factorial_loop(n));
	printf("factorial_tailRecur(%d) is: %d \n", n, factorial_tailRecur(n,1));
}
