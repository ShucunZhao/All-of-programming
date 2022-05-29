#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName){
	char * suffix = ".counts";
	char * OutputName = (char*)malloc((strlen(inputName)+7+1)*sizeof(char));
	memset(OutputName,'\0',strlen(inputName)+7+1);
	strncpy(OutputName,inputName,strlen(inputName));
	strcat(OutputName,suffix);
	return OutputName;
}
/*
int main(int argc, char ** argv){
	if(argc!=2){	
		fprintf(stderr, "Input command line arguments are invalid!\n");
		return EXIT_FAILURE;
	}
	const char * inputName = argv[1];
	if(inputName==NULL){
		fprintf(stderr, "Input file name %s is invalid!\n", argv[1]);
		return EXIT_FAILURE;
	} 
	char * OutputName = computeOutputFileName(inputName);
	if(OutputName==NULL){
		fprintf(stderr, "Output file name %s is invalid!\n", OutputName);
		return EXIT_FAILURE;
	} 
	fprintf(stdout, "Input name: %s, Output name: %s\n", inputName, OutputName);
	free(OutputName);
	return EXIT_SUCCESS;
}
*/
