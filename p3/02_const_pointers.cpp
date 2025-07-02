
int main() {
  int y{0};
  // pointer to a "const" value
  const int *yPtr{&y};
  // *yPtr = 100; // error

  int x;
  int *const ptr{&x}; // constant pointer to an integer that can be modified,
                      // but ptr must always point to the same memory location
  *ptr = 7;           // allowed, *ptr is not constant
  // ptr = &y; // error

  int z;
  const int *const zPtr{&z};
  *zPtr = 7; // error
  zPtr = &x; // error
}
