### Why Printf is usually faster than `std::cout`

There is a performance benefit to using `printf()` from the C standard library header:
```c
#include <cstdio>

// Doing this with std::cout requires multiple manipulators
printf("%08d %.3f\n", 42, 33.14159);
```

`printf` is faster because:
1. It doesn't use locales
2. it doesn't use virtual functions
3. It doesn't do type dispatching
4. It doesn't manage formatting state
5. It doesn't synchronize with C++ streams unless you force it

It will just parse a format string and write bytes, giving you exact control over formatting:
* width, precision, padding, alignment, hex, octal, scientific notation, zero-padding, and fixed-width integers.

This is useful for working with C APIs when you're working with the POSIX, embedded firmware, C libraries, and system calls.
###### Why is it faster than IOSTREAM

`std::cout` would involve `operator<<` overloads, formatting flags, locale checks, streambuf virtual dispatch, and potential flushing - you're using less overhead with `printf` compared to iostreams in lieu of type-safety also.

Whenever you write to `std::cout` or `printf`, your output does not go directly to the screen - instead it goes into a buffer (a temporary chunk of memory).

"Force the buffer to be written out right now". If you do not flush, the buffer may sit there until it fills up or until the program ends.

The buffering makes I/O faster - writing to the terminal is slow while writing to memory is fast. So the system stores output in a buffer and writes it all at once later to reduce system calls and speed up your program.

Interestingly, flushing happens automatically when you print newlines with `std::endl`:
```cpp
std::cout << "Hello" << std::endl; // flushes (newline + flush)
```

As another aside, flushing does not happen when you do this:
```cpp
std::cout << "Hello\n";    // does NOT flush
std::cout << "Loading..."; // may not appear yet until something forces a flush
```

Because flushing is expensive due to forcing a system call with `std::endl;` that is why if you don't need to flush you'd prefer:
```cpp
std::cout << '\n';
```

---
### Disabling Synchronization between CIN and COUT

By default, C++ iostreams are synchronized with C stdio (`scanf, printf`) which means when you write to `cout` it flushes to keep `printf` output in order and when you read from `cin` it flushes `cout` first. 

Everything stays consistent but slower - every time you read from `cin`, `cout` flushes first (tied to each other (e.g. the synchronization)).

```cpp
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
```

This breaks the connection between C I/O and C++ I/O where `cout` no longer flushes automatically to stay in sync with `printf`; `cin` no longer forces `cout` to flush. This provides a 2-5x faster performance boost.

The `cin.tie(nullptr)` removes the rule "reading from `cin` flushes `cout` first"; preventing unnecessary flushes and making input faster.

###### Consequences

You must not mix `printf` / `scanf` with `cout`/`cin` anymore; output order may become unpredictable. If you rely on `cout` flushing automatically, it will not happen - this is safe provided you stick ONLY to iostreams.
###### Manual Flushing in lieu of disabling sync

This is the explicit and idiomatic C++ way to flush manually:
```cpp
std::cout << "Hello" << std::flush;
// Flushing without printing anything
std::cout.flush(); // Same effect, different syntax
```

If you're mixing C and C++ I/O (not recommended after disabling sync):
```cpp
fflush(stdout);
```

This becomes risky where once C and C++ buffers are no longer coordinated, mixing them could cause undefined behavior. 

---
### Extensibility with IOSTREAMS

`printf` can not do this because it uses variadic functions (`...`); having no type information at runtime and it cannot call user-defined formatting functions.

Variadic meaning 'accepting a variable number of arguments'; c-style example being:
```cpp
int sum(int count, ...);

// Called as
sum(3, 10, 20, 30);
```

The compiler has no idea what types you passed meaning you must manually extract them using `va_list` which is error-prone, so doing this is unsafe.

Now onto the modern applications of extensibility.
##### Extending `std::cout` (output)

Suppose you have a custom type:
```cpp
struct Vec2 {
	float x, y;
};
```

You can interpret the following as such:
```cpp
std::ostream& operator<<(std::ostream& os, const YourType& obj);
```

You can make it printable:
```cpp
std::ostream& operator<<(std::ostream& os, const Vec2& v) {
	return os << "(" << v.x << ", " << v.y << ")";
}
```

Now you can do:
```cpp
Vec2 v{3.0f, 4.0f};
std::cout << v << "\n";
```

This works with any stream (`std::cout`, file streams, string streams)
##### Extending `std::cin` (input)

You can interpret the following as such:
```cpp
std::istream& operator>>(std::istream& is, YourType& obj);
```

You can teach C++ how to read your type:
```cpp
std::istream& operator>>(std::istream& is, Vec2& v) {
	return is >> v.x >> v.y;
}
```

Now:
```cpp
Vec2 v;
std::cin >> v;
```

If the user types:
```text
3.5 7.2
```

Then `v.x == 3.5` and `v.y == 7,2`

---
### Why `fmt::print` is preferred as of C++ 20

It is the case that using the following could be preferred as of C++20:
```
#include <format>
fmt::print("Hello {}, the answer is {}\n", name. value);
```

This includes type-safety, custom types, it is fast like printf(), Pythonic, and has compile-time format checking with `fmt::compile`.

Extensibility is possible with this as well:
```cpp
struct Vec2 { float x, y; };

template<>
struct fmt::formatter<Vec2> {
  constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

  template <typename FormatContext>
  auto format(const Vec2& v, FormatContext& ctx) {
    return fmt::format_to(ctx.out(), "({}, {})", v.x, v.y);
  }
};

// Now you can do
fmt::print("v = {}\n", Vec2{3, 4});
```

---
