// 03-number-guesser.cpp

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    const int range_start = 1;
    const int range_length = 10;
    const int num_of_guesses = 3;

    int range_end = range_start + (range_length - 1); // Calculate last number in range

    int guessed_num;
    int correct_num;

    srand(time(NULL)); // Seed RNG

    correct_num = rand() % range_length + range_start; // Get a random number in the range

    // Print random number (for debugging)
    cout << "Random number: " << correct_num << endl << endl;

    // Prompt user
    cout << "Guess a number between " << range_start
        << " and " << range_end
        << ", you have " << num_of_guesses
        << " guesses" << endl;

    for (int i = 0; i < num_of_guesses; i++) {
        cout << endl;
        cout << "Guess " << i + 1 << ": ";
        cin >> guessed_num; // No error handling

        // Check if the number was correct
        if (guessed_num == correct_num)
        {
            cout << "Correct!" << endl; // Congratulate and break out of loop
            break;
        }
        else if (guessed_num > correct_num)
        {
            cout << "Too high." << endl;
        }
        else if (guessed_num < correct_num)
        {
            cout << "Too low." << endl;
        }
    }

    cout << "The number was " << correct_num << endl;
}
