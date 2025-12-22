#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructed." << std::endl;
    this->brain = new Brain();
}

WrongAnimal::~WrongAnimal()
{
    delete this->brain;
    std::cout << "WrongAnimal destructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    this->type = src.type;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    this->brain = new Brain(*(src.brain));
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    if (this != &src) {
        this->type = src.type;
        this->brain = new Brain(*(src.brain));
    }
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

Brain *WrongAnimal::getBrain()
{
    return (NULL);
}