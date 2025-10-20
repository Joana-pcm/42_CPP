#include <iostream>
#include <string>
#include <iomanip>
#include "phonebook.hpp"

PhoneBook::PhoneBook(){
    contactCount = 0;
}

PhoneBook::~PhoneBook(){
}

void    PhoneBook::displayPhoneBook() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }
}

std::string PhoneBook::formatField(const std::string& field) const {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void    PhoneBook::addContact(int index){
    if (index < 0 || index > 8)
        std::cout << "Invalid index: " << index << std::endl;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    contacts[index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    if (contactCount < 8)
        contactCount++;
}