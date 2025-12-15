#pragma once

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &src);
        Animal &operator=(const Animal &src);
        virtual void makeSound() const = 0;
        virtual std::string getType() const = 0;
};