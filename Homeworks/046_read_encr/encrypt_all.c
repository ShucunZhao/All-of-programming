#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(FILE * f1, int key, FILE * f2){
  int c;
  int i=0;
  //char LINE[1024]={'\0'}
  while ((c = fgetc(f1)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      c += key;//110-92
      c %= 26;//26
      c += 'a';//25+97=122
    }
    //printf("%c", c);
	//LINE[i] = c;
	fprintf(f2, "%c", c);
	i++;
  }
}

int main(int argc, char ** argv) {
  if (argc != 4) {
    fprintf(stderr,"Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f1 = fopen(argv[2], "r");
  FILE * f2 = fopen(argv[3], "w+");
  if (f1 == NULL) {
    perror("Could not open file1.\n");
    return EXIT_FAILURE;
  }
  if (f2 == NULL) {
    perror("Could not open file2.\n");
    return EXIT_FAILURE;
  }
 
  int key = atoi(argv[1]);
  if (key == 0) {
    fprintf(stderr,"Invalid key (%s): must be a non-zero integer\n", argv[1]);
    return EXIT_FAILURE;
  }
 
  encrypt(f1,key,f2);
  if (fclose(f1) != 0||fclose(f2) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
