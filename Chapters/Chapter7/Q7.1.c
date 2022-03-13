#include<stdio.h>

int pascal(int i, int j){
	if(i<j){
		return 0;
	}
	else if(j==0||(i==j)){
		return 1;
	}
	else{
		return (pascal(i-1,j-1)+pascal(i-1,j));
	}
}

int main(){
	int i;
	int j;
	printf("Enter a position:\n");
	printf("The row is:\n");
	scanf("%d", &i);
	printf("The column is:\n");
	scanf("%d", &j);
	printf("The Pascal's triangle value of [%d,%d] is: %d \n", i,j,pascal(i,j));
	return 0;
}
