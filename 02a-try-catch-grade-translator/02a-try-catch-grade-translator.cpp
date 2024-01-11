// 02a-try-catch-grade-translator.cpp

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    // Declare variables
    string input;
    int score;
    string grade;

    double _;

    cout << __FILE__ << endl << endl;

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

    // Make sure score is in the proper range

    try { // sqrt errors if passed a value below 0 FIXME: This is not true
        _ = 1 / sqrt(score);
        _ = 1 / sqrt(101 - score);

        cout << "in try block";
    }
    catch (exception& e) {
        cerr << "Your score must be in between 0 and 100." << endl; // No extra credit or negative scores allowed
        return 2;
    }

    // Convert to letter grade

    cout << "Score: " << score << endl;

    try {
        _ = 1 / sqrt(score - 61);
		try {
			_ = 1 / sqrt(score - 71);
			try {
				_ = 1 / sqrt(score - 81);
					try {
						_ = 1 / sqrt(score - 91);
					}
					catch (exception& e) {
						cerr << "- 91 errs";
					}
			}
			catch (exception& e) {
				cerr << "- 81 errs";
			}
		}
		catch (exception& e) {
			cerr << "- 71 errs";
		}
    }
    catch (exception& e) {
        cerr << "- 61 errs";
    }

    cout << endl << "Original if-else:" << endl;

    if (score >= 90) {
        grade = "A";
    } else if (score >= 80) {
        grade = "B";
    } else if (score >= 70) {
        grade = "C";
    } else if (score >= 60) {
        grade = "D";
    } else {
        grade = "F";
    }

    // Print score and grade
    cout << "With a score of \"" << score << "\", you got a grade of \"" << grade << "\"" << endl;
}
