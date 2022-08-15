#include <iostream>
#include <cstdlib>
#include <vector>

template<typename T>
void f (std::vector<T> & v, const T & d) {//d=12, 42
  typename std::vector<T>::iterator it = v.begin();
  while (it != v.end()) {
    if (*it >= d) {//
      break;
    }
    ++it;
  }
  v.insert(it, d);//[0,1,4,9,12,16,42]
} 
template<typename T>
void g (std::vector<T> & v, const T & a, const T & b) {//a=5, b=4
  typename std::vector<T>::iterator it = v.begin();
  while (it != v.end()) {
    if (*it % a == b) {
      it = v.erase(it);
    }
    else {
      ++it;
    }
  }
}

/*Output:
 * 42 
 * 16
 * 12
 * 1
 * 0
 */

int main(void) {
  std::vector<int> someNums;
  for (int i = 0; i < 5; i++) {
    someNums.push_back (i*i);//[0,1,4,9,16]
  }
  f<int>(someNums, 12);
  f<int>(someNums, 42);//[0,1,4,9,12,16,42]
  g<int>(someNums, 5 , 4);//[0,1,12,16,42]
  std::vector<int>::const_reverse_iterator ri = someNums.rbegin();
  while (ri != someNums.rend()) {
    std::cout << *ri << "\n";
    ++ri;
  }
  return EXIT_SUCCESS;
}
