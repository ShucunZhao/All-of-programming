#include<stdio.h>
#include<math.h>

int myAbs(int n){
	if(n<0){
		return -n;
	}
	else{
		return n;
	}

}

int main(){
	int x;
	printf("Please input an integer number:\n");
	scanf("%d", &x);
	printf("The absolute value of this number is:\n %d", myAbs(x));
	return 0;
}
