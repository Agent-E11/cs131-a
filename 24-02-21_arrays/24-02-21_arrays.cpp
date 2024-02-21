// 24-02-21_arrays.cpp

#include <iostream>

using namespace std;

const int MAX_SIZE = 25;

void print_array(int a[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "]\n";
}

void swap_ints(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int nums[MAX_SIZE];
    int num;
    int i = 0;

    cout << "Enter up to " << MAX_SIZE << " numbers" << endl;
    while (cin >> num) {
        if (num == -99) {
            cout << "Exiting\n";
            break;
        }

        nums[i] = num;
        i++;
        if (i >= MAX_SIZE) {
            break;
        }
    }

    cout << "Unsorted: ";
    print_array(nums, MAX_SIZE);

    // Sort array in place
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < MAX_SIZE; i++) {
            if (nums[i - 1] > nums[i]) {
                swap_ints(nums[i - 1], nums[i]);
                sorted = false;
            }
        }
		print_array(nums, MAX_SIZE);
    }

    cout << "Sorted: ";
    print_array(nums, MAX_SIZE);
}
