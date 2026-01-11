# Parallel Execution On STL

You can parallelize most of the algorithms from the Standard Library, all you have to do is
specify the first argument into the algorithm.

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

`parallel_policy` 
