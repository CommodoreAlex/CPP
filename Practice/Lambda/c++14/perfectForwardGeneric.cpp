#include <iostream>
#include <string>

void foo(const std::string& ) { std::cout << "foo(const string&)\n"; }
void foo(const std::string&& ) { std::cout << "foo(string&&)\n"; }

int main() {
  const auto callFoo = [](auto &&str) {
    std::cout << "Calling foo() on: " << str << '\n';
    foo(std::forward<decltype(str)>(str));
  };

  const std::string str = "Hello World";
  callFoo(str);
  callFoo("Hello World Ref Ref");
}
