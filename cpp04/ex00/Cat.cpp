#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructed." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructed." << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
        Animal::operator=(src);
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}