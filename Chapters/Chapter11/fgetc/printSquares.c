#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
	if(argc!=4){
		printf("U should only enter four argument in command line.\n");
		return EXIT_FAILURE;
	}
	int start = atoi(argv[1]);
	int end = atoi(argv[2]);
	FILE * f = fopen(argv[3], "w");
	if(f==NULL){
		printf("The file was not exit.\n");
		return EXIT_FAILURE;
	}
	for(int i=start;i<end;i++){
		fprintf(f,"%d\n", i*i);
	}
	if(fclose(f)!=0){
		printf("xxx.\n");
	}
	return EXIT_SUCCESS;
}
