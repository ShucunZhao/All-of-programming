#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rand_story.h"
#include "provided.h"

void stripNewline(char * str){
	char * ptr = strchr(str, '\n');
	if(ptr!=NULL){
		*ptr='\0';
	}
}

//char * findFill(char * label){}

catarray_t * deleteWord(catarray_t * cats, char * ditto){
	catarray_t * temp = (catarray_t*)malloc(sizeof(catarray_t));
	temp->n = 0;
	temp->arr = NULL;
	for(size_t i=0;i<cats->n;i++){
		temp->n++;
		temp->arr = (category_t*)realloc(temp->arr, temp->n*sizeof(category_t));
		temp->arr[i].name = (char*)malloc((strlen(cats->arr[i].name)+1)*sizeof(char));
		memset(temp->arr[i].name,'\0',strlen(cats->arr[i].name)+1);
		strncpy(temp->arr[i].name,cats->arr[i].name,strlen(cats->arr[i].name));
		temp->arr[i].n_words = 0;
		temp->arr[i].words = NULL;
		for(size_t j=0;j<cats->arr[i].n_words;j++){
			if(strcmp(ditto, cats->arr[i].words[j])==0){
				free(cats->arr[i].words[j]);
				continue;//Skip the ditto word
			}
			temp->arr[i].n_words++;
			temp->arr[i].words = (char**)realloc(temp->arr[i].words, temp->arr[i].n_words*sizeof(char*));
			temp->arr[i].words[temp->arr[i].n_words-1] = (char*)malloc((strlen(cats->arr[i].words[j])+1)*sizeof(char));
			memset(temp->arr[i].words[temp->arr[i].n_words-1],'\0',strlen(cats->arr[i].words[j])+1);
			strncpy(temp->arr[i].words[temp->arr[i].n_words-1],cats->arr[i].words[j],strlen(cats->arr[i].words[j]));
			free(cats->arr[i].words[j]);
		}
		free(cats->arr[i].words);
		free(cats->arr[i].name);
	}
	free(cats->arr);
	free(cats);
	free(ditto);
	return temp;
}

void replaceWord(char * filename, catarray_t * cats, int mode){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "File %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	//Prepare for separation from '_':
	char * sep = "_";
	char * label = NULL;
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
	//Create a new double pointer catarray_t to save the fill words set
	size_t setNum = 0;
	catarray_t * fillSet = NULL;
	int index;
	int check2;
	//Selected mode:(-n)
	int check3;
	int first2=1;
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
		while(strchr(sub,'_')!=NULL){
 			token = strsep(&sub, sep);
			label = strsep(&sub, sep);
			//Find the replace word place and the template content
			//Check if the label length is 1 to determine wheter it is number.
			if(strlen(label)==1){
				if(isdigit(*label)){
					check2=0;
					index = atoi(label);
					//Traverse the fillSet to find the represent index element
					for(size_t x=0;x<setNum;x++){
						if(index==(int)fillSet[x].n){
							fill = fillSet[x].arr->words[0];
							fillSet[x].n=1;//If find represent element, let it's index be 1.
							check2=1;
							continue;
						}
						fillSet[x].n++;//Let other non-found element index accumulate
					}
					if(!check2){//If didn't find any represent element, there was a error index.
						fprintf(stderr, "The template number %s is invalid!\n", label);
						exit(EXIT_FAILURE);
					}
				}
				else{
					fprintf(stderr, "The template %s is invalid!\n", label);//Error: length is 1 but isn't number
				}
			}
			else{//If template isn't number, add the new fill element.
				for(size_t y=0;y<setNum;y++){
					fillSet[y].n++;
				}
				//Find the first shouw fill word.
				fill = chooseWord(label, cats);
				if(mode==1&&(!first2)){//Check if the selected mode:
					check3=0;
					for(size_t g=0;g<setNum;g++){
						if(strcmp(fill,fillSet[g].arr->words[0])==0){
							char * ditto = (char*)malloc((strlen(fill)+1)*sizeof(char));
							memset(ditto,'\0',strlen(fill)+1);
							strncpy(ditto, fill, strlen(fill));
							cats = deleteWord(cats, ditto);//Cause the random seed is certain so that the return word is same each time
													      //If u want to return a non-reuse word u should delete the used one from the cats
							check3 = 1;	
							break;
						}
					}
					if(check3){
						fill = chooseWord(label, cats);
					}
				}
				//After found the fill, reset the size of fill words set and add it:
				setNum++;
				fillSet = (catarray_t*)realloc(fillSet, setNum*sizeof(catarray_t));
				fillSet[setNum-1].n=1;
				fillSet[setNum-1].arr = (category_t*)malloc(sizeof(category_t));
				fillSet[setNum-1].arr->words=(char**)malloc(sizeof(char*));
				fillSet[setNum-1].arr->words[0]=(char*)malloc((strlen(fill)+1)*sizeof(char));
				memset(fillSet[setNum-1].arr->words[0], '\0', strlen(fill)+1);
				strncpy(fillSet[setNum-1].arr->words[0], fill, strlen(fill));//copy it!
				first2=0;//Close the first button.
			}
			//After determining the final fill word, do the splice step:
			lenFill = strlen(fill);
			lenTok = strlen(token);
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
		}
		New = (char*)realloc(New, (lenNew+strlen(sub)+1)*sizeof(char));
		strcat(New, sub);
		fprintf(stdout, "%s", New);
		free(New);
		cur = NULL;
		free(lines[i]);
		i++;
		//Reset the variables:
		token = NULL;
		New = NULL;
		fill = NULL;
		first=1;
		check=0;//Check if double '
	}
	free(cur);
	free(lines);
	for(size_t z=0;z<setNum;z++){
		free(fillSet[z].arr->words[0]);	
		free(fillSet[z].arr->words);
		free(fillSet[z].arr);
	}
	free(fillSet);
	//Key step: If in mode 1, you should free the new generated cats in deleteWord here!
	//Other mode would free cats in freeWordMem out of the replaceWord box.
	if(mode==1){
		freeWordMem(cats);
	}
	while(fclose(f)!=0){
		fprintf(stderr, "Failed to close file %s\n!", filename);
		exit(EXIT_FAILURE);
	}
}

catarray_t * readWord(char * filename){
//void readWord(char * filename){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "File %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	//Create a catarray_t set to store the word info:
	catarray_t * cats = (catarray_t*)malloc(sizeof(catarray_t));
	cats->n = 0;
	cats->arr = NULL;
	//Preparation of separation from ':':
	char * sep2 = ":";
	char * token2 = NULL;
	char * sub2 = NULL;//Key setp:Same effect as sub in func readStory
	char * checkline2 = NULL;
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
				fprintf(stderr, "The number of ':' in line %ld of input file %s is invalid!\n", i, filename);
				exit(EXIT_FAILURE);
			}
		}
		//Store the cats:
		sub2 = lines2[i]; 
		token2 = strsep(&sub2, sep2);
		//Traverse the crrent set to find the same element:
		for(size_t j=0;j<cats->n;j++){
			if(strcmp(token2, cats->arr[j].name)==0){
				cats->arr[j].n_words++;
				cats->arr[j].words = (char**)realloc(cats->arr[j].words, cats->arr[j].n_words*sizeof(char*));
				//Key Step: the values must malloc the memory to save, if you just make it point to 
				//sub2 that will lead to cannot free the lines2[i].
				cats->arr[j].words[cats->arr[j].n_words-1] = (char*)malloc((strlen(sub2)+1)*sizeof(char));
				memset(cats->arr[j].words[cats->arr[j].n_words-1],'\0',strlen(sub2)+1);
				strncpy(cats->arr[j].words[cats->arr[j].n_words-1], sub2, strlen(sub2)+1);
				check2 = 1;
				break;
			}
		}
		if(check2){
			cur2 = NULL;
			free(lines2[i]);
			i++;
			//free(lines2[i]);
			//Reset the variables:
			token2 = NULL;
			sub2 = NULL;
			continue;
		}
		cats->n++;
		cats->arr = (category_t*)realloc(cats->arr, cats->n*sizeof(category_t));
		cats->arr[cats->n-1].n_words = 1;
		//Key Step: the tag and values must malloc the memory to save, if you just make it point to 
		//the token2 or sub2 that will lead to cannot free the lines2[i].
		cats->arr[cats->n-1].name = (char*)malloc((strlen(token2)+1)*sizeof(char));
		memset(cats->arr[cats->n-1].name,'\0',strlen(token2)+1);
		strncpy(cats->arr[cats->n-1].name, token2, strlen(token2)+1);
		cats->arr[cats->n-1].words = (char**)malloc(cats->arr[cats->n-1].n_words*sizeof(char*));
		cats->arr[cats->n-1].words[cats->arr[cats->n-1].n_words-1] = (char*)malloc((strlen(sub2)+1)*sizeof(char));
		memset(cats->arr[cats->n-1].words[cats->arr[cats->n-1].n_words-1],'\0',strlen(sub2)+1);
		strncpy(cats->arr[cats->n-1].words[cats->arr[cats->n-1].n_words-1], sub2, strlen(sub2)+1);
		//free lines2 related mem
		cur2 = NULL;
		free(lines2[i]);//Must free it before i++
		i++;
		//Reset the variables:
		token2 = NULL;
		sub2 = NULL;
		//free(token2);
	}
	free(cur2);
	free(lines2);
	/*
	//Verification:
	for(size_t k=0;k<cats->num;k++){
		fprintf(stdout, "%s:\n", cats->category[k]->tag);
		free(cats->category[k]->tag);
		for(size_t l=0;l<cats->category[k]->num;l++){
			fprintf(stdout,"  %s\n", cats->category[k]->values[l]);
			free(cats->category[k]->values[l]);
		}
		free(cats->category[k]->values);
		free(cats->category[k]);
	}
	free(cats->category);
	free(cats);
	*/
	while(fclose(f)!=0){
		fprintf(stderr, "Failed to close file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return cats;
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
		while(strchr(sub,'_')!=NULL){
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
		//free(lines[i]);
		cur = NULL;
		free(lines[i]);
		i++;
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

void freeWordMem(catarray_t * cats){
	for(size_t k=0;k<cats->n;k++){
		fprintf(stdout, "%s:\n", cats->arr[k].name);
		free(cats->arr[k].name);
		for(size_t l=0;l<cats->arr[k].n_words;l++){
			fprintf(stdout,"  %s\n", cats->arr[k].words[l]);
			free(cats->arr[k].words[l]);
		}
		free(cats->arr[k].words);
	}
	free(cats->arr);
	free(cats);
}

/*
int main(int argc, char ** argv){
	int mode = 0;
	if(argc==4){
		if(strcmp(argv[1], "-n")==0){
			mode=1;
		}
		else{
			fprintf(stderr, "The selective argument %s is invalid!\n", argv[1]);
			return EXIT_FAILURE;
		}
		//readStory(argv[1]);
		catarray_t * cats = readWord(argv[2]);
		if(cats==NULL){
			fprintf(stderr, "The cats is invalid!\n");
			return EXIT_FAILURE;
		}
		replaceWord(argv[3], cats, mode);
	//	freeWordMem(cats);
	}
	else if(argc==3){
		//readStory(argv[1]);
		catarray_t * cats = readWord(argv[1]);
		if(cats==NULL){
			fprintf(stderr, "The cats is invalid!\n");
			return EXIT_FAILURE;
		}
		replaceWord(argv[2], cats, mode);
		freeWordMem(cats);
	}
	else{
		fprintf(stderr, "Input command line arguments are invalid!\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
*/
