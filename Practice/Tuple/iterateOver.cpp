#include <iostream>
#include <tuple>

int main() {

  auto t = std::make_tuple(42, 3.14, "Hello");

  std::apply([](auto&&... elems) {
    ((std::cout << elems << " "), ...);
  }, t);
  
  return 0;
}
