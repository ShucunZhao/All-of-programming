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

//void countInput(char * filename, kvSet_t * kv){//(Verification)
uniqSet_t * countInput(char * filename, kvSet_t * kv){
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
	int flag;//Used for judging if there has same value in existed list. 
	int check;//Used for checking if find the correspond value in kvpair set.
	char * curVal = NULL;//Used for saving the current value parsed in lines2.
	uniqSet_t * uniqSet = (uniqSet_t*)malloc(sizeof(uniqSet_t));
	uniqSet->num = 0;//At first there is empty set.
	uniqSet->countSet = NULL;//Let it be NULL and realloc it after find the new value.
	/*
	 * Key step here: 
	 * 1.We can't just use char unknow[8] = "<unknow>" here cause when this function return
	 *   the unknow will be released and the unknow pointer would point to somewhere we didn't define
	 * 2.We can't use unknow = "<unknow>" after char * unknow = (char*)malloc(9*sizeof(char))
	 *   because "<unknow>" is a constant and has its address, if u let pointer unknow you malloc point
	 *   to it you will lose your previously allocated memory, so you must use strcpy(strncpy is more 
	 *   save cause it check the number of element to copy) instead.
	 */
	char * unknow = (char*)malloc(9*sizeof(char));
	memset(unknow,'\0', 9);//Initial the element with '\0'
	strncpy(unknow, "<unknow>", 9);//Must do this.
	for(size_t j=0;j<i;j++){
		//Step1: Reset these two factor when parsing a new input.
		flag = 0;
		check = 0;
		//Step2.1: Find the correspond element in kvpair.
		for(size_t k=0;k<kv->kvNum;k++){
			if(strcmp(lines2[j],kv->kvpair[k]->key)==0){
				curVal = kv->kvpair[k]->value;
				check = 1;
				break;
			}
		}
		//Step2.2: If didn't find related key in kvpairs, 
		// 		   let the current value be "<unknow>"
		if(!check){
			/*
			if(unknow==NULL){
				unknow = (char*)malloc(sizeof(*unknow));
				unknow = "<unknow>";
			}
			*/
			curVal = unknow;
		}
		//Step3.1: Check if there has same element in current count set.
		for(size_t l=0;l<uniqSet->num;l++){
			if(strcmp(curVal, uniqSet->countSet[l]->Val)==0){
				uniqSet->countSet[l]->Count++;
				flag=1;
				break;
			}
		}
		//Step3.3: If found, continue to next lines2[j].
		if(flag){
			free(lines2[j]);
			continue;
		}
		//Step4: If didn't find, realloc new place to save the new value.
		uniqSet->num++;
		uniqSet->countSet = (count_t**)realloc(uniqSet->countSet, uniqSet->num*sizeof(count_t*));
		uniqSet->countSet[uniqSet->num-1] = (count_t*)malloc(sizeof(count_t));
		uniqSet->countSet[uniqSet->num-1]->Val = curVal;
		uniqSet->countSet[uniqSet->num-1]->Count = 1;
		free(lines2[j]);
	}
	free(lines2);
	/*//(Verification)	
	for(size_t m=0;m<uniqSet->num;m++){
		fprintf(stdout, "%s: %ld", uniqSet->countSet[m]->Val, uniqSet->countSet[m]->Count);
		fprintf(stdout, "\n");
		free(uniqSet->countSet[m]);
	}
	free(uniqSet->countSet);
	free(uniqSet);
	*/
	//free(unknow);
	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close!\n", filename);
		exit(EXIT_FAILURE);
	}
	//free(uniqSet->countSet[0]->Val);
	//free(unknow);
	return uniqSet;
}

void printFile(char * filename, uniqSet_t * uniqSet){
	char * newFileName = (char*)malloc((strlen(filename)+6+1)*sizeof(char));
	memset(newFileName,'\0',strlen(filename)+6+1);
	char * suffix = ".count";
	strncpy(newFileName, filename, strlen(filename));
	strcat(newFileName, suffix);
	FILE * f = fopen(newFileName, "w");
	for(size_t i=0; i<uniqSet->num;i++){
		fprintf(f, "%s: %ld\n", uniqSet->countSet[i]->Val, uniqSet->countSet[i]->Count);
	}
	free(newFileName);
	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close!\n", filename);
		exit(EXIT_FAILURE);
	}
}

void uniqFreeMem(uniqSet_t * uniqSet){

	//Define the unknow if you find it in uniqSet->countSet[]->Val you should free it.	
	char unknow1[9] = {'<','u','n','k','n','o','w','>','\0'};
	int flag = 1;//This flag is to check if the <unknow> be free.
	
	//Print the unique counting set and free the related memory. 
	for(size_t m=0;m<uniqSet->num;m++){
		fprintf(stdout, "%s: %ld", uniqSet->countSet[m]->Val, uniqSet->countSet[m]->Count);//If find unknow, free it!
		fprintf(stdout, "\n");
		
		if((strcmp(uniqSet->countSet[m]->Val, unknow1)==0)&&(flag=1)){
			free(uniqSet->countSet[m]->Val);
			flag=0;
		}
		
		free(uniqSet->countSet[m]);
	}
	free(uniqSet->countSet);
	free(uniqSet);
}

void kvFreeMem(kvSet_t * kvSet){
	//Print the kvpairs and free the related memory.	
	for(size_t k=0; k<kvSet->kvNum; k++){
		fprintf(stdout, "key = '%s' value = '%s'\n", kvSet->kvpair[k]->key, kvSet->kvpair[k]->value);
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
		uniqSet_t * outName = countInput(argv[i], kv);
		if(outName==NULL){
			fprintf(stderr, "outName is invalid!\n");
		}
		fprintf(stderr, "===========\n");
		printFile(argv[i], outName);
		uniqFreeMem(outName);
	}
	kvFreeMem(kv);
	return EXIT_SUCCESS;
}
