#include<stdio.h>

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
    for(int i=0; i<=1000; i++){
	if(i==0){
	    printf("The binary2 of '%d' is:%d", i, i);
	}
	else{
	    printBinary2(i);
	}
	printf("\n");
    }
}
