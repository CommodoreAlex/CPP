#include <memory>
#include <iostream>
using namespace std;

struct Resource {

	// Constructor: Runs when a resource object is created
	Resource() { cout << "Resource acquired\n"; }

	// Destructor: Runs when the object is destroyed
	~Resource() { cout << "Resource destroyed\n"; }
};

int main() {


	// Lambda function named deleter; 
	auto deleter = [](Resource* r) {
		cout << "Custom deleter called\n";
		delete r;	// Deletes the pointer manually (frees memory that 'r' points to)
	};

	// Creates unique_ptr named 'res'. Manages a Resource() object created with new Resource
	// Uses the custom deleter lambda instead of the default deleter
	// Decltype tells the compiler the exact type of lambda so it can be used as the deleter

	// unique_ptr<T, Deleter>(T* ptr, Deleter d);
	unique_ptr<Resource, decltype(deleter)> res(new Resource, deleter);
}
