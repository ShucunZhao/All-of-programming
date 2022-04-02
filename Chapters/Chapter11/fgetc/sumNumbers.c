#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 5
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
	long total = 0;
	char line[LINE_SIZE];
	while(fgets(line, LINE_SIZE, f)!=NULL){
		if(strchr(line,'\n')==NULL){
			printf("Line is too long.\n");
			return EXIT_FAILURE;
		}
		total+=atoi(line);
	}
	printf("Total is: %ld", total);
	return EXIT_SUCCESS;
}
