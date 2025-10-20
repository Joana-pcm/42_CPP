#include <iostream>
#include <string>
#include <iomanip>
#include "phonebook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD") {
			int index = phoneBook.con % 8; // Overwrite oldest contact if more than 8
			phoneBook.addContact(index);
		} else if (command == "SEARCH") {
			phoneBook.displayPhoneBook();
			std::cout << "Enter index to view details: ";
			std::string indexStr;
			std::getline(std::cin, indexStr);
			int index = std::stoi(indexStr);
			if (index >= 0 && index < phoneBook.getContactCount()) {
				phoneBook.displayContactDetails(index);
			} else {
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