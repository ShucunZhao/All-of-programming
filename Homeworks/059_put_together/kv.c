#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

void stripNewline(char * str){
	char * p = strchr(str, '\n');
	if(p!=NULL){
		*p='\0';
	}
}

kvSet_t * readKv(char * filename){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "The argument %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}

	//Define the KvSet info:
	kvSet_t * kvSet = (kvSet_t*)malloc(sizeof(kvSet_t));
	kvSet->kvNum = 0;
	kvSet->kvpair = NULL;
	char * sep = "=";

	//Parsing each line of input file and generate the kvpairs:
	char ** lines = NULL;
	char * cur = NULL;
	size_t linecap;
	size_t i = 0;
	while(getline(&cur, &linecap, f)>=0){
		lines = (char**)realloc(lines, (i+1)*sizeof(char*));
		lines[i] = cur;
		stripNewline(lines[i]);//Strip the '\n'
							  //char * newline = lines[j];//Same reason with Q13.8_plus(prevent the strsep make the lines[j] be null)	
		if(strchr(lines[i], '=')==NULL){
			fprintf(stderr, "The line%ld of input file is invalid\n", i);
			exit(EXIT_FAILURE);
		}
		//Cutting the line with symbol "=":
		kvSet->kvNum++; 
		kvSet->kvpair = (kvpair_t**)realloc(kvSet->kvpair, kvSet->kvNum *sizeof(kvpair_t*));
		kvSet->kvpair[i] = (kvpair_t*)malloc(sizeof(kvpair_t));
		char * token = strsep(&lines[i], sep);
		kvSet->kvpair[i]->key = token;
		kvSet->kvpair[i]->value = lines[i];	
		///////////////////
		cur = NULL;
		i++;
	}
	free(cur);
	free(lines);

	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close\n", filename);
		exit(EXIT_FAILURE);
	}
	return kvSet;
}

void kvFreeMem(kvSet_t * kvSet){
	//Print the kvpairs and free the related memory.	
	for(size_t k=0; k<kvSet->kvNum; k++){
		fprintf(stdout, "key = '%s' value = '%s'\n", kvSet->kvpair[k]->key, kvSet->kvpair[k]->value);
		free(kvSet->kvpair[k]->key);//Free the head of address is enough
		//free(kvSet->kvpair[k]->value);
		free(kvSet->kvpair[k]);
		//free(lines[k]);
	}	
	free(kvSet->kvpair);
	free(kvSet);
}

/*
int main(int argc, char ** argv){
	if(argc<1){
		fprintf(stderr, "Input command line arguments are invalid!\n");
		return EXIT_FAILURE;
	}
	kvSet_t * kv = readKv(argv[1]);
	if(kv==NULL){
		fprintf(stderr, "kvSet is invalid!\n");
		return EXIT_FAILURE;
	}
	kvFreeMem(kv);
	return EXIT_SUCCESS;
}
*/
