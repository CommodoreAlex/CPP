# Switch Case Statements and Replacements






Array-based switch-replacement with function pointers:
```cpp
#include <iostream>

void foo() { std::cout << "foo\n"; }
void bar() { std::cout << "bar\n"; }
void baz() { std::cout << "baz\n"; }

int main() {
    // Array of function pointers
    void (*actions[])() = { foo, bar, baz };

    int op = 1; // Example input

    if (op >= 0 && op < 3) {
        actions[op]();   // Calls bar()
    } else {
        std::cout << "Invalid option\n";
    }
}
```
