// 24-01-08_uppercaser.cpp
// In-class project (ungraded)

#include <iostream>

using namespace std;

int main()
{
	char input;
char modified;

	cout << "Input a letter: ";
	cin >> input;
	cout << endl;

	if (input >= 'a' && input <= 'z') { // Check if input is a lowercase letter
		modified = input - 32; // Change to uppercase
	}
	else if (input >= 'A' && input <= 'Z') { // Check if input is an uppercase letter
		modified = input + 32; // Change to lowercase
	}
	else { // If it's not a letter, exit
		cout << "Invalid input" << endl;
		return 1;
	}

	cout << "You input: " << input << endl;
	cout << "Modified : " << modified << endl;
}