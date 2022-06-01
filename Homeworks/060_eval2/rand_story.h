#ifndef _RAND_STORY_H__
#define _RAND_STORY_H__
#include "provided.h"

void stripNewline(char * str);

catarray_t * readWord(char * filename);

void readStory(char * filename);

void replaceWord(char * filename, catarray_t * cats);

void freeWordMem(catarray_t * cats);

#endif
