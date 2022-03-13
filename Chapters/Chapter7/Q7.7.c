#include <stdio.h>

void printHex(unsigned x, char buffer[], int acc){
	unsigned mod;
	mod=x%16;
	if(mod<=9){
		//buffer[acc]=(char)mod;
		buffer[acc] = mod + '0';
	}
	else if(mod==10){
		buffer[acc]='A';
	}
	else if(mod==11){
		buffer[acc]='B';
	}
	else if(mod==12){
		buffer[acc]='C';
	}
	else if(mod==13){
		buffer[acc]='D';
	}
	else if(mod==14){
		buffer[acc]='E';
	}
	else{
		buffer[acc]='F';
	}
	if(x/16==0){
		for(int i=acc; i>=0; i--){
			printf("%c", buffer[i]);
		}
		return;
	}
	x/=16;
	printHex(x, buffer, acc+1);
}

int main(){
	char buffer[30];
	unsigned x;
	printf("Enter an unsigned int:\n");
	scanf("%d", &x);
	printf("The hexadecimal format of %d is:",x);
	printHex(x,buffer,0);
	printf("\n");
	return 0;
}
