#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class WrongAnimal
{
    protected:
        std::string type;
        Brain *brain;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal &operator=(const WrongAnimal &src);
        void makeSound() const;
        std::string getType() const;
        Brain *getBrain();
};