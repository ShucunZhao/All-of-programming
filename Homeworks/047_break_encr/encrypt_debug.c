#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//f-input.txt,r
//key: 5
//void encrypt(FILE * f, int key){
void encrypt(char * f, int key){
  //int c;
  while (*f!='\0') {
	char c = *f;
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      c += key;
      c %= 26;
      c += 'a';
    }
	f++;
    printf("%c", c);
  }
}

int main() {
  /*if (argc != 3) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  int key = atoi(argv[1]);//key:5
  if (key == 0) {
    fprintf(stderr,"Invalid key (%s): must be a non-zero integer\n", argv[1]);
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[2], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }*/
  char f[11]="An example\0";
  int key=5;
  encrypt(f,key);
  /*if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }*/
  return EXIT_SUCCESS;
}
