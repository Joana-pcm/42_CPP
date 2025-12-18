#pragma once

#include "AAnimal.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        void makeSound() const;
        std::string getType() const;
};