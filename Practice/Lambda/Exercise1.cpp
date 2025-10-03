#include <iostream>
using namespace std;

int main() {

	int multiplier = 3;

	// Lambda that captures 'multiplier' and takes an int argument 'x'
	auto multiply = [multiplier](int x) {
		return x * multiplier;
	};

	int result = multiply(5);	// Pass 5 as argument
	cout << "Result: " << result << endl;

	return 0;
}
