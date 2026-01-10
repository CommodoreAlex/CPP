# Fold Expressions

When the number of arguments is unknown or flexible, variadic templates make sense.
- They let you write functions that accept any number of any types without runtime overhead too.

Fold expressions are perfect when you want to combine all arguments in a pack, see example.

Example:
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

Use variadic templates and fold expressions when:
- You need flexibility in the number of arguments
- You want compile‑time type safety
- You want zero runtime overhead
- You want clean, elegant code that avoids repetition

Avoid them when:
- A normal loop or overload is clearer
- The number of arguments is fixed
- The abstraction becomes too clever for its own good

---
