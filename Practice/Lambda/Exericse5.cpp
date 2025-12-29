#include <type_traits>
#include <cassert>

  int divide(int a, int ) {
    assert(b != 0); // ensure no divison by zero
    return a / b;
  }

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

  // An assert, run-time failure
  divide(10, 2);
  divide(10, 0);  // Fail here
}
