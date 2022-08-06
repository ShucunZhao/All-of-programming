#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T>
std::ostream & operator<<(std::ostream & s, const std::vector<T> & v) {
  s << "[";
  for (size_t i = 0; i < v.size(); i++) {
    if (i > 0) {
      s << ", ";
    }
    s << v[i];
  }
  s << "]";
  return s;
}

/*Output:
 * [3]
 * [3, 5]
 * [3, 5, 7]
 * [3, 5, 7, 9]
 * [[3], [3, 5], [3, 5, 7], [3, 5, 7, 9]]
 */

int main(void) {
  std::vector<int> v1;
  std::vector<std::vector<int> > v2;
  for (size_t i =0; i < 4; i++) {
    v1.push_back(2*i+3);//3579
    v2.push_back(v1);//3353573579
    std::cout << v1 << std::endl;
  }
  std::cout << v2 << std::endl;
  return EXIT_SUCCESS;
}
