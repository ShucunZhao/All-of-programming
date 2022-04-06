#include <stdio.h>
#include <stdlib.h>

int* aFunction(int x, int *p, int ** q) {
  printf("x = %d\n", x);
  printf("*p = %d\n", *p);
  printf("**q= %d\n", **q);
  *p = 42;
  /*
   *  int anArray[3][3] = { {1,2,3},
			{4,5,6},
			{42,8,9} };
*/
  **q = 99;
  /*
   *  int anArray[3][3] = { {1,2,3},
			{99,5,6},
			{42,8,9} };
*/
 
  *q = &p[1];
  /*
   *  int anArray[3][3] = { {1,2,3},
			{point to 8,5,6},
			{42,8,9} };
			This step is only point to the '8' address but didn't change the address valure by **q, so after return the frame would be destroyed and the anArray[3][3] would be:
		 int anArray[3][3] = { {1,2,3},
			{99,5,6},
			{42,8,9} };

*/
 
 
  return &p[2];
}

int main (void) {
  int anArray[3][3] = { {1,2,3},
			{4,5,6},
			{7,8,9} };
  int * p = anArray[1];//{4,5,6}
  int * q = aFunction(anArray[0][0], anArray[2], &p);//q point to 9
  for (int i =0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d\n", anArray[i][j]);
    }
  }
  printf("*q=%d\n", *q);

  return EXIT_SUCCESS;
}
