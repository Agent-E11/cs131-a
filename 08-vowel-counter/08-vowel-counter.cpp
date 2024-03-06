// 08-vowel-counter.cpp

#include <iostream>
#include <string>
#include <vector>

/// <summary>
/// Counts the number of vowels in a word
/// </summary>
/// <param name="word">A single word</param>
/// <returns>The number of vowels in the word. Returns -1 if there was an error</returns>
int count_vowels(std::string word) {
	const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	int count = 0;
	for (int i = 0; i < word.length(); i++) {
		if (std::isspace(word[i])) return -1;
		const char* pos = std::find(std::begin(vowels), std::end(vowels), word[i]);
		if (pos != std::end(vowels)) {
			count++;
		}
	}
	return count;
}

std::vector<std::string> split_words(std::string s) {
	std::vector<std::string> words;
	std::string word = "";

	for (int i = 0; i < s.length(); i++) {
		std::cout << "s[i] = `" << s[i] << "`\t";
		if (std::isspace(s[i])) {
			std::cout << "is space\t";
			if (word.empty()) {
				std::cout << "is empty\t" << std::endl;
				continue;
			}
			else {
				std::cout << "no empty\t";
				words.push_back(word);
				word = "";
			}
		}
		else {
			word += s[i];
			std::cout << "no space\t" << "w: " << word << "\t";
		}
		std::cout << std::endl;
	}
	// Add last word
	if (!word.empty()) words.push_back(word);

	return words;
}

/// <summary>
/// Prints vector<string> to stdout
/// </summary>
/// <param name="v">Vector to be printed</param>
static void print_vec(std::vector<std::string> v) {
	std::cout << "[ ";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ", ";
	std::cout << "]" << std::endl;
}

int main() {
	std::string s = "This is a    long test    of this thi  ng     ";
	auto v = split_words(s);

	print_vec(v);

	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		int c = count_vowels(v[i]);

		if (c == -1)
			exit(1);

		count += c;
	}

	std::cout << "Total vowels: " << count << std::endl;
}
