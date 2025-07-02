
#include <iostream>
#include <stdexcept>
#include <vector>

void outputVector(const std::vector<int> &items);
void inputVector(std::vector<int> &items);

int main() {
  std::vector<int> ints1(7);
  std::vector<int> ints2(10);

  std::cout << "Size of vector ints1 is " << ints1.size()
            << "\nvector after initialization:";
  outputVector(ints1);

  std::cout << "Size of vector ints2 is " << ints2.size()
            << "\nvector after initialization:";
  outputVector(ints2);

  std::cout << "\nEnter 17 integers:\n";
  inputVector(ints1);
  inputVector(ints2);

  std::cout << "After input:\n";
  outputVector(ints1);
  std::cout << "ints2\n";
  outputVector(ints2);

  if (ints1 != ints2) {
    std::cout << "ints1 and ints2 are not equal\n";
  }

  std::vector ints3{ints1}; // copy constructor
                            //
  std::cout << "assigning ints2 to ints1\n";
  ints1 = ints2;

  if (ints1 == ints2) {
    std::cout << "ints1 and ints2 are now equal\n";
  }

  try {
    std::cout << "Attempting to display ints1.at(15), should throw\n";
    std::cout << ints1.at(15);
  } catch (const std::out_of_range &ex) {
    std::cerr << "An exception occured: " << ex.what() << '\n';
  }

  std::cout << "current ints3 size: " << ints3.size() << '\n';
  ints3.push_back(1000);
  std::cout << "New ints3 size: " << ints3.size() << '\n';
  outputVector(ints3);
}

void outputVector(const std::vector<int> &items) {
  for (const int &item : items) {
    std::cout << item << ' ';
  }

  std::cout << '\n';
}

void inputVector(std::vector<int> &items) {
  for (int &item : items) {
    std::cin >> item;
  }
}
