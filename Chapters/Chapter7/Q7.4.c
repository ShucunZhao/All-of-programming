#include<stdio.h>

void g(int x){//The recursion should use the frame to check the data flowing.In here, the order is f(42)-g(42)-g(4)-g(0), so the printf order should be g(0)-g(4)-g(42)-f(42), then it totally printf 42\n.
	if(x!=0){
		g(x/10);
		printf("%d", x%10);
	}
}

void f(int x){
	if(x<0){
		printf("-");
		g(-x);
	}
	else if(x==0){
		printf("0");
	}
	else{
		g(x);
	}
	printf("\n");
}

int main(){
	f(42);
	f(-913);
	return 0;
}
//42
//(f(-913)-g(913)..-g(91)..-g(9)..-g(0))
//-913
//
