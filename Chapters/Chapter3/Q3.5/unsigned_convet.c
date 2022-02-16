#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	char binaryScanf[256];
	int intBinaryScanf[256];
	long int decimal = 0;

	scanf("%s", binaryScanf);
	for(int i=0, j=strlen(binaryScanf); i < strlen(binaryScanf); i++){
		intBinaryScanf[i] = binaryScanf[--j] - '0';
	}
	for(int i=0; i<strlen(binaryScanf); i++){
		decimal += intBinaryScanf[i]*(int)pow(2,i);

	}
	printf("%lu\n", decimal);
	return 0;
}
