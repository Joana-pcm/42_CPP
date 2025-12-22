#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructed." << std::endl;
    this->brain = new Brain();
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructed." << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->brain = new Brain(*(src.brain));
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
    {
        Animal::operator=(src);
        this->brain = new Brain(*(src.brain));
    }
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

Brain *Dog::getBrain()
{
    return (this->brain);
}