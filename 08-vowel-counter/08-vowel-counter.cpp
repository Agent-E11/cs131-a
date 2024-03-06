// 08-vowel-counter.cpp

#include <iostream>
#include <string>

/// <summary>
/// Counts the number of vowels in a word
/// </summary>
/// <param name="word">A single word</param>
/// <returns>The number of vowels in the word. Returns -1 if there was an error</returns>
int count_vowels(std::string word) {
	const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	int count = 0;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == ' ') return -1;
		const char* pos = std::find(std::begin(vowels), std::end(vowels), word[i]);
		if (pos != std::end(vowels)) {
			count++;
		}
	}
	return count;
}

int main() {
	int c;

	c = count_vowels("test");
	std::cout << "test: " << c << std::endl;
	c = count_vowels("tree");
	std::cout << "tree: " << c << std::endl;
	c = count_vowels("6357");
	std::cout << "6357: " << c << std::endl;
	c = count_vowels("floozle");
	std::cout << "floozle: " << c << std::endl;
	c = count_vowels("faster");
	std::cout << "faster: " << c << std::endl;
	c = count_vowels("two words");
	std::cout << "two words: " << c << std::endl;
}
