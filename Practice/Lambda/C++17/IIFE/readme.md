# Immediately Invoked Functional Expression (IIFE)

`std::invoke()` is a good alternative to calling Lambda's at the end with `();`

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
