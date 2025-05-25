#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Student {
    string name; // Holding the name of a student
    vector<int> scores; // This is a dynamically resizable array of integers
};

// Function to calculate grades
char calculateGrade(double average) {
    if (average >= 90.0) return 'A';
    else if (average >= 80.0) return 'B';
    else if (average >= 70.0) return 'C';
    else if (average >= 60.0) return 'D';
    else return 'F';
}

// Function to calculate average from vector of scores
double calculateAverage(const vector<int>& scores) {
    int total = 0;
    for (int score : scores) {
        total += score;
    }
    return static_cast<double>(total) / scores.size();
}

int main() {
    vector<Student> students; // Declard vector to hold multiple student objects 
    char more;                // Holding a 'char' of y/n

    // Start a do-while loop so the code inside runs at least once, or more
    do {
        Student student; // Create a new student object to hold one student's data

        cout << "Enter student name: ";
        getline(cin, student.name);  // Do NOT call cin.ignore() here

        cout << "Enter 3 test scores:\n";

        for (int i = 0; i < 3; ++i) {

            int score;

            while (true) {

                cout << "Score " << (i + 1) << ": ";
                cin >> score;

                if (cin.fail() || score < 0 || score > 100) {
                    cout << "Invalid score. Please enter a number between 0 and 100.\n";

                    // Clear error flags and discard invalid input
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;  // Valid input, exit inner loop and move to next score
                }
            }
            student.scores.push_back(score);  // Add validated score to vector
        }

        students.push_back(student);

        cout << "Add another student? (y/n): ";
        cin >> more;
        cin.ignore();  // Clear the newline after user inputs y/n

    } while (tolower(more) == 'y');

    // Calling the actual object in memory '&' (otherwise it copies the whole vector)
    // Adding const tells the compiler this loop should not modify the Student object s (read-only data)
    cout << "\n--- Student Records ---\n";


    for (const Student& s : students) {
        cout << "Name: " << s.name << "\nScores: ";

        for (int score : s.scores) {
            cout << score << " ";
        }

        double average = calculateAverage(s.scores);
        char grade = calculateGrade(average);

        cout << "\nAverage Score: " << average;
        cout << "\nGrade: " << grade << "\n\n";

    }

    return 0;
}
