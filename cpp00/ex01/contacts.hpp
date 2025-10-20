#include <iostream>
#include <string>
#include <iomanip>

class Contact {
private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
public:
	Contact();
	Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber, std::string darkestSecret);
	~Contact();
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setNickname(const std::string& nickname);
	void setPhoneNumber(const std::string& phoneNumber);
	void setDarkestSecret(const std::string& darkestSecret);
};