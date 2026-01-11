#include <array>
#include <algorithm>

constexpr auto CountValues(auto container, auto cmp) {
  return std::count_if(begin(container), end(container), cmp);
  }

int main() {
  constexpr auto minVal = CountValues(std::array{-10, 6, 8, 4, -5, 2, 4, 6},
    [](auto a) { return a >= 0; }
  );
  return minVal;
}
