#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char ** argv){
	if(argc!=2){
		printf("U should only enter tow argument in command line.\n");
		exit(EXIT_FAILURE);
	}
	FILE * f = fopen(argv[1], "r");
	if(f==NULL){
		printf("Read fault.\n");
		exit(EXIT_FAILURE);
	}
	int c;
	int letters = 0;
	while((c=fgetc(f))!=EOF){
		if(isalpha(c)){
			letters++;
		}
	}
	printf("%s has %d letters in it\n", argv[1], letters);
	return EXIT_SUCCESS;
}
