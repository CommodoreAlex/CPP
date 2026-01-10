#include <iostream>

struct Baz { 
  auto foo() {
    // capture entire object by value
    return [*this] { std::cout << s << '\n'; };
  }
  // Every instance of baz has its own s
  std::string s;
};

int main() {

  const auto f1 = Baz{"xyz"}.foo();
  const auto f2 = Baz{"abc"}.foo();
  f1();
  f2();

}
