#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructed." << std::endl;
    this->brain = new Brain();
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructed." << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat copy constructor called." << std::endl;
    this->brain = new Brain(*(src.brain));
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
    {
        Animal::operator=(src);
        this->brain = new Brain(*(src.brain));
    }
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

Brain *Cat::getBrain()
{
    return (this->brain);
}