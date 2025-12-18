#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meows." << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->type);
}