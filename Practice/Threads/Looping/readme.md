
Boiler plate for looping threads:
```cpp
#include <iostream>
#include <thread>
#include <vector>

void worker(int id) {
  std::cout << "Thread " << id << " is running" << std::endl;
}

int main() {
  std::vector<std::thread> threads;

  for (size_t i {}; i < 5; i++) {
    threads.emplace_back(worker, i);
  }

  for (auto& t : threads) {
    t.join();
  }

  std::cout << "All threads finished." << std::endl;
  return 0;
}
```
