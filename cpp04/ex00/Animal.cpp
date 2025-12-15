#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructed." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructed." << std::endl;
}

Animal::Animal(const Animal &src)
{
    this->type = src.type;
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}