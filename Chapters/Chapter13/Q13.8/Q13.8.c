/* Description: Read two command line arguments and use the second 
 * one's words to fill the first one '_' location randomly.
 * Solution:
 * 1.Read the words file to save into string set(struct).
 * 2.Traverse the story string and find the each '_' location.
 * 3.Delete the '_' char and randomly extract word to fill it.
 * 4.Write output file.
 * 5.Free all memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wordSet_tag{
	char ** words;
	size_t wordNum;
}wordSet_t;

void stripNewline(char * str){
	char * p = strchr(str, '\n');
	if(p!=NULL){
		*p='\0';
	}
}

wordSet_t * readWord(char * filename){
//void readWord(char * filename){//(Verification)
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "File %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	char ** lines = NULL;
	char * cur = NULL;
	size_t linecap;
	size_t i = 0;
	while(getline(&cur, &linecap, f)>=0){
		lines = (char**)realloc(lines, (i+1)*sizeof(char*));
		lines[i] = cur;
		cur = NULL;
		i++;
	}
	free(cur);
	//Save the words to strcut
	wordSet_t * wordSet = (wordSet_t*)malloc(sizeof(wordSet_t));
	wordSet->wordNum = i;
	wordSet->words = (char**)malloc(wordSet->wordNum*sizeof(char*));
	for(size_t j=0;j<i;j++){
		stripNewline(lines[j]);
		wordSet->words[j] = lines[j];
	}
	free(lines);
	/*
	//Verification
	for(size_t k=0;k<wordSet->wordNum;k++){
		printf("word[%ld]:%s\n", k, wordSet->words[k]);
		free(wordSet->words[k]);
	}
	free(wordSet->words);
	free(wordSet);*/
	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close!\n", filename);
		exit(EXIT_FAILURE);
	}
	return wordSet;
}

char * randomWord(wordSet_t * wordSet){
	size_t i = rand()%wordSet->wordNum;
	return wordSet->words[i];
}

void printStory(char * filename, wordSet_t * wordSet){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "File %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	int c;
	while((c=fgetc(f))!=EOF){
		if(c=='_'){
			printf("%s", randomWord(wordSet));
		}
		else{
			printf("%c", c);
		}
	}
	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close!\n", filename);
		exit(EXIT_FAILURE);
	}
}


//void fillStory(){}

//void writeOutput(){}

void freeMem(wordSet_t * wordSet){
	//Free the wordSet related memory.
	for(size_t k=0;k<wordSet->wordNum;k++){
		printf("word[%ld]:%s\n", k, wordSet->words[k]);
		free(wordSet->words[k]);
	}
	free(wordSet->words);
	free(wordSet);
}

int main(int argc, char ** argv){
	if(argc!=3){
		fprintf(stderr, "The number of argument is invalid!\n");
		return EXIT_FAILURE;
	}
	wordSet_t * wordSet = readWord(argv[2]);
	if(wordSet==NULL){
		fprintf(stderr, "Failed to read word!\n");
	}
	printStory(argv[1], wordSet);
	freeMem(wordSet);
	return EXIT_SUCCESS;
}
