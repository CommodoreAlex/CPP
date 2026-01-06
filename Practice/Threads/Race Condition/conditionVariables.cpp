#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex m;               // protects shared data
std::condition_variable cv; // allows threads to wait to be notified
std::queue<int> dataQueue;  // shared buffer between producer/consumer
bool done = false;          // tells consumer when the producer is finished

void producer() {
  for (int i = 1; i <= 5; i++) {

    { // <-- start small scope
      std::lock_guard<std::mutex> lock(m);
      dataQueue.push(i);
      std::cout << "Produced: " << i << std::endl;
    } // <-- lock_guard destroyed here, mutex unlocked
    
    cv.notify_one();  // wake up one waiting thread
  }

  { // another small scope
    std::lock_guard<std::mutex> lock(m);
    done = true;
  } // lock released

  cv.notify_one(); // notify consumers that production is done
}

void consumer() {
  while (true) {
    std::unique_lock<std::mutex> lock(m);

    cv.wait(lock, [] { return !dataQueue.empty() || done; });

    if (!dataQueue.empty()) {
      int value = dataQueue.front();
      dataQueue.pop();
      std::cout << "Consumed: " << value << std::endl;
    } else if (done) {
      break;
    }
  }
}

int main() {
  std::thread t1(producer);
  std::thread t2(consumer);

  t1.join();
  t2.join();

  std::cout << "All done." << std::endl;
  return 0;
}

