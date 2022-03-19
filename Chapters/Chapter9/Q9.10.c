#include <stdio.h>

int arrayContains(int *array, size_t n, int toFind){
	for(int i=0; i<n; i++){
		if(*array==toFind){
			return 1;
		}
		array++;
	}
	return 0;
}

int main(){
	int n;
	int i_set[14] = {10,5,2,7,-5,6,-8,0,-3,-5,8,-2,7,-6};
	printf("Please enter a toFind number:\n");
	scanf("%d", &n);
	if(arrayContains(i_set, 14, n)){
		printf("i_set contains %d.\n", n);
	}
	else{
		printf("Didn't find %d.\n", n);
	}
	return 0;
}
