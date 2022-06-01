#ifndef __PROVIDED_H__
#define __PROVIDED_H__

typedef struct category_tag{
	char * tag;
	size_t num;
	char ** values;
}category_t;

typedef struct catarray_tag{
	size_t num;
	category_t * category;
}catarray_t;

const char * chooseWord(char * category, catarray_t * cats);

void printWords(catarray_t * cats);

#endif
