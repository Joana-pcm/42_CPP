#pragma once

#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
    private:
        Brain* brain;
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &src);
        WrongCat &operator=(const WrongCat &src);
        void makeSound() const;
        std::string getType() const;
        Brain *getBrain();
};