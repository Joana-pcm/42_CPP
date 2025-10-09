#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook {
public:
	Contact contacts[8];
	int contactCount;

	void addContact();
	void searchContacts() const;
	void displayContact(int index) const;
	std::string formatField(const std::string& field) const;
};

class Contact
{
public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};
