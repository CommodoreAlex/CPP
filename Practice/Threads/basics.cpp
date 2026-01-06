#include <iostream>
#include <thread>

void workerFunction(std::string message) {
  std::cout << "Thread says: " << message << std::endl;
}

int main() {
  std::thread t1(workerFunction, "Hello from thread 1");
  std::thread t2(workerFunction, "Hello from thread 2");

  t1.join();
  t2.join();

  std::cout << "Both threads finished." << std::endl;
  return 0;
}
