#include<stdio.h>
#include<stdlib.h>

void f(int x){
	int y = abs(x);
	printf("abs of %d is: %d\n", x, y);
	if(y<0){
		printf("abs(%d) = %d. That can't be right!\n", x, y);
	}
}

int main(){
	int x;
	printf("Enter a integer:\n");
	scanf("%d\n", &x);
	f(x);
	return 0;
}
