#include <iostream>

int main() {
  constexpr int a{7};
  const int *aPtr{&a};

  std::cout << "The address of a is " << &a << "\n The value of a is " << a
            << "\nThe value of *aPtr is " << *aPtr;
}
