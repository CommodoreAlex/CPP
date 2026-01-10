# Macros

These are text substitution rules handled by the C++ preprocessor.

Before code is compiled, the preprocessor rewrites part of your source file according to the macros defined
introduced with `#define`.

A macro is not a C++ feature, it is a text-rewriting tool that runs before C++ begins.

Most things macros used to do can now be done better with:

|Old macro use|Modern alternative|
|---|---|
|Constants|`constexpr` variables|
|Inline functions|`inline` or lambdas|
|Type-safe functions|Templates|
|Include guards|`#pragma once`|
|Debug logging|`constexpr if`, logging libraries|


---

#### There are object-like macros

Example:
```cpp
#define PI 3.14159
```

Anywhere the compiler sees PI, it replaces it with `3.14159`.

#### Function-like macros

They look like functions but are just text substitution.

Example:
```cpp
#define SQUARE(x) ((x) * (x))
int y = SQUARE(5);  // becomes ((5) * (5))
```

This can be dangerous where they do not respest types or evaluation rules.

#### Conditional Compilation Macros

Used to include or exclude code.

Example:
```cpp
#ifdef DEBUG
  std::cout << "Debug mode\n";
#endif
```
OR
```cpp
#if defined(WINDOWS)
  // Windows-specific code
#endif
```

#### Include Guards

The most common use:
```cpp
#ifndef MY_HEADER_H
#define MY_HEADER_H

// header contents
#endif
```
---







