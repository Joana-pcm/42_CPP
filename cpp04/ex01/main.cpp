#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << std::endl << "----- Construct Shelter -----" 
    << std::endl << std::endl;
    const Animal *shelter[4] = {new Dog(), new Cat(), new Dog(), new Cat()};
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (shelter[i]->getType() == "Dog")
            (shelter[i]->getBrain())->setIdea(0, "I want to play fetch!");
        else if (shelter[i]->getType() == "Cat")
            (shelter[i]->getBrain())->setIdea(0, "I want to nap!");
    }
    std::cout << std::endl
     << "----- Animal Info -----" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << std::endl;
        std::cout << "Animal Type: " << shelter[i]->getType() << std::endl;
        shelter[i]->makeSound();
        std::cout << shelter[i]->getType() << " ideas: " << (shelter[i]->getBrain())->getIdea(0) << std::endl;
    }
    std::cout << std::endl
            << "----- Cleaning Up Shelter -----" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << std::endl;
        std::cout << "Deleting Animal of type: " << shelter[i]->getType() << std::endl;
        delete shelter[i];
    }
    std::cout << std::endl << "----- Wrong Shelter -----" << std::endl;
    const WrongAnimal *wrongShelter[2] = {new WrongCat(), new WrongCat()};
    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        (wrongShelter[i]->getBrain())->setIdea(0, "I want to nap!");
    }
    std::cout << std::endl
     << "----- Wrong Animal Info -----" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << std::endl
        << "Wrong Animal Type: " << wrongShelter[i]->getType() << std::endl;
        wrongShelter[i]->makeSound();
        std::cout << "Wrong Cat ideas: " << (wrongShelter[i]->getBrain())->getIdea(0) << std::endl;
    }
    std::cout << std::endl
    << "----- Cleaning Up Wrong Shelter -----" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << std::endl 
        << "Deleting Wrong Animal of type: " << wrongShelter[i]->getType() << std::endl;
        delete wrongShelter[i];
    }
    return 0;
}