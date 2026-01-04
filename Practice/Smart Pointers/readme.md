
# Smart Pointers in C++

There are three types of smart pointers in C++ that streamline the memory allocation process with more safety checks.

You do not have to use `new` or `delete` when using smart pointers.

Smart Pointers matter because they solve for:
- memory leaks
- double deletes
- dangling pointers
- exception-unsafe code
- manual `new`/`delete` mistakes

They also integrate with RAII (Resource Acquisition Is Initialization).

Most modern C++ codebases follow a rule of using `unique_ptr` unless you specifically need a shared ownership, in which case, depending on the circumstances employ `weak_ptr` to break cyclical issues.

---
Unique Pointer: Exclusive Ownership
--

Only one `unique_ptr` can own a given object at a time.

This will clarify ownership, perform automatic cleanup, and prevent copying.

Example:
```cpp
#include <memory>
#include <iostream>

int main() {

	std::unique_ptr<int> p = std::make_unique<int>(100);
	std::cout << *p << '\n';  // prints 100

	return 0;
} // p goes out of scope -> memory automatically freed.

```

Moving ownership is allowed:
```cpp
std::unique_ptr<int> a = std::make_unique<int>(100);
std::unique_ptr<int> b = std::move(a);  // a becomes null
```

This prevents double-free bugs.

---
Shared Pointer: Shared Ownership
--

Multiple smart pointers can own the same object, the object will be deleted when the last `shared_ptr` goes away.

Use this pointer when ownership is shared, multiple objects need access to the same resource, or when lifetime is not strictly hierarchical.

Example:
```cpp
#include <memory>
#include <iostream>

int main() {

	std::shared_ptr<int> p1 = std::make_unique<int>(100);
	std::shared_ptr<int> p2 = p1; // shared ownership
	
	std::cout << p1.use_count() << '\n'; // prints 2

	return 0;
}
```

You can use `use_count()` to keep track of reference counting; keeping a counter of how many owners exist with a shared pointer.

---
Weak Pointer: Shared Ownership
--

This is used with `shared_ptr` to break cycles - a `weak_ptr` does not contribute to the reference count.

This exists for the following reason:
```text
A owns B
B owns A
```

If both use `shared_ptr`, neither will ever reach zero - causing a memory leak.

`weak_ptr` solves for this problem.

Example:
```cpp
std::shared_ptr<int> p1 = std::make_shared<int>(5);
std::weak_ptr<int> wp = p1;

if (auto locked = wp.lock()) {
	std::cout << *locked << '\n';
}
```

`lock()` gives you a temporary `shared_ptr` if the object still exists

---


