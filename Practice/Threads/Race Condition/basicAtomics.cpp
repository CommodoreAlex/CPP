#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> counter{0};

void worker() {
  for (int i = 0; i < 100000; i++) {
    counter++;  // atomic increment
  }
}

int main() {

  std::vector<std::thread> threads;

  for (int i = 0; i < 5; i++) {
    threads.emplace_back(worker);
  }

  for (auto& t : threads) {
    t.join();
  }

  std::cout << "Final counter: " << counter << std::endl;
  return 0;
}
