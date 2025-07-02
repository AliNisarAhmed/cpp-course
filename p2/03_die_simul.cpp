
#include <format>
#include <iostream>
#include <random>

int main() {
  std::random_device rd;
  std::default_random_engine engine{rd()}; // rd() produces a seed
  std::uniform_int_distribution<> randomDie{1, 6};
  // 1 more than 6 sided die, ignore index 0 to align with die values
  constexpr size_t arraySize{7};
  std::array<int, arraySize> freqs{};

  for (int roll{1}; roll <= 60'000'000; roll++) {
    ++freqs.at(randomDie(engine));
  }

  std::cout << std::format("{}:{:>13}\n", "Face", "Frequency");

  for (size_t face{1}; face < freqs.size(); ++face) {
    std::cout << std::format("{:>4}{:>13}\n", face, freqs.at(face));
  }
}
