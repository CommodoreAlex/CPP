# Integer Literal Forms in C++

C++ allows you to form several bases and several suffixes.
--

Example of using a suffix:
```cpp
for (size_t i = {0uz}; i < n; ++i) {};
```

You can wrap any literal in braces like the above to create a `braced-init-list` containing a literal.

---

Unsigned suffixes:
```cpp
42u
42U
0u
```

Example:
```cpp
for (size_t i = {0uz}; i < n; ++i) {};
```

---

Long / long long suffixes:
```cpp
42l   // long
42L
42ll  // long long
42LL
```

Combinations of unsigned + long:
```cpp
42ul
42uL
42Ul
42lu
42LU
42llu
42LLu
42ull
42ULL
```

The size-type suffix:
```cpp
0z     // size_t literal
0uz    // unsigned + size_t
0Z
0uZ
```

The `'z'` in this case means make this literal the same type as `size_t`

You can insert `'` anywhere between digits:
```cpp
1'000'000
0b1010'1100
0xFF'EE'12
```

This does not change the value it just expands on readability.

---
