#include <iostream>

struct Baz { 
  std::string foo() {
    const auto lam = [this]() { return s; };
    return lam();
  }

  std::string s = "Hello from Baz!";

};

int main() {

  Baz b;
  std::cout << b.foo();
}
