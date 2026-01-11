#include <iostream>
// Using consteval for immediate compile-time lambda
int main() {
  const int x = 10;
  auto lam = [](int x) consteval { return x + x; };
  return lam(x);
}
