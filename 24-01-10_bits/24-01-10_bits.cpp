// 24-01-10_bits.cpp

#include <iostream>
#include <bitset>

using namespace std;

enum opts {
	is_24hour = 0b1000,
	is_premium = 0b0100,
	is_darkmode = 0b0010,
	is_admin = 0b0001,
};

void printbits(int x) {
    cout << bitset<4>(x) << endl;
}

bitset<4> bits(int x) {
    return bitset<4>(x);
}

void add_opt(int& config, opts opt) {
    config |= opt;
}

void remove_opt(int& config, opts opt) {
    config &= ~opt;
}

int main()
{
    int user_config =
        opts::is_admin |
        opts::is_darkmode;

    bool should_continue;
    char input;

    do {
        should_continue = true;
        opts opt;

        cout << "User config: ";
        printbits(user_config);

		if (user_config & opts::is_24hour)
			cout << "User is using 24 hour format" << endl;
        else
			cout << "User is not using 24 hour format" << endl;

		if (user_config & opts::is_premium)
			cout << "User is paying me" << endl;
        else
			cout << "User is not paying me :(" << endl;

        if (user_config & opts::is_darkmode)
            cout << "User is in dark mode" << endl;
        else
            cout << "User is not in dark mode" << endl;

		if (user_config & opts::is_admin)
			cout << "User is an admin" << endl;
        else
			cout << "User is not an admin" << endl;

        cout << endl;

        cout << "Which option would you like to modify?\n[(H)our, (P)remium, (D)ark mode, (A)dmin]: ";
        cin >> input;

        switch (input) {
        case 'H': case 'h':
            cout << "Editing is_24hour..." << endl;
            break;
        case 'P': case 'p':
            cout << "Editing is_premium..." << endl;
            break;
        case 'D': case 'd':
            cout << "Editing is_darkmode..." << endl;
            break;
        case 'A': case 'a':
            cout << "Editing is_admin..." << endl;
            break;
        case 'Q': case 'q':
            cout << "Quitting..." << endl;
            should_continue = false;
            continue;
        default:
            cout << "Invalid option" << endl;
            continue;
        }

        cout << "\nWhat would you like to set it to?: ";
        cin >> input;
        cout << endl;

        switch (input) {
        case 'T': case 'Y': case '1':
        case 't': case 'y':
            cout << "Yes" << endl;
        default:
            cout << "No" << endl;
        }

    } while (should_continue);

    //cout << "User's config: ";
    //printbits(user_config);

    //if (user_config & opts::is_darkmode) {
    //    cout << "User is in dark mode" << endl;
    //}
    //if (user_config & opts::is_24hour) {
    //    cout << "User is using 24 hour format" << endl;
    //}
    //if (user_config & opts::is_admin) {
    //    cout << "User is an admin" << endl;
    //}
    //if (user_config & opts::is_premium) {
    //    cout << "User is paying me" << endl;
    //}
}
