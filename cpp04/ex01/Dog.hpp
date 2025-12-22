#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        void makeSound() const;
        std::string getType() const;
        Brain *getBrain();
};