#include <stdio.h>
#include <stdlib.h>

int & f(int * ptr, int & r) {//ptr -- data[1], r -- 9(data[3])
  r ++;//data -- {6,8,8,10,10}
  ptr[3] += r;//The ptr[3] is data[5] out of bound so the data -- {6,8,47,10,20}//final
  return ptr[1];//ptr[1] -- data[3]
}

int main(void) {
  int data[] = {6, 7, 8, 9,10};
  int & x = data[1];//x -- 7
  x = data[2];// data -- {6, 8, 8, 9, 10}
  int * p = &x;//p -- 8(data[1])
  f(p, data[3]) = 47;//
  for (int i = 0; i < 5; i++) {
    printf("data[%d] = %d\n", i, data[i]);
  }
  printf("x = %d\n", x);
  return EXIT_SUCCESS;
}
/*Output:
 * 1. data[0] = 6
 * 	  data[1] = 8
 * 	  data[2] = 47
 * 	  data[3] = 10
 * 	  data[4] = 20
 * 	  x = 8
 */ 	  
