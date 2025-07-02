#include <array>
#include <format>
#include <iostream>
#include <numeric>

int multiply(int x, int y) { return x * y; }

int main() {
  constexpr std::array ints{10, 20, 30, 40};
  auto total = std::accumulate(std::begin(ints), std::end(ints), 0);
  std::cout << std::format("Total: {}\n", total);
  // auto product = std::accumulate(std::begin(ints), std::end(ints), 1,
  // multiply);
  auto product =
      std::accumulate(std::begin(ints), std::end(ints), 1,
                      [](const auto &x, const auto &y) { return x * y; });
  std::cout << std::format("Product: {}\n", product);
}
