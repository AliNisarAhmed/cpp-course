#include "rapidcsv.h"
#include <format>
#include <iostream>
#include <string>
#include <vector>

int main() {
  rapidcsv::Document document{"accounts.csv"};
  std::vector<int> accounts{document.GetColumn<int>("account")};
  std::vector<std::string> names{document.GetColumn<std::string>("name")};
  auto balances{document.GetColumn<double>("balance")};

  std::cout << std::format("{:<10}{:<13}{:>7}\n", "Account", "Name", "Balance");

  for (size_t i{0}; i < accounts.size(); ++i) {
    std::cout << std::format("{:<10}{:<13}{:>7.2f}\n", accounts.at(i),
                             names.at(i), balances.at(i));
  }
}
