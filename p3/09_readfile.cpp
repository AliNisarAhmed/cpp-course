#include <cstdlib>
#include <format>
#include <fstream>
#include <iostream>
int main() {
  if (std::ifstream input{"clients.txt", std::ios::in}) {
    std::cout << std::format("{:<10}{:<13}{:>7}\n", "Account", "Name",
                             "Balance");

    int account;
    std::string name;
    double balance;

    while (input >> account >> name >> balance) {
      std::cout << std::format("{:<10}{:<13}{:>7.2f}\n", account, name,
                               balance);
    }
  } else {
    std::cerr << "File could not be opened\n";
    exit(EXIT_FAILURE);
  }
}
