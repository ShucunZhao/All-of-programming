#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rand_story.h"
#include "provided.h"

void stripNewline(char * str){
	char * ptr = strchr(str, '\n');
	if(ptr!=NULL){
		*ptr='\0';
	}
}

void readStory(char * filename){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "File %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	//Prepare for separation from '_':
	char * sep = "_";
	char * token = NULL;
	char * New = NULL;
	const char * fill = NULL;
	size_t lenTok;
	size_t lenNew;
	size_t lenFill;
	int first=1;
	int check=0;//Check if double '_'
	//Read and parse the input line:
	char ** lines = NULL;
	char * cur = NULL;
	size_t linecap;
	size_t i = 0;
	while(getline(&cur, &linecap, f)>=0){
		lines = (char**)realloc(lines, (i+1)*sizeof(char*));
		lines[i] = cur;
		char * sub = lines[i];//Key setp: U must define a substitute of lines[i] cause the strsep() 
							//function will change the origin address of line[i] that will lead 
							//the free(lines[i]) to fail(free the new address and lost the origin one.)
		char * checkline = strchr(lines[i],'_');
		if(checkline==NULL){
			fprintf(stderr, "Line %ld format of input file is invalid!\n", i);
			exit(EXIT_FAILURE);
		} 	
		while(*checkline!='\0'){
			if(*checkline=='_'){
				check++;
			}
			checkline++;
		}
		if((check%2)!=0){
			fprintf(stderr, "The number of blanks input file is invalid!\n");
			exit(EXIT_FAILURE);
		} 	
		while(strchr(lines[i],'_')!=NULL){
			/*
			if(*lines[i]=='\n'){
				break;
			}
			*/
			token = strsep(&sub, sep);
			lenTok = strlen(token);
			fill = chooseWord(NULL, NULL);
			lenFill = strlen(fill);
			if(first){	
				New = (char*)realloc(New, (lenTok+lenFill+1)*sizeof(char));
				memset(New,'\0',lenTok+lenFill+1);
				first=0;
			}
			else{
				New = (char*)realloc(New, (lenNew+lenTok+lenFill+1)*sizeof(char));
			}
			strcat(New, token);
			strcat(New, fill);
			lenNew = strlen(New);
			strsep(&sub, sep);
		}
		New = (char*)realloc(New, (lenNew+strlen(sub)+1)*sizeof(char));
		strcat(New, sub);
		fprintf(stdout, "%s", New);
		free(New);
		free(lines[i]);
		cur = NULL;
		//Reset the variables:
		token = NULL;
		New = NULL;
		fill = NULL;
		first=1;
		check=0;//Check if double '
	}
	free(cur);
	free(lines);
	while(fclose(f)!=0){
		fprintf(stderr, "Failed to close file %s\n!", filename);
		exit(EXIT_FAILURE);
	}
}

/*
int main(int argc, char ** argv){
	if(argc!=2){
		fprintf(stderr, "Input command line arguments are invalid!\n");
		return EXIT_FAILURE;
	}
	readStory(argv[1]);
}
*/
