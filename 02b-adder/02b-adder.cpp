// 02b-adder.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Initialize sum
	int sum = 0;
	
	while (true) { // Loop forever
		string input;

		// Get input
		cout << "Enter number: ";
		cin >> input;

		try {
			// Convert to int
			int n = stoi(input);

			if (n == 0) { break; } // If the number is 0, exit the loop

			// Add number to sum
			sum += n;
		}
		catch (exception& e) {
			// If there was an error converting, print error
			cerr << "error: " << e.what() << endl;
		}
	}

	// Print sum
	cout << "Sum: " << sum << endl;
}

