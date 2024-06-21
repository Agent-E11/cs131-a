// 08-vowel-counter.cpp

#include <iostream>
#include <string>
#include <vector>

/// <summary>
/// Counts the number of vowels in a word
/// </summary>
/// <param name="word">A single word</param>
/// <returns>The number of vowels in the word. -1 if there was an error</returns>
static int count_vowels(std::string word) {
	const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	int count = 0;
	for (int i = 0; i < word.length(); i++) {
		// If the character is a space, then it isn't a single word
		if (std::isspace(word[i])) return -1;

		// Find position of letter in vowels
		const char* pos = std::find(std::begin(vowels), std::end(vowels), word[i]);

		// If the letter is in vowels, increment the count
		if (pos != std::end(vowels))
			count++;
	}

	// If there are no other vowels, search for `y`s
	if (count == 0)
		for (int i = 0; i < word.length(); i++)
			if (word[i] == 'y')
				count += 1;

	return count;
}

/// <summary>
/// Splits a string into a vector of words.
/// A word is a group of characters surrounded by any amount of whitespace.
/// Whitespace is defined by std::isspace().
/// 
/// Multiple spaces in a row will be treated the same as a single space
/// </summary>
/// <param name="s">String to be split</param>
/// <returns>A vector of words</returns>
static std::vector<std::string> split_words(std::string s) {
	std::vector<std::string> words;
	std::string word = "";

	// Loop through the characters in the sentence
	for (int i = 0; i < s.length(); i++) {
		if (std::isspace(s[i])) {
			if (word.empty()) {
				// If the character is whitespace and the word is empty, ignore it
				continue;
			}
			else {
				// If the character is whitespace and there is a word,
				// add it to words and reset the word
				words.push_back(word);
				word = "";
			}
		}
		else {
			// If the character is not whitespace, add it to the word
			word += s[i];
		}
	}
	// Add the final word (If it isn't empty)
	if (!word.empty()) words.push_back(word);

	return words;
}

static void print_vec(std::vector<std::string> v) {
	std::cout << "[ ";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ", ";
	std::cout << "]" << std::endl;
}

int main() {
	// Get input
	std::cout << "Enter a sentence: ";
	std::string input;
	std::getline(std::cin, input);

	// Split into words
	std::vector<std::string> words = split_words(input);

	print_vec(words);

	// Sum up all vowels in all words
	int count = 0;
	for (int i = 0; i < words.size(); i++) {
		int c = count_vowels(words[i]);

		// If there was an error, quit the program
		if (c == -1)
			exit(1);

		count += c;
	}

	std::cout << "Total vowels: " << count << std::endl;
}
