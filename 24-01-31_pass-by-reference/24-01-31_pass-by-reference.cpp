// 24-01-31_pass-by-reference.cpp

#include <iostream>
using namespace std;

int doublePlusOne(int n) {
    return 2 * n + 1;
}
void doublePlusOneRef(int& n) {
    n = 2 * n + 1;
}

int main()
{
    int a = 1;

    cout << &a;
}
