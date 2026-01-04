
# Default Constructors

You do not need to write a default constructor if your class has no constructors at all, the compiler automatically generates one:
```cpp
class Foo {
	int x;
};
// Compiler generates Foo() automatically
```

This works fine unless you need explicit behavior:

You need a default constructor when:
* You declared another constructor
* You want it private (singleton)
* You want trivial/constexpr/noexcept behavior
* You deleted other constructors
* You want to express intent clearly

Otherwise, the compiler will generate it for you

---
When you MUST explicitly write a default constructor:
--

1. **When you declare any other constructor**

If you write any constructor (copy, move, or custom), the compiler stops generating the default one.

Example:
```cpp
class Foo {
public:
	Foo(int) {} // custom constructor
};
```

This will default:
```cpp
Foo f; // no default constructor exists
```

If you want a default construction, you must write:
```cpp
Foo() = default;
```

2. **When you want the constructor to be private**

This is the singleton casE:
```cpp
class Singleton {
private:
	Singleton() = default; // must explicitly declare it
};
```

If you do not declare it, the compiler generates a public constructor, which breaks the Singleton pattern.

3. When you want the constructor to be trivial / constexpr / noexcept

A defaulted constructor:
```cpp
Foo() = default;
```

Is:
* trivial if possible
* constexpr if possible
* noexcept if possible

But writing:
```cpp
Foo() {}
```

Is not trivial, not constexpr, and not noexcept unless you add those manually.

So `= default` gives the compiler maximum optimization freedom.

4. **When you deleted copy / move constructors**

If you do this:
```cpp
Foo(const Foo&) = delete;
Foo(Foo&&) = delete;
```

The compiler may also delete the default constructor unless you explicitly restore it:
```cpp
Foo() = default;
```

---
