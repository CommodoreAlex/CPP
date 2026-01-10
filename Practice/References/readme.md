# References in C++

More to be added later- for now, see universal/forwarding reference:
```cpp
#include <iostream>
#include <type_traits>

// fn is a universal/forwarding reference

template<typename Callable>
void CallWith10(Callable&& fn) {}
```

Where `T&&` would be an RVALUE reference - it becomes a "universal/forwarding" reference under
the context of a template (e.g. Callable&&)
