/*
Note: The printBinary2 function can convert most situation of decimal number,
while the printBinary just only can convert within the maximum of 1023.
 */
#include<stdio.h>

void printBinary(int n){//This method express the binary with integer so that the maximum is 1023(1111111111)
    int origin = n;
    int mode;
    int binary; 
    int bit = 1;
    int times = 20;
    while(n != 0){
        times -= 1;
        if(times == 0){
            printf("Warnining: The input integer is out of 20 bits.\n");
            break;
        }
	mode = n%2;
	binary += mode*bit;
	bit *= 10;
	n /= 2;
    }
    printf("The binary1 of '%d' is: %d\n", origin, binary);
}

void printBinary2(int n){
    int origin2 = n;
    int mode2;
    int binary2[30]={0};
    int index = 0;
    int times2 = 20;
    while(n!=0){
	times2 -= 1;
	if(times2 == 0){
	printf("Warning: The input integer is out of 20 bits.\n");
	break;
	}
	mode2 = n%2;
	binary2[index]=mode2;
	//printf("binary[%d]:%d\n", index, binary2[index]);
	index+=1;
	n/=2;
    }
    printf("The binary2 of '%d' is:", origin2);
    for(int i=(index-1); i>=0; i--){
    //printf("binary2[%d]:%d", i, binary2[i]);
    printf("%d", binary2[i]);
    }
}

int main(){
    int n;
    printf("Please enter an integer which has at most 20 bits:\n");
    scanf("%d", &n);
    printBinary(n);
    printBinary2(n);
}
