
// call_function can take any callable object (void) f 
// and call it with argument 10
template<typename F>
void call_function(F f) {
  f(10);
}

int main() {

  // Captureless lambda converted to a function pointer
  // static_cast forces the lambda to become a fPointer of type: int (*)(int)
  call_function(static_cast<int (*)(int)>([](int x) { return x + 2; }));

  // A pointer to a function that takes an int and returns an int
  call_function(static_cast<int (*)(int)>([](int x) { return x * 2; }));

  return 0;
}
