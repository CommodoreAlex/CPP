# Lambda Function Pointer


If you apply a unary operator `+` to a lambda it converts it to a function pointer, if the lambda has no captures:
```cpp
#include <type_traits>

int main() {
	auto funcPtr = +[]{};
	
	static_assert(std::is_same<decltype(funcPtr), void (*)()>::value);
	
	return 0;
}
```

A lambda without captures is convertible to a function pointer:
```cpp
void (*fp)() = []{};  // OK
```

Normally you would write:
```cpp
auto x = []{};
```

You can check if the Lambda has the type:
```cpp
void (*)()
```

You can do a static assert on this for type verification:
```cpp
static_assert(std::is_same<decltype(funcPtr), void (*)()>::value);
```
