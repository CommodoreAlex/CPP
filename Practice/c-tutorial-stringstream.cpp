#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	
    // A vector of the parsed integers
    vector<int> result;
    
    // Creating a stringstream using our parameter
    stringstream ss(str);
    
    int num; // Holding our values
    char ch; // Use for discarded comma delimiters
    
    while (ss >> num) { // Extract integers
        result.push_back(num);
        ss >> ch; // Extract commas if any
    }
    
    return result; // Return parsed integers
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
