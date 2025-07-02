#include <array>
#include <format>
#include <iostream>

int main() {
  constexpr std::array responses{1, 2, 5, 4, 3, 5, 2, 1, 3, 1,
                                 4, 3, 3, 3, 2, 3, 3, 2, 2, 5};

  constexpr size_t freqSize{6};
  std::array<int, freqSize> freqs{};

  for (const int &resp : responses) {
    ++freqs.at(resp);
  }

  std::cout << std::format("{}{:>12}\n", "Rating", "Frequency");

  for (size_t rating{1}; rating < freqs.size(); rating++) {
    std::cout << std::format("{:>6}{:>12}\n", rating, freqs.at(rating));
  }
}
