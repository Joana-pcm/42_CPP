#include <iostream>
#include <string>
#include <iomanip>
#include "phonebook.hpp"
#include "contacts.hpp"

PhoneBook::PhoneBook(){
    contactCount = 0;
}

PhoneBook::~PhoneBook(){

}

void    addContact(int index){
    if (index < 0 || index > 8)
        std::cout << "Invalid index: " << index << std::endl;
    getFirstName();
    setFirstName();
}