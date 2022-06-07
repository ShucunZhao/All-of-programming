#ifndef __PROVIDED_H__
#define __PROVIDED_H__

#include <stdlib.h>

typedef struct category_tag {
  char * name;
  char ** words;
  size_t n_words;
}category_t;

typedef struct catarray_tag {
  category_t * arr;
  size_t n;
}catarray_t;

const char * chooseWord(char * category, catarray_t * cats);

void printWords(catarray_t * cats);

#endif
