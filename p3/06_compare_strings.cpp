
#include <format>
#include <iostream>

void displayResult(const std::string &s, int result) {
  if (result == 0) {
    std::cout << std::format("{} == 0\n", s);
  } else if (result < 0) {
    std::cout << std::format("{} < 0\n", s);
  } else {
    std::cout << std::format("{} > 0\n", s);
  }
}

int main() {
  const std::string s1{"Testing the comparison functions"};
  const std::string s2{"Hello"};
  const std::string s3{"stinger"};
  const std::string s4{s2};

  displayResult("s1.compare(s2)", s1.compare(s2));
}
