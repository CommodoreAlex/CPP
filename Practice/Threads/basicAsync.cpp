#include <iostream>
#include <future>

int compute() {
  return 42;
}

int main() {

  // std::async launches compute() in a background thread; returning a future
  std::future<int> result = std::async(std::launch::async, compute);

  // future.get() waits for the result and returns it
  std::cout << "Result: " << result.get() << std::endl;

  return 0;
}
