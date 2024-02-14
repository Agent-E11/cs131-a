// 24-2-14_midterm.cpp

//#include <iostream>
//#include <string>
//
//using namespace std;

/// --- Question 3 ---
//void question_3() {
//	string input;
//
//	cout << "What is your name?: ";
//	cin >> input;
//
//	cout << "Hello, " << input << "!" << endl;
//}
//
//int main() {
//	question_3();
//	return 0;
//}

/// --- Question 4 ---
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int quantity = 3;
//    float price = 1.50; // Change type from `int` to `float`
//    cout << "The total cost is " << (quantity * price) << endl;
//    system("pause");
//    return 0;
//}

/// --- Question 5 ---
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int num1 = 3, num2 = 4;
//    if (num1 == num2) // Change from assignment `=` to comparison `==`
//    {
//        cout << "They are equal." << endl;
//    }
//    else
//    {
//        cout << "They are not equal." << endl;
//    }
//    system("pause");
//    return 0;
//}

/// --- Question 8 ---
///*
//The following program is supposed to follow the standard grading scale of
//90 + = A, 80 - 89 = B, 70 - 79 = C, 60 - 69 = D, and less than 60 = F.
//When given a score of 70, however, it prints a D.
//
//What one - line change would you make to the program to make it work properly ?
//*/
//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int score = 70;
//
//    if (score >= 90) {
//        cout << "A" << endl;
//    }
//    else if (score >= 80) {
//        cout << "B" << endl;
//    }
//    else if (score >= 70) {
//        cout << "C" << endl;
//    }
//    else if (score >= 60) {
//        cout << "D" << endl;
//    }
//    else {
//        cout << "F" << endl;
//    }
//    system("pause");
//    return 0;
//}

/// --- Question 9 ---
///*
//The following series of IF statements is supposed to follow the standard grading scale of 
//90+ = A, 80-89 = B, 70-79 = C, 60-69 = D, and less than 60 = F.  
//It is supposed to take a score and convert it to the appropriate letter grade.
//
//Test the program and describe how it does not work.  
//
//Then describe how you would fix this program.
//*/
//
//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int score;
//
//    cout << "Input grade: ";
//
//    cin >> score;
//
//    if (score >= 90)
//    {
//        cout << "A" << endl;
//    }
//    else if (score >= 80) // Change `if` statements to `else if` statements
//    {
//        cout << "B" << endl;
//    }
//    else if (score >= 70)
//    {
//        cout << "C" << endl;
//    }
//    else if (score >= 60)
//    {
//        cout << "D" << endl;
//    }
//    else
//    {
//        cout << "F" << endl;
//    }
//    system("pause");
//    return 0;
//}

/// --- Question 10 ---
///*
//The following while loop should produce "2 4 6 8 Who do we appreciate?"
//
//1) What does it do?
//2) Enter one corrected line that fixes the program.
//*/
//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int count = 2;
//
//    // Cheer loop
//    while (count < 9) // Change `!=` to `<`
//    {
//        cout << count << " ";
//        count += 2;
//    }
//    cout << "\nWho do we appreciate?\n";
//    system("pause");
//    return 0;
//}

/// --- Question 11 ---
///*
//A short C++ program that asks the user for a number and uses a do-while loop to print the number as many times as the number
//*/
//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int number;
//
//    cout << "Number: ";
//
//    cin >> number;
//
//    int i = 0;
//    do {
//        cout << number << " ";
//        i++;
//    } while (number > i);
//
//    cout << endl;
//
//    system("pause");
//    return 0;
//}

/// --- Question 12 ---
///*
//The following while loop does a countdown to "Blastoff"!
//
//Convert the "while" loop to a "for" loop.
//*/
//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    for (int i = 5; i > 0; i--) {
//        cout << i << " ";
//    }
//
//    cout << "\nBlastoff!\n";
//
//    system("pause");
//    return 0;
//}

/// --- Question 13 ---
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// implement getNumberOfSides
//int getNumberOfSides(string shape) {
//    if (shape == "Triangle") {
//        return 3;
//    }
//    if (shape == "Square") {
//        return 4;
//    }
//    if (shape == "Hexagon") {
//        return 6;
//    }
//}
//
//int main() {
//    int numSides;
//    string shape;
//
//    cout << "Input a shape (Triangle, Square, or Hexagon): ";
//
//    cin >> shape;
//
//    numSides = getNumberOfSides(shape);
//
//    cout << "A " << shape << " has " << numSides << " sides. Now you know!\n";
//
//    system("pause");
//    return 0;
//}

/// --- Question 14 ---
//#include <iostream>
//
//using namespace std;
//
//// implement doubleThis as a Call By Reference function
//void doubleThis(int& num) {
//    num *= 2;
//}
//
//int main()
//{
//    int num;
//
//    cout << "Input number: ";
//
//    cin >> num;
//
//    doubleThis(num);
//
//    cout << "x2=" << num << "\n";
//
//    system("pause");
//    return 0;
//}

/// --- Question 15 ---
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string scores_file = "C:\\Users\\eamon.burns.BELTEC\\scores.txt";
    ifstream input_file;

    int scores[5] = { 0, 0, 0, 0, 0 }; // I already know that there are only 5 scores

    // Open file for reading
    input_file.open(scores_file);

    // Read lines into scores
    for (int i = 0; i < 5; i++) {
        int input;
        if (input_file >> input) {
            cout << "Storing value: " << input << endl;
            scores[i] = input;
        }
        else {
            cout << "EOF, exiting..." << endl;
            break;
        }
    }

    // Sum all the numbers
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }

    // Print out sum and average
    cout << "\nTotal sum: " << sum << endl;
    cout << "Mean average: " << static_cast<float>(sum) / 5 << endl; // Cast the sum into a float so that the result won't be trucated

    input_file.close();
}
