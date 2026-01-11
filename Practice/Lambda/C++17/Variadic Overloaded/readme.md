# Variadic Overloaded Pattern

Example:
```cpp
#include <iostream>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main() {
  const auto test = overloaded {
    [](const int& i) { std::cout << "int: " << i << '\n'; },
    [](const float& f) { std::cout << "float: " << f << '\n'; },
    [](const std::string& s) { std::cout << "string: " << s << '\n'; }
  };

  test("10.0f");
}
```

# Using Variant, Visit, Inheritence, Overloaded Lambdas

Example:
```cpp
#include <iostream>
#include <variant>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main() {
  const auto PrintVisitor = [](const auto& t) { std::cout << t << "\n"; };

  std::variant<int, float, std::string> intFloatString { "Hello" };

  std::visit(PrintVisitor, intFloatString);

  std::visit(overloaded{
    [](int& i) { i *= 2; },
    [](float& f) { f *= 2.0f; },
    [](std::string& s) { s = s + s; }
  }, intFloatString);

  std::visit(PrintVisitor, intFloatString);
}
```

#### Explanation

Using `std::variant` and `std::visit` from `#include <variant>`
- `std::variant` is a type-safe union; holding exactly one of several possible types at a time
- `std::variant` is how you extract or operate on the value inside a variant

C++ does not let you overload lambdas directly, but you are able to combine them.

`std::visit` needs one callable object whose `operator()` is overloaded for each type in `std::variant` - but lambdas can not be overloaded; so they must be combined into a single object that has multiple `operator()` overloads.

Meaning Ts is a pack of types, containing many types, where each type in `Ts` will be one of the lambdas you pass in:
```cpp
Overloaded{
  [](int){},
  [](double){},
  [](std::string){}
};
```

Here `Ts...` becomes:
```cpp
Ts = { lambda<int>, lambda<double>, lambda<string> }
```

So the struct becomes:
```cpp
struct Overloaded : lambda<int>, lambda<double>, lambda<string> { ... };
```

If you inherit from multiple classes, and each class has an `operator()`, then the derived class has all of them:
```cpp
struct A { void operator()(int){} };
struct B { void operator()(double){} };
struct C : A, B {};
// Now C has C::operator()(int) and C::operator()(double)
```

Those operators become visible;
```cpp
using Ts::operator()...;
```

Which becomes:
```cpp
using lambda<int>::operator();
using lambda<double>::operator();
using lambda<string>::operator();
```

The deduction guide:
```cpp
template<class... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;
```

This lets you write:
```cpp
Overloaded{
    [](int){},
    [](double){}
};
```

Instead of:
```cpp
Overloaded<decltype(lambda1), decltype(lambda2)>{ lambda1, lambda2 };
```

The pattern in action:
```cpp
std::variant<int, std::string> v = 42;

std::visit(Overloaded{
    [](int i) { std::cout << "int: " << i; },
    [](const std::string& s) { std::cout << "string: " << s; }
}, v);
```
