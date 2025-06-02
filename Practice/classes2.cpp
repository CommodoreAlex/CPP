#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Class Student
class Student {
    
    // Encapsulated, only accessible via member functions
    private:
        vector<int> scores; // Vector to store 5 exam scores
        
    public:
        // Constructors
        void input() {
            int score;
            for (int i = 0; i < 5; i++) {
                cin >> score;            // Read score from input
                scores.push_back(score); // Append to scores vector
            }
        }
    
        // Return the sum of all scores stored in the scores vector
        int calculateTotalScore() {
            int total = 0;
            for (int i = 0; i < scores.size(); i++) {
                total += scores[i]; // Add each score to the total
            }
            return total;
        }    
};


int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
