#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        void makeSound() const;
        std::string getType() const;
};