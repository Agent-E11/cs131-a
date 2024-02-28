// 24-02-28_pointers.cpp

#include <iostream>

using namespace std;

int main()
{
    // * : create a pointer
    // & : get a pointer to an existing variable

    int* p1, * p2; // Declare a pointer
    int** p3;

    int n1 = 111;
    int n2 = 222;

    // Assign the pointers
    p1 = &n1;
    p2 = &n2;

    //cout << "n1: " << n1 << "\nn2: " << n2 << endl;
    //cout << "&n1: " << &n1 << "\n&n2: " << &n2 << endl;
    //cout << "p1: " << p1 << "\np2: " << p2 << endl;
    //cout << "*p1: " << *p1 << "\n*p2: " << *p2 << endl; // Dereference a pointer
    //p2 = p1;
    //cout << "p2 = p1\n";
    //cout << "p1: " << p1 << "\np2: " << p2 << endl;
    //cout << "*p1: " << *p1 << "\n*p2: " << *p2 << endl;
    //p3 = &p1;
    //cout << "p3 = &p1\n";
    //cout << "p1: " << p1 << "\np2: " << p2 << endl;
    //cout << "*p1: " << *p1 << "\n*p2: " << *p2 << "\n*p3: " << *p3 << endl;

    //**p3 = 333;

    //cout << "n1: " << n1 << "\nn2: " << n2 << endl;



}
