#include <iostream>
#include <string>
#include <cctype> // For isupper, islower, isdigit

using namespace std;

int main(){
    string password;

    cout << "Enter your password: ";
    cin >> password;

    cout << "You entered: " << password << endl;

    // Initializing our variables for string analysis
    int upperCount = 0;
    int lowerCount = 0;
    int digitCount = 0;
    int symbolCount = 0;


    // Logic to loop through string
    for (char c : password) {
        if (isupper(c))
            upperCount++;
        else if (islower(c))
            lowerCount++;
        else if (isdigit(c))
            digitCount++;
        else
            symbolCount++;
    }

    // Debugging: printing counts
    cout << "Uppercase: " << upperCount << endl;
    cout << "Lowercase: " << lowerCount << endl;
    cout << "Digits: " << digitCount << endl;
    cout << "Symbols: " << symbolCount << endl;


    // Grading the password
    int length = password.length();

    if (length < 6 || (upperCount == 0 && lowerCount == 0) || (digitCount == 0 && symbolCount == 0)) {
        cout << "Strenght of '" << password << "': Weak" << endl;
    }
    else if (length >= 8 && upperCount > 0 && lowerCount > 0 && digitCount > 0 && symbolCount > 0){
        cout << "Strength of '" << password << "': Strong" << endl;
    }
    else {
        cout << "Strength of '" << password << "': Medium";
    }

    return 0;
}
