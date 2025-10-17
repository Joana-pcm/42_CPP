#include <iostream>
#include <string>
#include <iomanip>
#include "contacts.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;

	public:
	PhoneBook();
	~PhoneBook();

	void addContact(int index);
	void searchContacts() const;
	void displayContact(int index) const;
	std::string formatField(const std::string& field) const;
};