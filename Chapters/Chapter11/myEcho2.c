#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv){
	int flag=1;
	const char * str1 = "-n";
	for(int i=1;i<argc;i++){
		printf(" %s", argv[i]);
		if(strcmp(argv[i], str1)==0){
			flag = 0;
		}
		//printf(" ");
	}
	if(flag){
		printf("\n");
	}
	return 0;
}
