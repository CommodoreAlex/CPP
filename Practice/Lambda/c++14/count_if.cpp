#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  const std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  const auto count = std::count_if(v.begin(), v.end(), [](int x) { return x > 2 && x < 6; });

  const auto count2 = std::count_if(v.begin(), v.end(), [](int x) { return x > 5; });

  std::cout << "Count = " << count << '\n';
  std::cout << "Count = " << count2 << '\n';
}
