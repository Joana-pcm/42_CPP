#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &src);
        Animal &operator=(const Animal &src);
        virtual void makeSound() const;
        virtual std::string getType() const;
        virtual Brain *getBrain();
};