## IIFE - Immediately Invoked Function Expression

You can call a lambda right at instantiation with `();` following construction:
```cpp
#include <iostream>

int main() {
	int x = 1, y = 1;
	[&]() noexcept { ++x; ++y; }(); // <-- call()
	
	std::cout << x << "," << y;
	return 0;
}
```
