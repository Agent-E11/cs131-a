// 24-03-13_recursion.cpp

#include <iostream>
#include <string>

// Iterative
uint64_t factorio(uint64_t n) {
	int res = 1;
	for (int i = n; i > 0; i--) {
		res *= i;
	}
	return res;
}

// Recursive
uint64_t factorial(uint64_t n) {
	// base case
	if (n == 0) return 1;

	// recursive case
	return n * factorial(n - 1);
}

// Fibonacci
// f(5) = f(4) + f(3)
// f(x) = f(x-1) + f(x-2)
int fibonacci(int n) {
	// base case
	if (n == 0 || n == 1) return n;

	// recursive case
	return fibonacci(n - 1) + fibonacci(n - 2);
}

// Write vertivcal
// Iterative
void write_vertical_iter(int n) {
	std::string buffer = "";
	do {
		buffer.insert(0, std::to_string(n % 10) + '\n');
		n /= 10;
	} while (n > 0); 
	std::cout << buffer << std::endl;
}

// Recursive
void write_vertical(int n) {
	if (n < 10) {
		std::cout << n << std::endl;
	}
	else {
		std::cout << n % 10 << std::endl;
		write_vertical(n / 10);
	}
}

int main() {
	write_vertical(1234);
}
