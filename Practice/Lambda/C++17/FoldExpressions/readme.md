# Fold Expressions

```cpp
#include <iostream>

int main() {
  // parameter pack variadic generic lambda
  const auto sumLambda = [] (auto... args) {
    std::cout << "sum of: " << sizeof...(args) << " numbers\n";
    // fold expression
    return (args + ... + 0);
  };

  std::cout << sumLambda(1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
}
```
