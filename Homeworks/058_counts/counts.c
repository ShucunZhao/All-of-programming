#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void){
	counts_t * counts = (counts_t*)malloc(sizeof(counts_t));
	counts->nums = 0;
	counts->countInfo = NULL;
	//unknow part:
	counts->unknow = (countInfo_t*)malloc(sizeof(countInfo_t));
	char * unknowVal = "<unknow>";
	counts->unknow->value = (char*)malloc((strlen(unknowVal)+1)*sizeof(char));
	memset(counts->unknow->value,'\0',strlen(unknowVal)+1);
	strncpy(counts->unknow->value,unknowVal,strlen(unknowVal)+1);
	counts->unknow->times = 0;
	return counts;
}

void addCount(counts_t * counts, const char * name){
	int flag=0;
	if(name==NULL){
		counts->unknow->times++;		
	}
	else{
		for(size_t i=0;i<counts->nums;i++){
			if(strcmp(counts->countInfo[i]->value, name)==0){
				counts->countInfo[i]->times++;
				flag=1;
				break;
			}
		}
		if(!flag){
			counts->nums++;
			counts->countInfo = (countInfo_t**)realloc(counts->countInfo, counts->nums*sizeof(countInfo_t*));
			counts->countInfo[counts->nums-1] = (countInfo_t*)malloc(sizeof(countInfo_t));
			counts->countInfo[counts->nums-1]->times=1;
			
			size_t nameLen = strlen(name);
			counts->countInfo[counts->nums-1]->value = (char*)malloc((nameLen+1)*sizeof(char));
			memset(counts->countInfo[counts->nums-1]->value,'\0',nameLen+1);
			strncpy(counts->countInfo[counts->nums-1]->value,name,nameLen+1);
			
			//strcpy(counts->countInfo[counts->nums-1]->value,name);
		}
	}
}

void printCounts(counts_t * counts, FILE * f){
	for(size_t i=0;i<counts->nums;i++){
		fprintf(f, "%s: %ld\n", counts->countInfo[i]->value,counts->countInfo[i]->times);
	}
	if(counts->unknow->times>0){
		fprintf(f, "%s : %ld\n", counts->unknow->value, counts->unknow->times);
	}
}

void freeCounts(counts_t * counts){
	for(size_t i=0;i<counts->nums;i++){
		free(counts->countInfo[i]->value);
		free(counts->countInfo[i]);
	}
	free(counts->countInfo);
	free(counts->unknow->value);
	free(counts->unknow);
	free(counts);
}
