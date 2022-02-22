#include<stdio.h>
int fratorial(int n){
	if(n>0){
	int j =1;
	for(int i=1; i<=n; i++){
		j=j*i;		
	}
	return j;
	}
	else{
	return 1;
	}
}

int main(){
	int x;
	printf("Enter an integer:\n");
	scanf("%d", &x);
	if (x<0){
	printf("Warning: Please enter the 0 or positive integer!");
	}
	else{
	printf("The fratorial of '%d' is:%d", x, fratorial(x));
	}
	return 0;
}
