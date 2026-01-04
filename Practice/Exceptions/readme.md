Exceptions
--

C++ exceptions are divided into two major families:
1. Logic errors: Bugs in your code
2. Runtime errors: Problems caused by the environment or input

---
Logic Error
--

`std::logic_error` means "The program is wrong. This should never happen if the code is correct."

These errors indicate programmer mistakes, not bad input or external failures.

Examples:
- Calling a function with invalid arguments
- Violating a precondition
- Accessing out-of-range indices
- Using an object in an invalid state

Derived exceptions:
1. `std::invalid_argument`
2. `std::domain_error`
3. `std::length_error`
4. `std::out_of_range`

When to throw it:
- When the caller misuses your API or violates assumptions

Example:
```cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
	if (b == 0) {
		throw std::logic_error("divide(): denominator cannot be zero");
	}
	return a / b;
}

int main() {
	try {
		std::cout << divide(10, 0) << '\n';
	} catch (const std::logic_error& e) {
		std::cerr << "Logic error: " << e.what() << '\n';
	}
}
```

---
Runtime Error
--

A runtime error means "The program is correct, but something went wrong at runtime.", these errors come from external conditions or unpredictable situations.

Examples:
* File not found
* Network failure
* Memory exhaustion
* Hardware issues
* Unexpected inputs from the user

Derived Exceptions:
1. `std::range_error`
2. `std::overflow_error`
3. `std::underflow_error`

When to throw it:
* When the program encounters a problem it could not prevent through logic alone.

Example:
```cpp
#include <iostream>
#include <stdexcept>
#include <fstream>


void loadFile(const std::string& path) {
	std::ifstream file(path);
	if(!file) {
		throw std::runtime_error("Failed to open file: " + path);
	}
	// read file...
}

int main() {
	try {
		loadFile("missing.txt");
	} catch (const std::runtime_error& e) {
		std::cerr << "Runtime error: " << e.what() << '\n';
	}
}
```
