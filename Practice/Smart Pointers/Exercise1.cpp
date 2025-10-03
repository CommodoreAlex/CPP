#include <memory>
#include <iostream>
using namespace std;

int main() {

	// Exclusive Ownership

	// Declares a smart pointer that will manage an int. Owns a piece of memory and ensures cleanup
	unique_ptr<int> ptr = make_unique<int>(10);	// Create new int on the heap and wraps it in a unique_ptr; safer than using new
	cout << "Value: " << *ptr << endl;

	// Ownership transfer
	unique_ptr<int> ptr2 = move(ptr);
	if (!ptr) cout << "PTR1 is null after the move.\n";
	cout << "PTR2 value: " << *ptr2 << endl;

	return 0;
}
