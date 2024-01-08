// 01-multiplier.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Declare number array
    int nums[3];

    // Initialize index
    int i = 0;

    // Loop until `i` is 3 (until the `nums` array is filled)
    while (i < 3) {
        string str;
        cout << "Enter number " << i + 1 << ": "; // Prompt user
        cin >> str; // Get input
        cout << endl; // New line

        try {
            nums[i] = stoi(str); // Convert and place in array
            i++; // If it was successful, go to next number
        } catch (const exception& e) {
            // If there was an error, print it out and try again
            cerr << "Error: " << e.what() << endl;
            cerr << "Try again.";
        }
    }

    // Print all numbers
    cout << "Numbers:";
    for (int n : nums)
        cout << " " << n;
    cout << endl;

    // Calculate result
    int result = nums[0] * nums[1] + nums[2];

    // Print result
    cout << "Result: (" << nums[0] << "*" << nums[1] << ")+" << nums[2] << " = " << result << endl;
}
