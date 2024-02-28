// 24-02-28_vectors.cpp

#include <iostream>
#include <vector>
#include <string>

void display_vector(std::vector<std::string>& v) {
	system("cls");
	std::cout << "CUSTOMER QUEUE\n";
	std::cout << "--------------\n";
	if (v.empty()) {
		std::cout << "The queue is empty.\n";
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			std::cout << i + 1 << ": " << v[i] << std::endl;
		}
	}
	std::cout << "\n(S)erve\t(A)dd\t(R)emove\t(Q)uit\n";
}

int main()
{
	char selection;
	std::string next_customer;
	int remove_customer;
	std::vector<std::string> queue = {"Luke", "Leia"};

	queue.insert(queue.begin() + 1, "Jango");

	while (true) {
		display_vector(queue);

		std::cin >> selection;

		switch (selection) {
		case 'S': case 's':
			if (queue.empty()) {
				std::cout << "Queue is empty.\n";
			} else {
				std::cout << "Serving " << queue[0] << "\n";
				queue.erase(queue.begin());
			}
			break;

		case 'A': case 'a':
			std::cout << "Who is next in line?: ";
			std::cin >> next_customer;
			queue.push_back(next_customer);
			std::cout << "Added " << next_customer << std::endl;
			break;
			
		case 'R': case 'r':
			std::cout << "Who should be removed?: ";
			std::cin >> remove_customer;

			queue.erase(queue.begin() + (remove_customer - 1));

			break;

		case 'Q': case 'q':
			std::cout << "Quitting...\n";
			return 0;
			break;

		default:
			std::cout << "Invalid option, try again\n";
			break;
		}
		system("pause");
	}
}
