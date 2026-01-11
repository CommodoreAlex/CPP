# Parallel Execution On STL

You can parallelize most of the algorithms from the Standard Library, all you have to do is
specify the first argument into the algorithm.

This is only a preference where parallel custom behavior is not required - do not use execution policies unless you're okay with the decisions being made for you with no governance on how threading occurs.

See example:
```cpp
auto myVec = GenerateVector();
std::sort(std::execution::par, myVec.begin(), myVec.end());
```

The argument `std::execution::par` is used to enable parallel execution of the algorithm.

There are other options too.

---

`sequenced_policy` - An execution policy type used as a unique type to disambiguate parallel
algorithm overloading and require that a parallel algorithm's execution not be parallelised.

`parallel_policy` - An execution policy type used as a unique type to disambiguate parallel algorithm overloading and indicate that a parallel algorithm's execution may be parallelized.

`Parallel_unsequenced_policy` - An execution policy type used as a unique type to disambiguate parallel algorithm overloading and indicate that a parallel algorithm's execution may be parallelised and vectorised.

You can pass these global instances from the `<execution>` header to algorithms:
- `std::execution::par`
- `std::execution::seq`
- `std::execution::par_unseq`
- `std::execution::unseq` (C++20)

Example:
```cpp
#include <execution>
#include <vector>
#include <iostream>
#include <numeric>

int main() {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(), 0);
  std::vector<int> output;
  std::for_each(std::execution::par, vec.begin(), vec.end(),
  [&output](int& elem) { if ( elem % 2 == 0) { output.push_back(elem);}});

  for ( const auto& elem : output) {
    std::cout << elem << ", ";
  }
}
```













