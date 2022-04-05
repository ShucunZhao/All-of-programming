#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char ** argv){
	if(argc!=2){
		printf("Please enter tow command line auguments.\n");
		return EXIT_FAILURE;
	}
	FILE * f = fopen(argv[1], "r");
	if(f==NULL){
		printf("Open %s failed.\n", argv[1]);
		return EXIT_FAILURE;
	}
	char c;
	int n=0;
	int counter=0;
	while((c=fgetc(f))!=EOF){
//		printf("counter:%d\n",counter);
		if(counter>71){
			printf("This is invalid FEN board.\n");
			return EXIT_FAILURE;
		}
		if(c=='/'){
			counter++;
			if(n==8){
				printf("\n");
				n=0;
			}
			else{
				printf("This is invalid FEN board.\n");
				return EXIT_FAILURE;
			}
		}
		else if(isdigit(c)){
			int i = c-'0';
			for(int j=0;j<i;j++){
				printf(" ");
				counter++;
				n++;
			}
		}
		else{
			counter++;
			printf("%c", c);
			n++;
		}
	}
	if(fclose(f)!=0){
		printf("file %s close failed.\n", argv[1]);
	}
	//printf("counter:%d\n",counter);
	if(counter!=72){
		printf("This is invalid FEN board.\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
