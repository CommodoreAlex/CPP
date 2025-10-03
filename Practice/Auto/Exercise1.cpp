#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main() {

	vector<int> nums = {1, 2, 3, 4, 5};

	// Type deduction (creating copies of each element in nums)
	for (auto num : nums) {
		cout << num << " ";
		;
	};

	cout << "\nModified numbers:" << endl;

	// Creating a reference to each element (modify original vector through num)
	for (auto& num : nums) { 
		num *= 2;	// Modify original vector elements
		cout << "Value: " << num << ", Type: " << typeid(num).name() << endl;
	};

	// Create a read only reference
	for (const auto& num : nums) { cout << num << " "; };

	return 0;
}
