#include <iostream>

int main() {
  int* a = new int(10);
  int*& b = a;
  std::cout << b << " " << a;
  return 0;
}