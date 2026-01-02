#include <iostream>

// Inheriting from a lambda is possible

template<typename Callable>
class ComplexFn : public Callable {
public:
  explicit ComplexFn(Callable f) : Callable(f) {} // no implicit conversion
};

template<typename Callable>
ComplexFn<Callable> MakeComplexFunctionObject(Callable&& cal) {
  return ComplexFn<Callable>(std::forward<Callable>(cal));
}

int main() {

  const auto func = MakeComplexFunctionObject([]() {
    std::cout << "Hello Complex Function Object!";
  });

  func();

  return 0;
}
