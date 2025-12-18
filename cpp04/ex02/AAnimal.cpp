#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
    std::cout << "Animal constructed." << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructed." << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
    this->type = src.type;
    std::cout << "Animal copy constructor called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void AAnimal::makeSound() const
{
    std::cout << "Animal makes a sound." << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->type);
}

Brain *AAnimal::getBrain() const
{
    return (this->brain);
}