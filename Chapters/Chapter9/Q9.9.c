#include <stdio.h>

int sumArray(int *s, size_t n){
	int sum1 = 0;
	for(int i=0;i<n;i++){
		sum1+=*s;
		s++;
	}
	return sum1;
}

int main(){
	int i_set[14] = {10,5,2,7,-5,6,-8,0,-3,-5,8,-2,7,-6};
	int sum1 = 0;
	for(int i=0;i<14;i++){
		sum1+=i_set[i];
	}
	printf("The sum result of sum1 is: %d\n", sum1);
	printf("The sum result is: %d\n", sumArray(i_set, 14));
	return 0;
}
