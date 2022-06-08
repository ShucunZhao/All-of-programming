#ifndef _RAND_STORY_H__
#define _RAND_STORY_H__
#include "provided.h"

void stripNewline(char * str);

catarray_t * deleteWord(catarray_t * cats, char * ditto);

catarray_t * readWord(char * filename);

void readStory(char * filename);

void replaceWord(char * filename, catarray_t * cats, int mode);

void freeWordMem(catarray_t * cats);

#endif
