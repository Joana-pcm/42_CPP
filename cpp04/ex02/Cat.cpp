#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructed." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructed." << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat &src) : AAnimal(src)
{
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
        AAnimal::operator=(src);
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