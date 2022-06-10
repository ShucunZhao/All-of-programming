#include <stdio.h>
#include <stdlib.h>

class MyClass {
private:
  int x;
  int y;
public:
  void setPoints(int newx, int newy) { 
    x = newx;
    y = newy;
  }
  void doStuff(const MyClass & p);
  int computeSomething() const {
    return x *3 + y -2;//a: 43*3+18-2=129+16=145
						//b: 22*3 + 40 -2 = 66+40-2=104
						//b: 6*3+5-2=21
						//c: 27+3-2=28
						//c: 21*3+39-2=61+39=100
						//a: 43*3+18-2=129+16=145
  }
};

void printMessage(const MyClass * m1) {
  printf("%p has %d\n", m1, m1->computeSomething());
}
void MyClass::doStuff(const MyClass & p) {
  x = p.y + 3;
  y = p.x - 4;
  printMessage(this);
  printMessage(&p);
}

int main(void) {
  MyClass a;
  MyClass b;
  MyClass c;
  a.setPoints(1,1);//a.x=1,a.y=1
  b.setPoints(22,40);//b.x=22,b.y=40
  c.setPoints(9,3);//c.x=9,c.y=3
  a.doStuff(b);//a.x=40+3=43, a.y=22-4=18
  b.doStuff(c);//b.x=3+3=6,b.y=9-4=5
  c.doStuff(a);//c.x = 18+3=21,c.y=43-4=39
  return EXIT_SUCCESS;
}
/*Output:
* 1. 0x4050 has 145
* 2. 0x4080 has 104
* 3. 0x4080 has 21
* 4. 0x40B0 has 28
* 5. 0x40B0 has 100
* 6. 0x4050 has 145
*/


