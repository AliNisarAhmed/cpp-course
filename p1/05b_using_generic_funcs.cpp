#include "05a_maximum.h"
#include <iostream>

int main() {
  std::cout << "Input 3 ints\n";

  int i1, i2, i3;
  std::cin >> i1 >> i2 >> i3;

  std::cout << "max: " << maximum(i1, i2, i3) << '\n';

  double d1, d2, d3;
  std::cout << "Input 3 doubles\n";
  std::cin >> d1 >> d2 >> d3;

  std::cout << "max double: " << maximum(d1, d2, d3) << '\n';
}
