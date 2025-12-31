
### Type Alias's in C++

The old way in C/C++ of creating a type alias; new name for an existing type:
```c
typedef int my_int
```

The modern way of doing this in C++ with better interpretation:
```cpp
using my_int = int;
```

Both of the create a type alias but `using` is the modern, cleaner version.

The reason why people prefer using is because it is easier to read compared to `typedef`:
```cpp
// Reads right-to-left
typedef void (*f_ptr)(int)
```

You have to read this inside-put:
- `f_ptr` is a pointer to a function, taking an `int` and returning `void`.

So using the modern version allows you to read it this way (reads left-to-right):
```cpp
using f_ptr = void(*)(int)
```

---

`typedef` cannot create template aliases but `using` can:
```cpp
template<typename T>
using Vec = std::vector<T>;
```

