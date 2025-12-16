#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    this->type = src.type;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}