#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string type;
        Brain *brain;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal &src);
        AAnimal &operator=(const AAnimal &src);
        virtual void makeSound() const = 0;
        virtual std::string getType() const = 0;
        virtual Brain *getBrain() const;
};