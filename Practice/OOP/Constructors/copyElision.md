# Copy Elision

Copy Elision is a rule in C++ that allows the compiler to skip creating temporary objects and skip calling / move constructors, even if those constructors have side effects.

C++ is allowed (and sometimes required) to construct an object directly in its final location instead of creating intermediate copies.

So instead of:
1. Make a temporary
2. Copy it
3. Destroy the temporary
C++ can do:
- Construct the final object directly.

No temporary. No Copy. No Move.

Without Copy Elision code like this would create unnecessary temporary objects:
```cpp
return G();
```

##### Optional Copy Elision (Pre-C++17 Behavior)

Before C++17 copy elision is optional, where using patterns like Named Return Value Optimization (NVRO) may eliminate copies:
```cpp
G make() {
	G x;
	return x;  // NVRO
}
```

The compiler is allowed to skip the copy, but not required.
##### Guaranteed Copy Elision (C++17 Behavior and later)

In certain cases, the compiler must eliminate a copy.

The most important case:
```cpp
G make() {
	return G();  // prvlaue return
}
```

The object is constructed directly into the caller's variable - so the program only prints `ctor`, and never `copy` in the example below.



----

Because of guaranteed copy elision in C++17 the compiler is required to treat `return G()` as "Construct the return object directly using `G()`" and since the return object is the same object as `g` in `main()`, only one construction happens.

Example:
```cpp
struct G {
	// Default Constructor
    G() { std::cout << "ctor\n"; }
    // Copy Constructor
    G(const G&) { std::cout << "copy\n"; }
};

// Create a function make() that returns G
G make() {
	// Construct a temporary G using the default constructor
    return G();
}

// Copy elision occurs here
int main() {
	// Temporary is never created; constructed directlty using G() inside make()
    G g = make();
}
```
