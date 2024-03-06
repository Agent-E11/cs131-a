// 24-03-06_classes.cpp

#include <iostream>
#include <vector>
#include <format>

class BankAcct {
public:
	BankAcct() {} // If no parameters
    BankAcct(std::string name, double balance) {
        this->name = name;
        this->balance = balance;
    }
    std::string name;
    double get_balance() {
        return balance;
    }
	void deposit(double amount) {
		this->balance += amount;
    }
	void print();

private:
    double balance = 0;
};

void display_accts(std::vector<BankAcct> accts);

int main() {

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    char choice;
	std::vector<BankAcct> accts;

    BankAcct wecu("WECU", 0.0);
    BankAcct icu("ICU", 0.0);
	BankAcct becu;
	becu.name = "BECU";
	becu.deposit(100);
    accts.push_back(wecu);
    accts.push_back(icu);
	accts.push_back(becu);

	std::string msg = "";
	do {
		system("cls");
		// display interface
		std::cout << msg << std::endl << std::endl;
		std::cout << "Account\tBalance\n";
		std::cout << "------------------------\n";
		display_accts(accts);
		std::cout << "(A)dd\t(D)eposit\t(R)emove\t(Q)uit\n\n> ";
		// user input
		std::cin >> choice;
		choice = tolower(choice);

		std::string name;
		double balance;
		double amount;
		bool found;
		BankAcct new_acct;
		switch (choice) {
		case 'a':
			// Add account

			std::cout << "Name of new account: ";
			std::cin >> new_acct.name;
			std::cout << "Starting balance: ";
			std::cin >> balance;
			new_acct.deposit(balance);

			accts.push_back(new_acct);

			msg = std::format("Added acount: {}", new_acct.name);
			break;
		case 'd':
			std::cout << "Name of account to deposit to: ";
			std::cin >> name;
			std::cout << "Deposit amount: ";
			std::cin >> amount;

			found = false;
			for (BankAcct &acct : accts) {
				if (acct.name == name) {
					found = true;
					acct.deposit(amount);
					break;
				}
			}

			if (found) {
				msg = std::format("Deposited {} to account {}", amount, name);
			}
			else {
				msg = std::format("Could not find account with name `{}`", name);
			}

			break;
		case 'r':
			std::cout << "Name of account to remove: ";
			std::cin >> name;

			found = false;
			for (int i = 0; i < accts.size(); i++) {
				if (accts[i].name == name) {
					found = true;
					accts.erase(accts.begin() + i);
					break;
				}
			}
			
			if (found) {
				msg = std::format("Removed acount: {}", name);
			}
			else {
				msg = std::format("Could not find account with name `{}`", name);
			}
			break;
		case 'q':
			// Quit program
			std::cout << "Quitting... \n";
			break;
		}
	} while (choice != 'q');
}

void display_accts(std::vector<BankAcct> accts) {
	for (BankAcct acct : accts) {
		acct.print();
	}
}

void BankAcct::print() {
	std::cout << this->name << "\t" << this->get_balance() << "\n";
}
