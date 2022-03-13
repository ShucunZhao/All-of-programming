/*************************************************************************
	> File Name: fibonacii.c
	> Author: ShucunZhao
	> Mail: zhaoshucun@neworldkey.com
	> Created Time: Fri 11 Mar 2022 08:14:45 PM CST
 ************************************************************************/

#include<stdio.h>

int fibonacii(int n){
	if(n<0){
		if(n%2==0){
			return -fibonacii(-n);
		}
		else{
			return fibonacii(-n);
		}
	}
	else if(n==0||n==1){
		return n;
	}
	else{
		return (fibonacii(n-1)+fibonacii(n-2));
	}
}

int main(){
	int n;
	printf("Input an integer n:\n");
	scanf("%d", &n);
	printf("The fibonacii of '%d' is: %d \n", n, fibonacii(n));
	return 0;
}
