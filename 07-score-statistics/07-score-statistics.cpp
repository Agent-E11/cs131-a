// 07-score-statistics.cpp

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

void print_vector(vector<int> v) {
	cout << "[ ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "]\n";
}

int main() {
	vector<int> scores = {};
	string input;

	cout << "Input scores one at a time, separated by new lines (q to quit):\n";

	while (cin >> input) {
		if (input == "q" || input == "Q") {
			break;
		}

		try {
			int score = stoi(input);

			scores.push_back(score);
		}
		catch (exception& e) {
			cout << "Invalid number" << endl;
		}
	}

	// Calculate maximum, minimum, and average

	int max = 0,
		min = numeric_limits<int>::max(),
		sum = 0;
	float avg = 0;

	int n;
	for (int i = 0; i < scores.size(); i++) {
		n = scores[i];
		if (n > max)
			max = n;

		if (n < min)
			min = n;

		sum += n;
	}

	avg = static_cast<float>(sum) / scores.size();

	float closest_diff = numeric_limits<float>::infinity();
	int closest_i = 0;
	float diff;
	for (int i = 0; i < scores.size(); i++) {
		n = scores[i];
		diff = abs(n - avg);
		if (diff < closest_diff) {
			closest_diff = diff;
			closest_i = i;
		}
	}

	cout << "Scores: ";
	print_vector(scores);

	// Display stats
	cout << "Max: " << max << "\n";
	cout << "Min: " << min << "\n";
	cout << "Avg: " << avg << "\n";

	// Display closest score
	cout << "\nScore closest to the average: " << scores[closest_i] << endl;
	cout << "With a difference of: " << closest_diff << endl;
}
