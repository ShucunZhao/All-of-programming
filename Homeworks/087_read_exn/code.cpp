#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>

class Something {
  int x;
public:
  Something(int _x): x(_x) {
    std::cout << "Something(" << x << ")\n";
  }
  ~Something() {
    std::cout << "~Something(" << x << ")\n";
  }
};

int g(int a, int b) {
  Something(99);
  int divisor = a + b;//-3,-2,-1,0
  if (divisor == 0) {
    throw std::domain_error("Division by zero");
  }
  return (a-b) / (divisor);//26,39,79,
}

int f(int x) {//x=-40
  int total = 0;
  Something(42);//This is the unamed temporary object that would be destructed after this line.
  for (int i = 37; i <= 42; i++) {
    total += g (x, i);//g(-40,37):26,g(-40,38):65,g(-40,39):144,g(-40,40):
  }
  return total;
}
/*Output:
 * Something(1)
 * Something(7)
 * Something(3)
 * ~Something(3)
 * Something(42)
 * ~Something(42)
 * Something(99)
 * ~Something(99)
 * Something(99)
 * ~Something(99)
 * Something(99)
 * ~Something(99)
 * Something(99)
 * ~Something(99)
 * ~Something(7)
 * A domain error (Division by zero) occured!
 * At the end of main
 * ~Something(1)
 */
int main(void) {
  Something s1(1);
  try {
    Something s2(7);
    Something (3);  //read this line carefully.....
    int answer = f(-40);
    std::cout << "The answer is " << answer << "\n";
  }
  catch (std::out_of_range & re) {
    std::cout << "A range exception (" << re.what() << ") occured!\n";
  }
  catch (std::domain_error & de ) {
    std::cout << "A domain error (" << de.what() << ") occured!\n";
  }
  catch (std::exception & e) {
    std::cout << "An exception (" << e.what() << " ) occured!\n";
  }
  std::cout << "At the end of main \n";
  return EXIT_SUCCESS;
}
