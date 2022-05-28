#ifndef __OUTNAME_H__	
#define __OUTNAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * computeOutputFileName(const char * inputName);

char * computeOutputFileName(const char * inputName){
	char * suffix = ".counts";
	char * OutputName = (char*)malloc((strlen(inputName)+7+1)*sizeof(char));
	memset(OutputName,'\0',strlen(inputName)+7+1);
	strncpy(OutputName,inputName,strlen(inputName));
	strcat(OutputName,suffix);
	return OutputName;
}

#endif
