#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex m;

void worker() {
  for (int i = 0; i < 100000; i++) {
    m.lock();    // lock before touching shared data
    counter++;   // critical section
    m.unlock();  // unlock after
  }
}

int main() {
  std::thread t1(worker);
  std::thread t2(worker);

  t1.join();
  t2.join();

  std::cout << "Final Counter: " << counter << std::endl;
  return 0;
}
