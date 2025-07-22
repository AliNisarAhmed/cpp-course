#include <format>
#include <iostream>
#include <span>
#include <vector>

void displayArray(const int items[], size_t size) {
  for (size_t i{0}; i < size; i++) {
    std::cout << std::format("{} ", items[i]);
  }
}

void displaySpan(std::span<const int> items) {
  for (const auto &item : items) {
    std::cout << std::format("{} ", item);
  }
}

void times2(std::span<int> items) {
  for (int &item : items) {
    item *= 2;
  }
}

int main() {
  int values1[]{1, 2, 3, 4, 5};
  std::array values2{6, 7, 8, 9, 10};
  std::vector values3{11, 12, 13, 14, 15};

  displayArray(values1, 5);
  displaySpan(values1);
  displaySpan(values2);
  displaySpan(values3);

  std::span mySpan{values1};
  auto front = mySpan.front();
  auto back = mySpan.back();
}
