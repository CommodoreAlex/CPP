#include <iostream>
using namespace std;

int main (){

    string str = "Hello, world!";
    cout << "Full String: " << str << endl;

    // Extract the substring "Hello"
    string substr1 = str.substr(0, 5);
    cout << "First slice: " << substr1 << endl;

    // Extract the substring "world!"
    string substr2 = str.substr(7, 6);
    cout << "Second slice: " << substr2 << endl;

    // Attempting to extract an invalid substring to incur an error
    try {
        string substr3 = str.substr(20);
    } catch (const out_of_range& oor) {
        cerr << "Out of Range error: " << oor.what() << endl;
    }

    return 0;
}
