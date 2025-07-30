#include <sstream>
int main() {
  const std::string inputString{"Atonia test 123 4.7 A"};

  std::istringstream input{inputString};

  std::string s1;
  std::string s2;
  int i;
  double d;
  char c;

  input >> s1 >> s2 >> i >> d >> c;
}
