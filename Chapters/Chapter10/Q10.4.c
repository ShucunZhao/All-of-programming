#include <stdio.h>

long mystrtol(char * str, char ** endptr, int base){
	_Bool flag=0;	
	while(*str==' '){
		str++;
	}
	if(*str=='+'){
		str++;
	}
	if(*str=='-'){
		flag=1;
		str++;
	}
	if(base==0||base==10){
		if(*str<'0'||*str>'9'||*str=='\0'){
			endptr=NULL;
			printf("The string part:%s\n", *endptr);
			return 0;
		}
		int i=0; 
		while(*str>='0'&&*str<='9'&&*str!='\0'){
			i=i*10+*str-'0';
			str++;
		}
		endptr=&str;
		printf("The string part:%s\n", *endptr);
		if(flag){
			i=-i;
		}
		return i;
	}
	else if(base==16){
		int n = 6;
		int filter[6]={-1,-1,-1,-1,-1,-1};
		int decimal=0;
		int k=1;
		int i;
		while(((*str-'A')<=5&&*str!='\0')||(*str>='0'&&*str<='9'&&*str!='\0')){
			n--;
			if(*str>='0'&&*str<='9'){
				i=*str-'0';
				filter[n]=i;
				str++;
				continue;
			}
			if((*str-'A')<=5){
				if(*str==' '){
					str++;
					continue;
				}
				i=*str-'A'+10;
				filter[n]=i;
				str++;
				continue;
			}
		}
		for(int j=0;j<6;j++){
			if(filter[j]==-1){
				continue;
			}
			decimal = decimal+k*filter[j];
			k*=16;
		}
		endptr=&str;
		printf("The string part:%s\n", *endptr);
		return decimal;
	}
	else{
		endptr=NULL;
		printf("The string part:%s\n", *endptr);
		return 0;
	}
}

int main(){
	char str[] = " A45 this is test.";
	char * endptr;
	long ret;
	ret = mystrtol(str,&endptr,16);
	printf("The number part:%ld\n", ret);
//	printf("The string part:%s\n", endptr);
	return 0;
}
