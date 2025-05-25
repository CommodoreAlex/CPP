#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Sum function
int simpleArraySum(vector<int> ar) {
    int sum = 0; // Initialize the sum

    // Using a range-based loop to add to sum
    for ( int num : ar ) {
        sum += num;
    }

    return sum;
}

int main() {

    int n;
    cout << "How many numbers do you want to enter? ";
    cin >> n;

    vector<int> numbers; // Declare vector to store inputs

    cout << "Enter " << n << " numbers:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Number " << (i + 1) << ": ";
        int value;
        cin >> value;
        numbers.push_back(value); // Add to vector
    }

    cout << "You entered: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    // Calling our sum function to return our array sum
    int result = simpleArraySum(numbers);
    cout << "\nSum of array: " << result << endl;

    return 0;

 }
