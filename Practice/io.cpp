#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string name;
    int score;

    cout << "Enter student name: ";
    cin.ignore(); // clear leftover newline from previous input
    getline(cin, name);

    cout << "Student score: ";
    cin >> score;

    ofstream outFile("scores.txt", ios::app); // Open a file in append mode

    // Checking if file is open, then writing to the file our data
    if (outFile.is_open()) {
        outFile << name << "," << score << endl;
        outFile.close();
    } else {
        cout << "Error: Could not open file for writing." << endl;
        return 1;
    }

    // Checking if file is open, then reading our data back
    ifstream inFile("scores.txt");

    if (inFile.is_open()) {
        string readName;
        int readScore;

        cout << "\n--- Student Scores ---\n";

        string line;

        while (getline(inFile, line)) {
            size_t commaPos = line.find(',');

            if (commaPos != string::npos) {
                string readName = line.substr(0, commaPos);
                int readScore = stoi(line.substr(commaPos + 1));
                cout << readName << " scored " << readScore << endl;
            } else {
                cout << "Error: Incorrect file format." << endl;
                return 1;
            }
        } // end of while loop

        inFile.close();  // Close file after reading all lines

    } else {
        cout << "Error: Could not open file for reading." << endl;
        return 1;
    }

    return 0;
} 
