/* Description:
 * Read the first input file and pare the "=" sign
 * to second part "key"="value", then read the second
 * file to match the key and cout the time they occur,
 * for example, input1:
 *	Jean Luc Picard=Captain
	Will Riker=Commander
	Beverly Crusher=Commander
	Data=Lt. Commander
	Geordi LaForge=Lt. Commander
	Worf=Lt. Commander
	Deanna Troi=Commander
  	input2:
	Jean Luc Picard
	Will Riker
	Worf
	Deanna Troi
	Q
	output:
	Captain: 1
	Commander: 2
	Lt. Commander: 1
	<unknown> : 1
 * =======Step=======
 * 1.Read file1 to generate the key/value pairs(call it kv)	
 * 2.Count from 2 to argc(call it i)
 * 3.Count values appear in argv[i] and use kv as key to pair(call it c)
 * 4.Compute output file name from argv[i](call it outName) 
 * 5.Open file named by outName(call it f) and print the counts from c
 *   into the FILE f
 * 6.Free outName and kv memory
*/

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

//void readKv(char * filename){//(Verification)
kvSet_t * readKv(char * filename){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "The argument %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	//Store all input file to line Set:
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
	kvSet_t * kvSet = (kvSet_t*)malloc(sizeof(kvSet_t));
	kvSet->kvNum = i;
	kvSet->kvpair = (kvpair_t**)malloc(kvSet->kvNum*sizeof(kvpair_t*));
	char * sep = "=";
	//size_t lenKey;
	//size_t lenVal;
	for(size_t j=0;j<i;j++){
		stripNewline(lines[j]);//Strip the '\n'
		//char * newline = lines[j];//Same reason with Q13.8_plus(prevent the strsep make the lines[j] be null)	
		if(strchr(lines[j], '=')==NULL){
			fprintf(stderr, "The line%ld of input file is invalid\n", j);
			exit(EXIT_FAILURE);
		}
		//char * token = strsep(&newline, sep);
		char * token = strsep(&lines[j], sep);
		//lenKey = strlen(token);
		//lenVal = strlen(newline);
		//malloc the mem for kvpair
		kvSet->kvpair[j] = (kvpair_t*)malloc(sizeof(kvpair_t));
		//kvSet->kvpair[j]->key = (char*)malloc(lenKey*sizeof(char));//We don't need to create new memory to save
																	//cause we have created when malloc the kvSet->kvpair[j] 
	  	kvSet->kvpair[j]->key = token;
		//fprintf(stdout, "The key is: %s\n", kvSet->kvpair[j]->key);
		//kvSet->kvpair[j]->value = (char*)malloc(lenVal*sizeof(char));
		kvSet->kvpair[j]->value = lines[j];	
		//fprintf(stdout, "The value is: %s\n", kvSet->kvpair[j]->value);
		//free(kvSet->kvpair[j]);
		//free(lines[j]);
	}
	free(lines);
	/*(Verification)
	//Print the result and free the related memory.	
	for(size_t k=0; k<kvSet->kvNum; k++){
		fprintf(stdout, "The key is: %s\n", kvSet->kvpair[k]->key);
		fprintf(stdout, "The value is: %s\n", kvSet->kvpair[k]->value);
		free(kvSet->kvpair[k]->key);
		//free(kvSet->kvpair[k]->value);
		//free(lines[k]);
		free(kvSet->kvpair[k]);
		//free(lines[k]);
	}	
	free(kvSet->kvpair);
	free(kvSet);
	*/
	//free(lines);
	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close\n", filename);
		exit(EXIT_FAILURE);
	}
	return kvSet;
}

void countInput(char * filename, kvSet_t * kv){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "Input file %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	//Store the input file list:
	char ** lines2 = NULL;
	char * cur2 = NULL;
	size_t linecap2;
	size_t i = 0;
	while(getline(&cur2, &linecap2, f)>=0){
		lines2 = (char**)realloc(lines2, (i+1)*sizeof(char*));
		lines2[i] = cur2;
		stripNewline(lines2[i]);
		cur2 = NULL;
		i++;
	}
	free(cur2);
	//Generate the unique list:
	int first=1;
	int flag1;
	int flag2;
	int flag3 = 0;
	uniqSet_t * uniqSet = (uniqSet_t*)malloc(sizeof(uniqSet_t));
	for(size_t j=0;j<i;j++){
		flag2=0;
		flag1=0;
		for(size_t k=0;k<kv->kvNum;k++){
			if(strcmp(lines2[j],kv->kvpair[k]->key)==0){
				if(first){
					uniqSet->num = 1;
					uniqSet->countSet = (count_t**)malloc(uniqSet->num*sizeof(count_t*));
					uniqSet->countSet[uniqSet->num-1] = (count_t*)malloc(uniqSet->num*sizeof(count_t));
					uniqSet->countSet[uniqSet->num-1]->Val = kv->kvpair[k]->value;
					uniqSet->countSet[uniqSet->num-1]->Count = 1;
					first=0;
					flag3=1;
					continue;
				}
				for(int l=0;l<uniqSet->num;l++){
					if(strcmp(kv->kvpair[k]->value,uniqSet->countSet[l]->Val)==0){
						uniqSet->countSet[l]->Count++;
						flag1=1;
						break;
					}
				}
				if(flag1){
					continue;
				}
				uniqSet->num++;
				uniqSet->countSet = (count_t**)realloc(uniqSet->countSet, uniqSet->num*sizeof(count_t*));
				uniqSet->countSet[uniqSet->num-1] = (count_t*)malloc(uniqSet->num*sizeof(count_t));
				uniqSet->countSet[uniqSet->num-1]->Val = kv->kvpair[k]->value;
				uniqSet->countSet[uniqSet->num-1]->Count = 1;
				flag2=1;
			}
		}
		if(flag3){
			flag3 = 0;
			free(lines2[j]);
			continue;
		}
		if(flag2||flag1){
			free(lines2[j]);
			continue;
		}
		//Unknow part:
		char * unknow = (char*)malloc(10*sizeof(char));
		unknow = "<unknow>";
		if(first){
			uniqSet_t * uniqSet = (uniqSet_t*)malloc(sizeof(uniqSet_t));
			uniqSet->num = 1;
			uniqSet->countSet = (count_t**)malloc(uniqSet->num*sizeof(count_t*));
			uniqSet->countSet[uniqSet->num-1]->Val = unknow;
			uniqSet->countSet[uniqSet->num-1]->Count = 1;
			first=0;
			free(lines2[j]);
			continue;
		}
		uniqSet->num++;
		uniqSet->countSet = (count_t**)realloc(uniqSet->countSet, uniqSet->num*sizeof(count_t*));
		uniqSet->countSet[uniqSet->num-1] = (count_t*)malloc(uniqSet->num*sizeof(count_t));
		uniqSet->countSet[uniqSet->num-1]->Val = unknow;
		//free(unknow);
		uniqSet->countSet[uniqSet->num-1]->Count = 1;
		free(lines2[j]);
	}
	free(lines2);
	for(size_t m=0;m<uniqSet->num;m++){
		fprintf(stdout, "%s: %ld", uniqSet->countSet[m]->Val, uniqSet->countSet[m]->Count);
		fprintf(stdout, "\n");
		free(uniqSet->countSet[m]);
	}
	//free(unknow);
	free(uniqSet->countSet);
	free(uniqSet);
	//free(unknow);
	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close!\n", filename);
		exit(EXIT_FAILURE);
	}
}

//void printFile(){}

void freeMem(kvSet_t * kvSet){
	//Print the result and free the related memory.	
	for(size_t k=0; k<kvSet->kvNum; k++){
		fprintf(stdout, "The key is: %s\n", kvSet->kvpair[k]->key);
		fprintf(stdout, "The value is: %s\n", kvSet->kvpair[k]->value);
		free(kvSet->kvpair[k]->key);
		//free(kvSet->kvpair[k]->value);
		//free(lines[k]);
		free(kvSet->kvpair[k]);
		//free(lines[k]);
	}	
	free(kvSet->kvpair);
	free(kvSet);
}

int main(int argc, char ** argv){
	if(argc<3){
		fprintf(stderr, "The command line argument is invalid!\n");
		return EXIT_FAILURE;
	}
	kvSet_t * kv = readKv(argv[1]);
	if(kv==NULL){
		fprintf(stderr, "kvSet is invalid!\n");
		return EXIT_FAILURE;
	}
	for(int i=2;i<argc;i++){
		countInput(argv[i], kv);
	}
	freeMem(kv);
	return EXIT_SUCCESS;
}
