#include <format>
#include <iostream>
#include <random>

int main() {
  unsigned int seed{0};

  std::cout << "Enter seed: ";
  std::cin >> seed;

  std::default_random_engine engine{seed};
  std::uniform_int_distribution randomDie{1, 6};

  int freq1{0};
  int freq2{0};
  int freq3{0};
  int freq4{0};
  int freq5{0};
  int freq6{0};

  for (int roll{1}; roll <= 60'000'000; roll++) {
    switch (const int face{randomDie(engine)}) {
    case 1:
      freq1++;
      break;
    case 2:
      freq2++;
      break;
    case 3:
      freq3++;
      break;
    case 4:
      freq4++;
      break;
    case 5:
      freq5++;
      break;
    case 6:
      freq6++;
      break;
    default:
      std::cout << "Not possible";
      break;
    }
  }

  std::cout << std::format("{:>4}{:>13}\n", "Face", "Frequency");
  std::cout << std::format("{:>4d}{:>13d}\n", 1, freq1)
            << std::format("{:>4d}{:>13d}\n", 2, freq2)
            << std::format("{:>4d}{:>13d}\n", 3, freq3)
            << std::format("{:>4d}{:>13d}\n", 4, freq4)
            << std::format("{:>4d}{:>13d}\n", 5, freq5)
            << std::format("{:>4d}{:>13d}\n", 6, freq6);
}
