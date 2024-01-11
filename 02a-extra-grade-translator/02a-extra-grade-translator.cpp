// 02a-extra-grade-translator.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Declare variables
    string input;
    int score;

    // Get raw input
    cout << "What was your score? (0 to 100): ";
    cin >> input;
    cout << endl; // New line

    // !!! This is not part of the logic! Only error handling before actual logic !!!
    // Convert to integer using `stoi`
    try {
        score = stoi(input);
    } catch (exception& e) {
        cerr << "\"" << input << "\" is not a valid integer" << endl;
        return 1;
    }

    // Clamp score to 0..90
    int clamped_score = max(min(score, 90), 0);

    int divided = clamped_score / 10;

    // --- Convert the range 0..9 (score) to 74..65 (characters J..A, lower number = later grade = higher char code)

    // Reverse order of range

    // Convert to a float
    float num = static_cast<float>(divided);

    // Middle of the range 0..9
    const float MID = 4.5;

    // Find the distance to the middle of the range
    float diff_to_mid = num - MID;

    // "Reflect" the number across the middle of the range
    int reflected = static_cast<int>(MID - diff_to_mid);

	// Apply offset

    int char_code = reflected + 65;

    // --- Change any score in 69..65 to 70 (E..J to F)

    char_code = min(char_code, 69); // Change any code in E..J (69..74) to E (69)

    // Find the difference to E
    int diff_to_e = char_code - 69;

    // If the difference is 0, then the character is E
    int is_e = !(diff_to_e); // diff = 0: is_e = 1, diff != 0: is_e = 0

    // Apply offset based on if it is E (if it is E, add 1)
    char_code += is_e;

    // Convert `char_code` to char
    char grade = char_code;

    // Print score and grade
    cout << "With a score of \"" << score << "\", you got a grade of \"" << grade << "\"" << endl;
}
