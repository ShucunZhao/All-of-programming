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

//catarray_t * readWord(char * filename){
void readWord(char * filename){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "File %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	//Create a catarray_t set to store the word info:
	catarray_t * cats = (catarray_t*)malloc(sizeof(catarray_t));
	cats->num = 0;
	cats->category = NULL;
	//Preparation of separation from ':':
	char * sep2 = ":";
	char * token2 = NULL;
	//char * New2 = NULL;
	char * sub2 = NULL;
	char * checkline2 = NULL;
	//size_t = strlen(lenTok2);
	//size_t = strlen(lenNew2);
	int check2;//check if repeated element.
	//Parsing the input words:
	char ** lines2 = NULL;
	char * cur2 = NULL;
	size_t line2cap;
	size_t i = 0;
	while(getline(&cur2, &line2cap, f)>=0){
		check2 = 0;
		lines2 = (char**)realloc(lines2, (i+1)*sizeof(char*));
		lines2[i] = cur2;
		stripNewline(lines2[i]);
		//Check if the ":" is valid:
		checkline2 = strchr(lines2[i],':');
		if(checkline2==NULL){
			fprintf(stderr, "Line %ld format of input file is invalid!\n", i);
			exit(EXIT_FAILURE);
		} 	
		while(*checkline2!='\0'){
			checkline2++;
			if(*checkline2==':'){
				fprintf(stderr, "The number of ':' in line %ld of input file is invalid!\n", i);
				exit(EXIT_FAILURE);
			}
		}
		//Store the cats:
		sub2 = lines2[i]; 
		token2 = strsep(&sub2, sep2);
		//Traverse the crrent set to find the same element:
		for(size_t j=0;j<cats->num;j++){
			if(strcmp(token2, cats->category[j]->tag)==0){
				cats->category[j]->num++;
				cats->category[j]->values = (char**)realloc(cats->category[j]->values, cats->category[j]->num*sizeof(char*));
				cats->category[j]->values[cats->category[j]->num-1] = sub2;
				check2 = 1;
				break;
			}
		}
		if(check2){
			token2 = NULL;
			sub2 = NULL;
			cur2 = NULL;
			i++;
	//		free(lines2[i]);
			continue;
		}
		cats->num++;
		cats->category = (category_t**)realloc(cats->category, cats->num*sizeof(category_t*));
		cats->category[cats->num-1] = (category_t*)malloc(sizeof(category_t));
		cats->category[cats->num-1]->num = 1;
		cats->category[cats->num-1]->tag = token2;
		cats->category[cats->num-1]->values = (char**)malloc(cats->category[cats->num-1]->num*sizeof(char*));
		cats->category[cats->num-1]->values[cats->category[cats->num-1]->num-1] = sub2;
		token2 = NULL;
		sub2 = NULL;
		cur2 = NULL;
		i++;
		//free(token2);
		//free(lines2[i]);
	}
	free(cur2);
	//Verification:
	for(size_t k=0;k<cats->num;k++){
		fprintf(stdout, "%s:\n", cats->category[k]->tag);
	//	free(cats->category[k]->tag);
		for(size_t l=0;l<cats->category[k]->num;l++){
			fprintf(stdout,"  %s\n", cats->category[k]->values[l]);
			//free(cats->category[k]->values[l]);
		}
		free(cats->category[k]->values);
		free(cats->category[k]);
	}
	free(cats->category);
	free(cats);
	free(lines2);
	/*
	free(cats->category);
	for(size_t m=0;m<i;m++){
		free(lines2[i]);
	}
	free(lines2);
	*/
	while(fclose(f)!=0){
		fprintf(stderr, "Failed to close file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	//return cats;
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
	char * sub = NULL;//Store the substitute of lines
	char * checkline = NULL;//Check the numer of "_"
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
		sub = lines[i];//Key setp: U must define a substitute of lines[i] cause the strsep() 
							//function will change the origin address of line[i] that will lead 
							//the free(lines[i]) to fail(free the new address and lost the origin one.)
		checkline = strchr(lines[i],'_');
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

int main(int argc, char ** argv){
	if(argc!=2){
		fprintf(stderr, "Input command line arguments are invalid!\n");
		return EXIT_FAILURE;
	}
	//readStory(argv[1]);
	readWord(argv[1]);
}
