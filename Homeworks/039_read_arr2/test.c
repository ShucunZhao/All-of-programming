#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NSTRS 3
int main(void) {
  const char * strs[3] = {"apple", "bannana", "carrot"};
  
  for (int i = 0; i < NSTRS; i++) {
    const char * a = strchr(strs[i], 'a');
    a++;
    printf("%c\n", *a);
    printf("%c\n", a[2]);
    a = strstr(strs[i], "nana");
    if (a != NULL) {
      printf("%s has %s %ld characters into it!\n", strs[i], a, a - strs[i]);//Here the a is an address and at the last three location of the strs[i] address.
    }
  }
  const char * ptr = strs[2];
  while (*ptr != '\0') {
    char x = *ptr + 3;
    printf("%c", x);
    ptr++;
  }
  printf("\n");
  return EXIT_SUCCESS;
}
