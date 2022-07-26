#include <string>
#include <iostream>
#include <cstdlib>


std::string f(std::string x) {//"Apple" "pple"
  if (x=="") {
    return "";
  }
  char first = x[0];//'A' 'p'
  std::string rest = x.substr(1);//"pple" "ple" ""
  std::cout << "first = " << first << " and rest = " << rest << std::endl;
  std::string ans = f(rest);// // // // // ans = ""
  ans.push_back(first);//'e'//
  std::cout << "ans = " << ans << std::endl;
  return ans;
}

int main(void) {
  std::string start("Apple");
  std::string ans = f(start);
  std::cout << "f(" << start << ") = " << ans << std::endl;
  return EXIT_SUCCESS;
}
/* Output:
 * first = "A" and rest = "pple"
 * first = "p" and rest = "ple"
 * first = "p" and rest = "le"
 * first = "l" and rest = "e"
 * first = "e" and rest = 
 * ans = e
 * ans = el
 * ans = elp
 * ans = elpp
 * ans = elppA
 * f(Apple) = elppA
 */
