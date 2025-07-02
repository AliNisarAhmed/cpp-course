#include <array>
#include <format>
#include <iostream>

int main() {
  std::array<int, 10> values;

  for (std::size_t i{0}; i < values.size(); i++) {
    values[i] = 10;
  }

  std::cout << std::format("{:>7}{:>10}\n", "Element", "Value");

  for (std::size_t i{0}; i < values.size(); i++) {
    std::cout << std::format("{:>7}{:>10}\n", i, values[i]);
  }

  std::array doubles{1.1, 2.2, 3.3, 4.4, 5.5};

  std::cout << "doubles before modification:\n";

  for (const double &item : doubles) {
    std::cout << std::format("{}\n", item);
  }

  for (double &item : doubles) {
    item = item * 2;
  }

  std::cout << "doubles after modification:\n";
  for (const double &item : doubles) {
    std::cout << std::format("{}\n", item);
  }

  for (double runningTotal{0}; const double &item : doubles) {
    runningTotal += item;
    std::cout << std::format("item: {}; runningTotal: {}\n", item,
                             runningTotal);
  }

  // this is evaluated at compile time, thus eliminating runtime overhead of
  // evaluation.
  constexpr size_t arraySize{5};
  std::array<int, arraySize> arr{42, 52, 62, 73, 83};
}
