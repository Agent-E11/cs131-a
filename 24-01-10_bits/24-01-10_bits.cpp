// 24-01-10_bits.cpp

#include <iostream>
#include <bitset>

using namespace std;

void printbits(int x) {
    cout << bitset<4>(x) << endl;
}

int main()
{
    enum config
    {
        dark_mode = 0b0001,
        metric_measurements = 0b0010,
        admin = 0b0100,
        likes_pandas = 0b1000,
    };

    printbits(config::dark_mode);
    printbits(config::metric_measurements);
    printbits(config::admin);
    printbits(config::likes_pandas);

    int user_config =
        config::dark_mode |
        config::admin;

    cout << "User's config: ";
    printbits(user_config);

    if (user_config & config::dark_mode) {
        cout << "User is in dark mode" << endl;
    }
    if (user_config & config::metric_measurements) {
        cout << "User is euri" << endl;
    }
    if (user_config & config::admin) {
        cout << "User is admin" << endl;
    }
    if (user_config & config::likes_pandas) {
        cout << "User is admin" << endl;
    }
}
