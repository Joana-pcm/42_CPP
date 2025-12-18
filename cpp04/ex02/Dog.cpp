#include "Dog.hpp"

Dog::Dog() :  AAnimal()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructed." << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructed." << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
        AAnimal::operator=(src);
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