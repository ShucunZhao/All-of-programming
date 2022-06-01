#ifndef __PROVIDED_H__
#define __PROVIDED_H__

typedef struct category_tag{
	char * name;
	size_t n_words;
	char ** words;
}category_t;

typedef struct catarray_tag{
	size_t n;
	category_t * arr;//Key point: U must use one pointer(not double pointer) here!
						 //Like char* the category_t * also can point at many element of
						 //category_t in category_t * set.
}catarray_t;

const char * chooseWord(char * category, catarray_t * cats);

void printWords(catarray_t * cats);

#endif
