# Why Concepts Matter

Before C++20, templates were "anything goes", where if you pass an incorrect type you would
return with an error.

Concepts let you write templates with type-safety in mind.

**A template without concepts:**
```cpp
template <typename T>
T add(T a, T b) {
  return a + b; // hope T supports +
}
```

If someone wrote `add("hi", 3)` then the compiler throws an error.

**A template with concepts:**
```cpp
#include <concepts>

template <std::integral T>
T add(T a, T b) {
  return a + b;
}
```

Now the compiler must say that "T must satisfy `std::integral`" which is clear and safe.

---

### There are other built-in standard C++20 concepts

|Concept|Meaning|
|---|---|
|`std::integral`|Any integer type|
|`std::floating_point`|float, double, long double|
|`std::signed_integral`|signed ints|
|`std::unsigned_integral`|unsigned ints|
|`std::same_as`|exactly the same type|
|`std::convertible_to`|can be converted to T|
|`std::invocableF, Args...>`|callable with given args|
|`std::ranges::range`|works with range‑based algorithms|

---

### You're able to write your own concepts

This is possible using `requires`:
```cpp
template <typename T>
concept Addable = requires(T a, T b) {
  { a + b } -> std::convertible_to<T>;
};
```

T must support a + b and the result must be convertible to T, then using it:
```cpp
template <Addable T>
T add(T a, T b) {
  return a + b;
}
```

---

### Concepts in function overloading

Concepts make overloads clean and readable:
```cpp
void print(std::integral auto x) {
  std::cout << "int: " << x << "\n";
}

void print(std::floating_point auto x) {
  std::cout << "float: " << x << "\n";
}

// Calling
print(10);   // int overload
print(3.14); // float overload
```

---

### Concepts with AUTO

C++20 lets you constrain auto directly:
```cpp
std::integral auto x = 10;    // OK
std::integral auto y = 3.14;  // error
```

This forces the type to be int (in this case), so 3.14 fails.

---

