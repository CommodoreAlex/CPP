#include <functional>

int main() {

  // This works because std::function is a full object type
  // The lambda stores a reference to that object
  // After init, the lambda can call it recursively
  const std::function<int(int)> factorial = [&factorial](int n) {
    return n > 1 ? n * factorial(n - 1) : 1;
  };

  return factorial(5);
}
