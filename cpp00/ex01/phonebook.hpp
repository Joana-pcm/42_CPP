#include <iostream>
#include <string>
#include <iomanip>
#include "contacts.hpp"

class PhoneBook {
private:
	/* struct Contact {
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	}; */
	Contact contacts[8];
	int contactCount;

	public:
	PhoneBook();
	~PhoneBook();

	void addContact(int index);
	void searchContacts() const;
	void displayContact(int index) const;
	void displayPhoneBook() const;
	std::string formatField(const std::string& field) const;
};