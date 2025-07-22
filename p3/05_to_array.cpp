
#include <format>
#include <iostream>

int main() {
  const auto display{[](const auto &items) {
    for (const auto &item : items) {
      std::cout << std::format("{} ", item);
    }
  }};

  const auto array1{std::array{"abc"}};
  display(array1); // size 1, prints "abc"

  const auto array2{std::to_array("C++20")};
  display(array2); // size 6 (5 chars + 1 null char), displays C + + 2 0
}
