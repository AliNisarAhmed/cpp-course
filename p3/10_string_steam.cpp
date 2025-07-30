#include <iostream>
#include <sstream>
#include <string>
int main() {
  std::ostringstream output;
  const std::string string1{"Output of several data types"};
  const std::string string2{"to an ostringstream object:"};
  const std::string string3{"\ndouble: "};
  const std::string string4{"\n  int: "};

  constexpr double d{123.4567};
  constexpr int i{22};

  output << string1 << string1 << string3 << d << string4 << i;

  std::cout << "output contains:\n" << output.str();

  output << "new characters added\n";

  std::cout << "output now contains ---- \n:" << output.str();
}
