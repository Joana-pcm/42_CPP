#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal constructed." << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructed." << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
    this->type = src.type;
    std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (this->type);
}

Brain *AAnimal::getBrain()
{
    return (NULL);
}