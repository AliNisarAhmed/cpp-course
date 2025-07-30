#include <cstdlib>
#include <format>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  if (std::ofstream output{"clients.txt", std::ios::out}) {
    std::cout << "Enter the account, name and balance.\n"
              << "Enter end-of-file to end input.\n";
    int account;
    std::string name;
    double balance;

    while (std::cin >> account >> name >> balance) {
      output << std::format("{} {} {}\n", account, name, balance);
      std::cout << "? ";
    }
  } else {
    std::cerr << "File could not be opened\n";
    std::exit(EXIT_FAILURE);
  }
}
