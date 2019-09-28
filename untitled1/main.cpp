#include <iostream>
#include <random>
int main() {
  int a = 4;
  decltype(a) b = a;
  decltype(auto) c = a;
  decltype(auto) d = (a);

  std::default_random_engine d;
  std::random_device;


  int a1[] = { 2, 3, 5, 7 };

  return 0;
}