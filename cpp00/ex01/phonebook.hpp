#include <iostream>
#include <string>
#include <iomanip>

class phonebook {
private:
	struct Contact {
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	};

	Contact contacts[8];
	int contactCount;

	void addContact();
	void searchContacts() const;
	void displayContact(int index) const;
	std::string formatField(const std::string& field) const;
};