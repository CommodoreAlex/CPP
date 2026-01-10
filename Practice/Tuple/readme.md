# Tuples in C++

A tuple is a compile-time fixed structure, not a container, where each element can have different types (like a tiny, anonymous struct whose fields don't have names - only positions).

This derives from the `<tuple>` header and is valuable when you want to group several values together without defining a custom struct.

Example:
```cpp
auto t = std::make_tuple(42, 3.14, "hello");
```

A tuple has:
- No `begin()`
- No `end()`
- No iterators
- No runtime size

To access elements in a tuple:
```cpp
// The index must be known at compile time
int a = std::get<0>(t);
double b = std::get<1>(t);
const char* c = std::get<2>(t);
```

#### Can you use for loops againast a tuple in C++ (Parameter Packs (C++11+))

An `std::tuple` is not a range, so a normal for loop (or range-for) does not apply, but you are able to iterate over a tuple by expanding it into a parameter pack with `std::apply`.

A parameter pack is a way for templates to accept zero or more paramteres, foundational to variadic templates 

A function that takes any number of arguments:
```cpp
template<typename... Args>
void foo(Args... args) {}
```

Where `Args...` is a type paramter pack and `args...` is a function parameter pack.

Now you can pass in anything:
```cpp
foo(1);
foo(1, 2.5, "hello");
foo(); // even zero arguments
```

You can use `...` to "expand" the pack with fold expressions (C++17), applying `<<` to each arguments:
```cpp
template<typename... Args>
void print_all(Args... args) {
  (std::cout << ... << args);
}
```

Iterating over a tuple with paramter packs and `std::apply`:
```cpp
auto t = std::make_tuple(1, 4.5, "all");
std::apply([](auto... xs) {
  ((std::cout << xs << " "), ...);
}, t);
```

#### Structured Bindings (C++17)

Structured bindings let you unpack a compound object (tuple, array, pair, struct) into individual named variables in a single, clean statement (similar to destructuring in Python/JavaScript).

Example:
```cpp
auto t = std::make_tuple(1, 2.5, "hi");
auto [a, b, c] = t;
```

This gets rid of repetitive `std::get<N>` calls.
