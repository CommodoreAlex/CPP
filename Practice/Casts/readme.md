# The Four C++ Casts

C++ has four explicit cast operators:
1. `static_cast`: normal, safe conversions
2. `const_cast`: change constness
3. `dynamic_cast`: safe down casting with runtime checks
4. `reinterpret_cast`: raw bit reinterpretation (dangerous)

---
#### Static (Normal) Cast

This is useful for safe, compile-time conversions:
* Converting between numeric types
* Converting `void*` -> typed pointer
* Upcasting in inheritance (derived->base)
* Converting lambdas to function pointers (see lambda section of repo)

You are not allowed to remove `const` or do down casting without Run-Time Type Identification (RTTI) checks:
```cpp
double d = 3.14;
int x = static_cast<int>(d);    // OK
```

----
#### Const Cast: Add/Remove Const/Volatile

This is the only cast that can change constness

This is good for:
* Interfacing with old C APIs that require non-const pointers
* Removing `const` when you know the underlying object is not const

This is dangerous if:
* You remove const and then modify an object that was originally declared const -> leading to undefined behavior.

An example of allowed use:
```cpp
const int x = 10;
int* p = const_cast<int*>(&x);  // allowed
```




---
#### Dynamic Cast: Safe Downcasting

This is used only with polymorphic classes (i.e. classes with virtual functions)

This is good for:
* Downcasting base -> derived safely.
* Checking object type at runtime.
* Returning `nullptr` if the cast is invalid.

An example:
```cpp
Base* b = new DeriveD();
Derived* d = dynamic_cast<Derived*>(b);  // OK
```

This is not for non-polymorphic types, primitive types, removing const, or casting unrelated types.

---
#### Reinterpret Cast: The "Dangerous" Cast

This is the low-level, "treat these bits as something else" cast.

This is good for:
* Casting between unrelated pointer types
* Casting integers <-> pointers
* Bit reinterpretation in low-level systems code

This is dangerous:
* There are no safety checks
* Can easily cause undefined behavior
* Should be avoided unless you really know what you're doing

Example:
```cpp
int x = 0x12345678;
char* p = reinterpret_cast<char*>(&x);  // treat int as bytes
```

