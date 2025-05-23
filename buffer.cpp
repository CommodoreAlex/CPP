#include <iostream>

int main() {
    const int SIZE = 10;
    char buffer[SIZE];  // Fixed-size buffer on the stack

    // Write: Fill buffer with A-J
    for (int i = 0; i < SIZE; ++i) {
        buffer[i] = 'A' + i;
    }

    // Read: Print buffer contents
    for (int i = 0; i < SIZE; ++i) {
        std::cout << buffer[i] << ' ';
    }

    std::cout << std::endl;
    return 0;
}
