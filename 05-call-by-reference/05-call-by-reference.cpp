// 05-call-by-reference.cpp

#include <iostream>

using namespace std;

void calculate_change(int cents, int& q, int& d, int& n, int& p) {
    q = cents / 25;
    cents %= 25;
    d = cents / 10;
    cents %= 10;
    n = cents / 5;
    cents %= 5;
    p = cents;
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
		int cents, q, d, n, p;

        cents = rand() % 1000;

		calculate_change(cents, q, d, n, p);

		cout << "Cents:   " << cents << endl;
		cout << "Quaters: " << q << endl;
		cout << "Dimes:   " << d << endl;
		cout << "Nickels: " << n << endl;
		cout << "Pennies: " << p << endl;

        cout << "Summed: " << q*25 + d*10 + n*5 + p << endl << endl;
    }
}
