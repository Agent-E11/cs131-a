// 06-file-io-grade-translator.cpp

#include <iostream>
#include <fstream>

using namespace std;

string get_grade(int score);

int main() {
	string files_dir = "C:\\Users\\eamon.burns.BELTEC\\coding\\cs131-a\\04-custom-function\\io-files\\";
	string out_file_name = "translated-grades.txt";
	string in_file_name = "raw-grades.txt";
	ofstream output_file;
	ifstream input_file;

    string name;
    int score;

    // Remove contents of old file
    output_file.open(files_dir + out_file_name);
    output_file << "";
    output_file.close();

    // Open files for reading and writing
    input_file.open(files_dir + in_file_name);
    output_file.open(files_dir + out_file_name, ios_base::app);

    // Loop over input (format of file is `<name> <score>` for each line)
    while (input_file >> name >> score) {
        // Construct each line
        string grade_line = name + " " + get_grade(score) + "\n";
        // Print the line and append it to the output file
        cout << grade_line;
        output_file << grade_line;
    }
    // Close files
    input_file.close();
    output_file.close();
}

string get_grade(int score) {
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
