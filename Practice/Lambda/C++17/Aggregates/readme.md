# Aggregates

Example
```cpp
#include <iostream>

struct Base {
  int x;
  double y;
};

struct Derived : Base {
  int z;
};

int main() {
  // Aggregate Initialized of Derived
  Derived d{ 10, 3.14, 42};
  std::cout << d.x << ", " << d.y << ", " << d.z << '\n';
}
```
