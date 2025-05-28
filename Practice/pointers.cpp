#include <iostream>

using namespace std;

int main(){

    // 1. Basic pointer to an integer
    int number = 42; // A normal integer variable
    int* ptr = &number;    // Pointer to 'number' (stores the address)

    cout << "Value of a number: " << number << "\n";
    cout << "Address of number (&number): " << &number << "\n";
    cout << "Value stored in ptr: " << ptr << " (same as &number)\n";
    cout << "Value pointed to by ptr (*ptr): " << *ptr << "\n\n";

    // 2. Modify value through the pointer
    *ptr = 100; // Change the value at the address ptr points to
    cout << "After *ptr = 100, number = " << number << "\n\n";

    // 3. Pointer and Arrays
    int buffer[5] = {10, 20, 30, 40, 50};
    int* bufPtr = buffer; // Points to the first element of the array

    cout << "Accessing array using pointer:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "buffer[" << i << "] = " << *(bufPtr + i) << "\n";
        // *(bufPtr) + i is the same as buffer[i]
    }

    cout << "\n";

    // 4. Pointer Arithmetic
    cout << "Demonstrating pointer arithmetic:\n";
    cout << "butPtr poitns to: " << *bufPtr << "\n";
    bufPtr++; // Moves to the next integer in the array
    cout << "After bufPtr++, it points to: " << *bufPtr << "\n";
    bufPtr += 2; // Move two more elements ahead
    cout << "After bufPtr += 2, it points to: " << *bufPtr << "\n\n";

    // 5. Reset pointer to start of buffer
    bufPtr = buffer; // Back to the beginning

    // 6. Alternative: using array syntax with pointers
    cout << "Alternative syntax: bufPtr[i] behaves like buffer[i]:\n";
    for (int i = 0; i < 5; i++) {
        cout << "bufPtr[" << i << "] = " << bufPtr[i] << "\n";
    }


    return 0;
}
