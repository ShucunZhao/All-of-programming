#include <stdio.h>

int myatoi(const char * str){
	_Bool flag=1;
	while(*str==' '){
		str++;
	}
	if(*str=='+'){
		str++;
	}
	if(*str=='-'){
		flag = 0;
		str++;
	}
	if(*str<'0'||*str>'9'||*str=='\0'){
		return 0;
	}
	int i = 0;
	while(*str>='0'&&*str<='9'&&*str!='\0'){
		i=i*10+*str-'0';
		str++;
	}
	if(!flag){
		printf("-");
	}
	return i;
}

int main(){
	const char str[]="  -345xcr";
	printf("The result of convertion is:\n");
	printf("%d\n", myatoi(str));
	return 0;
}
