#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructed." << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructed." << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
        Animal::operator=(src);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}

std::string Dog::getType() const
{
    return this->type;
}