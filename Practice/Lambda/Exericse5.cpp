#include <type_traits>

int main() {

  // Two return statements only if they deduce to the same type with lambdas
  const auto baz = [](int x) noexcept {
    if (x > 20)
      return x * 1.1;
    else
      return x * 2.1;
  };

  // Like an assert, but checks things at compile-time instead of run-time
  static_assert(std::is_same<double, decltype(baz(10))>::value, "has to be the same!");
}
