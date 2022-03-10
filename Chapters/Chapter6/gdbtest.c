#include<stdio.h>
int factorial(int n){
	int ans=1;
	for(int i=1; i<=n; i++){
		ans = ans*i;
	}
	return ans;
}
int main(){
	int x = factorial(3);
	printf("factorial(3) = %d\n", x);
	return 0;
}
