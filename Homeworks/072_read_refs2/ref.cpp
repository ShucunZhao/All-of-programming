#include <iostream>
#include <cstdlib>

class AClass {
private:
  int x;
  int y;
public:
  AClass(): x(0), y(0) {
    std::cout << "Making AClass\n";
  }
  AClass(int _x, int _y): x(_x), y(_y) {
    std::cout << "Making AClass(" << x << "," << y << ")\n";
  }
  ~AClass() {
    std::cout << "Destroying AClass(" << x << "," << y << ")\n";
  }
  int & max()  {
    if (x > y) {
      return x;
    }
    return y;
  }
  void set(int _x, int _y) {
    x = _x;
    y = _y;
  }
  int getX() const { return x; }
  int getY() const { return y; }
};

AClass * someFunction(int a, int b) {//(4,2)
  AClass * x = new AClass(a+2, b*8);//(6,16)
  AClass y(a*4-3,b+2);//(13,4)
  x->max() = y.max() - 3;//This step is let the max element of x equal to the max element of y:
  //x.y = y.x = 10;
  //x is (6,10)
  return x;
}

int main(void) {
  AClass a(3,4);
  int & r = a.max();//r == 4(cause y is larger so r is reference of a.y)
  AClass * b = someFunction(r,2);//b==x(6,10)
  a.set(b->getY(), b->getX() - 3);//a-(3,4)-(10,3)
  delete b;
  r = 9;//a.y = 9--a is (10,9)
  return EXIT_SUCCESS;
}
/* Output:
 * Making AClass(3,4)
 * Making AClass(6,16)
 * Making AClass(13,4)
 * Destroying AClass(13,4)
 * Destroying AClass(6,10)
 * Destroying AClass(10,3)
 */








