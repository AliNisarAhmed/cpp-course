
#include <format>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>

int main() {
  auto showValues{[](auto &values, const std::string &message) {
    std::cout << std::format("{}: ", message);
    for (const auto &value : values) {
      std::cout << std::format("{} ", value);
    }
    std::cout << '\n';
  }};

  auto values1{std::views::iota(1, 11)};
  showValues(values1, "Integers 1-10");

  auto values2{values1 |
               std::views::filter([](const auto &x) { return x % 2 == 0; })};
  showValues(values2, "Filtering evens");

  auto values3{values2 |
               std::views::transform([](const auto &x) { return x * x; })};
  showValues(values3, "squaring evens");

  auto values4{values1 |
               std::views::filter([](const auto &x) { return x % 2 == 0; }) |
               std::views::transform([](const auto &x) { return x * x; })};
}
