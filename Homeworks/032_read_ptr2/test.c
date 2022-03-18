#include <stdio.h>
#include <stdlib.h>

int f(int ** r, int ** s) {
  int temp = **r;   //80
  int temp2 = **s;  //12
  int * z = *r;     //z--p--&a
  *r = *s;          //p--&b
  *s = z;           //q--&a
  printf("**r = %d\n", **r);//
  printf("**s = %d\n", **s);
  *z += 3;             //a=a+3=83
  **s -= 8;            //a=a-8=75
  **r -= 19;           //b=b-19=-7
  return temp + temp2;  //-7+75=68
}

int main(void) {
  int a = 80;
  int b = 12;
  int * p = &a;
  int * q = &b;
  int x = f(&p, &q);
  printf("x = %d\n", x);
  printf("*p = %d\n", *p);
  printf("*q = %d\n", *q);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  return EXIT_SUCCESS;
}
