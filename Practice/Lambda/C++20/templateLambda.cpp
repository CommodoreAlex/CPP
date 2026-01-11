#include <iostream>

// In C++20 you can now let lambdas resolve to a templated call operator
auto foo = []<typename T>(std::vector<T> const& vec) {
  std::cout << std::size(vec) << '\n';
  std::cout << vec.capacity() << '\n';
};
