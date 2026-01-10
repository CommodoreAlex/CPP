# Immediately Invoked Functional Expression (IIFE)

`std::invoke()` is a good alternative to calling Lambda's at the end with `();` where it will immediately call the function.

Example:
```cpp
#include <iostream>
#include <functional>
#include <string>

int main() {
    const std::string in { "Hello World" };

    const std::string out = std::invoke([copy = in]() mutable {
        auto pos = copy.find("World");
        if (pos != std::string::npos) {
            copy.replace(pos, 5, "C++");
        }
        return copy;
    });

    std::cout << out;
}
```

Extracting Functions with IIFE:
```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  using Student = std::pair<std::vector<double>, std::string>;
  const std::vector<Student> db { { { 5.0, 5.0, 5.0, 4.0 }, "John"},
                                  { { 5.0, 5.0, 5.0, 4.0}, "Mark"},
                                  { { 5.0, 5.0, 5.0, 4.0 }, "Jame"} };

  auto ComputeAverages = [](const std::vector<Student>& db) {
  std::vector<std::pair<double, std::string>> out;
  for (auto& [marks, name] : db) {
    double avg = std::accumulate(marks.begin(), marks.end(), 0.0)/marks.size();
    out.push_back({avg, name});
  }
  return out;
  };

  auto averages = ComputeAverages(db);

  for ( const auto &[avg, name] : averages ) {
    std::cout << name << ": " << avg << '\n';
  }
  }
```
