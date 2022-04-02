#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
	if(argc!=3){
		printf("Please enter two arguments.\n");
		return EXIT_FAILURE;
	}
	FILE * f1 = fopen(argv[1], "r");
	FILE * f2 = fopen(argv[2], "w+");
	if(f1==NULL){
		printf("Couldn't track the file %s.\n", argv[1]);
	}
	int c;
	while((c=fgetc(f1))!=EOF){
		fprintf(f2, "%c", c);
	}
	if(fclose(f1)!=0){
		printf("file %s couldn't close.\n", argv[1]);
	}
	if(fclose(f2)!=0){
		printf("file %s couldn't close.\n", argv[2]);
	}
	return EXIT_SUCCESS;
}
