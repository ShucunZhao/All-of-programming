#include <stdio.h>

char buffer2[30]={'\0'};

void printHex(unsigned x, char buffer[], int acc){//This is tail-recursion.
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

char * printHex2(int x){//This is normal recursion.
	static int i = 0;
	if(x<16){
		if(x<10){
			buffer2[i]=x+'0';
		}
		else{
			buffer2[i]=x-10+'A';
		}
	}
	else{
		printHex2(x/16);
		i++;
		x%=16;
		if(x<10){
			buffer2[i]=x+'0';
		}
		else{
			buffer2[i]=x-10+'A';
		}
	}
	return buffer2;	
}

int main(){
	char buffer[30]={'\0'};
	char * ans_str;
	unsigned x;
	printf("Enter an unsigned int:\n");
	scanf("%d", &x);
	printf("The hexadecimal format of %d from printHex is:",x);
	printHex(x,buffer,0);
	printf("\n");
	ans_str=printHex2(x);
	printf("The hexadecimal format of %d from printHex2 is: %s\n",x,ans_str);
	return 0;
}
