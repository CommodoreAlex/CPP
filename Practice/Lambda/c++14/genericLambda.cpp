#include <iostream>

int main() {

  // See 'auto x' in paramters
  const auto foo = [](auto x, int y) { std::cout << x << ", " << y << '\n'; };

  foo(10, 1);
  foo(10.1234, 2);
  foo("Hello World", 1);
}
