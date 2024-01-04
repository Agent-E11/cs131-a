// 01-multiplier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int nums[3];

	int i = 0;

	while (i < 3) {
		string s;
		cout << "Enter number " << i + 1 << ":" << endl;
		
		try {
			cin >> s;
			nums[i] = stoi(s);
			i++;
		} catch (const exception& e) {
			cerr << "Error: " << e.what() << endl;
			cerr << "Try again.";
		}
	}

	cout << "Numbers:";
	for (int n : nums)
		cout << " " << n;
	cout << endl;

	cout << "Result: (" << nums[0] << "*" << nums[1] << ")+" << nums[2] << " = " << nums[0]*nums[1] + nums[2] << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
