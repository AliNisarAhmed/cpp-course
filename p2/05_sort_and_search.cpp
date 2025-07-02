#include <algorithm>
#include <array>
#include <format>
#include <iostream>
#include <string>

using namespace std::string_literals; // enables string object literals

int main() {
  std::array colors{"red"s, "orange"s, "yellow"s, "green"s, "blue"s, "indigo"s};

  std::cout << "Unsorted color array:\n";

  for (const std::string &color : colors) {
    std::cout << std::format("{}\n", color);
  }

  std::sort(std::begin(colors), std::end(colors));

  std::cout << "Sorted color array:\n";

  for (const std::string &color : colors) {
    std::cout << std::format("{}\n", color);
  }

  // search for color
  bool found{
      std::binary_search(std::begin(colors), std::end(colors), "indigo")};

  std::cout << std::format("\n\nindigo {} found in colors array\n",
                           found ? "was" : "was not");
}
