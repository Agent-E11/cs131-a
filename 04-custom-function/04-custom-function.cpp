// 04-custom-function.cpp

#include <iostream>
#include <string>

using namespace std;

string get_grade(int score)
{
    // Make sure score is in the proper range
    if (score > 100 || score < 0) {
        return "X"; // "X" means there was an error
    }

    // Convert to letter grade
    if (score >= 90) {
        return "A";
    } else if (score >= 80) {
        return "B";
    } else if (score >= 70) {
        return "C";
    } else if (score >= 60) {
        return "D";
    }

	return "F";
}

int main()
{
    // Declare variables
    string input;
    int score;

    // Get raw input
    cout << "What was your score? (0 to 100): ";
    cin >> input;
    cout << endl; // New line

    // Convert to integer using `stoi`
    try {
        score = stoi(input);
    } catch (exception& e) {
        cerr << "\"" << input << "\" is not a valid integer" << endl;
        return 1;
    }

    // Convert score to grade
    string grade = get_grade(score);

    // Print score and grade
    if (grade == "X") {
        cerr << "There was an error converting \"" << input << "\" to a grade" << endl;
    }
    else {
        cout << "With a score of \"" << score << "\", you got a grade of \"" << grade << "\"" << endl;
    }
}
