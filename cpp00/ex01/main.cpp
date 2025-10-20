#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "phonebook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD") {
			int index = phoneBook.getContactCount() % 8; // Overwrite oldest contact if more than 8
			phoneBook.addContact(index);
		}
		else if (command == "SEARCH") {
			phoneBook.displayPhoneBook();
			std::cout << "Enter index to view details: ";
			std::string indexStr;
			std::getline(std::cin, indexStr);
			int index = std::atoi(indexStr.c_str());
			if (index >= 0 && index < phoneBook.getContactCount()) {
				phoneBook.displayContact(index);
			}
			else {
				std::cout << "Invalid index." << std::endl;
			}
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Unknown command." << std::endl;
		}
	}

	return 0;
}