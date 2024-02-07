// 24-01-31_sorting.cpp

#include <iostream>

const int LEN = 16;

using namespace std;

void swap_numbers(int& x, int& y);

void print_array(int l [LEN]);

void bubble_sort(int l [LEN]);

int main()
{
	int list [LEN] = { 5, 3, 7, 1, 34, 8, 0, 2, 6, 6, 9, 12, 65, 3, 8, 98 };

	cout << "List: ";
	print_array(list);

	bubble_sort(list);
}

void swap_numbers(int& x, int& y) {
	int tmp = x;

	x = y;
	y = tmp;
}

void print_array(int l [LEN]) {
	cout << "[ ";
	for (int i = 0; i < LEN; i++) {
		cout << l[i] << " ";
	}
	cout << "]" << endl;
}

void bubble_sort(int l[LEN]) {
	bool is_sorted;
	do {
		is_sorted = true;

		for (int i = 0; i < LEN - 1; i++) {
			if (l[i] > l[i + 1]) {
				swap_numbers(l[i], l[i + 1]);
				is_sorted = false;
			}
			print_array(l);
		}
		cout << endl;
	} while (!is_sorted);
}
