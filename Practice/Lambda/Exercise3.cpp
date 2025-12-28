#include <iostream>
// Capturing two variables by copy and mutable


int main() {

  const auto print = [](const char* str, int x, int y) {
    std::cout << str << ": " << x << " " << y << '\n';
  };

  int x = 1, y = 1;

  print("in main()", x, y);

  auto foo = [x, y, &print]() mutable {
    ++x;
    ++y;
    print("in foo()", x, y);
  };

  foo();

  print("in main()", x, y);


  return 0;
}
