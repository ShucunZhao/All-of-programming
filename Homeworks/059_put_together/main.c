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
#include "outname.h"
#include "counts.h"

counts_t * countInput(char * filename, kvSet_t * kv){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "Input file %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	//Store the input file list and count the info:
	counts_t * counts = createCounts();
	char * curVal = NULL;//Used for saving the current value parsed in lines2.
	int check;//Used for checking if find the correspond value in kvpair set.
	//Traverse the input file:
	char ** lines2 = NULL;
	char * cur2 = NULL;
	size_t linecap2;
	size_t i = 0;
	while(getline(&cur2, &linecap2, f)>=0){
		check=0;
		lines2 = (char**)realloc(lines2, (i+1)*sizeof(char*));
		lines2[i] = cur2;
		stripNewline(lines2[i]);
		//Find the correspond element in kvpair:
		for(size_t k=0;k<kv->kvNum;k++){
			if(strcmp(lines2[i],kv->kvpair[k]->key)==0){
				curVal = kv->kvpair[k]->value;
				check = 1;
				break;
			}
		}
		if(!check){
			curVal = NULL;
		}
		addCount(counts, curVal);
		free(lines2[i]);
		cur2 = NULL;
		i++;
	}
	free(cur2);
	free(lines2);
	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close!\n", filename);
		exit(EXIT_FAILURE);
	}
	return counts;
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
		counts_t * counts = countInput(argv[i], kv);
		if(counts==NULL){
			fprintf(stderr, "outName is invalid!\n");
		}
		printCounts(counts, computeOutputFileName(argv[i]));
		freeCounts(counts);
	}
	kvFreeMem(kv);
	return EXIT_SUCCESS;
}
