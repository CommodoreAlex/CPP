# Perfect Forwarding

Perfect Forwarding is a technique that allows a function template to pass its arguments to another function exactly as it received them:
* If the caller passed an lvalue -> forward an lvalue.
* If the caller passed an rvalue -> forward an rvlaue.
* If the caller passed a const object -> forward const.
* If the caller passed a temporary -> forward a temporary.

It preserves the "value category" of the argument.

---

Perfect Forwarding is needed because templates often want to wrap or decorate a function call without changing how arguments behave.

Example problem:
```cpp
template<typename T>
void wrapper(T arg) {
	func(arg);  // always passes an lvalue
}
```

Even if the caller does:
```cpp
wrapper(std::string("hello"));  //rvalue
```

Inside `wrapper`, `arg` is an lvalue (because it has a name); so the rvalue-ness is lost - breaking move semantics.

---

#### Perfect Forwarding Solves for This

The correct pattern is:
```cpp
template<typename T>
void wrapper(T&& arg) {
	func(std::forward<T>(arg));
}
```

`T&&` in a template is a forwarding reference.

This is a special rule:
* If the caller passes an lvalue -> T becomes T&, and T&& collapses to T&
* If the caller passes an rvalue -> T stays T, and T&& stays T&&

This is called reference collapsing, and it's the magic behind perfect forwarding.

---

An example of the wrapper preserving the caller's intent perfectly:
```cpp
#include <iostream>

void process(const std::string& s) {
	std::cout << "lvaue\n"
};

void process(std::string&& s) {
	std::cout << "rvalue\n";
}

template<typename T>
void wrapper(T&& arg) {
	process(std::forward<T>(arg));
}

int main() {

	std::string name = "Emily";
	wrapper(name);               // prints "lvalue"
	wrapper(std::string("Hi"));  // prints "rvalue"

	return 0;
}
```
