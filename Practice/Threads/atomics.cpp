#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

// Used to share data between threads without data races
// These are thead-safe and race-free (no mutex required)

std::atomic<int> counter{};

// Testing atomics
void worker() {
  for (size_t i {}; i < 10; ++i) {
    counter++;  // atomic increment
  }
}

// This is to practice calling a thread with arguments
void printNTimes(const std::string& msg, int n) {
  for (int i {}; i < n; ++i) {
    std::cout << msg << " ";
  }
}

// Launching multiple threads
void vecWork(int id) {
  std::cout << "Thread: " << id << " running\n";
}

int main() {

  std::thread t(worker);  // Start a new thread running worker()
  t.join();               // Wait for it to finish
  std::cout << counter << std::endl;

  std::thread t2(printNTimes, "Hello", 3);
  t2.join();

  // A vector of threads: std::vector<type thread>
  std::vector<std::thread> threads;

  for (size_t i {}; i < 5; ++i) {
    // Build a thread in the vector container
    // push_back inserts an existing object (copy or move)
    // emplace_back creates the object in place (no copy or move)
    threads.emplace_back(vecWork, i);
  }

  // Using auto& in lieu of modifying the container itself; spawning threads
  for (auto& t : threads) {
    t.join();
  }

  return 0;
}
