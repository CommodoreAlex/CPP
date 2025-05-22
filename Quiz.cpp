#include <iostream>

// Avoiding having to use std:: whenever doing 'cout' for printing
using namespace std;

// Structure (struct) to store each quiz question (many variables)
struct Question {
    string text;
    string options[4]; // 'A', 'B', 'C', or 'D'
    char correct; // e.g., 'A'
};

// A sample quiz array
Question quiz[3] = {
    {"Capital of France?", {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"}, 'C'},
    {"2 + 2 = ?", {"A. 3", "B. 4", "C. 5", "D. 6"}, 'B'},
    {"Best programming language?", {"A. Python", "B. Java", "C. C++", "D. COBOL"}, 'C'}
};

int main() {

    // Storing the count of chances to answer correctly
    int totalQuestions = 3;

    // Keeping track of correct answers and user inputs
    int score = 0;
    char userAnswer;

    // Loop through each question in the quiz
    for (int i = 0; i < totalQuestions; i++) {
        cout << "\nQuestion " << (i + 1) << ": " << quiz[i].text << endl;

        // Loop through and print all 4 answer options for the question
        for (int j = 0; j < 4; j++) {
            cout << quiz[i].options[j] << endl;
        }

        // Get user input for the quiz
        cout << "\nYour answer (A/B/C/D): " << endl;
        cin >> userAnswer;

        // Change user input to uppercase char
        userAnswer = toupper(userAnswer);

        if (userAnswer == quiz[i].correct) {
            cout << "\nCorrect!" << endl;
            score++; // Adding to our score counter
        } else {
            cout << "\nWrong. Correct answer is " << quiz[i].correct << ".\n";
        }
    }

    // Final Result
    cout << "\nYou scored " << score << " out of " << totalQuestions << "." << endl;

    return 0;

}
