Example of a race condition:
```cpp
#include <iostream>
#include <thread>

int counter = 0;

void worker() {
    for (int i = 0; i < 100000; i++) {
        counter++;   // NOT SAFE
    }
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << "Final counter: " << counter << std::endl;
    return 0;
}
```

To mitigate these you should use mutex, semaphores, or atomics.
