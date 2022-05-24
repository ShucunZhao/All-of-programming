/* Description: Read two command line arguments and use the words
 * from second one to fill the '_' of first one randomly.
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

typedef struct storySet_tag{
	char ** storyLine;
	size_t lineNum;
}storySet_t;

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

void writeStory(char * filename, wordSet_t * wordSet){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "File %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	char ** lines2 = NULL;
	char * cur2 = NULL;
	size_t linecap2;
	size_t i = 0;
	while(getline(&cur2, &linecap2, f)>=0){
		lines2 = (char**)realloc(lines2, (i+1)*sizeof(char*));
		lines2[i] = cur2;
		cur2 = NULL;
		i++;
	}
	free(cur2);
	//Save each line of story.
	storySet_t * storySet = (storySet_t*)malloc(sizeof(storySet_t));
	storySet->lineNum = i;
	storySet->storyLine = (char**)malloc(storySet->lineNum*sizeof(char*));
	char * sep = "_";
	for(size_t j=0;j<i;j++){
		if(strchr(lines2[j], '_')!=NULL){
			char * newLines = lines2[j];//Key step1: You must copy the line to a new variable because the
										//strsep() function would make it be NULL at last, which will cause
										//the getline() function couldn't free the line to make the leak of 
										//memory.
			char * newStr = NULL;
			char * fill = NULL;
			size_t lenNew = strlen(newLines);
			size_t lenTok;
			size_t lenFill;
			char * token = strsep(&newLines, sep);
			int flag = 1;//The flag to determine if the first time to realloc memory for initialization.
			while(token[strlen(token)-1]!='\n'){
				lenTok = strlen(token);
				fill = randomWord(wordSet);
				lenFill = strlen(fill);
				newStr = (char*)realloc(newStr, (lenNew+lenTok+lenFill+1)*sizeof(char));
				if(flag){//Key step2: You must inital the pointer if there is the first time to create 
						//because the strcat() function is start with the founded '\0', and the first
						//created memory addresses are assigned random.
					newStr[0]='\0';
					flag=0;
				}
				strcat(newStr, token);
				strcat(newStr, fill);
				lenNew = strlen(newStr);
				token = strsep(&newLines, sep);
			}
			lenNew = strlen(newStr);
			lenTok = strlen(token);
			newStr = (char*)realloc(newStr, (lenNew+lenTok+1)*sizeof(char));
			strcat(newStr, token);
			storySet->storyLine[j] = newStr;
			//fprintf(stdout, "%s", storySet->storyLine[j]);
			//free(storySet->storyLine[j]);
			free(lines2[j]);
		}
		else{
			storySet->storyLine[j] = lines2[j];
			//fprintf(stdout, "%s", storySet->storyLine[j]);
			//free(storySet->storyLine[j]);
		}
	}
	//Printf the story lines and free the memory.
	printf("story:\n");
	for(size_t k=0; k<storySet->lineNum;k++){
		fprintf(stdout, "%s", storySet->storyLine[k]);
		free(storySet->storyLine[k]);
		//free(lines2[k]);
	}
	free(storySet->storyLine);
	free(storySet);
	free(lines2);

	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close!\n", filename);
		exit(EXIT_FAILURE);
	}
}

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
	writeStory(argv[1], wordSet);
	freeMem(wordSet);
	return EXIT_SUCCESS;
}
