// 10b-bank-account-classes.cpp

#include <iostream>
#include <vector>
#include <format>
#include <string>

constexpr auto COULD_NOT_FIND_ERR = "Could not find account with name `{}`";
constexpr auto INVALID_NUMBER_ERR = "Not a valid number";

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

static int find_account(std::vector<BankAcct> accts, std::string name);

bool get_double(double& n);

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
		// Display interface
		std::cout << msg << std::endl << std::endl;
		std::cout << "Account\tBalance\n";
		std::cout << "------------------------\n";
		display_accts(accts);
		std::cout << "(A)dd\t(D)eposit\t(W)ithdraw\t(T)ransfer\t(R)emove\t(Q)uit\n\n> ";
		// Get user input
		std::cin >> choice;
		choice = tolower(choice);

		std::string name1;
		std::string name2;
		double balance;
		double amount;
		bool success;
		int pos;
		BankAcct new_acct;

		BankAcct *transfer_from_acct = nullptr;
		BankAcct *transfer_to_acct = nullptr;

		switch (choice) {
		case 'a':
			// Add account

			// Get name
			std::cout << "Name of new account: ";
			std::cin >> new_acct.name;

			// Get starting balance
			std::cout << "Starting balance: $";
			success = get_double(balance);
			if (!success) {
				msg = std::format(INVALID_NUMBER_ERR);
				break;
			}

			// Add balance and add new_acct to accts
			new_acct.deposit(balance);
			accts.push_back(new_acct);

			msg = std::format("Added acount `{}` with starting balance `${:.2f}`", new_acct.name, balance);
			break;

		case 'd':
			// Deposit to account

			// Get name
			std::cout << "Name of account to deposit to: ";
			std::cin >> name1;

			// Find position of account
			pos = find_account(accts, name1);
			if (pos == -1) {
				msg = std::format(COULD_NOT_FIND_ERR, name1);
				break;
			}

			// Get amount
			std::cout << "Amount to deposit: $";
			success = get_double(amount);
			if (!success) {
				msg = std::format(INVALID_NUMBER_ERR);
				break;
			}
			if (amount < 0) {
				msg = "Cannot deposit a negative amount (use (W)ithdraw)";
				break;
			}

			// Deposit amount
			accts[pos].deposit(amount);

			msg = std::format("Deposited `${:.2f}` to account `{}`", amount, name1);
			break;

		case 'w':
			// Withdraw from account

			// Get name
			std::cout << "Name of account to withdraw from: ";
			std::cin >> name1;

			// Find position of account
			pos = find_account(accts, name1);
			if (pos == -1) {
				msg = std::format(COULD_NOT_FIND_ERR, name1);
				break;
			}

			// Get amount
			std::cout << "Amount to withdraw: $";
			success = get_double(amount);
			if (!success) {
				msg = std::format(INVALID_NUMBER_ERR);
				break;
			}
			if (amount < 0) {
				msg = "Cannot withdraw a negative amount (use (D)eposit)";
				break;
			}

			// Deposit the inverse of amount (withdraw)
			accts[pos].deposit(-amount);

			msg = std::format("Withdrew `${:.2f}` from account `{}`", amount, name1);
			break;

		case 't':
			// Transfer between accounts

			// Get first name
			std::cout << "Name of account to transfer from: ";
			std::cin >> name1;

			// Find position of account and get reference
			pos = find_account(accts, name1);
			if (pos == -1) {
				msg = std::format(COULD_NOT_FIND_ERR, name1);
				break;
			}
			transfer_from_acct = &accts[pos];

			// Get second name
			std::cout << "Name of account to transfer to: ";
			std::cin >> name2;

			if (name1 == name2) {
				msg = "Cannot transfer to and from the same account";
				break;
			}

			// Find position of account and get reference
			pos = find_account(accts, name2);
			if (pos == -1) {
				msg = std::format(COULD_NOT_FIND_ERR, name2);
				break;
			}
			transfer_to_acct = &accts[pos];

			// Get amount
			std::cout << std::format("Amount to transfer from `{}` to `{}`: $", name1, name2);
			success = get_double(amount);
			if (!success) {
				msg = std::format(INVALID_NUMBER_ERR);
				break;
			}

			// Subtract from first account, add to second account
			transfer_from_acct->deposit(-amount);
			transfer_to_acct->deposit(amount);

			msg = std::format("Transferred `${:.2f}` from `{}` to `{}`", amount, name1, name2);
			break;

		case 'r':
			// Remove account

			// Get name
			std::cout << "Name of account to remove: ";
			std::cin >> name1;

			// Find position of account
			pos = find_account(accts, name1);

			if (pos != -1) {
				// If it is there, remove account
				accts.erase(accts.begin() + pos);
				msg = std::format("Removed acount `{}`", name1);
			}
			else {
				// If it is not there, set msg to an error
				msg = std::format(COULD_NOT_FIND_ERR, name1);
			}
			break;

		case 'q':
			// Quit program

			std::cout << "Quitting... \n";
			break;

		default:
			msg = "Invalid option";
		}
	} while (choice != 'q');
}

/// <summary>
/// Finds a BankAcct in a vector when given a name
/// </summary>
/// <param name="accts">Accounts to search</param>
/// <param name="name">Name of BankAcct to search for</param>
/// <returns>The index of the found BankAcct, will be -1 if it cannot be found</returns>
static int find_account(std::vector<BankAcct> accts, std::string name) {
	for (int i = 0; i < accts.size(); i++) {
		if (accts[i].name == name) return i;
	}
	return -1;
}

/// <summary>
/// Get a double using std::cin
/// </summary>
/// <param name="n">Reference to be overwritten with the new double. If there is an error, it will not be changed</param>
/// <returns>Returns the success value, true if success, false if fail</returns>
bool get_double(double& n) {
	// Get input
	std::string input;
	std::cin >> input;

	try {
		// Try to convert to double
		n = std::stod(input);
	}
	catch (std::exception& e) {
		// If there was an error, return false
		return false;
	}
	// If there was no error, return true
	return true;
}

void display_accts(std::vector<BankAcct> accts) {
	for (BankAcct acct : accts) {
		acct.print();
	}
}

void BankAcct::print() {
	std::cout << this->name << "\t$" << this->get_balance() << std::endl;
}
