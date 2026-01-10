#include <iostream>

int main() {

  const auto factorial = [](int n) noexcept {
    const auto f_impl = [](int n, const auto& impl) noexcept -> int  {
      return n > 1 ? n * impl(n - 1, impl) : 1;
    };
    return f_impl(n, f_impl);
  };
  return factorial(5);
}
