// 02a-grade-translator.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Declare variables
	string input;
	int score;
	string grade;

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
	if (score > 100 || score < 0) {
		cerr << "Your score must be in between 0 and 100." << endl; // No extra credit or negative scores allowed
		return 2;
	}

	// Convert to letter grade
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
