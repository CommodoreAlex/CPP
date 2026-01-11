#include <iostream>
#include <thread>
#include <vector>
#include <numeric> // for std::iota

int main() {
  const auto printThreadID = [](const char* str) {
    std::cout << str << ": "
              << std::this_thread::get_id() << " thread id\n";
  };

  std::vector<int> numbers(100);

  std::thread iotaThread([&numbers, &printThreadID](int startArg) {
    std::iota(numbers.begin(), numbers.end(), startArg);
    printThreadID("iota in");
  }, 10);

  iotaThread.join();
  printThreadID("printing numbers in");

  for (const auto& num : numbers) {
    std::cout << num << ", ";
  }
}
