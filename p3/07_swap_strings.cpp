
#include <iostream>
#include <string>

int main() {
  std::string s1{"one"};
  std::string s2{"two"};

  s1.swap(s2);

  std::cout << s1.capacity() << " " << s1.max_size() << " " << s1.size() << " "
            << s1.empty();
}
