#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <chrono>  // For timing
#include <thread>
#include <future>
#include <mutex>
using namespace std;


// Function to sum all elements in a vector, without modifying the vector via const
// The vector is passed by reference to avoid copying large data
long long sequentialSum(const vector<int>& data) {
    return accumulate(data.begin(), data.end(), 0LL); // 0LL = long long initial sum, adds up values in a range with accumulate
}


// Parallel processing with control over how many thread to use
long long parallelSum(const vector<int>& data,int numThreads) {
    size_t length = data.size();
    size_t blockSize = length / numThreads;

    vector<future<long long>> futures; // Initilaize a long, long vector for asynchronous processing via futures

    // Launch threads
    for (int i = 0; i < numThreads; i++) {
        size_t start = i * blockSize;                                // Start index of this chunk
        size_t end = (i == numThreads - 1) ? length : start + blockSize;  // Last chunk takes any leftover

        // Launch async thread for the range [start, end)
        futures.push_back(async(launch::async, [start, end, &data]() -> long long {
            return accumulate(data.begin() + start, data.begin() + end, 0LL);
        }));
    }

    // Handles synchronization internally, safely waiting for threads result
    long long total = 0;
    for (auto& fut : futures) {
        total += fut.get();
    }

    return total;
}

int main() {

    const size_t size = 100'000'000; // 100 million elements, unsigned integer type to hold large objects
    vector<int> data(size, 1);       // Fill vector with 1s

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    long long sum = sequentialSum(data);

    // Stop timing
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Sequential Sum
    cout << "Sequential sum: " << sum << endl;
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    // Paralell Sum
    int numThreads = thread::hardware_concurrency(); // Use number of cores available
    if (numThreads == 0) numThreads = 4;              // Fallback default if unknown

    start = chrono::high_resolution_clock::now();
    long long parSum = parallelSum(data, numThreads);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> parDuration = end - start;

    cout << "Parallel sum (" << numThreads << " threads): " << parSum << endl;
    cout << "Time taken (parallel): " << parDuration.count() << " seconds" << endl;

    return 0;
}
