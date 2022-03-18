#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y, int acc);

void anstest(unsigned ans, unsigned myResult, int n){
	if(ans!=myResult){
		printf("failure:%d\n",n);
		exit(EXIT_FAILURE);
	}
	printf("success:%d\n",n);
}

int main(){
	//printf("p(2,4):%d", power(2,4));
	anstest(power(2,4,1),16,1);
	anstest(power(-1,0,1),1,2);
	anstest(power(0,0,1),1,3);
	anstest(power(9,9,1),387420489,4);
	return EXIT_SUCCESS;
}
